#pragma once

#include "desaina_node.h"
#include "document.h"
#include <stdint.h>

class IdGenerator {
public:
	IdGenerator(uint32_t sessionId);
  GUID genId() {
		return { sessionId, localId++ };
	}
private:
	uint32_t sessionId;
	uint32_t localId = 0;
};

struct DesainaOption {
	uint32_t sessionId;
};

class Desaina {
	public:
		Desaina(DesainaOption option): sessionId(option.sessionId), idGenerator(option.sessionId) {};
		~Desaina();
		void tick();
		bool processMessage(uint8_t *buffer, uint32_t size);
		void applyNodeChanges(Desaina_Kiwi::Message message);
		void applyNodeChange(Desaina_Kiwi::NodeChange node_change);

		bool loadDocument(uint8_t* buffer, uint32_t size) {
			bool is_loaded = processMessage(buffer, size);
			if (!is_loaded) {
				return false;
			}
			document.set_loaded(true);
			return true;
		};

		IdGenerator idGenerator;
	private:
		Document document;
		uint32_t sessionId = 0;
};