#pragma once

#include <cstdint>
#include <iostream>
#include <memory>
#include <unordered_map>
#include <utility>
#include <vector>
#include "primitives.h"
#include "common/object.h"

namespace dea::resource {
using ResourceId = uint32_t;

class ResourceAttachment {
public:
	virtual ~ResourceAttachment() = default;
};

class ResourceItem : public base::NonCopyable {
friend class Resource;
public:
  ResourceItem(ResourceType type) : type_(type) {}

	ResourceItem(ResourceItem&& other) : id_(other.id_), type_(other.type_), attachment_(std::move(other.attachment_)) {
		other.id_ = 0;
		other.attachment_ = nullptr;
	}

	ResourceId id() const { return id_; }
  ResourceType type() const { return type_; }

	void setAttachment(std::unique_ptr<ResourceAttachment> attachment) { attachment_ = std::move(attachment); }
	template<typename T>
	auto* attachment() const {
    if (attachment_ == nullptr) {
      return static_cast<T>(nullptr);
    }
    return static_cast<T>(attachment_.get());
  }

	virtual ~ResourceItem();
private:
  ResourceId id_{};
  ResourceType type_;
  std::unique_ptr<ResourceAttachment> attachment_ = nullptr;
};

class ResourceProvider {
public:
	ResourceProvider(ResourceType type) : type_(type) {}
	virtual void remove(const ResourceItem* item) = 0;
	virtual bool isType(ResourceType type) const { return type == type_; }
	virtual ~ResourceProvider() = default;
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

	template<typename T = ResourceItem*>
	static auto Get(ResourceId id) {
		return static_cast<T>(getInstance().get(id));
	}

	ResourceId add(ResourceItem* item) {
		auto id = nextId_++;
		resources_[id] = item;
    item->id_ = id;
  
		return id;
	}

	void addProvider(std::unique_ptr<ResourceProvider>&& provider) {
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
      return it->second;
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
	ResourceId nextId_ = 1;
	std::unordered_map<ResourceId, ResourceItem*> resources_;
};

} // namespace dea::change