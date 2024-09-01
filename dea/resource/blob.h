#pragma once

#include "base/data.h"
#include "resource.h"
#include <cassert>
#include <unordered_set>
#include <vector>

namespace dea::resource {

class BlobResourceItem : public ResourceItem {
public:
	BlobResourceItem(ResourceType type, base::Data&& data) : ResourceItem(type), data_(std::move(data)) {}
	BlobResourceItem(BlobResourceItem&& other) : ResourceItem(std::move(other)), data_(std::move(other.data_)) {}

  const auto* data() const { return &data_; }
private:
	base::Data data_;
};

class BlobResourceProvider : public ResourceProvider {
public:
	BlobResourceProvider() : ResourceProvider(Type) {}
	BlobResourceProvider(const BlobResourceProvider&) = delete;

	BlobResourceItem* store(base::Data&& data) {
		if (data_.find(data) != data_.end()) {
			return nullptr;
		}
	  auto item = &resourceItems_.emplace_back(Type, std::move(data));
		auto& instance = Resource::getInstance();
		instance.add(item);
		return item;
	}

	void remove(const ResourceItem* item) override {
	}

	bool has(const base::Data& data) const {
		return data_.find(data) != data_.end();
	}

	static inline constexpr ResourceType Type = ResourceType::Blob;
private:
	static inline std::unordered_set<base::Data> data_;
	static inline std::vector<BlobResourceItem> resourceItems_;
};

struct BlobResource {
	friend class BlobResourceProvider;

	static ResourceItem* add(base::Data&& data) {
		auto& instance = Resource::getInstance();
		auto* provider = static_cast<BlobResourceProvider*>(instance.getProvider(BlobResourceProvider::Type));
		assert(provider);

		return provider->store(std::move(data));
	}
};

} // namespace dea::resource