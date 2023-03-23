#include <stdint.h>
#include "document.h"

class Device {
	int type;
	int id;
	virtual void handleInput() = 0;
	virtual void clear() = 0;
}

class MouseDevice : public Device {
	buffer;
	handleInput();
};

class KeyboardDevice : public Device {
	buffer;
	handleInput();
};

struct DesainaOptions {
	int width;
	int height;
	int deviceRatio;
	int device;
};

class IOSystem {
	// EventSystem is a singleton
	IOSystem(Desaina&);
	~IOSystem();
	std::vector<Device> devices;
	mountDevice(Device device);
	unmountDevice(int device);
};

clas Viewport {
	Matrix matrix;
};

class Desaina {
	public:
		Desaina();
		~Desaina();
		void init();
		void tick();
		void render();
		void quit();
		bool loadDocument(const char* buffer, uint32_t size) {
			// load document
		};
};