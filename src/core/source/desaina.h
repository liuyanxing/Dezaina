#pragma once

#include "base_type.h"
#include "desaina_node.h"
#include "document.h"
#include "event_system/event.h"
#include "event_system/event_emitter.h"
#include "include/core/SkPath.h"
#include "kiwi.h"
#include <_types/_uint32_t.h>
#include <functional>
#include <memory>
#include <stdint.h>
#include "select_system/select_system.h"
#include "services/blob_service.h"
#include "services/id_generator.h"
#include "services/services.h"
#include "system/system.h"
#include "types/cursor.h"
#include "util/node_geometry.h"

class EventSystem;
class RenderSystem;
class ViewPortSystem;
class SelectSystem;
class ActionSystem;
class ChangeSystem;
class EditSystem;
class CreateSystem;

struct DesainaOption {
	uint32_t sessionId;
};

struct WindowInfo {
  int width;
  int height;
  float devicePixelRatio;
};



using BlobReMap = unordered_map<uint32_t, uint32_t>;
using Systems = vector<System*>;
using NextTickHandler = std::function<void()>;

class Desaina : public EventEmitter {
	public:
		Desaina(DesainaOption option):
			sessionId_(option.sessionId),
			services({std::make_unique<IdGenerator>(option.sessionId), std::make_unique<BlobService>()}),
			document(&services) {
        addSystems();
        buildEvents();
      };
		~Desaina() = default;
		void tick();
    void nextTick(const NextTickHandler& nextTickHandler) {
      nextTickHandlers_.push_back(nextTickHandler);
    }

		bool loadDocument(kiwi::ByteBuffer& buffer);

    void buildEvents();
    template<typename T, typename N>
    void registerSystem(N** desainaSystem);
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

    BlobPair addBlob(const Blob& blob) {
      auto blob_key = services.blobService->addBlob(blob);
      auto* blob_ptr = services.blobService->getBlob(blob_key);
      return {blob_key, blob_ptr} ;
    }

    Blob* getBlob(uint32_t key) {
      return services.blobService->getBlob(key);
    }

    uint32_t frame() {
      return frameCount;
    }

		Services services;
		Document document;
    EventSystem* eventSystem = nullptr;
		RenderSystem* renderSystem = nullptr;
		ViewPortSystem* viewPortSystem = nullptr;
    SelectSystem* selectSystem = nullptr;
  	ActionSystem* actionSystem = nullptr;
  	ChangeSystem* changeSystem = nullptr;
    EditSystem* editSystem = nullptr;
    CreateSystem* createSystem = nullptr;
	private:
    void remapBlobId();
		uint32_t sessionId_ = 0;
    unordered_map<int, Geometry> geometries_{};
    Systems systems_{};
    WindowInfo windowInfo_{};
    uint32_t frameCount = 0;
    vector<NextTickHandler> nextTickHandlers_{};
};
