#pragma once

#include "base_type.h"
#include "desaina_node.h"
#include "document.h"
#include "edit_system/edit_system.h"
#include "edit_system/editor/editor.h"
#include "event_system/event.h"
#include "event_system/event_emitter.h"
#include "include/core/SkPath.h"
#include "kiwi.h"
#include <memory>
#include <stdint.h>
#include "select_system/select_system.h"
#include "services/blob_service.h"
#include "services/id_generator.h"
#include "services/services.h"
#include "event_system/event_system.h"
#include "render_system/render_system.h"
#include "system/system.h"
#include "viewport_system/viewport_system.h"
#include "action_system/action_system.h"
#include "change_system/change_system.h"
#include "edit_system/edit_system.h"
#include "types/cursor.h"

struct DesainaOption {
	uint32_t sessionId;
};

struct WindowInfo {
  int width;
  int height;
  float devicePixelRatio;
};

struct Geometry {
  SkPath path;
  const Blob* commandsBlob = nullptr;
  const SkPath& getPath() {
    if (path.isEmpty()) {
      path = util::toSkPath(commandsBlob);
    }
    return path;
  }
};

using BlobReMap = unordered_map<uint32_t, uint32_t>;
using Systems = vector<System*>;

class Desaina : public EventEmitter {
	public:
		Desaina(DesainaOption option):
			sessionId_(option.sessionId),
			services({std::make_unique<IdGenerator>(option.sessionId), std::make_unique<BlobService>()}),
			document(&services) {
        buildEvents();
        addSystems();
      };
		~Desaina() = default;
		void tick();

		bool loadDocument(kiwi::ByteBuffer& buffer) {
			bool is_loaded = changeSystem.processMessage(buffer);
			if (!is_loaded) {
				return false;
			}
			document.setLoaded(true);
			document.buildDocTree();
			document.builPath();
			return true;
		};

    void buildEvents();
    void addSystems();

		bool encode(kiwi::ByteBuffer& buffer);

    Systems* getSystems() {
      return &systems_;
    }

    void setWindowInfo(const WindowInfo& windowInfo) {
      windowInfo_ = windowInfo;
    }

    const WindowInfo& getWindowInfo() const {
      return windowInfo_;
    }

    void setCursor(CursorType cursorType) {
      UIEvent::Builder builder(EventType::kSetCursor);
      auto event = builder.build();
      event.cursorType = cursorType;
      emit(event);
    }

  std::pair<uint32_t, Geometry*> addGeomtryFromBlob(const Blob& blob) {
      auto blob_key = services.blobService->addBlob(blob);
      const auto* blob_ptr = services.blobService->getBlob(blob_key);
      auto geometryPair = geometries_.insert({blob_key, Geometry{.commandsBlob = blob_ptr}});
      return {blob_key, &geometryPair.first->second} ;
    }

    Geometry* getGeometry(uint32_t key) {
      auto iter = geometries_.find(key);
      if (iter == geometries_.end()) {
        return nullptr;
      }
      return &iter->second;
    }

		Services services;
		Document document;
    EventSystem eventSystem{this};
		RenderSystem renderSystem{this};
		ViewPortSystem viewPortSystem{this};
    SelectSystem selectSystem{this};
  	ActionSystem actionSystem{};
  	ChangeSystem changeSystem{this};
    EditSystem editSystem{this};
    Editor* editor = nullptr;
	private:
    void remapBlobId();
		uint32_t sessionId_ = 0;
    unordered_map<int, Geometry> geometries_{};
    Systems systems_{};
    WindowInfo windowInfo_{};
};
