#pragma once
#include <algorithm>
#include <cstddef>
#include "primitives.h"
#include "primitives/index.h"
#include "prims.h"
#include "common/const_string.h"


namespace dea::command {

	template <base::ConstString str>
	struct DescriptionProp {
		DescriptionProp() {
			std::copy(str.data, str.data + descSize, description);
		}
		static constexpr size_t descSize = sizeof(str.data);
		char description[descSize];
	};

	enum class ZoomType {
		In,
		Out,
		Fit,
		Reset,
	};
	template <ZoomType type_v, base::ConstString description> 
	struct ZoomCommand {
		struct Props : DescriptionProp<description> {} props;
		struct Args { ZoomType type = type_v; } args;
		static constexpr auto type = CmdType::Zoom;
		static constexpr auto condition = DeaState::Select | DeaState::Edite;
	};

	using ZoomInCmd = ZoomCommand<ZoomType::In, "zoom in">;
	using ZoomOutCmd = ZoomCommand<ZoomType::Out, "zoom out">;
	using ZoomFitCmd = ZoomCommand<ZoomType::Fit, "zoom fit">;
	using ZoomResetCmd = ZoomCommand<ZoomType::Reset, "zoom reset">;

template <AlignType type_v, base::ConstString description> 
	struct AlignCommand {
		struct Props : DescriptionProp<description> {} props;
		struct Args { AlignType type = type_v; } args;
		static constexpr CmdType type = CmdType::Align;
	};

	using AlignLeftCmd = AlignCommand<AlignType::Left, "align left">;
	using AlignRightCmd = AlignCommand<AlignType::Right, "align right">;
	using AlignLeftRightCmd = AlignCommand<AlignType::LeftRight, "align left right">;
	using AlignTopCmd = AlignCommand<AlignType::Top, "align top">;
	using AlignBottomCmd = AlignCommand<AlignType::Bottom, "align bottom">;
	using AlignTopBottomCmd = AlignCommand<AlignType::TopBottom, "align top bottom">;
	using AlignHorizontalCenterCmd = AlignCommand<AlignType::HorizontalCenter, "align horizontal center">;
	using AlignVerticalCenterCmd = AlignCommand<AlignType::VerticalCenter, "align vertical center">;
	using AlignHorizontalSpaceBetweenCmd = AlignCommand<AlignType::HorizontalSpaceBetween, "align horizontal space between">;
	using AlignVerticalSpaceBetweenCmd = AlignCommand<AlignType::VerticalSpaceBetween, "align vertical space between">;

} // namespace dea::command