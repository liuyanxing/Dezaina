export const messages = [
	{
		"name": "Glyph",
		"type": "class",
    "changeType": "Glyph",
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
		"name": "TextData",
		"type": "class",
    "changeType": "TextData",
		"members": [
			{
				"name": "characters",
				"type": "std::string"
			},
			{
				"name": "characterStyleIDs",
				"type": "std::vector<uint>"
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
				"type": "std::vector<Baseline>"
			},
			{
				"name": "glyphs",
				"type": "std::vector<Glyph>"
			},
			{
				"name": "decorations",
				"type": "std::vector<Decoration>"
			}
		]
	},
	{
		"name": "DerivedTextData",
		"type": "class",
    "changeType": "DerivedTextData",
		"members": [
			{
				"name": "layoutSize",
				"type": "Vector"
			},
			{
				"name": "baselines",
				"type": "std::vector<Baseline>"
			},
			{
				"name": "glyphs",
				"type": "std::vector<Glyph>"
			},
			{
				"name": "decorations",
				"type": "std::vector<Decoration>"
			}
		]
	}
]
