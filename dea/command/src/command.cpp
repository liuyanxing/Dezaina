#include "command.h"
#include "cmds.h"
#include "primitives.h"

namespace dea::command {

void Command::buildDefaultCmd() {
	addCmdToRepo<ZoomInCmd>();
	addCmdToRepo<ZoomOutCmd>();
}

}