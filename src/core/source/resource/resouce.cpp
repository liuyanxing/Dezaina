#include "desaina_node.h"
#include <string>
#include <unordered_set>
#include <vector>
class Resource {
public:
		~Resource();

		void load(const std::string& path);
		void unload();

		bool isLoaded() const;
		const std::string& getPath() const;
private:
	GUID guid_;
	std::unordered_set<GUID> consumers_;
};