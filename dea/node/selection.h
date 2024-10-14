#include <vector>
#include "node.h"

namespace dea::node {
class Selection {
public:
	auto& getSelection() { return selection; }
	void setSelection(const std::vector<node::GUID>& nodes) { selection = std::move(nodes) ; }
private:
	std::vector<node::GUID> selection;
};

}