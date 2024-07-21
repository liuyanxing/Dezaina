#pragma once

#include "document.h"
#include "editor.h"
#include "change.h"

namespace dea::document {

class Executor {
public:
	Executor(Document& doc, Editor& editor, change::Change& change) : doc_(doc), editor_(editor), change_(change) {}
	bool execute();

private:
	Document& doc_;
	Editor& editor_;
	change::Change& change_;
};

} // namespace dea::document