#pragma once

#include "document/include/document.h"
#include "viewport/include/viewport.h"

namespace dea {

class Dezaina {
public:
	Dezaina() : doc_(0) {
	}
	bool loadDocument(char* data, size_t size) {
		return doc_.load(data, size);
	}

	void initViewport(uint32_t width, uint32_t height, float devicePixelRatio) {
		viewport_.update(width, height, devicePixelRatio);
	}
private:
	document::Document doc_;
	ViewPort viewport_;
};

}