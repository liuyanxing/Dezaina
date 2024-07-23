#include "resource.h"
#include "blob.h"

namespace dea::resource {

ResourceItem::~ResourceItem() {
	Resource::getInstance().remove(this);
}

void Resource::Init() {
	Resource::getInstance().addProvider(std::make_unique<BlobResourceProvider>());
}

} // namespace dea::resource