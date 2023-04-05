#include <unordered_map>
class System {
public:
	System();
	~System();

	virtual void mount();
	virtual void unmount();
};

class KeymapSystem : public System {
public:
	key_map_ = std::unordered_map<int, Action>();
	KeymapSystem();
	~KeymapSystem();

	void addKeymap(Keymap keymap);

	void handleInput();
	void clear();

	bool fireAction(int actionId, void* param) {
		if (key_map_.find(actionId) != key_map_.end()) {
			return key_map_[actionId].apply(param);
		}
		return false;
	};

	void addKeymap(int keyCode, Action action) {
		key_map_[keyCode] = action;
	};

	handleKeydown(int keyCode) {
		if (key_map_.find(keyCode) != key_map_.end()) {
			key_map_[keyCode].apply();
		}
		if (keycode == "delet") {
			fireAction(0, "curSelectId");
		}
	};
};

KeymapSystem.addAction(0, DelteNodeAction);

KeymapSystem.fireAction(0, "nodeId");