#include "base/array.h"

namespace dea::change {

template <typename ChangeItem>
class UndoRedo {
public:
  UndoRedo() {
  }

  void recordChange(const ChangeItem& change) {}

  void undo() {
    if (current_ == -1) {
      return;
    }
    current_--;
  }

  void redo() {
    if (current_ == stack_.size()) {
      return;
    }
    current_++;
  }

  bool canUndo() const {
    return stack_.empty();
  }

  bool canRedo() const {
    return stack_.full();
  }

private:
  base::array<ChangeItem, 50> stack_;
  int current_ = -1;
};

} // namespace dea
