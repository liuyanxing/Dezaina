#include "document.h"
#include <stdint.h>

class Desaina {
	public:
		Desaina();
		~Desaina();
		void tick();
		bool loadDocument(const char* buffer, uint32_t size);

	private:
		Document document;
		uint32_t sessionId = 0;
};