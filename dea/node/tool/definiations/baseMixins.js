export const baseMixins = [
	{
		"name": "BaseNodeMixin",
		"type": "class",
    "changeType": "NodeChange",
		"members": [
			{
				"name": "guid",
				"type": "GUID"
			},
			{
				"name": "parentIndex",
				"type": "ParentIndex"
			},
			{
				"name": "name",
				"type": "std::string"
			},
			{
				"name": "type",
				"type": "NodeType",
				"default": "NONE"
			},
			{
				"name": "nextSibling",
				"type": "BaseNodeMixinPointer",
				"skipChange": true
			},
		],
    "isChangeVirtual": true,
	},
	{
		"name": "SceneNodeMixin",
		"type": "class",
    "changeType": "NodeChange",
		"members": [
			{
				"name": "visible",
				"type": "boolean",
				"default": true
			},
			{
				"name": "locked",
				"type": "boolean",
				"default": false
			}
		]
	},
	{
		"name": "CornerMixin",
		"type": "class",
    "changeType": "NodeChange",
		"members": [
			{
				"name": "cornerRadius",
				"type": "float",
				"default": 0
			},
			{
				"name": "cornerSmoothing",
				"type": "float",
				"default": 0
			}
		]
	},
	{
		"name": "RectangleCornerMixin",
		"type": "class",
    "changeType": "NodeChange",
		"members": [
			{
				"name": "rectangleTopLeftCornerRadius",
				"type": "float",
				"default": 0
			},
			{
				"name": "rectangleTopRightCornerRadius",
				"type": "float",
				"default": 0
			},
			{
				"name": "rectangleBottomLeftCornerRadius",
				"type": "float",
				"default": 0
			},
			{
				"name": "rectangleBottomRightCornerRadius",
				"type": "float",
				"default": 0
			}
		]
	},
	{
		"name": "IndividualStrokesMixin",
		"type": "class",
    "changeType": "NodeChange",
		"members": [
			{
				"name": "borderTopWeight",
				"type": "float",
				"default": 0
			},
			{
				"name": "borderBottomWeight",
				"type": "float",
				"default": 0
			},
			{
				"name": "borderLeftWeight",
				"type": "float",
				"default": 0
			},
			{
				"name": "borderRightWeight",
				"type": "float",
				"default": 0
			}
		]
	},
	{
		"name": "MinimalStrokesMixin",
		"type": "class",
    "changeType": "NodeChange",
		"members": [
			{
				"name": "strokePaints",
				"type": "std::vector<PaintUnion>"
			},
			{
				"name": "styleIdForStrokeFill",
				"type": "StyleId"
			},
			{
				"name": "strokeWeight",
				"type": "float",
				"default": 0
			},
			{
				"name": "strokeJoin",
				"type": "StrokeJoin"
			},
			{
				"name": "strokeAlign",
				"type": "StrokeAlign"
			},
			{
				"name": "dashPattern",
				"type": "std::vector<float>"
			},
			{
				"name": "strokeGeometry",
				"type": "std::vector<Path>"
			}
		]
	},
	{
		"name": "MinimalFillsMixin",
		"type": "class",
    "changeType": "NodeChange",
		"members": [
			{
				"name": "fillPaints",
				"type": "std::vector<PaintUnion>"
			},
			{
				"name": "styleIdForStrokeFill",
				"type": "StyleId"
			}
		]
	},
	{
		"name": "DimensionAndPositionMixin",
		"type": "class",
    "changeType": "NodeChange",
		"members": [
			{
				"name": "size",
				"type": "Vector"
			},
			{
				"name": "transform",
				"type": "Matrix"
			}
		]
	},
	{
		"name": "ConstraintMixin",
		"type": "class",
    "changeType": "NodeChange",
		"members": [
			{
				"name": "horizontalConstraint",
				"type": "ConstraintType"
			},
			{
				"name": "verticalConstraint",
				"type": "ConstraintType"
			}
		]
	},
	{
		"name": "EffectMixin",
		"type": "class",
    "changeType": "NodeChange",
		"members": [
			{
				"name": "effects",
				"type": "std::vector<Effect>"
			},
			{
				"name": "styleIdForEffect",
				"type": "StyleId"
			}
		]
	},
	{
		"name": "ExportMixin",
		"type": "class",
    "changeType": "NodeChange",
		"members": []
	},
	{
		"name": "BlendMixin",
		"type": "class",
    "changeType": "NodeChange",
		"members": []
	},
	{
		"name": "AutoLayoutMixin",
		"type": "class",
    "changeType": "NodeChange",
		"members": [
			{
				"name": "stackMode",
				"type": "StackMode"
			},
			{
				"name": "stackWrap",
				"type": "StackWrap"
			},
			{
				"name": "stackPaddingRight",
				"type": "float",
				"default": 0
			},
			{
				"name": "stackPaddingBottom",
				"type": "float",
				"default": 0
			},
			{
				"name": "stackHorizontalPadding",
				"type": "float",
				"default": 0
			},
			{
				"name": "stackVerticalPadding",
				"type": "float",
				"default": 0
			}
		]
	}
]