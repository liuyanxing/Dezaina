#pragma once

#include <cassert>
#include <fstream>
#include "desaina.h"
#include "imgui.h"

inline void CreateFilePanel(Desaina* desaina) {
	ImGui::Begin("File");

	if (ImGui::Button("create default file")) {
		desaina->document.createDefaultFile();
	}

	if (ImGui::Button("save file to local")) {
		std::fstream file;
		file.open("test.desaina", std::ios::out | std::ios::binary);
		kiwi::ByteBuffer buffer;
		if (!desaina->encode(buffer)) {
			assert(false);
		}
		file.write((char*)buffer.data(), buffer.size());
	}

	ImGui::End();
}