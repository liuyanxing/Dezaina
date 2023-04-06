#include "document.h"

bool Document::load(const char* buffer, uint32_t size) {
	if (isLoaded) {
		close();
	}
	isLoaded = true;
	return isLoaded;
}

void Document::close() {
}
