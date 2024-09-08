#pragma once

#include <cassert>
#include <fstream>
#include <filesystem>
#include <memory>
#include <iostream>
#include "dezaina.h"
#include "imgui.h"

inline void CreateFilePanel(dea::Dezaina& desaina) {
	ImGui::Begin("File");

	if (ImGui::Button("create default file")) {
		// desaina->document.createDefaultFile();
	}

	if (ImGui::Button("save file to local")) {
		// std::fstream file;
		// file.open("test.desaina", std::ios::out | std::ios::binary);
		// kiwi::ByteBuffer buffer;
		// if (!desaina->encode(buffer)) {
		// 	assert(false);
		// }
		// file.write((char*)buffer.data(), buffer.size());
	}

	if (ImGui::Button("load file from local")) {
    std::filesystem::path fig_dir = std::filesystem::current_path() / "figs";
		std::fstream file;
		file.open(fig_dir / "round-rect", std::ios::in | std::ios::binary);
		if (!file.is_open()) {
			std::cout << fig_dir << std::endl;
			return;
		}
		file.seekg(0, std::ios::end);
		auto size = file.tellg();
		std::shared_ptr<char[]> data(new char[size]);
		file.seekg(0, std::ios::beg);
		file.read(data.get(), size);
		desaina.loadDocument(data.get(), size);
	}

	ImGui::End();
}