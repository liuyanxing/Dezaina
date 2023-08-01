#pragma once

#include "desaina_node.h"
#include "document.h"
#include "kiwi.h"
#include <memory>
#include <stdint.h>
#include "services/id_generator.h"
#include "services/services.h"
#include "function/event_system/event_system.h"

struct DesainaOption {
	uint32_t sessionId;
};

class Desaina {
	public:
		Desaina(DesainaOption option):
			sessionId_(option.sessionId),
			services({std::make_unique<IdGenerator>(option.sessionId)}),
			document(&services) {
        buildEvents();
      };
		~Desaina() = default;
		void tick();
		bool processMessage(uint8_t *buffer, uint32_t size);
		bool processMessage(kiwi::ByteBuffer& buffer);
		void applyNodeChanges(const Desaina_Kiwi::Message& message);
		void applyNodeChange(const Desaina_Kiwi::NodeChange& node_change);

		bool loadDocument(uint8_t* buffer, uint32_t size) {
			bool is_loaded = processMessage(buffer, size);
			if (!is_loaded) {
				return false;
			}
			document.setLoaded(true);
			document.buildDocTree();
			document.builPath();
			return true;
		};

    void buildEvents();

		bool encode(kiwi::ByteBuffer& buffer);

		Document document;
		Services services;
    EventSystem eventSystem;
	private:
		uint32_t sessionId_ = 0;
};