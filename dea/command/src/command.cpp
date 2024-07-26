#include "command.h"
#include "cmds.h"
#include "primitives.h"

namespace dea::command {

void Command::buildDefaultCmd() {
	using ZoomIn = ZoomCommand<ZoomCommand<0, "df">::IN, "zoom in">;
}

}