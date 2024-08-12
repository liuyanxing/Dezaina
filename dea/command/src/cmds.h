#pragma once
#include <algorithm>
#include <cstddef>
#include "primitives.h"
#include "primitives/index.h"
#include "prims.h"
#include "common/const_string.h"


namespace dea::command {

	template <base::ConstString str>
	struct CommandProp {
		CommandProp() {
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
	template <ZoomType type_v,base::ConstString idStr, base::ConstString description> 
	struct ZoomCommand {
		struct Props : CommandProp<description> { ZoomType type = type_v; } props;
		struct Args { void parse(const kiwi::buffer& args) {} } args;
		static constexpr auto type = CmdType::Zoom;
		static constexpr auto condition = DeaState::Select | DeaState::Edite;
		static constexpr auto id = idStr.hash(); 
	};

	using ZoomInCmd = ZoomCommand<ZoomType::In, "zoom in">;
	using ZoomOutCmd = ZoomCommand<ZoomType::Out, "zoom out">;
	using ZoomFitCmd = ZoomCommand<ZoomType::Fit, "zoom fit">;
	using ZoomResetCmd = ZoomCommand<ZoomType::Reset, "zoom reset">;

	template <AlignType type_v, base::ConstString description> 
	struct AlignCommand {
		struct Props : CommandProp<description> { AlignType type = type_v; } props;
		struct Args {  } args;
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