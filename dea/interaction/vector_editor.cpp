#include "vector_editor.h"
#include "resource.h"
#include "resource/blob.h"
#include "config/size.h"
#include "config/color.h"

namespace dea::interaction {
	using namespace node;
	using namespace resource;
	using namespace event;

  void VectorEditor::saveNetwork() {
		auto* resourceItem = Resource::getInstance().getProvider<BlobResourceProvider>()->store(network_.serialize());
		auto* vectorNode = node::node_cast<VectorNode>(node_);
		auto vectorData = vectorNode->getVectorData();
		vectorData.setVectorNetworkBlob(resourceItem->id());
		editor_.setVectorData(vectorData);
	}

	void VectorEditor::buildCtrlNodes() {
		vertexNodes_.clear();
		vertexNodeMap_.clear();

		// it's important to reserve because vertexNodes_ may reallocate
		vertexNodes_.reserve(network_.getSegments().size() * 2);

		for (int i = 0; auto * segment : network_.getSegments()) {
			auto& [v0, v1] = segment->getVerticies();
			vertexNodes_.emplace_back(v0, frame_).getNode().setName("v" + std::to_string(i) + std::string("_0"));
			vertexNodes_.emplace_back(v1, frame_).getNode().setName("v" + std::to_string(i) + std::string("_1"));
			i++;
		}
		for (auto& nodeVertex : vertexNodes_)
		{
			vertexNodeMap_.insert({ nodeVertex.getVertex(), &nodeVertex });
		}
		for (auto& vertexNode : vertexNodes_) {
			vertexNode.getInterNode().addEventListener(EventType::MouseDrag, [this, &vertexNode](Event &e) {
				auto &event = static_cast<MouseEvent &>(e);
				vertexNode.getVertex()->getVertex()->translate(event.worldDx, event.worldDy);
			});
			vertexNode.getInterNode().addEventListener(EventType::MouseDown, [this, &vertexNode](Event &e) {
				auto &event = static_cast<MouseEvent &>(e);
				selectVertexNode(&vertexNode);
			});
			vertexNode.getCtrlHandleNode().getInterNode().addEventListener(EventType::MouseDown, [this, &vertexNode](Event &e) {
				selectVertexNode(&vertexNode, 0);
			});
		}
	}

	void VectorEditor::selectVertexNode(VertexNode* node, int depth) {
		if (!node) return;
		for (auto& vertexNode : vertexNodes_) {
			vertexNode.unSelect();
			vertexNode.getCtrlHandleNode().hide();
		}

		node->select();
		onSelectVertexNodeCb_(node);

		gfx::Segment::VertexIter iter{node->getVertex()};
		do {
			vertexNodeMap_[iter.get()]->select();
			if (depth == 0 && iter.get() != node->getVertex()) { continue; }
			vertexNodeMap_[iter.clone().goAnother().get()]->getCtrlHandleNode().show();
		} while(iter.goNext());
	}

	void VectorEditor::startEditVector() {
		editMode_ = Vector;
		BoundEditor::invalidate();
		arena_ = std::make_unique<SkArenaAlloc>(40 * 1024);
		if (auto* vector = node::node_cast<node::VectorNode>(node_)) {
			const auto resourceItem = Resource::getInstance().get(vector->getVectorData().getVectorNetworkBlob());
			assert(resourceItem);
			gfx::Network::buildFromData(resourceItem->as<BlobResourceItem>()->data(), *arena_, network_);
			network_.buildCycles(*arena_);
		}
		buildCtrlNodes();
	}

	VectorEditor::VertexNode::VertexNode(gfx::SegmentVertex* vertex, Frame& parent) : vertex_(vertex) {
		pos_ = {vertex->getVertex()->x(), vertex->getVertex()->y()};
		SolidPaint fillPaint;
		fillPaint.setColor({1, 0, 0, 1});
		SolidPaint strokePaint;
		auto &[r, g, b, a] = config::color::Primary;
		strokePaint.setColor({r, g, b, a});

		node_.setFillPaints({fillPaint});
		node_.setStrokePaints({strokePaint});
		node_.setStrokeWeight(config::size::Min);
		node_.setSize({config::size::Small, config::size::Small});
		auto* v = vertex_->getVertex();
		node_.setTransform(Matrix::Translate(v->x(), v->y()));
		node_.layout(&node_);

		node::Container::append(&node_, &parent);
	}

	void VectorEditor::VertexNode::select() {
		auto fillPaint = node_.getFillPaints();
		std::get<SolidPaint>(fillPaint[0]).setColor({ 1, 0, 0, 1 });
		ctrlHandleNode_.show();
	}

	void VectorEditor::VertexNode::unSelect() {
		ctrlHandleNode_.hide();
	}

	VectorEditor::CtrlHandleNode::CtrlHandleNode(Frame& parent) : vertexNode_(vertexNode) {
		container_.disable();

		SolidPaint fillPaint;
		fillPaint.setColor({1, 1, 1, 1});
		SolidPaint strokePaint;
		auto &[r, g, b, a] = config::color::Primary;
		strokePaint.setColor({r, g, b, a});

		node_.setFillPaints({fillPaint});
		node_.setStrokePaints({strokePaint});
		node_.setStrokeWeight(config::size::Min);
		node_.setSize({config::size::Tiny, config::size::Tiny});
		node_.setTransform(Matrix::Translate(vertexNode.getTangentEnd()));
		node_.setName(vertexNode.getNode().getName() + "_R");
		node_.layout(&node_);
		node::Container::append(&node_, &parent);

		line_.setFillPaints({fillPaint});
		line_.setStrokePaints({strokePaint});
		line_.setStrokeWeight(config::size::Min);
		line_.setSize({config::size::Tiny, vertexNode.getTagentLength()});
		line_.setTransform(Matrix::Translate(vertexNode.getPos()) * Matrix::Rotate(vertexNode.getTangentAngle()));
		line_.disable();
		line_.setName(vertexNode.getNode().getName() + "_L");
		node::Container::append(&line_, &parent);
	}

}