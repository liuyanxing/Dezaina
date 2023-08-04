#include "document.h"
#include "bound_editor.h"

BoundEditor::BoundEditor(Editor* editor): editor_(editor) {
  const auto* selectedNodes = editor_->getDocument()->getSelectedNodes();
}