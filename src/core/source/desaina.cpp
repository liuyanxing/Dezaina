#include "kiwi.h"
#include <cstring>
#include <memory>
#include <stdint.h>
#include <iostream>

#include "base_type.h"

#define IMPLEMENT_KIWI_H
#define IMPLEMENT_SCHEMA_H

#include "event_system/event.h"
#include <cstdint>
#include "desaina_node.h"
#include "util/node_geometry.h"
#include "desaina.h"
#include "change_system/change_system.h"
#include "viewport_system/viewport_system.h"

bool Desaina::loadDocument(kiwi::ByteBuffer &buffer) {
  bool is_loaded = changeSystem->processMessage(buffer);
  if (!is_loaded) {
    return false;
  }
  document.setLoaded(true);
  document.buildDocTree();
  document.builPath();
  return true;

}

bool Desaina::encode(kiwi::ByteBuffer &buffer) {
	kiwi::MemoryPool pool;
	Desaina_Kiwi::Message message;
	message.set_type(Desaina_Kiwi::MessageType::NODE_CHANGES);
	auto allNodes = document.getAllNodes();
	auto& nodeChanges = message.set_nodeChanges(pool, allNodes.size());

	for (uint32_t i = 0; i < allNodes.size(); ++i) {
		auto& nodeChange = nodeChanges[i];
		allNodes[i]->toChange(nodeChange, pool);
	}

	return message.encode(buffer);
}

void Desaina::buildEvents() {
  viewPortSystem->addEventListener(EventType::kViewPortChange, [this](Event* event) {
    if (auto* curPage = document.getCurrentPage()) {
      curPage->setViewMatrix(viewPortSystem->getViewMatrix());
    }
  });
}

void Desaina::addSystems() {
}

void Desaina::tick() {
  for (const auto &system : systems_) {
    system->tick();
  }
  for (const auto &system : systems_) {
    system->afterTick();
  }
  frameCount++;
}
