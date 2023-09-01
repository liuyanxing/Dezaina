#pragma once

#include "base_type.h"
#include "desaina_node.h"
#include "document.h"
#include "kiwi.h"
#include <memory>
#include <stdint.h>
#include "select_system/select_system.h"
#include "services/id_generator.h"
#include "services/services.h"
#include "event_system/event_system.h"
#include "render_system/render_system.h"
#include "system/system.h"
#include "viewport_system/viewport_system.h"
#include "action_system/action_system.h"

struct DesainaOption {
	uint32_t sessionId;
};

struct WindowInfo {
  int width;
  int height;
  float devicePixelRatio;
};

using Systems = vector<System*>;

class Desaina {
	public:
		Desaina(DesainaOption option):
			sessionId_(option.sessionId),
			services({std::make_unique<IdGenerator>(option.sessionId)}),
			document(&services) {
        buildEvents();
        addSystems();
      };
		~Desaina() = default;
		void tick();
		bool processMessage(kiwi::ByteBuffer& buffer);
		void applyNodeChanges(const Desaina_Kiwi::Message& message);
		void applyNodeChange(const Desaina_Kiwi::NodeChange& node_change);

		bool loadDocument(kiwi::ByteBuffer& buffer) {
			bool is_loaded = processMessage(buffer);
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

		Services services;
		Document document;
    EventSystem eventSystem{this};
		RenderSystem renderSystem{this};
		ViewPortSystem viewPortSystem{this};
    SelectSystem selectSystem{this};
  	ActionSystem actionSystem{};
	private:
		uint32_t sessionId_ = 0;
    vector<DataSharedPtr> blobs_;
    Systems systems_{};
    WindowInfo windowInfo_{};
};
