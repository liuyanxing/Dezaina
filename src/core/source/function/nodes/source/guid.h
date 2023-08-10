
#include "desaina_node.h"
#include <cstdint>

inline uint32_t hashGUID(const GUID& guid) {
	return (guid.get_sessionID() << (31 - 12)) + guid.get_localID();
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
			return lhs.sessionId == rhs.sessionId && lhs.localId == rhs.localId;
		}
	};
}
