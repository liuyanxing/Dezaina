#pragma once

#include "desaina_node.h"
#include "include/private/base/SkTArray.h"

using Node = BaseNodeMixin;
using NodeChange = Desaina_Kiwi::NodeChange;
using kiwiPool = kiwi::MemoryPool;

namespace util {
	bool isDocument(const Node* node);
  bool isPage(const Node* node);
  bool isFrame(const Node* node);
  bool isRectangle(const Node* node);
  bool isStar(const Node* node);
  bool isEllipse(const Node* node);
  bool isLine(const Node* node);
  bool isPolygon(const Node* node);
  bool isContainer(const Node *node);
  bool isSceneNode(const Node* node);
  bool isVector(const Node* node);
  bool isText(const Node* node);
  bool isDefaultShapeNode(const Node* node);
  bool isInsatance(const Node* node);
  bool isSymbol(const Node* node);
}
