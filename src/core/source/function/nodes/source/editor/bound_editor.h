#pragma once

#include "editor.h"
#include <vector>

class BoundEditor {
public:
	BoundEditor(Editor* editor);

private:
  Editor* editor_;
};