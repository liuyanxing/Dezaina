#include "document.h"
#include <stdint.h>

struct DesainaOption {
	uint32_t sessionId;
};

class Desaina {
	public:
		Desaina(DesainaOption option): sessionId(option.sessionId) {};
		~Desaina();
		void tick();
		bool loadDocument(const char* buffer, uint32_t size) {
			return document.load(buffer, size);
		};

	private:
		Document document;
		uint32_t sessionId = 0;
};