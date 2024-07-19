#pragma once

#include "common/buffer.h"
#include "resource.h"
#include <cassert>
#include <unordered_set>
#include <vector>

namespace dea::resource {

class ImageResourceItem : public ResourceItem {
public:
	ImageResourceItem(ResourceType type) : ResourceItem(type) {}
  const auto* data() const { return data_; }
private:
	base::Data* data_;
};

class ImageResourceProvider : public ResourceProvider {
public:
	ImageResourceItem* store(const base::Data& resource) {
		if (resources_.find(&resource) != resources_.end()) {
			return nullptr;
		}
	  auto* item =	&resourceItems_.emplace_back(type_);
		auto& instance = Resource::getInstance();
		instance.add(item);
		return item;
	}

	void remove(const ResourceItem* item) {
	}

	bool has(const base::Data& data) const {
		return resources_.find(&data) != resources_.end();
	}

	bool isType(ResourceType type) const override {
		return type == type_;
	}

	void setType(ResourceType type) override {
		type_ = type;
		Type_ = type;
	}

	static auto Type() {
		return Type_;	
	}

private:
	static ResourceType Type_;
	static std::unordered_set<const base::Data*> resources_;
	static inline std::vector<ImageResourceItem> resourceItems_;
};

struct ImageResource {
	friend class ImageResourceProvider;

	static ResourceItem* add(const base::Data& data) {
		auto& instance = Resource::getInstance();
		auto* provider = static_cast<ImageResourceProvider*>(instance.getProvider(ResourceProvider::Type()));
		assert(provider);

		return provider->store(data);
	}
};

} // namespace dea::resource