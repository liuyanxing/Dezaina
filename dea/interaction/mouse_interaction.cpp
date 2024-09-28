#include "mouse_interaction.h"
#include "interaction.h"
#include "interaction/bound_editor.h"
#include "dezaina.h"

namespace dea::interaction {
	MouseInteraction::MouseInteraction(Interaction &inter) :
		docSelection_(inter.getDocSelection(), nullptr, Interaction::GetDocNodeScreenBound),
		interSelection_(inter.getInterSelection(), inter.getInterPage()) {
			docSelection_.onSelectionChange([this](const node::NodeConstArary &nodes) {
				handleSelectionChange(nodes);
			});
			interSelection_.onMoveOnNode([this](node::NodeConstPtr node) {
				return !interaction::node_cast<Frame>(node);
			});
	}

  void MouseInteraction::onMouseMove(event::MouseEvent &event) {
	auto* node = interSelection_.getHoverNode();
	if (!node) return;
    auto *emitter = interaction::node_cast<event::EventEmitter>(node);
    emitter->emit(event);
	}

  void MouseInteraction::onMouseDrag(event::MouseEvent &event) {
    if (interSelection_.empty()) {
      return;
    }
    setEventLocalPosition(event, node::NodeIterWithWorldMatrix(event.target));
    for (auto *node : interSelection_.getSelection()) {
      auto *emitter = interaction::node_cast<event::EventEmitter>(node);
      emitter->emit(event);
    }
	}

  void MouseInteraction::onPageChange(event::Event &event) {
		docSelection_.setRoot(Dezaina::instance().document().currentPage());
	}

	void MouseInteraction::handleSelectionChange(const node::NodeConstArary &selection) {
		if (selection.empty()) {
			return;
		}

		node::NodeIdArray ids;
		for (auto *node : selection) {
			ids.push_back(node->getGuid());
		}
		Dezaina::editor().select(ids);
	}
} // namespace dea::interaction