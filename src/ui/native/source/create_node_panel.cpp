#include "document.h"
#include "frame.h"
#include "type_traits"

#include "desaina_node.h"
#include "imgui.h"
#include "desaina.h"
#include "function/change/desaina_change.h"
#include "kiwi.h"
#include "function/creaet_system/create_system.h"

void CreateNodePanel(Desaina* desaina) {
	ImGui::Begin("Create Node");

	if (ImGui::Button("Rect")) {
    desaina->createSystem->startCreating<RectangleNode>();
	}

	if (ImGui::Button("Frame")) {
    desaina->createSystem->startCreating<FrameNode>();
	}

	ImGui::End();
}