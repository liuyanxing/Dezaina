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
	KeymapSystem();
	~KeymapSystem();

	void addKeymap(Keymap keymap);

	void handleInput();
	void clear();

	// bool fireAction(int actionId, void* param) {
	// 	if (key_map_.find(actionId) != key_map_.end()) {
	// 		return key_map_[actionId].apply(param);
	// 	}
	// 	return false;
	// };

	// void addKeymap(int keyCode, Action action) {
	// 	key_map_[keyCode] = action;
	// };

};
