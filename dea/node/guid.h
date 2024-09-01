#include "node.h"

#include <cstdint>

inline uint32_t hashGUID(const dea::node::GUID& guid) {
  auto sessionID = guid.sessionID;
	return (sessionID << (31 - 12)) + guid.localID;
}

namespace std {
	template<>
	struct hash<dea::node::GUID> {
		size_t operator()(const dea::node::GUID& guid) const {
			return hashGUID(guid);
		}
	};

	template<>
	struct equal_to<dea::node::GUID> {
		bool operator()(const dea::node::GUID& lhs, const dea::node::GUID& rhs) const {
			return lhs.sessionID == rhs.sessionID && lhs.localID == rhs.localID;
		}
	};
}
