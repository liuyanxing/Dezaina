#pragma once

#include "base/data.h"
#include "resource.h"
#include <cassert>
#include <unordered_set>
#include "primitives.h"

namespace dea::resource {

class BlobResourceItem : public ResourceItem {
public:
	BlobResourceItem(base::Data&& data) : ResourceItem(ResourceType::Blob), data_(std::move(data)) {}
	BlobResourceItem(BlobResourceItem&& other) : ResourceItem(std::move(other)), data_(std::move(other.data_)) {}

  const auto* data() const { return &data_; }
private:
	base::Data data_;
};

class BlobResourceProvider : public ResourceProvider {
public:
	BlobResourceProvider() : ResourceProvider(ResourceType::Blob) {}
	BlobResourceProvider(const BlobResourceProvider&) = delete;

	BlobResourceItem* store(base::Data&& data) {
		if (data_.find(data) != data_.end()) {
			return nullptr;
		}
	  auto item = &data_.emplace(std::move(data)).second;
		auto& instance = Resource::getInstance();
		instance.add(item);
		return item;
	}

	void remove(const ResourceItem* item) override {
	}

	bool has(const base::Data& data) const {
		return data_.find(data) != data_.end();
	}

private:
	std::unordered_set<BlobResourceItem> data_;
};

} // namespace dea::resource