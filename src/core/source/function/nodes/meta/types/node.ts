interface RectangleNodeBase extends
    DefaultShapeNode,
    ConstraintMixin,
    CornerMixin,
    RectangleCornerMixin,
    IndividualStrokesMixin {
}

interface LineNodeBase extends
    DefaultShapeNode,
    ConstraintMixin {}

interface EllipseNodeBase extends
    DefaultShapeNode,
    ConstraintMixin,
    CornerMixin {
      arcData: ArcData
    }

interface PolygonNodeBase extends
    DefaultShapeNode,
    ConstraintMixin,
    CornerMixin {
      count: uint | 3
    }

interface StarNodeBase extends
    DefaultShapeNode,
    ConstraintMixin,
    CornerMixin {
      count: uint | 5
    }

interface VectorNodeBase extends
    DefaultShapeNode,
    ConstraintMixin,
    CornerMixin {
      vectorData: VectorData
    }

interface FrameNodeBase extends DefaultFrameMixin {
}

interface PageNodeBase extends BaseNodeMixin {
  backgroundColor: Color
  backgroundOpacity: float
  backgroundEnabled: bool
}

interface DocumentNodeBase extends BaseNodeMixin {
}
