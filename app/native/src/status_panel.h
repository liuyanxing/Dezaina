#include "dezaina.h"
#include "imgui.h"

inline void CreateStatusPanel(dea::Dezaina &desaina) {
  ImGui::Begin("Status");

  auto &interStatus = desaina.getInteraction().status;
  auto *hoverDocNode = interStatus.hoverDocNode;
  ImGui::Text("hover Node name: %s",
              hoverDocNode ? hoverDocNode->getName().c_str() : "");
  ImGui::Text("mouse world pos: %.2f, %.2f", interStatus.mouseWorldPos.x,
              interStatus.mouseWorldPos.y);
  ImGui::End();
}
