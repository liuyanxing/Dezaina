#include "vector_editor.h"
#include "resource.h"
#include "resource/blob.h"

namespace dea::interaction {
	using namespace node;
	using namespace resource;

	void VectorEditor::startEditVector() {
		editMode_ = Vector;
		BoundEditor::invalidate();
		arena_ = std::make_unique<SkArenaAlloc>(40 * 1024);
		if (auto* vector = node::node_cast<node::VectorNode>(node_)) {
		    const auto resourceItem = Resource::getInstance().get(vector->getVectorData().getVectorNetworkBlob());
			gfx::Network::buildFromData(resourceItem->as<BlobResourceItem>()->data(), *arena_, network_);
			network_.buildCycles(*arena_);
		}
	}

}