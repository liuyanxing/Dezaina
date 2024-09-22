#pragma once

#include "primitives.h"
#include "node.h"
#include <memory>

namespace dea::change {

	class Command {
	public:
		virtual void execute() = 0;
		virtual void undo() = 0;
		virtual void redo() = 0;

		virtual ~Command() = default;
	};

	class SelectionCommand : public Command {
	public:
		SelectionCommand(node::NodeIdArray& selection)
			: redoSelection_(selection) {
			}

		static auto Make(node::NodeIdArray& selection) {
			return std::make_unique<SelectionCommand>(selection);
		}

		void execute() override;
		void undo() override;
		void redo() override;
		void takeUndoSnapshot();
	private:
		node::NodeIdArray undoSelection_;
		node::NodeIdArray redoSelection_;
	};

	class NodeChangesCommand : public Command {
	public:
		NodeChangesCommand(NodeChanges* changes, kiwi::MemoryPool& pool)
			: changes_(changes), pool_(&pool) {
			}

		static auto Make(NodeChanges& changes, kiwi::MemoryPool& pool) {
			return std::make_unique<NodeChangesCommand>(&changes, pool);
		}

		void execute() override;
		void undo() override;
		void redo() override;
		void takeRedoSnapShot();
		void takeUndoSnapshot();

	private:
		NodeChanges* changes_;
		kiwi::MemoryPool* pool_;
		std::unique_ptr<message::Message> redoMessage_;
		base::Data undoSnapshot_;
		base::Data redoSnapshot_;
	};

	class DeleteCommand : public NodeChangesCommand {
	public:
		DeleteCommand(node::NodeIdArray& ids, kiwi::MemoryPool& pool)
			: NodeChangesCommand(&changes_, pool) {
			}

		static auto Make(node::NodeIdArray& ids, kiwi::MemoryPool& pool) {
			return std::make_unique<DeleteCommand>(ids, pool);
		}

		void takeUndoSnapshot();
		void execute() override;
		void undo() override;
		void redo() override;
	private:
		node::NodeIdArray ids_;
		NodeChanges changes_;
	};

	class CommandManager {
	public:
		void execute(std::unique_ptr<Command> command) {
			command->execute();
			commands.push_back(move(command));
			redoCommands.clear();
		}

		void undo() {
			if (commands.empty()) {
				return;
			}
			commands.back()->undo();
			redoCommands.push_back(move(commands.back()));
			commands.pop_back();
		}

		void redo() {
			if (redoCommands.empty()) {
				return;
			}
			redoCommands.back()->redo();
			commands.push_back(move(redoCommands.back()));
			redoCommands.pop_back();
		}

	private:
		std::vector<std::unique_ptr<Command>> commands;
	  std::vector<std::unique_ptr<Command>> redoCommands;
	};

}