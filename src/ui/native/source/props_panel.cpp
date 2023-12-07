#include "props_panel.h"
#include "base/math.h"
#include "imgui.h"
#include "util/node_geometry.h"
#include <cmath>

void CreatePropsPanel(Desaina* desaina) {
  // ImGui::Begin("Props");

  // auto* editor = desaina->editSystem->getEditor();
  // if (!editor) {
  //   ImGui::End();
  //   return;
  // }

  // auto transform = editor->getEditTransform();
  // float rotation = base::getRotation(transform);
  // if (ImGui::InputFloat("rotation", &rotation)) {
  //   editor->setRotatation(rotation);
  // }

  // float x = transform.getTranslateX();
  // if (ImGui::InputFloat("x", &x)) {
  //   editor->setTranslateX(x);
  // }

  // float y = transform.getTranslateY();
  // if (ImGui::InputFloat("y", &y)) {
  //   editor->setTranslateY(y);
  // }
  // ImGui::Text("%.2f %.2f %.2f", transform.get(0), transform.get(1), transform.get(2));
  // ImGui::Text("%.2f %.2f %.2f", transform.get(3), transform.get(4), transform.get(5));
  // ImGui::End();
}
