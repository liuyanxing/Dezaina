#pragma once
#include "primitives.h"
#include <algorithm>
#include "common/const_string.h"

#include <cstddef>
#include <string>

namespace dea::command {

	template <base::ConstString str>
	struct DescriptionProp {
		DescriptionProp() {
			constexpr size_t size = sizeof(str.data);
			std::copy(str.data, str.data + size, description);
		}
		char description[sizeof(str.data)];
	};

	enum class ZoomType {
		IN,
		OUT,
		FIT,
		RESET
	};
	template <ZoomType Type, base::ConstString str> 
	struct ZoomCommand {
		struct Props : DescriptionProp<str> {};
		struct Args {
			ZoomType type = Type;
		};
		static constexpr CmdType type = CmdType::Zoom;
	};

	enum class AlignType {
		Left,
		Right,
		LeftRight,
		Top,
		Bottom,
		TopBottom,
		HorizontalCenter,
		VerticalCenter,
	  HorizontalSpaceBetween,
		VerticalSpaceBetween,
	};
	template <AlignType Type, base::ConstString str> 
	struct AlignCommand {
		struct Props : DescriptionProp<str> {};
		struct Args {
			AlignType type = Type;
		};
		static constexpr CmdType type = CmdType::Align;
	};

} // namespace dea::command