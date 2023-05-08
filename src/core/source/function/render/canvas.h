#include "document.h"
#include "include/core/SkMatrix.h"
#include "include/core/SkRefCnt.h"
#include "include/core/SkSurface.h"
#include "page.h"

struct CanvasOptions {
		int width = 800;
		int height = 600;
		int devicePixelRatio = 1;
};

class Canvas {
public:
		Canvas(Document* doc) : document_(doc) {};
		~Canvas() = default;
		void initCanvas(const CanvasOptions& options) {
			auto& [width, height, devicePixelRatio] = options;

			onWindowResize(width, height, devicePixelRatio);
			createSurface();
		};

		void onWindowResize(int width, int height, int devicePixelRatio) {
			devicePixelRatio_ = devicePixelRatio;
			width_ = width * devicePixelRatio_;
			height_ = height * devicePixelRatio_;
			projection_matrix_.setScale(devicePixelRatio_, devicePixelRatio_, width_ / 2., height_ / 2.);
			vp_matrix_ = view_matrix_ * projection_matrix_;
		};

		bool createSurface();

		void drawNode(const Node *node);
		void drawPage(PageNode *page);

		void setWidth(int width);
		void setHeight(int height);
		void setBuffer(void *buffer);

		int width() const;
		int height() const;
		void *buffer() const;

		SkMatrix getVPMatrix() const {
			return vp_matrix_;
		};

		void clear();
		void tick();
private:
		int width_;
		int height_;
		int devicePixelRatio_;
		void *buffer_;
		SkMatrix view_matrix_;
		SkMatrix projection_matrix_;
		SkMatrix vp_matrix_;
		sk_sp<SkSurface> surface_{nullptr};
		SkCanvas* canvas_{nullptr};
		Document* document_{nullptr};
		
};