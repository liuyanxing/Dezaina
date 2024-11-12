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
		for (auto* segment : network_.getSegments()) {
			auto& [v0, v1] = segment->getVerticies();
			vertexNodes_.emplace_back(v0, frame_);
			vertexNodes_.emplace_back(v1, frame_);
		}
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
		selectedVertexNodes_.push_back(node);

		ctrlHandleNodes_.clear();
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
		fillPaint.setColor({1, 1, 1, 1});
		SolidPaint strokePaint;
		auto &[r, g, b, a] = config::color::Primary;
		strokePaint.setColor({r, g, b, a});

    node_.setFillPaints({fillPaint});
		node_.setStrokePaints({strokePaint});
    node_.setStrokeWeight(config::size::Min);
    node_.setSize({config::size::Tiny, config::size::Tiny});
		auto* v = vertex_->getVertex();
    node_.setTransform(Matrix::Translate(v->x(), v->y()));
		node::Container::append(&node_, &parent);
	}

	void VectorEditor::VertexNode::select() {
		auto fillPaint = node_.getFillPaints();
		// fillPaint[0].setColor({1, 0, 0, 1});
		// node_.setFillPaints(fillPaint);
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
		node::Container::append(&node_, &parent);

		Rectangle line;
		line.setFillPaints({fillPaint});
		line.setStrokePaints({strokePaint});
		line.setStrokeWeight(config::size::Min);
		line.setSize({config::size::Tiny, vertexNode.getTagentLength()});
		line.setTransform(Matrix::Translate(vertexNode.getPos()) * Matrix::Rotate(vertexNode.getTangentAngle()));
		line.disable();
		node::Container::append(&line, &parent);
	}

}