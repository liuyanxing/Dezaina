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

	static constexpr ResourceType Type = ResourceType::Blob;
private:
	base::Data data_;
};

} // namespace dea::resource

namespace std {
template<>
struct hash<dea::resource::BlobResourceItem> {
	size_t operator()(const dea::resource::BlobResourceItem& item) const {
		return std::hash<dea::base::Data>()(*item.data());
	}
};

template<>
struct equal_to<dea::resource::BlobResourceItem> {
	bool operator()(const dea::resource::BlobResourceItem& lhs, const dea::resource::BlobResourceItem& rhs) const {
		bool isEqual = *lhs.data() == *rhs.data();
		if (isEqual) {
			return true;
		}
		return false;
	}
};

} // namespace std

namespace dea::resource {
class BlobResourceProvider : public ResourceProvider {
public:
	BlobResourceProvider() : ResourceProvider(ResourceType::Blob) {}
	BlobResourceProvider(const BlobResourceProvider&) = delete;

	BlobResourceItem* store(base::Data&& data) {
		auto iter = data_.insert(BlobResourceItem{ std::move(data) }).first;
		auto& instance = Resource::getInstance();
		BlobResourceItem* item = const_cast<BlobResourceItem*>(&(*iter));
		instance.add(item);
		return item;
	}

	void remove(const ResourceItem* item) override {
	}

	bool has(const base::Data& data) const {
		
	}

	static constexpr ResourceType Type = ResourceType::Blob;

private:
	std::unordered_set<BlobResourceItem> data_;
};

} // namespace dea::resource