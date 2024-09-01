export const enums = [
  {
    "name": "NumberUnits",
    "type": "enum",
    "values": ["RAW", "PIXELS", "PERCENT"]
  },
  {
    "name": "BlendMode",
    "type": "enum",
    "values": [
      "PASS_THROUGH", "NORMAL", "DARKEN", "MULTIPLY",
      "LINEAR_BURN", "COLOR_BURN", "LIGHTEN", "SCREEN",
      "LINEAR_DODGE", "COLOR_DODGE", "OVERLAY", "SOFT_LIGHT",
      "HARD_LIGHT", "DIFFERENCE", "EXCLUSION", "HUE",
      "SATURATION", "COLOR", "LUMINOSITY"
    ]
  },
  {
    "name": "EffectType",
    "type": "enum",
    "values": [
      "DROP_SHADOW", "INNER_SHADOW", "LAYER_BLUR", "BACKGROUND_BLUR"
    ]
  },
  {
    "name": "PaintType",
    "type": "enum",
    "values": [
      "SOLID", "GRADIENT_LINEAR", "GRADIENT_RADIAL",
      "GRADIENT_ANGULAR", "GRADIENT_DIAMOND", "IMAGE"
    ]
  },
  {
    "name": "ImageScaleMode",
    "type": "enum",
    "values": ["STRETCH", "FIT", "FILL", "TILE"]
  },
  {
    "name": "ConstraintType",
    "type": "enum",
    "values": ["MIN", "CENTER", "MAX", "STRETCH", "SCALE"]
  },
  {
    "name": "LayoutAlignType",
    "type": "enum",
    "values": ["MIN", "CENTER", "MAX", "STRETCH", "SCALE", "INHERIT"]
  },
  {
    "name": "StackMode",
    "type": "enum",
    "values": ["NONE", "HORIZONTAL", "VERTICAL"]
  },
  {
    "name": "StackWrap",
    "type": "enum",
    "values": ["NO_WRAP", "WRAP"]
  },
  {
    "name": "AxisSizingMode",
    "type": "enum",
    "values": ["FIXED", "AUTO"]
  },
  {
    "name": "PrimaryAxisAlignItems",
    "type": "enum",
    "values": ["MIN", "MAX", "CENTER", "SPACE_BETWEEN"]
  },
  {
    "name": "CounterAxisAlignItems",
    "type": "enum",
    "values": ["MIN", "MAX", "CENTER", "BASELINE"]
  },
  {
    "name": "CounterAxisAlignContent",
    "type": "enum",
    "values": ["AUTO", "SPACE_BETWEEN"]
  },
  {
    "name": "NodeType",
    "type": "enum",
    "values": [
      "NONE", "DOCUMENT", "CANVAS", "GROUP", "FRAME", "BOOLEAN_OPERATION",
      "VECTOR", "STAR", "LINE", "ELLIPSE", "RECTANGLE",
      "REGULAR_POLYGON", "ROUNDED_RECTANGLE", "TEXT",
      "SLICE", "SYMBOL", "INSTANCE", "STICKY", "SHAPE_WITH_TEXT",
      "CONNECTOR", "CODE_BLOCK", "WIDGET", "STAMP", "MEDIA",
      "HIGHLIGHT", "SECTION", "SECTION_OVERLAY", "WASHI_TAPE",
      "VARIABLE", "TABLE", "TABLE_CELL", "VARIABLE_SET", "SLIDE", 
      "INTER_FRAME", "INTER_RECTANGLE", "INTER_PATH",
    ]
  },
  {
    "name": "MessageType",
    "type": "enum",
    "values": [
      "JOIN_START", "NODE_CHANGES", "USER_CHANGES", "JOIN_END",
      "SIGNAL", "STYLE", "STYLE_SET", "JOIN_START_SKIP_RELOAD",
      "NOTIFY_SHOULD_UPGRADE", "UPGRADE_DONE", "UPGRADE_REFRESH",
      "SCENE_GRAPH_QUERY", "SCENE_GRAPH_REPLY", "DIFF",
      "CLIENT_BROADCAST", "JOIN_START_JOURNALED"
    ]
  },
  {
    "name": "StrokeCap",
    "type": "enum",
    "values": [
      "NONE", "ROUND", "SQUARE", "ARROW_LINES", "ARROW_EQUILATERAL"
    ]
  },
  {
    "name": "StrokeJoin",
    "type": "enum",
    "values": ["MITER", "BEVEL", "ROUND"]
  },
  {
    "name": "StrokeAlign",
    "type": "enum",
    "values": ["CENTER", "INSIDE", "OUTSIDE"]
  },
  {
    "name": "WindingRule",
    "type": "enum",
    "values": ["NONZERO", "EVENODD", "NONE"]
  }
]