#include <string>

struct Command {
	char name[32];
	char description[128];
	virtual bool apply() = 0;
};
