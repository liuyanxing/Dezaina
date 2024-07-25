#pragma once

#include "document/include/document.h"
#include "viewport/viewport.h"

namespace dea {

class Dezaina {
public:
	Dezaina() : doc_(0) {
	}
	bool loadDocument(char* data, size_t size) {
		auto res = doc_.load(data, size);
		doc_.dump();
		return res;
	}

	void initViewport(uint32_t width, uint32_t height, float devicePixelRatio) {
		viewport_.update(width, height, devicePixelRatio);
	}

	void dumpDocument() {
		doc_.dump();
	}

private:
	document::Document doc_;
	ViewPort viewport_;
};

}