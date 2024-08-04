export const structs = [
	{
		"name": "GUID",
		"type": "struct",
		"members": [
			{
				"name": "sessionID",
				"type": "uint",
				"default": 0
			},
			{
				"name": "localID",
				"type": "uint",
				"default": 0
			}
		]
	},
	{
		"name": "Vector",
		"type": "struct",
		"members": [
			{
				"name": "x",
				"type": "float",
				"default": 0
			},
			{
				"name": "y",
				"type": "float",
				"default": 0
			}
		]
	},
	{
		"name": "Rect",
		"type": "struct",
		"members": [
			{
				"name": "x",
				"type": "float"
			},
			{
				"name": "y",
				"type": "float"
			},
			{
				"name": "w",
				"type": "float"
			},
			{
				"name": "h",
				"type": "float"
			}
		]
	},
	{
		"name": "Matrix",
		"type": "struct",
		"members": [
			{
				"name": "m00",
				"type": "float",
				"default": 1
			},
			{
				"name": "m01",
				"type": "float",
				"default": 0
			},
			{
				"name": "m02",
				"type": "float",
				"default": 0
			},
			{
				"name": "m10",
				"type": "float",
				"default": 0
			},
			{
				"name": "m11",
				"type": "float",
				"default": 1
			},
			{
				"name": "m12",
				"type": "float",
				"default": 0
			}
		]
	},
	{
		"name": "Number",
		"type": "struct",
		"members": [
			{
				"name": "value",
				"type": "float"
			},
			{
				"name": "units",
				"type": "NumberUnits"
			}
		]
	},
	{
		"name": "Color",
		"type": "struct",
		"members": [
			{
				"name": "r",
				"type": "float",
				"default": 0
			},
			{
				"name": "g",
				"type": "float",
				"default": 0
			},
			{
				"name": "b",
				"type": "float",
				"default": 0
			},
			{
				"name": "a",
				"type": "float",
				"default": 1
			}
		]
	},
	{
		"name": "Effect",
		"type": "struct",
		"members": [
			{
				"name": "type",
				"type": "EffectType"
			}
		]
	},
	{
		"name": "DropShadowEffect",
		"type": "struct",
	  "changeType": "Effect",
		"members": [
			{
				"name": "color",
				"type": "Color"
			},
			{
				"name": "offset",
				"type": "Vector"
			},
			{
				"name": "radius",
				"type": "float",
				"default": 0
			},
			{
				"name": "spread",
				"type": "float",
				"default": 0
			},
			{
				"name": "visible",
				"type": "bool",
				"default": true
			},
			{
				"name": "blendMode",
				"type": "BlendMode"
			},
			{
				"name": "showShadowBehindNode",
				"type": "bool",
				"default": false
			}
		]
	},
	{
		"name": "InnerShadowEffect",
		"type": "struct",
	  "changeType": "Effect",
		"members": [
			{
				"name": "color",
				"type": "Color"
			},
			{
				"name": "offset",
				"type": "Vector"
			},
			{
				"name": "radius",
				"type": "float",
				"default": 10
			},
			{
				"name": "spread",
				"type": "float",
				"default": 0
			},
			{
				"name": "visible",
				"type": "bool",
				"default": true
			},
			{
				"name": "blendMode",
				"type": "BlendMode"
			}
		]
	},
	{
		"name": "BlurEffect",
		"type": "struct",
	  "changeType": "Effect",
		"members": [
			{
				"name": "radius",
				"type": "float",
				"default": 10
			},
			{
				"name": "visible",
				"type": "bool",
				"default": true
			}
		]
	},
	{
		"name": "ColorStop",
		"type": "struct",
		"members": [
			{
				"name": "position",
				"type": "float",
				"default": 0
			},
			{
				"name": "color",
				"type": "Color"
			}
		]
	},
	{
		"name": "Paint",
		"type": "struct",
		"members": [
			{
				"name": "type",
				"type": "PaintType"
			},
			{
				"name": "visible",
				"type": "bool",
				"default": true
			},
			{
				"name": "opacity",
				"type": "float",
				"default": 1
			},
			{
				"name": "blendMode",
				"type": "BlendMode"
			}
		]
	},
	{
		"name": "SolidPaint",
		"type": "struct",
		"changeType": "Paint",
    "extends": ["Paint"],
		"members": [
			{
				"name": "color",
				"type": "Color"
			}
		]
	},
	{
		"name": "GradientPaint",
		"type": "struct",
		"changeType": "Paint",
    "extends": ["Paint"],
		"members": [
			{
				"name": "transform",
				"type": "Matrix"
			},
			{
				"name": "stops",
				"type": "Array<ColorStop>"
			}
		]
	},
	{
		"name": "ImagePaint",
		"type": "struct",
		"changeType": "Paint",
    "extends": ["Paint"],
		"members": [
			{
				"name": "imageScaleMode",
				"type": "ImageScaleMode"
			},
			{
				"name": "transform",
				"type": "Matrix"
			}
		]
	},
	{
		"name": "Path",
		"type": "struct",
		"members": [
			{
				"name": "windingRule",
				"type": "WindingRule"
			},
			{
				"name": "commandsBlob",
				"type": "uint"
			}
		]
	},
	{
		"name": "ParentIndex",
		"type": "struct",
		"members": [
			{
				"name": "guid",
				"type": "GUID"
			},
			{
				"name": "position",
				"type": "string"
			}
		]
	},
	{
		"name": "AssetRef",
		"type": "struct",
		"members": [
			{
				"name": "key",
				"type": "string"
			},
			{
				"name": "version",
				"type": "string"
			}
		]
	},
	{
		"name": "StyleId",
		"type": "struct",
		"members": [
			{
				"name": "guid",
				"type": "GUID"
			},
			{
				"name": "assetRef",
				"type": "AssetRef"
			}
		]
	},
	{
		"name": "ArcData",
		"type": "struct",
		"members": [
			{
				"name": "startingAngle",
				"type": "float",
				"default": 0
			},
			{
				"name": "endingAngle",
				"type": "float",
				"default": 6.2831854820251465
			},
			{
				"name": "innerRadius",
				"type": "float",
				"default": 0
			}
		]
	},
	{
		"name": "VectorData",
		"type": "struct",
		"members": [
			{
				"name": "vectorNetworkBlob",
				"type": "uint"
			}
		]
	},
	{
		"name": "Glyph",
		"type": "struct",
		"members": [
			{
				"name": "styleID",
				"type": "uint"
			},
			{
				"name": "commandsBlob",
				"type": "uint"
			},
			{
				"name": "position",
				"type": "Vector"
			},
			{
				"name": "fontSize",
				"type": "float"
			},
			{
				"name": "advance",
				"type": "float"
			}
		]
	},
	{
		"name": "Decoration",
		"type": "struct",
		"members": [
			{
				"name": "rects",
				"type": "Array<Rect>"
			}
		]
	},
	{
		"name": "Baseline",
		"type": "struct",
		"members": [
			{
				"name": "position",
				"type": "Vector"
			},
			{
				"name": "width",
				"type": "float"
			},
			{
				"name": "lineY",
				"type": "float"
			},
			{
				"name": "lineHeight",
				"type": "float"
			},
			{
				"name": "lineAscent",
				"type": "float"
			},
			{
				"name": "firstCharacter",
				"type": "uint"
			},
			{
				"name": "endCharacter",
				"type": "uint"
			}
		]
	},
	{
		"name": "TextData",
		"type": "struct",
		"members": [
			{
				"name": "characters",
				"type": "string"
			},
			{
				"name": "styleOverrideTable",
				"type": "Buffer"
			},
			{
				"name": "layoutSize",
				"type": "Vector"
			},
			{
				"name": "baselines",
				"type": "Array<Baseline>"
			},
			{
				"name": "glyphs",
				"type": "Array<Glyph>"
			},
			{
				"name": "decorations",
				"type": "Array<Decoration>"
			}
		]
	},
	{
		"name": "SymbolData",
		"type": "struct",
		"members": [
			{
				"name": "symbolID",
				"type": "GUID"
			},
			{
				"name": "symbolOverrides",
				"type": "Buffer"
			},
			{
				"name": "uniformScaleFactor",
				"type": "float"
			}
		]
	}
]