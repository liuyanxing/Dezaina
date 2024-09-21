#include "command.h"
#include "dezaina.h"
#include "node.h"
#include "node/utility.h"
#include "schema/message.h"
#include "base/data.h"
#include "resource.h"
#include "geometry/geometry.h"

namespace dea::change {

using namespace node;
using namespace base;

void NodeChangesCommand::takeUndoSnapshot() {
	message::Message message;
	message.set_type(message::MessageType::NODE_CHANGES);
	auto& pool = *pool_;
	auto& snapshots = message.set_nodeChanges(pool, changes_->size());

	std::vector<const Data*> pathes;
	auto index = 0;
	for (auto& [node, nodeChange] : *changes_) {
		auto& snapshot = snapshots[index];
		node->takeSnapshot(snapshot, *nodeChange, pool);
		if (auto *shape = node_cast<DefaultShapeNode>(node); shape && !isFillPathValid(nodeChange)) {
			auto* item = resource::Resource::getInstance().get(shape->getFillGeometry().front().commandsBlob);
			if (item && item->as<resource::BlobResourceItem>()) {
				pathes.push_back(item->as<resource::BlobResourceItem>()->data());
				snapshot.set_fillGeometry(pool, 1)[0].set_commandsBlob(pathes.size() - 1);
			}
		}
	}

  auto pathBlobMessage = message.set_blobs(pool, pathes.size());
	for (int i = 0; i < pathBlobMessage.size(); i++) {
		auto& path = pathes[i];
		auto& blobBuffer = pathBlobMessage[i].set_bytes(pool, path->size());
		blobBuffer.set(path->dataU8(), path->size());
	}
	
	kiwi::ByteBuffer buffer;
	message.encode(buffer);
	undoSnapshot_ = Data::MakeWithCopy(buffer.data(), buffer.size());
}

void NodeChangesCommand::takeRedoSnapShot() {
	message::Message message;
  message.set_type(message::MessageType::NODE_CHANGES);
	auto& pool = *pool_;
  auto& nodeChanges = message.set_nodeChanges(pool, changes_->size());
  
	std::vector<const Data*> pathes;
	for (int index = 0; auto& [node, nodeChange] : *changes_) {
	  Dezaina::instance().document().applyNodeChange(nodeChange);
		if (!isFillPathValid(nodeChange)) {
			auto *item = resource::BlobResource::add(geometry::buildFill(node));
			pathes.push_back(item->data());
      nodeChange->set_fillGeometry(pool, 1)[0].set_commandsBlob(pathes.size() - 1);
		}
		if (!isStrokePathValid(nodeChange)) {
		}
		nodeChanges[index++] = *nodeChange;
	}

  auto pathBlobMessage = message.set_blobs(pool, pathes.size());
	for (int i = 0; i < pathBlobMessage.size(); i++) {
		auto& path = pathes[i];
		auto& blobBuffer = pathBlobMessage[i].set_bytes(pool, path->size());
		blobBuffer.set(path->dataU8(), path->size());
	}

	kiwi::ByteBuffer buffer;
	message.encode(buffer);

	redoSnapshot_ = Data::MakeWithCopy(buffer.data(), buffer.size());
}

void NodeChangesCommand::execute() {
	takeUndoSnapshot();
	takeRedoSnapShot();

	Dezaina::instance().document().applyMessage(*redoMessage_);
	redoMessage_ = nullptr;
}

void NodeChangesCommand::redo() {
	kiwi::ByteBuffer buffer(redoSnapshot_.dataU8(), redoSnapshot_.size());
	message::Message message;
	kiwi::MemoryPool pool;
	message.decode(buffer, pool);
	Dezaina::instance().document().applyMessage(message);
}

void NodeChangesCommand::undo() {
	kiwi::ByteBuffer buffer(redoSnapshot_.dataU8(), redoSnapshot_.size());
	message::Message message;
	kiwi::MemoryPool pool;
	message.decode(buffer, pool);
	Dezaina::instance().document().applyMessage(message);
}

}