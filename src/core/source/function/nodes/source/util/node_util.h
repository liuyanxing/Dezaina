#pragma once

#include "document.h"
class NodeUtil {
public:
  NodeUtil(Document* document) : document_(document) {}
private:
  Document* document_;
};
