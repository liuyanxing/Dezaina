#pragma once

#include "../include/editor.h"
#include "change.h"

namespace dea::document {

class Document;

class Executor {
public:
	Executor(Document& doc, Editor& editor,Change& change) : doc_(doc), editor_(editor), change_(change) {}
	bool execute();

private:
	Document& doc_;
	Editor& editor_;
	Change& change_;
};

} // namespace dea::document