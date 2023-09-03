#include "document.h"
#include "bound_editor.h"
#include "desaina.h"
#include "include/core/SkRect.h"
#include "util/node_geometry.h"

BoundEditor::BoundEditor(Editor* editor): editor_(editor) {
  init();
}

void BoundEditor::init() {
  buildBound();
  bindEvents();
  bindInteractionArea();
}

void BoundEditor::buildBound() {
  auto selectedNodes = editor_->getEditingNodes();
  bound_.setEmpty();
  for (auto node : selectedNodes) {
    auto bound = util::getWorldBound(node, &editor_->desaina->document);
    bound_.join(bound);
  }
}

void BoundEditor::bindInteractionArea() {
}

void BoundEditor::bindEvents() {
  editor_->addEventListener(EventType::kMouseDrag, [this](Event* event) {
    handleMouseDrag(event);
  });
}

void BoundEditor::handleMouseDrag(Event* event) {
  auto& actionSystem = editor_->desaina->actionSystem;
  auto mouseEvent = static_cast<MouseEvent*>(event);
  auto selectedNodes = editor_->getEditingNodes();
  auto deltaX = mouseEvent->deltaX;
  auto deltaY = mouseEvent->deltaY;
  
  for (auto node : selectedNodes) {
    auto m = util::getTransfromMatrix(node);
    m.postTranslate(deltaX, deltaY);
    PropertyType type = PropertyType::kTransform;
    PropertyValue transform = util::toMatrix(m);
    actionSystem.addAction(UpdatePropertiesAction::Make(node->get_guid(), type, transform));
  }
  editor_->setDirty();
}


