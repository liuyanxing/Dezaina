#pragma once

#include "desaina.h"
#include "imgui.h"

inline void CreateFilePanel(Desaina* desaina) {
	ImGui::Begin("File");

	if (ImGui::Button("create default file")) {
		desaina->document.createDefaultFile();
	}

	ImGui::End();
}