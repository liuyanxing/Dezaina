
#include "desaina_node.h"
#include <cstdint>

inline uint32_t hashGUID(const GUID& guid) {
  auto sessionID = guid.get_sessionID();
	return (sessionID << (31 - 12)) + guid.get_localID();
}

namespace std {
	template<>
	struct hash<GUID> {
		size_t operator()(const GUID& guid) const {
			return hashGUID(guid);
		}
	};

	template<>
	struct equal_to<GUID> {
		bool operator()(const GUID& lhs, const GUID& rhs) const {
			return lhs.get_sessionID() == rhs.get_sessionID() && lhs.get_localID() == rhs.get_localID();
		}
	};
}
