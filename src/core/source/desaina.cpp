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

#include "event_system/event_system.h"
#include "change_system/change_system.h"
#include "viewport_system/viewport_system.h"
#include "creaet_system/create_system.h"
#include "edit_system/edit_system.h"
#include "action_system/action_system.h"
#include "render_system/render_system.h"

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

template<typename T, typename N>
void Desaina::registerSystem(N** desainaSystem) {
  // todo destruct
  auto* system = new T(this);
  systems_.push_back(system);
  *desainaSystem = system;
}

void Desaina::addSystems() {
	registerSystem<EventSystem>(&eventSystem);
  registerSystem<SelectSystem>(&selectSystem);
  registerSystem<EditSystem>(&editSystem);
  registerSystem<ViewPortSystem>(&viewPortSystem);
  registerSystem<ActionSystem>(&actionSystem);
  registerSystem<ChangeSystem>(&changeSystem);
  registerSystem<RenderSystem>(&renderSystem);
  registerSystem<CreateSystem>(&createSystem);
}

void Desaina::tick() {
  for (const auto &system : systems_) {
    system->tick();
  }
  for (const auto &system : systems_) {
    system->afterTick();
  }
  for (const auto& nextTickHandler : nextTickHandlers_) {
    nextTickHandler();
  }
  nextTickHandlers_.clear();
  frameCount++;
}
