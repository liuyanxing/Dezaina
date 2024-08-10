#include "cmds.generated.h"
#include "command.h"

namespace dea::command {

void Command::buildDefaultCmd() {
	addCmdToRepo<ZoomIn>();
}

} // namespace dea::command
