#pragma once

#include <cassert>
#include <fstream>
#include <filesystem>
#include <memory>
#include <iostream>
#include "dezaina.h"
#include "imgui.h"
#include "loader.h"

inline void CreateFilePanel(dea::Dezaina& desaina) {
	ImGui::Begin("File");

	if (ImGui::Button("load fig")) {
    std::filesystem::path fig_dir = std::filesystem::current_path() / "figs" / "all shapes.fig";
    // std::filesystem::path fig_dir = std::filesystem::current_path() / "figs" / "text.fig";
		auto& loader = loader::Loader::getInstance();
		loader.loadFig(fig_dir.string());
		desaina.loadFig(loader.getFig());
	}

	ImGui::End();
}