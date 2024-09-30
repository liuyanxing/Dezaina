#pragma once

#include "node.h"
#include "container.h"
#include "guid.h"
#include "selection.h"

namespace dea::node
{

class RectangleNode : public RectangleNodeBase {
public:
  static constexpr NodeType Type = NodeType::RECTANGLE;
	RectangleNode() {
	  setType(Type);
	}
};

class LineNode : public LineNodeBase {
public:
  static constexpr NodeType Type = NodeType::LINE;
	LineNode() {
	  setType(Type);
	}
};

class EllipseNode : public EllipseNodeBase {
public:
  static constexpr NodeType Type = NodeType::ELLIPSE;
	EllipseNode() {
	  setType(Type);
	}
};

class PolygonNode : public PolygonNodeBase {
public:
  static constexpr NodeType Type = NodeType::REGULAR_POLYGON;
	PolygonNode() {
	  setType(Type);
	}
};

class StarNode : public StarNodeBase {
public:
  static constexpr NodeType Type = NodeType::STAR;
	StarNode() {
	  setType(Type);
	}
};

class VectorNode : public VectorNodeBase {
public:
  static constexpr NodeType Type = NodeType::VECTOR;
	VectorNode() {
	  setType(Type);
	}
};

class FrameNode : public FrameNodeBase, public Container {
public:
  static constexpr NodeType Type = NodeType::FRAME;
	FrameNode() {
	  setType(Type);
	}
};

class SymbolNode : public SymbolNodeBase {
public:
  static constexpr NodeType Type = NodeType::SYMBOL;
	SymbolNode() {
	  setType(Type);
	}
};

class InstanceNode : public InstanceNodeBase {
public:
  static constexpr NodeType Type = NodeType::INSTANCE;
	InstanceNode() {
	  setType(Type);
	}
};

class TextNode : public TextNodeBase {
public:
  static constexpr NodeType Type = NodeType::TEXT;
	TextNode() {
	  setType(Type);
	}
};

class PageNode : public PageNodeBase, public Container, public Selection, public DimensionAndPositionMixin {
public:
  static constexpr NodeType Type = NodeType::CANVAS;
	PageNode() {
	  setType(Type);
	}
};

class DocumentNode : public DocumentNodeBase, public Container {
public:
  static constexpr NodeType Type = NodeType::DOCUMENT;
	DocumentNode() {
	  setType(Type);
	}
};


} // namespace dea::node