export const nodeMixins = [
  {
    "name": "GeometryMixin",
    "type": "class",
    "extends": [
      "MinimalStrokesMixin",
      "MinimalFillsMixin"
    ],
    "changeType": "NodeChange",
    "members": [
      {
        "name": "strokeCap",
        "type": "StrokeCap"
      },
      {
        "name": "miterLimit",
        "type": "float",
        "default": 0
      },
      {
        "name": "fillGeometry",
        "type": "std::vector<Path>"
      }
    ]
  },
  {
    "name": "LayoutMixin",
    "type": "class",
    "extends": [
      "DimensionAndPositionMixin"
    ],
    "changeType": "NodeChange",
    "members": []
  },
  {
    "name": "DefaultShapeNode",
    "type": "class",
    "extends": [
      "BaseNodeMixin",
      "SceneNodeMixin",
      "ExportMixin",
      "BlendMixin",
      "GeometryMixin",
      "LayoutMixin"
    ],
    "changeType": "NodeChange",
    "members": []
  },
  {
    "name": "BaseFrameMixin",
    "type": "class",
    "extends": [
      "DefaultShapeNode",
      "CornerMixin",
      "RectangleCornerMixin",
      "EffectMixin",
      "ConstraintMixin",
      "IndividualStrokesMixin"
    ],
    "changeType": "NodeChange",
    "members": []
  },
  {
    "name": "DefaultFrameMixin",
    "type": "class",
    "extends": [
      "BaseFrameMixin"
    ],
    "changeType": "NodeChange",
    "members": []
  },
  {
    "name": "SubTextMixin",
    "type": "class",
    "extends": [
      "DefaultShapeNode"
    ],
    "changeType": "NodeChange",
    "members": [
      {
        "name": "styleID",
        "type": "uint"
      },
      {
        "name": "letterSpacing",
        "type": "Number"
      },
      {
        "name": "lineHeight",
        "type": "Number"
      }
    ]
  },
  {
    "name": "TextNodeMixin",
    "type": "class",
    "extends": [
      "DefaultShapeNode"
    ],
    "changeType": "NodeChange",
    "members": []
  }
]