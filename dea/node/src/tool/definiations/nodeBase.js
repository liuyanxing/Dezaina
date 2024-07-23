export const nodeBase = [
  {
    "name": "RectangleNodeBase",
    "type": "class",
    "extends": [
      "DefaultShapeNode",
      "ConstraintMixin",
      "CornerMixin",
      "RectangleCornerMixin",
      "IndividualStrokesMixin"
    ],
    "changeType": "NodeChange",
    "members": [],
    "node": "RectangleNode",
    "nodeType": "RECTANGLE",
  },
  {
    "name": "LineNodeBase",
    "type": "class",
    "extends": [
      "DefaultShapeNode",
      "ConstraintMixin"
    ],
    "changeType": "NodeChange",
    "members": [],
    "node": "LineNode",
    "nodeType": "LINE",
  },
  {
    "name": "EllipseNodeBase",
    "type": "class",
    "extends": [
      "DefaultShapeNode",
      "ConstraintMixin",
      "CornerMixin"
    ],
    "changeType": "NodeChange",
    "members": [
      {
        "name": "arcData",
        "type": "ArcData"
      }
    ],
    "node": "EllipseNode",
    "nodeType": "ELLIPSE",
  },
  {
    "name": "PolygonNodeBase",
    "type": "class",
    "extends": [
      "DefaultShapeNode",
      "ConstraintMixin",
      "CornerMixin"
    ],
    "changeType": "NodeChange",
    "members": [
      {
        "name": "count",
        "type": "uint",
        "default": 3
      }
    ],
    "node": "PolygonNode",
    "nodeType": "REGULAR_POLYGON",
  },
  {
    "name": "StarNodeBase",
    "type": "class",
    "extends": [
      "DefaultShapeNode",
      "ConstraintMixin",
      "CornerMixin"
    ],
    "changeType": "NodeChange",
    "members": [
      {
        "name": "count",
        "type": "uint",
        "default": 5
      }
    ],
    "node": "StarNode",
    "nodeType": "STAR",
  },
  {
    "name": "VectorNodeBase",
    "type": "class",
    "extends": [
      "DefaultShapeNode",
      "ConstraintMixin",
      "CornerMixin"
    ],
    "changeType": "NodeChange",
    "members": [
      {
        "name": "vectorData",
        "type": "VectorData"
      }
    ],
    "node": "VectorNode",
    "nodeType": "VECTOR",
  },
  {
    "name": "FrameNodeBase",
    "type": "class",
    "extends": [
      "DefaultFrameMixin"
    ],
    "changeType": "NodeChange",
    "members": [],
    "node": "FrameNode",
    "nodeType": "FRAME",
  },
  {
    "name": "SymbolNodeBase",
    "type": "class",
    "extends": [
      "DefaultFrameMixin"
    ],
    "changeType": "NodeChange",
    "members": [],
    "node": "SymbolNode",
    "nodeType": "SYMBOL",
  },
  {
    "name": "InstanceNodeBase",
    "type": "class",
    "extends": [
      "DefaultFrameMixin"
    ],
    "changeType": "NodeChange",
    "members": [
      {
        "name": "symbolData",
        "type": "SymbolData"
      },
      {
        "name": "derivedSymbolData",
        "type": "Buffer"
      }
    ],
    "node": "InstanceNode",
    "nodeType": "INSTANCE",
  },
  {
    "name": "TextNodeBase",
    "type": "class",
    "extends": [
      "TextNodeMixin"
    ],
    "changeType": "NodeChange",
    "members": [
      {
        "name": "textData",
        "type": "TextData"
      }
    ],
    "node": "TextNode",
    "nodeType": "TEXT",
  },
  {
    "name": "PageNodeBase",
    "type": "class",
    "extends": [
      "BaseNodeMixin"
    ],
    "changeType": "NodeChange",
    "members": [
      {
        "name": "backgroundColor",
        "type": "Color"
      },
      {
        "name": "backgroundOpacity",
        "type": "float"
      },
      {
        "name": "backgroundEnabled",
        "type": "bool"
      }
    ],
    "node": "PageNode",
    "nodeType": "CANVAS",
  },
  {
    "name": "DocumentNodeBase",
    "type": "class",
    "extends": [
      "BaseNodeMixin"
    ],
    "changeType": "NodeChange",
    "members": [],
    "node": "DocumentNode",
    "nodeType": "DOCUMENT",
  }
]