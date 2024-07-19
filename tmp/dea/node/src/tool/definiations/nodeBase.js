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
    "members": []
  },
  {
    "name": "LineNodeBase",
    "type": "class",
    "extends": [
      "DefaultShapeNode",
      "ConstraintMixin"
    ],
    "changeType": "NodeChange",
    "members": []
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
    ]
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
    ]
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
    ]
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
    ]
  },
  {
    "name": "FrameNodeBase",
    "type": "class",
    "extends": [
      "DefaultFrameMixin"
    ],
    "changeType": "NodeChange",
    "members": []
  },
  {
    "name": "SymbolNodeBase",
    "type": "class",
    "extends": [
      "DefaultFrameMixin"
    ],
    "changeType": "NodeChange",
    "members": []
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
    ]
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
    ]
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
    ]
  },
  {
    "name": "DocumentNodeBase",
    "type": "class",
    "extends": [
      "BaseNodeMixin"
    ],
    "changeType": "NodeChange",
    "members": []
  }
]