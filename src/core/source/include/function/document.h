#include "desaina_node.h"

class Document : public DocumentNode
{
public:
	Document() = default;
	~Document();
	bool load(const char* buffer, uint32_t size);
	void close();
private:
	bool isLoaded = false;
};