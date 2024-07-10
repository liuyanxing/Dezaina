#include "document.h"

#include "imgui.h"
#include "desaina.h"
#include "kiwi.h"
#include "function/creaet_system/create_system.h"

void CreateNodePanel(Desaina* desaina) {
	ImGui::Begin("Create Node");

	if (ImGui::Button("Rect")) {
    // desaina->createSystem->startCreating<RectangleNode>();
	}

	if (ImGui::Button("Frame")) {
    // desaina->createSystem->startCreating<FrameNode>();
	}

	ImGui::End();
}