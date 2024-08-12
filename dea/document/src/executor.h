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

	void chooseLayoutEngine(node::NodeConstPtr node);
	void buildConstraintLayout(node::NodeConstPtr node);
	void buildAutoLayout(node::NodeConstPtr node);
	void diffNodes(node::NodeConstPtr node);

	void rotate(node::NodeConstPtr node, float degrees);
	void transform(node::NodeConstPtr node, const node::Matrix& matrix);
	void resize(node::NodeConstPtr node, const node::ResizeValue& values);
};

} // namespace dea::document