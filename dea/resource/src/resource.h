#pragma once

#include <cstdint>
#include <memory>
#include <unordered_map>
#include <vector>

namespace dea::resource {
using ResourceId = uint32_t;
using ResourceType = uint8_t;

class ResourceItem {
public:
  ResourceItem(ResourceType type) : type_(type) {}
	ResourceId id() const { return id_; }
  ResourceType type() const { return type_; }
	virtual ~ResourceItem();
private:
  ResourceId id_;
  ResourceType type_;
};

class ResourceProvider {
public:
	virtual void remove(const ResourceItem* item) = 0;
	virtual bool isType(ResourceType type) const { return type == type_; }
	virtual ~ResourceProvider() = default;
	virtual void setType(ResourceType type) = 0;
protected:
	ResourceType type_;
};

class Resource {
friend class ResourceItem;
public:
	static Resource& getInstance() {
		static Resource instance;
		return instance;
	}

	static void Init();

	ResourceId add(const ResourceItem* item) {
		auto id = nextId_++;
		resources_.emplace(id, *item);
		return id;
	}

	void addProvider(std::unique_ptr<ResourceProvider>&& provider) {
	  provider->setType(nextType_++);
		providers_.push_back(std::move(provider));
	}

	ResourceProvider* getProvider(ResourceType type) {
		for (auto& provider : providers_) {
			if (provider->isType(type)) {
				return provider.get();
			}
		}
		return nullptr;
	}

	ResourceItem* get(ResourceId id) {
		auto it = resources_.find(id);
		if (it != resources_.end()) {
		}
		return nullptr;
	}

	// delte copy
	Resource(const Resource&) = delete;
	Resource& operator=(const Resource&) = delete;

private:
  void remove(const ResourceItem* item) {
	  for (auto& provider : providers_) {
		  if (provider->isType(item->type())) {
			  provider->remove(item);
				resources_.erase(item->id());
			  return;
		  }
	  }
	}

	Resource() = default;
	std::vector<std::unique_ptr<ResourceProvider>> providers_;
	ResourceType nextType_ = 1;
	ResourceId nextId_ = 1;
	std::unordered_map<ResourceId, ResourceItem> resources_;
};

} // namespace dea::change