#include "include/core/SkMatrix.h"

class SceneNode;

struct CanvasOptions {
		int width = 800;
		int height = 600;
		int devicePixelRatio = 1;
};

class Canvas {
public:
		Canvas(CanvasOptions options) : width_(options.width), height_(options.height), devicePixelRatio_(options.devicePixelRatio) {
      createSurface();
    };
		~Canvas();

    bool createSurface();

		void drawNode(SceneNode *node);

		void setWidth(int width);
		void setHeight(int height);
		void setBuffer(void *buffer);

		int width() const;
		int height() const;
		void *buffer() const;

		void clear();
private:
		int width_;
		int height_;
		int devicePixelRatio_;
		void *buffer_;
		SkMatrix viewport_;
};