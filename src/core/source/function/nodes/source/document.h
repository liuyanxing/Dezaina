#include "desaina_node.h"
#include <vector>
#include <memory>
#include "page.h"
#include "frame.h"
#include "rectangle.h"

class Document : public DocumentNodeBase
{
public:
	Document() = default;
	~Document();
	bool load(const char* buffer, uint32_t size);
	void close();
	void appendChild(std::shared_ptr<PageNode>& page);

	// 创建node唯一的入口
	RectangleNode& createRectNode();
	FrameNode& createFrameNode();
private:
	bool isLoaded = false;
	std::vector<std::shared_ptr<PageNode>> children;
};