#pragma once

#include <cassert>
#include <fstream>
#include <filesystem>
#include <memory>
#include "dezaina.h"
#include "imgui.h"
#include "loader.h"

inline void CreateNodePanel(dea::Dezaina& desaina) {
	if (ImGui::Button("Rectangle")) {
		desaina.startCreateNode("rectangle");
	}
	if (ImGui::Button("Frame")) {
		desaina.startCreateNode("frame");
	}
	if (ImGui::Button("Polygon")) {
		desaina.startCreateNode("polygon");
	}
	if (ImGui::Button("Star")) {
		desaina.startCreateNode("star");
	}
	if (ImGui::Button("Ellipse")) {
		desaina.startCreateNode("ellipse");
	}
	if (ImGui::Button("Line")) {
		desaina.startCreateNode("line");
	}
	if (ImGui::Button("Text")) {
		desaina.startCreateNode("text");
	}
}

inline void NodePropsPanel(dea::Dezaina& desaina) {
}

inline void CreateInterPanel(dea::Dezaina& desaina) {
	ImGui::Begin("interaction");

	if (ImGui::Button("load fig")) {
    std::filesystem::path fig_dir = std::filesystem::current_path() / "figs" / "all shapes.fig";
    // std::filesystem::path fig_dir = std::filesystem::current_path() / "figs" / "text.fig";
		auto& loader = loader::Loader::getInstance();
		loader.loadFig(fig_dir.string());
		desaina.loadFig(loader.getFig());
	}

	CreateNodePanel(desaina);

	ImGui::End();
}