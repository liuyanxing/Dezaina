#pragma once

namespace dea::command {

enum class CmdType {
	// Document commands
	EXPORT_DOCUMENT,
	IMPORT_DOCUMENT,
	// Node commands
	ADD_NODE,
	REMOVE_NODE,
	CLONE_NODE,
	Align,
	// View commands
	Zoom,
	// Selection commands
	SELECT_ALL,
	SELECT_NONE,
	SELECT_INVERSE,
	// Group commands
	GROUP,
	UNGROUP,
	// Undo/Redo commands
	UNDO,
	REDO,
	last = REDO
};

}