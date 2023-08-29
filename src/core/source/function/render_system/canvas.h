#pragma once

#include "desaina_node.h"
#include "document.h"
#include "include/core/SkCanvas.h"
#include "include/core/SkColor.h"
#include "include/core/SkMatrix.h"
#include "include/core/SkPaint.h"
#include "include/core/SkPath.h"
#include "include/core/SkRect.h"
#include "include/core/SkRefCnt.h"
#include "include/core/SkSurface.h"
#include "util/node_props.h"

#include "page.h"

class Document;
class Desaina;

struct CanvasOptions {
		int width = 800;
		int height = 600;
		int devicePixelRatio = 1;
};

class Canvas {
public:
		Canvas(Desaina* desaina);
		~Canvas() = default;

		void onWindowResize(int width, int height, int devicePixelRatio) {
			devicePixelRatio_ = devicePixelRatio;
			width_ = width * devicePixelRatio_;
			height_ = height * devicePixelRatio_;
			createSurface();
		};

		bool createSurface();

		void drawNode(const Node *node);
    void drawText(const TextNode *text);
		void drawPage(PageNode *page);

    void drawGeometry(const vector<SkPath> &geometry, const vector<PaintWithRect> &paints);


		void setWidth(int width);
		void setHeight(int height);
		void setBuffer(void *buffer);

		int width() const;
		int height() const;
		void *buffer() const;

		void clear();
		void tick();
private:
		int width_;
		int height_;
		int devicePixelRatio_;
		void *buffer_;
		sk_sp<SkSurface> surface_{nullptr};
		SkCanvas* canvas_{nullptr};
    Desaina* desaina_{nullptr};
    Document* document_{nullptr};
		
};
