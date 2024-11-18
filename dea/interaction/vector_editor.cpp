#include "vector_editor.h"
#include "resource.h"
#include "resource/blob.h"
#include "config/size.h"
#include "config/color.h"
#include <unordered_set>

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
		// it's important to reserve size because vertexNodes_ may reallocate
		vertexNodes_.reserve(network_.getSegments().size() * 2);

		for (int i = 0; auto * segment : network_.getSegments()) {
			auto& [v0, v1] = segment->getVerticies();
			vertexNodes_.emplace_back(v0, frame_);
			vertexNodes_.back().getNode().setName("v" + std::to_string(i) + std::string("_0"));
			vertexNodes_.emplace_back(v1, frame_);
			vertexNodes_.back().getNode().setName("v" + std::to_string(i) + std::string("_1"));
			i++;
		}
		ctrlHandleNodes_.reserve(vertexNodes_.size() * 4);
		for (auto& nodeVertex : vertexNodes_)
		{
			vertexNodeMap_.insert({ nodeVertex.getVertex(), &nodeVertex });
		}
		for (auto& vertexNode : vertexNodes_) {
			vertexNode.getNode().addEventListener(EventType::MouseDrag, [this, &vertexNode](Event &e) {
				auto &event = static_cast<MouseEvent &>(e);
				vertexNode.getVertex()->getVertex()->translate(event.worldDx, event.worldDy);
			});
			vertexNode.getNode().addEventListener(EventType::MouseDown, [this, &vertexNode](Event &e) {
				auto &event = static_cast<MouseEvent &>(e);
				selectVertexNode(&vertexNode);
			});
		}
	}

	void VectorEditor::selectVertexNode(VertexNode* node, int depth) {
		if (!node) return;
		node->select();
		selectedVertexNodes_.push_back(node);
		onSelectVertexNodeCb_(node);

		// get edited vertexNode
		std::unordered_set<gfx::SegmentVertex*> vertexNodes;
		auto addToCtrlHandleNodes = [this, &vertexNodes](gfx::SegmentVertex* vertex) {
			if (vertexNodes.contains(vertex)) return;
			vertexNodes.insert(vertex);
			ctrlHandleNodes_.emplace_back(*vertexNodeMap_[vertex], frame_);
		};
		for (auto& vertexNode : vertexNodes_) {
			gfx::Segment::VertexIter iter{node->getVertex()};
			do {
				addToCtrlHandleNodes(iter.get());
				if (depth == 0 && iter.get() != node->getVertex()) { continue; }
				addToCtrlHandleNodes(iter.clone().goAnother().get());
			} while(iter.goNext());
		}
		for (auto& ctrlHandleNode : ctrlHandleNodes_) {
			ctrlHandleNode.getNode().addEventListener(EventType::MouseDown, [this, &ctrlHandleNode](Event &e) {
				selectVertexNode(&ctrlHandleNode.getVertexNode(), 0);
			});
		  ctrlHandleNode.getNode().addEventListener(EventType::MouseDrag, [this, &ctrlHandleNode](Event &e) {
				auto &event = static_cast<MouseEvent &>(e);
				ctrlHandleNode.getVertexNode().getVertex()->translateTangent(event.worldDx, event.worldDy);
				// network_.encode();
			});
		}
	}

	void VectorEditor::startEditVector() {
		editMode_ = Vector;
		BoundEditor::invalidate();
		arena_ = std::make_unique<SkArenaAlloc>(40 * 1024);
		if (auto* vector = node::node_cast<node::VectorNode>(node_)) {
			const auto resourceItem = Resource::getInstance().get(vector->getVectorData().getVectorNetworkBlob());
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
	}

	VectorEditor::CtrlHandleNode::CtrlHandleNode(VertexNode& vertexNode, Frame& parent) : vertexNode_(vertexNode) {
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