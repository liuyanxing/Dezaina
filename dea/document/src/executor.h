#pragma once

#include "editor.h"
#include "change.h"
#include "layout.h"
#include <memory>

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
	std::unique_ptr<Layout> layoutEngine_ = nullptr;

	void chooseLayoutEngine(const node::Node* node);
	void buildConstraintLayout(const node::Node* node);
	void buildAutoLayout(const node::Node* node);
	void diffNodes(const node::Node* node);

	void rotate(const node::Node* node, float degrees);
	void transform(const node::Node* node, const node::Matrix& matrix);
	void resize(const node::Node* node, const node::ResizeValue& values);
};

} // namespace dea::document