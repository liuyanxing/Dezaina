#include "edit_system.h"
#include "action_system/UpdatePropertiesAction.h"
#include "desaina_node.h"
#include "edit_system/editor/vector_node_editor.h"
#include "editor/bound_editor.h"
#include "include/core/SkPoint.h"
#include "util/node_props.h"
#include "desaina.h"
#include <iostream>
#include "util/skia.h"
#include "select_system/select_system.h"
#include "edit_system/editor/rectangle_node_editor.h"
#include "edit_system/editor/frame_node_editor.h"

EditSystem::EditSystem(Desaina* desaina) : desaina_(desaina) {
  // 因为依赖顺序问题其它system可能还没有初始化，所以这里延迟到下一帧再绑定事件
  // todo 其它system也应该这么处理
  desaina_->nextTick([this]() {
    bindEvents();
  });
}

void EditSystem::bindEvents() {
  desaina_->selectSystem->addEventListener(EventType::kSelectionChange, [this](Event* event) {
    setEditorBySelection();
  });
  
  addEventListener(EventType::kAny, [this](Event* event) {
    if (editorView_) {
      editorView_->emit(event);
    }
  });
}

void EditSystem::setEditorBySelection() {
  auto selectedNodes = desaina_->document.getSelectedNodes();
  if (selectedNodes.size() == 0) {
    editorView_ = nullptr;
    return;
  }
  
  if (selectedNodes.size() == 1) {
    auto node = selectedNodes[0];
    switch (node->get_type()) {
      case NodeType::ROUNDED_RECTANGLE:
      case NodeType::RECTANGLE: 
      case NodeType::VECTOR: {
        editorView_ = std::make_unique<RectangleNodeEditor>(desaina_);
        break;
      }
      case NodeType::FRAME: {
        editorView_ = std::make_unique<FrameNodeEditor>(desaina_);
        break;
      }
      default: {
        break;
      }
    }
  } else {
    editorView_ = std::make_unique<NodeEditor>(desaina_);
  }
}

void EditSystem::selectCtrlNodeByPoint(const SkPoint& point) {
  if (editorView_ == nullptr) {
    return;
  }
  editorView_->setSelectNodeByPoint(point);
}

void EditSystem::afterTick() {
  if (editorView_ != nullptr) {
    editorView_->update();
  }
}
