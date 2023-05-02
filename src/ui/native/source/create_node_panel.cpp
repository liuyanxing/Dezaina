#include "document.h"
#include "type_traits"

#include "desaina_node.h"
#include "imgui.h"
#include "desaina.h"
#include "function/change/desaina_change.h"
#include "kiwi.h"

void CreateNodePanel(Desaina* desaina) {
	ImGui::Begin("Create Node");

	if (ImGui::Button("Rect")) {
		kiwi::ByteBuffer buffer;
		desaina_change::createMessageBuffer(NodeType::RECTANGLE, buffer, desaina);	
		desaina->processMessage(buffer);
	}

	if (ImGui::Button("Frame")) {
		kiwi::ByteBuffer buffer;
		desaina_change::createMessageBuffer(NodeType::FRAME, buffer, desaina);	
		desaina->processMessage(buffer);
	}

	ImGui::End();
}