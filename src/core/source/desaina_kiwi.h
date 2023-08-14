#include "kiwi.h"

namespace Desaina_Kiwi {

#ifndef INCLUDE_DESAINA_KIWI_H
#define INCLUDE_DESAINA_KIWI_H

class BinarySchema {
public:
  bool parse(kiwi::ByteBuffer &bb);
  const kiwi::BinarySchema &underlyingSchema() const { return _schema; }
  bool skipImageField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipVideoField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipPaintFilterMessageField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipPaintField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipFontMetaDataField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipFontVariationField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipTextDataField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipDerivedTextDataField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipHyperlinkBoxField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipMentionBoxField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipBaselineField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipGlyphField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipDecorationField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipBlockquoteField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipVectorDataField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipGUIDPathField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipSymbolDataField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipGUIDPathMappingField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipNodeGenerationDataField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipDerivedImmutableFrameDataField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipAssetRefField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipStateGroupIdField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipStyleIdField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipSymbolIdField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipVariableIDField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipVariableSetIDField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipSharedSymbolReferenceField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipSharedComponentMasterDataField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipInstanceOverrideStashField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipInstanceOverrideStashV2Field(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipEffectField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipTransitionInfoField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipPrototypeDeviceField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipOverlayBackgroundAppearanceField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipExportSettingsField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipLayoutGridField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipGuideField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipPathField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipSharedStyleReferenceField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipSharedStyleMasterDataField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipArcDataField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipSymbolLinkField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipPluginDataField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipPluginRelaunchDataField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipMultiplayerFieldVersionField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipConnectorEndpointField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipConnectorControlPointField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipConnectorTextMidpointField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipLibraryMoveInfoField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipLibraryMoveHistoryItemField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipDeveloperRelatedLinkField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipWidgetPointerField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipEditInfoField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipSectionStatusInfoField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipNodeChangeField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipVideoPlaybackField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipWidgetHoverStyleField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipWidgetDerivedSubtreeCursorField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipMultiplayerMapField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipMultiplayerMapEntryField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipVariableDataMapField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipVariableDataMapEntryField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipVariableModeBySetMapField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipVariableModeBySetMapEntryField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipCodeSyntaxMapField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipCodeSyntaxMapEntryField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipTableRowColumnPositionMapField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipTableRowColumnPositionMapEntryField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipTableRowColumnSizeMapField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipTableRowColumnSizeMapEntryField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipAgendaPositionMapField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipAgendaPositionMapEntryField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipAgendaMetadataMapField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipAgendaMetadataMapEntryField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipAgendaMetadataField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipAgendaTimerInfoField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipAgendaVoteInfoField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipAgendaMusicInfoField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipComponentPropRefField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipComponentPropAssignmentField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipComponentPropDefField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipComponentPropValueField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipComponentPropPreferredValuesField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipInstanceSwapPreferredValueField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipWidgetMetadataField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipWidgetPropertyMenuSelectorOptionField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipWidgetPropertyMenuItemField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipInternalDataForTestField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipStateGroupPropertyValueOrderField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipTextListDataField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipTextLineDataField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipDerivedTextLineDataField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipPrototypeInteractionField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipPrototypeEventField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipPrototypeVariableTargetField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipConditionalActionsField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipPrototypeActionField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipPrototypeStartingPointField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipKeyTriggerField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipHyperlinkField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipMentionField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipEmbedDataField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipStampDataField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipLinkPreviewDataField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipViewportField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipMouseField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipTriggeredOverlayDataField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipPresentedStateField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipTopLevelPlaybackChangeField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipInstanceStateChangeField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipTextCursorField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipTextSelectionField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipPlaybackChangeKeyframeField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipStateMappingField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipScrollMappingField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipPlaybackUpdateField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipChatMessageField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipVoiceMetadataField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipUserChangeField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipSceneGraphQueryField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipNodeChangesMetadataField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipCursorReactionField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipTimerInfoField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipMusicInfoField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipPresenterNominationField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipPresenterInfoField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipClientBroadcastField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipMessageField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipDiffChunkField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipDiffPayloadField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipRichMediaDataField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipVariableAnyValueField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipExpressionField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipVariableMapValueField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipVariableMapField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipVariableDataField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipVariableSetModeField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipVariableDataValuesField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipVariableDataValuesEntryField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipOptionalVectorField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipMigrationStatusField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipNodeFieldMapField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipNodeFieldMapEntryField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipARIAAttributeAnyValueField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipARIAAttributeDataField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipARIAAttributesMapField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipARIAAttributesMapEntryField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipHandoffStatusMapEntryField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipHandoffStatusMapField(kiwi::ByteBuffer &bb, uint32_t id) const;

private:
  kiwi::BinarySchema _schema;
  uint32_t _indexImage = 0;
  uint32_t _indexVideo = 0;
  uint32_t _indexPaintFilterMessage = 0;
  uint32_t _indexPaint = 0;
  uint32_t _indexFontMetaData = 0;
  uint32_t _indexFontVariation = 0;
  uint32_t _indexTextData = 0;
  uint32_t _indexDerivedTextData = 0;
  uint32_t _indexHyperlinkBox = 0;
  uint32_t _indexMentionBox = 0;
  uint32_t _indexBaseline = 0;
  uint32_t _indexGlyph = 0;
  uint32_t _indexDecoration = 0;
  uint32_t _indexBlockquote = 0;
  uint32_t _indexVectorData = 0;
  uint32_t _indexGUIDPath = 0;
  uint32_t _indexSymbolData = 0;
  uint32_t _indexGUIDPathMapping = 0;
  uint32_t _indexNodeGenerationData = 0;
  uint32_t _indexDerivedImmutableFrameData = 0;
  uint32_t _indexAssetRef = 0;
  uint32_t _indexStateGroupId = 0;
  uint32_t _indexStyleId = 0;
  uint32_t _indexSymbolId = 0;
  uint32_t _indexVariableID = 0;
  uint32_t _indexVariableSetID = 0;
  uint32_t _indexSharedSymbolReference = 0;
  uint32_t _indexSharedComponentMasterData = 0;
  uint32_t _indexInstanceOverrideStash = 0;
  uint32_t _indexInstanceOverrideStashV2 = 0;
  uint32_t _indexEffect = 0;
  uint32_t _indexTransitionInfo = 0;
  uint32_t _indexPrototypeDevice = 0;
  uint32_t _indexOverlayBackgroundAppearance = 0;
  uint32_t _indexExportSettings = 0;
  uint32_t _indexLayoutGrid = 0;
  uint32_t _indexGuide = 0;
  uint32_t _indexPath = 0;
  uint32_t _indexSharedStyleReference = 0;
  uint32_t _indexSharedStyleMasterData = 0;
  uint32_t _indexArcData = 0;
  uint32_t _indexSymbolLink = 0;
  uint32_t _indexPluginData = 0;
  uint32_t _indexPluginRelaunchData = 0;
  uint32_t _indexMultiplayerFieldVersion = 0;
  uint32_t _indexConnectorEndpoint = 0;
  uint32_t _indexConnectorControlPoint = 0;
  uint32_t _indexConnectorTextMidpoint = 0;
  uint32_t _indexLibraryMoveInfo = 0;
  uint32_t _indexLibraryMoveHistoryItem = 0;
  uint32_t _indexDeveloperRelatedLink = 0;
  uint32_t _indexWidgetPointer = 0;
  uint32_t _indexEditInfo = 0;
  uint32_t _indexSectionStatusInfo = 0;
  uint32_t _indexNodeChange = 0;
  uint32_t _indexVideoPlayback = 0;
  uint32_t _indexWidgetHoverStyle = 0;
  uint32_t _indexWidgetDerivedSubtreeCursor = 0;
  uint32_t _indexMultiplayerMap = 0;
  uint32_t _indexMultiplayerMapEntry = 0;
  uint32_t _indexVariableDataMap = 0;
  uint32_t _indexVariableDataMapEntry = 0;
  uint32_t _indexVariableModeBySetMap = 0;
  uint32_t _indexVariableModeBySetMapEntry = 0;
  uint32_t _indexCodeSyntaxMap = 0;
  uint32_t _indexCodeSyntaxMapEntry = 0;
  uint32_t _indexTableRowColumnPositionMap = 0;
  uint32_t _indexTableRowColumnPositionMapEntry = 0;
  uint32_t _indexTableRowColumnSizeMap = 0;
  uint32_t _indexTableRowColumnSizeMapEntry = 0;
  uint32_t _indexAgendaPositionMap = 0;
  uint32_t _indexAgendaPositionMapEntry = 0;
  uint32_t _indexAgendaMetadataMap = 0;
  uint32_t _indexAgendaMetadataMapEntry = 0;
  uint32_t _indexAgendaMetadata = 0;
  uint32_t _indexAgendaTimerInfo = 0;
  uint32_t _indexAgendaVoteInfo = 0;
  uint32_t _indexAgendaMusicInfo = 0;
  uint32_t _indexComponentPropRef = 0;
  uint32_t _indexComponentPropAssignment = 0;
  uint32_t _indexComponentPropDef = 0;
  uint32_t _indexComponentPropValue = 0;
  uint32_t _indexComponentPropPreferredValues = 0;
  uint32_t _indexInstanceSwapPreferredValue = 0;
  uint32_t _indexWidgetMetadata = 0;
  uint32_t _indexWidgetPropertyMenuSelectorOption = 0;
  uint32_t _indexWidgetPropertyMenuItem = 0;
  uint32_t _indexInternalDataForTest = 0;
  uint32_t _indexStateGroupPropertyValueOrder = 0;
  uint32_t _indexTextListData = 0;
  uint32_t _indexTextLineData = 0;
  uint32_t _indexDerivedTextLineData = 0;
  uint32_t _indexPrototypeInteraction = 0;
  uint32_t _indexPrototypeEvent = 0;
  uint32_t _indexPrototypeVariableTarget = 0;
  uint32_t _indexConditionalActions = 0;
  uint32_t _indexPrototypeAction = 0;
  uint32_t _indexPrototypeStartingPoint = 0;
  uint32_t _indexKeyTrigger = 0;
  uint32_t _indexHyperlink = 0;
  uint32_t _indexMention = 0;
  uint32_t _indexEmbedData = 0;
  uint32_t _indexStampData = 0;
  uint32_t _indexLinkPreviewData = 0;
  uint32_t _indexViewport = 0;
  uint32_t _indexMouse = 0;
  uint32_t _indexTriggeredOverlayData = 0;
  uint32_t _indexPresentedState = 0;
  uint32_t _indexTopLevelPlaybackChange = 0;
  uint32_t _indexInstanceStateChange = 0;
  uint32_t _indexTextCursor = 0;
  uint32_t _indexTextSelection = 0;
  uint32_t _indexPlaybackChangeKeyframe = 0;
  uint32_t _indexStateMapping = 0;
  uint32_t _indexScrollMapping = 0;
  uint32_t _indexPlaybackUpdate = 0;
  uint32_t _indexChatMessage = 0;
  uint32_t _indexVoiceMetadata = 0;
  uint32_t _indexUserChange = 0;
  uint32_t _indexSceneGraphQuery = 0;
  uint32_t _indexNodeChangesMetadata = 0;
  uint32_t _indexCursorReaction = 0;
  uint32_t _indexTimerInfo = 0;
  uint32_t _indexMusicInfo = 0;
  uint32_t _indexPresenterNomination = 0;
  uint32_t _indexPresenterInfo = 0;
  uint32_t _indexClientBroadcast = 0;
  uint32_t _indexMessage = 0;
  uint32_t _indexDiffChunk = 0;
  uint32_t _indexDiffPayload = 0;
  uint32_t _indexRichMediaData = 0;
  uint32_t _indexVariableAnyValue = 0;
  uint32_t _indexExpression = 0;
  uint32_t _indexVariableMapValue = 0;
  uint32_t _indexVariableMap = 0;
  uint32_t _indexVariableData = 0;
  uint32_t _indexVariableSetMode = 0;
  uint32_t _indexVariableDataValues = 0;
  uint32_t _indexVariableDataValuesEntry = 0;
  uint32_t _indexOptionalVector = 0;
  uint32_t _indexMigrationStatus = 0;
  uint32_t _indexNodeFieldMap = 0;
  uint32_t _indexNodeFieldMapEntry = 0;
  uint32_t _indexARIAAttributeAnyValue = 0;
  uint32_t _indexARIAAttributeData = 0;
  uint32_t _indexARIAAttributesMap = 0;
  uint32_t _indexARIAAttributesMapEntry = 0;
  uint32_t _indexHandoffStatusMapEntry = 0;
  uint32_t _indexHandoffStatusMap = 0;
};

enum class MessageType : uint32_t {
  JOIN_START = 0,
  NODE_CHANGES = 1,
  USER_CHANGES = 2,
  JOIN_END = 3,
  SIGNAL = 4,
  STYLE = 5,
  STYLE_SET = 6,
  JOIN_START_SKIP_RELOAD = 7,
  NOTIFY_SHOULD_UPGRADE = 8,
  UPGRADE_DONE = 9,
  UPGRADE_REFRESH = 10,
  SCENE_GRAPH_QUERY = 11,
  SCENE_GRAPH_REPLY = 12,
  DIFF = 13,
  CLIENT_BROADCAST = 14,
  JOIN_START_JOURNALED = 15,
  STREAM_START = 16,
  STREAM_END = 17,
};

enum class Axis : uint32_t {
  X = 0,
  Y = 1,
};

enum class Access : uint32_t {
  READ_ONLY = 0,
  READ_WRITE = 1,
};

enum class NodePhase : uint32_t {
  CREATED = 0,
  REMOVED = 1,
};

enum class WindingRule : uint32_t {
  NONZERO = 0,
  ODD = 1,
};

enum class NodeType : uint32_t {
  NONE = 0,
  DOCUMENT = 1,
  CANVAS = 2,
  GROUP = 3,
  FRAME = 4,
  BOOLEAN_OPERATION = 5,
  VECTOR = 6,
  STAR = 7,
  LINE = 8,
  ELLIPSE = 9,
  RECTANGLE = 10,
  REGULAR_POLYGON = 11,
  ROUNDED_RECTANGLE = 12,
  TEXT = 13,
  SLICE = 14,
  SYMBOL = 15,
  INSTANCE = 16,
  STICKY = 17,
  SHAPE_WITH_TEXT = 18,
  CONNECTOR = 19,
  CODE_BLOCK = 20,
  WIDGET = 21,
  STAMP = 22,
  MEDIA = 23,
  HIGHLIGHT = 24,
  SECTION = 25,
  SECTION_OVERLAY = 26,
  WASHI_TAPE = 27,
  VARIABLE = 28,
  TABLE = 29,
  TABLE_CELL = 30,
  VARIABLE_SET = 31,
  SLIDE = 32,
};

enum class ShapeWithTextType : uint32_t {
  SQUARE = 0,
  ELLIPSE = 1,
  DIAMOND = 2,
  TRIANGLE_UP = 3,
  TRIANGLE_DOWN = 4,
  ROUNDED_RECTANGLE = 5,
  PARALLELOGRAM_RIGHT = 6,
  PARALLELOGRAM_LEFT = 7,
  ENG_DATABASE = 8,
  ENG_QUEUE = 9,
  ENG_FILE = 10,
  ENG_FOLDER = 11,
  TRAPEZOID = 12,
  PREDEFINED_PROCESS = 13,
  SHIELD = 14,
  DOCUMENT_SINGLE = 15,
  DOCUMENT_MULTIPLE = 16,
  MANUAL_INPUT = 17,
  HEXAGON = 18,
  CHEVRON = 19,
  PENTAGON = 20,
  OCTAGON = 21,
  STAR = 22,
  PLUS = 23,
  ARROW_LEFT = 24,
  ARROW_RIGHT = 25,
  SUMMING_JUNCTION = 26,
  OR = 27,
  SPEECH_BUBBLE = 28,
  INTERNAL_STORAGE = 29,
};

enum class BlendMode : uint32_t {
  PASS_THROUGH = 0,
  NORMAL = 1,
  DARKEN = 2,
  MULTIPLY = 3,
  LINEAR_BURN = 4,
  COLOR_BURN = 5,
  LIGHTEN = 6,
  SCREEN = 7,
  LINEAR_DODGE = 8,
  COLOR_DODGE = 9,
  OVERLAY = 10,
  SOFT_LIGHT = 11,
  HARD_LIGHT = 12,
  DIFFERENCE = 13,
  EXCLUSION = 14,
  HUE = 15,
  SATURATION = 16,
  COLOR = 17,
  LUMINOSITY = 18,
};

enum class PaintType : uint32_t {
  SOLID = 0,
  GRADIENT_LINEAR = 1,
  GRADIENT_RADIAL = 2,
  GRADIENT_ANGULAR = 3,
  GRADIENT_DIAMOND = 4,
  IMAGE = 5,
  EMOJI = 6,
  VIDEO = 7,
};

enum class ImageScaleMode : uint32_t {
  STRETCH = 0,
  FIT = 1,
  FILL = 2,
  TILE = 3,
};

enum class EffectType : uint32_t {
  INNER_SHADOW = 0,
  DROP_SHADOW = 1,
  FOREGROUND_BLUR = 2,
  BACKGROUND_BLUR = 3,
};

enum class TextCase : uint32_t {
  ORIGINAL = 0,
  UPPER = 1,
  LOWER = 2,
  TITLE = 3,
  SMALL_CAPS = 4,
  SMALL_CAPS_FORCED = 5,
};

enum class TextDecoration : uint32_t {
  NONE = 0,
  UNDERLINE = 1,
  STRIKETHROUGH = 2,
};

enum class LeadingTrim : uint32_t {
  NONE = 0,
  CAP_HEIGHT = 1,
};

enum class NumberUnits : uint32_t {
  RAW = 0,
  PIXELS = 1,
  PERCENT = 2,
};

enum class ConstraintType : uint32_t {
  MIN = 0,
  CENTER = 1,
  MAX = 2,
  STRETCH = 3,
  SCALE = 4,
  FIXED_MIN = 5,
  FIXED_MAX = 6,
};

enum class StrokeAlign : uint32_t {
  CENTER = 0,
  INSIDE = 1,
  OUTSIDE = 2,
};

enum class StrokeCap : uint32_t {
  NONE = 0,
  ROUND = 1,
  SQUARE = 2,
  ARROW_LINES = 3,
  ARROW_EQUILATERAL = 4,
  DIAMOND_FILLED = 5,
  TRIANGLE_FILLED = 6,
  HIGHLIGHT = 7,
  WASHI_TAPE_1 = 8,
  WASHI_TAPE_2 = 9,
  WASHI_TAPE_3 = 10,
  WASHI_TAPE_4 = 11,
  WASHI_TAPE_5 = 12,
  WASHI_TAPE_6 = 13,
  CIRCLE_FILLED = 14,
};

enum class StrokeJoin : uint32_t {
  MITER = 0,
  BEVEL = 1,
  ROUND = 2,
};

enum class BooleanOperation : uint32_t {
  UNION = 0,
  INTERSECT = 1,
  SUBTRACT = 2,
  XOR = 3,
};

enum class TextAlignHorizontal : uint32_t {
  LEFT = 0,
  CENTER = 1,
  RIGHT = 2,
  JUSTIFIED = 3,
};

enum class TextAlignVertical : uint32_t {
  TOP = 0,
  CENTER = 1,
  BOTTOM = 2,
};

enum class MouseCursor : uint32_t {
  DEFAULT = 0,
  CROSSHAIR = 1,
  EYEDROPPER = 2,
  HAND = 3,
  PAINT_BUCKET = 4,
  PEN = 5,
  PENCIL = 6,
  MARKER = 7,
  ERASER = 8,
  HIGHLIGHTER = 9,
};

enum class VectorMirror : uint32_t {
  NONE = 0,
  ANGLE = 1,
  ANGLE_AND_LENGTH = 2,
};

enum class DashMode : uint32_t {
  CLIP = 0,
  STRETCH = 1,
};

enum class ImageType : uint32_t {
  PNG = 0,
  JPEG = 1,
  SVG = 2,
  PDF = 3,
};

enum class ExportConstraintType : uint32_t {
  CONTENT_SCALE = 0,
  CONTENT_WIDTH = 1,
  CONTENT_HEIGHT = 2,
};

enum class LayoutGridType : uint32_t {
  MIN = 0,
  CENTER = 1,
  STRETCH = 2,
  MAX = 3,
};

enum class LayoutGridPattern : uint32_t {
  STRIPES = 0,
  GRID = 1,
};

enum class TextAutoResize : uint32_t {
  NONE = 0,
  WIDTH_AND_HEIGHT = 1,
  HEIGHT = 2,
};

enum class TextTruncation : uint32_t {
  DISABLED = 0,
  ENDING = 1,
};

enum class StyleSetType : uint32_t {
  PERSONAL = 0,
  TEAM = 1,
  CUSTOM = 2,
  FREQUENCY = 3,
  TEMPORARY = 4,
};

enum class StyleSetContentType : uint32_t {
  SOLID = 0,
  GRADIENT = 1,
  IMAGE = 2,
};

enum class StackMode : uint32_t {
  NONE = 0,
  HORIZONTAL = 1,
  VERTICAL = 2,
};

enum class StackAlign : uint32_t {
  MIN = 0,
  CENTER = 1,
  MAX = 2,
  BASELINE = 3,
};

enum class StackCounterAlign : uint32_t {
  MIN = 0,
  CENTER = 1,
  MAX = 2,
  STRETCH = 3,
  AUTO = 4,
  BASELINE = 5,
};

enum class StackJustify : uint32_t {
  MIN = 0,
  CENTER = 1,
  MAX = 2,
  SPACE_EVENLY = 3,
  SPACE_BETWEEN = 4,
};

enum class StackSize : uint32_t {
  FIXED = 0,
  RESIZE_TO_FIT = 1,
  RESIZE_TO_FIT_WITH_IMPLICIT_SIZE = 2,
};

enum class StackPositioning : uint32_t {
  AUTO = 0,
  ABSOLUTE = 1,
};

enum class StackWrap : uint32_t {
  NO_WRAP = 0,
  WRAP = 1,
};

enum class StackCounterAlignContent : uint32_t {
  AUTO = 0,
  SPACE_BETWEEN = 1,
};

enum class ConnectionType : uint32_t {
  NONE = 0,
  INTERNAL_NODE = 1,
  URL = 2,
  BACK = 3,
  CLOSE = 4,
  SET_VARIABLE = 5,
  UPDATE_MEDIA_RUNTIME = 6,
  CONDITIONAL = 7,
};

enum class InteractionType : uint32_t {
  ON_CLICK = 0,
  AFTER_TIMEOUT = 1,
  MOUSE_IN = 2,
  MOUSE_OUT = 3,
  ON_HOVER = 4,
  MOUSE_DOWN = 5,
  MOUSE_UP = 6,
  ON_PRESS = 7,
  NONE = 8,
  DRAG = 9,
  ON_KEY_DOWN = 10,
  ON_VOICE = 11,
  ON_MEDIA_HIT = 12,
  ON_MEDIA_END = 13,
  MOUSE_ENTER = 14,
  MOUSE_LEAVE = 15,
};

enum class TransitionType : uint32_t {
  INSTANT_TRANSITION = 0,
  DISSOLVE = 1,
  FADE = 2,
  SLIDE_FROM_LEFT = 3,
  SLIDE_FROM_RIGHT = 4,
  SLIDE_FROM_TOP = 5,
  SLIDE_FROM_BOTTOM = 6,
  PUSH_FROM_LEFT = 7,
  PUSH_FROM_RIGHT = 8,
  PUSH_FROM_TOP = 9,
  PUSH_FROM_BOTTOM = 10,
  MOVE_FROM_LEFT = 11,
  MOVE_FROM_RIGHT = 12,
  MOVE_FROM_TOP = 13,
  MOVE_FROM_BOTTOM = 14,
  SLIDE_OUT_TO_LEFT = 15,
  SLIDE_OUT_TO_RIGHT = 16,
  SLIDE_OUT_TO_TOP = 17,
  SLIDE_OUT_TO_BOTTOM = 18,
  MOVE_OUT_TO_LEFT = 19,
  MOVE_OUT_TO_RIGHT = 20,
  MOVE_OUT_TO_TOP = 21,
  MOVE_OUT_TO_BOTTOM = 22,
  MAGIC_MOVE = 23,
  SMART_ANIMATE = 24,
  SCROLL_ANIMATE = 25,
};

enum class EasingType : uint32_t {
  IN_CUBIC = 0,
  OUT_CUBIC = 1,
  INOUT_CUBIC = 2,
  LINEAR = 3,
  IN_BACK_CUBIC = 4,
  OUT_BACK_CUBIC = 5,
  INOUT_BACK_CUBIC = 6,
  CUSTOM_CUBIC = 7,
  SPRING = 8,
  GENTLE_SPRING = 9,
  CUSTOM_SPRING = 10,
  SPRING_PRESET_ONE = 11,
  SPRING_PRESET_TWO = 12,
  SPRING_PRESET_THREE = 13,
};

enum class ScrollDirection : uint32_t {
  NONE = 0,
  HORIZONTAL = 1,
  VERTICAL = 2,
  BOTH = 3,
};

enum class ScrollContractedState : uint32_t {
  EXPANDED = 0,
  CONTRACTED = 1,
};

enum class FontVariantNumericFigure : uint32_t {
  NORMAL = 0,
  LINING = 1,
  OLDSTYLE = 2,
};

enum class FontVariantNumericSpacing : uint32_t {
  NORMAL = 0,
  PROPORTIONAL = 1,
  TABULAR = 2,
};

enum class FontVariantNumericFraction : uint32_t {
  NORMAL = 0,
  DIAGONAL = 1,
  STACKED = 2,
};

enum class FontVariantCaps : uint32_t {
  NORMAL = 0,
  SMALL = 1,
  ALL_SMALL = 2,
  PETITE = 3,
  ALL_PETITE = 4,
  UNICASE = 5,
  TITLING = 6,
};

enum class FontVariantPosition : uint32_t {
  NORMAL = 0,
  SUB = 1,
  SUPER = 2,
};

enum class FontStyle : uint32_t {
  NORMAL = 0,
  ITALIC = 1,
};

enum class OpenTypeFeature : uint32_t {
  PCAP = 0,
  C2PC = 1,
  CASE = 2,
  CPSP = 3,
  TITL = 4,
  UNIC = 5,
  ZERO = 6,
  SINF = 7,
  ORDN = 8,
  AFRC = 9,
  DNOM = 10,
  NUMR = 11,
  LIGA = 12,
  CLIG = 13,
  DLIG = 14,
  HLIG = 15,
  RLIG = 16,
  AALT = 17,
  CALT = 18,
  RCLT = 19,
  SALT = 20,
  RVRN = 21,
  VERT = 22,
  SWSH = 23,
  CSWH = 24,
  NALT = 25,
  CCMP = 26,
  STCH = 27,
  HIST = 28,
  SIZE = 29,
  ORNM = 30,
  ITAL = 31,
  RAND = 32,
  DTLS = 33,
  FLAC = 34,
  MGRK = 35,
  SSTY = 36,
  KERN = 37,
  FWID = 38,
  HWID = 39,
  HALT = 40,
  TWID = 41,
  QWID = 42,
  PWID = 43,
  JUST = 44,
  LFBD = 45,
  OPBD = 46,
  RTBD = 47,
  PALT = 48,
  PKNA = 49,
  LTRA = 50,
  LTRM = 51,
  RTLA = 52,
  RTLM = 53,
  ABRV = 54,
  ABVM = 55,
  ABVS = 56,
  VALT = 57,
  VHAL = 58,
  BLWF = 59,
  BLWM = 60,
  BLWS = 61,
  AKHN = 62,
  CJCT = 63,
  CFAR = 64,
  CPCT = 65,
  CURS = 66,
  DIST = 67,
  EXPT = 68,
  FALT = 69,
  FINA = 70,
  FIN2 = 71,
  FIN3 = 72,
  HALF = 73,
  HALN = 74,
  HKNA = 75,
  HNGL = 76,
  HOJO = 77,
  INIT = 78,
  ISOL = 79,
  JP78 = 80,
  JP83 = 81,
  JP90 = 82,
  JP04 = 83,
  LJMO = 84,
  LOCL = 85,
  MARK = 86,
  MEDI = 87,
  MED2 = 88,
  MKMK = 89,
  NLCK = 90,
  NUKT = 91,
  PREF = 92,
  PRES = 93,
  VPAL = 94,
  PSTF = 95,
  PSTS = 96,
  RKRF = 97,
  RPHF = 98,
  RUBY = 99,
  SMPL = 100,
  TJMO = 101,
  TNAM = 102,
  TRAD = 103,
  VATU = 104,
  VJMO = 105,
  VKNA = 106,
  VKRN = 107,
  VRTR = 108,
  VRT2 = 109,
  SS01 = 110,
  SS02 = 111,
  SS03 = 112,
  SS04 = 113,
  SS05 = 114,
  SS06 = 115,
  SS07 = 116,
  SS08 = 117,
  SS09 = 118,
  SS10 = 119,
  SS11 = 120,
  SS12 = 121,
  SS13 = 122,
  SS14 = 123,
  SS15 = 124,
  SS16 = 125,
  SS17 = 126,
  SS18 = 127,
  SS19 = 128,
  SS20 = 129,
  CV01 = 130,
  CV02 = 131,
  CV03 = 132,
  CV04 = 133,
  CV05 = 134,
  CV06 = 135,
  CV07 = 136,
  CV08 = 137,
  CV09 = 138,
  CV10 = 139,
  CV11 = 140,
  CV12 = 141,
  CV13 = 142,
  CV14 = 143,
  CV15 = 144,
  CV16 = 145,
  CV17 = 146,
  CV18 = 147,
  CV19 = 148,
  CV20 = 149,
  CV21 = 150,
  CV22 = 151,
  CV23 = 152,
  CV24 = 153,
  CV25 = 154,
  CV26 = 155,
  CV27 = 156,
  CV28 = 157,
  CV29 = 158,
  CV30 = 159,
  CV31 = 160,
  CV32 = 161,
  CV33 = 162,
  CV34 = 163,
  CV35 = 164,
  CV36 = 165,
  CV37 = 166,
  CV38 = 167,
  CV39 = 168,
  CV40 = 169,
  CV41 = 170,
  CV42 = 171,
  CV43 = 172,
  CV44 = 173,
  CV45 = 174,
  CV46 = 175,
  CV47 = 176,
  CV48 = 177,
  CV49 = 178,
  CV50 = 179,
  CV51 = 180,
  CV52 = 181,
  CV53 = 182,
  CV54 = 183,
  CV55 = 184,
  CV56 = 185,
  CV57 = 186,
  CV58 = 187,
  CV59 = 188,
  CV60 = 189,
  CV61 = 190,
  CV62 = 191,
  CV63 = 192,
  CV64 = 193,
  CV65 = 194,
  CV66 = 195,
  CV67 = 196,
  CV68 = 197,
  CV69 = 198,
  CV70 = 199,
  CV71 = 200,
  CV72 = 201,
  CV73 = 202,
  CV74 = 203,
  CV75 = 204,
  CV76 = 205,
  CV77 = 206,
  CV78 = 207,
  CV79 = 208,
  CV80 = 209,
  CV81 = 210,
  CV82 = 211,
  CV83 = 212,
  CV84 = 213,
  CV85 = 214,
  CV86 = 215,
  CV87 = 216,
  CV88 = 217,
  CV89 = 218,
  CV90 = 219,
  CV91 = 220,
  CV92 = 221,
  CV93 = 222,
  CV94 = 223,
  CV95 = 224,
  CV96 = 225,
  CV97 = 226,
  CV98 = 227,
  CV99 = 228,
};

enum class PrototypeDeviceType : uint32_t {
  NONE = 0,
  PRESET = 1,
  CUSTOM = 2,
  PRESENTATION = 3,
};

enum class DeviceRotation : uint32_t {
  NONE = 0,
  CCW_90 = 1,
};

enum class OverlayPositionType : uint32_t {
  CENTER = 0,
  TOP_LEFT = 1,
  TOP_CENTER = 2,
  TOP_RIGHT = 3,
  BOTTOM_LEFT = 4,
  BOTTOM_CENTER = 5,
  BOTTOM_RIGHT = 6,
  MANUAL = 7,
};

enum class OverlayBackgroundInteraction : uint32_t {
  NONE = 0,
  CLOSE_ON_CLICK_OUTSIDE = 1,
};

enum class OverlayBackgroundType : uint32_t {
  NONE = 0,
  SOLID_COLOR = 1,
};

enum class NavigationType : uint32_t {
  NAVIGATE = 0,
  OVERLAY = 1,
  SWAP = 2,
  SWAP_STATE = 3,
  SCROLL_TO = 4,
};

enum class ExportColorProfile : uint32_t {
  DOCUMENT = 0,
  SRGB = 1,
  DISPLAY_P3_V4 = 2,
};

enum class ExportSVGIDMode : uint32_t {
  IF_NEEDED = 0,
  ALWAYS = 1,
};

enum class StyleType : uint32_t {
  NONE = 0,
  FILL = 1,
  STROKE = 2,
  TEXT = 3,
  EFFECT = 4,
  EXPORT = 5,
  GRID = 6,
};

enum class ScrollBehavior : uint32_t {
  SCROLLS = 0,
  FIXED_WHEN_CHILD_OF_SCROLLING_FRAME = 1,
  STICKY_SCROLLS = 2,
};

enum class ConnectorMagnet : uint32_t {
  NONE = 0,
  AUTO = 1,
  TOP = 2,
  LEFT = 3,
  BOTTOM = 4,
  RIGHT = 5,
  CENTER = 6,
};

enum class ConnectorTextSection : uint32_t {
  MIDDLE_TO_START = 0,
  MIDDLE_TO_END = 1,
};

enum class ConnectorLineStyle : uint32_t {
  ELBOWED = 0,
  STRAIGHT = 1,
};

enum class EditorType : uint32_t {
  DESIGN = 0,
  WHITEBOARD = 1,
  SLIDES = 2,
};

enum class MaskType : uint32_t {
  ALPHA = 0,
  OUTLINE = 1,
  LUMINANCE = 2,
};

enum class SectionStatus : uint32_t {
  NONE = 0,
  BUILD = 1,
};

enum class MediaAction : uint32_t {
  PLAY = 0,
  PAUSE = 1,
  TOGGLE_PLAY_PAUSE = 2,
  MUTE = 3,
  UNMUTE = 4,
  TOGGLE_MUTE_UNMUTE = 5,
  SKIP_FORWARD = 6,
  SKIP_BACKWARD = 7,
  SKIP_TO = 8,
};

enum class VariableField : uint32_t {
  MISSING = 0,
  CORNER_RADIUS = 1,
  PARAGRAPH_SPACING = 2,
  PARAGRAPH_INDENT = 3,
  STROKE_WEIGHT = 4,
  STACK_SPACING = 5,
  STACK_PADDING_LEFT = 6,
  STACK_PADDING_TOP = 7,
  STACK_PADDING_RIGHT = 8,
  STACK_PADDING_BOTTOM = 9,
  VISIBLE = 10,
  TEXT_DATA = 11,
  WIDTH = 12,
  HEIGHT = 13,
  RECTANGLE_TOP_LEFT_CORNER_RADIUS = 14,
  RECTANGLE_TOP_RIGHT_CORNER_RADIUS = 15,
  RECTANGLE_BOTTOM_LEFT_CORNER_RADIUS = 16,
  RECTANGLE_BOTTOM_RIGHT_CORNER_RADIUS = 17,
  BORDER_TOP_WEIGHT = 18,
  BORDER_BOTTOM_WEIGHT = 19,
  BORDER_LEFT_WEIGHT = 20,
  BORDER_RIGHT_WEIGHT = 21,
  VARIANT_PROPERTIES = 22,
  STACK_COUNTER_SPACING = 23,
  MIN_WIDTH = 24,
  MAX_WIDTH = 25,
  MIN_HEIGHT = 26,
  MAX_HEIGHT = 27,
};

enum class AgendaItemType : uint32_t {
  NODE = 0,
  BLOCK = 1,
};

enum class ComponentPropNodeField : uint32_t {
  VISIBLE = 0,
  TEXT_DATA = 1,
  OVERRIDDEN_SYMBOL_ID = 2,
  INHERIT_FILL_STYLE_ID = 3,
};

enum class ComponentPropType : uint32_t {
  BOOL = 0,
  TEXT = 1,
  COLOR = 2,
  INSTANCE_SWAP = 3,
};

enum class InstanceSwapPreferredValueType : uint32_t {
  COMPONENT = 0,
  STATE_GROUP = 1,
};

enum class WidgetEvent : uint32_t {
  MOUSE_DOWN = 0,
  CLICK = 1,
  TEXT_EDIT_END = 2,
  ATTACHED_STICKABLES_CHANGED = 3,
  STUCK_STATUS_CHANGED = 4,
};

enum class WidgetInputBehavior : uint32_t {
  WRAP = 0,
  TRUNCATE = 1,
  MULTILINE = 2,
};

enum class WidgetPropertyMenuItemType : uint32_t {
  ACTION = 0,
  SEPARATOR = 1,
  COLOR = 2,
  DROPDOWN = 3,
  COLOR_SELECTOR = 4,
  TOGGLE = 5,
  LINK = 6,
};

enum class CodeBlockLanguage : uint32_t {
  TYPESCRIPT = 0,
  CPP = 1,
  RUBY = 2,
  CSS = 3,
  JAVASCRIPT = 4,
  HTML = 5,
  JSON = 6,
  GRAPHQL = 7,
  PYTHON = 8,
  GO = 9,
  SQL = 10,
  SWIFT = 11,
  KOTLIN = 12,
  RUST = 13,
  BASH = 14,
  PLAINTEXT = 15,
};

enum class InternalEnumForTest : uint32_t {
  OLD = 1,
};

enum class BulletType : uint32_t {
  ORDERED = 0,
  UNORDERED = 1,
  INDENT = 2,
  NO_LIST = 3,
};

enum class LineType : uint32_t {
  PLAIN = 0,
  ORDERED_LIST = 1,
  UNORDERED_LIST = 2,
  BLOCKQUOTE = 3,
  HEADER = 4,
};

enum class SourceDirectionality : uint32_t {
  AUTO = 0,
  LTR = 1,
  RTL = 2,
};

enum class Directionality : uint32_t {
  LTR = 0,
  RTL = 1,
};

enum class DirectionalityIntent : uint32_t {
  IMPLICIT = 0,
  EXPLICIT = 1,
};

enum class TriggerDevice : uint32_t {
  KEYBOARD = 0,
  UNKNOWN_CONTROLLER = 1,
  XBOX_ONE = 2,
  PS4 = 3,
  SWITCH_PRO = 4,
};

enum class MentionSource : uint32_t {
  DEFAULT = 0,
  COPY_DUPLICATE = 1,
};

enum class TransitionDirection : uint32_t {
  FORWARD = 0,
  REVERSE = 1,
};

enum class PlaybackChangePhase : uint32_t {
  INITIATED = 0,
  ABORTED = 1,
  COMMITTED = 2,
};

enum class Heartbeat : uint32_t {
  FOREGROUND = 0,
  BACKGROUND = 1,
};

enum class RichMediaType : uint32_t {
  ANIMATED_IMAGE = 0,
  VIDEO = 1,
};

enum class VariableDataType : uint32_t {
  BOOLEAN = 0,
  FLOAT = 1,
  STRING = 2,
  ALIAS = 3,
  COLOR = 4,
  EXPRESSION = 5,
  MAP = 6,
  SYMBOL_ID = 7,
};

enum class VariableResolvedDataType : uint32_t {
  BOOLEAN = 0,
  FLOAT = 1,
  STRING = 2,
  COLOR = 4,
  MAP = 5,
  SYMBOL_ID = 6,
};

enum class ExpressionFunction : uint32_t {
  ADDITION = 0,
  SUBTRACTION = 1,
  RESOLVE_VARIANT = 2,
  MULTIPLY = 3,
  DIVIDE = 4,
  EQUALS = 5,
  NOT_EQUAL = 6,
  LESS_THAN = 7,
  LESS_THAN_OR_EQUAL = 8,
  GREATER_THAN = 9,
  GREATER_THAN_OR_EQUAL = 10,
  AND = 11,
  OR = 12,
  NOT = 13,
  STRINGIFY = 14,
  TERNARY = 15,
  VAR_MODE_LOOKUP = 16,
};

enum class VariableScope : uint32_t {
  ALL_SCOPES = 0,
  TEXT_CONTENT = 1,
  CORNER_RADIUS = 2,
  WIDTH_HEIGHT = 3,
  GAP = 4,
  ALL_FILLS = 5,
  FRAME_FILL = 6,
  SHAPE_FILL = 7,
  TEXT_FILL = 8,
  STROKE = 9,
};

enum class CodeSyntaxPlatform : uint32_t {
  WEB = 0,
  ANDROID = 1,
  iOS = 2,
};

enum class HTMLTag : uint32_t {
  AUTO = 0,
  ARTICLE = 1,
  SECTION = 2,
  NAV = 3,
  ASIDE = 4,
  H1 = 5,
  H2 = 6,
  H3 = 7,
  H4 = 8,
  H5 = 9,
  H6 = 10,
  HGROUP = 11,
  HEADER = 12,
  FOOTER = 13,
  ADDRESS = 14,
  P = 15,
  HR = 16,
  PRE = 17,
  BLOCKQUOTE = 18,
  OL = 19,
  UL = 20,
  MENU = 21,
  LI = 22,
  DL = 23,
  DT = 24,
  DD = 25,
  FIGURE = 26,
  FIGCAPTION = 27,
  MAIN = 28,
  DIV = 29,
  A = 30,
  EM = 31,
  STRONG = 32,
  SMALL = 33,
  S = 34,
  CITE = 35,
  Q = 36,
  DFN = 37,
  ABBR = 38,
  RUBY = 39,
  RT = 40,
  RP = 41,
  DATA = 42,
  TIME = 43,
  CODE = 44,
  VAR = 45,
  SAMP = 46,
  KBD = 47,
  SUB = 48,
  SUP = 49,
  I = 50,
  B = 51,
  U = 52,
  MARK = 53,
  BDI = 54,
  BDO = 55,
  SPAN = 56,
  BR = 57,
  WBR = 58,
  PICTURE = 59,
  SOURCE = 60,
  IMG = 61,
  FORM = 62,
  LABEL = 63,
  INPUT = 64,
  BUTTON = 65,
  SELECT = 66,
  DATALIST = 67,
  OPTGROUP = 68,
  OPTION = 69,
  TEXTAREA = 70,
  OUTPUT = 71,
  PROGRESS = 72,
  METER = 73,
  FIELDSET = 74,
  LEGEND = 75,
};

enum class ARIARole : uint32_t {
  AUTO = 0,
  NONE = 52,
  APPLICATION = 30,
  BANNER = 67,
  COMPLEMENTARY = 68,
  CONTENTINFO = 69,
  FORM = 70,
  MAIN = 71,
  NAVIGATION = 72,
  REGION = 73,
  SEARCH = 74,
  SEPARATOR = 13,
  ARTICLE = 31,
  COLUMNHEADER = 35,
  DEFINITION = 36,
  DIRECTORY = 38,
  DOCUMENT = 39,
  GROUP = 44,
  HEADING = 45,
  IMG = 46,
  LIST = 48,
  LISTITEM = 49,
  MATH = 50,
  NOTE = 53,
  PRESENTATION = 55,
  ROW = 56,
  ROWGROUP = 57,
  ROWHEADER = 58,
  TABLE = 62,
  TOOLBAR = 65,
  BUTTON = 1,
  CHECKBOX = 2,
  GRIDCELL = 3,
  LINK = 4,
  MENUITEM = 5,
  MENUITEMCHECKBOX = 6,
  MENUITEMRADIO = 7,
  OPTION = 8,
  PROGRESSBAR = 9,
  RADIO = 10,
  SCROLLBAR = 11,
  SLIDER = 14,
  SPINBUTTON = 15,
  TAB = 17,
  TABPANEL = 18,
  TEXTBOX = 19,
  TREEITEM = 20,
  COMBOBOX = 21,
  GRID = 22,
  LISTBOX = 23,
  MENU = 24,
  MENUBAR = 25,
  RADIOGROUP = 26,
  TABLIST = 27,
  TREE = 28,
  TREEGRID = 29,
  TOOLTIP = 66,
  ALERT = 75,
  LOG = 76,
  MARQUEE = 77,
  STATUS = 78,
  TIMER = 79,
  ALERTDIALOG = 80,
  DIALOG = 81,
  SEARCHBOX = 12,
  SWITCH = 16,
  BLOCKQUOTE = 32,
  CAPTION = 33,
  CELL = 34,
  DELETION = 37,
  EMPHASIS = 40,
  FEED = 41,
  FIGURE = 42,
  GENERIC = 43,
  INSERTION = 47,
  METER = 51,
  PARAGRAPH = 54,
  STRONG = 59,
  SUBSCRIPT = 60,
  SUPERSCRIPT = 61,
  TERM = 63,
  TIME = 64,
  IMAGE = 82,
  HEADING_1 = 83,
  HEADING_2 = 84,
  HEADING_3 = 85,
  HEADING_4 = 86,
  HEADING_5 = 87,
  HEADING_6 = 88,
  HEADER = 89,
  FOOTER = 90,
  SIDEBAR = 91,
  SECTION = 92,
  MAINCONTENT = 93,
  TABLE_CELL = 94,
  WIDGET = 95,
};

enum class ColorProfile : uint32_t {
  SRGB = 0,
  DISPLAY_P3 = 1,
};

enum class DocumentColorProfile : uint32_t {
  LEGACY = 0,
  SRGB = 1,
  DISPLAY_P3 = 2,
};

enum class ChildReadingDirection : uint32_t {
  NONE = 0,
  LEFT_TO_RIGHT = 1,
  RIGHT_TO_LEFT = 2,
};

enum class ARIAAttributeDataType : uint32_t {
  BOOLEAN = 0,
  STRING = 1,
  FLOAT = 2,
  INT = 3,
};

class GUID;
class Color;
class Vector;
class Rect;
class ColorStop;
class Matrix;
class ParentIndex;
class Number;
class FontName;
class ExportConstraint;
class GUIDMapping;
class Blob;
class Image;
class Video;
class FilterColorAdjust;
class PaintFilterMessage;
class Paint;
class FontMetaData;
class FontVariation;
class TextData;
class DerivedTextData;
class HyperlinkBox;
class MentionBox;
class Baseline;
class Glyph;
class Decoration;
class Blockquote;
class VectorData;
class GUIDPath;
class SymbolData;
class GUIDPathMapping;
class NodeGenerationData;
class DerivedImmutableFrameData;
class AssetRef;
class StateGroupId;
class StyleId;
class SymbolId;
class VariableID;
class VariableSetID;
class SharedSymbolReference;
class SharedComponentMasterData;
class InstanceOverrideStash;
class InstanceOverrideStashV2;
class Effect;
class TransitionInfo;
class PrototypeDevice;
class OverlayBackgroundAppearance;
class ExportSettings;
class LayoutGrid;
class Guide;
class Path;
class SharedStyleReference;
class SharedStyleMasterData;
class ArcData;
class SymbolLink;
class PluginData;
class PluginRelaunchData;
class MultiplayerFieldVersion;
class ConnectorEndpoint;
class ConnectorControlPoint;
class ConnectorTextMidpoint;
class LibraryMoveInfo;
class LibraryMoveHistoryItem;
class DeveloperRelatedLink;
class WidgetPointer;
class EditInfo;
class SectionStatusInfo;
class NodeChange;
class VideoPlayback;
class WidgetHoverStyle;
class WidgetDerivedSubtreeCursor;
class MultiplayerMap;
class MultiplayerMapEntry;
class VariableDataMap;
class VariableDataMapEntry;
class VariableModeBySetMap;
class VariableModeBySetMapEntry;
class CodeSyntaxMap;
class CodeSyntaxMapEntry;
class TableRowColumnPositionMap;
class TableRowColumnPositionMapEntry;
class TableRowColumnSizeMap;
class TableRowColumnSizeMapEntry;
class AgendaPositionMap;
class AgendaPositionMapEntry;
class AgendaMetadataMap;
class AgendaMetadataMapEntry;
class AgendaMetadata;
class AgendaTimerInfo;
class AgendaVoteInfo;
class AgendaMusicInfo;
class ComponentPropRef;
class ComponentPropAssignment;
class ComponentPropDef;
class ComponentPropValue;
class ComponentPropPreferredValues;
class InstanceSwapPreferredValue;
class WidgetMetadata;
class WidgetPropertyMenuSelectorOption;
class WidgetPropertyMenuItem;
class InternalDataForTest;
class StateGroupPropertyValueOrder;
class TextListData;
class TextLineData;
class DerivedTextLineData;
class PrototypeInteraction;
class PrototypeEvent;
class PrototypeVariableTarget;
class ConditionalActions;
class PrototypeAction;
class PrototypeStartingPoint;
class KeyTrigger;
class Hyperlink;
class Mention;
class EmbedData;
class StampData;
class LinkPreviewData;
class Viewport;
class Mouse;
class Click;
class ScrollPosition;
class TriggeredOverlay;
class TriggeredOverlayData;
class PresentedState;
class TopLevelPlaybackChange;
class InstanceStateChange;
class TextCursor;
class TextSelection;
class PlaybackChangeKeyframe;
class StateMapping;
class ScrollMapping;
class PlaybackUpdate;
class ChatMessage;
class VoiceMetadata;
class UserChange;
class SceneGraphQuery;
class NodeChangesMetadata;
class CursorReaction;
class TimerInfo;
class MusicInfo;
class PresenterNomination;
class PresenterInfo;
class ClientBroadcast;
class Message;
class DiffChunk;
class DiffPayload;
class RichMediaData;
class VariableAnyValue;
class Expression;
class VariableMapValue;
class VariableMap;
class VariableData;
class VariableSetMode;
class VariableDataValues;
class VariableDataValuesEntry;
class OptionalVector;
class MigrationStatus;
class NodeFieldMap;
class NodeFieldMapEntry;
class ARIAAttributeAnyValue;
class ARIAAttributeData;
class ARIAAttributesMap;
class ARIAAttributesMapEntry;
class HandoffStatusMapEntry;
class HandoffStatusMap;

class GUID {
public:
  GUID() { (void)_flags; }

  uint32_t *sessionID();
  const uint32_t *sessionID() const;
  void set_sessionID(const uint32_t &value);

  uint32_t *localID();
  const uint32_t *localID() const;
  void set_localID(const uint32_t &value);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  uint32_t _data_sessionID = {};
  uint32_t _data_localID = {};
};

class Color {
public:
  Color() { (void)_flags; }

  float *r();
  const float *r() const;
  void set_r(const float &value);

  float *g();
  const float *g() const;
  void set_g(const float &value);

  float *b();
  const float *b() const;
  void set_b(const float &value);

  float *a();
  const float *a() const;
  void set_a(const float &value);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  float _data_r = {};
  float _data_g = {};
  float _data_b = {};
  float _data_a = {};
};

class Vector {
public:
  Vector() { (void)_flags; }

  float *x();
  const float *x() const;
  void set_x(const float &value);

  float *y();
  const float *y() const;
  void set_y(const float &value);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  float _data_x = {};
  float _data_y = {};
};

class Rect {
public:
  Rect() { (void)_flags; }

  float *x();
  const float *x() const;
  void set_x(const float &value);

  float *y();
  const float *y() const;
  void set_y(const float &value);

  float *w();
  const float *w() const;
  void set_w(const float &value);

  float *h();
  const float *h() const;
  void set_h(const float &value);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  float _data_x = {};
  float _data_y = {};
  float _data_w = {};
  float _data_h = {};
};

class ColorStop {
public:
  ColorStop() { (void)_flags; }

  Color *color();
  const Color *color() const;
  void set_color(Color *value);

  float *position();
  const float *position() const;
  void set_position(const float &value);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  Color *_data_color = {};
  float _data_position = {};
};

class Matrix {
public:
  Matrix() { (void)_flags; }

  float *m00();
  const float *m00() const;
  void set_m00(const float &value);

  float *m01();
  const float *m01() const;
  void set_m01(const float &value);

  float *m02();
  const float *m02() const;
  void set_m02(const float &value);

  float *m10();
  const float *m10() const;
  void set_m10(const float &value);

  float *m11();
  const float *m11() const;
  void set_m11(const float &value);

  float *m12();
  const float *m12() const;
  void set_m12(const float &value);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  float _data_m00 = {};
  float _data_m01 = {};
  float _data_m02 = {};
  float _data_m10 = {};
  float _data_m11 = {};
  float _data_m12 = {};
};

class ParentIndex {
public:
  ParentIndex() { (void)_flags; }

  GUID *guid();
  const GUID *guid() const;
  void set_guid(GUID *value);

  kiwi::String *position();
  const kiwi::String *position() const;
  void set_position(const kiwi::String &value);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  GUID *_data_guid = {};
  kiwi::String _data_position = {};
};

class Number {
public:
  Number() { (void)_flags; }

  float *value();
  const float *value() const;
  void set_value(const float &value);

  NumberUnits *units();
  const NumberUnits *units() const;
  void set_units(const NumberUnits &value);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  NumberUnits _data_units = {};
  float _data_value = {};
};

class FontName {
public:
  FontName() { (void)_flags; }

  kiwi::String *family();
  const kiwi::String *family() const;
  void set_family(const kiwi::String &value);

  kiwi::String *style();
  const kiwi::String *style() const;
  void set_style(const kiwi::String &value);

  kiwi::String *postscript();
  const kiwi::String *postscript() const;
  void set_postscript(const kiwi::String &value);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  kiwi::String _data_family = {};
  kiwi::String _data_style = {};
  kiwi::String _data_postscript = {};
};

class ExportConstraint {
public:
  ExportConstraint() { (void)_flags; }

  ExportConstraintType *type();
  const ExportConstraintType *type() const;
  void set_type(const ExportConstraintType &value);

  float *value();
  const float *value() const;
  void set_value(const float &value);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  ExportConstraintType _data_type = {};
  float _data_value = {};
};

class GUIDMapping {
public:
  GUIDMapping() { (void)_flags; }

  GUID *from();
  const GUID *from() const;
  void set_from(GUID *value);

  GUID *to();
  const GUID *to() const;
  void set_to(GUID *value);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  GUID *_data_from = {};
  GUID *_data_to = {};
};

class Blob {
public:
  Blob() { (void)_flags; }

  kiwi::Array<uint8_t> *bytes();
  const kiwi::Array<uint8_t> *bytes() const;
  kiwi::Array<uint8_t> &set_bytes(kiwi::MemoryPool &pool, uint32_t count);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  kiwi::Array<uint8_t> _data_bytes = {};
};

class Image {
public:
  Image() { (void)_flags; }

  kiwi::Array<uint8_t> *hash();
  const kiwi::Array<uint8_t> *hash() const;
  kiwi::Array<uint8_t> &set_hash(kiwi::MemoryPool &pool, uint32_t count);

  kiwi::String *name();
  const kiwi::String *name() const;
  void set_name(const kiwi::String &value);

  uint32_t *dataBlob();
  const uint32_t *dataBlob() const;
  void set_dataBlob(const uint32_t &value);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  kiwi::Array<uint8_t> _data_hash = {};
  kiwi::String _data_name = {};
  uint32_t _data_dataBlob = {};
};

class Video {
public:
  Video() { (void)_flags; }

  kiwi::Array<uint8_t> *hash();
  const kiwi::Array<uint8_t> *hash() const;
  kiwi::Array<uint8_t> &set_hash(kiwi::MemoryPool &pool, uint32_t count);

  kiwi::String *s3Url();
  const kiwi::String *s3Url() const;
  void set_s3Url(const kiwi::String &value);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  kiwi::Array<uint8_t> _data_hash = {};
  kiwi::String _data_s3Url = {};
};

class FilterColorAdjust {
public:
  FilterColorAdjust() { (void)_flags; }

  float *tint();
  const float *tint() const;
  void set_tint(const float &value);

  float *shadows();
  const float *shadows() const;
  void set_shadows(const float &value);

  float *highlights();
  const float *highlights() const;
  void set_highlights(const float &value);

  float *detail();
  const float *detail() const;
  void set_detail(const float &value);

  float *exposure();
  const float *exposure() const;
  void set_exposure(const float &value);

  float *vignette();
  const float *vignette() const;
  void set_vignette(const float &value);

  float *temperature();
  const float *temperature() const;
  void set_temperature(const float &value);

  float *vibrance();
  const float *vibrance() const;
  void set_vibrance(const float &value);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  float _data_tint = {};
  float _data_shadows = {};
  float _data_highlights = {};
  float _data_detail = {};
  float _data_exposure = {};
  float _data_vignette = {};
  float _data_temperature = {};
  float _data_vibrance = {};
};

class PaintFilterMessage {
public:
  PaintFilterMessage() { (void)_flags; }

  float *tint();
  const float *tint() const;
  void set_tint(const float &value);

  float *shadows();
  const float *shadows() const;
  void set_shadows(const float &value);

  float *highlights();
  const float *highlights() const;
  void set_highlights(const float &value);

  float *detail();
  const float *detail() const;
  void set_detail(const float &value);

  float *exposure();
  const float *exposure() const;
  void set_exposure(const float &value);

  float *vignette();
  const float *vignette() const;
  void set_vignette(const float &value);

  float *temperature();
  const float *temperature() const;
  void set_temperature(const float &value);

  float *vibrance();
  const float *vibrance() const;
  void set_vibrance(const float &value);

  float *contrast();
  const float *contrast() const;
  void set_contrast(const float &value);

  float *brightness();
  const float *brightness() const;
  void set_brightness(const float &value);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  float _data_tint = {};
  float _data_shadows = {};
  float _data_highlights = {};
  float _data_detail = {};
  float _data_exposure = {};
  float _data_vignette = {};
  float _data_temperature = {};
  float _data_vibrance = {};
  float _data_contrast = {};
  float _data_brightness = {};
};

class Paint {
public:
  Paint() { (void)_flags; }

  PaintType *type();
  const PaintType *type() const;
  void set_type(const PaintType &value);

  Color *color();
  const Color *color() const;
  void set_color(Color *value);

  float *opacity();
  const float *opacity() const;
  void set_opacity(const float &value);

  bool *visible();
  const bool *visible() const;
  void set_visible(const bool &value);

  BlendMode *blendMode();
  const BlendMode *blendMode() const;
  void set_blendMode(const BlendMode &value);

  kiwi::Array<ColorStop> *stops();
  const kiwi::Array<ColorStop> *stops() const;
  kiwi::Array<ColorStop> &set_stops(kiwi::MemoryPool &pool, uint32_t count);

  Matrix *transform();
  const Matrix *transform() const;
  void set_transform(Matrix *value);

  Image *image();
  const Image *image() const;
  void set_image(Image *value);

  Image *imageThumbnail();
  const Image *imageThumbnail() const;
  void set_imageThumbnail(Image *value);

  Image *animatedImage();
  const Image *animatedImage() const;
  void set_animatedImage(Image *value);

  uint32_t *animationFrame();
  const uint32_t *animationFrame() const;
  void set_animationFrame(const uint32_t &value);

  ImageScaleMode *imageScaleMode();
  const ImageScaleMode *imageScaleMode() const;
  void set_imageScaleMode(const ImageScaleMode &value);

  bool *imageShouldColorManage();
  const bool *imageShouldColorManage() const;
  void set_imageShouldColorManage(const bool &value);

  float *rotation();
  const float *rotation() const;
  void set_rotation(const float &value);

  float *scale();
  const float *scale() const;
  void set_scale(const float &value);

  FilterColorAdjust *filterColorAdjust();
  const FilterColorAdjust *filterColorAdjust() const;
  void set_filterColorAdjust(FilterColorAdjust *value);

  PaintFilterMessage *paintFilter();
  const PaintFilterMessage *paintFilter() const;
  void set_paintFilter(PaintFilterMessage *value);

  kiwi::Array<uint32_t> *emojiCodePoints();
  const kiwi::Array<uint32_t> *emojiCodePoints() const;
  kiwi::Array<uint32_t> &set_emojiCodePoints(kiwi::MemoryPool &pool, uint32_t count);

  Video *video();
  const Video *video() const;
  void set_video(Video *value);

  uint32_t *originalImageWidth();
  const uint32_t *originalImageWidth() const;
  void set_originalImageWidth(const uint32_t &value);

  uint32_t *originalImageHeight();
  const uint32_t *originalImageHeight() const;
  void set_originalImageHeight(const uint32_t &value);

  VariableData *colorVar();
  const VariableData *colorVar() const;
  void set_colorVar(VariableData *value);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  PaintType _data_type = {};
  Color *_data_color = {};
  BlendMode _data_blendMode = {};
  kiwi::Array<ColorStop> _data_stops = {};
  Matrix *_data_transform = {};
  Image *_data_image = {};
  Image *_data_imageThumbnail = {};
  Image *_data_animatedImage = {};
  ImageScaleMode _data_imageScaleMode = {};
  FilterColorAdjust *_data_filterColorAdjust = {};
  PaintFilterMessage *_data_paintFilter = {};
  kiwi::Array<uint32_t> _data_emojiCodePoints = {};
  Video *_data_video = {};
  VariableData *_data_colorVar = {};
  float _data_opacity = {};
  uint32_t _data_animationFrame = {};
  float _data_rotation = {};
  float _data_scale = {};
  uint32_t _data_originalImageWidth = {};
  uint32_t _data_originalImageHeight = {};
  bool _data_visible = {};
  bool _data_imageShouldColorManage = {};
};

class FontMetaData {
public:
  FontMetaData() { (void)_flags; }

  FontName *key();
  const FontName *key() const;
  void set_key(FontName *value);

  float *fontLineHeight();
  const float *fontLineHeight() const;
  void set_fontLineHeight(const float &value);

  kiwi::Array<uint8_t> *fontDigest();
  const kiwi::Array<uint8_t> *fontDigest() const;
  kiwi::Array<uint8_t> &set_fontDigest(kiwi::MemoryPool &pool, uint32_t count);

  FontStyle *fontStyle();
  const FontStyle *fontStyle() const;
  void set_fontStyle(const FontStyle &value);

  int32_t *fontWeight();
  const int32_t *fontWeight() const;
  void set_fontWeight(const int32_t &value);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  FontName *_data_key = {};
  kiwi::Array<uint8_t> _data_fontDigest = {};
  FontStyle _data_fontStyle = {};
  float _data_fontLineHeight = {};
  int32_t _data_fontWeight = {};
};

class FontVariation {
public:
  FontVariation() { (void)_flags; }

  uint32_t *axisTag();
  const uint32_t *axisTag() const;
  void set_axisTag(const uint32_t &value);

  kiwi::String *axisName();
  const kiwi::String *axisName() const;
  void set_axisName(const kiwi::String &value);

  float *value();
  const float *value() const;
  void set_value(const float &value);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  kiwi::String _data_axisName = {};
  uint32_t _data_axisTag = {};
  float _data_value = {};
};

class TextData {
public:
  TextData() { (void)_flags; }

  kiwi::String *characters();
  const kiwi::String *characters() const;
  void set_characters(const kiwi::String &value);

  kiwi::Array<uint32_t> *characterStyleIDs();
  const kiwi::Array<uint32_t> *characterStyleIDs() const;
  kiwi::Array<uint32_t> &set_characterStyleIDs(kiwi::MemoryPool &pool, uint32_t count);

  kiwi::Array<NodeChange> *styleOverrideTable();
  const kiwi::Array<NodeChange> *styleOverrideTable() const;
  kiwi::Array<NodeChange> &set_styleOverrideTable(kiwi::MemoryPool &pool, uint32_t count);

  Vector *layoutSize();
  const Vector *layoutSize() const;
  void set_layoutSize(Vector *value);

  kiwi::Array<Baseline> *baselines();
  const kiwi::Array<Baseline> *baselines() const;
  kiwi::Array<Baseline> &set_baselines(kiwi::MemoryPool &pool, uint32_t count);

  kiwi::Array<Glyph> *glyphs();
  const kiwi::Array<Glyph> *glyphs() const;
  kiwi::Array<Glyph> &set_glyphs(kiwi::MemoryPool &pool, uint32_t count);

  kiwi::Array<Decoration> *decorations();
  const kiwi::Array<Decoration> *decorations() const;
  kiwi::Array<Decoration> &set_decorations(kiwi::MemoryPool &pool, uint32_t count);

  kiwi::Array<Blockquote> *blockquotes();
  const kiwi::Array<Blockquote> *blockquotes() const;
  kiwi::Array<Blockquote> &set_blockquotes(kiwi::MemoryPool &pool, uint32_t count);

  uint32_t *layoutVersion();
  const uint32_t *layoutVersion() const;
  void set_layoutVersion(const uint32_t &value);

  kiwi::Array<FontMetaData> *fontMetaData();
  const kiwi::Array<FontMetaData> *fontMetaData() const;
  kiwi::Array<FontMetaData> &set_fontMetaData(kiwi::MemoryPool &pool, uint32_t count);

  kiwi::Array<FontName> *fallbackFonts();
  const kiwi::Array<FontName> *fallbackFonts() const;
  kiwi::Array<FontName> &set_fallbackFonts(kiwi::MemoryPool &pool, uint32_t count);

  kiwi::Array<HyperlinkBox> *hyperlinkBoxes();
  const kiwi::Array<HyperlinkBox> *hyperlinkBoxes() const;
  kiwi::Array<HyperlinkBox> &set_hyperlinkBoxes(kiwi::MemoryPool &pool, uint32_t count);

  kiwi::Array<TextLineData> *lines();
  const kiwi::Array<TextLineData> *lines() const;
  kiwi::Array<TextLineData> &set_lines(kiwi::MemoryPool &pool, uint32_t count);

  int32_t *truncationStartIndex();
  const int32_t *truncationStartIndex() const;
  void set_truncationStartIndex(const int32_t &value);

  float *truncatedHeight();
  const float *truncatedHeight() const;
  void set_truncatedHeight(const float &value);

  kiwi::Array<float> *logicalIndexToCharacterOffsetMap();
  const kiwi::Array<float> *logicalIndexToCharacterOffsetMap() const;
  kiwi::Array<float> &set_logicalIndexToCharacterOffsetMap(kiwi::MemoryPool &pool, uint32_t count);

  float *minContentHeight();
  const float *minContentHeight() const;
  void set_minContentHeight(const float &value);

  kiwi::Array<MentionBox> *mentionBoxes();
  const kiwi::Array<MentionBox> *mentionBoxes() const;
  kiwi::Array<MentionBox> &set_mentionBoxes(kiwi::MemoryPool &pool, uint32_t count);

  kiwi::Array<DerivedTextLineData> *derivedLines();
  const kiwi::Array<DerivedTextLineData> *derivedLines() const;
  kiwi::Array<DerivedTextLineData> &set_derivedLines(kiwi::MemoryPool &pool, uint32_t count);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  kiwi::String _data_characters = {};
  kiwi::Array<uint32_t> _data_characterStyleIDs = {};
  kiwi::Array<NodeChange> _data_styleOverrideTable = {};
  Vector *_data_layoutSize = {};
  kiwi::Array<Baseline> _data_baselines = {};
  kiwi::Array<Glyph> _data_glyphs = {};
  kiwi::Array<Decoration> _data_decorations = {};
  kiwi::Array<Blockquote> _data_blockquotes = {};
  kiwi::Array<FontMetaData> _data_fontMetaData = {};
  kiwi::Array<FontName> _data_fallbackFonts = {};
  kiwi::Array<HyperlinkBox> _data_hyperlinkBoxes = {};
  kiwi::Array<TextLineData> _data_lines = {};
  kiwi::Array<float> _data_logicalIndexToCharacterOffsetMap = {};
  kiwi::Array<MentionBox> _data_mentionBoxes = {};
  kiwi::Array<DerivedTextLineData> _data_derivedLines = {};
  uint32_t _data_layoutVersion = {};
  int32_t _data_truncationStartIndex = {};
  float _data_truncatedHeight = {};
  float _data_minContentHeight = {};
};

class DerivedTextData {
public:
  DerivedTextData() { (void)_flags; }

  Vector *layoutSize();
  const Vector *layoutSize() const;
  void set_layoutSize(Vector *value);

  kiwi::Array<Baseline> *baselines();
  const kiwi::Array<Baseline> *baselines() const;
  kiwi::Array<Baseline> &set_baselines(kiwi::MemoryPool &pool, uint32_t count);

  kiwi::Array<Glyph> *glyphs();
  const kiwi::Array<Glyph> *glyphs() const;
  kiwi::Array<Glyph> &set_glyphs(kiwi::MemoryPool &pool, uint32_t count);

  kiwi::Array<Decoration> *decorations();
  const kiwi::Array<Decoration> *decorations() const;
  kiwi::Array<Decoration> &set_decorations(kiwi::MemoryPool &pool, uint32_t count);

  kiwi::Array<Blockquote> *blockquotes();
  const kiwi::Array<Blockquote> *blockquotes() const;
  kiwi::Array<Blockquote> &set_blockquotes(kiwi::MemoryPool &pool, uint32_t count);

  kiwi::Array<FontMetaData> *fontMetaData();
  const kiwi::Array<FontMetaData> *fontMetaData() const;
  kiwi::Array<FontMetaData> &set_fontMetaData(kiwi::MemoryPool &pool, uint32_t count);

  kiwi::Array<HyperlinkBox> *hyperlinkBoxes();
  const kiwi::Array<HyperlinkBox> *hyperlinkBoxes() const;
  kiwi::Array<HyperlinkBox> &set_hyperlinkBoxes(kiwi::MemoryPool &pool, uint32_t count);

  int32_t *truncationStartIndex();
  const int32_t *truncationStartIndex() const;
  void set_truncationStartIndex(const int32_t &value);

  float *truncatedHeight();
  const float *truncatedHeight() const;
  void set_truncatedHeight(const float &value);

  kiwi::Array<float> *logicalIndexToCharacterOffsetMap();
  const kiwi::Array<float> *logicalIndexToCharacterOffsetMap() const;
  kiwi::Array<float> &set_logicalIndexToCharacterOffsetMap(kiwi::MemoryPool &pool, uint32_t count);

  kiwi::Array<MentionBox> *mentionBoxes();
  const kiwi::Array<MentionBox> *mentionBoxes() const;
  kiwi::Array<MentionBox> &set_mentionBoxes(kiwi::MemoryPool &pool, uint32_t count);

  kiwi::Array<DerivedTextLineData> *derivedLines();
  const kiwi::Array<DerivedTextLineData> *derivedLines() const;
  kiwi::Array<DerivedTextLineData> &set_derivedLines(kiwi::MemoryPool &pool, uint32_t count);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  Vector *_data_layoutSize = {};
  kiwi::Array<Baseline> _data_baselines = {};
  kiwi::Array<Glyph> _data_glyphs = {};
  kiwi::Array<Decoration> _data_decorations = {};
  kiwi::Array<Blockquote> _data_blockquotes = {};
  kiwi::Array<FontMetaData> _data_fontMetaData = {};
  kiwi::Array<HyperlinkBox> _data_hyperlinkBoxes = {};
  kiwi::Array<float> _data_logicalIndexToCharacterOffsetMap = {};
  kiwi::Array<MentionBox> _data_mentionBoxes = {};
  kiwi::Array<DerivedTextLineData> _data_derivedLines = {};
  int32_t _data_truncationStartIndex = {};
  float _data_truncatedHeight = {};
};

class HyperlinkBox {
public:
  HyperlinkBox() { (void)_flags; }

  Rect *bounds();
  const Rect *bounds() const;
  void set_bounds(Rect *value);

  kiwi::String *url();
  const kiwi::String *url() const;
  void set_url(const kiwi::String &value);

  GUID *guid();
  const GUID *guid() const;
  void set_guid(GUID *value);

  int32_t *hyperlinkID();
  const int32_t *hyperlinkID() const;
  void set_hyperlinkID(const int32_t &value);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  Rect *_data_bounds = {};
  kiwi::String _data_url = {};
  GUID *_data_guid = {};
  int32_t _data_hyperlinkID = {};
};

class MentionBox {
public:
  MentionBox() { (void)_flags; }

  Rect *bounds();
  const Rect *bounds() const;
  void set_bounds(Rect *value);

  uint32_t *startIndex();
  const uint32_t *startIndex() const;
  void set_startIndex(const uint32_t &value);

  uint32_t *endIndex();
  const uint32_t *endIndex() const;
  void set_endIndex(const uint32_t &value);

  bool *isValid();
  const bool *isValid() const;
  void set_isValid(const bool &value);

  uint32_t *mentionKey();
  const uint32_t *mentionKey() const;
  void set_mentionKey(const uint32_t &value);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  Rect *_data_bounds = {};
  uint32_t _data_startIndex = {};
  uint32_t _data_endIndex = {};
  uint32_t _data_mentionKey = {};
  bool _data_isValid = {};
};

class Baseline {
public:
  Baseline() { (void)_flags; }

  Vector *position();
  const Vector *position() const;
  void set_position(Vector *value);

  float *width();
  const float *width() const;
  void set_width(const float &value);

  float *lineY();
  const float *lineY() const;
  void set_lineY(const float &value);

  float *lineHeight();
  const float *lineHeight() const;
  void set_lineHeight(const float &value);

  float *lineAscent();
  const float *lineAscent() const;
  void set_lineAscent(const float &value);

  float *ignoreLeadingTrim();
  const float *ignoreLeadingTrim() const;
  void set_ignoreLeadingTrim(const float &value);

  uint32_t *firstCharacter();
  const uint32_t *firstCharacter() const;
  void set_firstCharacter(const uint32_t &value);

  uint32_t *endCharacter();
  const uint32_t *endCharacter() const;
  void set_endCharacter(const uint32_t &value);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  Vector *_data_position = {};
  float _data_width = {};
  float _data_lineY = {};
  float _data_lineHeight = {};
  float _data_lineAscent = {};
  float _data_ignoreLeadingTrim = {};
  uint32_t _data_firstCharacter = {};
  uint32_t _data_endCharacter = {};
};

class Glyph {
public:
  Glyph() { (void)_flags; }

  uint32_t *commandsBlob();
  const uint32_t *commandsBlob() const;
  void set_commandsBlob(const uint32_t &value);

  Vector *position();
  const Vector *position() const;
  void set_position(Vector *value);

  uint32_t *styleID();
  const uint32_t *styleID() const;
  void set_styleID(const uint32_t &value);

  float *fontSize();
  const float *fontSize() const;
  void set_fontSize(const float &value);

  uint32_t *firstCharacter();
  const uint32_t *firstCharacter() const;
  void set_firstCharacter(const uint32_t &value);

  float *advance();
  const float *advance() const;
  void set_advance(const float &value);

  kiwi::Array<uint32_t> *emojiCodePoints();
  const kiwi::Array<uint32_t> *emojiCodePoints() const;
  kiwi::Array<uint32_t> &set_emojiCodePoints(kiwi::MemoryPool &pool, uint32_t count);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  Vector *_data_position = {};
  kiwi::Array<uint32_t> _data_emojiCodePoints = {};
  uint32_t _data_commandsBlob = {};
  uint32_t _data_styleID = {};
  float _data_fontSize = {};
  uint32_t _data_firstCharacter = {};
  float _data_advance = {};
};

class Decoration {
public:
  Decoration() { (void)_flags; }

  kiwi::Array<Rect> *rects();
  const kiwi::Array<Rect> *rects() const;
  kiwi::Array<Rect> &set_rects(kiwi::MemoryPool &pool, uint32_t count);

  uint32_t *styleID();
  const uint32_t *styleID() const;
  void set_styleID(const uint32_t &value);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  kiwi::Array<Rect> _data_rects = {};
  uint32_t _data_styleID = {};
};

class Blockquote {
public:
  Blockquote() { (void)_flags; }

  Rect *verticalBar();
  const Rect *verticalBar() const;
  void set_verticalBar(Rect *value);

  Rect *quoteMarkBounds();
  const Rect *quoteMarkBounds() const;
  void set_quoteMarkBounds(Rect *value);

  uint32_t *styleID();
  const uint32_t *styleID() const;
  void set_styleID(const uint32_t &value);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  Rect *_data_verticalBar = {};
  Rect *_data_quoteMarkBounds = {};
  uint32_t _data_styleID = {};
};

class VectorData {
public:
  VectorData() { (void)_flags; }

  uint32_t *vectorNetworkBlob();
  const uint32_t *vectorNetworkBlob() const;
  void set_vectorNetworkBlob(const uint32_t &value);

  Vector *normalizedSize();
  const Vector *normalizedSize() const;
  void set_normalizedSize(Vector *value);

  kiwi::Array<NodeChange> *styleOverrideTable();
  const kiwi::Array<NodeChange> *styleOverrideTable() const;
  kiwi::Array<NodeChange> &set_styleOverrideTable(kiwi::MemoryPool &pool, uint32_t count);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  Vector *_data_normalizedSize = {};
  kiwi::Array<NodeChange> _data_styleOverrideTable = {};
  uint32_t _data_vectorNetworkBlob = {};
};

class GUIDPath {
public:
  GUIDPath() { (void)_flags; }

  kiwi::Array<GUID> *guids();
  const kiwi::Array<GUID> *guids() const;
  kiwi::Array<GUID> &set_guids(kiwi::MemoryPool &pool, uint32_t count);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  kiwi::Array<GUID> _data_guids = {};
};

class SymbolData {
public:
  SymbolData() { (void)_flags; }

  GUID *symbolID();
  const GUID *symbolID() const;
  void set_symbolID(GUID *value);

  kiwi::Array<NodeChange> *symbolOverrides();
  const kiwi::Array<NodeChange> *symbolOverrides() const;
  kiwi::Array<NodeChange> &set_symbolOverrides(kiwi::MemoryPool &pool, uint32_t count);

  float *uniformScaleFactor();
  const float *uniformScaleFactor() const;
  void set_uniformScaleFactor(const float &value);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  GUID *_data_symbolID = {};
  kiwi::Array<NodeChange> _data_symbolOverrides = {};
  float _data_uniformScaleFactor = {};
};

class GUIDPathMapping {
public:
  GUIDPathMapping() { (void)_flags; }

  GUID *id();
  const GUID *id() const;
  void set_id(GUID *value);

  GUIDPath *path();
  const GUIDPath *path() const;
  void set_path(GUIDPath *value);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  GUID *_data_id = {};
  GUIDPath *_data_path = {};
};

class NodeGenerationData {
public:
  NodeGenerationData() { (void)_flags; }

  kiwi::Array<NodeChange> *overrides();
  const kiwi::Array<NodeChange> *overrides() const;
  kiwi::Array<NodeChange> &set_overrides(kiwi::MemoryPool &pool, uint32_t count);

  bool *useFineGrainedSyncing();
  const bool *useFineGrainedSyncing() const;
  void set_useFineGrainedSyncing(const bool &value);

  kiwi::Array<NodeChange> *diffOnlyRemovals();
  const kiwi::Array<NodeChange> *diffOnlyRemovals() const;
  kiwi::Array<NodeChange> &set_diffOnlyRemovals(kiwi::MemoryPool &pool, uint32_t count);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  kiwi::Array<NodeChange> _data_overrides = {};
  kiwi::Array<NodeChange> _data_diffOnlyRemovals = {};
  bool _data_useFineGrainedSyncing = {};
};

class DerivedImmutableFrameData {
public:
  DerivedImmutableFrameData() { (void)_flags; }

  kiwi::Array<NodeChange> *overrides();
  const kiwi::Array<NodeChange> *overrides() const;
  kiwi::Array<NodeChange> &set_overrides(kiwi::MemoryPool &pool, uint32_t count);

  uint32_t *version();
  const uint32_t *version() const;
  void set_version(const uint32_t &value);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  kiwi::Array<NodeChange> _data_overrides = {};
  uint32_t _data_version = {};
};

class AssetRef {
public:
  AssetRef() { (void)_flags; }

  kiwi::String *key();
  const kiwi::String *key() const;
  void set_key(const kiwi::String &value);

  kiwi::String *version();
  const kiwi::String *version() const;
  void set_version(const kiwi::String &value);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  kiwi::String _data_key = {};
  kiwi::String _data_version = {};
};

class StateGroupId {
public:
  StateGroupId() { (void)_flags; }

  GUID *guid();
  const GUID *guid() const;
  void set_guid(GUID *value);

  AssetRef *assetRef();
  const AssetRef *assetRef() const;
  void set_assetRef(AssetRef *value);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  GUID *_data_guid = {};
  AssetRef *_data_assetRef = {};
};

class StyleId {
public:
  StyleId() { (void)_flags; }

  GUID *guid();
  const GUID *guid() const;
  void set_guid(GUID *value);

  AssetRef *assetRef();
  const AssetRef *assetRef() const;
  void set_assetRef(AssetRef *value);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  GUID *_data_guid = {};
  AssetRef *_data_assetRef = {};
};

class SymbolId {
public:
  SymbolId() { (void)_flags; }

  GUID *guid();
  const GUID *guid() const;
  void set_guid(GUID *value);

  AssetRef *assetRef();
  const AssetRef *assetRef() const;
  void set_assetRef(AssetRef *value);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  GUID *_data_guid = {};
  AssetRef *_data_assetRef = {};
};

class VariableID {
public:
  VariableID() { (void)_flags; }

  GUID *guid();
  const GUID *guid() const;
  void set_guid(GUID *value);

  AssetRef *assetRef();
  const AssetRef *assetRef() const;
  void set_assetRef(AssetRef *value);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  GUID *_data_guid = {};
  AssetRef *_data_assetRef = {};
};

class VariableSetID {
public:
  VariableSetID() { (void)_flags; }

  GUID *guid();
  const GUID *guid() const;
  void set_guid(GUID *value);

  AssetRef *assetRef();
  const AssetRef *assetRef() const;
  void set_assetRef(AssetRef *value);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  GUID *_data_guid = {};
  AssetRef *_data_assetRef = {};
};

class SharedSymbolReference {
public:
  SharedSymbolReference() { (void)_flags; }

  kiwi::String *fileKey();
  const kiwi::String *fileKey() const;
  void set_fileKey(const kiwi::String &value);

  GUID *symbolID();
  const GUID *symbolID() const;
  void set_symbolID(GUID *value);

  kiwi::String *versionHash();
  const kiwi::String *versionHash() const;
  void set_versionHash(const kiwi::String &value);

  kiwi::Array<GUIDPathMapping> *guidPathMappings();
  const kiwi::Array<GUIDPathMapping> *guidPathMappings() const;
  kiwi::Array<GUIDPathMapping> &set_guidPathMappings(kiwi::MemoryPool &pool, uint32_t count);

  kiwi::Array<uint8_t> *bytes();
  const kiwi::Array<uint8_t> *bytes() const;
  kiwi::Array<uint8_t> &set_bytes(kiwi::MemoryPool &pool, uint32_t count);

  kiwi::Array<GUIDMapping> *libraryGUIDToSubscribingGUID();
  const kiwi::Array<GUIDMapping> *libraryGUIDToSubscribingGUID() const;
  kiwi::Array<GUIDMapping> &set_libraryGUIDToSubscribingGUID(kiwi::MemoryPool &pool, uint32_t count);

  kiwi::String *componentKey();
  const kiwi::String *componentKey() const;
  void set_componentKey(const kiwi::String &value);

  kiwi::Array<GUIDPathMapping> *unflatteningMappings();
  const kiwi::Array<GUIDPathMapping> *unflatteningMappings() const;
  kiwi::Array<GUIDPathMapping> &set_unflatteningMappings(kiwi::MemoryPool &pool, uint32_t count);

  bool *isUnflattened();
  const bool *isUnflattened() const;
  void set_isUnflattened(const bool &value);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  kiwi::String _data_fileKey = {};
  GUID *_data_symbolID = {};
  kiwi::String _data_versionHash = {};
  kiwi::Array<GUIDPathMapping> _data_guidPathMappings = {};
  kiwi::Array<uint8_t> _data_bytes = {};
  kiwi::Array<GUIDMapping> _data_libraryGUIDToSubscribingGUID = {};
  kiwi::String _data_componentKey = {};
  kiwi::Array<GUIDPathMapping> _data_unflatteningMappings = {};
  bool _data_isUnflattened = {};
};

class SharedComponentMasterData {
public:
  SharedComponentMasterData() { (void)_flags; }

  kiwi::String *componentKey();
  const kiwi::String *componentKey() const;
  void set_componentKey(const kiwi::String &value);

  kiwi::Array<GUIDPathMapping> *publishingGUIDPathToTeamLibraryGUID();
  const kiwi::Array<GUIDPathMapping> *publishingGUIDPathToTeamLibraryGUID() const;
  kiwi::Array<GUIDPathMapping> &set_publishingGUIDPathToTeamLibraryGUID(kiwi::MemoryPool &pool, uint32_t count);

  bool *isUnflattened();
  const bool *isUnflattened() const;
  void set_isUnflattened(const bool &value);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  kiwi::String _data_componentKey = {};
  kiwi::Array<GUIDPathMapping> _data_publishingGUIDPathToTeamLibraryGUID = {};
  bool _data_isUnflattened = {};
};

class InstanceOverrideStash {
public:
  InstanceOverrideStash() { (void)_flags; }

  GUIDPath *overridePathOfSwappedInstance();
  const GUIDPath *overridePathOfSwappedInstance() const;
  void set_overridePathOfSwappedInstance(GUIDPath *value);

  kiwi::String *componentKey();
  const kiwi::String *componentKey() const;
  void set_componentKey(const kiwi::String &value);

  kiwi::Array<NodeChange> *overrides();
  const kiwi::Array<NodeChange> *overrides() const;
  kiwi::Array<NodeChange> &set_overrides(kiwi::MemoryPool &pool, uint32_t count);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  GUIDPath *_data_overridePathOfSwappedInstance = {};
  kiwi::String _data_componentKey = {};
  kiwi::Array<NodeChange> _data_overrides = {};
};

class InstanceOverrideStashV2 {
public:
  InstanceOverrideStashV2() { (void)_flags; }

  GUIDPath *overridePathOfSwappedInstance();
  const GUIDPath *overridePathOfSwappedInstance() const;
  void set_overridePathOfSwappedInstance(GUIDPath *value);

  GUID *localSymbolID();
  const GUID *localSymbolID() const;
  void set_localSymbolID(GUID *value);

  kiwi::Array<NodeChange> *overrides();
  const kiwi::Array<NodeChange> *overrides() const;
  kiwi::Array<NodeChange> &set_overrides(kiwi::MemoryPool &pool, uint32_t count);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  GUIDPath *_data_overridePathOfSwappedInstance = {};
  GUID *_data_localSymbolID = {};
  kiwi::Array<NodeChange> _data_overrides = {};
};

class Effect {
public:
  Effect() { (void)_flags; }

  EffectType *type();
  const EffectType *type() const;
  void set_type(const EffectType &value);

  Color *color();
  const Color *color() const;
  void set_color(Color *value);

  Vector *offset();
  const Vector *offset() const;
  void set_offset(Vector *value);

  float *radius();
  const float *radius() const;
  void set_radius(const float &value);

  bool *visible();
  const bool *visible() const;
  void set_visible(const bool &value);

  BlendMode *blendMode();
  const BlendMode *blendMode() const;
  void set_blendMode(const BlendMode &value);

  float *spread();
  const float *spread() const;
  void set_spread(const float &value);

  bool *showShadowBehindNode();
  const bool *showShadowBehindNode() const;
  void set_showShadowBehindNode(const bool &value);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  EffectType _data_type = {};
  Color *_data_color = {};
  Vector *_data_offset = {};
  BlendMode _data_blendMode = {};
  float _data_radius = {};
  float _data_spread = {};
  bool _data_visible = {};
  bool _data_showShadowBehindNode = {};
};

class TransitionInfo {
public:
  TransitionInfo() { (void)_flags; }

  TransitionType *type();
  const TransitionType *type() const;
  void set_type(const TransitionType &value);

  float *duration();
  const float *duration() const;
  void set_duration(const float &value);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  TransitionType _data_type = {};
  float _data_duration = {};
};

class PrototypeDevice {
public:
  PrototypeDevice() { (void)_flags; }

  PrototypeDeviceType *type();
  const PrototypeDeviceType *type() const;
  void set_type(const PrototypeDeviceType &value);

  Vector *size();
  const Vector *size() const;
  void set_size(Vector *value);

  kiwi::String *presetIdentifier();
  const kiwi::String *presetIdentifier() const;
  void set_presetIdentifier(const kiwi::String &value);

  DeviceRotation *rotation();
  const DeviceRotation *rotation() const;
  void set_rotation(const DeviceRotation &value);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  PrototypeDeviceType _data_type = {};
  Vector *_data_size = {};
  kiwi::String _data_presetIdentifier = {};
  DeviceRotation _data_rotation = {};
};

class OverlayBackgroundAppearance {
public:
  OverlayBackgroundAppearance() { (void)_flags; }

  OverlayBackgroundType *backgroundType();
  const OverlayBackgroundType *backgroundType() const;
  void set_backgroundType(const OverlayBackgroundType &value);

  Color *backgroundColor();
  const Color *backgroundColor() const;
  void set_backgroundColor(Color *value);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  OverlayBackgroundType _data_backgroundType = {};
  Color *_data_backgroundColor = {};
};

class ExportSettings {
public:
  ExportSettings() { (void)_flags; }

  kiwi::String *suffix();
  const kiwi::String *suffix() const;
  void set_suffix(const kiwi::String &value);

  ImageType *imageType();
  const ImageType *imageType() const;
  void set_imageType(const ImageType &value);

  ExportConstraint *constraint();
  const ExportConstraint *constraint() const;
  void set_constraint(ExportConstraint *value);

  bool *svgDataName();
  const bool *svgDataName() const;
  void set_svgDataName(const bool &value);

  ExportSVGIDMode *svgIDMode();
  const ExportSVGIDMode *svgIDMode() const;
  void set_svgIDMode(const ExportSVGIDMode &value);

  bool *svgOutlineText();
  const bool *svgOutlineText() const;
  void set_svgOutlineText(const bool &value);

  bool *contentsOnly();
  const bool *contentsOnly() const;
  void set_contentsOnly(const bool &value);

  bool *svgForceStrokeMasks();
  const bool *svgForceStrokeMasks() const;
  void set_svgForceStrokeMasks(const bool &value);

  bool *useAbsoluteBounds();
  const bool *useAbsoluteBounds() const;
  void set_useAbsoluteBounds(const bool &value);

  ExportColorProfile *colorProfile();
  const ExportColorProfile *colorProfile() const;
  void set_colorProfile(const ExportColorProfile &value);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  kiwi::String _data_suffix = {};
  ImageType _data_imageType = {};
  ExportConstraint *_data_constraint = {};
  ExportSVGIDMode _data_svgIDMode = {};
  ExportColorProfile _data_colorProfile = {};
  bool _data_svgDataName = {};
  bool _data_svgOutlineText = {};
  bool _data_contentsOnly = {};
  bool _data_svgForceStrokeMasks = {};
  bool _data_useAbsoluteBounds = {};
};

class LayoutGrid {
public:
  LayoutGrid() { (void)_flags; }

  LayoutGridType *type();
  const LayoutGridType *type() const;
  void set_type(const LayoutGridType &value);

  Axis *axis();
  const Axis *axis() const;
  void set_axis(const Axis &value);

  bool *visible();
  const bool *visible() const;
  void set_visible(const bool &value);

  int32_t *numSections();
  const int32_t *numSections() const;
  void set_numSections(const int32_t &value);

  float *offset();
  const float *offset() const;
  void set_offset(const float &value);

  float *sectionSize();
  const float *sectionSize() const;
  void set_sectionSize(const float &value);

  float *gutterSize();
  const float *gutterSize() const;
  void set_gutterSize(const float &value);

  Color *color();
  const Color *color() const;
  void set_color(Color *value);

  LayoutGridPattern *pattern();
  const LayoutGridPattern *pattern() const;
  void set_pattern(const LayoutGridPattern &value);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  LayoutGridType _data_type = {};
  Axis _data_axis = {};
  Color *_data_color = {};
  LayoutGridPattern _data_pattern = {};
  int32_t _data_numSections = {};
  float _data_offset = {};
  float _data_sectionSize = {};
  float _data_gutterSize = {};
  bool _data_visible = {};
};

class Guide {
public:
  Guide() { (void)_flags; }

  Axis *axis();
  const Axis *axis() const;
  void set_axis(const Axis &value);

  float *offset();
  const float *offset() const;
  void set_offset(const float &value);

  GUID *guid();
  const GUID *guid() const;
  void set_guid(GUID *value);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  Axis _data_axis = {};
  GUID *_data_guid = {};
  float _data_offset = {};
};

class Path {
public:
  Path() { (void)_flags; }

  WindingRule *windingRule();
  const WindingRule *windingRule() const;
  void set_windingRule(const WindingRule &value);

  uint32_t *commandsBlob();
  const uint32_t *commandsBlob() const;
  void set_commandsBlob(const uint32_t &value);

  uint32_t *styleID();
  const uint32_t *styleID() const;
  void set_styleID(const uint32_t &value);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  WindingRule _data_windingRule = {};
  uint32_t _data_commandsBlob = {};
  uint32_t _data_styleID = {};
};

class SharedStyleReference {
public:
  SharedStyleReference() { (void)_flags; }

  kiwi::String *styleKey();
  const kiwi::String *styleKey() const;
  void set_styleKey(const kiwi::String &value);

  kiwi::String *versionHash();
  const kiwi::String *versionHash() const;
  void set_versionHash(const kiwi::String &value);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  kiwi::String _data_styleKey = {};
  kiwi::String _data_versionHash = {};
};

class SharedStyleMasterData {
public:
  SharedStyleMasterData() { (void)_flags; }

  kiwi::String *styleKey();
  const kiwi::String *styleKey() const;
  void set_styleKey(const kiwi::String &value);

  kiwi::String *sortPosition();
  const kiwi::String *sortPosition() const;
  void set_sortPosition(const kiwi::String &value);

  kiwi::String *fileKey();
  const kiwi::String *fileKey() const;
  void set_fileKey(const kiwi::String &value);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  kiwi::String _data_styleKey = {};
  kiwi::String _data_sortPosition = {};
  kiwi::String _data_fileKey = {};
};

class ArcData {
public:
  ArcData() { (void)_flags; }

  float *startingAngle();
  const float *startingAngle() const;
  void set_startingAngle(const float &value);

  float *endingAngle();
  const float *endingAngle() const;
  void set_endingAngle(const float &value);

  float *innerRadius();
  const float *innerRadius() const;
  void set_innerRadius(const float &value);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  float _data_startingAngle = {};
  float _data_endingAngle = {};
  float _data_innerRadius = {};
};

class SymbolLink {
public:
  SymbolLink() { (void)_flags; }

  kiwi::String *uri();
  const kiwi::String *uri() const;
  void set_uri(const kiwi::String &value);

  kiwi::String *displayName();
  const kiwi::String *displayName() const;
  void set_displayName(const kiwi::String &value);

  kiwi::String *displayText();
  const kiwi::String *displayText() const;
  void set_displayText(const kiwi::String &value);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  kiwi::String _data_uri = {};
  kiwi::String _data_displayName = {};
  kiwi::String _data_displayText = {};
};

class PluginData {
public:
  PluginData() { (void)_flags; }

  kiwi::String *pluginID();
  const kiwi::String *pluginID() const;
  void set_pluginID(const kiwi::String &value);

  kiwi::String *value();
  const kiwi::String *value() const;
  void set_value(const kiwi::String &value);

  kiwi::String *key();
  const kiwi::String *key() const;
  void set_key(const kiwi::String &value);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  kiwi::String _data_pluginID = {};
  kiwi::String _data_value = {};
  kiwi::String _data_key = {};
};

class PluginRelaunchData {
public:
  PluginRelaunchData() { (void)_flags; }

  kiwi::String *pluginID();
  const kiwi::String *pluginID() const;
  void set_pluginID(const kiwi::String &value);

  kiwi::String *message();
  const kiwi::String *message() const;
  void set_message(const kiwi::String &value);

  kiwi::String *command();
  const kiwi::String *command() const;
  void set_command(const kiwi::String &value);

  bool *isDeleted();
  const bool *isDeleted() const;
  void set_isDeleted(const bool &value);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  kiwi::String _data_pluginID = {};
  kiwi::String _data_message = {};
  kiwi::String _data_command = {};
  bool _data_isDeleted = {};
};

class MultiplayerFieldVersion {
public:
  MultiplayerFieldVersion() { (void)_flags; }

  uint32_t *counter();
  const uint32_t *counter() const;
  void set_counter(const uint32_t &value);

  uint32_t *sessionID();
  const uint32_t *sessionID() const;
  void set_sessionID(const uint32_t &value);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  uint32_t _data_counter = {};
  uint32_t _data_sessionID = {};
};

class ConnectorEndpoint {
public:
  ConnectorEndpoint() { (void)_flags; }

  GUID *endpointNodeID();
  const GUID *endpointNodeID() const;
  void set_endpointNodeID(GUID *value);

  Vector *position();
  const Vector *position() const;
  void set_position(Vector *value);

  ConnectorMagnet *magnet();
  const ConnectorMagnet *magnet() const;
  void set_magnet(const ConnectorMagnet &value);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  GUID *_data_endpointNodeID = {};
  Vector *_data_position = {};
  ConnectorMagnet _data_magnet = {};
};

class ConnectorControlPoint {
public:
  ConnectorControlPoint() { (void)_flags; }

  Vector *position();
  const Vector *position() const;
  void set_position(Vector *value);

  Vector *axis();
  const Vector *axis() const;
  void set_axis(Vector *value);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  Vector *_data_position = {};
  Vector *_data_axis = {};
};

class ConnectorTextMidpoint {
public:
  ConnectorTextMidpoint() { (void)_flags; }

  ConnectorTextSection *section();
  const ConnectorTextSection *section() const;
  void set_section(const ConnectorTextSection &value);

  float *offset();
  const float *offset() const;
  void set_offset(const float &value);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  ConnectorTextSection _data_section = {};
  float _data_offset = {};
};

class LibraryMoveInfo {
public:
  LibraryMoveInfo() { (void)_flags; }

  kiwi::String *oldKey();
  const kiwi::String *oldKey() const;
  void set_oldKey(const kiwi::String &value);

  kiwi::String *pasteFileKey();
  const kiwi::String *pasteFileKey() const;
  void set_pasteFileKey(const kiwi::String &value);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  kiwi::String _data_oldKey = {};
  kiwi::String _data_pasteFileKey = {};
};

class LibraryMoveHistoryItem {
public:
  LibraryMoveHistoryItem() { (void)_flags; }

  GUID *sourceNodeId();
  const GUID *sourceNodeId() const;
  void set_sourceNodeId(GUID *value);

  kiwi::String *sourceComponentKey();
  const kiwi::String *sourceComponentKey() const;
  void set_sourceComponentKey(const kiwi::String &value);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  GUID *_data_sourceNodeId = {};
  kiwi::String _data_sourceComponentKey = {};
};

class DeveloperRelatedLink {
public:
  DeveloperRelatedLink() { (void)_flags; }

  kiwi::String *nodeId();
  const kiwi::String *nodeId() const;
  void set_nodeId(const kiwi::String &value);

  kiwi::String *fileKey();
  const kiwi::String *fileKey() const;
  void set_fileKey(const kiwi::String &value);

  kiwi::String *linkName();
  const kiwi::String *linkName() const;
  void set_linkName(const kiwi::String &value);

  kiwi::String *linkUrl();
  const kiwi::String *linkUrl() const;
  void set_linkUrl(const kiwi::String &value);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  kiwi::String _data_nodeId = {};
  kiwi::String _data_fileKey = {};
  kiwi::String _data_linkName = {};
  kiwi::String _data_linkUrl = {};
};

class WidgetPointer {
public:
  WidgetPointer() { (void)_flags; }

  GUID *nodeId();
  const GUID *nodeId() const;
  void set_nodeId(GUID *value);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  GUID *_data_nodeId = {};
};

class EditInfo {
public:
  EditInfo() { (void)_flags; }

  kiwi::String *timestampIso8601();
  const kiwi::String *timestampIso8601() const;
  void set_timestampIso8601(const kiwi::String &value);

  kiwi::String *userId();
  const kiwi::String *userId() const;
  void set_userId(const kiwi::String &value);

  uint32_t *lastEditedAt();
  const uint32_t *lastEditedAt() const;
  void set_lastEditedAt(const uint32_t &value);

  uint32_t *createdAt();
  const uint32_t *createdAt() const;
  void set_createdAt(const uint32_t &value);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  kiwi::String _data_timestampIso8601 = {};
  kiwi::String _data_userId = {};
  uint32_t _data_lastEditedAt = {};
  uint32_t _data_createdAt = {};
};

class SectionStatusInfo {
public:
  SectionStatusInfo() { (void)_flags; }

  SectionStatus *status();
  const SectionStatus *status() const;
  void set_status(const SectionStatus &value);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  SectionStatus _data_status = {};
};

class NodeChange {
public:
  NodeChange() { (void)_flags; }

  GUID *guid();
  const GUID *guid() const;
  void set_guid(GUID *value);

  uint32_t *guidTag();
  const uint32_t *guidTag() const;
  void set_guidTag(const uint32_t &value);

  NodePhase *phase();
  const NodePhase *phase() const;
  void set_phase(const NodePhase &value);

  uint32_t *phaseTag();
  const uint32_t *phaseTag() const;
  void set_phaseTag(const uint32_t &value);

  ParentIndex *parentIndex();
  const ParentIndex *parentIndex() const;
  void set_parentIndex(ParentIndex *value);

  uint32_t *parentIndexTag();
  const uint32_t *parentIndexTag() const;
  void set_parentIndexTag(const uint32_t &value);

  NodeType *type();
  const NodeType *type() const;
  void set_type(const NodeType &value);

  uint32_t *typeTag();
  const uint32_t *typeTag() const;
  void set_typeTag(const uint32_t &value);

  kiwi::String *name();
  const kiwi::String *name() const;
  void set_name(const kiwi::String &value);

  uint32_t *nameTag();
  const uint32_t *nameTag() const;
  void set_nameTag(const uint32_t &value);

  bool *isPublishable();
  const bool *isPublishable() const;
  void set_isPublishable(const bool &value);

  kiwi::String *description();
  const kiwi::String *description() const;
  void set_description(const kiwi::String &value);

  LibraryMoveInfo *libraryMoveInfo();
  const LibraryMoveInfo *libraryMoveInfo() const;
  void set_libraryMoveInfo(LibraryMoveInfo *value);

  kiwi::Array<LibraryMoveHistoryItem> *libraryMoveHistory();
  const kiwi::Array<LibraryMoveHistoryItem> *libraryMoveHistory() const;
  kiwi::Array<LibraryMoveHistoryItem> &set_libraryMoveHistory(kiwi::MemoryPool &pool, uint32_t count);

  kiwi::String *key();
  const kiwi::String *key() const;
  void set_key(const kiwi::String &value);

  uint32_t *styleID();
  const uint32_t *styleID() const;
  void set_styleID(const uint32_t &value);

  uint32_t *styleIDTag();
  const uint32_t *styleIDTag() const;
  void set_styleIDTag(const uint32_t &value);

  bool *isSoftDeletedStyle();
  const bool *isSoftDeletedStyle() const;
  void set_isSoftDeletedStyle(const bool &value);

  bool *isNonUpdateable();
  const bool *isNonUpdateable() const;
  void set_isNonUpdateable(const bool &value);

  bool *isFillStyle();
  const bool *isFillStyle() const;
  void set_isFillStyle(const bool &value);

  bool *isStrokeStyle();
  const bool *isStrokeStyle() const;
  void set_isStrokeStyle(const bool &value);

  StyleType *styleType();
  const StyleType *styleType() const;
  void set_styleType(const StyleType &value);

  kiwi::String *styleDescription();
  const kiwi::String *styleDescription() const;
  void set_styleDescription(const kiwi::String &value);

  kiwi::String *version();
  const kiwi::String *version() const;
  void set_version(const kiwi::String &value);

  SharedStyleMasterData *sharedStyleMasterData();
  const SharedStyleMasterData *sharedStyleMasterData() const;
  void set_sharedStyleMasterData(SharedStyleMasterData *value);

  SharedStyleReference *sharedStyleReference();
  const SharedStyleReference *sharedStyleReference() const;
  void set_sharedStyleReference(SharedStyleReference *value);

  kiwi::String *sortPosition();
  const kiwi::String *sortPosition() const;
  void set_sortPosition(const kiwi::String &value);

  SharedStyleMasterData *ojansSuperSecretNodeField();
  const SharedStyleMasterData *ojansSuperSecretNodeField() const;
  void set_ojansSuperSecretNodeField(SharedStyleMasterData *value);

  SharedStyleMasterData *sevMoonlitLilyData();
  const SharedStyleMasterData *sevMoonlitLilyData() const;
  void set_sevMoonlitLilyData(SharedStyleMasterData *value);

  GUID *inheritFillStyleID();
  const GUID *inheritFillStyleID() const;
  void set_inheritFillStyleID(GUID *value);

  GUID *inheritStrokeStyleID();
  const GUID *inheritStrokeStyleID() const;
  void set_inheritStrokeStyleID(GUID *value);

  GUID *inheritTextStyleID();
  const GUID *inheritTextStyleID() const;
  void set_inheritTextStyleID(GUID *value);

  GUID *inheritExportStyleID();
  const GUID *inheritExportStyleID() const;
  void set_inheritExportStyleID(GUID *value);

  GUID *inheritEffectStyleID();
  const GUID *inheritEffectStyleID() const;
  void set_inheritEffectStyleID(GUID *value);

  GUID *inheritGridStyleID();
  const GUID *inheritGridStyleID() const;
  void set_inheritGridStyleID(GUID *value);

  GUID *inheritFillStyleIDForStroke();
  const GUID *inheritFillStyleIDForStroke() const;
  void set_inheritFillStyleIDForStroke(GUID *value);

  StyleId *styleIdForFill();
  const StyleId *styleIdForFill() const;
  void set_styleIdForFill(StyleId *value);

  StyleId *styleIdForStrokeFill();
  const StyleId *styleIdForStrokeFill() const;
  void set_styleIdForStrokeFill(StyleId *value);

  StyleId *styleIdForText();
  const StyleId *styleIdForText() const;
  void set_styleIdForText(StyleId *value);

  StyleId *styleIdForEffect();
  const StyleId *styleIdForEffect() const;
  void set_styleIdForEffect(StyleId *value);

  StyleId *styleIdForGrid();
  const StyleId *styleIdForGrid() const;
  void set_styleIdForGrid(StyleId *value);

  kiwi::Array<Paint> *backgroundPaints();
  const kiwi::Array<Paint> *backgroundPaints() const;
  kiwi::Array<Paint> &set_backgroundPaints(kiwi::MemoryPool &pool, uint32_t count);

  GUID *inheritFillStyleIDForBackground();
  const GUID *inheritFillStyleIDForBackground() const;
  void set_inheritFillStyleIDForBackground(GUID *value);

  bool *isStateGroup();
  const bool *isStateGroup() const;
  void set_isStateGroup(const bool &value);

  kiwi::Array<StateGroupPropertyValueOrder> *stateGroupPropertyValueOrders();
  const kiwi::Array<StateGroupPropertyValueOrder> *stateGroupPropertyValueOrders() const;
  kiwi::Array<StateGroupPropertyValueOrder> &set_stateGroupPropertyValueOrders(kiwi::MemoryPool &pool, uint32_t count);

  SharedSymbolReference *sharedSymbolReference();
  const SharedSymbolReference *sharedSymbolReference() const;
  void set_sharedSymbolReference(SharedSymbolReference *value);

  bool *isSymbolPublishable();
  const bool *isSymbolPublishable() const;
  void set_isSymbolPublishable(const bool &value);

  kiwi::Array<GUIDPathMapping> *sharedSymbolMappings();
  const kiwi::Array<GUIDPathMapping> *sharedSymbolMappings() const;
  kiwi::Array<GUIDPathMapping> &set_sharedSymbolMappings(kiwi::MemoryPool &pool, uint32_t count);

  kiwi::String *sharedSymbolVersion();
  const kiwi::String *sharedSymbolVersion() const;
  void set_sharedSymbolVersion(const kiwi::String &value);

  SharedComponentMasterData *sharedComponentMasterData();
  const SharedComponentMasterData *sharedComponentMasterData() const;
  void set_sharedComponentMasterData(SharedComponentMasterData *value);

  kiwi::String *symbolDescription();
  const kiwi::String *symbolDescription() const;
  void set_symbolDescription(const kiwi::String &value);

  kiwi::Array<GUIDPathMapping> *unflatteningMappings();
  const kiwi::Array<GUIDPathMapping> *unflatteningMappings() const;
  kiwi::Array<GUIDPathMapping> &set_unflatteningMappings(kiwi::MemoryPool &pool, uint32_t count);

  kiwi::Array<GUIDPathMapping> *forceUnflatteningMappings();
  const kiwi::Array<GUIDPathMapping> *forceUnflatteningMappings() const;
  kiwi::Array<GUIDPathMapping> &set_forceUnflatteningMappings(kiwi::MemoryPool &pool, uint32_t count);

  kiwi::String *publishFile();
  const kiwi::String *publishFile() const;
  void set_publishFile(const kiwi::String &value);

  GUID *publishID();
  const GUID *publishID() const;
  void set_publishID(GUID *value);

  kiwi::String *componentKey();
  const kiwi::String *componentKey() const;
  void set_componentKey(const kiwi::String &value);

  bool *isC2();
  const bool *isC2() const;
  void set_isC2(const bool &value);

  kiwi::String *publishedVersion();
  const kiwi::String *publishedVersion() const;
  void set_publishedVersion(const kiwi::String &value);

  kiwi::String *originComponentKey();
  const kiwi::String *originComponentKey() const;
  void set_originComponentKey(const kiwi::String &value);

  kiwi::Array<ComponentPropDef> *componentPropDefs();
  const kiwi::Array<ComponentPropDef> *componentPropDefs() const;
  kiwi::Array<ComponentPropDef> &set_componentPropDefs(kiwi::MemoryPool &pool, uint32_t count);

  kiwi::Array<ComponentPropRef> *componentPropRefs();
  const kiwi::Array<ComponentPropRef> *componentPropRefs() const;
  kiwi::Array<ComponentPropRef> &set_componentPropRefs(kiwi::MemoryPool &pool, uint32_t count);

  SymbolData *symbolData();
  const SymbolData *symbolData() const;
  void set_symbolData(SymbolData *value);

  uint32_t *symbolDataTag();
  const uint32_t *symbolDataTag() const;
  void set_symbolDataTag(const uint32_t &value);

  kiwi::Array<NodeChange> *derivedSymbolData();
  const kiwi::Array<NodeChange> *derivedSymbolData() const;
  kiwi::Array<NodeChange> &set_derivedSymbolData(kiwi::MemoryPool &pool, uint32_t count);

  GUID *overriddenSymbolID();
  const GUID *overriddenSymbolID() const;
  void set_overriddenSymbolID(GUID *value);

  kiwi::Array<ComponentPropAssignment> *componentPropAssignments();
  const kiwi::Array<ComponentPropAssignment> *componentPropAssignments() const;
  kiwi::Array<ComponentPropAssignment> &set_componentPropAssignments(kiwi::MemoryPool &pool, uint32_t count);

  bool *propsAreBubbled();
  const bool *propsAreBubbled() const;
  void set_propsAreBubbled(const bool &value);

  kiwi::Array<InstanceOverrideStash> *overrideStash();
  const kiwi::Array<InstanceOverrideStash> *overrideStash() const;
  kiwi::Array<InstanceOverrideStash> &set_overrideStash(kiwi::MemoryPool &pool, uint32_t count);

  kiwi::Array<InstanceOverrideStashV2> *overrideStashV2();
  const kiwi::Array<InstanceOverrideStashV2> *overrideStashV2() const;
  kiwi::Array<InstanceOverrideStashV2> &set_overrideStashV2(kiwi::MemoryPool &pool, uint32_t count);

  GUIDPath *guidPath();
  const GUIDPath *guidPath() const;
  void set_guidPath(GUIDPath *value);

  uint32_t *guidPathTag();
  const uint32_t *guidPathTag() const;
  void set_guidPathTag(const uint32_t &value);

  int32_t *overrideLevel();
  const int32_t *overrideLevel() const;
  void set_overrideLevel(const int32_t &value);

  float *fontSize();
  const float *fontSize() const;
  void set_fontSize(const float &value);

  uint32_t *fontSizeTag();
  const uint32_t *fontSizeTag() const;
  void set_fontSizeTag(const uint32_t &value);

  float *paragraphIndent();
  const float *paragraphIndent() const;
  void set_paragraphIndent(const float &value);

  uint32_t *paragraphIndentTag();
  const uint32_t *paragraphIndentTag() const;
  void set_paragraphIndentTag(const uint32_t &value);

  float *paragraphSpacing();
  const float *paragraphSpacing() const;
  void set_paragraphSpacing(const float &value);

  uint32_t *paragraphSpacingTag();
  const uint32_t *paragraphSpacingTag() const;
  void set_paragraphSpacingTag(const uint32_t &value);

  TextAlignHorizontal *textAlignHorizontal();
  const TextAlignHorizontal *textAlignHorizontal() const;
  void set_textAlignHorizontal(const TextAlignHorizontal &value);

  uint32_t *textAlignHorizontalTag();
  const uint32_t *textAlignHorizontalTag() const;
  void set_textAlignHorizontalTag(const uint32_t &value);

  TextAlignVertical *textAlignVertical();
  const TextAlignVertical *textAlignVertical() const;
  void set_textAlignVertical(const TextAlignVertical &value);

  uint32_t *textAlignVerticalTag();
  const uint32_t *textAlignVerticalTag() const;
  void set_textAlignVerticalTag(const uint32_t &value);

  TextCase *textCase();
  const TextCase *textCase() const;
  void set_textCase(const TextCase &value);

  uint32_t *textCaseTag();
  const uint32_t *textCaseTag() const;
  void set_textCaseTag(const uint32_t &value);

  TextDecoration *textDecoration();
  const TextDecoration *textDecoration() const;
  void set_textDecoration(const TextDecoration &value);

  uint32_t *textDecorationTag();
  const uint32_t *textDecorationTag() const;
  void set_textDecorationTag(const uint32_t &value);

  Number *lineHeight();
  const Number *lineHeight() const;
  void set_lineHeight(Number *value);

  uint32_t *lineHeightTag();
  const uint32_t *lineHeightTag() const;
  void set_lineHeightTag(const uint32_t &value);

  FontName *fontName();
  const FontName *fontName() const;
  void set_fontName(FontName *value);

  uint32_t *fontNameTag();
  const uint32_t *fontNameTag() const;
  void set_fontNameTag(const uint32_t &value);

  TextData *textData();
  const TextData *textData() const;
  void set_textData(TextData *value);

  uint32_t *textDataTag();
  const uint32_t *textDataTag() const;
  void set_textDataTag(const uint32_t &value);

  DerivedTextData *derivedTextData();
  const DerivedTextData *derivedTextData() const;
  void set_derivedTextData(DerivedTextData *value);

  bool *fontVariantCommonLigatures();
  const bool *fontVariantCommonLigatures() const;
  void set_fontVariantCommonLigatures(const bool &value);

  bool *fontVariantContextualLigatures();
  const bool *fontVariantContextualLigatures() const;
  void set_fontVariantContextualLigatures(const bool &value);

  bool *fontVariantDiscretionaryLigatures();
  const bool *fontVariantDiscretionaryLigatures() const;
  void set_fontVariantDiscretionaryLigatures(const bool &value);

  bool *fontVariantHistoricalLigatures();
  const bool *fontVariantHistoricalLigatures() const;
  void set_fontVariantHistoricalLigatures(const bool &value);

  bool *fontVariantOrdinal();
  const bool *fontVariantOrdinal() const;
  void set_fontVariantOrdinal(const bool &value);

  bool *fontVariantSlashedZero();
  const bool *fontVariantSlashedZero() const;
  void set_fontVariantSlashedZero(const bool &value);

  FontVariantNumericFigure *fontVariantNumericFigure();
  const FontVariantNumericFigure *fontVariantNumericFigure() const;
  void set_fontVariantNumericFigure(const FontVariantNumericFigure &value);

  FontVariantNumericSpacing *fontVariantNumericSpacing();
  const FontVariantNumericSpacing *fontVariantNumericSpacing() const;
  void set_fontVariantNumericSpacing(const FontVariantNumericSpacing &value);

  FontVariantNumericFraction *fontVariantNumericFraction();
  const FontVariantNumericFraction *fontVariantNumericFraction() const;
  void set_fontVariantNumericFraction(const FontVariantNumericFraction &value);

  FontVariantCaps *fontVariantCaps();
  const FontVariantCaps *fontVariantCaps() const;
  void set_fontVariantCaps(const FontVariantCaps &value);

  FontVariantPosition *fontVariantPosition();
  const FontVariantPosition *fontVariantPosition() const;
  void set_fontVariantPosition(const FontVariantPosition &value);

  Number *letterSpacing();
  const Number *letterSpacing() const;
  void set_letterSpacing(Number *value);

  kiwi::String *fontVersion();
  const kiwi::String *fontVersion() const;
  void set_fontVersion(const kiwi::String &value);

  LeadingTrim *leadingTrim();
  const LeadingTrim *leadingTrim() const;
  void set_leadingTrim(const LeadingTrim &value);

  bool *hangingPunctuation();
  const bool *hangingPunctuation() const;
  void set_hangingPunctuation(const bool &value);

  bool *hangingList();
  const bool *hangingList() const;
  void set_hangingList(const bool &value);

  int32_t *maxLines();
  const int32_t *maxLines() const;
  void set_maxLines(const int32_t &value);

  SectionStatus *sectionStatus();
  const SectionStatus *sectionStatus() const;
  void set_sectionStatus(const SectionStatus &value);

  SectionStatusInfo *sectionStatusInfo();
  const SectionStatusInfo *sectionStatusInfo() const;
  void set_sectionStatusInfo(SectionStatusInfo *value);

  uint32_t *textUserLayoutVersion();
  const uint32_t *textUserLayoutVersion() const;
  void set_textUserLayoutVersion(const uint32_t &value);

  kiwi::Array<OpenTypeFeature> *toggledOnOTFeatures();
  const kiwi::Array<OpenTypeFeature> *toggledOnOTFeatures() const;
  kiwi::Array<OpenTypeFeature> &set_toggledOnOTFeatures(kiwi::MemoryPool &pool, uint32_t count);

  kiwi::Array<OpenTypeFeature> *toggledOffOTFeatures();
  const kiwi::Array<OpenTypeFeature> *toggledOffOTFeatures() const;
  kiwi::Array<OpenTypeFeature> &set_toggledOffOTFeatures(kiwi::MemoryPool &pool, uint32_t count);

  Hyperlink *hyperlink();
  const Hyperlink *hyperlink() const;
  void set_hyperlink(Hyperlink *value);

  Mention *mention();
  const Mention *mention() const;
  void set_mention(Mention *value);

  kiwi::Array<FontVariation> *fontVariations();
  const kiwi::Array<FontVariation> *fontVariations() const;
  kiwi::Array<FontVariation> &set_fontVariations(kiwi::MemoryPool &pool, uint32_t count);

  uint32_t *textBidiVersion();
  const uint32_t *textBidiVersion() const;
  void set_textBidiVersion(const uint32_t &value);

  TextTruncation *textTruncation();
  const TextTruncation *textTruncation() const;
  void set_textTruncation(const TextTruncation &value);

  bool *hasHadRTLText();
  const bool *hasHadRTLText() const;
  void set_hasHadRTLText(const bool &value);

  bool *visible();
  const bool *visible() const;
  void set_visible(const bool &value);

  uint32_t *visibleTag();
  const uint32_t *visibleTag() const;
  void set_visibleTag(const uint32_t &value);

  bool *locked();
  const bool *locked() const;
  void set_locked(const bool &value);

  uint32_t *lockedTag();
  const uint32_t *lockedTag() const;
  void set_lockedTag(const uint32_t &value);

  float *opacity();
  const float *opacity() const;
  void set_opacity(const float &value);

  uint32_t *opacityTag();
  const uint32_t *opacityTag() const;
  void set_opacityTag(const uint32_t &value);

  BlendMode *blendMode();
  const BlendMode *blendMode() const;
  void set_blendMode(const BlendMode &value);

  uint32_t *blendModeTag();
  const uint32_t *blendModeTag() const;
  void set_blendModeTag(const uint32_t &value);

  Vector *size();
  const Vector *size() const;
  void set_size(Vector *value);

  uint32_t *sizeTag();
  const uint32_t *sizeTag() const;
  void set_sizeTag(const uint32_t &value);

  Matrix *transform();
  const Matrix *transform() const;
  void set_transform(Matrix *value);

  uint32_t *transformTag();
  const uint32_t *transformTag() const;
  void set_transformTag(const uint32_t &value);

  kiwi::Array<float> *dashPattern();
  const kiwi::Array<float> *dashPattern() const;
  kiwi::Array<float> &set_dashPattern(kiwi::MemoryPool &pool, uint32_t count);

  uint32_t *dashPatternTag();
  const uint32_t *dashPatternTag() const;
  void set_dashPatternTag(const uint32_t &value);

  bool *mask();
  const bool *mask() const;
  void set_mask(const bool &value);

  uint32_t *maskTag();
  const uint32_t *maskTag() const;
  void set_maskTag(const uint32_t &value);

  bool *maskIsOutline();
  const bool *maskIsOutline() const;
  void set_maskIsOutline(const bool &value);

  uint32_t *maskIsOutlineTag();
  const uint32_t *maskIsOutlineTag() const;
  void set_maskIsOutlineTag(const uint32_t &value);

  MaskType *maskType();
  const MaskType *maskType() const;
  void set_maskType(const MaskType &value);

  float *backgroundOpacity();
  const float *backgroundOpacity() const;
  void set_backgroundOpacity(const float &value);

  uint32_t *backgroundOpacityTag();
  const uint32_t *backgroundOpacityTag() const;
  void set_backgroundOpacityTag(const uint32_t &value);

  float *cornerRadius();
  const float *cornerRadius() const;
  void set_cornerRadius(const float &value);

  uint32_t *cornerRadiusTag();
  const uint32_t *cornerRadiusTag() const;
  void set_cornerRadiusTag(const uint32_t &value);

  float *strokeWeight();
  const float *strokeWeight() const;
  void set_strokeWeight(const float &value);

  uint32_t *strokeWeightTag();
  const uint32_t *strokeWeightTag() const;
  void set_strokeWeightTag(const uint32_t &value);

  StrokeAlign *strokeAlign();
  const StrokeAlign *strokeAlign() const;
  void set_strokeAlign(const StrokeAlign &value);

  uint32_t *strokeAlignTag();
  const uint32_t *strokeAlignTag() const;
  void set_strokeAlignTag(const uint32_t &value);

  StrokeCap *strokeCap();
  const StrokeCap *strokeCap() const;
  void set_strokeCap(const StrokeCap &value);

  uint32_t *strokeCapTag();
  const uint32_t *strokeCapTag() const;
  void set_strokeCapTag(const uint32_t &value);

  StrokeJoin *strokeJoin();
  const StrokeJoin *strokeJoin() const;
  void set_strokeJoin(const StrokeJoin &value);

  uint32_t *strokeJoinTag();
  const uint32_t *strokeJoinTag() const;
  void set_strokeJoinTag(const uint32_t &value);

  kiwi::Array<Paint> *fillPaints();
  const kiwi::Array<Paint> *fillPaints() const;
  kiwi::Array<Paint> &set_fillPaints(kiwi::MemoryPool &pool, uint32_t count);

  uint32_t *fillPaintsTag();
  const uint32_t *fillPaintsTag() const;
  void set_fillPaintsTag(const uint32_t &value);

  kiwi::Array<Paint> *strokePaints();
  const kiwi::Array<Paint> *strokePaints() const;
  kiwi::Array<Paint> &set_strokePaints(kiwi::MemoryPool &pool, uint32_t count);

  uint32_t *strokePaintsTag();
  const uint32_t *strokePaintsTag() const;
  void set_strokePaintsTag(const uint32_t &value);

  kiwi::Array<Effect> *effects();
  const kiwi::Array<Effect> *effects() const;
  kiwi::Array<Effect> &set_effects(kiwi::MemoryPool &pool, uint32_t count);

  uint32_t *effectsTag();
  const uint32_t *effectsTag() const;
  void set_effectsTag(const uint32_t &value);

  Color *backgroundColor();
  const Color *backgroundColor() const;
  void set_backgroundColor(Color *value);

  uint32_t *backgroundColorTag();
  const uint32_t *backgroundColorTag() const;
  void set_backgroundColorTag(const uint32_t &value);

  kiwi::Array<Path> *fillGeometry();
  const kiwi::Array<Path> *fillGeometry() const;
  kiwi::Array<Path> &set_fillGeometry(kiwi::MemoryPool &pool, uint32_t count);

  uint32_t *fillGeometryTag();
  const uint32_t *fillGeometryTag() const;
  void set_fillGeometryTag(const uint32_t &value);

  kiwi::Array<Path> *strokeGeometry();
  const kiwi::Array<Path> *strokeGeometry() const;
  kiwi::Array<Path> &set_strokeGeometry(kiwi::MemoryPool &pool, uint32_t count);

  uint32_t *strokeGeometryTag();
  const uint32_t *strokeGeometryTag() const;
  void set_strokeGeometryTag(const uint32_t &value);

  float *rectangleTopLeftCornerRadius();
  const float *rectangleTopLeftCornerRadius() const;
  void set_rectangleTopLeftCornerRadius(const float &value);

  float *rectangleTopRightCornerRadius();
  const float *rectangleTopRightCornerRadius() const;
  void set_rectangleTopRightCornerRadius(const float &value);

  float *rectangleBottomLeftCornerRadius();
  const float *rectangleBottomLeftCornerRadius() const;
  void set_rectangleBottomLeftCornerRadius(const float &value);

  float *rectangleBottomRightCornerRadius();
  const float *rectangleBottomRightCornerRadius() const;
  void set_rectangleBottomRightCornerRadius(const float &value);

  bool *rectangleCornerRadiiIndependent();
  const bool *rectangleCornerRadiiIndependent() const;
  void set_rectangleCornerRadiiIndependent(const bool &value);

  bool *rectangleCornerToolIndependent();
  const bool *rectangleCornerToolIndependent() const;
  void set_rectangleCornerToolIndependent(const bool &value);

  bool *proportionsConstrained();
  const bool *proportionsConstrained() const;
  void set_proportionsConstrained(const bool &value);

  bool *useAbsoluteBounds();
  const bool *useAbsoluteBounds() const;
  void set_useAbsoluteBounds(const bool &value);

  bool *borderTopHidden();
  const bool *borderTopHidden() const;
  void set_borderTopHidden(const bool &value);

  bool *borderBottomHidden();
  const bool *borderBottomHidden() const;
  void set_borderBottomHidden(const bool &value);

  bool *borderLeftHidden();
  const bool *borderLeftHidden() const;
  void set_borderLeftHidden(const bool &value);

  bool *borderRightHidden();
  const bool *borderRightHidden() const;
  void set_borderRightHidden(const bool &value);

  bool *bordersTakeSpace();
  const bool *bordersTakeSpace() const;
  void set_bordersTakeSpace(const bool &value);

  float *borderTopWeight();
  const float *borderTopWeight() const;
  void set_borderTopWeight(const float &value);

  float *borderBottomWeight();
  const float *borderBottomWeight() const;
  void set_borderBottomWeight(const float &value);

  float *borderLeftWeight();
  const float *borderLeftWeight() const;
  void set_borderLeftWeight(const float &value);

  float *borderRightWeight();
  const float *borderRightWeight() const;
  void set_borderRightWeight(const float &value);

  bool *borderStrokeWeightsIndependent();
  const bool *borderStrokeWeightsIndependent() const;
  void set_borderStrokeWeightsIndependent(const bool &value);

  ConstraintType *horizontalConstraint();
  const ConstraintType *horizontalConstraint() const;
  void set_horizontalConstraint(const ConstraintType &value);

  uint32_t *horizontalConstraintTag();
  const uint32_t *horizontalConstraintTag() const;
  void set_horizontalConstraintTag(const uint32_t &value);

  StackMode *stackMode();
  const StackMode *stackMode() const;
  void set_stackMode(const StackMode &value);

  uint32_t *stackModeTag();
  const uint32_t *stackModeTag() const;
  void set_stackModeTag(const uint32_t &value);

  float *stackSpacing();
  const float *stackSpacing() const;
  void set_stackSpacing(const float &value);

  uint32_t *stackSpacingTag();
  const uint32_t *stackSpacingTag() const;
  void set_stackSpacingTag(const uint32_t &value);

  float *stackPadding();
  const float *stackPadding() const;
  void set_stackPadding(const float &value);

  uint32_t *stackPaddingTag();
  const uint32_t *stackPaddingTag() const;
  void set_stackPaddingTag(const uint32_t &value);

  StackCounterAlign *stackCounterAlign();
  const StackCounterAlign *stackCounterAlign() const;
  void set_stackCounterAlign(const StackCounterAlign &value);

  StackJustify *stackJustify();
  const StackJustify *stackJustify() const;
  void set_stackJustify(const StackJustify &value);

  StackAlign *stackAlign();
  const StackAlign *stackAlign() const;
  void set_stackAlign(const StackAlign &value);

  float *stackHorizontalPadding();
  const float *stackHorizontalPadding() const;
  void set_stackHorizontalPadding(const float &value);

  float *stackVerticalPadding();
  const float *stackVerticalPadding() const;
  void set_stackVerticalPadding(const float &value);

  StackSize *stackWidth();
  const StackSize *stackWidth() const;
  void set_stackWidth(const StackSize &value);

  StackSize *stackHeight();
  const StackSize *stackHeight() const;
  void set_stackHeight(const StackSize &value);

  StackSize *stackPrimarySizing();
  const StackSize *stackPrimarySizing() const;
  void set_stackPrimarySizing(const StackSize &value);

  StackJustify *stackPrimaryAlignItems();
  const StackJustify *stackPrimaryAlignItems() const;
  void set_stackPrimaryAlignItems(const StackJustify &value);

  StackAlign *stackCounterAlignItems();
  const StackAlign *stackCounterAlignItems() const;
  void set_stackCounterAlignItems(const StackAlign &value);

  float *stackChildPrimaryGrow();
  const float *stackChildPrimaryGrow() const;
  void set_stackChildPrimaryGrow(const float &value);

  float *stackPaddingRight();
  const float *stackPaddingRight() const;
  void set_stackPaddingRight(const float &value);

  float *stackPaddingBottom();
  const float *stackPaddingBottom() const;
  void set_stackPaddingBottom(const float &value);

  StackCounterAlign *stackChildAlignSelf();
  const StackCounterAlign *stackChildAlignSelf() const;
  void set_stackChildAlignSelf(const StackCounterAlign &value);

  StackPositioning *stackPositioning();
  const StackPositioning *stackPositioning() const;
  void set_stackPositioning(const StackPositioning &value);

  bool *stackReverseZIndex();
  const bool *stackReverseZIndex() const;
  void set_stackReverseZIndex(const bool &value);

  StackWrap *stackWrap();
  const StackWrap *stackWrap() const;
  void set_stackWrap(const StackWrap &value);

  float *stackCounterSpacing();
  const float *stackCounterSpacing() const;
  void set_stackCounterSpacing(const float &value);

  OptionalVector *minSize();
  const OptionalVector *minSize() const;
  void set_minSize(OptionalVector *value);

  OptionalVector *maxSize();
  const OptionalVector *maxSize() const;
  void set_maxSize(OptionalVector *value);

  StackCounterAlignContent *stackCounterAlignContent();
  const StackCounterAlignContent *stackCounterAlignContent() const;
  void set_stackCounterAlignContent(const StackCounterAlignContent &value);

  bool *isSnakeGameBoard();
  const bool *isSnakeGameBoard() const;
  void set_isSnakeGameBoard(const bool &value);

  GUID *transitionNodeID();
  const GUID *transitionNodeID() const;
  void set_transitionNodeID(GUID *value);

  GUID *prototypeStartNodeID();
  const GUID *prototypeStartNodeID() const;
  void set_prototypeStartNodeID(GUID *value);

  Color *prototypeBackgroundColor();
  const Color *prototypeBackgroundColor() const;
  void set_prototypeBackgroundColor(Color *value);

  TransitionInfo *transitionInfo();
  const TransitionInfo *transitionInfo() const;
  void set_transitionInfo(TransitionInfo *value);

  TransitionType *transitionType();
  const TransitionType *transitionType() const;
  void set_transitionType(const TransitionType &value);

  float *transitionDuration();
  const float *transitionDuration() const;
  void set_transitionDuration(const float &value);

  EasingType *easingType();
  const EasingType *easingType() const;
  void set_easingType(const EasingType &value);

  bool *transitionPreserveScroll();
  const bool *transitionPreserveScroll() const;
  void set_transitionPreserveScroll(const bool &value);

  ConnectionType *connectionType();
  const ConnectionType *connectionType() const;
  void set_connectionType(const ConnectionType &value);

  kiwi::String *connectionURL();
  const kiwi::String *connectionURL() const;
  void set_connectionURL(const kiwi::String &value);

  PrototypeDevice *prototypeDevice();
  const PrototypeDevice *prototypeDevice() const;
  void set_prototypeDevice(PrototypeDevice *value);

  InteractionType *interactionType();
  const InteractionType *interactionType() const;
  void set_interactionType(const InteractionType &value);

  float *transitionTimeout();
  const float *transitionTimeout() const;
  void set_transitionTimeout(const float &value);

  bool *interactionMaintained();
  const bool *interactionMaintained() const;
  void set_interactionMaintained(const bool &value);

  float *interactionDuration();
  const float *interactionDuration() const;
  void set_interactionDuration(const float &value);

  bool *destinationIsOverlay();
  const bool *destinationIsOverlay() const;
  void set_destinationIsOverlay(const bool &value);

  bool *transitionShouldSmartAnimate();
  const bool *transitionShouldSmartAnimate() const;
  void set_transitionShouldSmartAnimate(const bool &value);

  kiwi::Array<PrototypeInteraction> *prototypeInteractions();
  const kiwi::Array<PrototypeInteraction> *prototypeInteractions() const;
  kiwi::Array<PrototypeInteraction> &set_prototypeInteractions(kiwi::MemoryPool &pool, uint32_t count);

  PrototypeStartingPoint *prototypeStartingPoint();
  const PrototypeStartingPoint *prototypeStartingPoint() const;
  void set_prototypeStartingPoint(PrototypeStartingPoint *value);

  kiwi::Array<PluginData> *pluginData();
  const kiwi::Array<PluginData> *pluginData() const;
  kiwi::Array<PluginData> &set_pluginData(kiwi::MemoryPool &pool, uint32_t count);

  kiwi::Array<PluginRelaunchData> *pluginRelaunchData();
  const kiwi::Array<PluginRelaunchData> *pluginRelaunchData() const;
  kiwi::Array<PluginRelaunchData> &set_pluginRelaunchData(kiwi::MemoryPool &pool, uint32_t count);

  ConnectorEndpoint *connectorStart();
  const ConnectorEndpoint *connectorStart() const;
  void set_connectorStart(ConnectorEndpoint *value);

  ConnectorEndpoint *connectorEnd();
  const ConnectorEndpoint *connectorEnd() const;
  void set_connectorEnd(ConnectorEndpoint *value);

  ConnectorLineStyle *connectorLineStyle();
  const ConnectorLineStyle *connectorLineStyle() const;
  void set_connectorLineStyle(const ConnectorLineStyle &value);

  StrokeCap *connectorStartCap();
  const StrokeCap *connectorStartCap() const;
  void set_connectorStartCap(const StrokeCap &value);

  StrokeCap *connectorEndCap();
  const StrokeCap *connectorEndCap() const;
  void set_connectorEndCap(const StrokeCap &value);

  kiwi::Array<ConnectorControlPoint> *connectorControlPoints();
  const kiwi::Array<ConnectorControlPoint> *connectorControlPoints() const;
  kiwi::Array<ConnectorControlPoint> &set_connectorControlPoints(kiwi::MemoryPool &pool, uint32_t count);

  ConnectorTextMidpoint *connectorTextMidpoint();
  const ConnectorTextMidpoint *connectorTextMidpoint() const;
  void set_connectorTextMidpoint(ConnectorTextMidpoint *value);

  ShapeWithTextType *shapeWithTextType();
  const ShapeWithTextType *shapeWithTextType() const;
  void set_shapeWithTextType(const ShapeWithTextType &value);

  float *shapeUserHeight();
  const float *shapeUserHeight() const;
  void set_shapeUserHeight(const float &value);

  DerivedImmutableFrameData *derivedImmutableFrameData();
  const DerivedImmutableFrameData *derivedImmutableFrameData() const;
  void set_derivedImmutableFrameData(DerivedImmutableFrameData *value);

  MultiplayerFieldVersion *derivedImmutableFrameDataVersion();
  const MultiplayerFieldVersion *derivedImmutableFrameDataVersion() const;
  void set_derivedImmutableFrameDataVersion(MultiplayerFieldVersion *value);

  NodeGenerationData *nodeGenerationData();
  const NodeGenerationData *nodeGenerationData() const;
  void set_nodeGenerationData(NodeGenerationData *value);

  CodeBlockLanguage *codeBlockLanguage();
  const CodeBlockLanguage *codeBlockLanguage() const;
  void set_codeBlockLanguage(const CodeBlockLanguage &value);

  LinkPreviewData *linkPreviewData();
  const LinkPreviewData *linkPreviewData() const;
  void set_linkPreviewData(LinkPreviewData *value);

  bool *shapeTruncates();
  const bool *shapeTruncates() const;
  void set_shapeTruncates(const bool &value);

  bool *sectionContentsHidden();
  const bool *sectionContentsHidden() const;
  void set_sectionContentsHidden(const bool &value);

  VideoPlayback *videoPlayback();
  const VideoPlayback *videoPlayback() const;
  void set_videoPlayback(VideoPlayback *value);

  StampData *stampData();
  const StampData *stampData() const;
  void set_stampData(StampData *value);

  MultiplayerMap *widgetSyncedState();
  const MultiplayerMap *widgetSyncedState() const;
  void set_widgetSyncedState(MultiplayerMap *value);

  uint32_t *widgetSyncCursor();
  const uint32_t *widgetSyncCursor() const;
  void set_widgetSyncCursor(const uint32_t &value);

  WidgetDerivedSubtreeCursor *widgetDerivedSubtreeCursor();
  const WidgetDerivedSubtreeCursor *widgetDerivedSubtreeCursor() const;
  void set_widgetDerivedSubtreeCursor(WidgetDerivedSubtreeCursor *value);

  WidgetPointer *widgetCachedAncestor();
  const WidgetPointer *widgetCachedAncestor() const;
  void set_widgetCachedAncestor(WidgetPointer *value);

  WidgetInputBehavior *widgetInputBehavior();
  const WidgetInputBehavior *widgetInputBehavior() const;
  void set_widgetInputBehavior(const WidgetInputBehavior &value);

  kiwi::String *widgetTooltip();
  const kiwi::String *widgetTooltip() const;
  void set_widgetTooltip(const kiwi::String &value);

  WidgetHoverStyle *widgetHoverStyle();
  const WidgetHoverStyle *widgetHoverStyle() const;
  void set_widgetHoverStyle(WidgetHoverStyle *value);

  bool *isWidgetStickable();
  const bool *isWidgetStickable() const;
  void set_isWidgetStickable(const bool &value);

  bool *shouldHideCursorsOnWidgetHover();
  const bool *shouldHideCursorsOnWidgetHover() const;
  void set_shouldHideCursorsOnWidgetHover(const bool &value);

  WidgetMetadata *widgetMetadata();
  const WidgetMetadata *widgetMetadata() const;
  void set_widgetMetadata(WidgetMetadata *value);

  kiwi::Array<WidgetEvent> *widgetEvents();
  const kiwi::Array<WidgetEvent> *widgetEvents() const;
  kiwi::Array<WidgetEvent> &set_widgetEvents(kiwi::MemoryPool &pool, uint32_t count);

  kiwi::Array<WidgetPropertyMenuItem> *widgetPropertyMenuItems();
  const kiwi::Array<WidgetPropertyMenuItem> *widgetPropertyMenuItems() const;
  kiwi::Array<WidgetPropertyMenuItem> &set_widgetPropertyMenuItems(kiwi::MemoryPool &pool, uint32_t count);

  TableRowColumnPositionMap *tableRowPositions();
  const TableRowColumnPositionMap *tableRowPositions() const;
  void set_tableRowPositions(TableRowColumnPositionMap *value);

  TableRowColumnPositionMap *tableColumnPositions();
  const TableRowColumnPositionMap *tableColumnPositions() const;
  void set_tableColumnPositions(TableRowColumnPositionMap *value);

  TableRowColumnSizeMap *tableRowHeights();
  const TableRowColumnSizeMap *tableRowHeights() const;
  void set_tableRowHeights(TableRowColumnSizeMap *value);

  TableRowColumnSizeMap *tableColumnWidths();
  const TableRowColumnSizeMap *tableColumnWidths() const;
  void set_tableColumnWidths(TableRowColumnSizeMap *value);

  InternalEnumForTest *internalEnumForTest();
  const InternalEnumForTest *internalEnumForTest() const;
  void set_internalEnumForTest(const InternalEnumForTest &value);

  InternalDataForTest *internalDataForTest();
  const InternalDataForTest *internalDataForTest() const;
  void set_internalDataForTest(InternalDataForTest *value);

  uint32_t *count();
  const uint32_t *count() const;
  void set_count(const uint32_t &value);

  uint32_t *countTag();
  const uint32_t *countTag() const;
  void set_countTag(const uint32_t &value);

  bool *autoRename();
  const bool *autoRename() const;
  void set_autoRename(const bool &value);

  uint32_t *autoRenameTag();
  const uint32_t *autoRenameTag() const;
  void set_autoRenameTag(const uint32_t &value);

  bool *backgroundEnabled();
  const bool *backgroundEnabled() const;
  void set_backgroundEnabled(const bool &value);

  uint32_t *backgroundEnabledTag();
  const uint32_t *backgroundEnabledTag() const;
  void set_backgroundEnabledTag(const uint32_t &value);

  bool *exportContentsOnly();
  const bool *exportContentsOnly() const;
  void set_exportContentsOnly(const bool &value);

  uint32_t *exportContentsOnlyTag();
  const uint32_t *exportContentsOnlyTag() const;
  void set_exportContentsOnlyTag(const uint32_t &value);

  float *starInnerScale();
  const float *starInnerScale() const;
  void set_starInnerScale(const float &value);

  uint32_t *starInnerScaleTag();
  const uint32_t *starInnerScaleTag() const;
  void set_starInnerScaleTag(const uint32_t &value);

  float *miterLimit();
  const float *miterLimit() const;
  void set_miterLimit(const float &value);

  uint32_t *miterLimitTag();
  const uint32_t *miterLimitTag() const;
  void set_miterLimitTag(const uint32_t &value);

  float *textTracking();
  const float *textTracking() const;
  void set_textTracking(const float &value);

  uint32_t *textTrackingTag();
  const uint32_t *textTrackingTag() const;
  void set_textTrackingTag(const uint32_t &value);

  BooleanOperation *booleanOperation();
  const BooleanOperation *booleanOperation() const;
  void set_booleanOperation(const BooleanOperation &value);

  uint32_t *booleanOperationTag();
  const uint32_t *booleanOperationTag() const;
  void set_booleanOperationTag(const uint32_t &value);

  ConstraintType *verticalConstraint();
  const ConstraintType *verticalConstraint() const;
  void set_verticalConstraint(const ConstraintType &value);

  uint32_t *verticalConstraintTag();
  const uint32_t *verticalConstraintTag() const;
  void set_verticalConstraintTag(const uint32_t &value);

  VectorMirror *handleMirroring();
  const VectorMirror *handleMirroring() const;
  void set_handleMirroring(const VectorMirror &value);

  uint32_t *handleMirroringTag();
  const uint32_t *handleMirroringTag() const;
  void set_handleMirroringTag(const uint32_t &value);

  kiwi::Array<ExportSettings> *exportSettings();
  const kiwi::Array<ExportSettings> *exportSettings() const;
  kiwi::Array<ExportSettings> &set_exportSettings(kiwi::MemoryPool &pool, uint32_t count);

  uint32_t *exportSettingsTag();
  const uint32_t *exportSettingsTag() const;
  void set_exportSettingsTag(const uint32_t &value);

  TextAutoResize *textAutoResize();
  const TextAutoResize *textAutoResize() const;
  void set_textAutoResize(const TextAutoResize &value);

  uint32_t *textAutoResizeTag();
  const uint32_t *textAutoResizeTag() const;
  void set_textAutoResizeTag(const uint32_t &value);

  kiwi::Array<LayoutGrid> *layoutGrids();
  const kiwi::Array<LayoutGrid> *layoutGrids() const;
  kiwi::Array<LayoutGrid> &set_layoutGrids(kiwi::MemoryPool &pool, uint32_t count);

  uint32_t *layoutGridsTag();
  const uint32_t *layoutGridsTag() const;
  void set_layoutGridsTag(const uint32_t &value);

  VectorData *vectorData();
  const VectorData *vectorData() const;
  void set_vectorData(VectorData *value);

  uint32_t *vectorDataTag();
  const uint32_t *vectorDataTag() const;
  void set_vectorDataTag(const uint32_t &value);

  bool *frameMaskDisabled();
  const bool *frameMaskDisabled() const;
  void set_frameMaskDisabled(const bool &value);

  uint32_t *frameMaskDisabledTag();
  const uint32_t *frameMaskDisabledTag() const;
  void set_frameMaskDisabledTag(const uint32_t &value);

  bool *resizeToFit();
  const bool *resizeToFit() const;
  void set_resizeToFit(const bool &value);

  uint32_t *resizeToFitTag();
  const uint32_t *resizeToFitTag() const;
  void set_resizeToFitTag(const uint32_t &value);

  bool *exportBackgroundDisabled();
  const bool *exportBackgroundDisabled() const;
  void set_exportBackgroundDisabled(const bool &value);

  kiwi::Array<Guide> *guides();
  const kiwi::Array<Guide> *guides() const;
  kiwi::Array<Guide> &set_guides(kiwi::MemoryPool &pool, uint32_t count);

  bool *internalOnly();
  const bool *internalOnly() const;
  void set_internalOnly(const bool &value);

  ScrollDirection *scrollDirection();
  const ScrollDirection *scrollDirection() const;
  void set_scrollDirection(const ScrollDirection &value);

  float *cornerSmoothing();
  const float *cornerSmoothing() const;
  void set_cornerSmoothing(const float &value);

  Vector *scrollOffset();
  const Vector *scrollOffset() const;
  void set_scrollOffset(Vector *value);

  bool *exportTextAsSVGText();
  const bool *exportTextAsSVGText() const;
  void set_exportTextAsSVGText(const bool &value);

  ScrollContractedState *scrollContractedState();
  const ScrollContractedState *scrollContractedState() const;
  void set_scrollContractedState(const ScrollContractedState &value);

  Vector *contractedSize();
  const Vector *contractedSize() const;
  void set_contractedSize(Vector *value);

  kiwi::String *fixedChildrenDivider();
  const kiwi::String *fixedChildrenDivider() const;
  void set_fixedChildrenDivider(const kiwi::String &value);

  ScrollBehavior *scrollBehavior();
  const ScrollBehavior *scrollBehavior() const;
  void set_scrollBehavior(const ScrollBehavior &value);

  ArcData *arcData();
  const ArcData *arcData() const;
  void set_arcData(ArcData *value);

  int32_t *derivedSymbolDataLayoutVersion();
  const int32_t *derivedSymbolDataLayoutVersion() const;
  void set_derivedSymbolDataLayoutVersion(const int32_t &value);

  NavigationType *navigationType();
  const NavigationType *navigationType() const;
  void set_navigationType(const NavigationType &value);

  OverlayPositionType *overlayPositionType();
  const OverlayPositionType *overlayPositionType() const;
  void set_overlayPositionType(const OverlayPositionType &value);

  Vector *overlayRelativePosition();
  const Vector *overlayRelativePosition() const;
  void set_overlayRelativePosition(Vector *value);

  OverlayBackgroundInteraction *overlayBackgroundInteraction();
  const OverlayBackgroundInteraction *overlayBackgroundInteraction() const;
  void set_overlayBackgroundInteraction(const OverlayBackgroundInteraction &value);

  OverlayBackgroundAppearance *overlayBackgroundAppearance();
  const OverlayBackgroundAppearance *overlayBackgroundAppearance() const;
  void set_overlayBackgroundAppearance(OverlayBackgroundAppearance *value);

  GUID *overrideKey();
  const GUID *overrideKey() const;
  void set_overrideKey(GUID *value);

  bool *containerSupportsFillStrokeAndCorners();
  const bool *containerSupportsFillStrokeAndCorners() const;
  void set_containerSupportsFillStrokeAndCorners(const bool &value);

  StackSize *stackCounterSizing();
  const StackSize *stackCounterSizing() const;
  void set_stackCounterSizing(const StackSize &value);

  bool *containersSupportFillStrokeAndCorners();
  const bool *containersSupportFillStrokeAndCorners() const;
  void set_containersSupportFillStrokeAndCorners(const bool &value);

  KeyTrigger *keyTrigger();
  const KeyTrigger *keyTrigger() const;
  void set_keyTrigger(KeyTrigger *value);

  kiwi::String *voiceEventPhrase();
  const kiwi::String *voiceEventPhrase() const;
  void set_voiceEventPhrase(const kiwi::String &value);

  kiwi::Array<GUID> *ancestorPathBeforeDeletion();
  const kiwi::Array<GUID> *ancestorPathBeforeDeletion() const;
  kiwi::Array<GUID> &set_ancestorPathBeforeDeletion(kiwi::MemoryPool &pool, uint32_t count);

  kiwi::Array<SymbolLink> *symbolLinks();
  const kiwi::Array<SymbolLink> *symbolLinks() const;
  kiwi::Array<SymbolLink> &set_symbolLinks(kiwi::MemoryPool &pool, uint32_t count);

  TextListData *textListData();
  const TextListData *textListData() const;
  void set_textListData(TextListData *value);

  bool *detachOpticalSizeFromFontSize();
  const bool *detachOpticalSizeFromFontSize() const;
  void set_detachOpticalSizeFromFontSize(const bool &value);

  float *listSpacing();
  const float *listSpacing() const;
  void set_listSpacing(const float &value);

  EmbedData *embedData();
  const EmbedData *embedData() const;
  void set_embedData(EmbedData *value);

  RichMediaData *richMediaData();
  const RichMediaData *richMediaData() const;
  void set_richMediaData(RichMediaData *value);

  MultiplayerMap *renderedSyncedState();
  const MultiplayerMap *renderedSyncedState() const;
  void set_renderedSyncedState(MultiplayerMap *value);

  bool *simplifyInstancePanels();
  const bool *simplifyInstancePanels() const;
  void set_simplifyInstancePanels(const bool &value);

  HTMLTag *accessibleHTMLTag();
  const HTMLTag *accessibleHTMLTag() const;
  void set_accessibleHTMLTag(const HTMLTag &value);

  ARIARole *ariaRole();
  const ARIARole *ariaRole() const;
  void set_ariaRole(const ARIARole &value);

  kiwi::String *accessibleLabel();
  const kiwi::String *accessibleLabel() const;
  void set_accessibleLabel(const kiwi::String &value);

  VariableData *variableData();
  const VariableData *variableData() const;
  void set_variableData(VariableData *value);

  VariableDataMap *variableConsumptionMap();
  const VariableDataMap *variableConsumptionMap() const;
  void set_variableConsumptionMap(VariableDataMap *value);

  VariableModeBySetMap *variableModeBySetMap();
  const VariableModeBySetMap *variableModeBySetMap() const;
  void set_variableModeBySetMap(VariableModeBySetMap *value);

  kiwi::Array<VariableSetMode> *variableSetModes();
  const kiwi::Array<VariableSetMode> *variableSetModes() const;
  kiwi::Array<VariableSetMode> &set_variableSetModes(kiwi::MemoryPool &pool, uint32_t count);

  VariableSetID *variableSetID();
  const VariableSetID *variableSetID() const;
  void set_variableSetID(VariableSetID *value);

  VariableResolvedDataType *variableResolvedType();
  const VariableResolvedDataType *variableResolvedType() const;
  void set_variableResolvedType(const VariableResolvedDataType &value);

  VariableDataValues *variableDataValues();
  const VariableDataValues *variableDataValues() const;
  void set_variableDataValues(VariableDataValues *value);

  kiwi::String *variableTokenName();
  const kiwi::String *variableTokenName() const;
  void set_variableTokenName(const kiwi::String &value);

  kiwi::Array<VariableScope> *variableScopes();
  const kiwi::Array<VariableScope> *variableScopes() const;
  kiwi::Array<VariableScope> &set_variableScopes(kiwi::MemoryPool &pool, uint32_t count);

  CodeSyntaxMap *codeSyntax();
  const CodeSyntaxMap *codeSyntax() const;
  void set_codeSyntax(CodeSyntaxMap *value);

  HandoffStatusMap *handoffStatusMap();
  const HandoffStatusMap *handoffStatusMap() const;
  void set_handoffStatusMap(HandoffStatusMap *value);

  AgendaPositionMap *agendaPositionMap();
  const AgendaPositionMap *agendaPositionMap() const;
  void set_agendaPositionMap(AgendaPositionMap *value);

  AgendaMetadataMap *agendaMetadataMap();
  const AgendaMetadataMap *agendaMetadataMap() const;
  void set_agendaMetadataMap(AgendaMetadataMap *value);

  MigrationStatus *migrationStatus();
  const MigrationStatus *migrationStatus() const;
  void set_migrationStatus(MigrationStatus *value);

  bool *isSoftDeleted();
  const bool *isSoftDeleted() const;
  void set_isSoftDeleted(const bool &value);

  EditInfo *editInfo();
  const EditInfo *editInfo() const;
  void set_editInfo(EditInfo *value);

  ColorProfile *colorProfile();
  const ColorProfile *colorProfile() const;
  void set_colorProfile(const ColorProfile &value);

  SymbolId *detachedSymbolId();
  const SymbolId *detachedSymbolId() const;
  void set_detachedSymbolId(SymbolId *value);

  ChildReadingDirection *childReadingDirection();
  const ChildReadingDirection *childReadingDirection() const;
  void set_childReadingDirection(const ChildReadingDirection &value);

  kiwi::String *readingIndex();
  const kiwi::String *readingIndex() const;
  void set_readingIndex(const kiwi::String &value);

  DocumentColorProfile *documentColorProfile();
  const DocumentColorProfile *documentColorProfile() const;
  void set_documentColorProfile(const DocumentColorProfile &value);

  kiwi::Array<DeveloperRelatedLink> *developerRelatedLinks();
  const kiwi::Array<DeveloperRelatedLink> *developerRelatedLinks() const;
  kiwi::Array<DeveloperRelatedLink> &set_developerRelatedLinks(kiwi::MemoryPool &pool, uint32_t count);

  kiwi::String *slideActiveThemeLibKey();
  const kiwi::String *slideActiveThemeLibKey() const;
  void set_slideActiveThemeLibKey(const kiwi::String &value);

  ARIAAttributesMap *ariaAttributes();
  const ARIAAttributesMap *ariaAttributes() const;
  void set_ariaAttributes(ARIAAttributesMap *value);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[12] = {};
  GUID *_data_guid = {};
  NodePhase _data_phase = {};
  ParentIndex *_data_parentIndex = {};
  NodeType _data_type = {};
  kiwi::String _data_name = {};
  kiwi::String _data_description = {};
  LibraryMoveInfo *_data_libraryMoveInfo = {};
  kiwi::Array<LibraryMoveHistoryItem> _data_libraryMoveHistory = {};
  kiwi::String _data_key = {};
  StyleType _data_styleType = {};
  kiwi::String _data_styleDescription = {};
  kiwi::String _data_version = {};
  SharedStyleMasterData *_data_sharedStyleMasterData = {};
  SharedStyleReference *_data_sharedStyleReference = {};
  kiwi::String _data_sortPosition = {};
  SharedStyleMasterData *_data_ojansSuperSecretNodeField = {};
  SharedStyleMasterData *_data_sevMoonlitLilyData = {};
  GUID *_data_inheritFillStyleID = {};
  GUID *_data_inheritStrokeStyleID = {};
  GUID *_data_inheritTextStyleID = {};
  GUID *_data_inheritExportStyleID = {};
  GUID *_data_inheritEffectStyleID = {};
  GUID *_data_inheritGridStyleID = {};
  GUID *_data_inheritFillStyleIDForStroke = {};
  StyleId *_data_styleIdForFill = {};
  StyleId *_data_styleIdForStrokeFill = {};
  StyleId *_data_styleIdForText = {};
  StyleId *_data_styleIdForEffect = {};
  StyleId *_data_styleIdForGrid = {};
  kiwi::Array<Paint> _data_backgroundPaints = {};
  GUID *_data_inheritFillStyleIDForBackground = {};
  kiwi::Array<StateGroupPropertyValueOrder> _data_stateGroupPropertyValueOrders = {};
  SharedSymbolReference *_data_sharedSymbolReference = {};
  kiwi::Array<GUIDPathMapping> _data_sharedSymbolMappings = {};
  kiwi::String _data_sharedSymbolVersion = {};
  SharedComponentMasterData *_data_sharedComponentMasterData = {};
  kiwi::String _data_symbolDescription = {};
  kiwi::Array<GUIDPathMapping> _data_unflatteningMappings = {};
  kiwi::Array<GUIDPathMapping> _data_forceUnflatteningMappings = {};
  kiwi::String _data_publishFile = {};
  GUID *_data_publishID = {};
  kiwi::String _data_componentKey = {};
  kiwi::String _data_publishedVersion = {};
  kiwi::String _data_originComponentKey = {};
  kiwi::Array<ComponentPropDef> _data_componentPropDefs = {};
  kiwi::Array<ComponentPropRef> _data_componentPropRefs = {};
  SymbolData *_data_symbolData = {};
  kiwi::Array<NodeChange> _data_derivedSymbolData = {};
  GUID *_data_overriddenSymbolID = {};
  kiwi::Array<ComponentPropAssignment> _data_componentPropAssignments = {};
  kiwi::Array<InstanceOverrideStash> _data_overrideStash = {};
  kiwi::Array<InstanceOverrideStashV2> _data_overrideStashV2 = {};
  GUIDPath *_data_guidPath = {};
  TextAlignHorizontal _data_textAlignHorizontal = {};
  TextAlignVertical _data_textAlignVertical = {};
  TextCase _data_textCase = {};
  TextDecoration _data_textDecoration = {};
  Number *_data_lineHeight = {};
  FontName *_data_fontName = {};
  TextData *_data_textData = {};
  DerivedTextData *_data_derivedTextData = {};
  FontVariantNumericFigure _data_fontVariantNumericFigure = {};
  FontVariantNumericSpacing _data_fontVariantNumericSpacing = {};
  FontVariantNumericFraction _data_fontVariantNumericFraction = {};
  FontVariantCaps _data_fontVariantCaps = {};
  FontVariantPosition _data_fontVariantPosition = {};
  Number *_data_letterSpacing = {};
  kiwi::String _data_fontVersion = {};
  LeadingTrim _data_leadingTrim = {};
  SectionStatus _data_sectionStatus = {};
  SectionStatusInfo *_data_sectionStatusInfo = {};
  kiwi::Array<OpenTypeFeature> _data_toggledOnOTFeatures = {};
  kiwi::Array<OpenTypeFeature> _data_toggledOffOTFeatures = {};
  Hyperlink *_data_hyperlink = {};
  Mention *_data_mention = {};
  kiwi::Array<FontVariation> _data_fontVariations = {};
  TextTruncation _data_textTruncation = {};
  BlendMode _data_blendMode = {};
  Vector *_data_size = {};
  Matrix *_data_transform = {};
  kiwi::Array<float> _data_dashPattern = {};
  MaskType _data_maskType = {};
  StrokeAlign _data_strokeAlign = {};
  StrokeCap _data_strokeCap = {};
  StrokeJoin _data_strokeJoin = {};
  kiwi::Array<Paint> _data_fillPaints = {};
  kiwi::Array<Paint> _data_strokePaints = {};
  kiwi::Array<Effect> _data_effects = {};
  Color *_data_backgroundColor = {};
  kiwi::Array<Path> _data_fillGeometry = {};
  kiwi::Array<Path> _data_strokeGeometry = {};
  ConstraintType _data_horizontalConstraint = {};
  StackMode _data_stackMode = {};
  StackCounterAlign _data_stackCounterAlign = {};
  StackJustify _data_stackJustify = {};
  StackAlign _data_stackAlign = {};
  StackSize _data_stackWidth = {};
  StackSize _data_stackHeight = {};
  StackSize _data_stackPrimarySizing = {};
  StackJustify _data_stackPrimaryAlignItems = {};
  StackAlign _data_stackCounterAlignItems = {};
  StackCounterAlign _data_stackChildAlignSelf = {};
  StackPositioning _data_stackPositioning = {};
  StackWrap _data_stackWrap = {};
  OptionalVector *_data_minSize = {};
  OptionalVector *_data_maxSize = {};
  StackCounterAlignContent _data_stackCounterAlignContent = {};
  GUID *_data_transitionNodeID = {};
  GUID *_data_prototypeStartNodeID = {};
  Color *_data_prototypeBackgroundColor = {};
  TransitionInfo *_data_transitionInfo = {};
  TransitionType _data_transitionType = {};
  EasingType _data_easingType = {};
  ConnectionType _data_connectionType = {};
  kiwi::String _data_connectionURL = {};
  PrototypeDevice *_data_prototypeDevice = {};
  InteractionType _data_interactionType = {};
  kiwi::Array<PrototypeInteraction> _data_prototypeInteractions = {};
  PrototypeStartingPoint *_data_prototypeStartingPoint = {};
  kiwi::Array<PluginData> _data_pluginData = {};
  kiwi::Array<PluginRelaunchData> _data_pluginRelaunchData = {};
  ConnectorEndpoint *_data_connectorStart = {};
  ConnectorEndpoint *_data_connectorEnd = {};
  ConnectorLineStyle _data_connectorLineStyle = {};
  StrokeCap _data_connectorStartCap = {};
  StrokeCap _data_connectorEndCap = {};
  kiwi::Array<ConnectorControlPoint> _data_connectorControlPoints = {};
  ConnectorTextMidpoint *_data_connectorTextMidpoint = {};
  ShapeWithTextType _data_shapeWithTextType = {};
  DerivedImmutableFrameData *_data_derivedImmutableFrameData = {};
  MultiplayerFieldVersion *_data_derivedImmutableFrameDataVersion = {};
  NodeGenerationData *_data_nodeGenerationData = {};
  CodeBlockLanguage _data_codeBlockLanguage = {};
  LinkPreviewData *_data_linkPreviewData = {};
  VideoPlayback *_data_videoPlayback = {};
  StampData *_data_stampData = {};
  MultiplayerMap *_data_widgetSyncedState = {};
  WidgetDerivedSubtreeCursor *_data_widgetDerivedSubtreeCursor = {};
  WidgetPointer *_data_widgetCachedAncestor = {};
  WidgetInputBehavior _data_widgetInputBehavior = {};
  kiwi::String _data_widgetTooltip = {};
  WidgetHoverStyle *_data_widgetHoverStyle = {};
  WidgetMetadata *_data_widgetMetadata = {};
  kiwi::Array<WidgetEvent> _data_widgetEvents = {};
  kiwi::Array<WidgetPropertyMenuItem> _data_widgetPropertyMenuItems = {};
  TableRowColumnPositionMap *_data_tableRowPositions = {};
  TableRowColumnPositionMap *_data_tableColumnPositions = {};
  TableRowColumnSizeMap *_data_tableRowHeights = {};
  TableRowColumnSizeMap *_data_tableColumnWidths = {};
  InternalEnumForTest _data_internalEnumForTest = {};
  InternalDataForTest *_data_internalDataForTest = {};
  BooleanOperation _data_booleanOperation = {};
  ConstraintType _data_verticalConstraint = {};
  VectorMirror _data_handleMirroring = {};
  kiwi::Array<ExportSettings> _data_exportSettings = {};
  TextAutoResize _data_textAutoResize = {};
  kiwi::Array<LayoutGrid> _data_layoutGrids = {};
  VectorData *_data_vectorData = {};
  kiwi::Array<Guide> _data_guides = {};
  ScrollDirection _data_scrollDirection = {};
  Vector *_data_scrollOffset = {};
  ScrollContractedState _data_scrollContractedState = {};
  Vector *_data_contractedSize = {};
  kiwi::String _data_fixedChildrenDivider = {};
  ScrollBehavior _data_scrollBehavior = {};
  ArcData *_data_arcData = {};
  NavigationType _data_navigationType = {};
  OverlayPositionType _data_overlayPositionType = {};
  Vector *_data_overlayRelativePosition = {};
  OverlayBackgroundInteraction _data_overlayBackgroundInteraction = {};
  OverlayBackgroundAppearance *_data_overlayBackgroundAppearance = {};
  GUID *_data_overrideKey = {};
  StackSize _data_stackCounterSizing = {};
  KeyTrigger *_data_keyTrigger = {};
  kiwi::String _data_voiceEventPhrase = {};
  kiwi::Array<GUID> _data_ancestorPathBeforeDeletion = {};
  kiwi::Array<SymbolLink> _data_symbolLinks = {};
  TextListData *_data_textListData = {};
  EmbedData *_data_embedData = {};
  RichMediaData *_data_richMediaData = {};
  MultiplayerMap *_data_renderedSyncedState = {};
  HTMLTag _data_accessibleHTMLTag = {};
  ARIARole _data_ariaRole = {};
  kiwi::String _data_accessibleLabel = {};
  VariableData *_data_variableData = {};
  VariableDataMap *_data_variableConsumptionMap = {};
  VariableModeBySetMap *_data_variableModeBySetMap = {};
  kiwi::Array<VariableSetMode> _data_variableSetModes = {};
  VariableSetID *_data_variableSetID = {};
  VariableResolvedDataType _data_variableResolvedType = {};
  VariableDataValues *_data_variableDataValues = {};
  kiwi::String _data_variableTokenName = {};
  kiwi::Array<VariableScope> _data_variableScopes = {};
  CodeSyntaxMap *_data_codeSyntax = {};
  HandoffStatusMap *_data_handoffStatusMap = {};
  AgendaPositionMap *_data_agendaPositionMap = {};
  AgendaMetadataMap *_data_agendaMetadataMap = {};
  MigrationStatus *_data_migrationStatus = {};
  EditInfo *_data_editInfo = {};
  ColorProfile _data_colorProfile = {};
  SymbolId *_data_detachedSymbolId = {};
  ChildReadingDirection _data_childReadingDirection = {};
  kiwi::String _data_readingIndex = {};
  DocumentColorProfile _data_documentColorProfile = {};
  kiwi::Array<DeveloperRelatedLink> _data_developerRelatedLinks = {};
  kiwi::String _data_slideActiveThemeLibKey = {};
  ARIAAttributesMap *_data_ariaAttributes = {};
  uint32_t _data_guidTag = {};
  uint32_t _data_phaseTag = {};
  uint32_t _data_parentIndexTag = {};
  uint32_t _data_typeTag = {};
  uint32_t _data_nameTag = {};
  uint32_t _data_styleID = {};
  uint32_t _data_styleIDTag = {};
  uint32_t _data_symbolDataTag = {};
  uint32_t _data_guidPathTag = {};
  int32_t _data_overrideLevel = {};
  float _data_fontSize = {};
  uint32_t _data_fontSizeTag = {};
  float _data_paragraphIndent = {};
  uint32_t _data_paragraphIndentTag = {};
  float _data_paragraphSpacing = {};
  uint32_t _data_paragraphSpacingTag = {};
  uint32_t _data_textAlignHorizontalTag = {};
  uint32_t _data_textAlignVerticalTag = {};
  uint32_t _data_textCaseTag = {};
  uint32_t _data_textDecorationTag = {};
  uint32_t _data_lineHeightTag = {};
  uint32_t _data_fontNameTag = {};
  uint32_t _data_textDataTag = {};
  int32_t _data_maxLines = {};
  uint32_t _data_textUserLayoutVersion = {};
  uint32_t _data_textBidiVersion = {};
  uint32_t _data_visibleTag = {};
  uint32_t _data_lockedTag = {};
  float _data_opacity = {};
  uint32_t _data_opacityTag = {};
  uint32_t _data_blendModeTag = {};
  uint32_t _data_sizeTag = {};
  uint32_t _data_transformTag = {};
  uint32_t _data_dashPatternTag = {};
  uint32_t _data_maskTag = {};
  uint32_t _data_maskIsOutlineTag = {};
  float _data_backgroundOpacity = {};
  uint32_t _data_backgroundOpacityTag = {};
  float _data_cornerRadius = {};
  uint32_t _data_cornerRadiusTag = {};
  float _data_strokeWeight = {};
  uint32_t _data_strokeWeightTag = {};
  uint32_t _data_strokeAlignTag = {};
  uint32_t _data_strokeCapTag = {};
  uint32_t _data_strokeJoinTag = {};
  uint32_t _data_fillPaintsTag = {};
  uint32_t _data_strokePaintsTag = {};
  uint32_t _data_effectsTag = {};
  uint32_t _data_backgroundColorTag = {};
  uint32_t _data_fillGeometryTag = {};
  uint32_t _data_strokeGeometryTag = {};
  float _data_rectangleTopLeftCornerRadius = {};
  float _data_rectangleTopRightCornerRadius = {};
  float _data_rectangleBottomLeftCornerRadius = {};
  float _data_rectangleBottomRightCornerRadius = {};
  float _data_borderTopWeight = {};
  float _data_borderBottomWeight = {};
  float _data_borderLeftWeight = {};
  float _data_borderRightWeight = {};
  uint32_t _data_horizontalConstraintTag = {};
  uint32_t _data_stackModeTag = {};
  float _data_stackSpacing = {};
  uint32_t _data_stackSpacingTag = {};
  float _data_stackPadding = {};
  uint32_t _data_stackPaddingTag = {};
  float _data_stackHorizontalPadding = {};
  float _data_stackVerticalPadding = {};
  float _data_stackChildPrimaryGrow = {};
  float _data_stackPaddingRight = {};
  float _data_stackPaddingBottom = {};
  float _data_stackCounterSpacing = {};
  float _data_transitionDuration = {};
  float _data_transitionTimeout = {};
  float _data_interactionDuration = {};
  float _data_shapeUserHeight = {};
  uint32_t _data_widgetSyncCursor = {};
  uint32_t _data_count = {};
  uint32_t _data_countTag = {};
  uint32_t _data_autoRenameTag = {};
  uint32_t _data_backgroundEnabledTag = {};
  uint32_t _data_exportContentsOnlyTag = {};
  float _data_starInnerScale = {};
  uint32_t _data_starInnerScaleTag = {};
  float _data_miterLimit = {};
  uint32_t _data_miterLimitTag = {};
  float _data_textTracking = {};
  uint32_t _data_textTrackingTag = {};
  uint32_t _data_booleanOperationTag = {};
  uint32_t _data_verticalConstraintTag = {};
  uint32_t _data_handleMirroringTag = {};
  uint32_t _data_exportSettingsTag = {};
  uint32_t _data_textAutoResizeTag = {};
  uint32_t _data_layoutGridsTag = {};
  uint32_t _data_vectorDataTag = {};
  uint32_t _data_frameMaskDisabledTag = {};
  uint32_t _data_resizeToFitTag = {};
  float _data_cornerSmoothing = {};
  int32_t _data_derivedSymbolDataLayoutVersion = {};
  float _data_listSpacing = {};
  bool _data_isPublishable = {};
  bool _data_isSoftDeletedStyle = {};
  bool _data_isNonUpdateable = {};
  bool _data_isFillStyle = {};
  bool _data_isStrokeStyle = {};
  bool _data_isStateGroup = {};
  bool _data_isSymbolPublishable = {};
  bool _data_isC2 = {};
  bool _data_propsAreBubbled = {};
  bool _data_fontVariantCommonLigatures = {};
  bool _data_fontVariantContextualLigatures = {};
  bool _data_fontVariantDiscretionaryLigatures = {};
  bool _data_fontVariantHistoricalLigatures = {};
  bool _data_fontVariantOrdinal = {};
  bool _data_fontVariantSlashedZero = {};
  bool _data_hangingPunctuation = {};
  bool _data_hangingList = {};
  bool _data_hasHadRTLText = {};
  bool _data_visible = {};
  bool _data_locked = {};
  bool _data_mask = {};
  bool _data_maskIsOutline = {};
  bool _data_rectangleCornerRadiiIndependent = {};
  bool _data_rectangleCornerToolIndependent = {};
  bool _data_proportionsConstrained = {};
  bool _data_useAbsoluteBounds = {};
  bool _data_borderTopHidden = {};
  bool _data_borderBottomHidden = {};
  bool _data_borderLeftHidden = {};
  bool _data_borderRightHidden = {};
  bool _data_bordersTakeSpace = {};
  bool _data_borderStrokeWeightsIndependent = {};
  bool _data_stackReverseZIndex = {};
  bool _data_isSnakeGameBoard = {};
  bool _data_transitionPreserveScroll = {};
  bool _data_interactionMaintained = {};
  bool _data_destinationIsOverlay = {};
  bool _data_transitionShouldSmartAnimate = {};
  bool _data_shapeTruncates = {};
  bool _data_sectionContentsHidden = {};
  bool _data_isWidgetStickable = {};
  bool _data_shouldHideCursorsOnWidgetHover = {};
  bool _data_autoRename = {};
  bool _data_backgroundEnabled = {};
  bool _data_exportContentsOnly = {};
  bool _data_frameMaskDisabled = {};
  bool _data_resizeToFit = {};
  bool _data_exportBackgroundDisabled = {};
  bool _data_internalOnly = {};
  bool _data_exportTextAsSVGText = {};
  bool _data_containerSupportsFillStrokeAndCorners = {};
  bool _data_containersSupportFillStrokeAndCorners = {};
  bool _data_detachOpticalSizeFromFontSize = {};
  bool _data_simplifyInstancePanels = {};
  bool _data_isSoftDeleted = {};
};

class VideoPlayback {
public:
  VideoPlayback() { (void)_flags; }

  bool *autoplay();
  const bool *autoplay() const;
  void set_autoplay(const bool &value);

  bool *mediaLoop();
  const bool *mediaLoop() const;
  void set_mediaLoop(const bool &value);

  bool *muted();
  const bool *muted() const;
  void set_muted(const bool &value);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  bool _data_autoplay = {};
  bool _data_mediaLoop = {};
  bool _data_muted = {};
};

class WidgetHoverStyle {
public:
  WidgetHoverStyle() { (void)_flags; }

  kiwi::Array<Paint> *fillPaints();
  const kiwi::Array<Paint> *fillPaints() const;
  kiwi::Array<Paint> &set_fillPaints(kiwi::MemoryPool &pool, uint32_t count);

  kiwi::Array<Paint> *strokePaints();
  const kiwi::Array<Paint> *strokePaints() const;
  kiwi::Array<Paint> &set_strokePaints(kiwi::MemoryPool &pool, uint32_t count);

  float *opacity();
  const float *opacity() const;
  void set_opacity(const float &value);

  bool *areFillPaintsSet();
  const bool *areFillPaintsSet() const;
  void set_areFillPaintsSet(const bool &value);

  bool *areStrokePaintsSet();
  const bool *areStrokePaintsSet() const;
  void set_areStrokePaintsSet(const bool &value);

  bool *isOpacitySet();
  const bool *isOpacitySet() const;
  void set_isOpacitySet(const bool &value);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  kiwi::Array<Paint> _data_fillPaints = {};
  kiwi::Array<Paint> _data_strokePaints = {};
  float _data_opacity = {};
  bool _data_areFillPaintsSet = {};
  bool _data_areStrokePaintsSet = {};
  bool _data_isOpacitySet = {};
};

class WidgetDerivedSubtreeCursor {
public:
  WidgetDerivedSubtreeCursor() { (void)_flags; }

  uint32_t *sessionID();
  const uint32_t *sessionID() const;
  void set_sessionID(const uint32_t &value);

  uint32_t *counter();
  const uint32_t *counter() const;
  void set_counter(const uint32_t &value);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  uint32_t _data_sessionID = {};
  uint32_t _data_counter = {};
};

class MultiplayerMap {
public:
  MultiplayerMap() { (void)_flags; }

  kiwi::Array<MultiplayerMapEntry> *entries();
  const kiwi::Array<MultiplayerMapEntry> *entries() const;
  kiwi::Array<MultiplayerMapEntry> &set_entries(kiwi::MemoryPool &pool, uint32_t count);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  kiwi::Array<MultiplayerMapEntry> _data_entries = {};
};

class MultiplayerMapEntry {
public:
  MultiplayerMapEntry() { (void)_flags; }

  kiwi::String *key();
  const kiwi::String *key() const;
  void set_key(const kiwi::String &value);

  kiwi::String *value();
  const kiwi::String *value() const;
  void set_value(const kiwi::String &value);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  kiwi::String _data_key = {};
  kiwi::String _data_value = {};
};

class VariableDataMap {
public:
  VariableDataMap() { (void)_flags; }

  kiwi::Array<VariableDataMapEntry> *entries();
  const kiwi::Array<VariableDataMapEntry> *entries() const;
  kiwi::Array<VariableDataMapEntry> &set_entries(kiwi::MemoryPool &pool, uint32_t count);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  kiwi::Array<VariableDataMapEntry> _data_entries = {};
};

class VariableDataMapEntry {
public:
  VariableDataMapEntry() { (void)_flags; }

  uint32_t *nodeField();
  const uint32_t *nodeField() const;
  void set_nodeField(const uint32_t &value);

  VariableData *variableData();
  const VariableData *variableData() const;
  void set_variableData(VariableData *value);

  VariableField *variableField();
  const VariableField *variableField() const;
  void set_variableField(const VariableField &value);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  VariableData *_data_variableData = {};
  VariableField _data_variableField = {};
  uint32_t _data_nodeField = {};
};

class VariableModeBySetMap {
public:
  VariableModeBySetMap() { (void)_flags; }

  kiwi::Array<VariableModeBySetMapEntry> *entries();
  const kiwi::Array<VariableModeBySetMapEntry> *entries() const;
  kiwi::Array<VariableModeBySetMapEntry> &set_entries(kiwi::MemoryPool &pool, uint32_t count);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  kiwi::Array<VariableModeBySetMapEntry> _data_entries = {};
};

class VariableModeBySetMapEntry {
public:
  VariableModeBySetMapEntry() { (void)_flags; }

  VariableSetID *variableSetID();
  const VariableSetID *variableSetID() const;
  void set_variableSetID(VariableSetID *value);

  GUID *variableModeID();
  const GUID *variableModeID() const;
  void set_variableModeID(GUID *value);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  VariableSetID *_data_variableSetID = {};
  GUID *_data_variableModeID = {};
};

class CodeSyntaxMap {
public:
  CodeSyntaxMap() { (void)_flags; }

  kiwi::Array<CodeSyntaxMapEntry> *entries();
  const kiwi::Array<CodeSyntaxMapEntry> *entries() const;
  kiwi::Array<CodeSyntaxMapEntry> &set_entries(kiwi::MemoryPool &pool, uint32_t count);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  kiwi::Array<CodeSyntaxMapEntry> _data_entries = {};
};

class CodeSyntaxMapEntry {
public:
  CodeSyntaxMapEntry() { (void)_flags; }

  CodeSyntaxPlatform *platform();
  const CodeSyntaxPlatform *platform() const;
  void set_platform(const CodeSyntaxPlatform &value);

  kiwi::String *value();
  const kiwi::String *value() const;
  void set_value(const kiwi::String &value);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  CodeSyntaxPlatform _data_platform = {};
  kiwi::String _data_value = {};
};

class TableRowColumnPositionMap {
public:
  TableRowColumnPositionMap() { (void)_flags; }

  kiwi::Array<TableRowColumnPositionMapEntry> *entries();
  const kiwi::Array<TableRowColumnPositionMapEntry> *entries() const;
  kiwi::Array<TableRowColumnPositionMapEntry> &set_entries(kiwi::MemoryPool &pool, uint32_t count);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  kiwi::Array<TableRowColumnPositionMapEntry> _data_entries = {};
};

class TableRowColumnPositionMapEntry {
public:
  TableRowColumnPositionMapEntry() { (void)_flags; }

  GUID *id();
  const GUID *id() const;
  void set_id(GUID *value);

  kiwi::String *position();
  const kiwi::String *position() const;
  void set_position(const kiwi::String &value);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  GUID *_data_id = {};
  kiwi::String _data_position = {};
};

class TableRowColumnSizeMap {
public:
  TableRowColumnSizeMap() { (void)_flags; }

  kiwi::Array<TableRowColumnSizeMapEntry> *entries();
  const kiwi::Array<TableRowColumnSizeMapEntry> *entries() const;
  kiwi::Array<TableRowColumnSizeMapEntry> &set_entries(kiwi::MemoryPool &pool, uint32_t count);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  kiwi::Array<TableRowColumnSizeMapEntry> _data_entries = {};
};

class TableRowColumnSizeMapEntry {
public:
  TableRowColumnSizeMapEntry() { (void)_flags; }

  GUID *id();
  const GUID *id() const;
  void set_id(GUID *value);

  float *size();
  const float *size() const;
  void set_size(const float &value);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  GUID *_data_id = {};
  float _data_size = {};
};

class AgendaPositionMap {
public:
  AgendaPositionMap() { (void)_flags; }

  kiwi::Array<AgendaPositionMapEntry> *entries();
  const kiwi::Array<AgendaPositionMapEntry> *entries() const;
  kiwi::Array<AgendaPositionMapEntry> &set_entries(kiwi::MemoryPool &pool, uint32_t count);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  kiwi::Array<AgendaPositionMapEntry> _data_entries = {};
};

class AgendaPositionMapEntry {
public:
  AgendaPositionMapEntry() { (void)_flags; }

  GUID *id();
  const GUID *id() const;
  void set_id(GUID *value);

  kiwi::String *position();
  const kiwi::String *position() const;
  void set_position(const kiwi::String &value);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  GUID *_data_id = {};
  kiwi::String _data_position = {};
};

class AgendaMetadataMap {
public:
  AgendaMetadataMap() { (void)_flags; }

  kiwi::Array<AgendaMetadataMapEntry> *entries();
  const kiwi::Array<AgendaMetadataMapEntry> *entries() const;
  kiwi::Array<AgendaMetadataMapEntry> &set_entries(kiwi::MemoryPool &pool, uint32_t count);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  kiwi::Array<AgendaMetadataMapEntry> _data_entries = {};
};

class AgendaMetadataMapEntry {
public:
  AgendaMetadataMapEntry() { (void)_flags; }

  GUID *id();
  const GUID *id() const;
  void set_id(GUID *value);

  AgendaMetadata *data();
  const AgendaMetadata *data() const;
  void set_data(AgendaMetadata *value);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  GUID *_data_id = {};
  AgendaMetadata *_data_data = {};
};

class AgendaMetadata {
public:
  AgendaMetadata() { (void)_flags; }

  kiwi::String *name();
  const kiwi::String *name() const;
  void set_name(const kiwi::String &value);

  AgendaItemType *type();
  const AgendaItemType *type() const;
  void set_type(const AgendaItemType &value);

  GUID *targetNodeID();
  const GUID *targetNodeID() const;
  void set_targetNodeID(GUID *value);

  AgendaTimerInfo *timerInfo();
  const AgendaTimerInfo *timerInfo() const;
  void set_timerInfo(AgendaTimerInfo *value);

  AgendaVoteInfo *voteInfo();
  const AgendaVoteInfo *voteInfo() const;
  void set_voteInfo(AgendaVoteInfo *value);

  AgendaMusicInfo *musicInfo();
  const AgendaMusicInfo *musicInfo() const;
  void set_musicInfo(AgendaMusicInfo *value);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  kiwi::String _data_name = {};
  AgendaItemType _data_type = {};
  GUID *_data_targetNodeID = {};
  AgendaTimerInfo *_data_timerInfo = {};
  AgendaVoteInfo *_data_voteInfo = {};
  AgendaMusicInfo *_data_musicInfo = {};
};

class AgendaTimerInfo {
public:
  AgendaTimerInfo() { (void)_flags; }

  uint32_t *timerLength();
  const uint32_t *timerLength() const;
  void set_timerLength(const uint32_t &value);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  uint32_t _data_timerLength = {};
};

class AgendaVoteInfo {
public:
  AgendaVoteInfo() { (void)_flags; }

  uint32_t *voteCount();
  const uint32_t *voteCount() const;
  void set_voteCount(const uint32_t &value);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  uint32_t _data_voteCount = {};
};

class AgendaMusicInfo {
public:
  AgendaMusicInfo() { (void)_flags; }

  kiwi::String *songID();
  const kiwi::String *songID() const;
  void set_songID(const kiwi::String &value);

  uint32_t *startTimeMs();
  const uint32_t *startTimeMs() const;
  void set_startTimeMs(const uint32_t &value);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  kiwi::String _data_songID = {};
  uint32_t _data_startTimeMs = {};
};

class ComponentPropRef {
public:
  ComponentPropRef() { (void)_flags; }

  uint32_t *nodeField();
  const uint32_t *nodeField() const;
  void set_nodeField(const uint32_t &value);

  GUID *defID();
  const GUID *defID() const;
  void set_defID(GUID *value);

  kiwi::String *zombieFallbackName();
  const kiwi::String *zombieFallbackName() const;
  void set_zombieFallbackName(const kiwi::String &value);

  ComponentPropNodeField *componentPropNodeField();
  const ComponentPropNodeField *componentPropNodeField() const;
  void set_componentPropNodeField(const ComponentPropNodeField &value);

  bool *isDeleted();
  const bool *isDeleted() const;
  void set_isDeleted(const bool &value);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  GUID *_data_defID = {};
  kiwi::String _data_zombieFallbackName = {};
  ComponentPropNodeField _data_componentPropNodeField = {};
  uint32_t _data_nodeField = {};
  bool _data_isDeleted = {};
};

class ComponentPropAssignment {
public:
  ComponentPropAssignment() { (void)_flags; }

  GUID *defID();
  const GUID *defID() const;
  void set_defID(GUID *value);

  ComponentPropValue *value();
  const ComponentPropValue *value() const;
  void set_value(ComponentPropValue *value);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  GUID *_data_defID = {};
  ComponentPropValue *_data_value = {};
};

class ComponentPropDef {
public:
  ComponentPropDef() { (void)_flags; }

  GUID *id();
  const GUID *id() const;
  void set_id(GUID *value);

  kiwi::String *name();
  const kiwi::String *name() const;
  void set_name(const kiwi::String &value);

  ComponentPropValue *initialValue();
  const ComponentPropValue *initialValue() const;
  void set_initialValue(ComponentPropValue *value);

  kiwi::String *sortPosition();
  const kiwi::String *sortPosition() const;
  void set_sortPosition(const kiwi::String &value);

  GUID *parentPropDefId();
  const GUID *parentPropDefId() const;
  void set_parentPropDefId(GUID *value);

  ComponentPropType *type();
  const ComponentPropType *type() const;
  void set_type(const ComponentPropType &value);

  bool *isDeleted();
  const bool *isDeleted() const;
  void set_isDeleted(const bool &value);

  ComponentPropPreferredValues *preferredValues();
  const ComponentPropPreferredValues *preferredValues() const;
  void set_preferredValues(ComponentPropPreferredValues *value);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  GUID *_data_id = {};
  kiwi::String _data_name = {};
  ComponentPropValue *_data_initialValue = {};
  kiwi::String _data_sortPosition = {};
  GUID *_data_parentPropDefId = {};
  ComponentPropType _data_type = {};
  ComponentPropPreferredValues *_data_preferredValues = {};
  bool _data_isDeleted = {};
};

class ComponentPropValue {
public:
  ComponentPropValue() { (void)_flags; }

  bool *boolValue();
  const bool *boolValue() const;
  void set_boolValue(const bool &value);

  TextData *textValue();
  const TextData *textValue() const;
  void set_textValue(TextData *value);

  GUID *guidValue();
  const GUID *guidValue() const;
  void set_guidValue(GUID *value);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  TextData *_data_textValue = {};
  GUID *_data_guidValue = {};
  bool _data_boolValue = {};
};

class ComponentPropPreferredValues {
public:
  ComponentPropPreferredValues() { (void)_flags; }

  kiwi::Array<kiwi::String> *stringValues();
  const kiwi::Array<kiwi::String> *stringValues() const;
  kiwi::Array<kiwi::String> &set_stringValues(kiwi::MemoryPool &pool, uint32_t count);

  kiwi::Array<InstanceSwapPreferredValue> *instanceSwapValues();
  const kiwi::Array<InstanceSwapPreferredValue> *instanceSwapValues() const;
  kiwi::Array<InstanceSwapPreferredValue> &set_instanceSwapValues(kiwi::MemoryPool &pool, uint32_t count);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  kiwi::Array<kiwi::String> _data_stringValues = {};
  kiwi::Array<InstanceSwapPreferredValue> _data_instanceSwapValues = {};
};

class InstanceSwapPreferredValue {
public:
  InstanceSwapPreferredValue() { (void)_flags; }

  InstanceSwapPreferredValueType *type();
  const InstanceSwapPreferredValueType *type() const;
  void set_type(const InstanceSwapPreferredValueType &value);

  kiwi::String *key();
  const kiwi::String *key() const;
  void set_key(const kiwi::String &value);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  InstanceSwapPreferredValueType _data_type = {};
  kiwi::String _data_key = {};
};

class WidgetMetadata {
public:
  WidgetMetadata() { (void)_flags; }

  kiwi::String *pluginID();
  const kiwi::String *pluginID() const;
  void set_pluginID(const kiwi::String &value);

  kiwi::String *pluginVersionID();
  const kiwi::String *pluginVersionID() const;
  void set_pluginVersionID(const kiwi::String &value);

  kiwi::String *widgetName();
  const kiwi::String *widgetName() const;
  void set_widgetName(const kiwi::String &value);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  kiwi::String _data_pluginID = {};
  kiwi::String _data_pluginVersionID = {};
  kiwi::String _data_widgetName = {};
};

class WidgetPropertyMenuSelectorOption {
public:
  WidgetPropertyMenuSelectorOption() { (void)_flags; }

  kiwi::String *option();
  const kiwi::String *option() const;
  void set_option(const kiwi::String &value);

  kiwi::String *tooltip();
  const kiwi::String *tooltip() const;
  void set_tooltip(const kiwi::String &value);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  kiwi::String _data_option = {};
  kiwi::String _data_tooltip = {};
};

class WidgetPropertyMenuItem {
public:
  WidgetPropertyMenuItem() { (void)_flags; }

  kiwi::String *propertyName();
  const kiwi::String *propertyName() const;
  void set_propertyName(const kiwi::String &value);

  kiwi::String *tooltip();
  const kiwi::String *tooltip() const;
  void set_tooltip(const kiwi::String &value);

  WidgetPropertyMenuItemType *itemType();
  const WidgetPropertyMenuItemType *itemType() const;
  void set_itemType(const WidgetPropertyMenuItemType &value);

  kiwi::String *icon();
  const kiwi::String *icon() const;
  void set_icon(const kiwi::String &value);

  kiwi::Array<WidgetPropertyMenuSelectorOption> *options();
  const kiwi::Array<WidgetPropertyMenuSelectorOption> *options() const;
  kiwi::Array<WidgetPropertyMenuSelectorOption> &set_options(kiwi::MemoryPool &pool, uint32_t count);

  kiwi::String *selectedOption();
  const kiwi::String *selectedOption() const;
  void set_selectedOption(const kiwi::String &value);

  bool *isToggled();
  const bool *isToggled() const;
  void set_isToggled(const bool &value);

  kiwi::String *href();
  const kiwi::String *href() const;
  void set_href(const kiwi::String &value);

  bool *allowCustomColor();
  const bool *allowCustomColor() const;
  void set_allowCustomColor(const bool &value);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  kiwi::String _data_propertyName = {};
  kiwi::String _data_tooltip = {};
  WidgetPropertyMenuItemType _data_itemType = {};
  kiwi::String _data_icon = {};
  kiwi::Array<WidgetPropertyMenuSelectorOption> _data_options = {};
  kiwi::String _data_selectedOption = {};
  kiwi::String _data_href = {};
  bool _data_isToggled = {};
  bool _data_allowCustomColor = {};
};

class InternalDataForTest {
public:
  InternalDataForTest() { (void)_flags; }

  int32_t *testFieldA();
  const int32_t *testFieldA() const;
  void set_testFieldA(const int32_t &value);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  int32_t _data_testFieldA = {};
};

class StateGroupPropertyValueOrder {
public:
  StateGroupPropertyValueOrder() { (void)_flags; }

  kiwi::String *property();
  const kiwi::String *property() const;
  void set_property(const kiwi::String &value);

  kiwi::Array<kiwi::String> *values();
  const kiwi::Array<kiwi::String> *values() const;
  kiwi::Array<kiwi::String> &set_values(kiwi::MemoryPool &pool, uint32_t count);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  kiwi::String _data_property = {};
  kiwi::Array<kiwi::String> _data_values = {};
};

class TextListData {
public:
  TextListData() { (void)_flags; }

  int32_t *listID();
  const int32_t *listID() const;
  void set_listID(const int32_t &value);

  BulletType *bulletType();
  const BulletType *bulletType() const;
  void set_bulletType(const BulletType &value);

  int32_t *indentationLevel();
  const int32_t *indentationLevel() const;
  void set_indentationLevel(const int32_t &value);

  int32_t *lineNumber();
  const int32_t *lineNumber() const;
  void set_lineNumber(const int32_t &value);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  BulletType _data_bulletType = {};
  int32_t _data_listID = {};
  int32_t _data_indentationLevel = {};
  int32_t _data_lineNumber = {};
};

class TextLineData {
public:
  TextLineData() { (void)_flags; }

  LineType *lineType();
  const LineType *lineType() const;
  void set_lineType(const LineType &value);

  int32_t *indentationLevel();
  const int32_t *indentationLevel() const;
  void set_indentationLevel(const int32_t &value);

  SourceDirectionality *sourceDirectionality();
  const SourceDirectionality *sourceDirectionality() const;
  void set_sourceDirectionality(const SourceDirectionality &value);

  Directionality *directionality();
  const Directionality *directionality() const;
  void set_directionality(const Directionality &value);

  DirectionalityIntent *directionalityIntent();
  const DirectionalityIntent *directionalityIntent() const;
  void set_directionalityIntent(const DirectionalityIntent &value);

  int32_t *downgradeStyleId();
  const int32_t *downgradeStyleId() const;
  void set_downgradeStyleId(const int32_t &value);

  int32_t *consistencyStyleId();
  const int32_t *consistencyStyleId() const;
  void set_consistencyStyleId(const int32_t &value);

  int32_t *listStartOffset();
  const int32_t *listStartOffset() const;
  void set_listStartOffset(const int32_t &value);

  bool *isFirstLineOfList();
  const bool *isFirstLineOfList() const;
  void set_isFirstLineOfList(const bool &value);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  LineType _data_lineType = {};
  SourceDirectionality _data_sourceDirectionality = {};
  Directionality _data_directionality = {};
  DirectionalityIntent _data_directionalityIntent = {};
  int32_t _data_indentationLevel = {};
  int32_t _data_downgradeStyleId = {};
  int32_t _data_consistencyStyleId = {};
  int32_t _data_listStartOffset = {};
  bool _data_isFirstLineOfList = {};
};

class DerivedTextLineData {
public:
  DerivedTextLineData() { (void)_flags; }

  Directionality *directionality();
  const Directionality *directionality() const;
  void set_directionality(const Directionality &value);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  Directionality _data_directionality = {};
};

class PrototypeInteraction {
public:
  PrototypeInteraction() { (void)_flags; }

  GUID *id();
  const GUID *id() const;
  void set_id(GUID *value);

  PrototypeEvent *event();
  const PrototypeEvent *event() const;
  void set_event(PrototypeEvent *value);

  kiwi::Array<PrototypeAction> *actions();
  const kiwi::Array<PrototypeAction> *actions() const;
  kiwi::Array<PrototypeAction> &set_actions(kiwi::MemoryPool &pool, uint32_t count);

  bool *isDeleted();
  const bool *isDeleted() const;
  void set_isDeleted(const bool &value);

  int32_t *stateManagementVersion();
  const int32_t *stateManagementVersion() const;
  void set_stateManagementVersion(const int32_t &value);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  GUID *_data_id = {};
  PrototypeEvent *_data_event = {};
  kiwi::Array<PrototypeAction> _data_actions = {};
  int32_t _data_stateManagementVersion = {};
  bool _data_isDeleted = {};
};

class PrototypeEvent {
public:
  PrototypeEvent() { (void)_flags; }

  InteractionType *interactionType();
  const InteractionType *interactionType() const;
  void set_interactionType(const InteractionType &value);

  bool *interactionMaintained();
  const bool *interactionMaintained() const;
  void set_interactionMaintained(const bool &value);

  float *interactionDuration();
  const float *interactionDuration() const;
  void set_interactionDuration(const float &value);

  KeyTrigger *keyTrigger();
  const KeyTrigger *keyTrigger() const;
  void set_keyTrigger(KeyTrigger *value);

  kiwi::String *voiceEventPhrase();
  const kiwi::String *voiceEventPhrase() const;
  void set_voiceEventPhrase(const kiwi::String &value);

  float *transitionTimeout();
  const float *transitionTimeout() const;
  void set_transitionTimeout(const float &value);

  float *mediaHitTime();
  const float *mediaHitTime() const;
  void set_mediaHitTime(const float &value);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  InteractionType _data_interactionType = {};
  KeyTrigger *_data_keyTrigger = {};
  kiwi::String _data_voiceEventPhrase = {};
  float _data_interactionDuration = {};
  float _data_transitionTimeout = {};
  float _data_mediaHitTime = {};
  bool _data_interactionMaintained = {};
};

class PrototypeVariableTarget {
public:
  PrototypeVariableTarget() { (void)_flags; }

  VariableID *id();
  const VariableID *id() const;
  void set_id(VariableID *value);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  VariableID *_data_id = {};
};

class ConditionalActions {
public:
  ConditionalActions() { (void)_flags; }

  kiwi::Array<PrototypeAction> *actions();
  const kiwi::Array<PrototypeAction> *actions() const;
  kiwi::Array<PrototypeAction> &set_actions(kiwi::MemoryPool &pool, uint32_t count);

  VariableData *condition();
  const VariableData *condition() const;
  void set_condition(VariableData *value);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  kiwi::Array<PrototypeAction> _data_actions = {};
  VariableData *_data_condition = {};
};

class PrototypeAction {
public:
  PrototypeAction() { (void)_flags; }

  GUID *transitionNodeID();
  const GUID *transitionNodeID() const;
  void set_transitionNodeID(GUID *value);

  TransitionType *transitionType();
  const TransitionType *transitionType() const;
  void set_transitionType(const TransitionType &value);

  float *transitionDuration();
  const float *transitionDuration() const;
  void set_transitionDuration(const float &value);

  EasingType *easingType();
  const EasingType *easingType() const;
  void set_easingType(const EasingType &value);

  float *transitionTimeout();
  const float *transitionTimeout() const;
  void set_transitionTimeout(const float &value);

  bool *transitionShouldSmartAnimate();
  const bool *transitionShouldSmartAnimate() const;
  void set_transitionShouldSmartAnimate(const bool &value);

  ConnectionType *connectionType();
  const ConnectionType *connectionType() const;
  void set_connectionType(const ConnectionType &value);

  kiwi::String *connectionURL();
  const kiwi::String *connectionURL() const;
  void set_connectionURL(const kiwi::String &value);

  Vector *overlayRelativePosition();
  const Vector *overlayRelativePosition() const;
  void set_overlayRelativePosition(Vector *value);

  NavigationType *navigationType();
  const NavigationType *navigationType() const;
  void set_navigationType(const NavigationType &value);

  bool *transitionPreserveScroll();
  const bool *transitionPreserveScroll() const;
  void set_transitionPreserveScroll(const bool &value);

  kiwi::Array<float> *easingFunction();
  const kiwi::Array<float> *easingFunction() const;
  kiwi::Array<float> &set_easingFunction(kiwi::MemoryPool &pool, uint32_t count);

  Vector *extraScrollOffset();
  const Vector *extraScrollOffset() const;
  void set_extraScrollOffset(Vector *value);

  GUID *targetVariableID();
  const GUID *targetVariableID() const;
  void set_targetVariableID(GUID *value);

  VariableAnyValue *targetVariableValue();
  const VariableAnyValue *targetVariableValue() const;
  void set_targetVariableValue(VariableAnyValue *value);

  MediaAction *mediaAction();
  const MediaAction *mediaAction() const;
  void set_mediaAction(const MediaAction &value);

  bool *transitionResetVideoPosition();
  const bool *transitionResetVideoPosition() const;
  void set_transitionResetVideoPosition(const bool &value);

  bool *openUrlInNewTab();
  const bool *openUrlInNewTab() const;
  void set_openUrlInNewTab(const bool &value);

  PrototypeVariableTarget *targetVariable();
  const PrototypeVariableTarget *targetVariable() const;
  void set_targetVariable(PrototypeVariableTarget *value);

  VariableData *targetVariableData();
  const VariableData *targetVariableData() const;
  void set_targetVariableData(VariableData *value);

  float *mediaSkipToTime();
  const float *mediaSkipToTime() const;
  void set_mediaSkipToTime(const float &value);

  float *mediaSkipByAmount();
  const float *mediaSkipByAmount() const;
  void set_mediaSkipByAmount(const float &value);

  kiwi::Array<VariableData> *conditions();
  const kiwi::Array<VariableData> *conditions() const;
  kiwi::Array<VariableData> &set_conditions(kiwi::MemoryPool &pool, uint32_t count);

  kiwi::Array<ConditionalActions> *conditionalActions();
  const kiwi::Array<ConditionalActions> *conditionalActions() const;
  kiwi::Array<ConditionalActions> &set_conditionalActions(kiwi::MemoryPool &pool, uint32_t count);

  bool *transitionResetScrollPosition();
  const bool *transitionResetScrollPosition() const;
  void set_transitionResetScrollPosition(const bool &value);

  bool *transitionResetInteractiveComponents();
  const bool *transitionResetInteractiveComponents() const;
  void set_transitionResetInteractiveComponents(const bool &value);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  GUID *_data_transitionNodeID = {};
  TransitionType _data_transitionType = {};
  EasingType _data_easingType = {};
  ConnectionType _data_connectionType = {};
  kiwi::String _data_connectionURL = {};
  Vector *_data_overlayRelativePosition = {};
  NavigationType _data_navigationType = {};
  kiwi::Array<float> _data_easingFunction = {};
  Vector *_data_extraScrollOffset = {};
  GUID *_data_targetVariableID = {};
  VariableAnyValue *_data_targetVariableValue = {};
  MediaAction _data_mediaAction = {};
  PrototypeVariableTarget *_data_targetVariable = {};
  VariableData *_data_targetVariableData = {};
  kiwi::Array<VariableData> _data_conditions = {};
  kiwi::Array<ConditionalActions> _data_conditionalActions = {};
  float _data_transitionDuration = {};
  float _data_transitionTimeout = {};
  float _data_mediaSkipToTime = {};
  float _data_mediaSkipByAmount = {};
  bool _data_transitionShouldSmartAnimate = {};
  bool _data_transitionPreserveScroll = {};
  bool _data_transitionResetVideoPosition = {};
  bool _data_openUrlInNewTab = {};
  bool _data_transitionResetScrollPosition = {};
  bool _data_transitionResetInteractiveComponents = {};
};

class PrototypeStartingPoint {
public:
  PrototypeStartingPoint() { (void)_flags; }

  kiwi::String *name();
  const kiwi::String *name() const;
  void set_name(const kiwi::String &value);

  kiwi::String *description();
  const kiwi::String *description() const;
  void set_description(const kiwi::String &value);

  kiwi::String *position();
  const kiwi::String *position() const;
  void set_position(const kiwi::String &value);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  kiwi::String _data_name = {};
  kiwi::String _data_description = {};
  kiwi::String _data_position = {};
};

class KeyTrigger {
public:
  KeyTrigger() { (void)_flags; }

  kiwi::Array<int32_t> *keyCodes();
  const kiwi::Array<int32_t> *keyCodes() const;
  kiwi::Array<int32_t> &set_keyCodes(kiwi::MemoryPool &pool, uint32_t count);

  TriggerDevice *triggerDevice();
  const TriggerDevice *triggerDevice() const;
  void set_triggerDevice(const TriggerDevice &value);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  kiwi::Array<int32_t> _data_keyCodes = {};
  TriggerDevice _data_triggerDevice = {};
};

class Hyperlink {
public:
  Hyperlink() { (void)_flags; }

  kiwi::String *url();
  const kiwi::String *url() const;
  void set_url(const kiwi::String &value);

  GUID *guid();
  const GUID *guid() const;
  void set_guid(GUID *value);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  kiwi::String _data_url = {};
  GUID *_data_guid = {};
};

class Mention {
public:
  Mention() { (void)_flags; }

  GUID *id();
  const GUID *id() const;
  void set_id(GUID *value);

  kiwi::String *mentionedUserId();
  const kiwi::String *mentionedUserId() const;
  void set_mentionedUserId(const kiwi::String &value);

  kiwi::String *mentionedByUserId();
  const kiwi::String *mentionedByUserId() const;
  void set_mentionedByUserId(const kiwi::String &value);

  kiwi::String *fileKey();
  const kiwi::String *fileKey() const;
  void set_fileKey(const kiwi::String &value);

  MentionSource *source();
  const MentionSource *source() const;
  void set_source(const MentionSource &value);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  GUID *_data_id = {};
  kiwi::String _data_mentionedUserId = {};
  kiwi::String _data_mentionedByUserId = {};
  kiwi::String _data_fileKey = {};
  MentionSource _data_source = {};
};

class EmbedData {
public:
  EmbedData() { (void)_flags; }

  kiwi::String *url();
  const kiwi::String *url() const;
  void set_url(const kiwi::String &value);

  kiwi::String *srcUrl();
  const kiwi::String *srcUrl() const;
  void set_srcUrl(const kiwi::String &value);

  kiwi::String *title();
  const kiwi::String *title() const;
  void set_title(const kiwi::String &value);

  kiwi::String *thumbnailUrl();
  const kiwi::String *thumbnailUrl() const;
  void set_thumbnailUrl(const kiwi::String &value);

  float *width();
  const float *width() const;
  void set_width(const float &value);

  float *height();
  const float *height() const;
  void set_height(const float &value);

  kiwi::String *embedType();
  const kiwi::String *embedType() const;
  void set_embedType(const kiwi::String &value);

  kiwi::String *thumbnailImageHash();
  const kiwi::String *thumbnailImageHash() const;
  void set_thumbnailImageHash(const kiwi::String &value);

  kiwi::String *faviconImageHash();
  const kiwi::String *faviconImageHash() const;
  void set_faviconImageHash(const kiwi::String &value);

  kiwi::String *provider();
  const kiwi::String *provider() const;
  void set_provider(const kiwi::String &value);

  kiwi::String *originalText();
  const kiwi::String *originalText() const;
  void set_originalText(const kiwi::String &value);

  kiwi::String *description();
  const kiwi::String *description() const;
  void set_description(const kiwi::String &value);

  kiwi::String *embedVersionId();
  const kiwi::String *embedVersionId() const;
  void set_embedVersionId(const kiwi::String &value);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  kiwi::String _data_url = {};
  kiwi::String _data_srcUrl = {};
  kiwi::String _data_title = {};
  kiwi::String _data_thumbnailUrl = {};
  kiwi::String _data_embedType = {};
  kiwi::String _data_thumbnailImageHash = {};
  kiwi::String _data_faviconImageHash = {};
  kiwi::String _data_provider = {};
  kiwi::String _data_originalText = {};
  kiwi::String _data_description = {};
  kiwi::String _data_embedVersionId = {};
  float _data_width = {};
  float _data_height = {};
};

class StampData {
public:
  StampData() { (void)_flags; }

  kiwi::String *userId();
  const kiwi::String *userId() const;
  void set_userId(const kiwi::String &value);

  kiwi::String *votingSessionId();
  const kiwi::String *votingSessionId() const;
  void set_votingSessionId(const kiwi::String &value);

  kiwi::String *stampedByUserId();
  const kiwi::String *stampedByUserId() const;
  void set_stampedByUserId(const kiwi::String &value);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  kiwi::String _data_userId = {};
  kiwi::String _data_votingSessionId = {};
  kiwi::String _data_stampedByUserId = {};
};

class LinkPreviewData {
public:
  LinkPreviewData() { (void)_flags; }

  kiwi::String *url();
  const kiwi::String *url() const;
  void set_url(const kiwi::String &value);

  kiwi::String *title();
  const kiwi::String *title() const;
  void set_title(const kiwi::String &value);

  kiwi::String *provider();
  const kiwi::String *provider() const;
  void set_provider(const kiwi::String &value);

  kiwi::String *description();
  const kiwi::String *description() const;
  void set_description(const kiwi::String &value);

  kiwi::String *thumbnailImageHash();
  const kiwi::String *thumbnailImageHash() const;
  void set_thumbnailImageHash(const kiwi::String &value);

  kiwi::String *faviconImageHash();
  const kiwi::String *faviconImageHash() const;
  void set_faviconImageHash(const kiwi::String &value);

  float *thumbnailImageWidth();
  const float *thumbnailImageWidth() const;
  void set_thumbnailImageWidth(const float &value);

  float *thumbnailImageHeight();
  const float *thumbnailImageHeight() const;
  void set_thumbnailImageHeight(const float &value);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  kiwi::String _data_url = {};
  kiwi::String _data_title = {};
  kiwi::String _data_provider = {};
  kiwi::String _data_description = {};
  kiwi::String _data_thumbnailImageHash = {};
  kiwi::String _data_faviconImageHash = {};
  float _data_thumbnailImageWidth = {};
  float _data_thumbnailImageHeight = {};
};

class Viewport {
public:
  Viewport() { (void)_flags; }

  Rect *canvasSpaceBounds();
  const Rect *canvasSpaceBounds() const;
  void set_canvasSpaceBounds(Rect *value);

  bool *pixelPreview();
  const bool *pixelPreview() const;
  void set_pixelPreview(const bool &value);

  float *pixelDensity();
  const float *pixelDensity() const;
  void set_pixelDensity(const float &value);

  GUID *canvasGuid();
  const GUID *canvasGuid() const;
  void set_canvasGuid(GUID *value);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  Rect *_data_canvasSpaceBounds = {};
  GUID *_data_canvasGuid = {};
  float _data_pixelDensity = {};
  bool _data_pixelPreview = {};
};

class Mouse {
public:
  Mouse() { (void)_flags; }

  MouseCursor *cursor();
  const MouseCursor *cursor() const;
  void set_cursor(const MouseCursor &value);

  Vector *canvasSpaceLocation();
  const Vector *canvasSpaceLocation() const;
  void set_canvasSpaceLocation(Vector *value);

  Rect *canvasSpaceSelectionBox();
  const Rect *canvasSpaceSelectionBox() const;
  void set_canvasSpaceSelectionBox(Rect *value);

  GUID *canvasGuid();
  const GUID *canvasGuid() const;
  void set_canvasGuid(GUID *value);

  uint32_t *cursorHiddenReason();
  const uint32_t *cursorHiddenReason() const;
  void set_cursorHiddenReason(const uint32_t &value);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  MouseCursor _data_cursor = {};
  Vector *_data_canvasSpaceLocation = {};
  Rect *_data_canvasSpaceSelectionBox = {};
  GUID *_data_canvasGuid = {};
  uint32_t _data_cursorHiddenReason = {};
};

class Click {
public:
  Click() { (void)_flags; }

  uint32_t *id();
  const uint32_t *id() const;
  void set_id(const uint32_t &value);

  Vector *point();
  const Vector *point() const;
  void set_point(Vector *value);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  Vector *_data_point = {};
  uint32_t _data_id = {};
};

class ScrollPosition {
public:
  ScrollPosition() { (void)_flags; }

  GUID *node();
  const GUID *node() const;
  void set_node(GUID *value);

  Vector *scrollOffset();
  const Vector *scrollOffset() const;
  void set_scrollOffset(Vector *value);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  GUID *_data_node = {};
  Vector *_data_scrollOffset = {};
};

class TriggeredOverlay {
public:
  TriggeredOverlay() { (void)_flags; }

  GUID *overlayGuid();
  const GUID *overlayGuid() const;
  void set_overlayGuid(GUID *value);

  GUID *hotspotGuid();
  const GUID *hotspotGuid() const;
  void set_hotspotGuid(GUID *value);

  GUID *swapGuid();
  const GUID *swapGuid() const;
  void set_swapGuid(GUID *value);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  GUID *_data_overlayGuid = {};
  GUID *_data_hotspotGuid = {};
  GUID *_data_swapGuid = {};
};

class TriggeredOverlayData {
public:
  TriggeredOverlayData() { (void)_flags; }

  GUID *overlayGuid();
  const GUID *overlayGuid() const;
  void set_overlayGuid(GUID *value);

  GUID *hotspotGuid();
  const GUID *hotspotGuid() const;
  void set_hotspotGuid(GUID *value);

  GUID *swapGuid();
  const GUID *swapGuid() const;
  void set_swapGuid(GUID *value);

  GUID *prototypeInteractionGuid();
  const GUID *prototypeInteractionGuid() const;
  void set_prototypeInteractionGuid(GUID *value);

  GUIDPath *hotspotBlueprintId();
  const GUIDPath *hotspotBlueprintId() const;
  void set_hotspotBlueprintId(GUIDPath *value);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  GUID *_data_overlayGuid = {};
  GUID *_data_hotspotGuid = {};
  GUID *_data_swapGuid = {};
  GUID *_data_prototypeInteractionGuid = {};
  GUIDPath *_data_hotspotBlueprintId = {};
};

class PresentedState {
public:
  PresentedState() { (void)_flags; }

  GUID *baseScreenID();
  const GUID *baseScreenID() const;
  void set_baseScreenID(GUID *value);

  kiwi::Array<TriggeredOverlayData> *overlays();
  const kiwi::Array<TriggeredOverlayData> *overlays() const;
  kiwi::Array<TriggeredOverlayData> &set_overlays(kiwi::MemoryPool &pool, uint32_t count);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  GUID *_data_baseScreenID = {};
  kiwi::Array<TriggeredOverlayData> _data_overlays = {};
};

class TopLevelPlaybackChange {
public:
  TopLevelPlaybackChange() { (void)_flags; }

  PresentedState *oldState();
  const PresentedState *oldState() const;
  void set_oldState(PresentedState *value);

  PresentedState *newState();
  const PresentedState *newState() const;
  void set_newState(PresentedState *value);

  GUIDPath *hotspotBlueprintID();
  const GUIDPath *hotspotBlueprintID() const;
  void set_hotspotBlueprintID(GUIDPath *value);

  GUID *interactionID();
  const GUID *interactionID() const;
  void set_interactionID(GUID *value);

  bool *isHotspotInNewPresentedState();
  const bool *isHotspotInNewPresentedState() const;
  void set_isHotspotInNewPresentedState(const bool &value);

  TransitionDirection *direction();
  const TransitionDirection *direction() const;
  void set_direction(const TransitionDirection &value);

  GUIDPath *instanceStablePath();
  const GUIDPath *instanceStablePath() const;
  void set_instanceStablePath(GUIDPath *value);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  PresentedState *_data_oldState = {};
  PresentedState *_data_newState = {};
  GUIDPath *_data_hotspotBlueprintID = {};
  GUID *_data_interactionID = {};
  TransitionDirection _data_direction = {};
  GUIDPath *_data_instanceStablePath = {};
  bool _data_isHotspotInNewPresentedState = {};
};

class InstanceStateChange {
public:
  InstanceStateChange() { (void)_flags; }

  GUID *stateID();
  const GUID *stateID() const;
  void set_stateID(GUID *value);

  GUID *interactionID();
  const GUID *interactionID() const;
  void set_interactionID(GUID *value);

  GUIDPath *hotspotStablePath();
  const GUIDPath *hotspotStablePath() const;
  void set_hotspotStablePath(GUIDPath *value);

  GUIDPath *instanceStablePath();
  const GUIDPath *instanceStablePath() const;
  void set_instanceStablePath(GUIDPath *value);

  PlaybackChangePhase *phase();
  const PlaybackChangePhase *phase() const;
  void set_phase(const PlaybackChangePhase &value);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  GUID *_data_stateID = {};
  GUID *_data_interactionID = {};
  GUIDPath *_data_hotspotStablePath = {};
  GUIDPath *_data_instanceStablePath = {};
  PlaybackChangePhase _data_phase = {};
};

class TextCursor {
public:
  TextCursor() { (void)_flags; }

  Rect *selectionBox();
  const Rect *selectionBox() const;
  void set_selectionBox(Rect *value);

  GUID *canvasGuid();
  const GUID *canvasGuid() const;
  void set_canvasGuid(GUID *value);

  GUID *textNodeGuid();
  const GUID *textNodeGuid() const;
  void set_textNodeGuid(GUID *value);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  Rect *_data_selectionBox = {};
  GUID *_data_canvasGuid = {};
  GUID *_data_textNodeGuid = {};
};

class TextSelection {
public:
  TextSelection() { (void)_flags; }

  kiwi::Array<Rect> *selectionBoxes();
  const kiwi::Array<Rect> *selectionBoxes() const;
  kiwi::Array<Rect> &set_selectionBoxes(kiwi::MemoryPool &pool, uint32_t count);

  GUID *canvasGuid();
  const GUID *canvasGuid() const;
  void set_canvasGuid(GUID *value);

  GUID *textNodeGuid();
  const GUID *textNodeGuid() const;
  void set_textNodeGuid(GUID *value);

  Vector *textSelectionRange();
  const Vector *textSelectionRange() const;
  void set_textSelectionRange(Vector *value);

  GUID *textNodeOrContainingIfGuid();
  const GUID *textNodeOrContainingIfGuid() const;
  void set_textNodeOrContainingIfGuid(GUID *value);

  GUID *tableCellRowId();
  const GUID *tableCellRowId() const;
  void set_tableCellRowId(GUID *value);

  GUID *tableCellColId();
  const GUID *tableCellColId() const;
  void set_tableCellColId(GUID *value);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  kiwi::Array<Rect> _data_selectionBoxes = {};
  GUID *_data_canvasGuid = {};
  GUID *_data_textNodeGuid = {};
  Vector *_data_textSelectionRange = {};
  GUID *_data_textNodeOrContainingIfGuid = {};
  GUID *_data_tableCellRowId = {};
  GUID *_data_tableCellColId = {};
};

class PlaybackChangeKeyframe {
public:
  PlaybackChangeKeyframe() { (void)_flags; }

  PlaybackChangePhase *phase();
  const PlaybackChangePhase *phase() const;
  void set_phase(const PlaybackChangePhase &value);

  float *progress();
  const float *progress() const;
  void set_progress(const float &value);

  float *timestamp();
  const float *timestamp() const;
  void set_timestamp(const float &value);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  PlaybackChangePhase _data_phase = {};
  float _data_progress = {};
  float _data_timestamp = {};
};

class StateMapping {
public:
  StateMapping() { (void)_flags; }

  GUIDPath *stablePath();
  const GUIDPath *stablePath() const;
  void set_stablePath(GUIDPath *value);

  TopLevelPlaybackChange *lastTopLevelChange();
  const TopLevelPlaybackChange *lastTopLevelChange() const;
  void set_lastTopLevelChange(TopLevelPlaybackChange *value);

  PlaybackChangeKeyframe *lastTopLevelChangeStatus();
  const PlaybackChangeKeyframe *lastTopLevelChangeStatus() const;
  void set_lastTopLevelChangeStatus(PlaybackChangeKeyframe *value);

  float *timestamp();
  const float *timestamp() const;
  void set_timestamp(const float &value);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  GUIDPath *_data_stablePath = {};
  TopLevelPlaybackChange *_data_lastTopLevelChange = {};
  PlaybackChangeKeyframe *_data_lastTopLevelChangeStatus = {};
  float _data_timestamp = {};
};

class ScrollMapping {
public:
  ScrollMapping() { (void)_flags; }

  GUIDPath *blueprintID();
  const GUIDPath *blueprintID() const;
  void set_blueprintID(GUIDPath *value);

  uint32_t *overlayIndex();
  const uint32_t *overlayIndex() const;
  void set_overlayIndex(const uint32_t &value);

  Vector *scrollOffset();
  const Vector *scrollOffset() const;
  void set_scrollOffset(Vector *value);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  GUIDPath *_data_blueprintID = {};
  Vector *_data_scrollOffset = {};
  uint32_t _data_overlayIndex = {};
};

class PlaybackUpdate {
public:
  PlaybackUpdate() { (void)_flags; }

  TopLevelPlaybackChange *lastTopLevelChange();
  const TopLevelPlaybackChange *lastTopLevelChange() const;
  void set_lastTopLevelChange(TopLevelPlaybackChange *value);

  PlaybackChangeKeyframe *lastTopLevelChangeStatus();
  const PlaybackChangeKeyframe *lastTopLevelChangeStatus() const;
  void set_lastTopLevelChangeStatus(PlaybackChangeKeyframe *value);

  kiwi::Array<ScrollMapping> *scrollMappings();
  const kiwi::Array<ScrollMapping> *scrollMappings() const;
  kiwi::Array<ScrollMapping> &set_scrollMappings(kiwi::MemoryPool &pool, uint32_t count);

  float *timestamp();
  const float *timestamp() const;
  void set_timestamp(const float &value);

  Vector *pointerLocation();
  const Vector *pointerLocation() const;
  void set_pointerLocation(Vector *value);

  bool *isTopLevelFrameChange();
  const bool *isTopLevelFrameChange() const;
  void set_isTopLevelFrameChange(const bool &value);

  kiwi::Array<StateMapping> *stateMappings();
  const kiwi::Array<StateMapping> *stateMappings() const;
  kiwi::Array<StateMapping> &set_stateMappings(kiwi::MemoryPool &pool, uint32_t count);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  TopLevelPlaybackChange *_data_lastTopLevelChange = {};
  PlaybackChangeKeyframe *_data_lastTopLevelChangeStatus = {};
  kiwi::Array<ScrollMapping> _data_scrollMappings = {};
  Vector *_data_pointerLocation = {};
  kiwi::Array<StateMapping> _data_stateMappings = {};
  float _data_timestamp = {};
  bool _data_isTopLevelFrameChange = {};
};

class ChatMessage {
public:
  ChatMessage() { (void)_flags; }

  kiwi::String *text();
  const kiwi::String *text() const;
  void set_text(const kiwi::String &value);

  kiwi::String *previousText();
  const kiwi::String *previousText() const;
  void set_previousText(const kiwi::String &value);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  kiwi::String _data_text = {};
  kiwi::String _data_previousText = {};
};

class VoiceMetadata {
public:
  VoiceMetadata() { (void)_flags; }

  kiwi::String *connectedCallId();
  const kiwi::String *connectedCallId() const;
  void set_connectedCallId(const kiwi::String &value);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  kiwi::String _data_connectedCallId = {};
};

class UserChange {
public:
  UserChange() { (void)_flags; }

  uint32_t *sessionID();
  const uint32_t *sessionID() const;
  void set_sessionID(const uint32_t &value);

  bool *connected();
  const bool *connected() const;
  void set_connected(const bool &value);

  kiwi::String *name();
  const kiwi::String *name() const;
  void set_name(const kiwi::String &value);

  Color *color();
  const Color *color() const;
  void set_color(Color *value);

  kiwi::String *imageURL();
  const kiwi::String *imageURL() const;
  void set_imageURL(const kiwi::String &value);

  Viewport *viewport();
  const Viewport *viewport() const;
  void set_viewport(Viewport *value);

  Mouse *mouse();
  const Mouse *mouse() const;
  void set_mouse(Mouse *value);

  kiwi::Array<GUID> *selection();
  const kiwi::Array<GUID> *selection() const;
  kiwi::Array<GUID> &set_selection(kiwi::MemoryPool &pool, uint32_t count);

  kiwi::Array<uint32_t> *observing();
  const kiwi::Array<uint32_t> *observing() const;
  kiwi::Array<uint32_t> &set_observing(kiwi::MemoryPool &pool, uint32_t count);

  kiwi::String *deviceName();
  const kiwi::String *deviceName() const;
  void set_deviceName(const kiwi::String &value);

  kiwi::Array<Click> *recentClicks();
  const kiwi::Array<Click> *recentClicks() const;
  kiwi::Array<Click> &set_recentClicks(kiwi::MemoryPool &pool, uint32_t count);

  kiwi::Array<ScrollPosition> *scrollPositions();
  const kiwi::Array<ScrollPosition> *scrollPositions() const;
  kiwi::Array<ScrollPosition> &set_scrollPositions(kiwi::MemoryPool &pool, uint32_t count);

  kiwi::Array<TriggeredOverlay> *triggeredOverlays();
  const kiwi::Array<TriggeredOverlay> *triggeredOverlays() const;
  kiwi::Array<TriggeredOverlay> &set_triggeredOverlays(kiwi::MemoryPool &pool, uint32_t count);

  kiwi::String *userID();
  const kiwi::String *userID() const;
  void set_userID(const kiwi::String &value);

  GUID *lastTriggeredHotspot();
  const GUID *lastTriggeredHotspot() const;
  void set_lastTriggeredHotspot(GUID *value);

  GUID *lastTriggeredPrototypeInteractionID();
  const GUID *lastTriggeredPrototypeInteractionID() const;
  void set_lastTriggeredPrototypeInteractionID(GUID *value);

  kiwi::Array<TriggeredOverlayData> *triggeredOverlaysData();
  const kiwi::Array<TriggeredOverlayData> *triggeredOverlaysData() const;
  kiwi::Array<TriggeredOverlayData> &set_triggeredOverlaysData(kiwi::MemoryPool &pool, uint32_t count);

  kiwi::Array<PlaybackUpdate> *playbackUpdates();
  const kiwi::Array<PlaybackUpdate> *playbackUpdates() const;
  kiwi::Array<PlaybackUpdate> &set_playbackUpdates(kiwi::MemoryPool &pool, uint32_t count);

  ChatMessage *chatMessage();
  const ChatMessage *chatMessage() const;
  void set_chatMessage(ChatMessage *value);

  VoiceMetadata *voiceMetadata();
  const VoiceMetadata *voiceMetadata() const;
  void set_voiceMetadata(VoiceMetadata *value);

  bool *canWrite();
  const bool *canWrite() const;
  void set_canWrite(const bool &value);

  bool *highFiveStatus();
  const bool *highFiveStatus() const;
  void set_highFiveStatus(const bool &value);

  kiwi::Array<InstanceStateChange> *instanceStateChanges();
  const kiwi::Array<InstanceStateChange> *instanceStateChanges() const;
  kiwi::Array<InstanceStateChange> &set_instanceStateChanges(kiwi::MemoryPool &pool, uint32_t count);

  TextCursor *textCursor();
  const TextCursor *textCursor() const;
  void set_textCursor(TextCursor *value);

  TextSelection *textSelection();
  const TextSelection *textSelection() const;
  void set_textSelection(TextSelection *value);

  uint32_t *connectedAtTimeS();
  const uint32_t *connectedAtTimeS() const;
  void set_connectedAtTimeS(const uint32_t &value);

  bool *focusOnTextCursor();
  const bool *focusOnTextCursor() const;
  void set_focusOnTextCursor(const bool &value);

  Heartbeat *heartbeat();
  const Heartbeat *heartbeat() const;
  void set_heartbeat(const Heartbeat &value);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  kiwi::String _data_name = {};
  Color *_data_color = {};
  kiwi::String _data_imageURL = {};
  Viewport *_data_viewport = {};
  Mouse *_data_mouse = {};
  kiwi::Array<GUID> _data_selection = {};
  kiwi::Array<uint32_t> _data_observing = {};
  kiwi::String _data_deviceName = {};
  kiwi::Array<Click> _data_recentClicks = {};
  kiwi::Array<ScrollPosition> _data_scrollPositions = {};
  kiwi::Array<TriggeredOverlay> _data_triggeredOverlays = {};
  kiwi::String _data_userID = {};
  GUID *_data_lastTriggeredHotspot = {};
  GUID *_data_lastTriggeredPrototypeInteractionID = {};
  kiwi::Array<TriggeredOverlayData> _data_triggeredOverlaysData = {};
  kiwi::Array<PlaybackUpdate> _data_playbackUpdates = {};
  ChatMessage *_data_chatMessage = {};
  VoiceMetadata *_data_voiceMetadata = {};
  kiwi::Array<InstanceStateChange> _data_instanceStateChanges = {};
  TextCursor *_data_textCursor = {};
  TextSelection *_data_textSelection = {};
  Heartbeat _data_heartbeat = {};
  uint32_t _data_sessionID = {};
  uint32_t _data_connectedAtTimeS = {};
  bool _data_connected = {};
  bool _data_canWrite = {};
  bool _data_highFiveStatus = {};
  bool _data_focusOnTextCursor = {};
};

class SceneGraphQuery {
public:
  SceneGraphQuery() { (void)_flags; }

  GUID *startingNode();
  const GUID *startingNode() const;
  void set_startingNode(GUID *value);

  uint32_t *depth();
  const uint32_t *depth() const;
  void set_depth(const uint32_t &value);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  GUID *_data_startingNode = {};
  uint32_t _data_depth = {};
};

class NodeChangesMetadata {
public:
  NodeChangesMetadata() { (void)_flags; }

  uint32_t *blobsFieldOffset();
  const uint32_t *blobsFieldOffset() const;
  void set_blobsFieldOffset(const uint32_t &value);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  uint32_t _data_blobsFieldOffset = {};
};

class CursorReaction {
public:
  CursorReaction() { (void)_flags; }

  kiwi::String *imageUrl();
  const kiwi::String *imageUrl() const;
  void set_imageUrl(const kiwi::String &value);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  kiwi::String _data_imageUrl = {};
};

class TimerInfo {
public:
  TimerInfo() { (void)_flags; }

  bool *isPaused();
  const bool *isPaused() const;
  void set_isPaused(const bool &value);

  uint32_t *timeRemainingMs();
  const uint32_t *timeRemainingMs() const;
  void set_timeRemainingMs(const uint32_t &value);

  uint32_t *totalTimeMs();
  const uint32_t *totalTimeMs() const;
  void set_totalTimeMs(const uint32_t &value);

  uint32_t *timerID();
  const uint32_t *timerID() const;
  void set_timerID(const uint32_t &value);

  kiwi::String *setBy();
  const kiwi::String *setBy() const;
  void set_setBy(const kiwi::String &value);

  uint32_t *songID();
  const uint32_t *songID() const;
  void set_songID(const uint32_t &value);

  uint32_t *lastReceivedSongTimestampMs();
  const uint32_t *lastReceivedSongTimestampMs() const;
  void set_lastReceivedSongTimestampMs(const uint32_t &value);

  kiwi::String *songUUID();
  const kiwi::String *songUUID() const;
  void set_songUUID(const kiwi::String &value);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  kiwi::String _data_setBy = {};
  kiwi::String _data_songUUID = {};
  uint32_t _data_timeRemainingMs = {};
  uint32_t _data_totalTimeMs = {};
  uint32_t _data_timerID = {};
  uint32_t _data_songID = {};
  uint32_t _data_lastReceivedSongTimestampMs = {};
  bool _data_isPaused = {};
};

class MusicInfo {
public:
  MusicInfo() { (void)_flags; }

  bool *isPaused();
  const bool *isPaused() const;
  void set_isPaused(const bool &value);

  uint32_t *messageID();
  const uint32_t *messageID() const;
  void set_messageID(const uint32_t &value);

  kiwi::String *songID();
  const kiwi::String *songID() const;
  void set_songID(const kiwi::String &value);

  uint32_t *lastReceivedSongTimestampMs();
  const uint32_t *lastReceivedSongTimestampMs() const;
  void set_lastReceivedSongTimestampMs(const uint32_t &value);

  bool *isStopped();
  const bool *isStopped() const;
  void set_isStopped(const bool &value);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  kiwi::String _data_songID = {};
  uint32_t _data_messageID = {};
  uint32_t _data_lastReceivedSongTimestampMs = {};
  bool _data_isPaused = {};
  bool _data_isStopped = {};
};

class PresenterNomination {
public:
  PresenterNomination() { (void)_flags; }

  uint32_t *sessionID();
  const uint32_t *sessionID() const;
  void set_sessionID(const uint32_t &value);

  bool *isCancelled();
  const bool *isCancelled() const;
  void set_isCancelled(const bool &value);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  uint32_t _data_sessionID = {};
  bool _data_isCancelled = {};
};

class PresenterInfo {
public:
  PresenterInfo() { (void)_flags; }

  uint32_t *sessionID();
  const uint32_t *sessionID() const;
  void set_sessionID(const uint32_t &value);

  PresenterNomination *nomination();
  const PresenterNomination *nomination() const;
  void set_nomination(PresenterNomination *value);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  PresenterNomination *_data_nomination = {};
  uint32_t _data_sessionID = {};
};

class ClientBroadcast {
public:
  ClientBroadcast() { (void)_flags; }

  uint32_t *sessionID();
  const uint32_t *sessionID() const;
  void set_sessionID(const uint32_t &value);

  CursorReaction *cursorReaction();
  const CursorReaction *cursorReaction() const;
  void set_cursorReaction(CursorReaction *value);

  TimerInfo *timer();
  const TimerInfo *timer() const;
  void set_timer(TimerInfo *value);

  PresenterInfo *presenter();
  const PresenterInfo *presenter() const;
  void set_presenter(PresenterInfo *value);

  PresenterInfo *prototypePresenter();
  const PresenterInfo *prototypePresenter() const;
  void set_prototypePresenter(PresenterInfo *value);

  MusicInfo *music();
  const MusicInfo *music() const;
  void set_music(MusicInfo *value);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  CursorReaction *_data_cursorReaction = {};
  TimerInfo *_data_timer = {};
  PresenterInfo *_data_presenter = {};
  PresenterInfo *_data_prototypePresenter = {};
  MusicInfo *_data_music = {};
  uint32_t _data_sessionID = {};
};

class Message {
public:
  Message() { (void)_flags; }

  MessageType *type();
  const MessageType *type() const;
  void set_type(const MessageType &value);

  uint32_t *sessionID();
  const uint32_t *sessionID() const;
  void set_sessionID(const uint32_t &value);

  uint32_t *ackID();
  const uint32_t *ackID() const;
  void set_ackID(const uint32_t &value);

  kiwi::Array<NodeChange> *nodeChanges();
  const kiwi::Array<NodeChange> *nodeChanges() const;
  kiwi::Array<NodeChange> &set_nodeChanges(kiwi::MemoryPool &pool, uint32_t count);

  kiwi::Array<UserChange> *userChanges();
  const kiwi::Array<UserChange> *userChanges() const;
  kiwi::Array<UserChange> &set_userChanges(kiwi::MemoryPool &pool, uint32_t count);

  kiwi::Array<Blob> *blobs();
  const kiwi::Array<Blob> *blobs() const;
  kiwi::Array<Blob> &set_blobs(kiwi::MemoryPool &pool, uint32_t count);

  uint32_t *blobBaseIndex();
  const uint32_t *blobBaseIndex() const;
  void set_blobBaseIndex(const uint32_t &value);

  kiwi::String *signalName();
  const kiwi::String *signalName() const;
  void set_signalName(const kiwi::String &value);

  Access *access();
  const Access *access() const;
  void set_access(const Access &value);

  kiwi::String *styleSetName();
  const kiwi::String *styleSetName() const;
  void set_styleSetName(const kiwi::String &value);

  StyleSetType *styleSetType();
  const StyleSetType *styleSetType() const;
  void set_styleSetType(const StyleSetType &value);

  StyleSetContentType *styleSetContentType();
  const StyleSetContentType *styleSetContentType() const;
  void set_styleSetContentType(const StyleSetContentType &value);

  int32_t *pasteID();
  const int32_t *pasteID() const;
  void set_pasteID(const int32_t &value);

  Vector *pasteOffset();
  const Vector *pasteOffset() const;
  void set_pasteOffset(Vector *value);

  kiwi::String *pasteFileKey();
  const kiwi::String *pasteFileKey() const;
  void set_pasteFileKey(const kiwi::String &value);

  kiwi::String *signalPayload();
  const kiwi::String *signalPayload() const;
  void set_signalPayload(const kiwi::String &value);

  kiwi::Array<SceneGraphQuery> *sceneGraphQueries();
  const kiwi::Array<SceneGraphQuery> *sceneGraphQueries() const;
  kiwi::Array<SceneGraphQuery> &set_sceneGraphQueries(kiwi::MemoryPool &pool, uint32_t count);

  NodeChangesMetadata *nodeChangesMetadata();
  const NodeChangesMetadata *nodeChangesMetadata() const;
  void set_nodeChangesMetadata(NodeChangesMetadata *value);

  uint32_t *fileVersion();
  const uint32_t *fileVersion() const;
  void set_fileVersion(const uint32_t &value);

  bool *pasteIsPartiallyOutsideEnclosingFrame();
  const bool *pasteIsPartiallyOutsideEnclosingFrame() const;
  void set_pasteIsPartiallyOutsideEnclosingFrame(const bool &value);

  GUID *pastePageId();
  const GUID *pastePageId() const;
  void set_pastePageId(GUID *value);

  bool *isCut();
  const bool *isCut() const;
  void set_isCut(const bool &value);

  kiwi::Array<Message> *localUndoStack();
  const kiwi::Array<Message> *localUndoStack() const;
  kiwi::Array<Message> &set_localUndoStack(kiwi::MemoryPool &pool, uint32_t count);

  kiwi::Array<Message> *localRedoStack();
  const kiwi::Array<Message> *localRedoStack() const;
  kiwi::Array<Message> &set_localRedoStack(kiwi::MemoryPool &pool, uint32_t count);

  kiwi::Array<ClientBroadcast> *broadcasts();
  const kiwi::Array<ClientBroadcast> *broadcasts() const;
  kiwi::Array<ClientBroadcast> &set_broadcasts(kiwi::MemoryPool &pool, uint32_t count);

  uint32_t *reconnectSequenceNumber();
  const uint32_t *reconnectSequenceNumber() const;
  void set_reconnectSequenceNumber(const uint32_t &value);

  kiwi::String *pasteBranchSourceFileKey();
  const kiwi::String *pasteBranchSourceFileKey() const;
  void set_pasteBranchSourceFileKey(const kiwi::String &value);

  EditorType *pasteEditorType();
  const EditorType *pasteEditorType() const;
  void set_pasteEditorType(const EditorType &value);

  kiwi::String *postSyncActions();
  const kiwi::String *postSyncActions() const;
  void set_postSyncActions(const kiwi::String &value);

  kiwi::Array<GUID> *publishedAssetGuids();
  const kiwi::Array<GUID> *publishedAssetGuids() const;
  kiwi::Array<GUID> &set_publishedAssetGuids(kiwi::MemoryPool &pool, uint32_t count);

  bool *dirtyFromInitialLoad();
  const bool *dirtyFromInitialLoad() const;
  void set_dirtyFromInitialLoad(const bool &value);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  MessageType _data_type = {};
  kiwi::Array<NodeChange> _data_nodeChanges = {};
  kiwi::Array<UserChange> _data_userChanges = {};
  kiwi::Array<Blob> _data_blobs = {};
  kiwi::String _data_signalName = {};
  Access _data_access = {};
  kiwi::String _data_styleSetName = {};
  StyleSetType _data_styleSetType = {};
  StyleSetContentType _data_styleSetContentType = {};
  Vector *_data_pasteOffset = {};
  kiwi::String _data_pasteFileKey = {};
  kiwi::String _data_signalPayload = {};
  kiwi::Array<SceneGraphQuery> _data_sceneGraphQueries = {};
  NodeChangesMetadata *_data_nodeChangesMetadata = {};
  GUID *_data_pastePageId = {};
  kiwi::Array<Message> _data_localUndoStack = {};
  kiwi::Array<Message> _data_localRedoStack = {};
  kiwi::Array<ClientBroadcast> _data_broadcasts = {};
  kiwi::String _data_pasteBranchSourceFileKey = {};
  EditorType _data_pasteEditorType = {};
  kiwi::String _data_postSyncActions = {};
  kiwi::Array<GUID> _data_publishedAssetGuids = {};
  uint32_t _data_sessionID = {};
  uint32_t _data_ackID = {};
  uint32_t _data_blobBaseIndex = {};
  int32_t _data_pasteID = {};
  uint32_t _data_fileVersion = {};
  uint32_t _data_reconnectSequenceNumber = {};
  bool _data_pasteIsPartiallyOutsideEnclosingFrame = {};
  bool _data_isCut = {};
  bool _data_dirtyFromInitialLoad = {};
};

class DiffChunk {
public:
  DiffChunk() { (void)_flags; }

  kiwi::Array<uint32_t> *nodeChanges();
  const kiwi::Array<uint32_t> *nodeChanges() const;
  kiwi::Array<uint32_t> &set_nodeChanges(kiwi::MemoryPool &pool, uint32_t count);

  NodePhase *phase();
  const NodePhase *phase() const;
  void set_phase(const NodePhase &value);

  NodeChange *displayNode();
  const NodeChange *displayNode() const;
  void set_displayNode(NodeChange *value);

  GUID *canvasId();
  const GUID *canvasId() const;
  void set_canvasId(GUID *value);

  kiwi::String *canvasName();
  const kiwi::String *canvasName() const;
  void set_canvasName(const kiwi::String &value);

  bool *canvasIsInternal();
  const bool *canvasIsInternal() const;
  void set_canvasIsInternal(const bool &value);

  kiwi::Array<uint32_t> *chunksAffectingThisChunk();
  const kiwi::Array<uint32_t> *chunksAffectingThisChunk() const;
  kiwi::Array<uint32_t> &set_chunksAffectingThisChunk(kiwi::MemoryPool &pool, uint32_t count);

  kiwi::Array<NodeChange> *basisParentHierarchy();
  const kiwi::Array<NodeChange> *basisParentHierarchy() const;
  kiwi::Array<NodeChange> &set_basisParentHierarchy(kiwi::MemoryPool &pool, uint32_t count);

  kiwi::Array<NodeChange> *parentHierarchy();
  const kiwi::Array<NodeChange> *parentHierarchy() const;
  kiwi::Array<NodeChange> &set_parentHierarchy(kiwi::MemoryPool &pool, uint32_t count);

  kiwi::Array<GUID> *basisParentHierarchyGuids();
  const kiwi::Array<GUID> *basisParentHierarchyGuids() const;
  kiwi::Array<GUID> &set_basisParentHierarchyGuids(kiwi::MemoryPool &pool, uint32_t count);

  kiwi::Array<GUID> *parentHierarchyGuids();
  const kiwi::Array<GUID> *parentHierarchyGuids() const;
  kiwi::Array<GUID> &set_parentHierarchyGuids(kiwi::MemoryPool &pool, uint32_t count);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  kiwi::Array<uint32_t> _data_nodeChanges = {};
  NodePhase _data_phase = {};
  NodeChange *_data_displayNode = {};
  GUID *_data_canvasId = {};
  kiwi::String _data_canvasName = {};
  kiwi::Array<uint32_t> _data_chunksAffectingThisChunk = {};
  kiwi::Array<NodeChange> _data_basisParentHierarchy = {};
  kiwi::Array<NodeChange> _data_parentHierarchy = {};
  kiwi::Array<GUID> _data_basisParentHierarchyGuids = {};
  kiwi::Array<GUID> _data_parentHierarchyGuids = {};
  bool _data_canvasIsInternal = {};
};

class DiffPayload {
public:
  DiffPayload() { (void)_flags; }

  kiwi::Array<NodeChange> *nodeChanges();
  const kiwi::Array<NodeChange> *nodeChanges() const;
  kiwi::Array<NodeChange> &set_nodeChanges(kiwi::MemoryPool &pool, uint32_t count);

  kiwi::Array<Blob> *blobs();
  const kiwi::Array<Blob> *blobs() const;
  kiwi::Array<Blob> &set_blobs(kiwi::MemoryPool &pool, uint32_t count);

  kiwi::Array<DiffChunk> *diffChunks();
  const kiwi::Array<DiffChunk> *diffChunks() const;
  kiwi::Array<DiffChunk> &set_diffChunks(kiwi::MemoryPool &pool, uint32_t count);

  kiwi::Array<NodeChange> *diffBasis();
  const kiwi::Array<NodeChange> *diffBasis() const;
  kiwi::Array<NodeChange> &set_diffBasis(kiwi::MemoryPool &pool, uint32_t count);

  kiwi::Array<NodeChange> *basisParentNodeChanges();
  const kiwi::Array<NodeChange> *basisParentNodeChanges() const;
  kiwi::Array<NodeChange> &set_basisParentNodeChanges(kiwi::MemoryPool &pool, uint32_t count);

  kiwi::Array<NodeChange> *parentNodeChanges();
  const kiwi::Array<NodeChange> *parentNodeChanges() const;
  kiwi::Array<NodeChange> &set_parentNodeChanges(kiwi::MemoryPool &pool, uint32_t count);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  kiwi::Array<NodeChange> _data_nodeChanges = {};
  kiwi::Array<Blob> _data_blobs = {};
  kiwi::Array<DiffChunk> _data_diffChunks = {};
  kiwi::Array<NodeChange> _data_diffBasis = {};
  kiwi::Array<NodeChange> _data_basisParentNodeChanges = {};
  kiwi::Array<NodeChange> _data_parentNodeChanges = {};
};

class RichMediaData {
public:
  RichMediaData() { (void)_flags; }

  kiwi::String *mediaHash();
  const kiwi::String *mediaHash() const;
  void set_mediaHash(const kiwi::String &value);

  RichMediaType *richMediaType();
  const RichMediaType *richMediaType() const;
  void set_richMediaType(const RichMediaType &value);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  kiwi::String _data_mediaHash = {};
  RichMediaType _data_richMediaType = {};
};

class VariableAnyValue {
public:
  VariableAnyValue() { (void)_flags; }

  bool *boolValue();
  const bool *boolValue() const;
  void set_boolValue(const bool &value);

  kiwi::String *textValue();
  const kiwi::String *textValue() const;
  void set_textValue(const kiwi::String &value);

  float *floatValue();
  const float *floatValue() const;
  void set_floatValue(const float &value);

  VariableID *alias();
  const VariableID *alias() const;
  void set_alias(VariableID *value);

  Color *colorValue();
  const Color *colorValue() const;
  void set_colorValue(Color *value);

  Expression *expressionValue();
  const Expression *expressionValue() const;
  void set_expressionValue(Expression *value);

  VariableMap *mapValue();
  const VariableMap *mapValue() const;
  void set_mapValue(VariableMap *value);

  SymbolId *symbolIdValue();
  const SymbolId *symbolIdValue() const;
  void set_symbolIdValue(SymbolId *value);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  kiwi::String _data_textValue = {};
  VariableID *_data_alias = {};
  Color *_data_colorValue = {};
  Expression *_data_expressionValue = {};
  VariableMap *_data_mapValue = {};
  SymbolId *_data_symbolIdValue = {};
  float _data_floatValue = {};
  bool _data_boolValue = {};
};

class Expression {
public:
  Expression() { (void)_flags; }

  ExpressionFunction *expressionFunction();
  const ExpressionFunction *expressionFunction() const;
  void set_expressionFunction(const ExpressionFunction &value);

  kiwi::Array<VariableData> *expressionArguments();
  const kiwi::Array<VariableData> *expressionArguments() const;
  kiwi::Array<VariableData> &set_expressionArguments(kiwi::MemoryPool &pool, uint32_t count);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  ExpressionFunction _data_expressionFunction = {};
  kiwi::Array<VariableData> _data_expressionArguments = {};
};

class VariableMapValue {
public:
  VariableMapValue() { (void)_flags; }

  kiwi::String *key();
  const kiwi::String *key() const;
  void set_key(const kiwi::String &value);

  VariableData *value();
  const VariableData *value() const;
  void set_value(VariableData *value);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  kiwi::String _data_key = {};
  VariableData *_data_value = {};
};

class VariableMap {
public:
  VariableMap() { (void)_flags; }

  kiwi::Array<VariableMapValue> *values();
  const kiwi::Array<VariableMapValue> *values() const;
  kiwi::Array<VariableMapValue> &set_values(kiwi::MemoryPool &pool, uint32_t count);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  kiwi::Array<VariableMapValue> _data_values = {};
};

class VariableData {
public:
  VariableData() { (void)_flags; }

  VariableAnyValue *value();
  const VariableAnyValue *value() const;
  void set_value(VariableAnyValue *value);

  VariableDataType *dataType();
  const VariableDataType *dataType() const;
  void set_dataType(const VariableDataType &value);

  VariableResolvedDataType *resolvedDataType();
  const VariableResolvedDataType *resolvedDataType() const;
  void set_resolvedDataType(const VariableResolvedDataType &value);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  VariableAnyValue *_data_value = {};
  VariableDataType _data_dataType = {};
  VariableResolvedDataType _data_resolvedDataType = {};
};

class VariableSetMode {
public:
  VariableSetMode() { (void)_flags; }

  GUID *id();
  const GUID *id() const;
  void set_id(GUID *value);

  kiwi::String *name();
  const kiwi::String *name() const;
  void set_name(const kiwi::String &value);

  kiwi::String *sortPosition();
  const kiwi::String *sortPosition() const;
  void set_sortPosition(const kiwi::String &value);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  GUID *_data_id = {};
  kiwi::String _data_name = {};
  kiwi::String _data_sortPosition = {};
};

class VariableDataValues {
public:
  VariableDataValues() { (void)_flags; }

  kiwi::Array<VariableDataValuesEntry> *entries();
  const kiwi::Array<VariableDataValuesEntry> *entries() const;
  kiwi::Array<VariableDataValuesEntry> &set_entries(kiwi::MemoryPool &pool, uint32_t count);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  kiwi::Array<VariableDataValuesEntry> _data_entries = {};
};

class VariableDataValuesEntry {
public:
  VariableDataValuesEntry() { (void)_flags; }

  GUID *modeID();
  const GUID *modeID() const;
  void set_modeID(GUID *value);

  VariableData *variableData();
  const VariableData *variableData() const;
  void set_variableData(VariableData *value);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  GUID *_data_modeID = {};
  VariableData *_data_variableData = {};
};

class OptionalVector {
public:
  OptionalVector() { (void)_flags; }

  Vector *value();
  const Vector *value() const;
  void set_value(Vector *value);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  Vector *_data_value = {};
};

class MigrationStatus {
public:
  MigrationStatus() { (void)_flags; }

  bool *dsdCleanup();
  const bool *dsdCleanup() const;
  void set_dsdCleanup(const bool &value);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  bool _data_dsdCleanup = {};
};

class NodeFieldMap {
public:
  NodeFieldMap() { (void)_flags; }

  kiwi::Array<NodeFieldMapEntry> *entries();
  const kiwi::Array<NodeFieldMapEntry> *entries() const;
  kiwi::Array<NodeFieldMapEntry> &set_entries(kiwi::MemoryPool &pool, uint32_t count);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  kiwi::Array<NodeFieldMapEntry> _data_entries = {};
};

class NodeFieldMapEntry {
public:
  NodeFieldMapEntry() { (void)_flags; }

  GUID *guid();
  const GUID *guid() const;
  void set_guid(GUID *value);

  uint32_t *field();
  const uint32_t *field() const;
  void set_field(const uint32_t &value);

  uint32_t *lastModifiedSequenceNumber();
  const uint32_t *lastModifiedSequenceNumber() const;
  void set_lastModifiedSequenceNumber(const uint32_t &value);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  GUID *_data_guid = {};
  uint32_t _data_field = {};
  uint32_t _data_lastModifiedSequenceNumber = {};
};

class ARIAAttributeAnyValue {
public:
  ARIAAttributeAnyValue() { (void)_flags; }

  bool *boolValue();
  const bool *boolValue() const;
  void set_boolValue(const bool &value);

  kiwi::String *stringValue();
  const kiwi::String *stringValue() const;
  void set_stringValue(const kiwi::String &value);

  float *floatValue();
  const float *floatValue() const;
  void set_floatValue(const float &value);

  int32_t *intValue();
  const int32_t *intValue() const;
  void set_intValue(const int32_t &value);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  kiwi::String _data_stringValue = {};
  float _data_floatValue = {};
  int32_t _data_intValue = {};
  bool _data_boolValue = {};
};

class ARIAAttributeData {
public:
  ARIAAttributeData() { (void)_flags; }

  ARIAAttributeDataType *type();
  const ARIAAttributeDataType *type() const;
  void set_type(const ARIAAttributeDataType &value);

  ARIAAttributeAnyValue *value();
  const ARIAAttributeAnyValue *value() const;
  void set_value(ARIAAttributeAnyValue *value);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  ARIAAttributeDataType _data_type = {};
  ARIAAttributeAnyValue *_data_value = {};
};

class ARIAAttributesMap {
public:
  ARIAAttributesMap() { (void)_flags; }

  kiwi::Array<ARIAAttributesMapEntry> *entries();
  const kiwi::Array<ARIAAttributesMapEntry> *entries() const;
  kiwi::Array<ARIAAttributesMapEntry> &set_entries(kiwi::MemoryPool &pool, uint32_t count);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  kiwi::Array<ARIAAttributesMapEntry> _data_entries = {};
};

class ARIAAttributesMapEntry {
public:
  ARIAAttributesMapEntry() { (void)_flags; }

  kiwi::String *attribute();
  const kiwi::String *attribute() const;
  void set_attribute(const kiwi::String &value);

  ARIAAttributeData *value();
  const ARIAAttributeData *value() const;
  void set_value(ARIAAttributeData *value);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  kiwi::String _data_attribute = {};
  ARIAAttributeData *_data_value = {};
};

class HandoffStatusMapEntry {
public:
  HandoffStatusMapEntry() { (void)_flags; }

  GUID *guid();
  const GUID *guid() const;
  void set_guid(GUID *value);

  SectionStatusInfo *handoffStatus();
  const SectionStatusInfo *handoffStatus() const;
  void set_handoffStatus(SectionStatusInfo *value);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  GUID *_data_guid = {};
  SectionStatusInfo *_data_handoffStatus = {};
};

class HandoffStatusMap {
public:
  HandoffStatusMap() { (void)_flags; }

  kiwi::Array<HandoffStatusMapEntry> *entries();
  const kiwi::Array<HandoffStatusMapEntry> *entries() const;
  kiwi::Array<HandoffStatusMapEntry> &set_entries(kiwi::MemoryPool &pool, uint32_t count);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  kiwi::Array<HandoffStatusMapEntry> _data_entries = {};
};

#endif
#ifdef IMPLEMENT_SCHEMA_H

bool BinarySchema::parse(kiwi::ByteBuffer &bb) {
  if (!_schema.parse(bb)) return false;
  _schema.findDefinition("Image", _indexImage);
  _schema.findDefinition("Video", _indexVideo);
  _schema.findDefinition("PaintFilterMessage", _indexPaintFilterMessage);
  _schema.findDefinition("Paint", _indexPaint);
  _schema.findDefinition("FontMetaData", _indexFontMetaData);
  _schema.findDefinition("FontVariation", _indexFontVariation);
  _schema.findDefinition("TextData", _indexTextData);
  _schema.findDefinition("DerivedTextData", _indexDerivedTextData);
  _schema.findDefinition("HyperlinkBox", _indexHyperlinkBox);
  _schema.findDefinition("MentionBox", _indexMentionBox);
  _schema.findDefinition("Baseline", _indexBaseline);
  _schema.findDefinition("Glyph", _indexGlyph);
  _schema.findDefinition("Decoration", _indexDecoration);
  _schema.findDefinition("Blockquote", _indexBlockquote);
  _schema.findDefinition("VectorData", _indexVectorData);
  _schema.findDefinition("GUIDPath", _indexGUIDPath);
  _schema.findDefinition("SymbolData", _indexSymbolData);
  _schema.findDefinition("GUIDPathMapping", _indexGUIDPathMapping);
  _schema.findDefinition("NodeGenerationData", _indexNodeGenerationData);
  _schema.findDefinition("DerivedImmutableFrameData", _indexDerivedImmutableFrameData);
  _schema.findDefinition("AssetRef", _indexAssetRef);
  _schema.findDefinition("StateGroupId", _indexStateGroupId);
  _schema.findDefinition("StyleId", _indexStyleId);
  _schema.findDefinition("SymbolId", _indexSymbolId);
  _schema.findDefinition("VariableID", _indexVariableID);
  _schema.findDefinition("VariableSetID", _indexVariableSetID);
  _schema.findDefinition("SharedSymbolReference", _indexSharedSymbolReference);
  _schema.findDefinition("SharedComponentMasterData", _indexSharedComponentMasterData);
  _schema.findDefinition("InstanceOverrideStash", _indexInstanceOverrideStash);
  _schema.findDefinition("InstanceOverrideStashV2", _indexInstanceOverrideStashV2);
  _schema.findDefinition("Effect", _indexEffect);
  _schema.findDefinition("TransitionInfo", _indexTransitionInfo);
  _schema.findDefinition("PrototypeDevice", _indexPrototypeDevice);
  _schema.findDefinition("OverlayBackgroundAppearance", _indexOverlayBackgroundAppearance);
  _schema.findDefinition("ExportSettings", _indexExportSettings);
  _schema.findDefinition("LayoutGrid", _indexLayoutGrid);
  _schema.findDefinition("Guide", _indexGuide);
  _schema.findDefinition("Path", _indexPath);
  _schema.findDefinition("SharedStyleReference", _indexSharedStyleReference);
  _schema.findDefinition("SharedStyleMasterData", _indexSharedStyleMasterData);
  _schema.findDefinition("ArcData", _indexArcData);
  _schema.findDefinition("SymbolLink", _indexSymbolLink);
  _schema.findDefinition("PluginData", _indexPluginData);
  _schema.findDefinition("PluginRelaunchData", _indexPluginRelaunchData);
  _schema.findDefinition("MultiplayerFieldVersion", _indexMultiplayerFieldVersion);
  _schema.findDefinition("ConnectorEndpoint", _indexConnectorEndpoint);
  _schema.findDefinition("ConnectorControlPoint", _indexConnectorControlPoint);
  _schema.findDefinition("ConnectorTextMidpoint", _indexConnectorTextMidpoint);
  _schema.findDefinition("LibraryMoveInfo", _indexLibraryMoveInfo);
  _schema.findDefinition("LibraryMoveHistoryItem", _indexLibraryMoveHistoryItem);
  _schema.findDefinition("DeveloperRelatedLink", _indexDeveloperRelatedLink);
  _schema.findDefinition("WidgetPointer", _indexWidgetPointer);
  _schema.findDefinition("EditInfo", _indexEditInfo);
  _schema.findDefinition("SectionStatusInfo", _indexSectionStatusInfo);
  _schema.findDefinition("NodeChange", _indexNodeChange);
  _schema.findDefinition("VideoPlayback", _indexVideoPlayback);
  _schema.findDefinition("WidgetHoverStyle", _indexWidgetHoverStyle);
  _schema.findDefinition("WidgetDerivedSubtreeCursor", _indexWidgetDerivedSubtreeCursor);
  _schema.findDefinition("MultiplayerMap", _indexMultiplayerMap);
  _schema.findDefinition("MultiplayerMapEntry", _indexMultiplayerMapEntry);
  _schema.findDefinition("VariableDataMap", _indexVariableDataMap);
  _schema.findDefinition("VariableDataMapEntry", _indexVariableDataMapEntry);
  _schema.findDefinition("VariableModeBySetMap", _indexVariableModeBySetMap);
  _schema.findDefinition("VariableModeBySetMapEntry", _indexVariableModeBySetMapEntry);
  _schema.findDefinition("CodeSyntaxMap", _indexCodeSyntaxMap);
  _schema.findDefinition("CodeSyntaxMapEntry", _indexCodeSyntaxMapEntry);
  _schema.findDefinition("TableRowColumnPositionMap", _indexTableRowColumnPositionMap);
  _schema.findDefinition("TableRowColumnPositionMapEntry", _indexTableRowColumnPositionMapEntry);
  _schema.findDefinition("TableRowColumnSizeMap", _indexTableRowColumnSizeMap);
  _schema.findDefinition("TableRowColumnSizeMapEntry", _indexTableRowColumnSizeMapEntry);
  _schema.findDefinition("AgendaPositionMap", _indexAgendaPositionMap);
  _schema.findDefinition("AgendaPositionMapEntry", _indexAgendaPositionMapEntry);
  _schema.findDefinition("AgendaMetadataMap", _indexAgendaMetadataMap);
  _schema.findDefinition("AgendaMetadataMapEntry", _indexAgendaMetadataMapEntry);
  _schema.findDefinition("AgendaMetadata", _indexAgendaMetadata);
  _schema.findDefinition("AgendaTimerInfo", _indexAgendaTimerInfo);
  _schema.findDefinition("AgendaVoteInfo", _indexAgendaVoteInfo);
  _schema.findDefinition("AgendaMusicInfo", _indexAgendaMusicInfo);
  _schema.findDefinition("ComponentPropRef", _indexComponentPropRef);
  _schema.findDefinition("ComponentPropAssignment", _indexComponentPropAssignment);
  _schema.findDefinition("ComponentPropDef", _indexComponentPropDef);
  _schema.findDefinition("ComponentPropValue", _indexComponentPropValue);
  _schema.findDefinition("ComponentPropPreferredValues", _indexComponentPropPreferredValues);
  _schema.findDefinition("InstanceSwapPreferredValue", _indexInstanceSwapPreferredValue);
  _schema.findDefinition("WidgetMetadata", _indexWidgetMetadata);
  _schema.findDefinition("WidgetPropertyMenuSelectorOption", _indexWidgetPropertyMenuSelectorOption);
  _schema.findDefinition("WidgetPropertyMenuItem", _indexWidgetPropertyMenuItem);
  _schema.findDefinition("InternalDataForTest", _indexInternalDataForTest);
  _schema.findDefinition("StateGroupPropertyValueOrder", _indexStateGroupPropertyValueOrder);
  _schema.findDefinition("TextListData", _indexTextListData);
  _schema.findDefinition("TextLineData", _indexTextLineData);
  _schema.findDefinition("DerivedTextLineData", _indexDerivedTextLineData);
  _schema.findDefinition("PrototypeInteraction", _indexPrototypeInteraction);
  _schema.findDefinition("PrototypeEvent", _indexPrototypeEvent);
  _schema.findDefinition("PrototypeVariableTarget", _indexPrototypeVariableTarget);
  _schema.findDefinition("ConditionalActions", _indexConditionalActions);
  _schema.findDefinition("PrototypeAction", _indexPrototypeAction);
  _schema.findDefinition("PrototypeStartingPoint", _indexPrototypeStartingPoint);
  _schema.findDefinition("KeyTrigger", _indexKeyTrigger);
  _schema.findDefinition("Hyperlink", _indexHyperlink);
  _schema.findDefinition("Mention", _indexMention);
  _schema.findDefinition("EmbedData", _indexEmbedData);
  _schema.findDefinition("StampData", _indexStampData);
  _schema.findDefinition("LinkPreviewData", _indexLinkPreviewData);
  _schema.findDefinition("Viewport", _indexViewport);
  _schema.findDefinition("Mouse", _indexMouse);
  _schema.findDefinition("TriggeredOverlayData", _indexTriggeredOverlayData);
  _schema.findDefinition("PresentedState", _indexPresentedState);
  _schema.findDefinition("TopLevelPlaybackChange", _indexTopLevelPlaybackChange);
  _schema.findDefinition("InstanceStateChange", _indexInstanceStateChange);
  _schema.findDefinition("TextCursor", _indexTextCursor);
  _schema.findDefinition("TextSelection", _indexTextSelection);
  _schema.findDefinition("PlaybackChangeKeyframe", _indexPlaybackChangeKeyframe);
  _schema.findDefinition("StateMapping", _indexStateMapping);
  _schema.findDefinition("ScrollMapping", _indexScrollMapping);
  _schema.findDefinition("PlaybackUpdate", _indexPlaybackUpdate);
  _schema.findDefinition("ChatMessage", _indexChatMessage);
  _schema.findDefinition("VoiceMetadata", _indexVoiceMetadata);
  _schema.findDefinition("UserChange", _indexUserChange);
  _schema.findDefinition("SceneGraphQuery", _indexSceneGraphQuery);
  _schema.findDefinition("NodeChangesMetadata", _indexNodeChangesMetadata);
  _schema.findDefinition("CursorReaction", _indexCursorReaction);
  _schema.findDefinition("TimerInfo", _indexTimerInfo);
  _schema.findDefinition("MusicInfo", _indexMusicInfo);
  _schema.findDefinition("PresenterNomination", _indexPresenterNomination);
  _schema.findDefinition("PresenterInfo", _indexPresenterInfo);
  _schema.findDefinition("ClientBroadcast", _indexClientBroadcast);
  _schema.findDefinition("Message", _indexMessage);
  _schema.findDefinition("DiffChunk", _indexDiffChunk);
  _schema.findDefinition("DiffPayload", _indexDiffPayload);
  _schema.findDefinition("RichMediaData", _indexRichMediaData);
  _schema.findDefinition("VariableAnyValue", _indexVariableAnyValue);
  _schema.findDefinition("Expression", _indexExpression);
  _schema.findDefinition("VariableMapValue", _indexVariableMapValue);
  _schema.findDefinition("VariableMap", _indexVariableMap);
  _schema.findDefinition("VariableData", _indexVariableData);
  _schema.findDefinition("VariableSetMode", _indexVariableSetMode);
  _schema.findDefinition("VariableDataValues", _indexVariableDataValues);
  _schema.findDefinition("VariableDataValuesEntry", _indexVariableDataValuesEntry);
  _schema.findDefinition("OptionalVector", _indexOptionalVector);
  _schema.findDefinition("MigrationStatus", _indexMigrationStatus);
  _schema.findDefinition("NodeFieldMap", _indexNodeFieldMap);
  _schema.findDefinition("NodeFieldMapEntry", _indexNodeFieldMapEntry);
  _schema.findDefinition("ARIAAttributeAnyValue", _indexARIAAttributeAnyValue);
  _schema.findDefinition("ARIAAttributeData", _indexARIAAttributeData);
  _schema.findDefinition("ARIAAttributesMap", _indexARIAAttributesMap);
  _schema.findDefinition("ARIAAttributesMapEntry", _indexARIAAttributesMapEntry);
  _schema.findDefinition("HandoffStatusMapEntry", _indexHandoffStatusMapEntry);
  _schema.findDefinition("HandoffStatusMap", _indexHandoffStatusMap);
  return true;
}

bool BinarySchema::skipImageField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexImage, id);
}

bool BinarySchema::skipVideoField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexVideo, id);
}

bool BinarySchema::skipPaintFilterMessageField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexPaintFilterMessage, id);
}

bool BinarySchema::skipPaintField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexPaint, id);
}

bool BinarySchema::skipFontMetaDataField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexFontMetaData, id);
}

bool BinarySchema::skipFontVariationField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexFontVariation, id);
}

bool BinarySchema::skipTextDataField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexTextData, id);
}

bool BinarySchema::skipDerivedTextDataField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexDerivedTextData, id);
}

bool BinarySchema::skipHyperlinkBoxField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexHyperlinkBox, id);
}

bool BinarySchema::skipMentionBoxField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexMentionBox, id);
}

bool BinarySchema::skipBaselineField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexBaseline, id);
}

bool BinarySchema::skipGlyphField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexGlyph, id);
}

bool BinarySchema::skipDecorationField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexDecoration, id);
}

bool BinarySchema::skipBlockquoteField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexBlockquote, id);
}

bool BinarySchema::skipVectorDataField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexVectorData, id);
}

bool BinarySchema::skipGUIDPathField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexGUIDPath, id);
}

bool BinarySchema::skipSymbolDataField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexSymbolData, id);
}

bool BinarySchema::skipGUIDPathMappingField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexGUIDPathMapping, id);
}

bool BinarySchema::skipNodeGenerationDataField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexNodeGenerationData, id);
}

bool BinarySchema::skipDerivedImmutableFrameDataField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexDerivedImmutableFrameData, id);
}

bool BinarySchema::skipAssetRefField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexAssetRef, id);
}

bool BinarySchema::skipStateGroupIdField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexStateGroupId, id);
}

bool BinarySchema::skipStyleIdField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexStyleId, id);
}

bool BinarySchema::skipSymbolIdField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexSymbolId, id);
}

bool BinarySchema::skipVariableIDField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexVariableID, id);
}

bool BinarySchema::skipVariableSetIDField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexVariableSetID, id);
}

bool BinarySchema::skipSharedSymbolReferenceField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexSharedSymbolReference, id);
}

bool BinarySchema::skipSharedComponentMasterDataField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexSharedComponentMasterData, id);
}

bool BinarySchema::skipInstanceOverrideStashField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexInstanceOverrideStash, id);
}

bool BinarySchema::skipInstanceOverrideStashV2Field(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexInstanceOverrideStashV2, id);
}

bool BinarySchema::skipEffectField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexEffect, id);
}

bool BinarySchema::skipTransitionInfoField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexTransitionInfo, id);
}

bool BinarySchema::skipPrototypeDeviceField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexPrototypeDevice, id);
}

bool BinarySchema::skipOverlayBackgroundAppearanceField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexOverlayBackgroundAppearance, id);
}

bool BinarySchema::skipExportSettingsField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexExportSettings, id);
}

bool BinarySchema::skipLayoutGridField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexLayoutGrid, id);
}

bool BinarySchema::skipGuideField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexGuide, id);
}

bool BinarySchema::skipPathField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexPath, id);
}

bool BinarySchema::skipSharedStyleReferenceField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexSharedStyleReference, id);
}

bool BinarySchema::skipSharedStyleMasterDataField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexSharedStyleMasterData, id);
}

bool BinarySchema::skipArcDataField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexArcData, id);
}

bool BinarySchema::skipSymbolLinkField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexSymbolLink, id);
}

bool BinarySchema::skipPluginDataField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexPluginData, id);
}

bool BinarySchema::skipPluginRelaunchDataField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexPluginRelaunchData, id);
}

bool BinarySchema::skipMultiplayerFieldVersionField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexMultiplayerFieldVersion, id);
}

bool BinarySchema::skipConnectorEndpointField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexConnectorEndpoint, id);
}

bool BinarySchema::skipConnectorControlPointField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexConnectorControlPoint, id);
}

bool BinarySchema::skipConnectorTextMidpointField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexConnectorTextMidpoint, id);
}

bool BinarySchema::skipLibraryMoveInfoField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexLibraryMoveInfo, id);
}

bool BinarySchema::skipLibraryMoveHistoryItemField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexLibraryMoveHistoryItem, id);
}

bool BinarySchema::skipDeveloperRelatedLinkField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexDeveloperRelatedLink, id);
}

bool BinarySchema::skipWidgetPointerField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexWidgetPointer, id);
}

bool BinarySchema::skipEditInfoField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexEditInfo, id);
}

bool BinarySchema::skipSectionStatusInfoField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexSectionStatusInfo, id);
}

bool BinarySchema::skipNodeChangeField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexNodeChange, id);
}

bool BinarySchema::skipVideoPlaybackField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexVideoPlayback, id);
}

bool BinarySchema::skipWidgetHoverStyleField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexWidgetHoverStyle, id);
}

bool BinarySchema::skipWidgetDerivedSubtreeCursorField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexWidgetDerivedSubtreeCursor, id);
}

bool BinarySchema::skipMultiplayerMapField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexMultiplayerMap, id);
}

bool BinarySchema::skipMultiplayerMapEntryField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexMultiplayerMapEntry, id);
}

bool BinarySchema::skipVariableDataMapField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexVariableDataMap, id);
}

bool BinarySchema::skipVariableDataMapEntryField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexVariableDataMapEntry, id);
}

bool BinarySchema::skipVariableModeBySetMapField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexVariableModeBySetMap, id);
}

bool BinarySchema::skipVariableModeBySetMapEntryField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexVariableModeBySetMapEntry, id);
}

bool BinarySchema::skipCodeSyntaxMapField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexCodeSyntaxMap, id);
}

bool BinarySchema::skipCodeSyntaxMapEntryField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexCodeSyntaxMapEntry, id);
}

bool BinarySchema::skipTableRowColumnPositionMapField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexTableRowColumnPositionMap, id);
}

bool BinarySchema::skipTableRowColumnPositionMapEntryField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexTableRowColumnPositionMapEntry, id);
}

bool BinarySchema::skipTableRowColumnSizeMapField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexTableRowColumnSizeMap, id);
}

bool BinarySchema::skipTableRowColumnSizeMapEntryField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexTableRowColumnSizeMapEntry, id);
}

bool BinarySchema::skipAgendaPositionMapField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexAgendaPositionMap, id);
}

bool BinarySchema::skipAgendaPositionMapEntryField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexAgendaPositionMapEntry, id);
}

bool BinarySchema::skipAgendaMetadataMapField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexAgendaMetadataMap, id);
}

bool BinarySchema::skipAgendaMetadataMapEntryField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexAgendaMetadataMapEntry, id);
}

bool BinarySchema::skipAgendaMetadataField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexAgendaMetadata, id);
}

bool BinarySchema::skipAgendaTimerInfoField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexAgendaTimerInfo, id);
}

bool BinarySchema::skipAgendaVoteInfoField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexAgendaVoteInfo, id);
}

bool BinarySchema::skipAgendaMusicInfoField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexAgendaMusicInfo, id);
}

bool BinarySchema::skipComponentPropRefField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexComponentPropRef, id);
}

bool BinarySchema::skipComponentPropAssignmentField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexComponentPropAssignment, id);
}

bool BinarySchema::skipComponentPropDefField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexComponentPropDef, id);
}

bool BinarySchema::skipComponentPropValueField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexComponentPropValue, id);
}

bool BinarySchema::skipComponentPropPreferredValuesField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexComponentPropPreferredValues, id);
}

bool BinarySchema::skipInstanceSwapPreferredValueField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexInstanceSwapPreferredValue, id);
}

bool BinarySchema::skipWidgetMetadataField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexWidgetMetadata, id);
}

bool BinarySchema::skipWidgetPropertyMenuSelectorOptionField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexWidgetPropertyMenuSelectorOption, id);
}

bool BinarySchema::skipWidgetPropertyMenuItemField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexWidgetPropertyMenuItem, id);
}

bool BinarySchema::skipInternalDataForTestField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexInternalDataForTest, id);
}

bool BinarySchema::skipStateGroupPropertyValueOrderField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexStateGroupPropertyValueOrder, id);
}

bool BinarySchema::skipTextListDataField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexTextListData, id);
}

bool BinarySchema::skipTextLineDataField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexTextLineData, id);
}

bool BinarySchema::skipDerivedTextLineDataField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexDerivedTextLineData, id);
}

bool BinarySchema::skipPrototypeInteractionField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexPrototypeInteraction, id);
}

bool BinarySchema::skipPrototypeEventField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexPrototypeEvent, id);
}

bool BinarySchema::skipPrototypeVariableTargetField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexPrototypeVariableTarget, id);
}

bool BinarySchema::skipConditionalActionsField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexConditionalActions, id);
}

bool BinarySchema::skipPrototypeActionField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexPrototypeAction, id);
}

bool BinarySchema::skipPrototypeStartingPointField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexPrototypeStartingPoint, id);
}

bool BinarySchema::skipKeyTriggerField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexKeyTrigger, id);
}

bool BinarySchema::skipHyperlinkField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexHyperlink, id);
}

bool BinarySchema::skipMentionField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexMention, id);
}

bool BinarySchema::skipEmbedDataField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexEmbedData, id);
}

bool BinarySchema::skipStampDataField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexStampData, id);
}

bool BinarySchema::skipLinkPreviewDataField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexLinkPreviewData, id);
}

bool BinarySchema::skipViewportField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexViewport, id);
}

bool BinarySchema::skipMouseField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexMouse, id);
}

bool BinarySchema::skipTriggeredOverlayDataField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexTriggeredOverlayData, id);
}

bool BinarySchema::skipPresentedStateField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexPresentedState, id);
}

bool BinarySchema::skipTopLevelPlaybackChangeField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexTopLevelPlaybackChange, id);
}

bool BinarySchema::skipInstanceStateChangeField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexInstanceStateChange, id);
}

bool BinarySchema::skipTextCursorField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexTextCursor, id);
}

bool BinarySchema::skipTextSelectionField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexTextSelection, id);
}

bool BinarySchema::skipPlaybackChangeKeyframeField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexPlaybackChangeKeyframe, id);
}

bool BinarySchema::skipStateMappingField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexStateMapping, id);
}

bool BinarySchema::skipScrollMappingField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexScrollMapping, id);
}

bool BinarySchema::skipPlaybackUpdateField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexPlaybackUpdate, id);
}

bool BinarySchema::skipChatMessageField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexChatMessage, id);
}

bool BinarySchema::skipVoiceMetadataField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexVoiceMetadata, id);
}

bool BinarySchema::skipUserChangeField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexUserChange, id);
}

bool BinarySchema::skipSceneGraphQueryField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexSceneGraphQuery, id);
}

bool BinarySchema::skipNodeChangesMetadataField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexNodeChangesMetadata, id);
}

bool BinarySchema::skipCursorReactionField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexCursorReaction, id);
}

bool BinarySchema::skipTimerInfoField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexTimerInfo, id);
}

bool BinarySchema::skipMusicInfoField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexMusicInfo, id);
}

bool BinarySchema::skipPresenterNominationField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexPresenterNomination, id);
}

bool BinarySchema::skipPresenterInfoField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexPresenterInfo, id);
}

bool BinarySchema::skipClientBroadcastField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexClientBroadcast, id);
}

bool BinarySchema::skipMessageField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexMessage, id);
}

bool BinarySchema::skipDiffChunkField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexDiffChunk, id);
}

bool BinarySchema::skipDiffPayloadField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexDiffPayload, id);
}

bool BinarySchema::skipRichMediaDataField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexRichMediaData, id);
}

bool BinarySchema::skipVariableAnyValueField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexVariableAnyValue, id);
}

bool BinarySchema::skipExpressionField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexExpression, id);
}

bool BinarySchema::skipVariableMapValueField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexVariableMapValue, id);
}

bool BinarySchema::skipVariableMapField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexVariableMap, id);
}

bool BinarySchema::skipVariableDataField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexVariableData, id);
}

bool BinarySchema::skipVariableSetModeField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexVariableSetMode, id);
}

bool BinarySchema::skipVariableDataValuesField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexVariableDataValues, id);
}

bool BinarySchema::skipVariableDataValuesEntryField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexVariableDataValuesEntry, id);
}

bool BinarySchema::skipOptionalVectorField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexOptionalVector, id);
}

bool BinarySchema::skipMigrationStatusField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexMigrationStatus, id);
}

bool BinarySchema::skipNodeFieldMapField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexNodeFieldMap, id);
}

bool BinarySchema::skipNodeFieldMapEntryField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexNodeFieldMapEntry, id);
}

bool BinarySchema::skipARIAAttributeAnyValueField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexARIAAttributeAnyValue, id);
}

bool BinarySchema::skipARIAAttributeDataField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexARIAAttributeData, id);
}

bool BinarySchema::skipARIAAttributesMapField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexARIAAttributesMap, id);
}

bool BinarySchema::skipARIAAttributesMapEntryField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexARIAAttributesMapEntry, id);
}

bool BinarySchema::skipHandoffStatusMapEntryField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexHandoffStatusMapEntry, id);
}

bool BinarySchema::skipHandoffStatusMapField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexHandoffStatusMap, id);
}

uint32_t *GUID::sessionID() {
  return _flags[0] & 1 ? &_data_sessionID : nullptr;
}

const uint32_t *GUID::sessionID() const {
  return _flags[0] & 1 ? &_data_sessionID : nullptr;
}

void GUID::set_sessionID(const uint32_t &value) {
  _flags[0] |= 1; _data_sessionID = value;
}

uint32_t *GUID::localID() {
  return _flags[0] & 2 ? &_data_localID : nullptr;
}

const uint32_t *GUID::localID() const {
  return _flags[0] & 2 ? &_data_localID : nullptr;
}

void GUID::set_localID(const uint32_t &value) {
  _flags[0] |= 2; _data_localID = value;
}

bool GUID::encode(kiwi::ByteBuffer &_bb) {
  if (sessionID() == nullptr) return false;
  _bb.writeVarUint(_data_sessionID);
  if (localID() == nullptr) return false;
  _bb.writeVarUint(_data_localID);
  return true;
}

bool GUID::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  if (!_bb.readVarUint(_data_sessionID)) return false;
  set_sessionID(_data_sessionID);
  if (!_bb.readVarUint(_data_localID)) return false;
  set_localID(_data_localID);
  return true;
}

float *Color::r() {
  return _flags[0] & 1 ? &_data_r : nullptr;
}

const float *Color::r() const {
  return _flags[0] & 1 ? &_data_r : nullptr;
}

void Color::set_r(const float &value) {
  _flags[0] |= 1; _data_r = value;
}

float *Color::g() {
  return _flags[0] & 2 ? &_data_g : nullptr;
}

const float *Color::g() const {
  return _flags[0] & 2 ? &_data_g : nullptr;
}

void Color::set_g(const float &value) {
  _flags[0] |= 2; _data_g = value;
}

float *Color::b() {
  return _flags[0] & 4 ? &_data_b : nullptr;
}

const float *Color::b() const {
  return _flags[0] & 4 ? &_data_b : nullptr;
}

void Color::set_b(const float &value) {
  _flags[0] |= 4; _data_b = value;
}

float *Color::a() {
  return _flags[0] & 8 ? &_data_a : nullptr;
}

const float *Color::a() const {
  return _flags[0] & 8 ? &_data_a : nullptr;
}

void Color::set_a(const float &value) {
  _flags[0] |= 8; _data_a = value;
}

bool Color::encode(kiwi::ByteBuffer &_bb) {
  if (r() == nullptr) return false;
  _bb.writeVarFloat(_data_r);
  if (g() == nullptr) return false;
  _bb.writeVarFloat(_data_g);
  if (b() == nullptr) return false;
  _bb.writeVarFloat(_data_b);
  if (a() == nullptr) return false;
  _bb.writeVarFloat(_data_a);
  return true;
}

bool Color::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  if (!_bb.readVarFloat(_data_r)) return false;
  set_r(_data_r);
  if (!_bb.readVarFloat(_data_g)) return false;
  set_g(_data_g);
  if (!_bb.readVarFloat(_data_b)) return false;
  set_b(_data_b);
  if (!_bb.readVarFloat(_data_a)) return false;
  set_a(_data_a);
  return true;
}

float *Vector::x() {
  return _flags[0] & 1 ? &_data_x : nullptr;
}

const float *Vector::x() const {
  return _flags[0] & 1 ? &_data_x : nullptr;
}

void Vector::set_x(const float &value) {
  _flags[0] |= 1; _data_x = value;
}

float *Vector::y() {
  return _flags[0] & 2 ? &_data_y : nullptr;
}

const float *Vector::y() const {
  return _flags[0] & 2 ? &_data_y : nullptr;
}

void Vector::set_y(const float &value) {
  _flags[0] |= 2; _data_y = value;
}

bool Vector::encode(kiwi::ByteBuffer &_bb) {
  if (x() == nullptr) return false;
  _bb.writeVarFloat(_data_x);
  if (y() == nullptr) return false;
  _bb.writeVarFloat(_data_y);
  return true;
}

bool Vector::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  if (!_bb.readVarFloat(_data_x)) return false;
  set_x(_data_x);
  if (!_bb.readVarFloat(_data_y)) return false;
  set_y(_data_y);
  return true;
}

float *Rect::x() {
  return _flags[0] & 1 ? &_data_x : nullptr;
}

const float *Rect::x() const {
  return _flags[0] & 1 ? &_data_x : nullptr;
}

void Rect::set_x(const float &value) {
  _flags[0] |= 1; _data_x = value;
}

float *Rect::y() {
  return _flags[0] & 2 ? &_data_y : nullptr;
}

const float *Rect::y() const {
  return _flags[0] & 2 ? &_data_y : nullptr;
}

void Rect::set_y(const float &value) {
  _flags[0] |= 2; _data_y = value;
}

float *Rect::w() {
  return _flags[0] & 4 ? &_data_w : nullptr;
}

const float *Rect::w() const {
  return _flags[0] & 4 ? &_data_w : nullptr;
}

void Rect::set_w(const float &value) {
  _flags[0] |= 4; _data_w = value;
}

float *Rect::h() {
  return _flags[0] & 8 ? &_data_h : nullptr;
}

const float *Rect::h() const {
  return _flags[0] & 8 ? &_data_h : nullptr;
}

void Rect::set_h(const float &value) {
  _flags[0] |= 8; _data_h = value;
}

bool Rect::encode(kiwi::ByteBuffer &_bb) {
  if (x() == nullptr) return false;
  _bb.writeVarFloat(_data_x);
  if (y() == nullptr) return false;
  _bb.writeVarFloat(_data_y);
  if (w() == nullptr) return false;
  _bb.writeVarFloat(_data_w);
  if (h() == nullptr) return false;
  _bb.writeVarFloat(_data_h);
  return true;
}

bool Rect::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  if (!_bb.readVarFloat(_data_x)) return false;
  set_x(_data_x);
  if (!_bb.readVarFloat(_data_y)) return false;
  set_y(_data_y);
  if (!_bb.readVarFloat(_data_w)) return false;
  set_w(_data_w);
  if (!_bb.readVarFloat(_data_h)) return false;
  set_h(_data_h);
  return true;
}

Color *ColorStop::color() {
  return _data_color;
}

const Color *ColorStop::color() const {
  return _data_color;
}

void ColorStop::set_color(Color *value) {
  _data_color = value;
}

float *ColorStop::position() {
  return _flags[0] & 2 ? &_data_position : nullptr;
}

const float *ColorStop::position() const {
  return _flags[0] & 2 ? &_data_position : nullptr;
}

void ColorStop::set_position(const float &value) {
  _flags[0] |= 2; _data_position = value;
}

bool ColorStop::encode(kiwi::ByteBuffer &_bb) {
  if (color() == nullptr) return false;
  if (!_data_color->encode(_bb)) return false;
  if (position() == nullptr) return false;
  _bb.writeVarFloat(_data_position);
  return true;
}

bool ColorStop::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  _data_color = _pool.allocate<Color>();
  if (!_data_color->decode(_bb, _pool, _schema)) return false;
  if (!_bb.readVarFloat(_data_position)) return false;
  set_position(_data_position);
  return true;
}

float *Matrix::m00() {
  return _flags[0] & 1 ? &_data_m00 : nullptr;
}

const float *Matrix::m00() const {
  return _flags[0] & 1 ? &_data_m00 : nullptr;
}

void Matrix::set_m00(const float &value) {
  _flags[0] |= 1; _data_m00 = value;
}

float *Matrix::m01() {
  return _flags[0] & 2 ? &_data_m01 : nullptr;
}

const float *Matrix::m01() const {
  return _flags[0] & 2 ? &_data_m01 : nullptr;
}

void Matrix::set_m01(const float &value) {
  _flags[0] |= 2; _data_m01 = value;
}

float *Matrix::m02() {
  return _flags[0] & 4 ? &_data_m02 : nullptr;
}

const float *Matrix::m02() const {
  return _flags[0] & 4 ? &_data_m02 : nullptr;
}

void Matrix::set_m02(const float &value) {
  _flags[0] |= 4; _data_m02 = value;
}

float *Matrix::m10() {
  return _flags[0] & 8 ? &_data_m10 : nullptr;
}

const float *Matrix::m10() const {
  return _flags[0] & 8 ? &_data_m10 : nullptr;
}

void Matrix::set_m10(const float &value) {
  _flags[0] |= 8; _data_m10 = value;
}

float *Matrix::m11() {
  return _flags[0] & 16 ? &_data_m11 : nullptr;
}

const float *Matrix::m11() const {
  return _flags[0] & 16 ? &_data_m11 : nullptr;
}

void Matrix::set_m11(const float &value) {
  _flags[0] |= 16; _data_m11 = value;
}

float *Matrix::m12() {
  return _flags[0] & 32 ? &_data_m12 : nullptr;
}

const float *Matrix::m12() const {
  return _flags[0] & 32 ? &_data_m12 : nullptr;
}

void Matrix::set_m12(const float &value) {
  _flags[0] |= 32; _data_m12 = value;
}

bool Matrix::encode(kiwi::ByteBuffer &_bb) {
  if (m00() == nullptr) return false;
  _bb.writeVarFloat(_data_m00);
  if (m01() == nullptr) return false;
  _bb.writeVarFloat(_data_m01);
  if (m02() == nullptr) return false;
  _bb.writeVarFloat(_data_m02);
  if (m10() == nullptr) return false;
  _bb.writeVarFloat(_data_m10);
  if (m11() == nullptr) return false;
  _bb.writeVarFloat(_data_m11);
  if (m12() == nullptr) return false;
  _bb.writeVarFloat(_data_m12);
  return true;
}

bool Matrix::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  if (!_bb.readVarFloat(_data_m00)) return false;
  set_m00(_data_m00);
  if (!_bb.readVarFloat(_data_m01)) return false;
  set_m01(_data_m01);
  if (!_bb.readVarFloat(_data_m02)) return false;
  set_m02(_data_m02);
  if (!_bb.readVarFloat(_data_m10)) return false;
  set_m10(_data_m10);
  if (!_bb.readVarFloat(_data_m11)) return false;
  set_m11(_data_m11);
  if (!_bb.readVarFloat(_data_m12)) return false;
  set_m12(_data_m12);
  return true;
}

GUID *ParentIndex::guid() {
  return _data_guid;
}

const GUID *ParentIndex::guid() const {
  return _data_guid;
}

void ParentIndex::set_guid(GUID *value) {
  _data_guid = value;
}

kiwi::String *ParentIndex::position() {
  return _flags[0] & 2 ? &_data_position : nullptr;
}

const kiwi::String *ParentIndex::position() const {
  return _flags[0] & 2 ? &_data_position : nullptr;
}

void ParentIndex::set_position(const kiwi::String &value) {
  _flags[0] |= 2; _data_position = value;
}

bool ParentIndex::encode(kiwi::ByteBuffer &_bb) {
  if (guid() == nullptr) return false;
  if (!_data_guid->encode(_bb)) return false;
  if (position() == nullptr) return false;
  _bb.writeString(_data_position.c_str());
  return true;
}

bool ParentIndex::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  _data_guid = _pool.allocate<GUID>();
  if (!_data_guid->decode(_bb, _pool, _schema)) return false;
  if (!_bb.readString(_data_position, _pool)) return false;
  set_position(_data_position);
  return true;
}

float *Number::value() {
  return _flags[0] & 1 ? &_data_value : nullptr;
}

const float *Number::value() const {
  return _flags[0] & 1 ? &_data_value : nullptr;
}

void Number::set_value(const float &value) {
  _flags[0] |= 1; _data_value = value;
}

NumberUnits *Number::units() {
  return _flags[0] & 2 ? &_data_units : nullptr;
}

const NumberUnits *Number::units() const {
  return _flags[0] & 2 ? &_data_units : nullptr;
}

void Number::set_units(const NumberUnits &value) {
  _flags[0] |= 2; _data_units = value;
}

bool Number::encode(kiwi::ByteBuffer &_bb) {
  if (value() == nullptr) return false;
  _bb.writeVarFloat(_data_value);
  if (units() == nullptr) return false;
  _bb.writeVarUint(static_cast<uint32_t>(_data_units));
  return true;
}

bool Number::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  if (!_bb.readVarFloat(_data_value)) return false;
  set_value(_data_value);
  if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_units))) return false;
  set_units(_data_units);
  return true;
}

kiwi::String *FontName::family() {
  return _flags[0] & 1 ? &_data_family : nullptr;
}

const kiwi::String *FontName::family() const {
  return _flags[0] & 1 ? &_data_family : nullptr;
}

void FontName::set_family(const kiwi::String &value) {
  _flags[0] |= 1; _data_family = value;
}

kiwi::String *FontName::style() {
  return _flags[0] & 2 ? &_data_style : nullptr;
}

const kiwi::String *FontName::style() const {
  return _flags[0] & 2 ? &_data_style : nullptr;
}

void FontName::set_style(const kiwi::String &value) {
  _flags[0] |= 2; _data_style = value;
}

kiwi::String *FontName::postscript() {
  return _flags[0] & 4 ? &_data_postscript : nullptr;
}

const kiwi::String *FontName::postscript() const {
  return _flags[0] & 4 ? &_data_postscript : nullptr;
}

void FontName::set_postscript(const kiwi::String &value) {
  _flags[0] |= 4; _data_postscript = value;
}

bool FontName::encode(kiwi::ByteBuffer &_bb) {
  if (family() == nullptr) return false;
  _bb.writeString(_data_family.c_str());
  if (style() == nullptr) return false;
  _bb.writeString(_data_style.c_str());
  if (postscript() == nullptr) return false;
  _bb.writeString(_data_postscript.c_str());
  return true;
}

bool FontName::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  if (!_bb.readString(_data_family, _pool)) return false;
  set_family(_data_family);
  if (!_bb.readString(_data_style, _pool)) return false;
  set_style(_data_style);
  if (!_bb.readString(_data_postscript, _pool)) return false;
  set_postscript(_data_postscript);
  return true;
}

ExportConstraintType *ExportConstraint::type() {
  return _flags[0] & 1 ? &_data_type : nullptr;
}

const ExportConstraintType *ExportConstraint::type() const {
  return _flags[0] & 1 ? &_data_type : nullptr;
}

void ExportConstraint::set_type(const ExportConstraintType &value) {
  _flags[0] |= 1; _data_type = value;
}

float *ExportConstraint::value() {
  return _flags[0] & 2 ? &_data_value : nullptr;
}

const float *ExportConstraint::value() const {
  return _flags[0] & 2 ? &_data_value : nullptr;
}

void ExportConstraint::set_value(const float &value) {
  _flags[0] |= 2; _data_value = value;
}

bool ExportConstraint::encode(kiwi::ByteBuffer &_bb) {
  if (type() == nullptr) return false;
  _bb.writeVarUint(static_cast<uint32_t>(_data_type));
  if (value() == nullptr) return false;
  _bb.writeVarFloat(_data_value);
  return true;
}

bool ExportConstraint::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_type))) return false;
  set_type(_data_type);
  if (!_bb.readVarFloat(_data_value)) return false;
  set_value(_data_value);
  return true;
}

GUID *GUIDMapping::from() {
  return _data_from;
}

const GUID *GUIDMapping::from() const {
  return _data_from;
}

void GUIDMapping::set_from(GUID *value) {
  _data_from = value;
}

GUID *GUIDMapping::to() {
  return _data_to;
}

const GUID *GUIDMapping::to() const {
  return _data_to;
}

void GUIDMapping::set_to(GUID *value) {
  _data_to = value;
}

bool GUIDMapping::encode(kiwi::ByteBuffer &_bb) {
  if (from() == nullptr) return false;
  if (!_data_from->encode(_bb)) return false;
  if (to() == nullptr) return false;
  if (!_data_to->encode(_bb)) return false;
  return true;
}

bool GUIDMapping::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  _data_from = _pool.allocate<GUID>();
  if (!_data_from->decode(_bb, _pool, _schema)) return false;
  _data_to = _pool.allocate<GUID>();
  if (!_data_to->decode(_bb, _pool, _schema)) return false;
  return true;
}

kiwi::Array<uint8_t> *Blob::bytes() {
  return _flags[0] & 1 ? &_data_bytes : nullptr;
}

const kiwi::Array<uint8_t> *Blob::bytes() const {
  return _flags[0] & 1 ? &_data_bytes : nullptr;
}

kiwi::Array<uint8_t> &Blob::set_bytes(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[0] |= 1; return _data_bytes = pool.array<uint8_t>(count);
}

bool Blob::encode(kiwi::ByteBuffer &_bb) {
  if (bytes() == nullptr) return false;
  _bb.writeVarUint(_data_bytes.size());
  for (uint8_t &_it : _data_bytes) _bb.writeByte(_it);
  return true;
}

bool Blob::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  uint32_t _count;
  if (!_bb.readVarUint(_count)) return false;
  for (uint8_t &_it : set_bytes(_pool, _count)) if (!_bb.readByte(_it)) return false;
  return true;
}

kiwi::Array<uint8_t> *Image::hash() {
  return _flags[0] & 1 ? &_data_hash : nullptr;
}

const kiwi::Array<uint8_t> *Image::hash() const {
  return _flags[0] & 1 ? &_data_hash : nullptr;
}

kiwi::Array<uint8_t> &Image::set_hash(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[0] |= 1; return _data_hash = pool.array<uint8_t>(count);
}

kiwi::String *Image::name() {
  return _flags[0] & 2 ? &_data_name : nullptr;
}

const kiwi::String *Image::name() const {
  return _flags[0] & 2 ? &_data_name : nullptr;
}

void Image::set_name(const kiwi::String &value) {
  _flags[0] |= 2; _data_name = value;
}

uint32_t *Image::dataBlob() {
  return _flags[0] & 4 ? &_data_dataBlob : nullptr;
}

const uint32_t *Image::dataBlob() const {
  return _flags[0] & 4 ? &_data_dataBlob : nullptr;
}

void Image::set_dataBlob(const uint32_t &value) {
  _flags[0] |= 4; _data_dataBlob = value;
}

bool Image::encode(kiwi::ByteBuffer &_bb) {
  if (hash() != nullptr) {
    _bb.writeVarUint(1);
    _bb.writeVarUint(_data_hash.size());
    for (uint8_t &_it : _data_hash) _bb.writeByte(_it);
  }
  if (name() != nullptr) {
    _bb.writeVarUint(2);
    _bb.writeString(_data_name.c_str());
  }
  if (dataBlob() != nullptr) {
    _bb.writeVarUint(3);
    _bb.writeVarUint(_data_dataBlob);
  }
  _bb.writeVarUint(0);
  return true;
}

bool Image::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  uint32_t _count;
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        if (!_bb.readVarUint(_count)) return false;
        for (uint8_t &_it : set_hash(_pool, _count)) if (!_bb.readByte(_it)) return false;
        break;
      }
      case 2: {
        if (!_bb.readString(_data_name, _pool)) return false;
        set_name(_data_name);
        break;
      }
      case 3: {
        if (!_bb.readVarUint(_data_dataBlob)) return false;
        set_dataBlob(_data_dataBlob);
        break;
      }
      default: {
        if (!_schema || !_schema->skipImageField(_bb, _type)) return false;
        break;
      }
    }
  }
}

kiwi::Array<uint8_t> *Video::hash() {
  return _flags[0] & 1 ? &_data_hash : nullptr;
}

const kiwi::Array<uint8_t> *Video::hash() const {
  return _flags[0] & 1 ? &_data_hash : nullptr;
}

kiwi::Array<uint8_t> &Video::set_hash(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[0] |= 1; return _data_hash = pool.array<uint8_t>(count);
}

kiwi::String *Video::s3Url() {
  return _flags[0] & 2 ? &_data_s3Url : nullptr;
}

const kiwi::String *Video::s3Url() const {
  return _flags[0] & 2 ? &_data_s3Url : nullptr;
}

void Video::set_s3Url(const kiwi::String &value) {
  _flags[0] |= 2; _data_s3Url = value;
}

bool Video::encode(kiwi::ByteBuffer &_bb) {
  if (hash() != nullptr) {
    _bb.writeVarUint(1);
    _bb.writeVarUint(_data_hash.size());
    for (uint8_t &_it : _data_hash) _bb.writeByte(_it);
  }
  if (s3Url() != nullptr) {
    _bb.writeVarUint(2);
    _bb.writeString(_data_s3Url.c_str());
  }
  _bb.writeVarUint(0);
  return true;
}

bool Video::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  uint32_t _count;
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        if (!_bb.readVarUint(_count)) return false;
        for (uint8_t &_it : set_hash(_pool, _count)) if (!_bb.readByte(_it)) return false;
        break;
      }
      case 2: {
        if (!_bb.readString(_data_s3Url, _pool)) return false;
        set_s3Url(_data_s3Url);
        break;
      }
      default: {
        if (!_schema || !_schema->skipVideoField(_bb, _type)) return false;
        break;
      }
    }
  }
}

float *FilterColorAdjust::tint() {
  return _flags[0] & 1 ? &_data_tint : nullptr;
}

const float *FilterColorAdjust::tint() const {
  return _flags[0] & 1 ? &_data_tint : nullptr;
}

void FilterColorAdjust::set_tint(const float &value) {
  _flags[0] |= 1; _data_tint = value;
}

float *FilterColorAdjust::shadows() {
  return _flags[0] & 2 ? &_data_shadows : nullptr;
}

const float *FilterColorAdjust::shadows() const {
  return _flags[0] & 2 ? &_data_shadows : nullptr;
}

void FilterColorAdjust::set_shadows(const float &value) {
  _flags[0] |= 2; _data_shadows = value;
}

float *FilterColorAdjust::highlights() {
  return _flags[0] & 4 ? &_data_highlights : nullptr;
}

const float *FilterColorAdjust::highlights() const {
  return _flags[0] & 4 ? &_data_highlights : nullptr;
}

void FilterColorAdjust::set_highlights(const float &value) {
  _flags[0] |= 4; _data_highlights = value;
}

float *FilterColorAdjust::detail() {
  return _flags[0] & 8 ? &_data_detail : nullptr;
}

const float *FilterColorAdjust::detail() const {
  return _flags[0] & 8 ? &_data_detail : nullptr;
}

void FilterColorAdjust::set_detail(const float &value) {
  _flags[0] |= 8; _data_detail = value;
}

float *FilterColorAdjust::exposure() {
  return _flags[0] & 16 ? &_data_exposure : nullptr;
}

const float *FilterColorAdjust::exposure() const {
  return _flags[0] & 16 ? &_data_exposure : nullptr;
}

void FilterColorAdjust::set_exposure(const float &value) {
  _flags[0] |= 16; _data_exposure = value;
}

float *FilterColorAdjust::vignette() {
  return _flags[0] & 32 ? &_data_vignette : nullptr;
}

const float *FilterColorAdjust::vignette() const {
  return _flags[0] & 32 ? &_data_vignette : nullptr;
}

void FilterColorAdjust::set_vignette(const float &value) {
  _flags[0] |= 32; _data_vignette = value;
}

float *FilterColorAdjust::temperature() {
  return _flags[0] & 64 ? &_data_temperature : nullptr;
}

const float *FilterColorAdjust::temperature() const {
  return _flags[0] & 64 ? &_data_temperature : nullptr;
}

void FilterColorAdjust::set_temperature(const float &value) {
  _flags[0] |= 64; _data_temperature = value;
}

float *FilterColorAdjust::vibrance() {
  return _flags[0] & 128 ? &_data_vibrance : nullptr;
}

const float *FilterColorAdjust::vibrance() const {
  return _flags[0] & 128 ? &_data_vibrance : nullptr;
}

void FilterColorAdjust::set_vibrance(const float &value) {
  _flags[0] |= 128; _data_vibrance = value;
}

bool FilterColorAdjust::encode(kiwi::ByteBuffer &_bb) {
  if (tint() == nullptr) return false;
  _bb.writeVarFloat(_data_tint);
  if (shadows() == nullptr) return false;
  _bb.writeVarFloat(_data_shadows);
  if (highlights() == nullptr) return false;
  _bb.writeVarFloat(_data_highlights);
  if (detail() == nullptr) return false;
  _bb.writeVarFloat(_data_detail);
  if (exposure() == nullptr) return false;
  _bb.writeVarFloat(_data_exposure);
  if (vignette() == nullptr) return false;
  _bb.writeVarFloat(_data_vignette);
  if (temperature() == nullptr) return false;
  _bb.writeVarFloat(_data_temperature);
  if (vibrance() == nullptr) return false;
  _bb.writeVarFloat(_data_vibrance);
  return true;
}

bool FilterColorAdjust::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  if (!_bb.readVarFloat(_data_tint)) return false;
  set_tint(_data_tint);
  if (!_bb.readVarFloat(_data_shadows)) return false;
  set_shadows(_data_shadows);
  if (!_bb.readVarFloat(_data_highlights)) return false;
  set_highlights(_data_highlights);
  if (!_bb.readVarFloat(_data_detail)) return false;
  set_detail(_data_detail);
  if (!_bb.readVarFloat(_data_exposure)) return false;
  set_exposure(_data_exposure);
  if (!_bb.readVarFloat(_data_vignette)) return false;
  set_vignette(_data_vignette);
  if (!_bb.readVarFloat(_data_temperature)) return false;
  set_temperature(_data_temperature);
  if (!_bb.readVarFloat(_data_vibrance)) return false;
  set_vibrance(_data_vibrance);
  return true;
}

float *PaintFilterMessage::tint() {
  return _flags[0] & 1 ? &_data_tint : nullptr;
}

const float *PaintFilterMessage::tint() const {
  return _flags[0] & 1 ? &_data_tint : nullptr;
}

void PaintFilterMessage::set_tint(const float &value) {
  _flags[0] |= 1; _data_tint = value;
}

float *PaintFilterMessage::shadows() {
  return _flags[0] & 2 ? &_data_shadows : nullptr;
}

const float *PaintFilterMessage::shadows() const {
  return _flags[0] & 2 ? &_data_shadows : nullptr;
}

void PaintFilterMessage::set_shadows(const float &value) {
  _flags[0] |= 2; _data_shadows = value;
}

float *PaintFilterMessage::highlights() {
  return _flags[0] & 4 ? &_data_highlights : nullptr;
}

const float *PaintFilterMessage::highlights() const {
  return _flags[0] & 4 ? &_data_highlights : nullptr;
}

void PaintFilterMessage::set_highlights(const float &value) {
  _flags[0] |= 4; _data_highlights = value;
}

float *PaintFilterMessage::detail() {
  return _flags[0] & 8 ? &_data_detail : nullptr;
}

const float *PaintFilterMessage::detail() const {
  return _flags[0] & 8 ? &_data_detail : nullptr;
}

void PaintFilterMessage::set_detail(const float &value) {
  _flags[0] |= 8; _data_detail = value;
}

float *PaintFilterMessage::exposure() {
  return _flags[0] & 16 ? &_data_exposure : nullptr;
}

const float *PaintFilterMessage::exposure() const {
  return _flags[0] & 16 ? &_data_exposure : nullptr;
}

void PaintFilterMessage::set_exposure(const float &value) {
  _flags[0] |= 16; _data_exposure = value;
}

float *PaintFilterMessage::vignette() {
  return _flags[0] & 32 ? &_data_vignette : nullptr;
}

const float *PaintFilterMessage::vignette() const {
  return _flags[0] & 32 ? &_data_vignette : nullptr;
}

void PaintFilterMessage::set_vignette(const float &value) {
  _flags[0] |= 32; _data_vignette = value;
}

float *PaintFilterMessage::temperature() {
  return _flags[0] & 64 ? &_data_temperature : nullptr;
}

const float *PaintFilterMessage::temperature() const {
  return _flags[0] & 64 ? &_data_temperature : nullptr;
}

void PaintFilterMessage::set_temperature(const float &value) {
  _flags[0] |= 64; _data_temperature = value;
}

float *PaintFilterMessage::vibrance() {
  return _flags[0] & 128 ? &_data_vibrance : nullptr;
}

const float *PaintFilterMessage::vibrance() const {
  return _flags[0] & 128 ? &_data_vibrance : nullptr;
}

void PaintFilterMessage::set_vibrance(const float &value) {
  _flags[0] |= 128; _data_vibrance = value;
}

float *PaintFilterMessage::contrast() {
  return _flags[0] & 256 ? &_data_contrast : nullptr;
}

const float *PaintFilterMessage::contrast() const {
  return _flags[0] & 256 ? &_data_contrast : nullptr;
}

void PaintFilterMessage::set_contrast(const float &value) {
  _flags[0] |= 256; _data_contrast = value;
}

float *PaintFilterMessage::brightness() {
  return _flags[0] & 512 ? &_data_brightness : nullptr;
}

const float *PaintFilterMessage::brightness() const {
  return _flags[0] & 512 ? &_data_brightness : nullptr;
}

void PaintFilterMessage::set_brightness(const float &value) {
  _flags[0] |= 512; _data_brightness = value;
}

bool PaintFilterMessage::encode(kiwi::ByteBuffer &_bb) {
  if (tint() != nullptr) {
    _bb.writeVarUint(1);
    _bb.writeVarFloat(_data_tint);
  }
  if (shadows() != nullptr) {
    _bb.writeVarUint(2);
    _bb.writeVarFloat(_data_shadows);
  }
  if (highlights() != nullptr) {
    _bb.writeVarUint(3);
    _bb.writeVarFloat(_data_highlights);
  }
  if (detail() != nullptr) {
    _bb.writeVarUint(4);
    _bb.writeVarFloat(_data_detail);
  }
  if (exposure() != nullptr) {
    _bb.writeVarUint(5);
    _bb.writeVarFloat(_data_exposure);
  }
  if (vignette() != nullptr) {
    _bb.writeVarUint(6);
    _bb.writeVarFloat(_data_vignette);
  }
  if (temperature() != nullptr) {
    _bb.writeVarUint(7);
    _bb.writeVarFloat(_data_temperature);
  }
  if (vibrance() != nullptr) {
    _bb.writeVarUint(8);
    _bb.writeVarFloat(_data_vibrance);
  }
  if (contrast() != nullptr) {
    _bb.writeVarUint(9);
    _bb.writeVarFloat(_data_contrast);
  }
  if (brightness() != nullptr) {
    _bb.writeVarUint(10);
    _bb.writeVarFloat(_data_brightness);
  }
  _bb.writeVarUint(0);
  return true;
}

bool PaintFilterMessage::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        if (!_bb.readVarFloat(_data_tint)) return false;
        set_tint(_data_tint);
        break;
      }
      case 2: {
        if (!_bb.readVarFloat(_data_shadows)) return false;
        set_shadows(_data_shadows);
        break;
      }
      case 3: {
        if (!_bb.readVarFloat(_data_highlights)) return false;
        set_highlights(_data_highlights);
        break;
      }
      case 4: {
        if (!_bb.readVarFloat(_data_detail)) return false;
        set_detail(_data_detail);
        break;
      }
      case 5: {
        if (!_bb.readVarFloat(_data_exposure)) return false;
        set_exposure(_data_exposure);
        break;
      }
      case 6: {
        if (!_bb.readVarFloat(_data_vignette)) return false;
        set_vignette(_data_vignette);
        break;
      }
      case 7: {
        if (!_bb.readVarFloat(_data_temperature)) return false;
        set_temperature(_data_temperature);
        break;
      }
      case 8: {
        if (!_bb.readVarFloat(_data_vibrance)) return false;
        set_vibrance(_data_vibrance);
        break;
      }
      case 9: {
        if (!_bb.readVarFloat(_data_contrast)) return false;
        set_contrast(_data_contrast);
        break;
      }
      case 10: {
        if (!_bb.readVarFloat(_data_brightness)) return false;
        set_brightness(_data_brightness);
        break;
      }
      default: {
        if (!_schema || !_schema->skipPaintFilterMessageField(_bb, _type)) return false;
        break;
      }
    }
  }
}

PaintType *Paint::type() {
  return _flags[0] & 1 ? &_data_type : nullptr;
}

const PaintType *Paint::type() const {
  return _flags[0] & 1 ? &_data_type : nullptr;
}

void Paint::set_type(const PaintType &value) {
  _flags[0] |= 1; _data_type = value;
}

Color *Paint::color() {
  return _data_color;
}

const Color *Paint::color() const {
  return _data_color;
}

void Paint::set_color(Color *value) {
  _data_color = value;
}

float *Paint::opacity() {
  return _flags[0] & 4 ? &_data_opacity : nullptr;
}

const float *Paint::opacity() const {
  return _flags[0] & 4 ? &_data_opacity : nullptr;
}

void Paint::set_opacity(const float &value) {
  _flags[0] |= 4; _data_opacity = value;
}

bool *Paint::visible() {
  return _flags[0] & 8 ? &_data_visible : nullptr;
}

const bool *Paint::visible() const {
  return _flags[0] & 8 ? &_data_visible : nullptr;
}

void Paint::set_visible(const bool &value) {
  _flags[0] |= 8; _data_visible = value;
}

BlendMode *Paint::blendMode() {
  return _flags[0] & 16 ? &_data_blendMode : nullptr;
}

const BlendMode *Paint::blendMode() const {
  return _flags[0] & 16 ? &_data_blendMode : nullptr;
}

void Paint::set_blendMode(const BlendMode &value) {
  _flags[0] |= 16; _data_blendMode = value;
}

kiwi::Array<ColorStop> *Paint::stops() {
  return _flags[0] & 32 ? &_data_stops : nullptr;
}

const kiwi::Array<ColorStop> *Paint::stops() const {
  return _flags[0] & 32 ? &_data_stops : nullptr;
}

kiwi::Array<ColorStop> &Paint::set_stops(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[0] |= 32; return _data_stops = pool.array<ColorStop>(count);
}

Matrix *Paint::transform() {
  return _data_transform;
}

const Matrix *Paint::transform() const {
  return _data_transform;
}

void Paint::set_transform(Matrix *value) {
  _data_transform = value;
}

Image *Paint::image() {
  return _data_image;
}

const Image *Paint::image() const {
  return _data_image;
}

void Paint::set_image(Image *value) {
  _data_image = value;
}

Image *Paint::imageThumbnail() {
  return _data_imageThumbnail;
}

const Image *Paint::imageThumbnail() const {
  return _data_imageThumbnail;
}

void Paint::set_imageThumbnail(Image *value) {
  _data_imageThumbnail = value;
}

Image *Paint::animatedImage() {
  return _data_animatedImage;
}

const Image *Paint::animatedImage() const {
  return _data_animatedImage;
}

void Paint::set_animatedImage(Image *value) {
  _data_animatedImage = value;
}

uint32_t *Paint::animationFrame() {
  return _flags[0] & 1024 ? &_data_animationFrame : nullptr;
}

const uint32_t *Paint::animationFrame() const {
  return _flags[0] & 1024 ? &_data_animationFrame : nullptr;
}

void Paint::set_animationFrame(const uint32_t &value) {
  _flags[0] |= 1024; _data_animationFrame = value;
}

ImageScaleMode *Paint::imageScaleMode() {
  return _flags[0] & 2048 ? &_data_imageScaleMode : nullptr;
}

const ImageScaleMode *Paint::imageScaleMode() const {
  return _flags[0] & 2048 ? &_data_imageScaleMode : nullptr;
}

void Paint::set_imageScaleMode(const ImageScaleMode &value) {
  _flags[0] |= 2048; _data_imageScaleMode = value;
}

bool *Paint::imageShouldColorManage() {
  return _flags[0] & 4096 ? &_data_imageShouldColorManage : nullptr;
}

const bool *Paint::imageShouldColorManage() const {
  return _flags[0] & 4096 ? &_data_imageShouldColorManage : nullptr;
}

void Paint::set_imageShouldColorManage(const bool &value) {
  _flags[0] |= 4096; _data_imageShouldColorManage = value;
}

float *Paint::rotation() {
  return _flags[0] & 8192 ? &_data_rotation : nullptr;
}

const float *Paint::rotation() const {
  return _flags[0] & 8192 ? &_data_rotation : nullptr;
}

void Paint::set_rotation(const float &value) {
  _flags[0] |= 8192; _data_rotation = value;
}

float *Paint::scale() {
  return _flags[0] & 16384 ? &_data_scale : nullptr;
}

const float *Paint::scale() const {
  return _flags[0] & 16384 ? &_data_scale : nullptr;
}

void Paint::set_scale(const float &value) {
  _flags[0] |= 16384; _data_scale = value;
}

FilterColorAdjust *Paint::filterColorAdjust() {
  return _data_filterColorAdjust;
}

const FilterColorAdjust *Paint::filterColorAdjust() const {
  return _data_filterColorAdjust;
}

void Paint::set_filterColorAdjust(FilterColorAdjust *value) {
  _data_filterColorAdjust = value;
}

PaintFilterMessage *Paint::paintFilter() {
  return _data_paintFilter;
}

const PaintFilterMessage *Paint::paintFilter() const {
  return _data_paintFilter;
}

void Paint::set_paintFilter(PaintFilterMessage *value) {
  _data_paintFilter = value;
}

kiwi::Array<uint32_t> *Paint::emojiCodePoints() {
  return _flags[0] & 131072 ? &_data_emojiCodePoints : nullptr;
}

const kiwi::Array<uint32_t> *Paint::emojiCodePoints() const {
  return _flags[0] & 131072 ? &_data_emojiCodePoints : nullptr;
}

kiwi::Array<uint32_t> &Paint::set_emojiCodePoints(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[0] |= 131072; return _data_emojiCodePoints = pool.array<uint32_t>(count);
}

Video *Paint::video() {
  return _data_video;
}

const Video *Paint::video() const {
  return _data_video;
}

void Paint::set_video(Video *value) {
  _data_video = value;
}

uint32_t *Paint::originalImageWidth() {
  return _flags[0] & 524288 ? &_data_originalImageWidth : nullptr;
}

const uint32_t *Paint::originalImageWidth() const {
  return _flags[0] & 524288 ? &_data_originalImageWidth : nullptr;
}

void Paint::set_originalImageWidth(const uint32_t &value) {
  _flags[0] |= 524288; _data_originalImageWidth = value;
}

uint32_t *Paint::originalImageHeight() {
  return _flags[0] & 1048576 ? &_data_originalImageHeight : nullptr;
}

const uint32_t *Paint::originalImageHeight() const {
  return _flags[0] & 1048576 ? &_data_originalImageHeight : nullptr;
}

void Paint::set_originalImageHeight(const uint32_t &value) {
  _flags[0] |= 1048576; _data_originalImageHeight = value;
}

VariableData *Paint::colorVar() {
  return _data_colorVar;
}

const VariableData *Paint::colorVar() const {
  return _data_colorVar;
}

void Paint::set_colorVar(VariableData *value) {
  _data_colorVar = value;
}

bool Paint::encode(kiwi::ByteBuffer &_bb) {
  if (type() != nullptr) {
    _bb.writeVarUint(1);
    _bb.writeVarUint(static_cast<uint32_t>(_data_type));
  }
  if (color() != nullptr) {
    _bb.writeVarUint(2);
    if (!_data_color->encode(_bb)) return false;
  }
  if (opacity() != nullptr) {
    _bb.writeVarUint(3);
    _bb.writeVarFloat(_data_opacity);
  }
  if (visible() != nullptr) {
    _bb.writeVarUint(4);
    _bb.writeByte(_data_visible);
  }
  if (blendMode() != nullptr) {
    _bb.writeVarUint(5);
    _bb.writeVarUint(static_cast<uint32_t>(_data_blendMode));
  }
  if (stops() != nullptr) {
    _bb.writeVarUint(6);
    _bb.writeVarUint(_data_stops.size());
    for (ColorStop &_it : _data_stops) if (!_it.encode(_bb)) return false;
  }
  if (transform() != nullptr) {
    _bb.writeVarUint(7);
    if (!_data_transform->encode(_bb)) return false;
  }
  if (image() != nullptr) {
    _bb.writeVarUint(8);
    if (!_data_image->encode(_bb)) return false;
  }
  if (imageThumbnail() != nullptr) {
    _bb.writeVarUint(9);
    if (!_data_imageThumbnail->encode(_bb)) return false;
  }
  if (animatedImage() != nullptr) {
    _bb.writeVarUint(16);
    if (!_data_animatedImage->encode(_bb)) return false;
  }
  if (animationFrame() != nullptr) {
    _bb.writeVarUint(17);
    _bb.writeVarUint(_data_animationFrame);
  }
  if (imageScaleMode() != nullptr) {
    _bb.writeVarUint(10);
    _bb.writeVarUint(static_cast<uint32_t>(_data_imageScaleMode));
  }
  if (imageShouldColorManage() != nullptr) {
    _bb.writeVarUint(22);
    _bb.writeByte(_data_imageShouldColorManage);
  }
  if (rotation() != nullptr) {
    _bb.writeVarUint(11);
    _bb.writeVarFloat(_data_rotation);
  }
  if (scale() != nullptr) {
    _bb.writeVarUint(12);
    _bb.writeVarFloat(_data_scale);
  }
  if (filterColorAdjust() != nullptr) {
    _bb.writeVarUint(13);
    if (!_data_filterColorAdjust->encode(_bb)) return false;
  }
  if (paintFilter() != nullptr) {
    _bb.writeVarUint(14);
    if (!_data_paintFilter->encode(_bb)) return false;
  }
  if (emojiCodePoints() != nullptr) {
    _bb.writeVarUint(15);
    _bb.writeVarUint(_data_emojiCodePoints.size());
    for (uint32_t &_it : _data_emojiCodePoints) _bb.writeVarUint(_it);
  }
  if (video() != nullptr) {
    _bb.writeVarUint(18);
    if (!_data_video->encode(_bb)) return false;
  }
  if (originalImageWidth() != nullptr) {
    _bb.writeVarUint(19);
    _bb.writeVarUint(_data_originalImageWidth);
  }
  if (originalImageHeight() != nullptr) {
    _bb.writeVarUint(20);
    _bb.writeVarUint(_data_originalImageHeight);
  }
  if (colorVar() != nullptr) {
    _bb.writeVarUint(21);
    if (!_data_colorVar->encode(_bb)) return false;
  }
  _bb.writeVarUint(0);
  return true;
}

bool Paint::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  uint32_t _count;
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_type))) return false;
        set_type(_data_type);
        break;
      }
      case 2: {
        _data_color = _pool.allocate<Color>();
        if (!_data_color->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 3: {
        if (!_bb.readVarFloat(_data_opacity)) return false;
        set_opacity(_data_opacity);
        break;
      }
      case 4: {
        if (!_bb.readByte(_data_visible)) return false;
        set_visible(_data_visible);
        break;
      }
      case 5: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_blendMode))) return false;
        set_blendMode(_data_blendMode);
        break;
      }
      case 6: {
        if (!_bb.readVarUint(_count)) return false;
        for (ColorStop &_it : set_stops(_pool, _count)) if (!_it.decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 7: {
        _data_transform = _pool.allocate<Matrix>();
        if (!_data_transform->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 8: {
        _data_image = _pool.allocate<Image>();
        if (!_data_image->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 9: {
        _data_imageThumbnail = _pool.allocate<Image>();
        if (!_data_imageThumbnail->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 16: {
        _data_animatedImage = _pool.allocate<Image>();
        if (!_data_animatedImage->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 17: {
        if (!_bb.readVarUint(_data_animationFrame)) return false;
        set_animationFrame(_data_animationFrame);
        break;
      }
      case 10: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_imageScaleMode))) return false;
        set_imageScaleMode(_data_imageScaleMode);
        break;
      }
      case 22: {
        if (!_bb.readByte(_data_imageShouldColorManage)) return false;
        set_imageShouldColorManage(_data_imageShouldColorManage);
        break;
      }
      case 11: {
        if (!_bb.readVarFloat(_data_rotation)) return false;
        set_rotation(_data_rotation);
        break;
      }
      case 12: {
        if (!_bb.readVarFloat(_data_scale)) return false;
        set_scale(_data_scale);
        break;
      }
      case 13: {
        _data_filterColorAdjust = _pool.allocate<FilterColorAdjust>();
        if (!_data_filterColorAdjust->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 14: {
        _data_paintFilter = _pool.allocate<PaintFilterMessage>();
        if (!_data_paintFilter->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 15: {
        if (!_bb.readVarUint(_count)) return false;
        for (uint32_t &_it : set_emojiCodePoints(_pool, _count)) if (!_bb.readVarUint(_it)) return false;
        break;
      }
      case 18: {
        _data_video = _pool.allocate<Video>();
        if (!_data_video->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 19: {
        if (!_bb.readVarUint(_data_originalImageWidth)) return false;
        set_originalImageWidth(_data_originalImageWidth);
        break;
      }
      case 20: {
        if (!_bb.readVarUint(_data_originalImageHeight)) return false;
        set_originalImageHeight(_data_originalImageHeight);
        break;
      }
      case 21: {
        _data_colorVar = _pool.allocate<VariableData>();
        if (!_data_colorVar->decode(_bb, _pool, _schema)) return false;
        break;
      }
      default: {
        if (!_schema || !_schema->skipPaintField(_bb, _type)) return false;
        break;
      }
    }
  }
}

FontName *FontMetaData::key() {
  return _data_key;
}

const FontName *FontMetaData::key() const {
  return _data_key;
}

void FontMetaData::set_key(FontName *value) {
  _data_key = value;
}

float *FontMetaData::fontLineHeight() {
  return _flags[0] & 2 ? &_data_fontLineHeight : nullptr;
}

const float *FontMetaData::fontLineHeight() const {
  return _flags[0] & 2 ? &_data_fontLineHeight : nullptr;
}

void FontMetaData::set_fontLineHeight(const float &value) {
  _flags[0] |= 2; _data_fontLineHeight = value;
}

kiwi::Array<uint8_t> *FontMetaData::fontDigest() {
  return _flags[0] & 4 ? &_data_fontDigest : nullptr;
}

const kiwi::Array<uint8_t> *FontMetaData::fontDigest() const {
  return _flags[0] & 4 ? &_data_fontDigest : nullptr;
}

kiwi::Array<uint8_t> &FontMetaData::set_fontDigest(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[0] |= 4; return _data_fontDigest = pool.array<uint8_t>(count);
}

FontStyle *FontMetaData::fontStyle() {
  return _flags[0] & 8 ? &_data_fontStyle : nullptr;
}

const FontStyle *FontMetaData::fontStyle() const {
  return _flags[0] & 8 ? &_data_fontStyle : nullptr;
}

void FontMetaData::set_fontStyle(const FontStyle &value) {
  _flags[0] |= 8; _data_fontStyle = value;
}

int32_t *FontMetaData::fontWeight() {
  return _flags[0] & 16 ? &_data_fontWeight : nullptr;
}

const int32_t *FontMetaData::fontWeight() const {
  return _flags[0] & 16 ? &_data_fontWeight : nullptr;
}

void FontMetaData::set_fontWeight(const int32_t &value) {
  _flags[0] |= 16; _data_fontWeight = value;
}

bool FontMetaData::encode(kiwi::ByteBuffer &_bb) {
  if (key() != nullptr) {
    _bb.writeVarUint(1);
    if (!_data_key->encode(_bb)) return false;
  }
  if (fontLineHeight() != nullptr) {
    _bb.writeVarUint(2);
    _bb.writeVarFloat(_data_fontLineHeight);
  }
  if (fontDigest() != nullptr) {
    _bb.writeVarUint(3);
    _bb.writeVarUint(_data_fontDigest.size());
    for (uint8_t &_it : _data_fontDigest) _bb.writeByte(_it);
  }
  if (fontStyle() != nullptr) {
    _bb.writeVarUint(4);
    _bb.writeVarUint(static_cast<uint32_t>(_data_fontStyle));
  }
  if (fontWeight() != nullptr) {
    _bb.writeVarUint(5);
    _bb.writeVarInt(_data_fontWeight);
  }
  _bb.writeVarUint(0);
  return true;
}

bool FontMetaData::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  uint32_t _count;
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        _data_key = _pool.allocate<FontName>();
        if (!_data_key->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 2: {
        if (!_bb.readVarFloat(_data_fontLineHeight)) return false;
        set_fontLineHeight(_data_fontLineHeight);
        break;
      }
      case 3: {
        if (!_bb.readVarUint(_count)) return false;
        for (uint8_t &_it : set_fontDigest(_pool, _count)) if (!_bb.readByte(_it)) return false;
        break;
      }
      case 4: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_fontStyle))) return false;
        set_fontStyle(_data_fontStyle);
        break;
      }
      case 5: {
        if (!_bb.readVarInt(_data_fontWeight)) return false;
        set_fontWeight(_data_fontWeight);
        break;
      }
      default: {
        if (!_schema || !_schema->skipFontMetaDataField(_bb, _type)) return false;
        break;
      }
    }
  }
}

uint32_t *FontVariation::axisTag() {
  return _flags[0] & 1 ? &_data_axisTag : nullptr;
}

const uint32_t *FontVariation::axisTag() const {
  return _flags[0] & 1 ? &_data_axisTag : nullptr;
}

void FontVariation::set_axisTag(const uint32_t &value) {
  _flags[0] |= 1; _data_axisTag = value;
}

kiwi::String *FontVariation::axisName() {
  return _flags[0] & 2 ? &_data_axisName : nullptr;
}

const kiwi::String *FontVariation::axisName() const {
  return _flags[0] & 2 ? &_data_axisName : nullptr;
}

void FontVariation::set_axisName(const kiwi::String &value) {
  _flags[0] |= 2; _data_axisName = value;
}

float *FontVariation::value() {
  return _flags[0] & 4 ? &_data_value : nullptr;
}

const float *FontVariation::value() const {
  return _flags[0] & 4 ? &_data_value : nullptr;
}

void FontVariation::set_value(const float &value) {
  _flags[0] |= 4; _data_value = value;
}

bool FontVariation::encode(kiwi::ByteBuffer &_bb) {
  if (axisTag() != nullptr) {
    _bb.writeVarUint(1);
    _bb.writeVarUint(_data_axisTag);
  }
  if (axisName() != nullptr) {
    _bb.writeVarUint(2);
    _bb.writeString(_data_axisName.c_str());
  }
  if (value() != nullptr) {
    _bb.writeVarUint(3);
    _bb.writeVarFloat(_data_value);
  }
  _bb.writeVarUint(0);
  return true;
}

bool FontVariation::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        if (!_bb.readVarUint(_data_axisTag)) return false;
        set_axisTag(_data_axisTag);
        break;
      }
      case 2: {
        if (!_bb.readString(_data_axisName, _pool)) return false;
        set_axisName(_data_axisName);
        break;
      }
      case 3: {
        if (!_bb.readVarFloat(_data_value)) return false;
        set_value(_data_value);
        break;
      }
      default: {
        if (!_schema || !_schema->skipFontVariationField(_bb, _type)) return false;
        break;
      }
    }
  }
}

kiwi::String *TextData::characters() {
  return _flags[0] & 1 ? &_data_characters : nullptr;
}

const kiwi::String *TextData::characters() const {
  return _flags[0] & 1 ? &_data_characters : nullptr;
}

void TextData::set_characters(const kiwi::String &value) {
  _flags[0] |= 1; _data_characters = value;
}

kiwi::Array<uint32_t> *TextData::characterStyleIDs() {
  return _flags[0] & 2 ? &_data_characterStyleIDs : nullptr;
}

const kiwi::Array<uint32_t> *TextData::characterStyleIDs() const {
  return _flags[0] & 2 ? &_data_characterStyleIDs : nullptr;
}

kiwi::Array<uint32_t> &TextData::set_characterStyleIDs(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[0] |= 2; return _data_characterStyleIDs = pool.array<uint32_t>(count);
}

kiwi::Array<NodeChange> *TextData::styleOverrideTable() {
  return _flags[0] & 4 ? &_data_styleOverrideTable : nullptr;
}

const kiwi::Array<NodeChange> *TextData::styleOverrideTable() const {
  return _flags[0] & 4 ? &_data_styleOverrideTable : nullptr;
}

kiwi::Array<NodeChange> &TextData::set_styleOverrideTable(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[0] |= 4; return _data_styleOverrideTable = pool.array<NodeChange>(count);
}

Vector *TextData::layoutSize() {
  return _data_layoutSize;
}

const Vector *TextData::layoutSize() const {
  return _data_layoutSize;
}

void TextData::set_layoutSize(Vector *value) {
  _data_layoutSize = value;
}

kiwi::Array<Baseline> *TextData::baselines() {
  return _flags[0] & 16 ? &_data_baselines : nullptr;
}

const kiwi::Array<Baseline> *TextData::baselines() const {
  return _flags[0] & 16 ? &_data_baselines : nullptr;
}

kiwi::Array<Baseline> &TextData::set_baselines(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[0] |= 16; return _data_baselines = pool.array<Baseline>(count);
}

kiwi::Array<Glyph> *TextData::glyphs() {
  return _flags[0] & 32 ? &_data_glyphs : nullptr;
}

const kiwi::Array<Glyph> *TextData::glyphs() const {
  return _flags[0] & 32 ? &_data_glyphs : nullptr;
}

kiwi::Array<Glyph> &TextData::set_glyphs(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[0] |= 32; return _data_glyphs = pool.array<Glyph>(count);
}

kiwi::Array<Decoration> *TextData::decorations() {
  return _flags[0] & 64 ? &_data_decorations : nullptr;
}

const kiwi::Array<Decoration> *TextData::decorations() const {
  return _flags[0] & 64 ? &_data_decorations : nullptr;
}

kiwi::Array<Decoration> &TextData::set_decorations(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[0] |= 64; return _data_decorations = pool.array<Decoration>(count);
}

kiwi::Array<Blockquote> *TextData::blockquotes() {
  return _flags[0] & 128 ? &_data_blockquotes : nullptr;
}

const kiwi::Array<Blockquote> *TextData::blockquotes() const {
  return _flags[0] & 128 ? &_data_blockquotes : nullptr;
}

kiwi::Array<Blockquote> &TextData::set_blockquotes(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[0] |= 128; return _data_blockquotes = pool.array<Blockquote>(count);
}

uint32_t *TextData::layoutVersion() {
  return _flags[0] & 256 ? &_data_layoutVersion : nullptr;
}

const uint32_t *TextData::layoutVersion() const {
  return _flags[0] & 256 ? &_data_layoutVersion : nullptr;
}

void TextData::set_layoutVersion(const uint32_t &value) {
  _flags[0] |= 256; _data_layoutVersion = value;
}

kiwi::Array<FontMetaData> *TextData::fontMetaData() {
  return _flags[0] & 512 ? &_data_fontMetaData : nullptr;
}

const kiwi::Array<FontMetaData> *TextData::fontMetaData() const {
  return _flags[0] & 512 ? &_data_fontMetaData : nullptr;
}

kiwi::Array<FontMetaData> &TextData::set_fontMetaData(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[0] |= 512; return _data_fontMetaData = pool.array<FontMetaData>(count);
}

kiwi::Array<FontName> *TextData::fallbackFonts() {
  return _flags[0] & 1024 ? &_data_fallbackFonts : nullptr;
}

const kiwi::Array<FontName> *TextData::fallbackFonts() const {
  return _flags[0] & 1024 ? &_data_fallbackFonts : nullptr;
}

kiwi::Array<FontName> &TextData::set_fallbackFonts(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[0] |= 1024; return _data_fallbackFonts = pool.array<FontName>(count);
}

kiwi::Array<HyperlinkBox> *TextData::hyperlinkBoxes() {
  return _flags[0] & 2048 ? &_data_hyperlinkBoxes : nullptr;
}

const kiwi::Array<HyperlinkBox> *TextData::hyperlinkBoxes() const {
  return _flags[0] & 2048 ? &_data_hyperlinkBoxes : nullptr;
}

kiwi::Array<HyperlinkBox> &TextData::set_hyperlinkBoxes(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[0] |= 2048; return _data_hyperlinkBoxes = pool.array<HyperlinkBox>(count);
}

kiwi::Array<TextLineData> *TextData::lines() {
  return _flags[0] & 4096 ? &_data_lines : nullptr;
}

const kiwi::Array<TextLineData> *TextData::lines() const {
  return _flags[0] & 4096 ? &_data_lines : nullptr;
}

kiwi::Array<TextLineData> &TextData::set_lines(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[0] |= 4096; return _data_lines = pool.array<TextLineData>(count);
}

int32_t *TextData::truncationStartIndex() {
  return _flags[0] & 8192 ? &_data_truncationStartIndex : nullptr;
}

const int32_t *TextData::truncationStartIndex() const {
  return _flags[0] & 8192 ? &_data_truncationStartIndex : nullptr;
}

void TextData::set_truncationStartIndex(const int32_t &value) {
  _flags[0] |= 8192; _data_truncationStartIndex = value;
}

float *TextData::truncatedHeight() {
  return _flags[0] & 16384 ? &_data_truncatedHeight : nullptr;
}

const float *TextData::truncatedHeight() const {
  return _flags[0] & 16384 ? &_data_truncatedHeight : nullptr;
}

void TextData::set_truncatedHeight(const float &value) {
  _flags[0] |= 16384; _data_truncatedHeight = value;
}

kiwi::Array<float> *TextData::logicalIndexToCharacterOffsetMap() {
  return _flags[0] & 32768 ? &_data_logicalIndexToCharacterOffsetMap : nullptr;
}

const kiwi::Array<float> *TextData::logicalIndexToCharacterOffsetMap() const {
  return _flags[0] & 32768 ? &_data_logicalIndexToCharacterOffsetMap : nullptr;
}

kiwi::Array<float> &TextData::set_logicalIndexToCharacterOffsetMap(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[0] |= 32768; return _data_logicalIndexToCharacterOffsetMap = pool.array<float>(count);
}

float *TextData::minContentHeight() {
  return _flags[0] & 65536 ? &_data_minContentHeight : nullptr;
}

const float *TextData::minContentHeight() const {
  return _flags[0] & 65536 ? &_data_minContentHeight : nullptr;
}

void TextData::set_minContentHeight(const float &value) {
  _flags[0] |= 65536; _data_minContentHeight = value;
}

kiwi::Array<MentionBox> *TextData::mentionBoxes() {
  return _flags[0] & 131072 ? &_data_mentionBoxes : nullptr;
}

const kiwi::Array<MentionBox> *TextData::mentionBoxes() const {
  return _flags[0] & 131072 ? &_data_mentionBoxes : nullptr;
}

kiwi::Array<MentionBox> &TextData::set_mentionBoxes(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[0] |= 131072; return _data_mentionBoxes = pool.array<MentionBox>(count);
}

kiwi::Array<DerivedTextLineData> *TextData::derivedLines() {
  return _flags[0] & 262144 ? &_data_derivedLines : nullptr;
}

const kiwi::Array<DerivedTextLineData> *TextData::derivedLines() const {
  return _flags[0] & 262144 ? &_data_derivedLines : nullptr;
}

kiwi::Array<DerivedTextLineData> &TextData::set_derivedLines(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[0] |= 262144; return _data_derivedLines = pool.array<DerivedTextLineData>(count);
}

bool TextData::encode(kiwi::ByteBuffer &_bb) {
  if (characters() != nullptr) {
    _bb.writeVarUint(1);
    _bb.writeString(_data_characters.c_str());
  }
  if (characterStyleIDs() != nullptr) {
    _bb.writeVarUint(2);
    _bb.writeVarUint(_data_characterStyleIDs.size());
    for (uint32_t &_it : _data_characterStyleIDs) _bb.writeVarUint(_it);
  }
  if (styleOverrideTable() != nullptr) {
    _bb.writeVarUint(3);
    _bb.writeVarUint(_data_styleOverrideTable.size());
    for (NodeChange &_it : _data_styleOverrideTable) if (!_it.encode(_bb)) return false;
  }
  if (layoutSize() != nullptr) {
    _bb.writeVarUint(4);
    if (!_data_layoutSize->encode(_bb)) return false;
  }
  if (baselines() != nullptr) {
    _bb.writeVarUint(5);
    _bb.writeVarUint(_data_baselines.size());
    for (Baseline &_it : _data_baselines) if (!_it.encode(_bb)) return false;
  }
  if (glyphs() != nullptr) {
    _bb.writeVarUint(6);
    _bb.writeVarUint(_data_glyphs.size());
    for (Glyph &_it : _data_glyphs) if (!_it.encode(_bb)) return false;
  }
  if (decorations() != nullptr) {
    _bb.writeVarUint(7);
    _bb.writeVarUint(_data_decorations.size());
    for (Decoration &_it : _data_decorations) if (!_it.encode(_bb)) return false;
  }
  if (blockquotes() != nullptr) {
    _bb.writeVarUint(16);
    _bb.writeVarUint(_data_blockquotes.size());
    for (Blockquote &_it : _data_blockquotes) if (!_it.encode(_bb)) return false;
  }
  if (layoutVersion() != nullptr) {
    _bb.writeVarUint(8);
    _bb.writeVarUint(_data_layoutVersion);
  }
  if (fontMetaData() != nullptr) {
    _bb.writeVarUint(9);
    _bb.writeVarUint(_data_fontMetaData.size());
    for (FontMetaData &_it : _data_fontMetaData) if (!_it.encode(_bb)) return false;
  }
  if (fallbackFonts() != nullptr) {
    _bb.writeVarUint(10);
    _bb.writeVarUint(_data_fallbackFonts.size());
    for (FontName &_it : _data_fallbackFonts) if (!_it.encode(_bb)) return false;
  }
  if (hyperlinkBoxes() != nullptr) {
    _bb.writeVarUint(11);
    _bb.writeVarUint(_data_hyperlinkBoxes.size());
    for (HyperlinkBox &_it : _data_hyperlinkBoxes) if (!_it.encode(_bb)) return false;
  }
  if (lines() != nullptr) {
    _bb.writeVarUint(12);
    _bb.writeVarUint(_data_lines.size());
    for (TextLineData &_it : _data_lines) if (!_it.encode(_bb)) return false;
  }
  if (truncationStartIndex() != nullptr) {
    _bb.writeVarUint(13);
    _bb.writeVarInt(_data_truncationStartIndex);
  }
  if (truncatedHeight() != nullptr) {
    _bb.writeVarUint(14);
    _bb.writeVarFloat(_data_truncatedHeight);
  }
  if (logicalIndexToCharacterOffsetMap() != nullptr) {
    _bb.writeVarUint(15);
    _bb.writeVarUint(_data_logicalIndexToCharacterOffsetMap.size());
    for (float &_it : _data_logicalIndexToCharacterOffsetMap) _bb.writeVarFloat(_it);
  }
  if (minContentHeight() != nullptr) {
    _bb.writeVarUint(17);
    _bb.writeVarFloat(_data_minContentHeight);
  }
  if (mentionBoxes() != nullptr) {
    _bb.writeVarUint(18);
    _bb.writeVarUint(_data_mentionBoxes.size());
    for (MentionBox &_it : _data_mentionBoxes) if (!_it.encode(_bb)) return false;
  }
  if (derivedLines() != nullptr) {
    _bb.writeVarUint(19);
    _bb.writeVarUint(_data_derivedLines.size());
    for (DerivedTextLineData &_it : _data_derivedLines) if (!_it.encode(_bb)) return false;
  }
  _bb.writeVarUint(0);
  return true;
}

bool TextData::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  uint32_t _count;
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        if (!_bb.readString(_data_characters, _pool)) return false;
        set_characters(_data_characters);
        break;
      }
      case 2: {
        if (!_bb.readVarUint(_count)) return false;
        for (uint32_t &_it : set_characterStyleIDs(_pool, _count)) if (!_bb.readVarUint(_it)) return false;
        break;
      }
      case 3: {
        if (!_bb.readVarUint(_count)) return false;
        for (NodeChange &_it : set_styleOverrideTable(_pool, _count)) if (!_it.decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 4: {
        _data_layoutSize = _pool.allocate<Vector>();
        if (!_data_layoutSize->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 5: {
        if (!_bb.readVarUint(_count)) return false;
        for (Baseline &_it : set_baselines(_pool, _count)) if (!_it.decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 6: {
        if (!_bb.readVarUint(_count)) return false;
        for (Glyph &_it : set_glyphs(_pool, _count)) if (!_it.decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 7: {
        if (!_bb.readVarUint(_count)) return false;
        for (Decoration &_it : set_decorations(_pool, _count)) if (!_it.decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 16: {
        if (!_bb.readVarUint(_count)) return false;
        for (Blockquote &_it : set_blockquotes(_pool, _count)) if (!_it.decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 8: {
        if (!_bb.readVarUint(_data_layoutVersion)) return false;
        set_layoutVersion(_data_layoutVersion);
        break;
      }
      case 9: {
        if (!_bb.readVarUint(_count)) return false;
        for (FontMetaData &_it : set_fontMetaData(_pool, _count)) if (!_it.decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 10: {
        if (!_bb.readVarUint(_count)) return false;
        for (FontName &_it : set_fallbackFonts(_pool, _count)) if (!_it.decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 11: {
        if (!_bb.readVarUint(_count)) return false;
        for (HyperlinkBox &_it : set_hyperlinkBoxes(_pool, _count)) if (!_it.decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 12: {
        if (!_bb.readVarUint(_count)) return false;
        for (TextLineData &_it : set_lines(_pool, _count)) if (!_it.decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 13: {
        if (!_bb.readVarInt(_data_truncationStartIndex)) return false;
        set_truncationStartIndex(_data_truncationStartIndex);
        break;
      }
      case 14: {
        if (!_bb.readVarFloat(_data_truncatedHeight)) return false;
        set_truncatedHeight(_data_truncatedHeight);
        break;
      }
      case 15: {
        if (!_bb.readVarUint(_count)) return false;
        for (float &_it : set_logicalIndexToCharacterOffsetMap(_pool, _count)) if (!_bb.readVarFloat(_it)) return false;
        break;
      }
      case 17: {
        if (!_bb.readVarFloat(_data_minContentHeight)) return false;
        set_minContentHeight(_data_minContentHeight);
        break;
      }
      case 18: {
        if (!_bb.readVarUint(_count)) return false;
        for (MentionBox &_it : set_mentionBoxes(_pool, _count)) if (!_it.decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 19: {
        if (!_bb.readVarUint(_count)) return false;
        for (DerivedTextLineData &_it : set_derivedLines(_pool, _count)) if (!_it.decode(_bb, _pool, _schema)) return false;
        break;
      }
      default: {
        if (!_schema || !_schema->skipTextDataField(_bb, _type)) return false;
        break;
      }
    }
  }
}

Vector *DerivedTextData::layoutSize() {
  return _data_layoutSize;
}

const Vector *DerivedTextData::layoutSize() const {
  return _data_layoutSize;
}

void DerivedTextData::set_layoutSize(Vector *value) {
  _data_layoutSize = value;
}

kiwi::Array<Baseline> *DerivedTextData::baselines() {
  return _flags[0] & 2 ? &_data_baselines : nullptr;
}

const kiwi::Array<Baseline> *DerivedTextData::baselines() const {
  return _flags[0] & 2 ? &_data_baselines : nullptr;
}

kiwi::Array<Baseline> &DerivedTextData::set_baselines(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[0] |= 2; return _data_baselines = pool.array<Baseline>(count);
}

kiwi::Array<Glyph> *DerivedTextData::glyphs() {
  return _flags[0] & 4 ? &_data_glyphs : nullptr;
}

const kiwi::Array<Glyph> *DerivedTextData::glyphs() const {
  return _flags[0] & 4 ? &_data_glyphs : nullptr;
}

kiwi::Array<Glyph> &DerivedTextData::set_glyphs(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[0] |= 4; return _data_glyphs = pool.array<Glyph>(count);
}

kiwi::Array<Decoration> *DerivedTextData::decorations() {
  return _flags[0] & 8 ? &_data_decorations : nullptr;
}

const kiwi::Array<Decoration> *DerivedTextData::decorations() const {
  return _flags[0] & 8 ? &_data_decorations : nullptr;
}

kiwi::Array<Decoration> &DerivedTextData::set_decorations(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[0] |= 8; return _data_decorations = pool.array<Decoration>(count);
}

kiwi::Array<Blockquote> *DerivedTextData::blockquotes() {
  return _flags[0] & 16 ? &_data_blockquotes : nullptr;
}

const kiwi::Array<Blockquote> *DerivedTextData::blockquotes() const {
  return _flags[0] & 16 ? &_data_blockquotes : nullptr;
}

kiwi::Array<Blockquote> &DerivedTextData::set_blockquotes(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[0] |= 16; return _data_blockquotes = pool.array<Blockquote>(count);
}

kiwi::Array<FontMetaData> *DerivedTextData::fontMetaData() {
  return _flags[0] & 32 ? &_data_fontMetaData : nullptr;
}

const kiwi::Array<FontMetaData> *DerivedTextData::fontMetaData() const {
  return _flags[0] & 32 ? &_data_fontMetaData : nullptr;
}

kiwi::Array<FontMetaData> &DerivedTextData::set_fontMetaData(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[0] |= 32; return _data_fontMetaData = pool.array<FontMetaData>(count);
}

kiwi::Array<HyperlinkBox> *DerivedTextData::hyperlinkBoxes() {
  return _flags[0] & 64 ? &_data_hyperlinkBoxes : nullptr;
}

const kiwi::Array<HyperlinkBox> *DerivedTextData::hyperlinkBoxes() const {
  return _flags[0] & 64 ? &_data_hyperlinkBoxes : nullptr;
}

kiwi::Array<HyperlinkBox> &DerivedTextData::set_hyperlinkBoxes(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[0] |= 64; return _data_hyperlinkBoxes = pool.array<HyperlinkBox>(count);
}

int32_t *DerivedTextData::truncationStartIndex() {
  return _flags[0] & 128 ? &_data_truncationStartIndex : nullptr;
}

const int32_t *DerivedTextData::truncationStartIndex() const {
  return _flags[0] & 128 ? &_data_truncationStartIndex : nullptr;
}

void DerivedTextData::set_truncationStartIndex(const int32_t &value) {
  _flags[0] |= 128; _data_truncationStartIndex = value;
}

float *DerivedTextData::truncatedHeight() {
  return _flags[0] & 256 ? &_data_truncatedHeight : nullptr;
}

const float *DerivedTextData::truncatedHeight() const {
  return _flags[0] & 256 ? &_data_truncatedHeight : nullptr;
}

void DerivedTextData::set_truncatedHeight(const float &value) {
  _flags[0] |= 256; _data_truncatedHeight = value;
}

kiwi::Array<float> *DerivedTextData::logicalIndexToCharacterOffsetMap() {
  return _flags[0] & 512 ? &_data_logicalIndexToCharacterOffsetMap : nullptr;
}

const kiwi::Array<float> *DerivedTextData::logicalIndexToCharacterOffsetMap() const {
  return _flags[0] & 512 ? &_data_logicalIndexToCharacterOffsetMap : nullptr;
}

kiwi::Array<float> &DerivedTextData::set_logicalIndexToCharacterOffsetMap(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[0] |= 512; return _data_logicalIndexToCharacterOffsetMap = pool.array<float>(count);
}

kiwi::Array<MentionBox> *DerivedTextData::mentionBoxes() {
  return _flags[0] & 1024 ? &_data_mentionBoxes : nullptr;
}

const kiwi::Array<MentionBox> *DerivedTextData::mentionBoxes() const {
  return _flags[0] & 1024 ? &_data_mentionBoxes : nullptr;
}

kiwi::Array<MentionBox> &DerivedTextData::set_mentionBoxes(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[0] |= 1024; return _data_mentionBoxes = pool.array<MentionBox>(count);
}

kiwi::Array<DerivedTextLineData> *DerivedTextData::derivedLines() {
  return _flags[0] & 2048 ? &_data_derivedLines : nullptr;
}

const kiwi::Array<DerivedTextLineData> *DerivedTextData::derivedLines() const {
  return _flags[0] & 2048 ? &_data_derivedLines : nullptr;
}

kiwi::Array<DerivedTextLineData> &DerivedTextData::set_derivedLines(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[0] |= 2048; return _data_derivedLines = pool.array<DerivedTextLineData>(count);
}

bool DerivedTextData::encode(kiwi::ByteBuffer &_bb) {
  if (layoutSize() != nullptr) {
    _bb.writeVarUint(1);
    if (!_data_layoutSize->encode(_bb)) return false;
  }
  if (baselines() != nullptr) {
    _bb.writeVarUint(2);
    _bb.writeVarUint(_data_baselines.size());
    for (Baseline &_it : _data_baselines) if (!_it.encode(_bb)) return false;
  }
  if (glyphs() != nullptr) {
    _bb.writeVarUint(3);
    _bb.writeVarUint(_data_glyphs.size());
    for (Glyph &_it : _data_glyphs) if (!_it.encode(_bb)) return false;
  }
  if (decorations() != nullptr) {
    _bb.writeVarUint(4);
    _bb.writeVarUint(_data_decorations.size());
    for (Decoration &_it : _data_decorations) if (!_it.encode(_bb)) return false;
  }
  if (blockquotes() != nullptr) {
    _bb.writeVarUint(5);
    _bb.writeVarUint(_data_blockquotes.size());
    for (Blockquote &_it : _data_blockquotes) if (!_it.encode(_bb)) return false;
  }
  if (fontMetaData() != nullptr) {
    _bb.writeVarUint(6);
    _bb.writeVarUint(_data_fontMetaData.size());
    for (FontMetaData &_it : _data_fontMetaData) if (!_it.encode(_bb)) return false;
  }
  if (hyperlinkBoxes() != nullptr) {
    _bb.writeVarUint(7);
    _bb.writeVarUint(_data_hyperlinkBoxes.size());
    for (HyperlinkBox &_it : _data_hyperlinkBoxes) if (!_it.encode(_bb)) return false;
  }
  if (truncationStartIndex() != nullptr) {
    _bb.writeVarUint(8);
    _bb.writeVarInt(_data_truncationStartIndex);
  }
  if (truncatedHeight() != nullptr) {
    _bb.writeVarUint(9);
    _bb.writeVarFloat(_data_truncatedHeight);
  }
  if (logicalIndexToCharacterOffsetMap() != nullptr) {
    _bb.writeVarUint(10);
    _bb.writeVarUint(_data_logicalIndexToCharacterOffsetMap.size());
    for (float &_it : _data_logicalIndexToCharacterOffsetMap) _bb.writeVarFloat(_it);
  }
  if (mentionBoxes() != nullptr) {
    _bb.writeVarUint(11);
    _bb.writeVarUint(_data_mentionBoxes.size());
    for (MentionBox &_it : _data_mentionBoxes) if (!_it.encode(_bb)) return false;
  }
  if (derivedLines() != nullptr) {
    _bb.writeVarUint(12);
    _bb.writeVarUint(_data_derivedLines.size());
    for (DerivedTextLineData &_it : _data_derivedLines) if (!_it.encode(_bb)) return false;
  }
  _bb.writeVarUint(0);
  return true;
}

bool DerivedTextData::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  uint32_t _count;
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        _data_layoutSize = _pool.allocate<Vector>();
        if (!_data_layoutSize->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 2: {
        if (!_bb.readVarUint(_count)) return false;
        for (Baseline &_it : set_baselines(_pool, _count)) if (!_it.decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 3: {
        if (!_bb.readVarUint(_count)) return false;
        for (Glyph &_it : set_glyphs(_pool, _count)) if (!_it.decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 4: {
        if (!_bb.readVarUint(_count)) return false;
        for (Decoration &_it : set_decorations(_pool, _count)) if (!_it.decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 5: {
        if (!_bb.readVarUint(_count)) return false;
        for (Blockquote &_it : set_blockquotes(_pool, _count)) if (!_it.decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 6: {
        if (!_bb.readVarUint(_count)) return false;
        for (FontMetaData &_it : set_fontMetaData(_pool, _count)) if (!_it.decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 7: {
        if (!_bb.readVarUint(_count)) return false;
        for (HyperlinkBox &_it : set_hyperlinkBoxes(_pool, _count)) if (!_it.decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 8: {
        if (!_bb.readVarInt(_data_truncationStartIndex)) return false;
        set_truncationStartIndex(_data_truncationStartIndex);
        break;
      }
      case 9: {
        if (!_bb.readVarFloat(_data_truncatedHeight)) return false;
        set_truncatedHeight(_data_truncatedHeight);
        break;
      }
      case 10: {
        if (!_bb.readVarUint(_count)) return false;
        for (float &_it : set_logicalIndexToCharacterOffsetMap(_pool, _count)) if (!_bb.readVarFloat(_it)) return false;
        break;
      }
      case 11: {
        if (!_bb.readVarUint(_count)) return false;
        for (MentionBox &_it : set_mentionBoxes(_pool, _count)) if (!_it.decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 12: {
        if (!_bb.readVarUint(_count)) return false;
        for (DerivedTextLineData &_it : set_derivedLines(_pool, _count)) if (!_it.decode(_bb, _pool, _schema)) return false;
        break;
      }
      default: {
        if (!_schema || !_schema->skipDerivedTextDataField(_bb, _type)) return false;
        break;
      }
    }
  }
}

Rect *HyperlinkBox::bounds() {
  return _data_bounds;
}

const Rect *HyperlinkBox::bounds() const {
  return _data_bounds;
}

void HyperlinkBox::set_bounds(Rect *value) {
  _data_bounds = value;
}

kiwi::String *HyperlinkBox::url() {
  return _flags[0] & 2 ? &_data_url : nullptr;
}

const kiwi::String *HyperlinkBox::url() const {
  return _flags[0] & 2 ? &_data_url : nullptr;
}

void HyperlinkBox::set_url(const kiwi::String &value) {
  _flags[0] |= 2; _data_url = value;
}

GUID *HyperlinkBox::guid() {
  return _data_guid;
}

const GUID *HyperlinkBox::guid() const {
  return _data_guid;
}

void HyperlinkBox::set_guid(GUID *value) {
  _data_guid = value;
}

int32_t *HyperlinkBox::hyperlinkID() {
  return _flags[0] & 8 ? &_data_hyperlinkID : nullptr;
}

const int32_t *HyperlinkBox::hyperlinkID() const {
  return _flags[0] & 8 ? &_data_hyperlinkID : nullptr;
}

void HyperlinkBox::set_hyperlinkID(const int32_t &value) {
  _flags[0] |= 8; _data_hyperlinkID = value;
}

bool HyperlinkBox::encode(kiwi::ByteBuffer &_bb) {
  if (bounds() != nullptr) {
    _bb.writeVarUint(1);
    if (!_data_bounds->encode(_bb)) return false;
  }
  if (url() != nullptr) {
    _bb.writeVarUint(2);
    _bb.writeString(_data_url.c_str());
  }
  if (guid() != nullptr) {
    _bb.writeVarUint(3);
    if (!_data_guid->encode(_bb)) return false;
  }
  if (hyperlinkID() != nullptr) {
    _bb.writeVarUint(4);
    _bb.writeVarInt(_data_hyperlinkID);
  }
  _bb.writeVarUint(0);
  return true;
}

bool HyperlinkBox::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        _data_bounds = _pool.allocate<Rect>();
        if (!_data_bounds->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 2: {
        if (!_bb.readString(_data_url, _pool)) return false;
        set_url(_data_url);
        break;
      }
      case 3: {
        _data_guid = _pool.allocate<GUID>();
        if (!_data_guid->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 4: {
        if (!_bb.readVarInt(_data_hyperlinkID)) return false;
        set_hyperlinkID(_data_hyperlinkID);
        break;
      }
      default: {
        if (!_schema || !_schema->skipHyperlinkBoxField(_bb, _type)) return false;
        break;
      }
    }
  }
}

Rect *MentionBox::bounds() {
  return _data_bounds;
}

const Rect *MentionBox::bounds() const {
  return _data_bounds;
}

void MentionBox::set_bounds(Rect *value) {
  _data_bounds = value;
}

uint32_t *MentionBox::startIndex() {
  return _flags[0] & 2 ? &_data_startIndex : nullptr;
}

const uint32_t *MentionBox::startIndex() const {
  return _flags[0] & 2 ? &_data_startIndex : nullptr;
}

void MentionBox::set_startIndex(const uint32_t &value) {
  _flags[0] |= 2; _data_startIndex = value;
}

uint32_t *MentionBox::endIndex() {
  return _flags[0] & 4 ? &_data_endIndex : nullptr;
}

const uint32_t *MentionBox::endIndex() const {
  return _flags[0] & 4 ? &_data_endIndex : nullptr;
}

void MentionBox::set_endIndex(const uint32_t &value) {
  _flags[0] |= 4; _data_endIndex = value;
}

bool *MentionBox::isValid() {
  return _flags[0] & 8 ? &_data_isValid : nullptr;
}

const bool *MentionBox::isValid() const {
  return _flags[0] & 8 ? &_data_isValid : nullptr;
}

void MentionBox::set_isValid(const bool &value) {
  _flags[0] |= 8; _data_isValid = value;
}

uint32_t *MentionBox::mentionKey() {
  return _flags[0] & 16 ? &_data_mentionKey : nullptr;
}

const uint32_t *MentionBox::mentionKey() const {
  return _flags[0] & 16 ? &_data_mentionKey : nullptr;
}

void MentionBox::set_mentionKey(const uint32_t &value) {
  _flags[0] |= 16; _data_mentionKey = value;
}

bool MentionBox::encode(kiwi::ByteBuffer &_bb) {
  if (bounds() != nullptr) {
    _bb.writeVarUint(1);
    if (!_data_bounds->encode(_bb)) return false;
  }
  if (startIndex() != nullptr) {
    _bb.writeVarUint(2);
    _bb.writeVarUint(_data_startIndex);
  }
  if (endIndex() != nullptr) {
    _bb.writeVarUint(3);
    _bb.writeVarUint(_data_endIndex);
  }
  if (isValid() != nullptr) {
    _bb.writeVarUint(4);
    _bb.writeByte(_data_isValid);
  }
  if (mentionKey() != nullptr) {
    _bb.writeVarUint(5);
    _bb.writeVarUint(_data_mentionKey);
  }
  _bb.writeVarUint(0);
  return true;
}

bool MentionBox::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        _data_bounds = _pool.allocate<Rect>();
        if (!_data_bounds->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 2: {
        if (!_bb.readVarUint(_data_startIndex)) return false;
        set_startIndex(_data_startIndex);
        break;
      }
      case 3: {
        if (!_bb.readVarUint(_data_endIndex)) return false;
        set_endIndex(_data_endIndex);
        break;
      }
      case 4: {
        if (!_bb.readByte(_data_isValid)) return false;
        set_isValid(_data_isValid);
        break;
      }
      case 5: {
        if (!_bb.readVarUint(_data_mentionKey)) return false;
        set_mentionKey(_data_mentionKey);
        break;
      }
      default: {
        if (!_schema || !_schema->skipMentionBoxField(_bb, _type)) return false;
        break;
      }
    }
  }
}

Vector *Baseline::position() {
  return _data_position;
}

const Vector *Baseline::position() const {
  return _data_position;
}

void Baseline::set_position(Vector *value) {
  _data_position = value;
}

float *Baseline::width() {
  return _flags[0] & 2 ? &_data_width : nullptr;
}

const float *Baseline::width() const {
  return _flags[0] & 2 ? &_data_width : nullptr;
}

void Baseline::set_width(const float &value) {
  _flags[0] |= 2; _data_width = value;
}

float *Baseline::lineY() {
  return _flags[0] & 4 ? &_data_lineY : nullptr;
}

const float *Baseline::lineY() const {
  return _flags[0] & 4 ? &_data_lineY : nullptr;
}

void Baseline::set_lineY(const float &value) {
  _flags[0] |= 4; _data_lineY = value;
}

float *Baseline::lineHeight() {
  return _flags[0] & 8 ? &_data_lineHeight : nullptr;
}

const float *Baseline::lineHeight() const {
  return _flags[0] & 8 ? &_data_lineHeight : nullptr;
}

void Baseline::set_lineHeight(const float &value) {
  _flags[0] |= 8; _data_lineHeight = value;
}

float *Baseline::lineAscent() {
  return _flags[0] & 16 ? &_data_lineAscent : nullptr;
}

const float *Baseline::lineAscent() const {
  return _flags[0] & 16 ? &_data_lineAscent : nullptr;
}

void Baseline::set_lineAscent(const float &value) {
  _flags[0] |= 16; _data_lineAscent = value;
}

float *Baseline::ignoreLeadingTrim() {
  return _flags[0] & 32 ? &_data_ignoreLeadingTrim : nullptr;
}

const float *Baseline::ignoreLeadingTrim() const {
  return _flags[0] & 32 ? &_data_ignoreLeadingTrim : nullptr;
}

void Baseline::set_ignoreLeadingTrim(const float &value) {
  _flags[0] |= 32; _data_ignoreLeadingTrim = value;
}

uint32_t *Baseline::firstCharacter() {
  return _flags[0] & 64 ? &_data_firstCharacter : nullptr;
}

const uint32_t *Baseline::firstCharacter() const {
  return _flags[0] & 64 ? &_data_firstCharacter : nullptr;
}

void Baseline::set_firstCharacter(const uint32_t &value) {
  _flags[0] |= 64; _data_firstCharacter = value;
}

uint32_t *Baseline::endCharacter() {
  return _flags[0] & 128 ? &_data_endCharacter : nullptr;
}

const uint32_t *Baseline::endCharacter() const {
  return _flags[0] & 128 ? &_data_endCharacter : nullptr;
}

void Baseline::set_endCharacter(const uint32_t &value) {
  _flags[0] |= 128; _data_endCharacter = value;
}

bool Baseline::encode(kiwi::ByteBuffer &_bb) {
  if (position() != nullptr) {
    _bb.writeVarUint(1);
    if (!_data_position->encode(_bb)) return false;
  }
  if (width() != nullptr) {
    _bb.writeVarUint(2);
    _bb.writeVarFloat(_data_width);
  }
  if (lineY() != nullptr) {
    _bb.writeVarUint(3);
    _bb.writeVarFloat(_data_lineY);
  }
  if (lineHeight() != nullptr) {
    _bb.writeVarUint(4);
    _bb.writeVarFloat(_data_lineHeight);
  }
  if (lineAscent() != nullptr) {
    _bb.writeVarUint(7);
    _bb.writeVarFloat(_data_lineAscent);
  }
  if (ignoreLeadingTrim() != nullptr) {
    _bb.writeVarUint(8);
    _bb.writeVarFloat(_data_ignoreLeadingTrim);
  }
  if (firstCharacter() != nullptr) {
    _bb.writeVarUint(5);
    _bb.writeVarUint(_data_firstCharacter);
  }
  if (endCharacter() != nullptr) {
    _bb.writeVarUint(6);
    _bb.writeVarUint(_data_endCharacter);
  }
  _bb.writeVarUint(0);
  return true;
}

bool Baseline::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        _data_position = _pool.allocate<Vector>();
        if (!_data_position->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 2: {
        if (!_bb.readVarFloat(_data_width)) return false;
        set_width(_data_width);
        break;
      }
      case 3: {
        if (!_bb.readVarFloat(_data_lineY)) return false;
        set_lineY(_data_lineY);
        break;
      }
      case 4: {
        if (!_bb.readVarFloat(_data_lineHeight)) return false;
        set_lineHeight(_data_lineHeight);
        break;
      }
      case 7: {
        if (!_bb.readVarFloat(_data_lineAscent)) return false;
        set_lineAscent(_data_lineAscent);
        break;
      }
      case 8: {
        if (!_bb.readVarFloat(_data_ignoreLeadingTrim)) return false;
        set_ignoreLeadingTrim(_data_ignoreLeadingTrim);
        break;
      }
      case 5: {
        if (!_bb.readVarUint(_data_firstCharacter)) return false;
        set_firstCharacter(_data_firstCharacter);
        break;
      }
      case 6: {
        if (!_bb.readVarUint(_data_endCharacter)) return false;
        set_endCharacter(_data_endCharacter);
        break;
      }
      default: {
        if (!_schema || !_schema->skipBaselineField(_bb, _type)) return false;
        break;
      }
    }
  }
}

uint32_t *Glyph::commandsBlob() {
  return _flags[0] & 1 ? &_data_commandsBlob : nullptr;
}

const uint32_t *Glyph::commandsBlob() const {
  return _flags[0] & 1 ? &_data_commandsBlob : nullptr;
}

void Glyph::set_commandsBlob(const uint32_t &value) {
  _flags[0] |= 1; _data_commandsBlob = value;
}

Vector *Glyph::position() {
  return _data_position;
}

const Vector *Glyph::position() const {
  return _data_position;
}

void Glyph::set_position(Vector *value) {
  _data_position = value;
}

uint32_t *Glyph::styleID() {
  return _flags[0] & 4 ? &_data_styleID : nullptr;
}

const uint32_t *Glyph::styleID() const {
  return _flags[0] & 4 ? &_data_styleID : nullptr;
}

void Glyph::set_styleID(const uint32_t &value) {
  _flags[0] |= 4; _data_styleID = value;
}

float *Glyph::fontSize() {
  return _flags[0] & 8 ? &_data_fontSize : nullptr;
}

const float *Glyph::fontSize() const {
  return _flags[0] & 8 ? &_data_fontSize : nullptr;
}

void Glyph::set_fontSize(const float &value) {
  _flags[0] |= 8; _data_fontSize = value;
}

uint32_t *Glyph::firstCharacter() {
  return _flags[0] & 16 ? &_data_firstCharacter : nullptr;
}

const uint32_t *Glyph::firstCharacter() const {
  return _flags[0] & 16 ? &_data_firstCharacter : nullptr;
}

void Glyph::set_firstCharacter(const uint32_t &value) {
  _flags[0] |= 16; _data_firstCharacter = value;
}

float *Glyph::advance() {
  return _flags[0] & 32 ? &_data_advance : nullptr;
}

const float *Glyph::advance() const {
  return _flags[0] & 32 ? &_data_advance : nullptr;
}

void Glyph::set_advance(const float &value) {
  _flags[0] |= 32; _data_advance = value;
}

kiwi::Array<uint32_t> *Glyph::emojiCodePoints() {
  return _flags[0] & 64 ? &_data_emojiCodePoints : nullptr;
}

const kiwi::Array<uint32_t> *Glyph::emojiCodePoints() const {
  return _flags[0] & 64 ? &_data_emojiCodePoints : nullptr;
}

kiwi::Array<uint32_t> &Glyph::set_emojiCodePoints(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[0] |= 64; return _data_emojiCodePoints = pool.array<uint32_t>(count);
}

bool Glyph::encode(kiwi::ByteBuffer &_bb) {
  if (commandsBlob() != nullptr) {
    _bb.writeVarUint(1);
    _bb.writeVarUint(_data_commandsBlob);
  }
  if (position() != nullptr) {
    _bb.writeVarUint(2);
    if (!_data_position->encode(_bb)) return false;
  }
  if (styleID() != nullptr) {
    _bb.writeVarUint(3);
    _bb.writeVarUint(_data_styleID);
  }
  if (fontSize() != nullptr) {
    _bb.writeVarUint(4);
    _bb.writeVarFloat(_data_fontSize);
  }
  if (firstCharacter() != nullptr) {
    _bb.writeVarUint(5);
    _bb.writeVarUint(_data_firstCharacter);
  }
  if (advance() != nullptr) {
    _bb.writeVarUint(6);
    _bb.writeVarFloat(_data_advance);
  }
  if (emojiCodePoints() != nullptr) {
    _bb.writeVarUint(7);
    _bb.writeVarUint(_data_emojiCodePoints.size());
    for (uint32_t &_it : _data_emojiCodePoints) _bb.writeVarUint(_it);
  }
  _bb.writeVarUint(0);
  return true;
}

bool Glyph::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  uint32_t _count;
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        if (!_bb.readVarUint(_data_commandsBlob)) return false;
        set_commandsBlob(_data_commandsBlob);
        break;
      }
      case 2: {
        _data_position = _pool.allocate<Vector>();
        if (!_data_position->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 3: {
        if (!_bb.readVarUint(_data_styleID)) return false;
        set_styleID(_data_styleID);
        break;
      }
      case 4: {
        if (!_bb.readVarFloat(_data_fontSize)) return false;
        set_fontSize(_data_fontSize);
        break;
      }
      case 5: {
        if (!_bb.readVarUint(_data_firstCharacter)) return false;
        set_firstCharacter(_data_firstCharacter);
        break;
      }
      case 6: {
        if (!_bb.readVarFloat(_data_advance)) return false;
        set_advance(_data_advance);
        break;
      }
      case 7: {
        if (!_bb.readVarUint(_count)) return false;
        for (uint32_t &_it : set_emojiCodePoints(_pool, _count)) if (!_bb.readVarUint(_it)) return false;
        break;
      }
      default: {
        if (!_schema || !_schema->skipGlyphField(_bb, _type)) return false;
        break;
      }
    }
  }
}

kiwi::Array<Rect> *Decoration::rects() {
  return _flags[0] & 1 ? &_data_rects : nullptr;
}

const kiwi::Array<Rect> *Decoration::rects() const {
  return _flags[0] & 1 ? &_data_rects : nullptr;
}

kiwi::Array<Rect> &Decoration::set_rects(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[0] |= 1; return _data_rects = pool.array<Rect>(count);
}

uint32_t *Decoration::styleID() {
  return _flags[0] & 2 ? &_data_styleID : nullptr;
}

const uint32_t *Decoration::styleID() const {
  return _flags[0] & 2 ? &_data_styleID : nullptr;
}

void Decoration::set_styleID(const uint32_t &value) {
  _flags[0] |= 2; _data_styleID = value;
}

bool Decoration::encode(kiwi::ByteBuffer &_bb) {
  if (rects() != nullptr) {
    _bb.writeVarUint(1);
    _bb.writeVarUint(_data_rects.size());
    for (Rect &_it : _data_rects) if (!_it.encode(_bb)) return false;
  }
  if (styleID() != nullptr) {
    _bb.writeVarUint(2);
    _bb.writeVarUint(_data_styleID);
  }
  _bb.writeVarUint(0);
  return true;
}

bool Decoration::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  uint32_t _count;
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        if (!_bb.readVarUint(_count)) return false;
        for (Rect &_it : set_rects(_pool, _count)) if (!_it.decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 2: {
        if (!_bb.readVarUint(_data_styleID)) return false;
        set_styleID(_data_styleID);
        break;
      }
      default: {
        if (!_schema || !_schema->skipDecorationField(_bb, _type)) return false;
        break;
      }
    }
  }
}

Rect *Blockquote::verticalBar() {
  return _data_verticalBar;
}

const Rect *Blockquote::verticalBar() const {
  return _data_verticalBar;
}

void Blockquote::set_verticalBar(Rect *value) {
  _data_verticalBar = value;
}

Rect *Blockquote::quoteMarkBounds() {
  return _data_quoteMarkBounds;
}

const Rect *Blockquote::quoteMarkBounds() const {
  return _data_quoteMarkBounds;
}

void Blockquote::set_quoteMarkBounds(Rect *value) {
  _data_quoteMarkBounds = value;
}

uint32_t *Blockquote::styleID() {
  return _flags[0] & 4 ? &_data_styleID : nullptr;
}

const uint32_t *Blockquote::styleID() const {
  return _flags[0] & 4 ? &_data_styleID : nullptr;
}

void Blockquote::set_styleID(const uint32_t &value) {
  _flags[0] |= 4; _data_styleID = value;
}

bool Blockquote::encode(kiwi::ByteBuffer &_bb) {
  if (verticalBar() != nullptr) {
    _bb.writeVarUint(1);
    if (!_data_verticalBar->encode(_bb)) return false;
  }
  if (quoteMarkBounds() != nullptr) {
    _bb.writeVarUint(2);
    if (!_data_quoteMarkBounds->encode(_bb)) return false;
  }
  if (styleID() != nullptr) {
    _bb.writeVarUint(3);
    _bb.writeVarUint(_data_styleID);
  }
  _bb.writeVarUint(0);
  return true;
}

bool Blockquote::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        _data_verticalBar = _pool.allocate<Rect>();
        if (!_data_verticalBar->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 2: {
        _data_quoteMarkBounds = _pool.allocate<Rect>();
        if (!_data_quoteMarkBounds->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 3: {
        if (!_bb.readVarUint(_data_styleID)) return false;
        set_styleID(_data_styleID);
        break;
      }
      default: {
        if (!_schema || !_schema->skipBlockquoteField(_bb, _type)) return false;
        break;
      }
    }
  }
}

uint32_t *VectorData::vectorNetworkBlob() {
  return _flags[0] & 1 ? &_data_vectorNetworkBlob : nullptr;
}

const uint32_t *VectorData::vectorNetworkBlob() const {
  return _flags[0] & 1 ? &_data_vectorNetworkBlob : nullptr;
}

void VectorData::set_vectorNetworkBlob(const uint32_t &value) {
  _flags[0] |= 1; _data_vectorNetworkBlob = value;
}

Vector *VectorData::normalizedSize() {
  return _data_normalizedSize;
}

const Vector *VectorData::normalizedSize() const {
  return _data_normalizedSize;
}

void VectorData::set_normalizedSize(Vector *value) {
  _data_normalizedSize = value;
}

kiwi::Array<NodeChange> *VectorData::styleOverrideTable() {
  return _flags[0] & 4 ? &_data_styleOverrideTable : nullptr;
}

const kiwi::Array<NodeChange> *VectorData::styleOverrideTable() const {
  return _flags[0] & 4 ? &_data_styleOverrideTable : nullptr;
}

kiwi::Array<NodeChange> &VectorData::set_styleOverrideTable(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[0] |= 4; return _data_styleOverrideTable = pool.array<NodeChange>(count);
}

bool VectorData::encode(kiwi::ByteBuffer &_bb) {
  if (vectorNetworkBlob() != nullptr) {
    _bb.writeVarUint(1);
    _bb.writeVarUint(_data_vectorNetworkBlob);
  }
  if (normalizedSize() != nullptr) {
    _bb.writeVarUint(2);
    if (!_data_normalizedSize->encode(_bb)) return false;
  }
  if (styleOverrideTable() != nullptr) {
    _bb.writeVarUint(3);
    _bb.writeVarUint(_data_styleOverrideTable.size());
    for (NodeChange &_it : _data_styleOverrideTable) if (!_it.encode(_bb)) return false;
  }
  _bb.writeVarUint(0);
  return true;
}

bool VectorData::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  uint32_t _count;
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        if (!_bb.readVarUint(_data_vectorNetworkBlob)) return false;
        set_vectorNetworkBlob(_data_vectorNetworkBlob);
        break;
      }
      case 2: {
        _data_normalizedSize = _pool.allocate<Vector>();
        if (!_data_normalizedSize->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 3: {
        if (!_bb.readVarUint(_count)) return false;
        for (NodeChange &_it : set_styleOverrideTable(_pool, _count)) if (!_it.decode(_bb, _pool, _schema)) return false;
        break;
      }
      default: {
        if (!_schema || !_schema->skipVectorDataField(_bb, _type)) return false;
        break;
      }
    }
  }
}

kiwi::Array<GUID> *GUIDPath::guids() {
  return _flags[0] & 1 ? &_data_guids : nullptr;
}

const kiwi::Array<GUID> *GUIDPath::guids() const {
  return _flags[0] & 1 ? &_data_guids : nullptr;
}

kiwi::Array<GUID> &GUIDPath::set_guids(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[0] |= 1; return _data_guids = pool.array<GUID>(count);
}

bool GUIDPath::encode(kiwi::ByteBuffer &_bb) {
  if (guids() != nullptr) {
    _bb.writeVarUint(1);
    _bb.writeVarUint(_data_guids.size());
    for (GUID &_it : _data_guids) if (!_it.encode(_bb)) return false;
  }
  _bb.writeVarUint(0);
  return true;
}

bool GUIDPath::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  uint32_t _count;
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        if (!_bb.readVarUint(_count)) return false;
        for (GUID &_it : set_guids(_pool, _count)) if (!_it.decode(_bb, _pool, _schema)) return false;
        break;
      }
      default: {
        if (!_schema || !_schema->skipGUIDPathField(_bb, _type)) return false;
        break;
      }
    }
  }
}

GUID *SymbolData::symbolID() {
  return _data_symbolID;
}

const GUID *SymbolData::symbolID() const {
  return _data_symbolID;
}

void SymbolData::set_symbolID(GUID *value) {
  _data_symbolID = value;
}

kiwi::Array<NodeChange> *SymbolData::symbolOverrides() {
  return _flags[0] & 2 ? &_data_symbolOverrides : nullptr;
}

const kiwi::Array<NodeChange> *SymbolData::symbolOverrides() const {
  return _flags[0] & 2 ? &_data_symbolOverrides : nullptr;
}

kiwi::Array<NodeChange> &SymbolData::set_symbolOverrides(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[0] |= 2; return _data_symbolOverrides = pool.array<NodeChange>(count);
}

float *SymbolData::uniformScaleFactor() {
  return _flags[0] & 4 ? &_data_uniformScaleFactor : nullptr;
}

const float *SymbolData::uniformScaleFactor() const {
  return _flags[0] & 4 ? &_data_uniformScaleFactor : nullptr;
}

void SymbolData::set_uniformScaleFactor(const float &value) {
  _flags[0] |= 4; _data_uniformScaleFactor = value;
}

bool SymbolData::encode(kiwi::ByteBuffer &_bb) {
  if (symbolID() != nullptr) {
    _bb.writeVarUint(1);
    if (!_data_symbolID->encode(_bb)) return false;
  }
  if (symbolOverrides() != nullptr) {
    _bb.writeVarUint(2);
    _bb.writeVarUint(_data_symbolOverrides.size());
    for (NodeChange &_it : _data_symbolOverrides) if (!_it.encode(_bb)) return false;
  }
  if (uniformScaleFactor() != nullptr) {
    _bb.writeVarUint(3);
    _bb.writeVarFloat(_data_uniformScaleFactor);
  }
  _bb.writeVarUint(0);
  return true;
}

bool SymbolData::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  uint32_t _count;
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        _data_symbolID = _pool.allocate<GUID>();
        if (!_data_symbolID->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 2: {
        if (!_bb.readVarUint(_count)) return false;
        for (NodeChange &_it : set_symbolOverrides(_pool, _count)) if (!_it.decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 3: {
        if (!_bb.readVarFloat(_data_uniformScaleFactor)) return false;
        set_uniformScaleFactor(_data_uniformScaleFactor);
        break;
      }
      default: {
        if (!_schema || !_schema->skipSymbolDataField(_bb, _type)) return false;
        break;
      }
    }
  }
}

GUID *GUIDPathMapping::id() {
  return _data_id;
}

const GUID *GUIDPathMapping::id() const {
  return _data_id;
}

void GUIDPathMapping::set_id(GUID *value) {
  _data_id = value;
}

GUIDPath *GUIDPathMapping::path() {
  return _data_path;
}

const GUIDPath *GUIDPathMapping::path() const {
  return _data_path;
}

void GUIDPathMapping::set_path(GUIDPath *value) {
  _data_path = value;
}

bool GUIDPathMapping::encode(kiwi::ByteBuffer &_bb) {
  if (id() != nullptr) {
    _bb.writeVarUint(1);
    if (!_data_id->encode(_bb)) return false;
  }
  if (path() != nullptr) {
    _bb.writeVarUint(2);
    if (!_data_path->encode(_bb)) return false;
  }
  _bb.writeVarUint(0);
  return true;
}

bool GUIDPathMapping::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        _data_id = _pool.allocate<GUID>();
        if (!_data_id->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 2: {
        _data_path = _pool.allocate<GUIDPath>();
        if (!_data_path->decode(_bb, _pool, _schema)) return false;
        break;
      }
      default: {
        if (!_schema || !_schema->skipGUIDPathMappingField(_bb, _type)) return false;
        break;
      }
    }
  }
}

kiwi::Array<NodeChange> *NodeGenerationData::overrides() {
  return _flags[0] & 1 ? &_data_overrides : nullptr;
}

const kiwi::Array<NodeChange> *NodeGenerationData::overrides() const {
  return _flags[0] & 1 ? &_data_overrides : nullptr;
}

kiwi::Array<NodeChange> &NodeGenerationData::set_overrides(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[0] |= 1; return _data_overrides = pool.array<NodeChange>(count);
}

bool *NodeGenerationData::useFineGrainedSyncing() {
  return _flags[0] & 2 ? &_data_useFineGrainedSyncing : nullptr;
}

const bool *NodeGenerationData::useFineGrainedSyncing() const {
  return _flags[0] & 2 ? &_data_useFineGrainedSyncing : nullptr;
}

void NodeGenerationData::set_useFineGrainedSyncing(const bool &value) {
  _flags[0] |= 2; _data_useFineGrainedSyncing = value;
}

kiwi::Array<NodeChange> *NodeGenerationData::diffOnlyRemovals() {
  return _flags[0] & 4 ? &_data_diffOnlyRemovals : nullptr;
}

const kiwi::Array<NodeChange> *NodeGenerationData::diffOnlyRemovals() const {
  return _flags[0] & 4 ? &_data_diffOnlyRemovals : nullptr;
}

kiwi::Array<NodeChange> &NodeGenerationData::set_diffOnlyRemovals(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[0] |= 4; return _data_diffOnlyRemovals = pool.array<NodeChange>(count);
}

bool NodeGenerationData::encode(kiwi::ByteBuffer &_bb) {
  if (overrides() != nullptr) {
    _bb.writeVarUint(1);
    _bb.writeVarUint(_data_overrides.size());
    for (NodeChange &_it : _data_overrides) if (!_it.encode(_bb)) return false;
  }
  if (useFineGrainedSyncing() != nullptr) {
    _bb.writeVarUint(2);
    _bb.writeByte(_data_useFineGrainedSyncing);
  }
  if (diffOnlyRemovals() != nullptr) {
    _bb.writeVarUint(3);
    _bb.writeVarUint(_data_diffOnlyRemovals.size());
    for (NodeChange &_it : _data_diffOnlyRemovals) if (!_it.encode(_bb)) return false;
  }
  _bb.writeVarUint(0);
  return true;
}

bool NodeGenerationData::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  uint32_t _count;
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        if (!_bb.readVarUint(_count)) return false;
        for (NodeChange &_it : set_overrides(_pool, _count)) if (!_it.decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 2: {
        if (!_bb.readByte(_data_useFineGrainedSyncing)) return false;
        set_useFineGrainedSyncing(_data_useFineGrainedSyncing);
        break;
      }
      case 3: {
        if (!_bb.readVarUint(_count)) return false;
        for (NodeChange &_it : set_diffOnlyRemovals(_pool, _count)) if (!_it.decode(_bb, _pool, _schema)) return false;
        break;
      }
      default: {
        if (!_schema || !_schema->skipNodeGenerationDataField(_bb, _type)) return false;
        break;
      }
    }
  }
}

kiwi::Array<NodeChange> *DerivedImmutableFrameData::overrides() {
  return _flags[0] & 1 ? &_data_overrides : nullptr;
}

const kiwi::Array<NodeChange> *DerivedImmutableFrameData::overrides() const {
  return _flags[0] & 1 ? &_data_overrides : nullptr;
}

kiwi::Array<NodeChange> &DerivedImmutableFrameData::set_overrides(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[0] |= 1; return _data_overrides = pool.array<NodeChange>(count);
}

uint32_t *DerivedImmutableFrameData::version() {
  return _flags[0] & 2 ? &_data_version : nullptr;
}

const uint32_t *DerivedImmutableFrameData::version() const {
  return _flags[0] & 2 ? &_data_version : nullptr;
}

void DerivedImmutableFrameData::set_version(const uint32_t &value) {
  _flags[0] |= 2; _data_version = value;
}

bool DerivedImmutableFrameData::encode(kiwi::ByteBuffer &_bb) {
  if (overrides() != nullptr) {
    _bb.writeVarUint(1);
    _bb.writeVarUint(_data_overrides.size());
    for (NodeChange &_it : _data_overrides) if (!_it.encode(_bb)) return false;
  }
  if (version() != nullptr) {
    _bb.writeVarUint(2);
    _bb.writeVarUint(_data_version);
  }
  _bb.writeVarUint(0);
  return true;
}

bool DerivedImmutableFrameData::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  uint32_t _count;
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        if (!_bb.readVarUint(_count)) return false;
        for (NodeChange &_it : set_overrides(_pool, _count)) if (!_it.decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 2: {
        if (!_bb.readVarUint(_data_version)) return false;
        set_version(_data_version);
        break;
      }
      default: {
        if (!_schema || !_schema->skipDerivedImmutableFrameDataField(_bb, _type)) return false;
        break;
      }
    }
  }
}

kiwi::String *AssetRef::key() {
  return _flags[0] & 1 ? &_data_key : nullptr;
}

const kiwi::String *AssetRef::key() const {
  return _flags[0] & 1 ? &_data_key : nullptr;
}

void AssetRef::set_key(const kiwi::String &value) {
  _flags[0] |= 1; _data_key = value;
}

kiwi::String *AssetRef::version() {
  return _flags[0] & 2 ? &_data_version : nullptr;
}

const kiwi::String *AssetRef::version() const {
  return _flags[0] & 2 ? &_data_version : nullptr;
}

void AssetRef::set_version(const kiwi::String &value) {
  _flags[0] |= 2; _data_version = value;
}

bool AssetRef::encode(kiwi::ByteBuffer &_bb) {
  if (key() != nullptr) {
    _bb.writeVarUint(1);
    _bb.writeString(_data_key.c_str());
  }
  if (version() != nullptr) {
    _bb.writeVarUint(2);
    _bb.writeString(_data_version.c_str());
  }
  _bb.writeVarUint(0);
  return true;
}

bool AssetRef::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        if (!_bb.readString(_data_key, _pool)) return false;
        set_key(_data_key);
        break;
      }
      case 2: {
        if (!_bb.readString(_data_version, _pool)) return false;
        set_version(_data_version);
        break;
      }
      default: {
        if (!_schema || !_schema->skipAssetRefField(_bb, _type)) return false;
        break;
      }
    }
  }
}

GUID *StateGroupId::guid() {
  return _data_guid;
}

const GUID *StateGroupId::guid() const {
  return _data_guid;
}

void StateGroupId::set_guid(GUID *value) {
  _data_guid = value;
}

AssetRef *StateGroupId::assetRef() {
  return _data_assetRef;
}

const AssetRef *StateGroupId::assetRef() const {
  return _data_assetRef;
}

void StateGroupId::set_assetRef(AssetRef *value) {
  _data_assetRef = value;
}

bool StateGroupId::encode(kiwi::ByteBuffer &_bb) {
  if (guid() != nullptr) {
    _bb.writeVarUint(1);
    if (!_data_guid->encode(_bb)) return false;
  }
  if (assetRef() != nullptr) {
    _bb.writeVarUint(2);
    if (!_data_assetRef->encode(_bb)) return false;
  }
  _bb.writeVarUint(0);
  return true;
}

bool StateGroupId::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        _data_guid = _pool.allocate<GUID>();
        if (!_data_guid->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 2: {
        _data_assetRef = _pool.allocate<AssetRef>();
        if (!_data_assetRef->decode(_bb, _pool, _schema)) return false;
        break;
      }
      default: {
        if (!_schema || !_schema->skipStateGroupIdField(_bb, _type)) return false;
        break;
      }
    }
  }
}

GUID *StyleId::guid() {
  return _data_guid;
}

const GUID *StyleId::guid() const {
  return _data_guid;
}

void StyleId::set_guid(GUID *value) {
  _data_guid = value;
}

AssetRef *StyleId::assetRef() {
  return _data_assetRef;
}

const AssetRef *StyleId::assetRef() const {
  return _data_assetRef;
}

void StyleId::set_assetRef(AssetRef *value) {
  _data_assetRef = value;
}

bool StyleId::encode(kiwi::ByteBuffer &_bb) {
  if (guid() != nullptr) {
    _bb.writeVarUint(1);
    if (!_data_guid->encode(_bb)) return false;
  }
  if (assetRef() != nullptr) {
    _bb.writeVarUint(2);
    if (!_data_assetRef->encode(_bb)) return false;
  }
  _bb.writeVarUint(0);
  return true;
}

bool StyleId::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        _data_guid = _pool.allocate<GUID>();
        if (!_data_guid->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 2: {
        _data_assetRef = _pool.allocate<AssetRef>();
        if (!_data_assetRef->decode(_bb, _pool, _schema)) return false;
        break;
      }
      default: {
        if (!_schema || !_schema->skipStyleIdField(_bb, _type)) return false;
        break;
      }
    }
  }
}

GUID *SymbolId::guid() {
  return _data_guid;
}

const GUID *SymbolId::guid() const {
  return _data_guid;
}

void SymbolId::set_guid(GUID *value) {
  _data_guid = value;
}

AssetRef *SymbolId::assetRef() {
  return _data_assetRef;
}

const AssetRef *SymbolId::assetRef() const {
  return _data_assetRef;
}

void SymbolId::set_assetRef(AssetRef *value) {
  _data_assetRef = value;
}

bool SymbolId::encode(kiwi::ByteBuffer &_bb) {
  if (guid() != nullptr) {
    _bb.writeVarUint(1);
    if (!_data_guid->encode(_bb)) return false;
  }
  if (assetRef() != nullptr) {
    _bb.writeVarUint(2);
    if (!_data_assetRef->encode(_bb)) return false;
  }
  _bb.writeVarUint(0);
  return true;
}

bool SymbolId::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        _data_guid = _pool.allocate<GUID>();
        if (!_data_guid->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 2: {
        _data_assetRef = _pool.allocate<AssetRef>();
        if (!_data_assetRef->decode(_bb, _pool, _schema)) return false;
        break;
      }
      default: {
        if (!_schema || !_schema->skipSymbolIdField(_bb, _type)) return false;
        break;
      }
    }
  }
}

GUID *VariableID::guid() {
  return _data_guid;
}

const GUID *VariableID::guid() const {
  return _data_guid;
}

void VariableID::set_guid(GUID *value) {
  _data_guid = value;
}

AssetRef *VariableID::assetRef() {
  return _data_assetRef;
}

const AssetRef *VariableID::assetRef() const {
  return _data_assetRef;
}

void VariableID::set_assetRef(AssetRef *value) {
  _data_assetRef = value;
}

bool VariableID::encode(kiwi::ByteBuffer &_bb) {
  if (guid() != nullptr) {
    _bb.writeVarUint(1);
    if (!_data_guid->encode(_bb)) return false;
  }
  if (assetRef() != nullptr) {
    _bb.writeVarUint(2);
    if (!_data_assetRef->encode(_bb)) return false;
  }
  _bb.writeVarUint(0);
  return true;
}

bool VariableID::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        _data_guid = _pool.allocate<GUID>();
        if (!_data_guid->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 2: {
        _data_assetRef = _pool.allocate<AssetRef>();
        if (!_data_assetRef->decode(_bb, _pool, _schema)) return false;
        break;
      }
      default: {
        if (!_schema || !_schema->skipVariableIDField(_bb, _type)) return false;
        break;
      }
    }
  }
}

GUID *VariableSetID::guid() {
  return _data_guid;
}

const GUID *VariableSetID::guid() const {
  return _data_guid;
}

void VariableSetID::set_guid(GUID *value) {
  _data_guid = value;
}

AssetRef *VariableSetID::assetRef() {
  return _data_assetRef;
}

const AssetRef *VariableSetID::assetRef() const {
  return _data_assetRef;
}

void VariableSetID::set_assetRef(AssetRef *value) {
  _data_assetRef = value;
}

bool VariableSetID::encode(kiwi::ByteBuffer &_bb) {
  if (guid() != nullptr) {
    _bb.writeVarUint(1);
    if (!_data_guid->encode(_bb)) return false;
  }
  if (assetRef() != nullptr) {
    _bb.writeVarUint(2);
    if (!_data_assetRef->encode(_bb)) return false;
  }
  _bb.writeVarUint(0);
  return true;
}

bool VariableSetID::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        _data_guid = _pool.allocate<GUID>();
        if (!_data_guid->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 2: {
        _data_assetRef = _pool.allocate<AssetRef>();
        if (!_data_assetRef->decode(_bb, _pool, _schema)) return false;
        break;
      }
      default: {
        if (!_schema || !_schema->skipVariableSetIDField(_bb, _type)) return false;
        break;
      }
    }
  }
}

kiwi::String *SharedSymbolReference::fileKey() {
  return _flags[0] & 1 ? &_data_fileKey : nullptr;
}

const kiwi::String *SharedSymbolReference::fileKey() const {
  return _flags[0] & 1 ? &_data_fileKey : nullptr;
}

void SharedSymbolReference::set_fileKey(const kiwi::String &value) {
  _flags[0] |= 1; _data_fileKey = value;
}

GUID *SharedSymbolReference::symbolID() {
  return _data_symbolID;
}

const GUID *SharedSymbolReference::symbolID() const {
  return _data_symbolID;
}

void SharedSymbolReference::set_symbolID(GUID *value) {
  _data_symbolID = value;
}

kiwi::String *SharedSymbolReference::versionHash() {
  return _flags[0] & 4 ? &_data_versionHash : nullptr;
}

const kiwi::String *SharedSymbolReference::versionHash() const {
  return _flags[0] & 4 ? &_data_versionHash : nullptr;
}

void SharedSymbolReference::set_versionHash(const kiwi::String &value) {
  _flags[0] |= 4; _data_versionHash = value;
}

kiwi::Array<GUIDPathMapping> *SharedSymbolReference::guidPathMappings() {
  return _flags[0] & 8 ? &_data_guidPathMappings : nullptr;
}

const kiwi::Array<GUIDPathMapping> *SharedSymbolReference::guidPathMappings() const {
  return _flags[0] & 8 ? &_data_guidPathMappings : nullptr;
}

kiwi::Array<GUIDPathMapping> &SharedSymbolReference::set_guidPathMappings(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[0] |= 8; return _data_guidPathMappings = pool.array<GUIDPathMapping>(count);
}

kiwi::Array<uint8_t> *SharedSymbolReference::bytes() {
  return _flags[0] & 16 ? &_data_bytes : nullptr;
}

const kiwi::Array<uint8_t> *SharedSymbolReference::bytes() const {
  return _flags[0] & 16 ? &_data_bytes : nullptr;
}

kiwi::Array<uint8_t> &SharedSymbolReference::set_bytes(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[0] |= 16; return _data_bytes = pool.array<uint8_t>(count);
}

kiwi::Array<GUIDMapping> *SharedSymbolReference::libraryGUIDToSubscribingGUID() {
  return _flags[0] & 32 ? &_data_libraryGUIDToSubscribingGUID : nullptr;
}

const kiwi::Array<GUIDMapping> *SharedSymbolReference::libraryGUIDToSubscribingGUID() const {
  return _flags[0] & 32 ? &_data_libraryGUIDToSubscribingGUID : nullptr;
}

kiwi::Array<GUIDMapping> &SharedSymbolReference::set_libraryGUIDToSubscribingGUID(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[0] |= 32; return _data_libraryGUIDToSubscribingGUID = pool.array<GUIDMapping>(count);
}

kiwi::String *SharedSymbolReference::componentKey() {
  return _flags[0] & 64 ? &_data_componentKey : nullptr;
}

const kiwi::String *SharedSymbolReference::componentKey() const {
  return _flags[0] & 64 ? &_data_componentKey : nullptr;
}

void SharedSymbolReference::set_componentKey(const kiwi::String &value) {
  _flags[0] |= 64; _data_componentKey = value;
}

kiwi::Array<GUIDPathMapping> *SharedSymbolReference::unflatteningMappings() {
  return _flags[0] & 128 ? &_data_unflatteningMappings : nullptr;
}

const kiwi::Array<GUIDPathMapping> *SharedSymbolReference::unflatteningMappings() const {
  return _flags[0] & 128 ? &_data_unflatteningMappings : nullptr;
}

kiwi::Array<GUIDPathMapping> &SharedSymbolReference::set_unflatteningMappings(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[0] |= 128; return _data_unflatteningMappings = pool.array<GUIDPathMapping>(count);
}

bool *SharedSymbolReference::isUnflattened() {
  return _flags[0] & 256 ? &_data_isUnflattened : nullptr;
}

const bool *SharedSymbolReference::isUnflattened() const {
  return _flags[0] & 256 ? &_data_isUnflattened : nullptr;
}

void SharedSymbolReference::set_isUnflattened(const bool &value) {
  _flags[0] |= 256; _data_isUnflattened = value;
}

bool SharedSymbolReference::encode(kiwi::ByteBuffer &_bb) {
  if (fileKey() != nullptr) {
    _bb.writeVarUint(1);
    _bb.writeString(_data_fileKey.c_str());
  }
  if (symbolID() != nullptr) {
    _bb.writeVarUint(2);
    if (!_data_symbolID->encode(_bb)) return false;
  }
  if (versionHash() != nullptr) {
    _bb.writeVarUint(3);
    _bb.writeString(_data_versionHash.c_str());
  }
  if (guidPathMappings() != nullptr) {
    _bb.writeVarUint(4);
    _bb.writeVarUint(_data_guidPathMappings.size());
    for (GUIDPathMapping &_it : _data_guidPathMappings) if (!_it.encode(_bb)) return false;
  }
  if (bytes() != nullptr) {
    _bb.writeVarUint(5);
    _bb.writeVarUint(_data_bytes.size());
    for (uint8_t &_it : _data_bytes) _bb.writeByte(_it);
  }
  if (libraryGUIDToSubscribingGUID() != nullptr) {
    _bb.writeVarUint(6);
    _bb.writeVarUint(_data_libraryGUIDToSubscribingGUID.size());
    for (GUIDMapping &_it : _data_libraryGUIDToSubscribingGUID) if (!_it.encode(_bb)) return false;
  }
  if (componentKey() != nullptr) {
    _bb.writeVarUint(7);
    _bb.writeString(_data_componentKey.c_str());
  }
  if (unflatteningMappings() != nullptr) {
    _bb.writeVarUint(8);
    _bb.writeVarUint(_data_unflatteningMappings.size());
    for (GUIDPathMapping &_it : _data_unflatteningMappings) if (!_it.encode(_bb)) return false;
  }
  if (isUnflattened() != nullptr) {
    _bb.writeVarUint(9);
    _bb.writeByte(_data_isUnflattened);
  }
  _bb.writeVarUint(0);
  return true;
}

bool SharedSymbolReference::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  uint32_t _count;
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        if (!_bb.readString(_data_fileKey, _pool)) return false;
        set_fileKey(_data_fileKey);
        break;
      }
      case 2: {
        _data_symbolID = _pool.allocate<GUID>();
        if (!_data_symbolID->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 3: {
        if (!_bb.readString(_data_versionHash, _pool)) return false;
        set_versionHash(_data_versionHash);
        break;
      }
      case 4: {
        if (!_bb.readVarUint(_count)) return false;
        for (GUIDPathMapping &_it : set_guidPathMappings(_pool, _count)) if (!_it.decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 5: {
        if (!_bb.readVarUint(_count)) return false;
        for (uint8_t &_it : set_bytes(_pool, _count)) if (!_bb.readByte(_it)) return false;
        break;
      }
      case 6: {
        if (!_bb.readVarUint(_count)) return false;
        for (GUIDMapping &_it : set_libraryGUIDToSubscribingGUID(_pool, _count)) if (!_it.decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 7: {
        if (!_bb.readString(_data_componentKey, _pool)) return false;
        set_componentKey(_data_componentKey);
        break;
      }
      case 8: {
        if (!_bb.readVarUint(_count)) return false;
        for (GUIDPathMapping &_it : set_unflatteningMappings(_pool, _count)) if (!_it.decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 9: {
        if (!_bb.readByte(_data_isUnflattened)) return false;
        set_isUnflattened(_data_isUnflattened);
        break;
      }
      default: {
        if (!_schema || !_schema->skipSharedSymbolReferenceField(_bb, _type)) return false;
        break;
      }
    }
  }
}

kiwi::String *SharedComponentMasterData::componentKey() {
  return _flags[0] & 1 ? &_data_componentKey : nullptr;
}

const kiwi::String *SharedComponentMasterData::componentKey() const {
  return _flags[0] & 1 ? &_data_componentKey : nullptr;
}

void SharedComponentMasterData::set_componentKey(const kiwi::String &value) {
  _flags[0] |= 1; _data_componentKey = value;
}

kiwi::Array<GUIDPathMapping> *SharedComponentMasterData::publishingGUIDPathToTeamLibraryGUID() {
  return _flags[0] & 2 ? &_data_publishingGUIDPathToTeamLibraryGUID : nullptr;
}

const kiwi::Array<GUIDPathMapping> *SharedComponentMasterData::publishingGUIDPathToTeamLibraryGUID() const {
  return _flags[0] & 2 ? &_data_publishingGUIDPathToTeamLibraryGUID : nullptr;
}

kiwi::Array<GUIDPathMapping> &SharedComponentMasterData::set_publishingGUIDPathToTeamLibraryGUID(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[0] |= 2; return _data_publishingGUIDPathToTeamLibraryGUID = pool.array<GUIDPathMapping>(count);
}

bool *SharedComponentMasterData::isUnflattened() {
  return _flags[0] & 4 ? &_data_isUnflattened : nullptr;
}

const bool *SharedComponentMasterData::isUnflattened() const {
  return _flags[0] & 4 ? &_data_isUnflattened : nullptr;
}

void SharedComponentMasterData::set_isUnflattened(const bool &value) {
  _flags[0] |= 4; _data_isUnflattened = value;
}

bool SharedComponentMasterData::encode(kiwi::ByteBuffer &_bb) {
  if (componentKey() != nullptr) {
    _bb.writeVarUint(1);
    _bb.writeString(_data_componentKey.c_str());
  }
  if (publishingGUIDPathToTeamLibraryGUID() != nullptr) {
    _bb.writeVarUint(2);
    _bb.writeVarUint(_data_publishingGUIDPathToTeamLibraryGUID.size());
    for (GUIDPathMapping &_it : _data_publishingGUIDPathToTeamLibraryGUID) if (!_it.encode(_bb)) return false;
  }
  if (isUnflattened() != nullptr) {
    _bb.writeVarUint(3);
    _bb.writeByte(_data_isUnflattened);
  }
  _bb.writeVarUint(0);
  return true;
}

bool SharedComponentMasterData::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  uint32_t _count;
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        if (!_bb.readString(_data_componentKey, _pool)) return false;
        set_componentKey(_data_componentKey);
        break;
      }
      case 2: {
        if (!_bb.readVarUint(_count)) return false;
        for (GUIDPathMapping &_it : set_publishingGUIDPathToTeamLibraryGUID(_pool, _count)) if (!_it.decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 3: {
        if (!_bb.readByte(_data_isUnflattened)) return false;
        set_isUnflattened(_data_isUnflattened);
        break;
      }
      default: {
        if (!_schema || !_schema->skipSharedComponentMasterDataField(_bb, _type)) return false;
        break;
      }
    }
  }
}

GUIDPath *InstanceOverrideStash::overridePathOfSwappedInstance() {
  return _data_overridePathOfSwappedInstance;
}

const GUIDPath *InstanceOverrideStash::overridePathOfSwappedInstance() const {
  return _data_overridePathOfSwappedInstance;
}

void InstanceOverrideStash::set_overridePathOfSwappedInstance(GUIDPath *value) {
  _data_overridePathOfSwappedInstance = value;
}

kiwi::String *InstanceOverrideStash::componentKey() {
  return _flags[0] & 2 ? &_data_componentKey : nullptr;
}

const kiwi::String *InstanceOverrideStash::componentKey() const {
  return _flags[0] & 2 ? &_data_componentKey : nullptr;
}

void InstanceOverrideStash::set_componentKey(const kiwi::String &value) {
  _flags[0] |= 2; _data_componentKey = value;
}

kiwi::Array<NodeChange> *InstanceOverrideStash::overrides() {
  return _flags[0] & 4 ? &_data_overrides : nullptr;
}

const kiwi::Array<NodeChange> *InstanceOverrideStash::overrides() const {
  return _flags[0] & 4 ? &_data_overrides : nullptr;
}

kiwi::Array<NodeChange> &InstanceOverrideStash::set_overrides(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[0] |= 4; return _data_overrides = pool.array<NodeChange>(count);
}

bool InstanceOverrideStash::encode(kiwi::ByteBuffer &_bb) {
  if (overridePathOfSwappedInstance() != nullptr) {
    _bb.writeVarUint(1);
    if (!_data_overridePathOfSwappedInstance->encode(_bb)) return false;
  }
  if (componentKey() != nullptr) {
    _bb.writeVarUint(2);
    _bb.writeString(_data_componentKey.c_str());
  }
  if (overrides() != nullptr) {
    _bb.writeVarUint(3);
    _bb.writeVarUint(_data_overrides.size());
    for (NodeChange &_it : _data_overrides) if (!_it.encode(_bb)) return false;
  }
  _bb.writeVarUint(0);
  return true;
}

bool InstanceOverrideStash::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  uint32_t _count;
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        _data_overridePathOfSwappedInstance = _pool.allocate<GUIDPath>();
        if (!_data_overridePathOfSwappedInstance->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 2: {
        if (!_bb.readString(_data_componentKey, _pool)) return false;
        set_componentKey(_data_componentKey);
        break;
      }
      case 3: {
        if (!_bb.readVarUint(_count)) return false;
        for (NodeChange &_it : set_overrides(_pool, _count)) if (!_it.decode(_bb, _pool, _schema)) return false;
        break;
      }
      default: {
        if (!_schema || !_schema->skipInstanceOverrideStashField(_bb, _type)) return false;
        break;
      }
    }
  }
}

GUIDPath *InstanceOverrideStashV2::overridePathOfSwappedInstance() {
  return _data_overridePathOfSwappedInstance;
}

const GUIDPath *InstanceOverrideStashV2::overridePathOfSwappedInstance() const {
  return _data_overridePathOfSwappedInstance;
}

void InstanceOverrideStashV2::set_overridePathOfSwappedInstance(GUIDPath *value) {
  _data_overridePathOfSwappedInstance = value;
}

GUID *InstanceOverrideStashV2::localSymbolID() {
  return _data_localSymbolID;
}

const GUID *InstanceOverrideStashV2::localSymbolID() const {
  return _data_localSymbolID;
}

void InstanceOverrideStashV2::set_localSymbolID(GUID *value) {
  _data_localSymbolID = value;
}

kiwi::Array<NodeChange> *InstanceOverrideStashV2::overrides() {
  return _flags[0] & 4 ? &_data_overrides : nullptr;
}

const kiwi::Array<NodeChange> *InstanceOverrideStashV2::overrides() const {
  return _flags[0] & 4 ? &_data_overrides : nullptr;
}

kiwi::Array<NodeChange> &InstanceOverrideStashV2::set_overrides(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[0] |= 4; return _data_overrides = pool.array<NodeChange>(count);
}

bool InstanceOverrideStashV2::encode(kiwi::ByteBuffer &_bb) {
  if (overridePathOfSwappedInstance() != nullptr) {
    _bb.writeVarUint(1);
    if (!_data_overridePathOfSwappedInstance->encode(_bb)) return false;
  }
  if (localSymbolID() != nullptr) {
    _bb.writeVarUint(2);
    if (!_data_localSymbolID->encode(_bb)) return false;
  }
  if (overrides() != nullptr) {
    _bb.writeVarUint(3);
    _bb.writeVarUint(_data_overrides.size());
    for (NodeChange &_it : _data_overrides) if (!_it.encode(_bb)) return false;
  }
  _bb.writeVarUint(0);
  return true;
}

bool InstanceOverrideStashV2::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  uint32_t _count;
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        _data_overridePathOfSwappedInstance = _pool.allocate<GUIDPath>();
        if (!_data_overridePathOfSwappedInstance->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 2: {
        _data_localSymbolID = _pool.allocate<GUID>();
        if (!_data_localSymbolID->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 3: {
        if (!_bb.readVarUint(_count)) return false;
        for (NodeChange &_it : set_overrides(_pool, _count)) if (!_it.decode(_bb, _pool, _schema)) return false;
        break;
      }
      default: {
        if (!_schema || !_schema->skipInstanceOverrideStashV2Field(_bb, _type)) return false;
        break;
      }
    }
  }
}

EffectType *Effect::type() {
  return _flags[0] & 1 ? &_data_type : nullptr;
}

const EffectType *Effect::type() const {
  return _flags[0] & 1 ? &_data_type : nullptr;
}

void Effect::set_type(const EffectType &value) {
  _flags[0] |= 1; _data_type = value;
}

Color *Effect::color() {
  return _data_color;
}

const Color *Effect::color() const {
  return _data_color;
}

void Effect::set_color(Color *value) {
  _data_color = value;
}

Vector *Effect::offset() {
  return _data_offset;
}

const Vector *Effect::offset() const {
  return _data_offset;
}

void Effect::set_offset(Vector *value) {
  _data_offset = value;
}

float *Effect::radius() {
  return _flags[0] & 8 ? &_data_radius : nullptr;
}

const float *Effect::radius() const {
  return _flags[0] & 8 ? &_data_radius : nullptr;
}

void Effect::set_radius(const float &value) {
  _flags[0] |= 8; _data_radius = value;
}

bool *Effect::visible() {
  return _flags[0] & 16 ? &_data_visible : nullptr;
}

const bool *Effect::visible() const {
  return _flags[0] & 16 ? &_data_visible : nullptr;
}

void Effect::set_visible(const bool &value) {
  _flags[0] |= 16; _data_visible = value;
}

BlendMode *Effect::blendMode() {
  return _flags[0] & 32 ? &_data_blendMode : nullptr;
}

const BlendMode *Effect::blendMode() const {
  return _flags[0] & 32 ? &_data_blendMode : nullptr;
}

void Effect::set_blendMode(const BlendMode &value) {
  _flags[0] |= 32; _data_blendMode = value;
}

float *Effect::spread() {
  return _flags[0] & 64 ? &_data_spread : nullptr;
}

const float *Effect::spread() const {
  return _flags[0] & 64 ? &_data_spread : nullptr;
}

void Effect::set_spread(const float &value) {
  _flags[0] |= 64; _data_spread = value;
}

bool *Effect::showShadowBehindNode() {
  return _flags[0] & 128 ? &_data_showShadowBehindNode : nullptr;
}

const bool *Effect::showShadowBehindNode() const {
  return _flags[0] & 128 ? &_data_showShadowBehindNode : nullptr;
}

void Effect::set_showShadowBehindNode(const bool &value) {
  _flags[0] |= 128; _data_showShadowBehindNode = value;
}

bool Effect::encode(kiwi::ByteBuffer &_bb) {
  if (type() != nullptr) {
    _bb.writeVarUint(1);
    _bb.writeVarUint(static_cast<uint32_t>(_data_type));
  }
  if (color() != nullptr) {
    _bb.writeVarUint(2);
    if (!_data_color->encode(_bb)) return false;
  }
  if (offset() != nullptr) {
    _bb.writeVarUint(3);
    if (!_data_offset->encode(_bb)) return false;
  }
  if (radius() != nullptr) {
    _bb.writeVarUint(4);
    _bb.writeVarFloat(_data_radius);
  }
  if (visible() != nullptr) {
    _bb.writeVarUint(5);
    _bb.writeByte(_data_visible);
  }
  if (blendMode() != nullptr) {
    _bb.writeVarUint(6);
    _bb.writeVarUint(static_cast<uint32_t>(_data_blendMode));
  }
  if (spread() != nullptr) {
    _bb.writeVarUint(7);
    _bb.writeVarFloat(_data_spread);
  }
  if (showShadowBehindNode() != nullptr) {
    _bb.writeVarUint(8);
    _bb.writeByte(_data_showShadowBehindNode);
  }
  _bb.writeVarUint(0);
  return true;
}

bool Effect::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_type))) return false;
        set_type(_data_type);
        break;
      }
      case 2: {
        _data_color = _pool.allocate<Color>();
        if (!_data_color->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 3: {
        _data_offset = _pool.allocate<Vector>();
        if (!_data_offset->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 4: {
        if (!_bb.readVarFloat(_data_radius)) return false;
        set_radius(_data_radius);
        break;
      }
      case 5: {
        if (!_bb.readByte(_data_visible)) return false;
        set_visible(_data_visible);
        break;
      }
      case 6: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_blendMode))) return false;
        set_blendMode(_data_blendMode);
        break;
      }
      case 7: {
        if (!_bb.readVarFloat(_data_spread)) return false;
        set_spread(_data_spread);
        break;
      }
      case 8: {
        if (!_bb.readByte(_data_showShadowBehindNode)) return false;
        set_showShadowBehindNode(_data_showShadowBehindNode);
        break;
      }
      default: {
        if (!_schema || !_schema->skipEffectField(_bb, _type)) return false;
        break;
      }
    }
  }
}

TransitionType *TransitionInfo::type() {
  return _flags[0] & 1 ? &_data_type : nullptr;
}

const TransitionType *TransitionInfo::type() const {
  return _flags[0] & 1 ? &_data_type : nullptr;
}

void TransitionInfo::set_type(const TransitionType &value) {
  _flags[0] |= 1; _data_type = value;
}

float *TransitionInfo::duration() {
  return _flags[0] & 2 ? &_data_duration : nullptr;
}

const float *TransitionInfo::duration() const {
  return _flags[0] & 2 ? &_data_duration : nullptr;
}

void TransitionInfo::set_duration(const float &value) {
  _flags[0] |= 2; _data_duration = value;
}

bool TransitionInfo::encode(kiwi::ByteBuffer &_bb) {
  if (type() != nullptr) {
    _bb.writeVarUint(1);
    _bb.writeVarUint(static_cast<uint32_t>(_data_type));
  }
  if (duration() != nullptr) {
    _bb.writeVarUint(2);
    _bb.writeVarFloat(_data_duration);
  }
  _bb.writeVarUint(0);
  return true;
}

bool TransitionInfo::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_type))) return false;
        set_type(_data_type);
        break;
      }
      case 2: {
        if (!_bb.readVarFloat(_data_duration)) return false;
        set_duration(_data_duration);
        break;
      }
      default: {
        if (!_schema || !_schema->skipTransitionInfoField(_bb, _type)) return false;
        break;
      }
    }
  }
}

PrototypeDeviceType *PrototypeDevice::type() {
  return _flags[0] & 1 ? &_data_type : nullptr;
}

const PrototypeDeviceType *PrototypeDevice::type() const {
  return _flags[0] & 1 ? &_data_type : nullptr;
}

void PrototypeDevice::set_type(const PrototypeDeviceType &value) {
  _flags[0] |= 1; _data_type = value;
}

Vector *PrototypeDevice::size() {
  return _data_size;
}

const Vector *PrototypeDevice::size() const {
  return _data_size;
}

void PrototypeDevice::set_size(Vector *value) {
  _data_size = value;
}

kiwi::String *PrototypeDevice::presetIdentifier() {
  return _flags[0] & 4 ? &_data_presetIdentifier : nullptr;
}

const kiwi::String *PrototypeDevice::presetIdentifier() const {
  return _flags[0] & 4 ? &_data_presetIdentifier : nullptr;
}

void PrototypeDevice::set_presetIdentifier(const kiwi::String &value) {
  _flags[0] |= 4; _data_presetIdentifier = value;
}

DeviceRotation *PrototypeDevice::rotation() {
  return _flags[0] & 8 ? &_data_rotation : nullptr;
}

const DeviceRotation *PrototypeDevice::rotation() const {
  return _flags[0] & 8 ? &_data_rotation : nullptr;
}

void PrototypeDevice::set_rotation(const DeviceRotation &value) {
  _flags[0] |= 8; _data_rotation = value;
}

bool PrototypeDevice::encode(kiwi::ByteBuffer &_bb) {
  if (type() != nullptr) {
    _bb.writeVarUint(1);
    _bb.writeVarUint(static_cast<uint32_t>(_data_type));
  }
  if (size() != nullptr) {
    _bb.writeVarUint(2);
    if (!_data_size->encode(_bb)) return false;
  }
  if (presetIdentifier() != nullptr) {
    _bb.writeVarUint(3);
    _bb.writeString(_data_presetIdentifier.c_str());
  }
  if (rotation() != nullptr) {
    _bb.writeVarUint(4);
    _bb.writeVarUint(static_cast<uint32_t>(_data_rotation));
  }
  _bb.writeVarUint(0);
  return true;
}

bool PrototypeDevice::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_type))) return false;
        set_type(_data_type);
        break;
      }
      case 2: {
        _data_size = _pool.allocate<Vector>();
        if (!_data_size->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 3: {
        if (!_bb.readString(_data_presetIdentifier, _pool)) return false;
        set_presetIdentifier(_data_presetIdentifier);
        break;
      }
      case 4: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_rotation))) return false;
        set_rotation(_data_rotation);
        break;
      }
      default: {
        if (!_schema || !_schema->skipPrototypeDeviceField(_bb, _type)) return false;
        break;
      }
    }
  }
}

OverlayBackgroundType *OverlayBackgroundAppearance::backgroundType() {
  return _flags[0] & 1 ? &_data_backgroundType : nullptr;
}

const OverlayBackgroundType *OverlayBackgroundAppearance::backgroundType() const {
  return _flags[0] & 1 ? &_data_backgroundType : nullptr;
}

void OverlayBackgroundAppearance::set_backgroundType(const OverlayBackgroundType &value) {
  _flags[0] |= 1; _data_backgroundType = value;
}

Color *OverlayBackgroundAppearance::backgroundColor() {
  return _data_backgroundColor;
}

const Color *OverlayBackgroundAppearance::backgroundColor() const {
  return _data_backgroundColor;
}

void OverlayBackgroundAppearance::set_backgroundColor(Color *value) {
  _data_backgroundColor = value;
}

bool OverlayBackgroundAppearance::encode(kiwi::ByteBuffer &_bb) {
  if (backgroundType() != nullptr) {
    _bb.writeVarUint(1);
    _bb.writeVarUint(static_cast<uint32_t>(_data_backgroundType));
  }
  if (backgroundColor() != nullptr) {
    _bb.writeVarUint(2);
    if (!_data_backgroundColor->encode(_bb)) return false;
  }
  _bb.writeVarUint(0);
  return true;
}

bool OverlayBackgroundAppearance::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_backgroundType))) return false;
        set_backgroundType(_data_backgroundType);
        break;
      }
      case 2: {
        _data_backgroundColor = _pool.allocate<Color>();
        if (!_data_backgroundColor->decode(_bb, _pool, _schema)) return false;
        break;
      }
      default: {
        if (!_schema || !_schema->skipOverlayBackgroundAppearanceField(_bb, _type)) return false;
        break;
      }
    }
  }
}

kiwi::String *ExportSettings::suffix() {
  return _flags[0] & 1 ? &_data_suffix : nullptr;
}

const kiwi::String *ExportSettings::suffix() const {
  return _flags[0] & 1 ? &_data_suffix : nullptr;
}

void ExportSettings::set_suffix(const kiwi::String &value) {
  _flags[0] |= 1; _data_suffix = value;
}

ImageType *ExportSettings::imageType() {
  return _flags[0] & 2 ? &_data_imageType : nullptr;
}

const ImageType *ExportSettings::imageType() const {
  return _flags[0] & 2 ? &_data_imageType : nullptr;
}

void ExportSettings::set_imageType(const ImageType &value) {
  _flags[0] |= 2; _data_imageType = value;
}

ExportConstraint *ExportSettings::constraint() {
  return _data_constraint;
}

const ExportConstraint *ExportSettings::constraint() const {
  return _data_constraint;
}

void ExportSettings::set_constraint(ExportConstraint *value) {
  _data_constraint = value;
}

bool *ExportSettings::svgDataName() {
  return _flags[0] & 8 ? &_data_svgDataName : nullptr;
}

const bool *ExportSettings::svgDataName() const {
  return _flags[0] & 8 ? &_data_svgDataName : nullptr;
}

void ExportSettings::set_svgDataName(const bool &value) {
  _flags[0] |= 8; _data_svgDataName = value;
}

ExportSVGIDMode *ExportSettings::svgIDMode() {
  return _flags[0] & 16 ? &_data_svgIDMode : nullptr;
}

const ExportSVGIDMode *ExportSettings::svgIDMode() const {
  return _flags[0] & 16 ? &_data_svgIDMode : nullptr;
}

void ExportSettings::set_svgIDMode(const ExportSVGIDMode &value) {
  _flags[0] |= 16; _data_svgIDMode = value;
}

bool *ExportSettings::svgOutlineText() {
  return _flags[0] & 32 ? &_data_svgOutlineText : nullptr;
}

const bool *ExportSettings::svgOutlineText() const {
  return _flags[0] & 32 ? &_data_svgOutlineText : nullptr;
}

void ExportSettings::set_svgOutlineText(const bool &value) {
  _flags[0] |= 32; _data_svgOutlineText = value;
}

bool *ExportSettings::contentsOnly() {
  return _flags[0] & 64 ? &_data_contentsOnly : nullptr;
}

const bool *ExportSettings::contentsOnly() const {
  return _flags[0] & 64 ? &_data_contentsOnly : nullptr;
}

void ExportSettings::set_contentsOnly(const bool &value) {
  _flags[0] |= 64; _data_contentsOnly = value;
}

bool *ExportSettings::svgForceStrokeMasks() {
  return _flags[0] & 128 ? &_data_svgForceStrokeMasks : nullptr;
}

const bool *ExportSettings::svgForceStrokeMasks() const {
  return _flags[0] & 128 ? &_data_svgForceStrokeMasks : nullptr;
}

void ExportSettings::set_svgForceStrokeMasks(const bool &value) {
  _flags[0] |= 128; _data_svgForceStrokeMasks = value;
}

bool *ExportSettings::useAbsoluteBounds() {
  return _flags[0] & 256 ? &_data_useAbsoluteBounds : nullptr;
}

const bool *ExportSettings::useAbsoluteBounds() const {
  return _flags[0] & 256 ? &_data_useAbsoluteBounds : nullptr;
}

void ExportSettings::set_useAbsoluteBounds(const bool &value) {
  _flags[0] |= 256; _data_useAbsoluteBounds = value;
}

ExportColorProfile *ExportSettings::colorProfile() {
  return _flags[0] & 512 ? &_data_colorProfile : nullptr;
}

const ExportColorProfile *ExportSettings::colorProfile() const {
  return _flags[0] & 512 ? &_data_colorProfile : nullptr;
}

void ExportSettings::set_colorProfile(const ExportColorProfile &value) {
  _flags[0] |= 512; _data_colorProfile = value;
}

bool ExportSettings::encode(kiwi::ByteBuffer &_bb) {
  if (suffix() != nullptr) {
    _bb.writeVarUint(1);
    _bb.writeString(_data_suffix.c_str());
  }
  if (imageType() != nullptr) {
    _bb.writeVarUint(2);
    _bb.writeVarUint(static_cast<uint32_t>(_data_imageType));
  }
  if (constraint() != nullptr) {
    _bb.writeVarUint(3);
    if (!_data_constraint->encode(_bb)) return false;
  }
  if (svgDataName() != nullptr) {
    _bb.writeVarUint(4);
    _bb.writeByte(_data_svgDataName);
  }
  if (svgIDMode() != nullptr) {
    _bb.writeVarUint(5);
    _bb.writeVarUint(static_cast<uint32_t>(_data_svgIDMode));
  }
  if (svgOutlineText() != nullptr) {
    _bb.writeVarUint(6);
    _bb.writeByte(_data_svgOutlineText);
  }
  if (contentsOnly() != nullptr) {
    _bb.writeVarUint(7);
    _bb.writeByte(_data_contentsOnly);
  }
  if (svgForceStrokeMasks() != nullptr) {
    _bb.writeVarUint(8);
    _bb.writeByte(_data_svgForceStrokeMasks);
  }
  if (useAbsoluteBounds() != nullptr) {
    _bb.writeVarUint(9);
    _bb.writeByte(_data_useAbsoluteBounds);
  }
  if (colorProfile() != nullptr) {
    _bb.writeVarUint(10);
    _bb.writeVarUint(static_cast<uint32_t>(_data_colorProfile));
  }
  _bb.writeVarUint(0);
  return true;
}

bool ExportSettings::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        if (!_bb.readString(_data_suffix, _pool)) return false;
        set_suffix(_data_suffix);
        break;
      }
      case 2: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_imageType))) return false;
        set_imageType(_data_imageType);
        break;
      }
      case 3: {
        _data_constraint = _pool.allocate<ExportConstraint>();
        if (!_data_constraint->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 4: {
        if (!_bb.readByte(_data_svgDataName)) return false;
        set_svgDataName(_data_svgDataName);
        break;
      }
      case 5: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_svgIDMode))) return false;
        set_svgIDMode(_data_svgIDMode);
        break;
      }
      case 6: {
        if (!_bb.readByte(_data_svgOutlineText)) return false;
        set_svgOutlineText(_data_svgOutlineText);
        break;
      }
      case 7: {
        if (!_bb.readByte(_data_contentsOnly)) return false;
        set_contentsOnly(_data_contentsOnly);
        break;
      }
      case 8: {
        if (!_bb.readByte(_data_svgForceStrokeMasks)) return false;
        set_svgForceStrokeMasks(_data_svgForceStrokeMasks);
        break;
      }
      case 9: {
        if (!_bb.readByte(_data_useAbsoluteBounds)) return false;
        set_useAbsoluteBounds(_data_useAbsoluteBounds);
        break;
      }
      case 10: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_colorProfile))) return false;
        set_colorProfile(_data_colorProfile);
        break;
      }
      default: {
        if (!_schema || !_schema->skipExportSettingsField(_bb, _type)) return false;
        break;
      }
    }
  }
}

LayoutGridType *LayoutGrid::type() {
  return _flags[0] & 1 ? &_data_type : nullptr;
}

const LayoutGridType *LayoutGrid::type() const {
  return _flags[0] & 1 ? &_data_type : nullptr;
}

void LayoutGrid::set_type(const LayoutGridType &value) {
  _flags[0] |= 1; _data_type = value;
}

Axis *LayoutGrid::axis() {
  return _flags[0] & 2 ? &_data_axis : nullptr;
}

const Axis *LayoutGrid::axis() const {
  return _flags[0] & 2 ? &_data_axis : nullptr;
}

void LayoutGrid::set_axis(const Axis &value) {
  _flags[0] |= 2; _data_axis = value;
}

bool *LayoutGrid::visible() {
  return _flags[0] & 4 ? &_data_visible : nullptr;
}

const bool *LayoutGrid::visible() const {
  return _flags[0] & 4 ? &_data_visible : nullptr;
}

void LayoutGrid::set_visible(const bool &value) {
  _flags[0] |= 4; _data_visible = value;
}

int32_t *LayoutGrid::numSections() {
  return _flags[0] & 8 ? &_data_numSections : nullptr;
}

const int32_t *LayoutGrid::numSections() const {
  return _flags[0] & 8 ? &_data_numSections : nullptr;
}

void LayoutGrid::set_numSections(const int32_t &value) {
  _flags[0] |= 8; _data_numSections = value;
}

float *LayoutGrid::offset() {
  return _flags[0] & 16 ? &_data_offset : nullptr;
}

const float *LayoutGrid::offset() const {
  return _flags[0] & 16 ? &_data_offset : nullptr;
}

void LayoutGrid::set_offset(const float &value) {
  _flags[0] |= 16; _data_offset = value;
}

float *LayoutGrid::sectionSize() {
  return _flags[0] & 32 ? &_data_sectionSize : nullptr;
}

const float *LayoutGrid::sectionSize() const {
  return _flags[0] & 32 ? &_data_sectionSize : nullptr;
}

void LayoutGrid::set_sectionSize(const float &value) {
  _flags[0] |= 32; _data_sectionSize = value;
}

float *LayoutGrid::gutterSize() {
  return _flags[0] & 64 ? &_data_gutterSize : nullptr;
}

const float *LayoutGrid::gutterSize() const {
  return _flags[0] & 64 ? &_data_gutterSize : nullptr;
}

void LayoutGrid::set_gutterSize(const float &value) {
  _flags[0] |= 64; _data_gutterSize = value;
}

Color *LayoutGrid::color() {
  return _data_color;
}

const Color *LayoutGrid::color() const {
  return _data_color;
}

void LayoutGrid::set_color(Color *value) {
  _data_color = value;
}

LayoutGridPattern *LayoutGrid::pattern() {
  return _flags[0] & 256 ? &_data_pattern : nullptr;
}

const LayoutGridPattern *LayoutGrid::pattern() const {
  return _flags[0] & 256 ? &_data_pattern : nullptr;
}

void LayoutGrid::set_pattern(const LayoutGridPattern &value) {
  _flags[0] |= 256; _data_pattern = value;
}

bool LayoutGrid::encode(kiwi::ByteBuffer &_bb) {
  if (type() != nullptr) {
    _bb.writeVarUint(1);
    _bb.writeVarUint(static_cast<uint32_t>(_data_type));
  }
  if (axis() != nullptr) {
    _bb.writeVarUint(2);
    _bb.writeVarUint(static_cast<uint32_t>(_data_axis));
  }
  if (visible() != nullptr) {
    _bb.writeVarUint(3);
    _bb.writeByte(_data_visible);
  }
  if (numSections() != nullptr) {
    _bb.writeVarUint(4);
    _bb.writeVarInt(_data_numSections);
  }
  if (offset() != nullptr) {
    _bb.writeVarUint(5);
    _bb.writeVarFloat(_data_offset);
  }
  if (sectionSize() != nullptr) {
    _bb.writeVarUint(6);
    _bb.writeVarFloat(_data_sectionSize);
  }
  if (gutterSize() != nullptr) {
    _bb.writeVarUint(7);
    _bb.writeVarFloat(_data_gutterSize);
  }
  if (color() != nullptr) {
    _bb.writeVarUint(8);
    if (!_data_color->encode(_bb)) return false;
  }
  if (pattern() != nullptr) {
    _bb.writeVarUint(9);
    _bb.writeVarUint(static_cast<uint32_t>(_data_pattern));
  }
  _bb.writeVarUint(0);
  return true;
}

bool LayoutGrid::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_type))) return false;
        set_type(_data_type);
        break;
      }
      case 2: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_axis))) return false;
        set_axis(_data_axis);
        break;
      }
      case 3: {
        if (!_bb.readByte(_data_visible)) return false;
        set_visible(_data_visible);
        break;
      }
      case 4: {
        if (!_bb.readVarInt(_data_numSections)) return false;
        set_numSections(_data_numSections);
        break;
      }
      case 5: {
        if (!_bb.readVarFloat(_data_offset)) return false;
        set_offset(_data_offset);
        break;
      }
      case 6: {
        if (!_bb.readVarFloat(_data_sectionSize)) return false;
        set_sectionSize(_data_sectionSize);
        break;
      }
      case 7: {
        if (!_bb.readVarFloat(_data_gutterSize)) return false;
        set_gutterSize(_data_gutterSize);
        break;
      }
      case 8: {
        _data_color = _pool.allocate<Color>();
        if (!_data_color->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 9: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_pattern))) return false;
        set_pattern(_data_pattern);
        break;
      }
      default: {
        if (!_schema || !_schema->skipLayoutGridField(_bb, _type)) return false;
        break;
      }
    }
  }
}

Axis *Guide::axis() {
  return _flags[0] & 1 ? &_data_axis : nullptr;
}

const Axis *Guide::axis() const {
  return _flags[0] & 1 ? &_data_axis : nullptr;
}

void Guide::set_axis(const Axis &value) {
  _flags[0] |= 1; _data_axis = value;
}

float *Guide::offset() {
  return _flags[0] & 2 ? &_data_offset : nullptr;
}

const float *Guide::offset() const {
  return _flags[0] & 2 ? &_data_offset : nullptr;
}

void Guide::set_offset(const float &value) {
  _flags[0] |= 2; _data_offset = value;
}

GUID *Guide::guid() {
  return _data_guid;
}

const GUID *Guide::guid() const {
  return _data_guid;
}

void Guide::set_guid(GUID *value) {
  _data_guid = value;
}

bool Guide::encode(kiwi::ByteBuffer &_bb) {
  if (axis() != nullptr) {
    _bb.writeVarUint(1);
    _bb.writeVarUint(static_cast<uint32_t>(_data_axis));
  }
  if (offset() != nullptr) {
    _bb.writeVarUint(2);
    _bb.writeVarFloat(_data_offset);
  }
  if (guid() != nullptr) {
    _bb.writeVarUint(3);
    if (!_data_guid->encode(_bb)) return false;
  }
  _bb.writeVarUint(0);
  return true;
}

bool Guide::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_axis))) return false;
        set_axis(_data_axis);
        break;
      }
      case 2: {
        if (!_bb.readVarFloat(_data_offset)) return false;
        set_offset(_data_offset);
        break;
      }
      case 3: {
        _data_guid = _pool.allocate<GUID>();
        if (!_data_guid->decode(_bb, _pool, _schema)) return false;
        break;
      }
      default: {
        if (!_schema || !_schema->skipGuideField(_bb, _type)) return false;
        break;
      }
    }
  }
}

WindingRule *Path::windingRule() {
  return _flags[0] & 1 ? &_data_windingRule : nullptr;
}

const WindingRule *Path::windingRule() const {
  return _flags[0] & 1 ? &_data_windingRule : nullptr;
}

void Path::set_windingRule(const WindingRule &value) {
  _flags[0] |= 1; _data_windingRule = value;
}

uint32_t *Path::commandsBlob() {
  return _flags[0] & 2 ? &_data_commandsBlob : nullptr;
}

const uint32_t *Path::commandsBlob() const {
  return _flags[0] & 2 ? &_data_commandsBlob : nullptr;
}

void Path::set_commandsBlob(const uint32_t &value) {
  _flags[0] |= 2; _data_commandsBlob = value;
}

uint32_t *Path::styleID() {
  return _flags[0] & 4 ? &_data_styleID : nullptr;
}

const uint32_t *Path::styleID() const {
  return _flags[0] & 4 ? &_data_styleID : nullptr;
}

void Path::set_styleID(const uint32_t &value) {
  _flags[0] |= 4; _data_styleID = value;
}

bool Path::encode(kiwi::ByteBuffer &_bb) {
  if (windingRule() != nullptr) {
    _bb.writeVarUint(1);
    _bb.writeVarUint(static_cast<uint32_t>(_data_windingRule));
  }
  if (commandsBlob() != nullptr) {
    _bb.writeVarUint(2);
    _bb.writeVarUint(_data_commandsBlob);
  }
  if (styleID() != nullptr) {
    _bb.writeVarUint(3);
    _bb.writeVarUint(_data_styleID);
  }
  _bb.writeVarUint(0);
  return true;
}

bool Path::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_windingRule))) return false;
        set_windingRule(_data_windingRule);
        break;
      }
      case 2: {
        if (!_bb.readVarUint(_data_commandsBlob)) return false;
        set_commandsBlob(_data_commandsBlob);
        break;
      }
      case 3: {
        if (!_bb.readVarUint(_data_styleID)) return false;
        set_styleID(_data_styleID);
        break;
      }
      default: {
        if (!_schema || !_schema->skipPathField(_bb, _type)) return false;
        break;
      }
    }
  }
}

kiwi::String *SharedStyleReference::styleKey() {
  return _flags[0] & 1 ? &_data_styleKey : nullptr;
}

const kiwi::String *SharedStyleReference::styleKey() const {
  return _flags[0] & 1 ? &_data_styleKey : nullptr;
}

void SharedStyleReference::set_styleKey(const kiwi::String &value) {
  _flags[0] |= 1; _data_styleKey = value;
}

kiwi::String *SharedStyleReference::versionHash() {
  return _flags[0] & 2 ? &_data_versionHash : nullptr;
}

const kiwi::String *SharedStyleReference::versionHash() const {
  return _flags[0] & 2 ? &_data_versionHash : nullptr;
}

void SharedStyleReference::set_versionHash(const kiwi::String &value) {
  _flags[0] |= 2; _data_versionHash = value;
}

bool SharedStyleReference::encode(kiwi::ByteBuffer &_bb) {
  if (styleKey() != nullptr) {
    _bb.writeVarUint(1);
    _bb.writeString(_data_styleKey.c_str());
  }
  if (versionHash() != nullptr) {
    _bb.writeVarUint(2);
    _bb.writeString(_data_versionHash.c_str());
  }
  _bb.writeVarUint(0);
  return true;
}

bool SharedStyleReference::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        if (!_bb.readString(_data_styleKey, _pool)) return false;
        set_styleKey(_data_styleKey);
        break;
      }
      case 2: {
        if (!_bb.readString(_data_versionHash, _pool)) return false;
        set_versionHash(_data_versionHash);
        break;
      }
      default: {
        if (!_schema || !_schema->skipSharedStyleReferenceField(_bb, _type)) return false;
        break;
      }
    }
  }
}

kiwi::String *SharedStyleMasterData::styleKey() {
  return _flags[0] & 1 ? &_data_styleKey : nullptr;
}

const kiwi::String *SharedStyleMasterData::styleKey() const {
  return _flags[0] & 1 ? &_data_styleKey : nullptr;
}

void SharedStyleMasterData::set_styleKey(const kiwi::String &value) {
  _flags[0] |= 1; _data_styleKey = value;
}

kiwi::String *SharedStyleMasterData::sortPosition() {
  return _flags[0] & 2 ? &_data_sortPosition : nullptr;
}

const kiwi::String *SharedStyleMasterData::sortPosition() const {
  return _flags[0] & 2 ? &_data_sortPosition : nullptr;
}

void SharedStyleMasterData::set_sortPosition(const kiwi::String &value) {
  _flags[0] |= 2; _data_sortPosition = value;
}

kiwi::String *SharedStyleMasterData::fileKey() {
  return _flags[0] & 4 ? &_data_fileKey : nullptr;
}

const kiwi::String *SharedStyleMasterData::fileKey() const {
  return _flags[0] & 4 ? &_data_fileKey : nullptr;
}

void SharedStyleMasterData::set_fileKey(const kiwi::String &value) {
  _flags[0] |= 4; _data_fileKey = value;
}

bool SharedStyleMasterData::encode(kiwi::ByteBuffer &_bb) {
  if (styleKey() != nullptr) {
    _bb.writeVarUint(1);
    _bb.writeString(_data_styleKey.c_str());
  }
  if (sortPosition() != nullptr) {
    _bb.writeVarUint(2);
    _bb.writeString(_data_sortPosition.c_str());
  }
  if (fileKey() != nullptr) {
    _bb.writeVarUint(3);
    _bb.writeString(_data_fileKey.c_str());
  }
  _bb.writeVarUint(0);
  return true;
}

bool SharedStyleMasterData::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        if (!_bb.readString(_data_styleKey, _pool)) return false;
        set_styleKey(_data_styleKey);
        break;
      }
      case 2: {
        if (!_bb.readString(_data_sortPosition, _pool)) return false;
        set_sortPosition(_data_sortPosition);
        break;
      }
      case 3: {
        if (!_bb.readString(_data_fileKey, _pool)) return false;
        set_fileKey(_data_fileKey);
        break;
      }
      default: {
        if (!_schema || !_schema->skipSharedStyleMasterDataField(_bb, _type)) return false;
        break;
      }
    }
  }
}

float *ArcData::startingAngle() {
  return _flags[0] & 1 ? &_data_startingAngle : nullptr;
}

const float *ArcData::startingAngle() const {
  return _flags[0] & 1 ? &_data_startingAngle : nullptr;
}

void ArcData::set_startingAngle(const float &value) {
  _flags[0] |= 1; _data_startingAngle = value;
}

float *ArcData::endingAngle() {
  return _flags[0] & 2 ? &_data_endingAngle : nullptr;
}

const float *ArcData::endingAngle() const {
  return _flags[0] & 2 ? &_data_endingAngle : nullptr;
}

void ArcData::set_endingAngle(const float &value) {
  _flags[0] |= 2; _data_endingAngle = value;
}

float *ArcData::innerRadius() {
  return _flags[0] & 4 ? &_data_innerRadius : nullptr;
}

const float *ArcData::innerRadius() const {
  return _flags[0] & 4 ? &_data_innerRadius : nullptr;
}

void ArcData::set_innerRadius(const float &value) {
  _flags[0] |= 4; _data_innerRadius = value;
}

bool ArcData::encode(kiwi::ByteBuffer &_bb) {
  if (startingAngle() != nullptr) {
    _bb.writeVarUint(1);
    _bb.writeVarFloat(_data_startingAngle);
  }
  if (endingAngle() != nullptr) {
    _bb.writeVarUint(2);
    _bb.writeVarFloat(_data_endingAngle);
  }
  if (innerRadius() != nullptr) {
    _bb.writeVarUint(3);
    _bb.writeVarFloat(_data_innerRadius);
  }
  _bb.writeVarUint(0);
  return true;
}

bool ArcData::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        if (!_bb.readVarFloat(_data_startingAngle)) return false;
        set_startingAngle(_data_startingAngle);
        break;
      }
      case 2: {
        if (!_bb.readVarFloat(_data_endingAngle)) return false;
        set_endingAngle(_data_endingAngle);
        break;
      }
      case 3: {
        if (!_bb.readVarFloat(_data_innerRadius)) return false;
        set_innerRadius(_data_innerRadius);
        break;
      }
      default: {
        if (!_schema || !_schema->skipArcDataField(_bb, _type)) return false;
        break;
      }
    }
  }
}

kiwi::String *SymbolLink::uri() {
  return _flags[0] & 1 ? &_data_uri : nullptr;
}

const kiwi::String *SymbolLink::uri() const {
  return _flags[0] & 1 ? &_data_uri : nullptr;
}

void SymbolLink::set_uri(const kiwi::String &value) {
  _flags[0] |= 1; _data_uri = value;
}

kiwi::String *SymbolLink::displayName() {
  return _flags[0] & 2 ? &_data_displayName : nullptr;
}

const kiwi::String *SymbolLink::displayName() const {
  return _flags[0] & 2 ? &_data_displayName : nullptr;
}

void SymbolLink::set_displayName(const kiwi::String &value) {
  _flags[0] |= 2; _data_displayName = value;
}

kiwi::String *SymbolLink::displayText() {
  return _flags[0] & 4 ? &_data_displayText : nullptr;
}

const kiwi::String *SymbolLink::displayText() const {
  return _flags[0] & 4 ? &_data_displayText : nullptr;
}

void SymbolLink::set_displayText(const kiwi::String &value) {
  _flags[0] |= 4; _data_displayText = value;
}

bool SymbolLink::encode(kiwi::ByteBuffer &_bb) {
  if (uri() != nullptr) {
    _bb.writeVarUint(1);
    _bb.writeString(_data_uri.c_str());
  }
  if (displayName() != nullptr) {
    _bb.writeVarUint(2);
    _bb.writeString(_data_displayName.c_str());
  }
  if (displayText() != nullptr) {
    _bb.writeVarUint(3);
    _bb.writeString(_data_displayText.c_str());
  }
  _bb.writeVarUint(0);
  return true;
}

bool SymbolLink::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        if (!_bb.readString(_data_uri, _pool)) return false;
        set_uri(_data_uri);
        break;
      }
      case 2: {
        if (!_bb.readString(_data_displayName, _pool)) return false;
        set_displayName(_data_displayName);
        break;
      }
      case 3: {
        if (!_bb.readString(_data_displayText, _pool)) return false;
        set_displayText(_data_displayText);
        break;
      }
      default: {
        if (!_schema || !_schema->skipSymbolLinkField(_bb, _type)) return false;
        break;
      }
    }
  }
}

kiwi::String *PluginData::pluginID() {
  return _flags[0] & 1 ? &_data_pluginID : nullptr;
}

const kiwi::String *PluginData::pluginID() const {
  return _flags[0] & 1 ? &_data_pluginID : nullptr;
}

void PluginData::set_pluginID(const kiwi::String &value) {
  _flags[0] |= 1; _data_pluginID = value;
}

kiwi::String *PluginData::value() {
  return _flags[0] & 2 ? &_data_value : nullptr;
}

const kiwi::String *PluginData::value() const {
  return _flags[0] & 2 ? &_data_value : nullptr;
}

void PluginData::set_value(const kiwi::String &value) {
  _flags[0] |= 2; _data_value = value;
}

kiwi::String *PluginData::key() {
  return _flags[0] & 4 ? &_data_key : nullptr;
}

const kiwi::String *PluginData::key() const {
  return _flags[0] & 4 ? &_data_key : nullptr;
}

void PluginData::set_key(const kiwi::String &value) {
  _flags[0] |= 4; _data_key = value;
}

bool PluginData::encode(kiwi::ByteBuffer &_bb) {
  if (pluginID() != nullptr) {
    _bb.writeVarUint(1);
    _bb.writeString(_data_pluginID.c_str());
  }
  if (value() != nullptr) {
    _bb.writeVarUint(2);
    _bb.writeString(_data_value.c_str());
  }
  if (key() != nullptr) {
    _bb.writeVarUint(3);
    _bb.writeString(_data_key.c_str());
  }
  _bb.writeVarUint(0);
  return true;
}

bool PluginData::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        if (!_bb.readString(_data_pluginID, _pool)) return false;
        set_pluginID(_data_pluginID);
        break;
      }
      case 2: {
        if (!_bb.readString(_data_value, _pool)) return false;
        set_value(_data_value);
        break;
      }
      case 3: {
        if (!_bb.readString(_data_key, _pool)) return false;
        set_key(_data_key);
        break;
      }
      default: {
        if (!_schema || !_schema->skipPluginDataField(_bb, _type)) return false;
        break;
      }
    }
  }
}

kiwi::String *PluginRelaunchData::pluginID() {
  return _flags[0] & 1 ? &_data_pluginID : nullptr;
}

const kiwi::String *PluginRelaunchData::pluginID() const {
  return _flags[0] & 1 ? &_data_pluginID : nullptr;
}

void PluginRelaunchData::set_pluginID(const kiwi::String &value) {
  _flags[0] |= 1; _data_pluginID = value;
}

kiwi::String *PluginRelaunchData::message() {
  return _flags[0] & 2 ? &_data_message : nullptr;
}

const kiwi::String *PluginRelaunchData::message() const {
  return _flags[0] & 2 ? &_data_message : nullptr;
}

void PluginRelaunchData::set_message(const kiwi::String &value) {
  _flags[0] |= 2; _data_message = value;
}

kiwi::String *PluginRelaunchData::command() {
  return _flags[0] & 4 ? &_data_command : nullptr;
}

const kiwi::String *PluginRelaunchData::command() const {
  return _flags[0] & 4 ? &_data_command : nullptr;
}

void PluginRelaunchData::set_command(const kiwi::String &value) {
  _flags[0] |= 4; _data_command = value;
}

bool *PluginRelaunchData::isDeleted() {
  return _flags[0] & 8 ? &_data_isDeleted : nullptr;
}

const bool *PluginRelaunchData::isDeleted() const {
  return _flags[0] & 8 ? &_data_isDeleted : nullptr;
}

void PluginRelaunchData::set_isDeleted(const bool &value) {
  _flags[0] |= 8; _data_isDeleted = value;
}

bool PluginRelaunchData::encode(kiwi::ByteBuffer &_bb) {
  if (pluginID() != nullptr) {
    _bb.writeVarUint(1);
    _bb.writeString(_data_pluginID.c_str());
  }
  if (message() != nullptr) {
    _bb.writeVarUint(2);
    _bb.writeString(_data_message.c_str());
  }
  if (command() != nullptr) {
    _bb.writeVarUint(3);
    _bb.writeString(_data_command.c_str());
  }
  if (isDeleted() != nullptr) {
    _bb.writeVarUint(4);
    _bb.writeByte(_data_isDeleted);
  }
  _bb.writeVarUint(0);
  return true;
}

bool PluginRelaunchData::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        if (!_bb.readString(_data_pluginID, _pool)) return false;
        set_pluginID(_data_pluginID);
        break;
      }
      case 2: {
        if (!_bb.readString(_data_message, _pool)) return false;
        set_message(_data_message);
        break;
      }
      case 3: {
        if (!_bb.readString(_data_command, _pool)) return false;
        set_command(_data_command);
        break;
      }
      case 4: {
        if (!_bb.readByte(_data_isDeleted)) return false;
        set_isDeleted(_data_isDeleted);
        break;
      }
      default: {
        if (!_schema || !_schema->skipPluginRelaunchDataField(_bb, _type)) return false;
        break;
      }
    }
  }
}

uint32_t *MultiplayerFieldVersion::counter() {
  return _flags[0] & 1 ? &_data_counter : nullptr;
}

const uint32_t *MultiplayerFieldVersion::counter() const {
  return _flags[0] & 1 ? &_data_counter : nullptr;
}

void MultiplayerFieldVersion::set_counter(const uint32_t &value) {
  _flags[0] |= 1; _data_counter = value;
}

uint32_t *MultiplayerFieldVersion::sessionID() {
  return _flags[0] & 2 ? &_data_sessionID : nullptr;
}

const uint32_t *MultiplayerFieldVersion::sessionID() const {
  return _flags[0] & 2 ? &_data_sessionID : nullptr;
}

void MultiplayerFieldVersion::set_sessionID(const uint32_t &value) {
  _flags[0] |= 2; _data_sessionID = value;
}

bool MultiplayerFieldVersion::encode(kiwi::ByteBuffer &_bb) {
  if (counter() != nullptr) {
    _bb.writeVarUint(1);
    _bb.writeVarUint(_data_counter);
  }
  if (sessionID() != nullptr) {
    _bb.writeVarUint(2);
    _bb.writeVarUint(_data_sessionID);
  }
  _bb.writeVarUint(0);
  return true;
}

bool MultiplayerFieldVersion::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        if (!_bb.readVarUint(_data_counter)) return false;
        set_counter(_data_counter);
        break;
      }
      case 2: {
        if (!_bb.readVarUint(_data_sessionID)) return false;
        set_sessionID(_data_sessionID);
        break;
      }
      default: {
        if (!_schema || !_schema->skipMultiplayerFieldVersionField(_bb, _type)) return false;
        break;
      }
    }
  }
}

GUID *ConnectorEndpoint::endpointNodeID() {
  return _data_endpointNodeID;
}

const GUID *ConnectorEndpoint::endpointNodeID() const {
  return _data_endpointNodeID;
}

void ConnectorEndpoint::set_endpointNodeID(GUID *value) {
  _data_endpointNodeID = value;
}

Vector *ConnectorEndpoint::position() {
  return _data_position;
}

const Vector *ConnectorEndpoint::position() const {
  return _data_position;
}

void ConnectorEndpoint::set_position(Vector *value) {
  _data_position = value;
}

ConnectorMagnet *ConnectorEndpoint::magnet() {
  return _flags[0] & 4 ? &_data_magnet : nullptr;
}

const ConnectorMagnet *ConnectorEndpoint::magnet() const {
  return _flags[0] & 4 ? &_data_magnet : nullptr;
}

void ConnectorEndpoint::set_magnet(const ConnectorMagnet &value) {
  _flags[0] |= 4; _data_magnet = value;
}

bool ConnectorEndpoint::encode(kiwi::ByteBuffer &_bb) {
  if (endpointNodeID() != nullptr) {
    _bb.writeVarUint(1);
    if (!_data_endpointNodeID->encode(_bb)) return false;
  }
  if (position() != nullptr) {
    _bb.writeVarUint(2);
    if (!_data_position->encode(_bb)) return false;
  }
  if (magnet() != nullptr) {
    _bb.writeVarUint(3);
    _bb.writeVarUint(static_cast<uint32_t>(_data_magnet));
  }
  _bb.writeVarUint(0);
  return true;
}

bool ConnectorEndpoint::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        _data_endpointNodeID = _pool.allocate<GUID>();
        if (!_data_endpointNodeID->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 2: {
        _data_position = _pool.allocate<Vector>();
        if (!_data_position->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 3: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_magnet))) return false;
        set_magnet(_data_magnet);
        break;
      }
      default: {
        if (!_schema || !_schema->skipConnectorEndpointField(_bb, _type)) return false;
        break;
      }
    }
  }
}

Vector *ConnectorControlPoint::position() {
  return _data_position;
}

const Vector *ConnectorControlPoint::position() const {
  return _data_position;
}

void ConnectorControlPoint::set_position(Vector *value) {
  _data_position = value;
}

Vector *ConnectorControlPoint::axis() {
  return _data_axis;
}

const Vector *ConnectorControlPoint::axis() const {
  return _data_axis;
}

void ConnectorControlPoint::set_axis(Vector *value) {
  _data_axis = value;
}

bool ConnectorControlPoint::encode(kiwi::ByteBuffer &_bb) {
  if (position() != nullptr) {
    _bb.writeVarUint(1);
    if (!_data_position->encode(_bb)) return false;
  }
  if (axis() != nullptr) {
    _bb.writeVarUint(2);
    if (!_data_axis->encode(_bb)) return false;
  }
  _bb.writeVarUint(0);
  return true;
}

bool ConnectorControlPoint::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        _data_position = _pool.allocate<Vector>();
        if (!_data_position->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 2: {
        _data_axis = _pool.allocate<Vector>();
        if (!_data_axis->decode(_bb, _pool, _schema)) return false;
        break;
      }
      default: {
        if (!_schema || !_schema->skipConnectorControlPointField(_bb, _type)) return false;
        break;
      }
    }
  }
}

ConnectorTextSection *ConnectorTextMidpoint::section() {
  return _flags[0] & 1 ? &_data_section : nullptr;
}

const ConnectorTextSection *ConnectorTextMidpoint::section() const {
  return _flags[0] & 1 ? &_data_section : nullptr;
}

void ConnectorTextMidpoint::set_section(const ConnectorTextSection &value) {
  _flags[0] |= 1; _data_section = value;
}

float *ConnectorTextMidpoint::offset() {
  return _flags[0] & 2 ? &_data_offset : nullptr;
}

const float *ConnectorTextMidpoint::offset() const {
  return _flags[0] & 2 ? &_data_offset : nullptr;
}

void ConnectorTextMidpoint::set_offset(const float &value) {
  _flags[0] |= 2; _data_offset = value;
}

bool ConnectorTextMidpoint::encode(kiwi::ByteBuffer &_bb) {
  if (section() != nullptr) {
    _bb.writeVarUint(1);
    _bb.writeVarUint(static_cast<uint32_t>(_data_section));
  }
  if (offset() != nullptr) {
    _bb.writeVarUint(2);
    _bb.writeVarFloat(_data_offset);
  }
  _bb.writeVarUint(0);
  return true;
}

bool ConnectorTextMidpoint::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_section))) return false;
        set_section(_data_section);
        break;
      }
      case 2: {
        if (!_bb.readVarFloat(_data_offset)) return false;
        set_offset(_data_offset);
        break;
      }
      default: {
        if (!_schema || !_schema->skipConnectorTextMidpointField(_bb, _type)) return false;
        break;
      }
    }
  }
}

kiwi::String *LibraryMoveInfo::oldKey() {
  return _flags[0] & 1 ? &_data_oldKey : nullptr;
}

const kiwi::String *LibraryMoveInfo::oldKey() const {
  return _flags[0] & 1 ? &_data_oldKey : nullptr;
}

void LibraryMoveInfo::set_oldKey(const kiwi::String &value) {
  _flags[0] |= 1; _data_oldKey = value;
}

kiwi::String *LibraryMoveInfo::pasteFileKey() {
  return _flags[0] & 2 ? &_data_pasteFileKey : nullptr;
}

const kiwi::String *LibraryMoveInfo::pasteFileKey() const {
  return _flags[0] & 2 ? &_data_pasteFileKey : nullptr;
}

void LibraryMoveInfo::set_pasteFileKey(const kiwi::String &value) {
  _flags[0] |= 2; _data_pasteFileKey = value;
}

bool LibraryMoveInfo::encode(kiwi::ByteBuffer &_bb) {
  if (oldKey() != nullptr) {
    _bb.writeVarUint(1);
    _bb.writeString(_data_oldKey.c_str());
  }
  if (pasteFileKey() != nullptr) {
    _bb.writeVarUint(2);
    _bb.writeString(_data_pasteFileKey.c_str());
  }
  _bb.writeVarUint(0);
  return true;
}

bool LibraryMoveInfo::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        if (!_bb.readString(_data_oldKey, _pool)) return false;
        set_oldKey(_data_oldKey);
        break;
      }
      case 2: {
        if (!_bb.readString(_data_pasteFileKey, _pool)) return false;
        set_pasteFileKey(_data_pasteFileKey);
        break;
      }
      default: {
        if (!_schema || !_schema->skipLibraryMoveInfoField(_bb, _type)) return false;
        break;
      }
    }
  }
}

GUID *LibraryMoveHistoryItem::sourceNodeId() {
  return _data_sourceNodeId;
}

const GUID *LibraryMoveHistoryItem::sourceNodeId() const {
  return _data_sourceNodeId;
}

void LibraryMoveHistoryItem::set_sourceNodeId(GUID *value) {
  _data_sourceNodeId = value;
}

kiwi::String *LibraryMoveHistoryItem::sourceComponentKey() {
  return _flags[0] & 2 ? &_data_sourceComponentKey : nullptr;
}

const kiwi::String *LibraryMoveHistoryItem::sourceComponentKey() const {
  return _flags[0] & 2 ? &_data_sourceComponentKey : nullptr;
}

void LibraryMoveHistoryItem::set_sourceComponentKey(const kiwi::String &value) {
  _flags[0] |= 2; _data_sourceComponentKey = value;
}

bool LibraryMoveHistoryItem::encode(kiwi::ByteBuffer &_bb) {
  if (sourceNodeId() != nullptr) {
    _bb.writeVarUint(1);
    if (!_data_sourceNodeId->encode(_bb)) return false;
  }
  if (sourceComponentKey() != nullptr) {
    _bb.writeVarUint(2);
    _bb.writeString(_data_sourceComponentKey.c_str());
  }
  _bb.writeVarUint(0);
  return true;
}

bool LibraryMoveHistoryItem::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        _data_sourceNodeId = _pool.allocate<GUID>();
        if (!_data_sourceNodeId->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 2: {
        if (!_bb.readString(_data_sourceComponentKey, _pool)) return false;
        set_sourceComponentKey(_data_sourceComponentKey);
        break;
      }
      default: {
        if (!_schema || !_schema->skipLibraryMoveHistoryItemField(_bb, _type)) return false;
        break;
      }
    }
  }
}

kiwi::String *DeveloperRelatedLink::nodeId() {
  return _flags[0] & 1 ? &_data_nodeId : nullptr;
}

const kiwi::String *DeveloperRelatedLink::nodeId() const {
  return _flags[0] & 1 ? &_data_nodeId : nullptr;
}

void DeveloperRelatedLink::set_nodeId(const kiwi::String &value) {
  _flags[0] |= 1; _data_nodeId = value;
}

kiwi::String *DeveloperRelatedLink::fileKey() {
  return _flags[0] & 2 ? &_data_fileKey : nullptr;
}

const kiwi::String *DeveloperRelatedLink::fileKey() const {
  return _flags[0] & 2 ? &_data_fileKey : nullptr;
}

void DeveloperRelatedLink::set_fileKey(const kiwi::String &value) {
  _flags[0] |= 2; _data_fileKey = value;
}

kiwi::String *DeveloperRelatedLink::linkName() {
  return _flags[0] & 4 ? &_data_linkName : nullptr;
}

const kiwi::String *DeveloperRelatedLink::linkName() const {
  return _flags[0] & 4 ? &_data_linkName : nullptr;
}

void DeveloperRelatedLink::set_linkName(const kiwi::String &value) {
  _flags[0] |= 4; _data_linkName = value;
}

kiwi::String *DeveloperRelatedLink::linkUrl() {
  return _flags[0] & 8 ? &_data_linkUrl : nullptr;
}

const kiwi::String *DeveloperRelatedLink::linkUrl() const {
  return _flags[0] & 8 ? &_data_linkUrl : nullptr;
}

void DeveloperRelatedLink::set_linkUrl(const kiwi::String &value) {
  _flags[0] |= 8; _data_linkUrl = value;
}

bool DeveloperRelatedLink::encode(kiwi::ByteBuffer &_bb) {
  if (nodeId() != nullptr) {
    _bb.writeVarUint(1);
    _bb.writeString(_data_nodeId.c_str());
  }
  if (fileKey() != nullptr) {
    _bb.writeVarUint(2);
    _bb.writeString(_data_fileKey.c_str());
  }
  if (linkName() != nullptr) {
    _bb.writeVarUint(3);
    _bb.writeString(_data_linkName.c_str());
  }
  if (linkUrl() != nullptr) {
    _bb.writeVarUint(4);
    _bb.writeString(_data_linkUrl.c_str());
  }
  _bb.writeVarUint(0);
  return true;
}

bool DeveloperRelatedLink::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        if (!_bb.readString(_data_nodeId, _pool)) return false;
        set_nodeId(_data_nodeId);
        break;
      }
      case 2: {
        if (!_bb.readString(_data_fileKey, _pool)) return false;
        set_fileKey(_data_fileKey);
        break;
      }
      case 3: {
        if (!_bb.readString(_data_linkName, _pool)) return false;
        set_linkName(_data_linkName);
        break;
      }
      case 4: {
        if (!_bb.readString(_data_linkUrl, _pool)) return false;
        set_linkUrl(_data_linkUrl);
        break;
      }
      default: {
        if (!_schema || !_schema->skipDeveloperRelatedLinkField(_bb, _type)) return false;
        break;
      }
    }
  }
}

GUID *WidgetPointer::nodeId() {
  return _data_nodeId;
}

const GUID *WidgetPointer::nodeId() const {
  return _data_nodeId;
}

void WidgetPointer::set_nodeId(GUID *value) {
  _data_nodeId = value;
}

bool WidgetPointer::encode(kiwi::ByteBuffer &_bb) {
  if (nodeId() != nullptr) {
    _bb.writeVarUint(1);
    if (!_data_nodeId->encode(_bb)) return false;
  }
  _bb.writeVarUint(0);
  return true;
}

bool WidgetPointer::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        _data_nodeId = _pool.allocate<GUID>();
        if (!_data_nodeId->decode(_bb, _pool, _schema)) return false;
        break;
      }
      default: {
        if (!_schema || !_schema->skipWidgetPointerField(_bb, _type)) return false;
        break;
      }
    }
  }
}

kiwi::String *EditInfo::timestampIso8601() {
  return _flags[0] & 1 ? &_data_timestampIso8601 : nullptr;
}

const kiwi::String *EditInfo::timestampIso8601() const {
  return _flags[0] & 1 ? &_data_timestampIso8601 : nullptr;
}

void EditInfo::set_timestampIso8601(const kiwi::String &value) {
  _flags[0] |= 1; _data_timestampIso8601 = value;
}

kiwi::String *EditInfo::userId() {
  return _flags[0] & 2 ? &_data_userId : nullptr;
}

const kiwi::String *EditInfo::userId() const {
  return _flags[0] & 2 ? &_data_userId : nullptr;
}

void EditInfo::set_userId(const kiwi::String &value) {
  _flags[0] |= 2; _data_userId = value;
}

uint32_t *EditInfo::lastEditedAt() {
  return _flags[0] & 4 ? &_data_lastEditedAt : nullptr;
}

const uint32_t *EditInfo::lastEditedAt() const {
  return _flags[0] & 4 ? &_data_lastEditedAt : nullptr;
}

void EditInfo::set_lastEditedAt(const uint32_t &value) {
  _flags[0] |= 4; _data_lastEditedAt = value;
}

uint32_t *EditInfo::createdAt() {
  return _flags[0] & 8 ? &_data_createdAt : nullptr;
}

const uint32_t *EditInfo::createdAt() const {
  return _flags[0] & 8 ? &_data_createdAt : nullptr;
}

void EditInfo::set_createdAt(const uint32_t &value) {
  _flags[0] |= 8; _data_createdAt = value;
}

bool EditInfo::encode(kiwi::ByteBuffer &_bb) {
  if (timestampIso8601() != nullptr) {
    _bb.writeVarUint(1);
    _bb.writeString(_data_timestampIso8601.c_str());
  }
  if (userId() != nullptr) {
    _bb.writeVarUint(2);
    _bb.writeString(_data_userId.c_str());
  }
  if (lastEditedAt() != nullptr) {
    _bb.writeVarUint(3);
    _bb.writeVarUint(_data_lastEditedAt);
  }
  if (createdAt() != nullptr) {
    _bb.writeVarUint(4);
    _bb.writeVarUint(_data_createdAt);
  }
  _bb.writeVarUint(0);
  return true;
}

bool EditInfo::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        if (!_bb.readString(_data_timestampIso8601, _pool)) return false;
        set_timestampIso8601(_data_timestampIso8601);
        break;
      }
      case 2: {
        if (!_bb.readString(_data_userId, _pool)) return false;
        set_userId(_data_userId);
        break;
      }
      case 3: {
        if (!_bb.readVarUint(_data_lastEditedAt)) return false;
        set_lastEditedAt(_data_lastEditedAt);
        break;
      }
      case 4: {
        if (!_bb.readVarUint(_data_createdAt)) return false;
        set_createdAt(_data_createdAt);
        break;
      }
      default: {
        if (!_schema || !_schema->skipEditInfoField(_bb, _type)) return false;
        break;
      }
    }
  }
}

SectionStatus *SectionStatusInfo::status() {
  return _flags[0] & 1 ? &_data_status : nullptr;
}

const SectionStatus *SectionStatusInfo::status() const {
  return _flags[0] & 1 ? &_data_status : nullptr;
}

void SectionStatusInfo::set_status(const SectionStatus &value) {
  _flags[0] |= 1; _data_status = value;
}

bool SectionStatusInfo::encode(kiwi::ByteBuffer &_bb) {
  if (status() != nullptr) {
    _bb.writeVarUint(1);
    _bb.writeVarUint(static_cast<uint32_t>(_data_status));
  }
  _bb.writeVarUint(0);
  return true;
}

bool SectionStatusInfo::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_status))) return false;
        set_status(_data_status);
        break;
      }
      default: {
        if (!_schema || !_schema->skipSectionStatusInfoField(_bb, _type)) return false;
        break;
      }
    }
  }
}

GUID *NodeChange::guid() {
  return _data_guid;
}

const GUID *NodeChange::guid() const {
  return _data_guid;
}

void NodeChange::set_guid(GUID *value) {
  _data_guid = value;
}

uint32_t *NodeChange::guidTag() {
  return _flags[0] & 2 ? &_data_guidTag : nullptr;
}

const uint32_t *NodeChange::guidTag() const {
  return _flags[0] & 2 ? &_data_guidTag : nullptr;
}

void NodeChange::set_guidTag(const uint32_t &value) {
  _flags[0] |= 2; _data_guidTag = value;
}

NodePhase *NodeChange::phase() {
  return _flags[0] & 4 ? &_data_phase : nullptr;
}

const NodePhase *NodeChange::phase() const {
  return _flags[0] & 4 ? &_data_phase : nullptr;
}

void NodeChange::set_phase(const NodePhase &value) {
  _flags[0] |= 4; _data_phase = value;
}

uint32_t *NodeChange::phaseTag() {
  return _flags[0] & 8 ? &_data_phaseTag : nullptr;
}

const uint32_t *NodeChange::phaseTag() const {
  return _flags[0] & 8 ? &_data_phaseTag : nullptr;
}

void NodeChange::set_phaseTag(const uint32_t &value) {
  _flags[0] |= 8; _data_phaseTag = value;
}

ParentIndex *NodeChange::parentIndex() {
  return _data_parentIndex;
}

const ParentIndex *NodeChange::parentIndex() const {
  return _data_parentIndex;
}

void NodeChange::set_parentIndex(ParentIndex *value) {
  _data_parentIndex = value;
}

uint32_t *NodeChange::parentIndexTag() {
  return _flags[0] & 32 ? &_data_parentIndexTag : nullptr;
}

const uint32_t *NodeChange::parentIndexTag() const {
  return _flags[0] & 32 ? &_data_parentIndexTag : nullptr;
}

void NodeChange::set_parentIndexTag(const uint32_t &value) {
  _flags[0] |= 32; _data_parentIndexTag = value;
}

NodeType *NodeChange::type() {
  return _flags[0] & 64 ? &_data_type : nullptr;
}

const NodeType *NodeChange::type() const {
  return _flags[0] & 64 ? &_data_type : nullptr;
}

void NodeChange::set_type(const NodeType &value) {
  _flags[0] |= 64; _data_type = value;
}

uint32_t *NodeChange::typeTag() {
  return _flags[0] & 128 ? &_data_typeTag : nullptr;
}

const uint32_t *NodeChange::typeTag() const {
  return _flags[0] & 128 ? &_data_typeTag : nullptr;
}

void NodeChange::set_typeTag(const uint32_t &value) {
  _flags[0] |= 128; _data_typeTag = value;
}

kiwi::String *NodeChange::name() {
  return _flags[0] & 256 ? &_data_name : nullptr;
}

const kiwi::String *NodeChange::name() const {
  return _flags[0] & 256 ? &_data_name : nullptr;
}

void NodeChange::set_name(const kiwi::String &value) {
  _flags[0] |= 256; _data_name = value;
}

uint32_t *NodeChange::nameTag() {
  return _flags[0] & 512 ? &_data_nameTag : nullptr;
}

const uint32_t *NodeChange::nameTag() const {
  return _flags[0] & 512 ? &_data_nameTag : nullptr;
}

void NodeChange::set_nameTag(const uint32_t &value) {
  _flags[0] |= 512; _data_nameTag = value;
}

bool *NodeChange::isPublishable() {
  return _flags[0] & 1024 ? &_data_isPublishable : nullptr;
}

const bool *NodeChange::isPublishable() const {
  return _flags[0] & 1024 ? &_data_isPublishable : nullptr;
}

void NodeChange::set_isPublishable(const bool &value) {
  _flags[0] |= 1024; _data_isPublishable = value;
}

kiwi::String *NodeChange::description() {
  return _flags[0] & 2048 ? &_data_description : nullptr;
}

const kiwi::String *NodeChange::description() const {
  return _flags[0] & 2048 ? &_data_description : nullptr;
}

void NodeChange::set_description(const kiwi::String &value) {
  _flags[0] |= 2048; _data_description = value;
}

LibraryMoveInfo *NodeChange::libraryMoveInfo() {
  return _data_libraryMoveInfo;
}

const LibraryMoveInfo *NodeChange::libraryMoveInfo() const {
  return _data_libraryMoveInfo;
}

void NodeChange::set_libraryMoveInfo(LibraryMoveInfo *value) {
  _data_libraryMoveInfo = value;
}

kiwi::Array<LibraryMoveHistoryItem> *NodeChange::libraryMoveHistory() {
  return _flags[0] & 8192 ? &_data_libraryMoveHistory : nullptr;
}

const kiwi::Array<LibraryMoveHistoryItem> *NodeChange::libraryMoveHistory() const {
  return _flags[0] & 8192 ? &_data_libraryMoveHistory : nullptr;
}

kiwi::Array<LibraryMoveHistoryItem> &NodeChange::set_libraryMoveHistory(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[0] |= 8192; return _data_libraryMoveHistory = pool.array<LibraryMoveHistoryItem>(count);
}

kiwi::String *NodeChange::key() {
  return _flags[0] & 16384 ? &_data_key : nullptr;
}

const kiwi::String *NodeChange::key() const {
  return _flags[0] & 16384 ? &_data_key : nullptr;
}

void NodeChange::set_key(const kiwi::String &value) {
  _flags[0] |= 16384; _data_key = value;
}

uint32_t *NodeChange::styleID() {
  return _flags[0] & 32768 ? &_data_styleID : nullptr;
}

const uint32_t *NodeChange::styleID() const {
  return _flags[0] & 32768 ? &_data_styleID : nullptr;
}

void NodeChange::set_styleID(const uint32_t &value) {
  _flags[0] |= 32768; _data_styleID = value;
}

uint32_t *NodeChange::styleIDTag() {
  return _flags[0] & 65536 ? &_data_styleIDTag : nullptr;
}

const uint32_t *NodeChange::styleIDTag() const {
  return _flags[0] & 65536 ? &_data_styleIDTag : nullptr;
}

void NodeChange::set_styleIDTag(const uint32_t &value) {
  _flags[0] |= 65536; _data_styleIDTag = value;
}

bool *NodeChange::isSoftDeletedStyle() {
  return _flags[0] & 131072 ? &_data_isSoftDeletedStyle : nullptr;
}

const bool *NodeChange::isSoftDeletedStyle() const {
  return _flags[0] & 131072 ? &_data_isSoftDeletedStyle : nullptr;
}

void NodeChange::set_isSoftDeletedStyle(const bool &value) {
  _flags[0] |= 131072; _data_isSoftDeletedStyle = value;
}

bool *NodeChange::isNonUpdateable() {
  return _flags[0] & 262144 ? &_data_isNonUpdateable : nullptr;
}

const bool *NodeChange::isNonUpdateable() const {
  return _flags[0] & 262144 ? &_data_isNonUpdateable : nullptr;
}

void NodeChange::set_isNonUpdateable(const bool &value) {
  _flags[0] |= 262144; _data_isNonUpdateable = value;
}

bool *NodeChange::isFillStyle() {
  return _flags[0] & 524288 ? &_data_isFillStyle : nullptr;
}

const bool *NodeChange::isFillStyle() const {
  return _flags[0] & 524288 ? &_data_isFillStyle : nullptr;
}

void NodeChange::set_isFillStyle(const bool &value) {
  _flags[0] |= 524288; _data_isFillStyle = value;
}

bool *NodeChange::isStrokeStyle() {
  return _flags[0] & 1048576 ? &_data_isStrokeStyle : nullptr;
}

const bool *NodeChange::isStrokeStyle() const {
  return _flags[0] & 1048576 ? &_data_isStrokeStyle : nullptr;
}

void NodeChange::set_isStrokeStyle(const bool &value) {
  _flags[0] |= 1048576; _data_isStrokeStyle = value;
}

StyleType *NodeChange::styleType() {
  return _flags[0] & 2097152 ? &_data_styleType : nullptr;
}

const StyleType *NodeChange::styleType() const {
  return _flags[0] & 2097152 ? &_data_styleType : nullptr;
}

void NodeChange::set_styleType(const StyleType &value) {
  _flags[0] |= 2097152; _data_styleType = value;
}

kiwi::String *NodeChange::styleDescription() {
  return _flags[0] & 4194304 ? &_data_styleDescription : nullptr;
}

const kiwi::String *NodeChange::styleDescription() const {
  return _flags[0] & 4194304 ? &_data_styleDescription : nullptr;
}

void NodeChange::set_styleDescription(const kiwi::String &value) {
  _flags[0] |= 4194304; _data_styleDescription = value;
}

kiwi::String *NodeChange::version() {
  return _flags[0] & 8388608 ? &_data_version : nullptr;
}

const kiwi::String *NodeChange::version() const {
  return _flags[0] & 8388608 ? &_data_version : nullptr;
}

void NodeChange::set_version(const kiwi::String &value) {
  _flags[0] |= 8388608; _data_version = value;
}

SharedStyleMasterData *NodeChange::sharedStyleMasterData() {
  return _data_sharedStyleMasterData;
}

const SharedStyleMasterData *NodeChange::sharedStyleMasterData() const {
  return _data_sharedStyleMasterData;
}

void NodeChange::set_sharedStyleMasterData(SharedStyleMasterData *value) {
  _data_sharedStyleMasterData = value;
}

SharedStyleReference *NodeChange::sharedStyleReference() {
  return _data_sharedStyleReference;
}

const SharedStyleReference *NodeChange::sharedStyleReference() const {
  return _data_sharedStyleReference;
}

void NodeChange::set_sharedStyleReference(SharedStyleReference *value) {
  _data_sharedStyleReference = value;
}

kiwi::String *NodeChange::sortPosition() {
  return _flags[0] & 67108864 ? &_data_sortPosition : nullptr;
}

const kiwi::String *NodeChange::sortPosition() const {
  return _flags[0] & 67108864 ? &_data_sortPosition : nullptr;
}

void NodeChange::set_sortPosition(const kiwi::String &value) {
  _flags[0] |= 67108864; _data_sortPosition = value;
}

SharedStyleMasterData *NodeChange::ojansSuperSecretNodeField() {
  return _data_ojansSuperSecretNodeField;
}

const SharedStyleMasterData *NodeChange::ojansSuperSecretNodeField() const {
  return _data_ojansSuperSecretNodeField;
}

void NodeChange::set_ojansSuperSecretNodeField(SharedStyleMasterData *value) {
  _data_ojansSuperSecretNodeField = value;
}

SharedStyleMasterData *NodeChange::sevMoonlitLilyData() {
  return _data_sevMoonlitLilyData;
}

const SharedStyleMasterData *NodeChange::sevMoonlitLilyData() const {
  return _data_sevMoonlitLilyData;
}

void NodeChange::set_sevMoonlitLilyData(SharedStyleMasterData *value) {
  _data_sevMoonlitLilyData = value;
}

GUID *NodeChange::inheritFillStyleID() {
  return _data_inheritFillStyleID;
}

const GUID *NodeChange::inheritFillStyleID() const {
  return _data_inheritFillStyleID;
}

void NodeChange::set_inheritFillStyleID(GUID *value) {
  _data_inheritFillStyleID = value;
}

GUID *NodeChange::inheritStrokeStyleID() {
  return _data_inheritStrokeStyleID;
}

const GUID *NodeChange::inheritStrokeStyleID() const {
  return _data_inheritStrokeStyleID;
}

void NodeChange::set_inheritStrokeStyleID(GUID *value) {
  _data_inheritStrokeStyleID = value;
}

GUID *NodeChange::inheritTextStyleID() {
  return _data_inheritTextStyleID;
}

const GUID *NodeChange::inheritTextStyleID() const {
  return _data_inheritTextStyleID;
}

void NodeChange::set_inheritTextStyleID(GUID *value) {
  _data_inheritTextStyleID = value;
}

GUID *NodeChange::inheritExportStyleID() {
  return _data_inheritExportStyleID;
}

const GUID *NodeChange::inheritExportStyleID() const {
  return _data_inheritExportStyleID;
}

void NodeChange::set_inheritExportStyleID(GUID *value) {
  _data_inheritExportStyleID = value;
}

GUID *NodeChange::inheritEffectStyleID() {
  return _data_inheritEffectStyleID;
}

const GUID *NodeChange::inheritEffectStyleID() const {
  return _data_inheritEffectStyleID;
}

void NodeChange::set_inheritEffectStyleID(GUID *value) {
  _data_inheritEffectStyleID = value;
}

GUID *NodeChange::inheritGridStyleID() {
  return _data_inheritGridStyleID;
}

const GUID *NodeChange::inheritGridStyleID() const {
  return _data_inheritGridStyleID;
}

void NodeChange::set_inheritGridStyleID(GUID *value) {
  _data_inheritGridStyleID = value;
}

GUID *NodeChange::inheritFillStyleIDForStroke() {
  return _data_inheritFillStyleIDForStroke;
}

const GUID *NodeChange::inheritFillStyleIDForStroke() const {
  return _data_inheritFillStyleIDForStroke;
}

void NodeChange::set_inheritFillStyleIDForStroke(GUID *value) {
  _data_inheritFillStyleIDForStroke = value;
}

StyleId *NodeChange::styleIdForFill() {
  return _data_styleIdForFill;
}

const StyleId *NodeChange::styleIdForFill() const {
  return _data_styleIdForFill;
}

void NodeChange::set_styleIdForFill(StyleId *value) {
  _data_styleIdForFill = value;
}

StyleId *NodeChange::styleIdForStrokeFill() {
  return _data_styleIdForStrokeFill;
}

const StyleId *NodeChange::styleIdForStrokeFill() const {
  return _data_styleIdForStrokeFill;
}

void NodeChange::set_styleIdForStrokeFill(StyleId *value) {
  _data_styleIdForStrokeFill = value;
}

StyleId *NodeChange::styleIdForText() {
  return _data_styleIdForText;
}

const StyleId *NodeChange::styleIdForText() const {
  return _data_styleIdForText;
}

void NodeChange::set_styleIdForText(StyleId *value) {
  _data_styleIdForText = value;
}

StyleId *NodeChange::styleIdForEffect() {
  return _data_styleIdForEffect;
}

const StyleId *NodeChange::styleIdForEffect() const {
  return _data_styleIdForEffect;
}

void NodeChange::set_styleIdForEffect(StyleId *value) {
  _data_styleIdForEffect = value;
}

StyleId *NodeChange::styleIdForGrid() {
  return _data_styleIdForGrid;
}

const StyleId *NodeChange::styleIdForGrid() const {
  return _data_styleIdForGrid;
}

void NodeChange::set_styleIdForGrid(StyleId *value) {
  _data_styleIdForGrid = value;
}

kiwi::Array<Paint> *NodeChange::backgroundPaints() {
  return _flags[1] & 512 ? &_data_backgroundPaints : nullptr;
}

const kiwi::Array<Paint> *NodeChange::backgroundPaints() const {
  return _flags[1] & 512 ? &_data_backgroundPaints : nullptr;
}

kiwi::Array<Paint> &NodeChange::set_backgroundPaints(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[1] |= 512; return _data_backgroundPaints = pool.array<Paint>(count);
}

GUID *NodeChange::inheritFillStyleIDForBackground() {
  return _data_inheritFillStyleIDForBackground;
}

const GUID *NodeChange::inheritFillStyleIDForBackground() const {
  return _data_inheritFillStyleIDForBackground;
}

void NodeChange::set_inheritFillStyleIDForBackground(GUID *value) {
  _data_inheritFillStyleIDForBackground = value;
}

bool *NodeChange::isStateGroup() {
  return _flags[1] & 2048 ? &_data_isStateGroup : nullptr;
}

const bool *NodeChange::isStateGroup() const {
  return _flags[1] & 2048 ? &_data_isStateGroup : nullptr;
}

void NodeChange::set_isStateGroup(const bool &value) {
  _flags[1] |= 2048; _data_isStateGroup = value;
}

kiwi::Array<StateGroupPropertyValueOrder> *NodeChange::stateGroupPropertyValueOrders() {
  return _flags[1] & 4096 ? &_data_stateGroupPropertyValueOrders : nullptr;
}

const kiwi::Array<StateGroupPropertyValueOrder> *NodeChange::stateGroupPropertyValueOrders() const {
  return _flags[1] & 4096 ? &_data_stateGroupPropertyValueOrders : nullptr;
}

kiwi::Array<StateGroupPropertyValueOrder> &NodeChange::set_stateGroupPropertyValueOrders(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[1] |= 4096; return _data_stateGroupPropertyValueOrders = pool.array<StateGroupPropertyValueOrder>(count);
}

SharedSymbolReference *NodeChange::sharedSymbolReference() {
  return _data_sharedSymbolReference;
}

const SharedSymbolReference *NodeChange::sharedSymbolReference() const {
  return _data_sharedSymbolReference;
}

void NodeChange::set_sharedSymbolReference(SharedSymbolReference *value) {
  _data_sharedSymbolReference = value;
}

bool *NodeChange::isSymbolPublishable() {
  return _flags[1] & 16384 ? &_data_isSymbolPublishable : nullptr;
}

const bool *NodeChange::isSymbolPublishable() const {
  return _flags[1] & 16384 ? &_data_isSymbolPublishable : nullptr;
}

void NodeChange::set_isSymbolPublishable(const bool &value) {
  _flags[1] |= 16384; _data_isSymbolPublishable = value;
}

kiwi::Array<GUIDPathMapping> *NodeChange::sharedSymbolMappings() {
  return _flags[1] & 32768 ? &_data_sharedSymbolMappings : nullptr;
}

const kiwi::Array<GUIDPathMapping> *NodeChange::sharedSymbolMappings() const {
  return _flags[1] & 32768 ? &_data_sharedSymbolMappings : nullptr;
}

kiwi::Array<GUIDPathMapping> &NodeChange::set_sharedSymbolMappings(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[1] |= 32768; return _data_sharedSymbolMappings = pool.array<GUIDPathMapping>(count);
}

kiwi::String *NodeChange::sharedSymbolVersion() {
  return _flags[1] & 65536 ? &_data_sharedSymbolVersion : nullptr;
}

const kiwi::String *NodeChange::sharedSymbolVersion() const {
  return _flags[1] & 65536 ? &_data_sharedSymbolVersion : nullptr;
}

void NodeChange::set_sharedSymbolVersion(const kiwi::String &value) {
  _flags[1] |= 65536; _data_sharedSymbolVersion = value;
}

SharedComponentMasterData *NodeChange::sharedComponentMasterData() {
  return _data_sharedComponentMasterData;
}

const SharedComponentMasterData *NodeChange::sharedComponentMasterData() const {
  return _data_sharedComponentMasterData;
}

void NodeChange::set_sharedComponentMasterData(SharedComponentMasterData *value) {
  _data_sharedComponentMasterData = value;
}

kiwi::String *NodeChange::symbolDescription() {
  return _flags[1] & 262144 ? &_data_symbolDescription : nullptr;
}

const kiwi::String *NodeChange::symbolDescription() const {
  return _flags[1] & 262144 ? &_data_symbolDescription : nullptr;
}

void NodeChange::set_symbolDescription(const kiwi::String &value) {
  _flags[1] |= 262144; _data_symbolDescription = value;
}

kiwi::Array<GUIDPathMapping> *NodeChange::unflatteningMappings() {
  return _flags[1] & 524288 ? &_data_unflatteningMappings : nullptr;
}

const kiwi::Array<GUIDPathMapping> *NodeChange::unflatteningMappings() const {
  return _flags[1] & 524288 ? &_data_unflatteningMappings : nullptr;
}

kiwi::Array<GUIDPathMapping> &NodeChange::set_unflatteningMappings(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[1] |= 524288; return _data_unflatteningMappings = pool.array<GUIDPathMapping>(count);
}

kiwi::Array<GUIDPathMapping> *NodeChange::forceUnflatteningMappings() {
  return _flags[1] & 1048576 ? &_data_forceUnflatteningMappings : nullptr;
}

const kiwi::Array<GUIDPathMapping> *NodeChange::forceUnflatteningMappings() const {
  return _flags[1] & 1048576 ? &_data_forceUnflatteningMappings : nullptr;
}

kiwi::Array<GUIDPathMapping> &NodeChange::set_forceUnflatteningMappings(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[1] |= 1048576; return _data_forceUnflatteningMappings = pool.array<GUIDPathMapping>(count);
}

kiwi::String *NodeChange::publishFile() {
  return _flags[1] & 2097152 ? &_data_publishFile : nullptr;
}

const kiwi::String *NodeChange::publishFile() const {
  return _flags[1] & 2097152 ? &_data_publishFile : nullptr;
}

void NodeChange::set_publishFile(const kiwi::String &value) {
  _flags[1] |= 2097152; _data_publishFile = value;
}

GUID *NodeChange::publishID() {
  return _data_publishID;
}

const GUID *NodeChange::publishID() const {
  return _data_publishID;
}

void NodeChange::set_publishID(GUID *value) {
  _data_publishID = value;
}

kiwi::String *NodeChange::componentKey() {
  return _flags[1] & 8388608 ? &_data_componentKey : nullptr;
}

const kiwi::String *NodeChange::componentKey() const {
  return _flags[1] & 8388608 ? &_data_componentKey : nullptr;
}

void NodeChange::set_componentKey(const kiwi::String &value) {
  _flags[1] |= 8388608; _data_componentKey = value;
}

bool *NodeChange::isC2() {
  return _flags[1] & 16777216 ? &_data_isC2 : nullptr;
}

const bool *NodeChange::isC2() const {
  return _flags[1] & 16777216 ? &_data_isC2 : nullptr;
}

void NodeChange::set_isC2(const bool &value) {
  _flags[1] |= 16777216; _data_isC2 = value;
}

kiwi::String *NodeChange::publishedVersion() {
  return _flags[1] & 33554432 ? &_data_publishedVersion : nullptr;
}

const kiwi::String *NodeChange::publishedVersion() const {
  return _flags[1] & 33554432 ? &_data_publishedVersion : nullptr;
}

void NodeChange::set_publishedVersion(const kiwi::String &value) {
  _flags[1] |= 33554432; _data_publishedVersion = value;
}

kiwi::String *NodeChange::originComponentKey() {
  return _flags[1] & 67108864 ? &_data_originComponentKey : nullptr;
}

const kiwi::String *NodeChange::originComponentKey() const {
  return _flags[1] & 67108864 ? &_data_originComponentKey : nullptr;
}

void NodeChange::set_originComponentKey(const kiwi::String &value) {
  _flags[1] |= 67108864; _data_originComponentKey = value;
}

kiwi::Array<ComponentPropDef> *NodeChange::componentPropDefs() {
  return _flags[1] & 134217728 ? &_data_componentPropDefs : nullptr;
}

const kiwi::Array<ComponentPropDef> *NodeChange::componentPropDefs() const {
  return _flags[1] & 134217728 ? &_data_componentPropDefs : nullptr;
}

kiwi::Array<ComponentPropDef> &NodeChange::set_componentPropDefs(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[1] |= 134217728; return _data_componentPropDefs = pool.array<ComponentPropDef>(count);
}

kiwi::Array<ComponentPropRef> *NodeChange::componentPropRefs() {
  return _flags[1] & 268435456 ? &_data_componentPropRefs : nullptr;
}

const kiwi::Array<ComponentPropRef> *NodeChange::componentPropRefs() const {
  return _flags[1] & 268435456 ? &_data_componentPropRefs : nullptr;
}

kiwi::Array<ComponentPropRef> &NodeChange::set_componentPropRefs(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[1] |= 268435456; return _data_componentPropRefs = pool.array<ComponentPropRef>(count);
}

SymbolData *NodeChange::symbolData() {
  return _data_symbolData;
}

const SymbolData *NodeChange::symbolData() const {
  return _data_symbolData;
}

void NodeChange::set_symbolData(SymbolData *value) {
  _data_symbolData = value;
}

uint32_t *NodeChange::symbolDataTag() {
  return _flags[1] & 1073741824 ? &_data_symbolDataTag : nullptr;
}

const uint32_t *NodeChange::symbolDataTag() const {
  return _flags[1] & 1073741824 ? &_data_symbolDataTag : nullptr;
}

void NodeChange::set_symbolDataTag(const uint32_t &value) {
  _flags[1] |= 1073741824; _data_symbolDataTag = value;
}

kiwi::Array<NodeChange> *NodeChange::derivedSymbolData() {
  return _flags[1] & 2147483648 ? &_data_derivedSymbolData : nullptr;
}

const kiwi::Array<NodeChange> *NodeChange::derivedSymbolData() const {
  return _flags[1] & 2147483648 ? &_data_derivedSymbolData : nullptr;
}

kiwi::Array<NodeChange> &NodeChange::set_derivedSymbolData(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[1] |= 2147483648; return _data_derivedSymbolData = pool.array<NodeChange>(count);
}

GUID *NodeChange::overriddenSymbolID() {
  return _data_overriddenSymbolID;
}

const GUID *NodeChange::overriddenSymbolID() const {
  return _data_overriddenSymbolID;
}

void NodeChange::set_overriddenSymbolID(GUID *value) {
  _data_overriddenSymbolID = value;
}

kiwi::Array<ComponentPropAssignment> *NodeChange::componentPropAssignments() {
  return _flags[2] & 2 ? &_data_componentPropAssignments : nullptr;
}

const kiwi::Array<ComponentPropAssignment> *NodeChange::componentPropAssignments() const {
  return _flags[2] & 2 ? &_data_componentPropAssignments : nullptr;
}

kiwi::Array<ComponentPropAssignment> &NodeChange::set_componentPropAssignments(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[2] |= 2; return _data_componentPropAssignments = pool.array<ComponentPropAssignment>(count);
}

bool *NodeChange::propsAreBubbled() {
  return _flags[2] & 4 ? &_data_propsAreBubbled : nullptr;
}

const bool *NodeChange::propsAreBubbled() const {
  return _flags[2] & 4 ? &_data_propsAreBubbled : nullptr;
}

void NodeChange::set_propsAreBubbled(const bool &value) {
  _flags[2] |= 4; _data_propsAreBubbled = value;
}

kiwi::Array<InstanceOverrideStash> *NodeChange::overrideStash() {
  return _flags[2] & 8 ? &_data_overrideStash : nullptr;
}

const kiwi::Array<InstanceOverrideStash> *NodeChange::overrideStash() const {
  return _flags[2] & 8 ? &_data_overrideStash : nullptr;
}

kiwi::Array<InstanceOverrideStash> &NodeChange::set_overrideStash(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[2] |= 8; return _data_overrideStash = pool.array<InstanceOverrideStash>(count);
}

kiwi::Array<InstanceOverrideStashV2> *NodeChange::overrideStashV2() {
  return _flags[2] & 16 ? &_data_overrideStashV2 : nullptr;
}

const kiwi::Array<InstanceOverrideStashV2> *NodeChange::overrideStashV2() const {
  return _flags[2] & 16 ? &_data_overrideStashV2 : nullptr;
}

kiwi::Array<InstanceOverrideStashV2> &NodeChange::set_overrideStashV2(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[2] |= 16; return _data_overrideStashV2 = pool.array<InstanceOverrideStashV2>(count);
}

GUIDPath *NodeChange::guidPath() {
  return _data_guidPath;
}

const GUIDPath *NodeChange::guidPath() const {
  return _data_guidPath;
}

void NodeChange::set_guidPath(GUIDPath *value) {
  _data_guidPath = value;
}

uint32_t *NodeChange::guidPathTag() {
  return _flags[2] & 64 ? &_data_guidPathTag : nullptr;
}

const uint32_t *NodeChange::guidPathTag() const {
  return _flags[2] & 64 ? &_data_guidPathTag : nullptr;
}

void NodeChange::set_guidPathTag(const uint32_t &value) {
  _flags[2] |= 64; _data_guidPathTag = value;
}

int32_t *NodeChange::overrideLevel() {
  return _flags[2] & 128 ? &_data_overrideLevel : nullptr;
}

const int32_t *NodeChange::overrideLevel() const {
  return _flags[2] & 128 ? &_data_overrideLevel : nullptr;
}

void NodeChange::set_overrideLevel(const int32_t &value) {
  _flags[2] |= 128; _data_overrideLevel = value;
}

float *NodeChange::fontSize() {
  return _flags[2] & 256 ? &_data_fontSize : nullptr;
}

const float *NodeChange::fontSize() const {
  return _flags[2] & 256 ? &_data_fontSize : nullptr;
}

void NodeChange::set_fontSize(const float &value) {
  _flags[2] |= 256; _data_fontSize = value;
}

uint32_t *NodeChange::fontSizeTag() {
  return _flags[2] & 512 ? &_data_fontSizeTag : nullptr;
}

const uint32_t *NodeChange::fontSizeTag() const {
  return _flags[2] & 512 ? &_data_fontSizeTag : nullptr;
}

void NodeChange::set_fontSizeTag(const uint32_t &value) {
  _flags[2] |= 512; _data_fontSizeTag = value;
}

float *NodeChange::paragraphIndent() {
  return _flags[2] & 1024 ? &_data_paragraphIndent : nullptr;
}

const float *NodeChange::paragraphIndent() const {
  return _flags[2] & 1024 ? &_data_paragraphIndent : nullptr;
}

void NodeChange::set_paragraphIndent(const float &value) {
  _flags[2] |= 1024; _data_paragraphIndent = value;
}

uint32_t *NodeChange::paragraphIndentTag() {
  return _flags[2] & 2048 ? &_data_paragraphIndentTag : nullptr;
}

const uint32_t *NodeChange::paragraphIndentTag() const {
  return _flags[2] & 2048 ? &_data_paragraphIndentTag : nullptr;
}

void NodeChange::set_paragraphIndentTag(const uint32_t &value) {
  _flags[2] |= 2048; _data_paragraphIndentTag = value;
}

float *NodeChange::paragraphSpacing() {
  return _flags[2] & 4096 ? &_data_paragraphSpacing : nullptr;
}

const float *NodeChange::paragraphSpacing() const {
  return _flags[2] & 4096 ? &_data_paragraphSpacing : nullptr;
}

void NodeChange::set_paragraphSpacing(const float &value) {
  _flags[2] |= 4096; _data_paragraphSpacing = value;
}

uint32_t *NodeChange::paragraphSpacingTag() {
  return _flags[2] & 8192 ? &_data_paragraphSpacingTag : nullptr;
}

const uint32_t *NodeChange::paragraphSpacingTag() const {
  return _flags[2] & 8192 ? &_data_paragraphSpacingTag : nullptr;
}

void NodeChange::set_paragraphSpacingTag(const uint32_t &value) {
  _flags[2] |= 8192; _data_paragraphSpacingTag = value;
}

TextAlignHorizontal *NodeChange::textAlignHorizontal() {
  return _flags[2] & 16384 ? &_data_textAlignHorizontal : nullptr;
}

const TextAlignHorizontal *NodeChange::textAlignHorizontal() const {
  return _flags[2] & 16384 ? &_data_textAlignHorizontal : nullptr;
}

void NodeChange::set_textAlignHorizontal(const TextAlignHorizontal &value) {
  _flags[2] |= 16384; _data_textAlignHorizontal = value;
}

uint32_t *NodeChange::textAlignHorizontalTag() {
  return _flags[2] & 32768 ? &_data_textAlignHorizontalTag : nullptr;
}

const uint32_t *NodeChange::textAlignHorizontalTag() const {
  return _flags[2] & 32768 ? &_data_textAlignHorizontalTag : nullptr;
}

void NodeChange::set_textAlignHorizontalTag(const uint32_t &value) {
  _flags[2] |= 32768; _data_textAlignHorizontalTag = value;
}

TextAlignVertical *NodeChange::textAlignVertical() {
  return _flags[2] & 65536 ? &_data_textAlignVertical : nullptr;
}

const TextAlignVertical *NodeChange::textAlignVertical() const {
  return _flags[2] & 65536 ? &_data_textAlignVertical : nullptr;
}

void NodeChange::set_textAlignVertical(const TextAlignVertical &value) {
  _flags[2] |= 65536; _data_textAlignVertical = value;
}

uint32_t *NodeChange::textAlignVerticalTag() {
  return _flags[2] & 131072 ? &_data_textAlignVerticalTag : nullptr;
}

const uint32_t *NodeChange::textAlignVerticalTag() const {
  return _flags[2] & 131072 ? &_data_textAlignVerticalTag : nullptr;
}

void NodeChange::set_textAlignVerticalTag(const uint32_t &value) {
  _flags[2] |= 131072; _data_textAlignVerticalTag = value;
}

TextCase *NodeChange::textCase() {
  return _flags[2] & 262144 ? &_data_textCase : nullptr;
}

const TextCase *NodeChange::textCase() const {
  return _flags[2] & 262144 ? &_data_textCase : nullptr;
}

void NodeChange::set_textCase(const TextCase &value) {
  _flags[2] |= 262144; _data_textCase = value;
}

uint32_t *NodeChange::textCaseTag() {
  return _flags[2] & 524288 ? &_data_textCaseTag : nullptr;
}

const uint32_t *NodeChange::textCaseTag() const {
  return _flags[2] & 524288 ? &_data_textCaseTag : nullptr;
}

void NodeChange::set_textCaseTag(const uint32_t &value) {
  _flags[2] |= 524288; _data_textCaseTag = value;
}

TextDecoration *NodeChange::textDecoration() {
  return _flags[2] & 1048576 ? &_data_textDecoration : nullptr;
}

const TextDecoration *NodeChange::textDecoration() const {
  return _flags[2] & 1048576 ? &_data_textDecoration : nullptr;
}

void NodeChange::set_textDecoration(const TextDecoration &value) {
  _flags[2] |= 1048576; _data_textDecoration = value;
}

uint32_t *NodeChange::textDecorationTag() {
  return _flags[2] & 2097152 ? &_data_textDecorationTag : nullptr;
}

const uint32_t *NodeChange::textDecorationTag() const {
  return _flags[2] & 2097152 ? &_data_textDecorationTag : nullptr;
}

void NodeChange::set_textDecorationTag(const uint32_t &value) {
  _flags[2] |= 2097152; _data_textDecorationTag = value;
}

Number *NodeChange::lineHeight() {
  return _data_lineHeight;
}

const Number *NodeChange::lineHeight() const {
  return _data_lineHeight;
}

void NodeChange::set_lineHeight(Number *value) {
  _data_lineHeight = value;
}

uint32_t *NodeChange::lineHeightTag() {
  return _flags[2] & 8388608 ? &_data_lineHeightTag : nullptr;
}

const uint32_t *NodeChange::lineHeightTag() const {
  return _flags[2] & 8388608 ? &_data_lineHeightTag : nullptr;
}

void NodeChange::set_lineHeightTag(const uint32_t &value) {
  _flags[2] |= 8388608; _data_lineHeightTag = value;
}

FontName *NodeChange::fontName() {
  return _data_fontName;
}

const FontName *NodeChange::fontName() const {
  return _data_fontName;
}

void NodeChange::set_fontName(FontName *value) {
  _data_fontName = value;
}

uint32_t *NodeChange::fontNameTag() {
  return _flags[2] & 33554432 ? &_data_fontNameTag : nullptr;
}

const uint32_t *NodeChange::fontNameTag() const {
  return _flags[2] & 33554432 ? &_data_fontNameTag : nullptr;
}

void NodeChange::set_fontNameTag(const uint32_t &value) {
  _flags[2] |= 33554432; _data_fontNameTag = value;
}

TextData *NodeChange::textData() {
  return _data_textData;
}

const TextData *NodeChange::textData() const {
  return _data_textData;
}

void NodeChange::set_textData(TextData *value) {
  _data_textData = value;
}

uint32_t *NodeChange::textDataTag() {
  return _flags[2] & 134217728 ? &_data_textDataTag : nullptr;
}

const uint32_t *NodeChange::textDataTag() const {
  return _flags[2] & 134217728 ? &_data_textDataTag : nullptr;
}

void NodeChange::set_textDataTag(const uint32_t &value) {
  _flags[2] |= 134217728; _data_textDataTag = value;
}

DerivedTextData *NodeChange::derivedTextData() {
  return _data_derivedTextData;
}

const DerivedTextData *NodeChange::derivedTextData() const {
  return _data_derivedTextData;
}

void NodeChange::set_derivedTextData(DerivedTextData *value) {
  _data_derivedTextData = value;
}

bool *NodeChange::fontVariantCommonLigatures() {
  return _flags[2] & 536870912 ? &_data_fontVariantCommonLigatures : nullptr;
}

const bool *NodeChange::fontVariantCommonLigatures() const {
  return _flags[2] & 536870912 ? &_data_fontVariantCommonLigatures : nullptr;
}

void NodeChange::set_fontVariantCommonLigatures(const bool &value) {
  _flags[2] |= 536870912; _data_fontVariantCommonLigatures = value;
}

bool *NodeChange::fontVariantContextualLigatures() {
  return _flags[2] & 1073741824 ? &_data_fontVariantContextualLigatures : nullptr;
}

const bool *NodeChange::fontVariantContextualLigatures() const {
  return _flags[2] & 1073741824 ? &_data_fontVariantContextualLigatures : nullptr;
}

void NodeChange::set_fontVariantContextualLigatures(const bool &value) {
  _flags[2] |= 1073741824; _data_fontVariantContextualLigatures = value;
}

bool *NodeChange::fontVariantDiscretionaryLigatures() {
  return _flags[2] & 2147483648 ? &_data_fontVariantDiscretionaryLigatures : nullptr;
}

const bool *NodeChange::fontVariantDiscretionaryLigatures() const {
  return _flags[2] & 2147483648 ? &_data_fontVariantDiscretionaryLigatures : nullptr;
}

void NodeChange::set_fontVariantDiscretionaryLigatures(const bool &value) {
  _flags[2] |= 2147483648; _data_fontVariantDiscretionaryLigatures = value;
}

bool *NodeChange::fontVariantHistoricalLigatures() {
  return _flags[3] & 1 ? &_data_fontVariantHistoricalLigatures : nullptr;
}

const bool *NodeChange::fontVariantHistoricalLigatures() const {
  return _flags[3] & 1 ? &_data_fontVariantHistoricalLigatures : nullptr;
}

void NodeChange::set_fontVariantHistoricalLigatures(const bool &value) {
  _flags[3] |= 1; _data_fontVariantHistoricalLigatures = value;
}

bool *NodeChange::fontVariantOrdinal() {
  return _flags[3] & 2 ? &_data_fontVariantOrdinal : nullptr;
}

const bool *NodeChange::fontVariantOrdinal() const {
  return _flags[3] & 2 ? &_data_fontVariantOrdinal : nullptr;
}

void NodeChange::set_fontVariantOrdinal(const bool &value) {
  _flags[3] |= 2; _data_fontVariantOrdinal = value;
}

bool *NodeChange::fontVariantSlashedZero() {
  return _flags[3] & 4 ? &_data_fontVariantSlashedZero : nullptr;
}

const bool *NodeChange::fontVariantSlashedZero() const {
  return _flags[3] & 4 ? &_data_fontVariantSlashedZero : nullptr;
}

void NodeChange::set_fontVariantSlashedZero(const bool &value) {
  _flags[3] |= 4; _data_fontVariantSlashedZero = value;
}

FontVariantNumericFigure *NodeChange::fontVariantNumericFigure() {
  return _flags[3] & 8 ? &_data_fontVariantNumericFigure : nullptr;
}

const FontVariantNumericFigure *NodeChange::fontVariantNumericFigure() const {
  return _flags[3] & 8 ? &_data_fontVariantNumericFigure : nullptr;
}

void NodeChange::set_fontVariantNumericFigure(const FontVariantNumericFigure &value) {
  _flags[3] |= 8; _data_fontVariantNumericFigure = value;
}

FontVariantNumericSpacing *NodeChange::fontVariantNumericSpacing() {
  return _flags[3] & 16 ? &_data_fontVariantNumericSpacing : nullptr;
}

const FontVariantNumericSpacing *NodeChange::fontVariantNumericSpacing() const {
  return _flags[3] & 16 ? &_data_fontVariantNumericSpacing : nullptr;
}

void NodeChange::set_fontVariantNumericSpacing(const FontVariantNumericSpacing &value) {
  _flags[3] |= 16; _data_fontVariantNumericSpacing = value;
}

FontVariantNumericFraction *NodeChange::fontVariantNumericFraction() {
  return _flags[3] & 32 ? &_data_fontVariantNumericFraction : nullptr;
}

const FontVariantNumericFraction *NodeChange::fontVariantNumericFraction() const {
  return _flags[3] & 32 ? &_data_fontVariantNumericFraction : nullptr;
}

void NodeChange::set_fontVariantNumericFraction(const FontVariantNumericFraction &value) {
  _flags[3] |= 32; _data_fontVariantNumericFraction = value;
}

FontVariantCaps *NodeChange::fontVariantCaps() {
  return _flags[3] & 64 ? &_data_fontVariantCaps : nullptr;
}

const FontVariantCaps *NodeChange::fontVariantCaps() const {
  return _flags[3] & 64 ? &_data_fontVariantCaps : nullptr;
}

void NodeChange::set_fontVariantCaps(const FontVariantCaps &value) {
  _flags[3] |= 64; _data_fontVariantCaps = value;
}

FontVariantPosition *NodeChange::fontVariantPosition() {
  return _flags[3] & 128 ? &_data_fontVariantPosition : nullptr;
}

const FontVariantPosition *NodeChange::fontVariantPosition() const {
  return _flags[3] & 128 ? &_data_fontVariantPosition : nullptr;
}

void NodeChange::set_fontVariantPosition(const FontVariantPosition &value) {
  _flags[3] |= 128; _data_fontVariantPosition = value;
}

Number *NodeChange::letterSpacing() {
  return _data_letterSpacing;
}

const Number *NodeChange::letterSpacing() const {
  return _data_letterSpacing;
}

void NodeChange::set_letterSpacing(Number *value) {
  _data_letterSpacing = value;
}

kiwi::String *NodeChange::fontVersion() {
  return _flags[3] & 512 ? &_data_fontVersion : nullptr;
}

const kiwi::String *NodeChange::fontVersion() const {
  return _flags[3] & 512 ? &_data_fontVersion : nullptr;
}

void NodeChange::set_fontVersion(const kiwi::String &value) {
  _flags[3] |= 512; _data_fontVersion = value;
}

LeadingTrim *NodeChange::leadingTrim() {
  return _flags[3] & 1024 ? &_data_leadingTrim : nullptr;
}

const LeadingTrim *NodeChange::leadingTrim() const {
  return _flags[3] & 1024 ? &_data_leadingTrim : nullptr;
}

void NodeChange::set_leadingTrim(const LeadingTrim &value) {
  _flags[3] |= 1024; _data_leadingTrim = value;
}

bool *NodeChange::hangingPunctuation() {
  return _flags[3] & 2048 ? &_data_hangingPunctuation : nullptr;
}

const bool *NodeChange::hangingPunctuation() const {
  return _flags[3] & 2048 ? &_data_hangingPunctuation : nullptr;
}

void NodeChange::set_hangingPunctuation(const bool &value) {
  _flags[3] |= 2048; _data_hangingPunctuation = value;
}

bool *NodeChange::hangingList() {
  return _flags[3] & 4096 ? &_data_hangingList : nullptr;
}

const bool *NodeChange::hangingList() const {
  return _flags[3] & 4096 ? &_data_hangingList : nullptr;
}

void NodeChange::set_hangingList(const bool &value) {
  _flags[3] |= 4096; _data_hangingList = value;
}

int32_t *NodeChange::maxLines() {
  return _flags[3] & 8192 ? &_data_maxLines : nullptr;
}

const int32_t *NodeChange::maxLines() const {
  return _flags[3] & 8192 ? &_data_maxLines : nullptr;
}

void NodeChange::set_maxLines(const int32_t &value) {
  _flags[3] |= 8192; _data_maxLines = value;
}

SectionStatus *NodeChange::sectionStatus() {
  return _flags[3] & 16384 ? &_data_sectionStatus : nullptr;
}

const SectionStatus *NodeChange::sectionStatus() const {
  return _flags[3] & 16384 ? &_data_sectionStatus : nullptr;
}

void NodeChange::set_sectionStatus(const SectionStatus &value) {
  _flags[3] |= 16384; _data_sectionStatus = value;
}

SectionStatusInfo *NodeChange::sectionStatusInfo() {
  return _data_sectionStatusInfo;
}

const SectionStatusInfo *NodeChange::sectionStatusInfo() const {
  return _data_sectionStatusInfo;
}

void NodeChange::set_sectionStatusInfo(SectionStatusInfo *value) {
  _data_sectionStatusInfo = value;
}

uint32_t *NodeChange::textUserLayoutVersion() {
  return _flags[3] & 65536 ? &_data_textUserLayoutVersion : nullptr;
}

const uint32_t *NodeChange::textUserLayoutVersion() const {
  return _flags[3] & 65536 ? &_data_textUserLayoutVersion : nullptr;
}

void NodeChange::set_textUserLayoutVersion(const uint32_t &value) {
  _flags[3] |= 65536; _data_textUserLayoutVersion = value;
}

kiwi::Array<OpenTypeFeature> *NodeChange::toggledOnOTFeatures() {
  return _flags[3] & 131072 ? &_data_toggledOnOTFeatures : nullptr;
}

const kiwi::Array<OpenTypeFeature> *NodeChange::toggledOnOTFeatures() const {
  return _flags[3] & 131072 ? &_data_toggledOnOTFeatures : nullptr;
}

kiwi::Array<OpenTypeFeature> &NodeChange::set_toggledOnOTFeatures(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[3] |= 131072; return _data_toggledOnOTFeatures = pool.array<OpenTypeFeature>(count);
}

kiwi::Array<OpenTypeFeature> *NodeChange::toggledOffOTFeatures() {
  return _flags[3] & 262144 ? &_data_toggledOffOTFeatures : nullptr;
}

const kiwi::Array<OpenTypeFeature> *NodeChange::toggledOffOTFeatures() const {
  return _flags[3] & 262144 ? &_data_toggledOffOTFeatures : nullptr;
}

kiwi::Array<OpenTypeFeature> &NodeChange::set_toggledOffOTFeatures(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[3] |= 262144; return _data_toggledOffOTFeatures = pool.array<OpenTypeFeature>(count);
}

Hyperlink *NodeChange::hyperlink() {
  return _data_hyperlink;
}

const Hyperlink *NodeChange::hyperlink() const {
  return _data_hyperlink;
}

void NodeChange::set_hyperlink(Hyperlink *value) {
  _data_hyperlink = value;
}

Mention *NodeChange::mention() {
  return _data_mention;
}

const Mention *NodeChange::mention() const {
  return _data_mention;
}

void NodeChange::set_mention(Mention *value) {
  _data_mention = value;
}

kiwi::Array<FontVariation> *NodeChange::fontVariations() {
  return _flags[3] & 2097152 ? &_data_fontVariations : nullptr;
}

const kiwi::Array<FontVariation> *NodeChange::fontVariations() const {
  return _flags[3] & 2097152 ? &_data_fontVariations : nullptr;
}

kiwi::Array<FontVariation> &NodeChange::set_fontVariations(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[3] |= 2097152; return _data_fontVariations = pool.array<FontVariation>(count);
}

uint32_t *NodeChange::textBidiVersion() {
  return _flags[3] & 4194304 ? &_data_textBidiVersion : nullptr;
}

const uint32_t *NodeChange::textBidiVersion() const {
  return _flags[3] & 4194304 ? &_data_textBidiVersion : nullptr;
}

void NodeChange::set_textBidiVersion(const uint32_t &value) {
  _flags[3] |= 4194304; _data_textBidiVersion = value;
}

TextTruncation *NodeChange::textTruncation() {
  return _flags[3] & 8388608 ? &_data_textTruncation : nullptr;
}

const TextTruncation *NodeChange::textTruncation() const {
  return _flags[3] & 8388608 ? &_data_textTruncation : nullptr;
}

void NodeChange::set_textTruncation(const TextTruncation &value) {
  _flags[3] |= 8388608; _data_textTruncation = value;
}

bool *NodeChange::hasHadRTLText() {
  return _flags[3] & 16777216 ? &_data_hasHadRTLText : nullptr;
}

const bool *NodeChange::hasHadRTLText() const {
  return _flags[3] & 16777216 ? &_data_hasHadRTLText : nullptr;
}

void NodeChange::set_hasHadRTLText(const bool &value) {
  _flags[3] |= 16777216; _data_hasHadRTLText = value;
}

bool *NodeChange::visible() {
  return _flags[3] & 33554432 ? &_data_visible : nullptr;
}

const bool *NodeChange::visible() const {
  return _flags[3] & 33554432 ? &_data_visible : nullptr;
}

void NodeChange::set_visible(const bool &value) {
  _flags[3] |= 33554432; _data_visible = value;
}

uint32_t *NodeChange::visibleTag() {
  return _flags[3] & 67108864 ? &_data_visibleTag : nullptr;
}

const uint32_t *NodeChange::visibleTag() const {
  return _flags[3] & 67108864 ? &_data_visibleTag : nullptr;
}

void NodeChange::set_visibleTag(const uint32_t &value) {
  _flags[3] |= 67108864; _data_visibleTag = value;
}

bool *NodeChange::locked() {
  return _flags[3] & 134217728 ? &_data_locked : nullptr;
}

const bool *NodeChange::locked() const {
  return _flags[3] & 134217728 ? &_data_locked : nullptr;
}

void NodeChange::set_locked(const bool &value) {
  _flags[3] |= 134217728; _data_locked = value;
}

uint32_t *NodeChange::lockedTag() {
  return _flags[3] & 268435456 ? &_data_lockedTag : nullptr;
}

const uint32_t *NodeChange::lockedTag() const {
  return _flags[3] & 268435456 ? &_data_lockedTag : nullptr;
}

void NodeChange::set_lockedTag(const uint32_t &value) {
  _flags[3] |= 268435456; _data_lockedTag = value;
}

float *NodeChange::opacity() {
  return _flags[3] & 536870912 ? &_data_opacity : nullptr;
}

const float *NodeChange::opacity() const {
  return _flags[3] & 536870912 ? &_data_opacity : nullptr;
}

void NodeChange::set_opacity(const float &value) {
  _flags[3] |= 536870912; _data_opacity = value;
}

uint32_t *NodeChange::opacityTag() {
  return _flags[3] & 1073741824 ? &_data_opacityTag : nullptr;
}

const uint32_t *NodeChange::opacityTag() const {
  return _flags[3] & 1073741824 ? &_data_opacityTag : nullptr;
}

void NodeChange::set_opacityTag(const uint32_t &value) {
  _flags[3] |= 1073741824; _data_opacityTag = value;
}

BlendMode *NodeChange::blendMode() {
  return _flags[3] & 2147483648 ? &_data_blendMode : nullptr;
}

const BlendMode *NodeChange::blendMode() const {
  return _flags[3] & 2147483648 ? &_data_blendMode : nullptr;
}

void NodeChange::set_blendMode(const BlendMode &value) {
  _flags[3] |= 2147483648; _data_blendMode = value;
}

uint32_t *NodeChange::blendModeTag() {
  return _flags[4] & 1 ? &_data_blendModeTag : nullptr;
}

const uint32_t *NodeChange::blendModeTag() const {
  return _flags[4] & 1 ? &_data_blendModeTag : nullptr;
}

void NodeChange::set_blendModeTag(const uint32_t &value) {
  _flags[4] |= 1; _data_blendModeTag = value;
}

Vector *NodeChange::size() {
  return _data_size;
}

const Vector *NodeChange::size() const {
  return _data_size;
}

void NodeChange::set_size(Vector *value) {
  _data_size = value;
}

uint32_t *NodeChange::sizeTag() {
  return _flags[4] & 4 ? &_data_sizeTag : nullptr;
}

const uint32_t *NodeChange::sizeTag() const {
  return _flags[4] & 4 ? &_data_sizeTag : nullptr;
}

void NodeChange::set_sizeTag(const uint32_t &value) {
  _flags[4] |= 4; _data_sizeTag = value;
}

Matrix *NodeChange::transform() {
  return _data_transform;
}

const Matrix *NodeChange::transform() const {
  return _data_transform;
}

void NodeChange::set_transform(Matrix *value) {
  _data_transform = value;
}

uint32_t *NodeChange::transformTag() {
  return _flags[4] & 16 ? &_data_transformTag : nullptr;
}

const uint32_t *NodeChange::transformTag() const {
  return _flags[4] & 16 ? &_data_transformTag : nullptr;
}

void NodeChange::set_transformTag(const uint32_t &value) {
  _flags[4] |= 16; _data_transformTag = value;
}

kiwi::Array<float> *NodeChange::dashPattern() {
  return _flags[4] & 32 ? &_data_dashPattern : nullptr;
}

const kiwi::Array<float> *NodeChange::dashPattern() const {
  return _flags[4] & 32 ? &_data_dashPattern : nullptr;
}

kiwi::Array<float> &NodeChange::set_dashPattern(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[4] |= 32; return _data_dashPattern = pool.array<float>(count);
}

uint32_t *NodeChange::dashPatternTag() {
  return _flags[4] & 64 ? &_data_dashPatternTag : nullptr;
}

const uint32_t *NodeChange::dashPatternTag() const {
  return _flags[4] & 64 ? &_data_dashPatternTag : nullptr;
}

void NodeChange::set_dashPatternTag(const uint32_t &value) {
  _flags[4] |= 64; _data_dashPatternTag = value;
}

bool *NodeChange::mask() {
  return _flags[4] & 128 ? &_data_mask : nullptr;
}

const bool *NodeChange::mask() const {
  return _flags[4] & 128 ? &_data_mask : nullptr;
}

void NodeChange::set_mask(const bool &value) {
  _flags[4] |= 128; _data_mask = value;
}

uint32_t *NodeChange::maskTag() {
  return _flags[4] & 256 ? &_data_maskTag : nullptr;
}

const uint32_t *NodeChange::maskTag() const {
  return _flags[4] & 256 ? &_data_maskTag : nullptr;
}

void NodeChange::set_maskTag(const uint32_t &value) {
  _flags[4] |= 256; _data_maskTag = value;
}

bool *NodeChange::maskIsOutline() {
  return _flags[4] & 512 ? &_data_maskIsOutline : nullptr;
}

const bool *NodeChange::maskIsOutline() const {
  return _flags[4] & 512 ? &_data_maskIsOutline : nullptr;
}

void NodeChange::set_maskIsOutline(const bool &value) {
  _flags[4] |= 512; _data_maskIsOutline = value;
}

uint32_t *NodeChange::maskIsOutlineTag() {
  return _flags[4] & 1024 ? &_data_maskIsOutlineTag : nullptr;
}

const uint32_t *NodeChange::maskIsOutlineTag() const {
  return _flags[4] & 1024 ? &_data_maskIsOutlineTag : nullptr;
}

void NodeChange::set_maskIsOutlineTag(const uint32_t &value) {
  _flags[4] |= 1024; _data_maskIsOutlineTag = value;
}

MaskType *NodeChange::maskType() {
  return _flags[4] & 2048 ? &_data_maskType : nullptr;
}

const MaskType *NodeChange::maskType() const {
  return _flags[4] & 2048 ? &_data_maskType : nullptr;
}

void NodeChange::set_maskType(const MaskType &value) {
  _flags[4] |= 2048; _data_maskType = value;
}

float *NodeChange::backgroundOpacity() {
  return _flags[4] & 4096 ? &_data_backgroundOpacity : nullptr;
}

const float *NodeChange::backgroundOpacity() const {
  return _flags[4] & 4096 ? &_data_backgroundOpacity : nullptr;
}

void NodeChange::set_backgroundOpacity(const float &value) {
  _flags[4] |= 4096; _data_backgroundOpacity = value;
}

uint32_t *NodeChange::backgroundOpacityTag() {
  return _flags[4] & 8192 ? &_data_backgroundOpacityTag : nullptr;
}

const uint32_t *NodeChange::backgroundOpacityTag() const {
  return _flags[4] & 8192 ? &_data_backgroundOpacityTag : nullptr;
}

void NodeChange::set_backgroundOpacityTag(const uint32_t &value) {
  _flags[4] |= 8192; _data_backgroundOpacityTag = value;
}

float *NodeChange::cornerRadius() {
  return _flags[4] & 16384 ? &_data_cornerRadius : nullptr;
}

const float *NodeChange::cornerRadius() const {
  return _flags[4] & 16384 ? &_data_cornerRadius : nullptr;
}

void NodeChange::set_cornerRadius(const float &value) {
  _flags[4] |= 16384; _data_cornerRadius = value;
}

uint32_t *NodeChange::cornerRadiusTag() {
  return _flags[4] & 32768 ? &_data_cornerRadiusTag : nullptr;
}

const uint32_t *NodeChange::cornerRadiusTag() const {
  return _flags[4] & 32768 ? &_data_cornerRadiusTag : nullptr;
}

void NodeChange::set_cornerRadiusTag(const uint32_t &value) {
  _flags[4] |= 32768; _data_cornerRadiusTag = value;
}

float *NodeChange::strokeWeight() {
  return _flags[4] & 65536 ? &_data_strokeWeight : nullptr;
}

const float *NodeChange::strokeWeight() const {
  return _flags[4] & 65536 ? &_data_strokeWeight : nullptr;
}

void NodeChange::set_strokeWeight(const float &value) {
  _flags[4] |= 65536; _data_strokeWeight = value;
}

uint32_t *NodeChange::strokeWeightTag() {
  return _flags[4] & 131072 ? &_data_strokeWeightTag : nullptr;
}

const uint32_t *NodeChange::strokeWeightTag() const {
  return _flags[4] & 131072 ? &_data_strokeWeightTag : nullptr;
}

void NodeChange::set_strokeWeightTag(const uint32_t &value) {
  _flags[4] |= 131072; _data_strokeWeightTag = value;
}

StrokeAlign *NodeChange::strokeAlign() {
  return _flags[4] & 262144 ? &_data_strokeAlign : nullptr;
}

const StrokeAlign *NodeChange::strokeAlign() const {
  return _flags[4] & 262144 ? &_data_strokeAlign : nullptr;
}

void NodeChange::set_strokeAlign(const StrokeAlign &value) {
  _flags[4] |= 262144; _data_strokeAlign = value;
}

uint32_t *NodeChange::strokeAlignTag() {
  return _flags[4] & 524288 ? &_data_strokeAlignTag : nullptr;
}

const uint32_t *NodeChange::strokeAlignTag() const {
  return _flags[4] & 524288 ? &_data_strokeAlignTag : nullptr;
}

void NodeChange::set_strokeAlignTag(const uint32_t &value) {
  _flags[4] |= 524288; _data_strokeAlignTag = value;
}

StrokeCap *NodeChange::strokeCap() {
  return _flags[4] & 1048576 ? &_data_strokeCap : nullptr;
}

const StrokeCap *NodeChange::strokeCap() const {
  return _flags[4] & 1048576 ? &_data_strokeCap : nullptr;
}

void NodeChange::set_strokeCap(const StrokeCap &value) {
  _flags[4] |= 1048576; _data_strokeCap = value;
}

uint32_t *NodeChange::strokeCapTag() {
  return _flags[4] & 2097152 ? &_data_strokeCapTag : nullptr;
}

const uint32_t *NodeChange::strokeCapTag() const {
  return _flags[4] & 2097152 ? &_data_strokeCapTag : nullptr;
}

void NodeChange::set_strokeCapTag(const uint32_t &value) {
  _flags[4] |= 2097152; _data_strokeCapTag = value;
}

StrokeJoin *NodeChange::strokeJoin() {
  return _flags[4] & 4194304 ? &_data_strokeJoin : nullptr;
}

const StrokeJoin *NodeChange::strokeJoin() const {
  return _flags[4] & 4194304 ? &_data_strokeJoin : nullptr;
}

void NodeChange::set_strokeJoin(const StrokeJoin &value) {
  _flags[4] |= 4194304; _data_strokeJoin = value;
}

uint32_t *NodeChange::strokeJoinTag() {
  return _flags[4] & 8388608 ? &_data_strokeJoinTag : nullptr;
}

const uint32_t *NodeChange::strokeJoinTag() const {
  return _flags[4] & 8388608 ? &_data_strokeJoinTag : nullptr;
}

void NodeChange::set_strokeJoinTag(const uint32_t &value) {
  _flags[4] |= 8388608; _data_strokeJoinTag = value;
}

kiwi::Array<Paint> *NodeChange::fillPaints() {
  return _flags[4] & 16777216 ? &_data_fillPaints : nullptr;
}

const kiwi::Array<Paint> *NodeChange::fillPaints() const {
  return _flags[4] & 16777216 ? &_data_fillPaints : nullptr;
}

kiwi::Array<Paint> &NodeChange::set_fillPaints(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[4] |= 16777216; return _data_fillPaints = pool.array<Paint>(count);
}

uint32_t *NodeChange::fillPaintsTag() {
  return _flags[4] & 33554432 ? &_data_fillPaintsTag : nullptr;
}

const uint32_t *NodeChange::fillPaintsTag() const {
  return _flags[4] & 33554432 ? &_data_fillPaintsTag : nullptr;
}

void NodeChange::set_fillPaintsTag(const uint32_t &value) {
  _flags[4] |= 33554432; _data_fillPaintsTag = value;
}

kiwi::Array<Paint> *NodeChange::strokePaints() {
  return _flags[4] & 67108864 ? &_data_strokePaints : nullptr;
}

const kiwi::Array<Paint> *NodeChange::strokePaints() const {
  return _flags[4] & 67108864 ? &_data_strokePaints : nullptr;
}

kiwi::Array<Paint> &NodeChange::set_strokePaints(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[4] |= 67108864; return _data_strokePaints = pool.array<Paint>(count);
}

uint32_t *NodeChange::strokePaintsTag() {
  return _flags[4] & 134217728 ? &_data_strokePaintsTag : nullptr;
}

const uint32_t *NodeChange::strokePaintsTag() const {
  return _flags[4] & 134217728 ? &_data_strokePaintsTag : nullptr;
}

void NodeChange::set_strokePaintsTag(const uint32_t &value) {
  _flags[4] |= 134217728; _data_strokePaintsTag = value;
}

kiwi::Array<Effect> *NodeChange::effects() {
  return _flags[4] & 268435456 ? &_data_effects : nullptr;
}

const kiwi::Array<Effect> *NodeChange::effects() const {
  return _flags[4] & 268435456 ? &_data_effects : nullptr;
}

kiwi::Array<Effect> &NodeChange::set_effects(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[4] |= 268435456; return _data_effects = pool.array<Effect>(count);
}

uint32_t *NodeChange::effectsTag() {
  return _flags[4] & 536870912 ? &_data_effectsTag : nullptr;
}

const uint32_t *NodeChange::effectsTag() const {
  return _flags[4] & 536870912 ? &_data_effectsTag : nullptr;
}

void NodeChange::set_effectsTag(const uint32_t &value) {
  _flags[4] |= 536870912; _data_effectsTag = value;
}

Color *NodeChange::backgroundColor() {
  return _data_backgroundColor;
}

const Color *NodeChange::backgroundColor() const {
  return _data_backgroundColor;
}

void NodeChange::set_backgroundColor(Color *value) {
  _data_backgroundColor = value;
}

uint32_t *NodeChange::backgroundColorTag() {
  return _flags[4] & 2147483648 ? &_data_backgroundColorTag : nullptr;
}

const uint32_t *NodeChange::backgroundColorTag() const {
  return _flags[4] & 2147483648 ? &_data_backgroundColorTag : nullptr;
}

void NodeChange::set_backgroundColorTag(const uint32_t &value) {
  _flags[4] |= 2147483648; _data_backgroundColorTag = value;
}

kiwi::Array<Path> *NodeChange::fillGeometry() {
  return _flags[5] & 1 ? &_data_fillGeometry : nullptr;
}

const kiwi::Array<Path> *NodeChange::fillGeometry() const {
  return _flags[5] & 1 ? &_data_fillGeometry : nullptr;
}

kiwi::Array<Path> &NodeChange::set_fillGeometry(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[5] |= 1; return _data_fillGeometry = pool.array<Path>(count);
}

uint32_t *NodeChange::fillGeometryTag() {
  return _flags[5] & 2 ? &_data_fillGeometryTag : nullptr;
}

const uint32_t *NodeChange::fillGeometryTag() const {
  return _flags[5] & 2 ? &_data_fillGeometryTag : nullptr;
}

void NodeChange::set_fillGeometryTag(const uint32_t &value) {
  _flags[5] |= 2; _data_fillGeometryTag = value;
}

kiwi::Array<Path> *NodeChange::strokeGeometry() {
  return _flags[5] & 4 ? &_data_strokeGeometry : nullptr;
}

const kiwi::Array<Path> *NodeChange::strokeGeometry() const {
  return _flags[5] & 4 ? &_data_strokeGeometry : nullptr;
}

kiwi::Array<Path> &NodeChange::set_strokeGeometry(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[5] |= 4; return _data_strokeGeometry = pool.array<Path>(count);
}

uint32_t *NodeChange::strokeGeometryTag() {
  return _flags[5] & 8 ? &_data_strokeGeometryTag : nullptr;
}

const uint32_t *NodeChange::strokeGeometryTag() const {
  return _flags[5] & 8 ? &_data_strokeGeometryTag : nullptr;
}

void NodeChange::set_strokeGeometryTag(const uint32_t &value) {
  _flags[5] |= 8; _data_strokeGeometryTag = value;
}

float *NodeChange::rectangleTopLeftCornerRadius() {
  return _flags[5] & 16 ? &_data_rectangleTopLeftCornerRadius : nullptr;
}

const float *NodeChange::rectangleTopLeftCornerRadius() const {
  return _flags[5] & 16 ? &_data_rectangleTopLeftCornerRadius : nullptr;
}

void NodeChange::set_rectangleTopLeftCornerRadius(const float &value) {
  _flags[5] |= 16; _data_rectangleTopLeftCornerRadius = value;
}

float *NodeChange::rectangleTopRightCornerRadius() {
  return _flags[5] & 32 ? &_data_rectangleTopRightCornerRadius : nullptr;
}

const float *NodeChange::rectangleTopRightCornerRadius() const {
  return _flags[5] & 32 ? &_data_rectangleTopRightCornerRadius : nullptr;
}

void NodeChange::set_rectangleTopRightCornerRadius(const float &value) {
  _flags[5] |= 32; _data_rectangleTopRightCornerRadius = value;
}

float *NodeChange::rectangleBottomLeftCornerRadius() {
  return _flags[5] & 64 ? &_data_rectangleBottomLeftCornerRadius : nullptr;
}

const float *NodeChange::rectangleBottomLeftCornerRadius() const {
  return _flags[5] & 64 ? &_data_rectangleBottomLeftCornerRadius : nullptr;
}

void NodeChange::set_rectangleBottomLeftCornerRadius(const float &value) {
  _flags[5] |= 64; _data_rectangleBottomLeftCornerRadius = value;
}

float *NodeChange::rectangleBottomRightCornerRadius() {
  return _flags[5] & 128 ? &_data_rectangleBottomRightCornerRadius : nullptr;
}

const float *NodeChange::rectangleBottomRightCornerRadius() const {
  return _flags[5] & 128 ? &_data_rectangleBottomRightCornerRadius : nullptr;
}

void NodeChange::set_rectangleBottomRightCornerRadius(const float &value) {
  _flags[5] |= 128; _data_rectangleBottomRightCornerRadius = value;
}

bool *NodeChange::rectangleCornerRadiiIndependent() {
  return _flags[5] & 256 ? &_data_rectangleCornerRadiiIndependent : nullptr;
}

const bool *NodeChange::rectangleCornerRadiiIndependent() const {
  return _flags[5] & 256 ? &_data_rectangleCornerRadiiIndependent : nullptr;
}

void NodeChange::set_rectangleCornerRadiiIndependent(const bool &value) {
  _flags[5] |= 256; _data_rectangleCornerRadiiIndependent = value;
}

bool *NodeChange::rectangleCornerToolIndependent() {
  return _flags[5] & 512 ? &_data_rectangleCornerToolIndependent : nullptr;
}

const bool *NodeChange::rectangleCornerToolIndependent() const {
  return _flags[5] & 512 ? &_data_rectangleCornerToolIndependent : nullptr;
}

void NodeChange::set_rectangleCornerToolIndependent(const bool &value) {
  _flags[5] |= 512; _data_rectangleCornerToolIndependent = value;
}

bool *NodeChange::proportionsConstrained() {
  return _flags[5] & 1024 ? &_data_proportionsConstrained : nullptr;
}

const bool *NodeChange::proportionsConstrained() const {
  return _flags[5] & 1024 ? &_data_proportionsConstrained : nullptr;
}

void NodeChange::set_proportionsConstrained(const bool &value) {
  _flags[5] |= 1024; _data_proportionsConstrained = value;
}

bool *NodeChange::useAbsoluteBounds() {
  return _flags[5] & 2048 ? &_data_useAbsoluteBounds : nullptr;
}

const bool *NodeChange::useAbsoluteBounds() const {
  return _flags[5] & 2048 ? &_data_useAbsoluteBounds : nullptr;
}

void NodeChange::set_useAbsoluteBounds(const bool &value) {
  _flags[5] |= 2048; _data_useAbsoluteBounds = value;
}

bool *NodeChange::borderTopHidden() {
  return _flags[5] & 4096 ? &_data_borderTopHidden : nullptr;
}

const bool *NodeChange::borderTopHidden() const {
  return _flags[5] & 4096 ? &_data_borderTopHidden : nullptr;
}

void NodeChange::set_borderTopHidden(const bool &value) {
  _flags[5] |= 4096; _data_borderTopHidden = value;
}

bool *NodeChange::borderBottomHidden() {
  return _flags[5] & 8192 ? &_data_borderBottomHidden : nullptr;
}

const bool *NodeChange::borderBottomHidden() const {
  return _flags[5] & 8192 ? &_data_borderBottomHidden : nullptr;
}

void NodeChange::set_borderBottomHidden(const bool &value) {
  _flags[5] |= 8192; _data_borderBottomHidden = value;
}

bool *NodeChange::borderLeftHidden() {
  return _flags[5] & 16384 ? &_data_borderLeftHidden : nullptr;
}

const bool *NodeChange::borderLeftHidden() const {
  return _flags[5] & 16384 ? &_data_borderLeftHidden : nullptr;
}

void NodeChange::set_borderLeftHidden(const bool &value) {
  _flags[5] |= 16384; _data_borderLeftHidden = value;
}

bool *NodeChange::borderRightHidden() {
  return _flags[5] & 32768 ? &_data_borderRightHidden : nullptr;
}

const bool *NodeChange::borderRightHidden() const {
  return _flags[5] & 32768 ? &_data_borderRightHidden : nullptr;
}

void NodeChange::set_borderRightHidden(const bool &value) {
  _flags[5] |= 32768; _data_borderRightHidden = value;
}

bool *NodeChange::bordersTakeSpace() {
  return _flags[5] & 65536 ? &_data_bordersTakeSpace : nullptr;
}

const bool *NodeChange::bordersTakeSpace() const {
  return _flags[5] & 65536 ? &_data_bordersTakeSpace : nullptr;
}

void NodeChange::set_bordersTakeSpace(const bool &value) {
  _flags[5] |= 65536; _data_bordersTakeSpace = value;
}

float *NodeChange::borderTopWeight() {
  return _flags[5] & 131072 ? &_data_borderTopWeight : nullptr;
}

const float *NodeChange::borderTopWeight() const {
  return _flags[5] & 131072 ? &_data_borderTopWeight : nullptr;
}

void NodeChange::set_borderTopWeight(const float &value) {
  _flags[5] |= 131072; _data_borderTopWeight = value;
}

float *NodeChange::borderBottomWeight() {
  return _flags[5] & 262144 ? &_data_borderBottomWeight : nullptr;
}

const float *NodeChange::borderBottomWeight() const {
  return _flags[5] & 262144 ? &_data_borderBottomWeight : nullptr;
}

void NodeChange::set_borderBottomWeight(const float &value) {
  _flags[5] |= 262144; _data_borderBottomWeight = value;
}

float *NodeChange::borderLeftWeight() {
  return _flags[5] & 524288 ? &_data_borderLeftWeight : nullptr;
}

const float *NodeChange::borderLeftWeight() const {
  return _flags[5] & 524288 ? &_data_borderLeftWeight : nullptr;
}

void NodeChange::set_borderLeftWeight(const float &value) {
  _flags[5] |= 524288; _data_borderLeftWeight = value;
}

float *NodeChange::borderRightWeight() {
  return _flags[5] & 1048576 ? &_data_borderRightWeight : nullptr;
}

const float *NodeChange::borderRightWeight() const {
  return _flags[5] & 1048576 ? &_data_borderRightWeight : nullptr;
}

void NodeChange::set_borderRightWeight(const float &value) {
  _flags[5] |= 1048576; _data_borderRightWeight = value;
}

bool *NodeChange::borderStrokeWeightsIndependent() {
  return _flags[5] & 2097152 ? &_data_borderStrokeWeightsIndependent : nullptr;
}

const bool *NodeChange::borderStrokeWeightsIndependent() const {
  return _flags[5] & 2097152 ? &_data_borderStrokeWeightsIndependent : nullptr;
}

void NodeChange::set_borderStrokeWeightsIndependent(const bool &value) {
  _flags[5] |= 2097152; _data_borderStrokeWeightsIndependent = value;
}

ConstraintType *NodeChange::horizontalConstraint() {
  return _flags[5] & 4194304 ? &_data_horizontalConstraint : nullptr;
}

const ConstraintType *NodeChange::horizontalConstraint() const {
  return _flags[5] & 4194304 ? &_data_horizontalConstraint : nullptr;
}

void NodeChange::set_horizontalConstraint(const ConstraintType &value) {
  _flags[5] |= 4194304; _data_horizontalConstraint = value;
}

uint32_t *NodeChange::horizontalConstraintTag() {
  return _flags[5] & 8388608 ? &_data_horizontalConstraintTag : nullptr;
}

const uint32_t *NodeChange::horizontalConstraintTag() const {
  return _flags[5] & 8388608 ? &_data_horizontalConstraintTag : nullptr;
}

void NodeChange::set_horizontalConstraintTag(const uint32_t &value) {
  _flags[5] |= 8388608; _data_horizontalConstraintTag = value;
}

StackMode *NodeChange::stackMode() {
  return _flags[5] & 16777216 ? &_data_stackMode : nullptr;
}

const StackMode *NodeChange::stackMode() const {
  return _flags[5] & 16777216 ? &_data_stackMode : nullptr;
}

void NodeChange::set_stackMode(const StackMode &value) {
  _flags[5] |= 16777216; _data_stackMode = value;
}

uint32_t *NodeChange::stackModeTag() {
  return _flags[5] & 33554432 ? &_data_stackModeTag : nullptr;
}

const uint32_t *NodeChange::stackModeTag() const {
  return _flags[5] & 33554432 ? &_data_stackModeTag : nullptr;
}

void NodeChange::set_stackModeTag(const uint32_t &value) {
  _flags[5] |= 33554432; _data_stackModeTag = value;
}

float *NodeChange::stackSpacing() {
  return _flags[5] & 67108864 ? &_data_stackSpacing : nullptr;
}

const float *NodeChange::stackSpacing() const {
  return _flags[5] & 67108864 ? &_data_stackSpacing : nullptr;
}

void NodeChange::set_stackSpacing(const float &value) {
  _flags[5] |= 67108864; _data_stackSpacing = value;
}

uint32_t *NodeChange::stackSpacingTag() {
  return _flags[5] & 134217728 ? &_data_stackSpacingTag : nullptr;
}

const uint32_t *NodeChange::stackSpacingTag() const {
  return _flags[5] & 134217728 ? &_data_stackSpacingTag : nullptr;
}

void NodeChange::set_stackSpacingTag(const uint32_t &value) {
  _flags[5] |= 134217728; _data_stackSpacingTag = value;
}

float *NodeChange::stackPadding() {
  return _flags[5] & 268435456 ? &_data_stackPadding : nullptr;
}

const float *NodeChange::stackPadding() const {
  return _flags[5] & 268435456 ? &_data_stackPadding : nullptr;
}

void NodeChange::set_stackPadding(const float &value) {
  _flags[5] |= 268435456; _data_stackPadding = value;
}

uint32_t *NodeChange::stackPaddingTag() {
  return _flags[5] & 536870912 ? &_data_stackPaddingTag : nullptr;
}

const uint32_t *NodeChange::stackPaddingTag() const {
  return _flags[5] & 536870912 ? &_data_stackPaddingTag : nullptr;
}

void NodeChange::set_stackPaddingTag(const uint32_t &value) {
  _flags[5] |= 536870912; _data_stackPaddingTag = value;
}

StackCounterAlign *NodeChange::stackCounterAlign() {
  return _flags[5] & 1073741824 ? &_data_stackCounterAlign : nullptr;
}

const StackCounterAlign *NodeChange::stackCounterAlign() const {
  return _flags[5] & 1073741824 ? &_data_stackCounterAlign : nullptr;
}

void NodeChange::set_stackCounterAlign(const StackCounterAlign &value) {
  _flags[5] |= 1073741824; _data_stackCounterAlign = value;
}

StackJustify *NodeChange::stackJustify() {
  return _flags[5] & 2147483648 ? &_data_stackJustify : nullptr;
}

const StackJustify *NodeChange::stackJustify() const {
  return _flags[5] & 2147483648 ? &_data_stackJustify : nullptr;
}

void NodeChange::set_stackJustify(const StackJustify &value) {
  _flags[5] |= 2147483648; _data_stackJustify = value;
}

StackAlign *NodeChange::stackAlign() {
  return _flags[6] & 1 ? &_data_stackAlign : nullptr;
}

const StackAlign *NodeChange::stackAlign() const {
  return _flags[6] & 1 ? &_data_stackAlign : nullptr;
}

void NodeChange::set_stackAlign(const StackAlign &value) {
  _flags[6] |= 1; _data_stackAlign = value;
}

float *NodeChange::stackHorizontalPadding() {
  return _flags[6] & 2 ? &_data_stackHorizontalPadding : nullptr;
}

const float *NodeChange::stackHorizontalPadding() const {
  return _flags[6] & 2 ? &_data_stackHorizontalPadding : nullptr;
}

void NodeChange::set_stackHorizontalPadding(const float &value) {
  _flags[6] |= 2; _data_stackHorizontalPadding = value;
}

float *NodeChange::stackVerticalPadding() {
  return _flags[6] & 4 ? &_data_stackVerticalPadding : nullptr;
}

const float *NodeChange::stackVerticalPadding() const {
  return _flags[6] & 4 ? &_data_stackVerticalPadding : nullptr;
}

void NodeChange::set_stackVerticalPadding(const float &value) {
  _flags[6] |= 4; _data_stackVerticalPadding = value;
}

StackSize *NodeChange::stackWidth() {
  return _flags[6] & 8 ? &_data_stackWidth : nullptr;
}

const StackSize *NodeChange::stackWidth() const {
  return _flags[6] & 8 ? &_data_stackWidth : nullptr;
}

void NodeChange::set_stackWidth(const StackSize &value) {
  _flags[6] |= 8; _data_stackWidth = value;
}

StackSize *NodeChange::stackHeight() {
  return _flags[6] & 16 ? &_data_stackHeight : nullptr;
}

const StackSize *NodeChange::stackHeight() const {
  return _flags[6] & 16 ? &_data_stackHeight : nullptr;
}

void NodeChange::set_stackHeight(const StackSize &value) {
  _flags[6] |= 16; _data_stackHeight = value;
}

StackSize *NodeChange::stackPrimarySizing() {
  return _flags[6] & 32 ? &_data_stackPrimarySizing : nullptr;
}

const StackSize *NodeChange::stackPrimarySizing() const {
  return _flags[6] & 32 ? &_data_stackPrimarySizing : nullptr;
}

void NodeChange::set_stackPrimarySizing(const StackSize &value) {
  _flags[6] |= 32; _data_stackPrimarySizing = value;
}

StackJustify *NodeChange::stackPrimaryAlignItems() {
  return _flags[6] & 64 ? &_data_stackPrimaryAlignItems : nullptr;
}

const StackJustify *NodeChange::stackPrimaryAlignItems() const {
  return _flags[6] & 64 ? &_data_stackPrimaryAlignItems : nullptr;
}

void NodeChange::set_stackPrimaryAlignItems(const StackJustify &value) {
  _flags[6] |= 64; _data_stackPrimaryAlignItems = value;
}

StackAlign *NodeChange::stackCounterAlignItems() {
  return _flags[6] & 128 ? &_data_stackCounterAlignItems : nullptr;
}

const StackAlign *NodeChange::stackCounterAlignItems() const {
  return _flags[6] & 128 ? &_data_stackCounterAlignItems : nullptr;
}

void NodeChange::set_stackCounterAlignItems(const StackAlign &value) {
  _flags[6] |= 128; _data_stackCounterAlignItems = value;
}

float *NodeChange::stackChildPrimaryGrow() {
  return _flags[6] & 256 ? &_data_stackChildPrimaryGrow : nullptr;
}

const float *NodeChange::stackChildPrimaryGrow() const {
  return _flags[6] & 256 ? &_data_stackChildPrimaryGrow : nullptr;
}

void NodeChange::set_stackChildPrimaryGrow(const float &value) {
  _flags[6] |= 256; _data_stackChildPrimaryGrow = value;
}

float *NodeChange::stackPaddingRight() {
  return _flags[6] & 512 ? &_data_stackPaddingRight : nullptr;
}

const float *NodeChange::stackPaddingRight() const {
  return _flags[6] & 512 ? &_data_stackPaddingRight : nullptr;
}

void NodeChange::set_stackPaddingRight(const float &value) {
  _flags[6] |= 512; _data_stackPaddingRight = value;
}

float *NodeChange::stackPaddingBottom() {
  return _flags[6] & 1024 ? &_data_stackPaddingBottom : nullptr;
}

const float *NodeChange::stackPaddingBottom() const {
  return _flags[6] & 1024 ? &_data_stackPaddingBottom : nullptr;
}

void NodeChange::set_stackPaddingBottom(const float &value) {
  _flags[6] |= 1024; _data_stackPaddingBottom = value;
}

StackCounterAlign *NodeChange::stackChildAlignSelf() {
  return _flags[6] & 2048 ? &_data_stackChildAlignSelf : nullptr;
}

const StackCounterAlign *NodeChange::stackChildAlignSelf() const {
  return _flags[6] & 2048 ? &_data_stackChildAlignSelf : nullptr;
}

void NodeChange::set_stackChildAlignSelf(const StackCounterAlign &value) {
  _flags[6] |= 2048; _data_stackChildAlignSelf = value;
}

StackPositioning *NodeChange::stackPositioning() {
  return _flags[6] & 4096 ? &_data_stackPositioning : nullptr;
}

const StackPositioning *NodeChange::stackPositioning() const {
  return _flags[6] & 4096 ? &_data_stackPositioning : nullptr;
}

void NodeChange::set_stackPositioning(const StackPositioning &value) {
  _flags[6] |= 4096; _data_stackPositioning = value;
}

bool *NodeChange::stackReverseZIndex() {
  return _flags[6] & 8192 ? &_data_stackReverseZIndex : nullptr;
}

const bool *NodeChange::stackReverseZIndex() const {
  return _flags[6] & 8192 ? &_data_stackReverseZIndex : nullptr;
}

void NodeChange::set_stackReverseZIndex(const bool &value) {
  _flags[6] |= 8192; _data_stackReverseZIndex = value;
}

StackWrap *NodeChange::stackWrap() {
  return _flags[6] & 16384 ? &_data_stackWrap : nullptr;
}

const StackWrap *NodeChange::stackWrap() const {
  return _flags[6] & 16384 ? &_data_stackWrap : nullptr;
}

void NodeChange::set_stackWrap(const StackWrap &value) {
  _flags[6] |= 16384; _data_stackWrap = value;
}

float *NodeChange::stackCounterSpacing() {
  return _flags[6] & 32768 ? &_data_stackCounterSpacing : nullptr;
}

const float *NodeChange::stackCounterSpacing() const {
  return _flags[6] & 32768 ? &_data_stackCounterSpacing : nullptr;
}

void NodeChange::set_stackCounterSpacing(const float &value) {
  _flags[6] |= 32768; _data_stackCounterSpacing = value;
}

OptionalVector *NodeChange::minSize() {
  return _data_minSize;
}

const OptionalVector *NodeChange::minSize() const {
  return _data_minSize;
}

void NodeChange::set_minSize(OptionalVector *value) {
  _data_minSize = value;
}

OptionalVector *NodeChange::maxSize() {
  return _data_maxSize;
}

const OptionalVector *NodeChange::maxSize() const {
  return _data_maxSize;
}

void NodeChange::set_maxSize(OptionalVector *value) {
  _data_maxSize = value;
}

StackCounterAlignContent *NodeChange::stackCounterAlignContent() {
  return _flags[6] & 262144 ? &_data_stackCounterAlignContent : nullptr;
}

const StackCounterAlignContent *NodeChange::stackCounterAlignContent() const {
  return _flags[6] & 262144 ? &_data_stackCounterAlignContent : nullptr;
}

void NodeChange::set_stackCounterAlignContent(const StackCounterAlignContent &value) {
  _flags[6] |= 262144; _data_stackCounterAlignContent = value;
}

bool *NodeChange::isSnakeGameBoard() {
  return _flags[6] & 524288 ? &_data_isSnakeGameBoard : nullptr;
}

const bool *NodeChange::isSnakeGameBoard() const {
  return _flags[6] & 524288 ? &_data_isSnakeGameBoard : nullptr;
}

void NodeChange::set_isSnakeGameBoard(const bool &value) {
  _flags[6] |= 524288; _data_isSnakeGameBoard = value;
}

GUID *NodeChange::transitionNodeID() {
  return _data_transitionNodeID;
}

const GUID *NodeChange::transitionNodeID() const {
  return _data_transitionNodeID;
}

void NodeChange::set_transitionNodeID(GUID *value) {
  _data_transitionNodeID = value;
}

GUID *NodeChange::prototypeStartNodeID() {
  return _data_prototypeStartNodeID;
}

const GUID *NodeChange::prototypeStartNodeID() const {
  return _data_prototypeStartNodeID;
}

void NodeChange::set_prototypeStartNodeID(GUID *value) {
  _data_prototypeStartNodeID = value;
}

Color *NodeChange::prototypeBackgroundColor() {
  return _data_prototypeBackgroundColor;
}

const Color *NodeChange::prototypeBackgroundColor() const {
  return _data_prototypeBackgroundColor;
}

void NodeChange::set_prototypeBackgroundColor(Color *value) {
  _data_prototypeBackgroundColor = value;
}

TransitionInfo *NodeChange::transitionInfo() {
  return _data_transitionInfo;
}

const TransitionInfo *NodeChange::transitionInfo() const {
  return _data_transitionInfo;
}

void NodeChange::set_transitionInfo(TransitionInfo *value) {
  _data_transitionInfo = value;
}

TransitionType *NodeChange::transitionType() {
  return _flags[6] & 16777216 ? &_data_transitionType : nullptr;
}

const TransitionType *NodeChange::transitionType() const {
  return _flags[6] & 16777216 ? &_data_transitionType : nullptr;
}

void NodeChange::set_transitionType(const TransitionType &value) {
  _flags[6] |= 16777216; _data_transitionType = value;
}

float *NodeChange::transitionDuration() {
  return _flags[6] & 33554432 ? &_data_transitionDuration : nullptr;
}

const float *NodeChange::transitionDuration() const {
  return _flags[6] & 33554432 ? &_data_transitionDuration : nullptr;
}

void NodeChange::set_transitionDuration(const float &value) {
  _flags[6] |= 33554432; _data_transitionDuration = value;
}

EasingType *NodeChange::easingType() {
  return _flags[6] & 67108864 ? &_data_easingType : nullptr;
}

const EasingType *NodeChange::easingType() const {
  return _flags[6] & 67108864 ? &_data_easingType : nullptr;
}

void NodeChange::set_easingType(const EasingType &value) {
  _flags[6] |= 67108864; _data_easingType = value;
}

bool *NodeChange::transitionPreserveScroll() {
  return _flags[6] & 134217728 ? &_data_transitionPreserveScroll : nullptr;
}

const bool *NodeChange::transitionPreserveScroll() const {
  return _flags[6] & 134217728 ? &_data_transitionPreserveScroll : nullptr;
}

void NodeChange::set_transitionPreserveScroll(const bool &value) {
  _flags[6] |= 134217728; _data_transitionPreserveScroll = value;
}

ConnectionType *NodeChange::connectionType() {
  return _flags[6] & 268435456 ? &_data_connectionType : nullptr;
}

const ConnectionType *NodeChange::connectionType() const {
  return _flags[6] & 268435456 ? &_data_connectionType : nullptr;
}

void NodeChange::set_connectionType(const ConnectionType &value) {
  _flags[6] |= 268435456; _data_connectionType = value;
}

kiwi::String *NodeChange::connectionURL() {
  return _flags[6] & 536870912 ? &_data_connectionURL : nullptr;
}

const kiwi::String *NodeChange::connectionURL() const {
  return _flags[6] & 536870912 ? &_data_connectionURL : nullptr;
}

void NodeChange::set_connectionURL(const kiwi::String &value) {
  _flags[6] |= 536870912; _data_connectionURL = value;
}

PrototypeDevice *NodeChange::prototypeDevice() {
  return _data_prototypeDevice;
}

const PrototypeDevice *NodeChange::prototypeDevice() const {
  return _data_prototypeDevice;
}

void NodeChange::set_prototypeDevice(PrototypeDevice *value) {
  _data_prototypeDevice = value;
}

InteractionType *NodeChange::interactionType() {
  return _flags[6] & 2147483648 ? &_data_interactionType : nullptr;
}

const InteractionType *NodeChange::interactionType() const {
  return _flags[6] & 2147483648 ? &_data_interactionType : nullptr;
}

void NodeChange::set_interactionType(const InteractionType &value) {
  _flags[6] |= 2147483648; _data_interactionType = value;
}

float *NodeChange::transitionTimeout() {
  return _flags[7] & 1 ? &_data_transitionTimeout : nullptr;
}

const float *NodeChange::transitionTimeout() const {
  return _flags[7] & 1 ? &_data_transitionTimeout : nullptr;
}

void NodeChange::set_transitionTimeout(const float &value) {
  _flags[7] |= 1; _data_transitionTimeout = value;
}

bool *NodeChange::interactionMaintained() {
  return _flags[7] & 2 ? &_data_interactionMaintained : nullptr;
}

const bool *NodeChange::interactionMaintained() const {
  return _flags[7] & 2 ? &_data_interactionMaintained : nullptr;
}

void NodeChange::set_interactionMaintained(const bool &value) {
  _flags[7] |= 2; _data_interactionMaintained = value;
}

float *NodeChange::interactionDuration() {
  return _flags[7] & 4 ? &_data_interactionDuration : nullptr;
}

const float *NodeChange::interactionDuration() const {
  return _flags[7] & 4 ? &_data_interactionDuration : nullptr;
}

void NodeChange::set_interactionDuration(const float &value) {
  _flags[7] |= 4; _data_interactionDuration = value;
}

bool *NodeChange::destinationIsOverlay() {
  return _flags[7] & 8 ? &_data_destinationIsOverlay : nullptr;
}

const bool *NodeChange::destinationIsOverlay() const {
  return _flags[7] & 8 ? &_data_destinationIsOverlay : nullptr;
}

void NodeChange::set_destinationIsOverlay(const bool &value) {
  _flags[7] |= 8; _data_destinationIsOverlay = value;
}

bool *NodeChange::transitionShouldSmartAnimate() {
  return _flags[7] & 16 ? &_data_transitionShouldSmartAnimate : nullptr;
}

const bool *NodeChange::transitionShouldSmartAnimate() const {
  return _flags[7] & 16 ? &_data_transitionShouldSmartAnimate : nullptr;
}

void NodeChange::set_transitionShouldSmartAnimate(const bool &value) {
  _flags[7] |= 16; _data_transitionShouldSmartAnimate = value;
}

kiwi::Array<PrototypeInteraction> *NodeChange::prototypeInteractions() {
  return _flags[7] & 32 ? &_data_prototypeInteractions : nullptr;
}

const kiwi::Array<PrototypeInteraction> *NodeChange::prototypeInteractions() const {
  return _flags[7] & 32 ? &_data_prototypeInteractions : nullptr;
}

kiwi::Array<PrototypeInteraction> &NodeChange::set_prototypeInteractions(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[7] |= 32; return _data_prototypeInteractions = pool.array<PrototypeInteraction>(count);
}

PrototypeStartingPoint *NodeChange::prototypeStartingPoint() {
  return _data_prototypeStartingPoint;
}

const PrototypeStartingPoint *NodeChange::prototypeStartingPoint() const {
  return _data_prototypeStartingPoint;
}

void NodeChange::set_prototypeStartingPoint(PrototypeStartingPoint *value) {
  _data_prototypeStartingPoint = value;
}

kiwi::Array<PluginData> *NodeChange::pluginData() {
  return _flags[7] & 128 ? &_data_pluginData : nullptr;
}

const kiwi::Array<PluginData> *NodeChange::pluginData() const {
  return _flags[7] & 128 ? &_data_pluginData : nullptr;
}

kiwi::Array<PluginData> &NodeChange::set_pluginData(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[7] |= 128; return _data_pluginData = pool.array<PluginData>(count);
}

kiwi::Array<PluginRelaunchData> *NodeChange::pluginRelaunchData() {
  return _flags[7] & 256 ? &_data_pluginRelaunchData : nullptr;
}

const kiwi::Array<PluginRelaunchData> *NodeChange::pluginRelaunchData() const {
  return _flags[7] & 256 ? &_data_pluginRelaunchData : nullptr;
}

kiwi::Array<PluginRelaunchData> &NodeChange::set_pluginRelaunchData(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[7] |= 256; return _data_pluginRelaunchData = pool.array<PluginRelaunchData>(count);
}

ConnectorEndpoint *NodeChange::connectorStart() {
  return _data_connectorStart;
}

const ConnectorEndpoint *NodeChange::connectorStart() const {
  return _data_connectorStart;
}

void NodeChange::set_connectorStart(ConnectorEndpoint *value) {
  _data_connectorStart = value;
}

ConnectorEndpoint *NodeChange::connectorEnd() {
  return _data_connectorEnd;
}

const ConnectorEndpoint *NodeChange::connectorEnd() const {
  return _data_connectorEnd;
}

void NodeChange::set_connectorEnd(ConnectorEndpoint *value) {
  _data_connectorEnd = value;
}

ConnectorLineStyle *NodeChange::connectorLineStyle() {
  return _flags[7] & 2048 ? &_data_connectorLineStyle : nullptr;
}

const ConnectorLineStyle *NodeChange::connectorLineStyle() const {
  return _flags[7] & 2048 ? &_data_connectorLineStyle : nullptr;
}

void NodeChange::set_connectorLineStyle(const ConnectorLineStyle &value) {
  _flags[7] |= 2048; _data_connectorLineStyle = value;
}

StrokeCap *NodeChange::connectorStartCap() {
  return _flags[7] & 4096 ? &_data_connectorStartCap : nullptr;
}

const StrokeCap *NodeChange::connectorStartCap() const {
  return _flags[7] & 4096 ? &_data_connectorStartCap : nullptr;
}

void NodeChange::set_connectorStartCap(const StrokeCap &value) {
  _flags[7] |= 4096; _data_connectorStartCap = value;
}

StrokeCap *NodeChange::connectorEndCap() {
  return _flags[7] & 8192 ? &_data_connectorEndCap : nullptr;
}

const StrokeCap *NodeChange::connectorEndCap() const {
  return _flags[7] & 8192 ? &_data_connectorEndCap : nullptr;
}

void NodeChange::set_connectorEndCap(const StrokeCap &value) {
  _flags[7] |= 8192; _data_connectorEndCap = value;
}

kiwi::Array<ConnectorControlPoint> *NodeChange::connectorControlPoints() {
  return _flags[7] & 16384 ? &_data_connectorControlPoints : nullptr;
}

const kiwi::Array<ConnectorControlPoint> *NodeChange::connectorControlPoints() const {
  return _flags[7] & 16384 ? &_data_connectorControlPoints : nullptr;
}

kiwi::Array<ConnectorControlPoint> &NodeChange::set_connectorControlPoints(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[7] |= 16384; return _data_connectorControlPoints = pool.array<ConnectorControlPoint>(count);
}

ConnectorTextMidpoint *NodeChange::connectorTextMidpoint() {
  return _data_connectorTextMidpoint;
}

const ConnectorTextMidpoint *NodeChange::connectorTextMidpoint() const {
  return _data_connectorTextMidpoint;
}

void NodeChange::set_connectorTextMidpoint(ConnectorTextMidpoint *value) {
  _data_connectorTextMidpoint = value;
}

ShapeWithTextType *NodeChange::shapeWithTextType() {
  return _flags[7] & 65536 ? &_data_shapeWithTextType : nullptr;
}

const ShapeWithTextType *NodeChange::shapeWithTextType() const {
  return _flags[7] & 65536 ? &_data_shapeWithTextType : nullptr;
}

void NodeChange::set_shapeWithTextType(const ShapeWithTextType &value) {
  _flags[7] |= 65536; _data_shapeWithTextType = value;
}

float *NodeChange::shapeUserHeight() {
  return _flags[7] & 131072 ? &_data_shapeUserHeight : nullptr;
}

const float *NodeChange::shapeUserHeight() const {
  return _flags[7] & 131072 ? &_data_shapeUserHeight : nullptr;
}

void NodeChange::set_shapeUserHeight(const float &value) {
  _flags[7] |= 131072; _data_shapeUserHeight = value;
}

DerivedImmutableFrameData *NodeChange::derivedImmutableFrameData() {
  return _data_derivedImmutableFrameData;
}

const DerivedImmutableFrameData *NodeChange::derivedImmutableFrameData() const {
  return _data_derivedImmutableFrameData;
}

void NodeChange::set_derivedImmutableFrameData(DerivedImmutableFrameData *value) {
  _data_derivedImmutableFrameData = value;
}

MultiplayerFieldVersion *NodeChange::derivedImmutableFrameDataVersion() {
  return _data_derivedImmutableFrameDataVersion;
}

const MultiplayerFieldVersion *NodeChange::derivedImmutableFrameDataVersion() const {
  return _data_derivedImmutableFrameDataVersion;
}

void NodeChange::set_derivedImmutableFrameDataVersion(MultiplayerFieldVersion *value) {
  _data_derivedImmutableFrameDataVersion = value;
}

NodeGenerationData *NodeChange::nodeGenerationData() {
  return _data_nodeGenerationData;
}

const NodeGenerationData *NodeChange::nodeGenerationData() const {
  return _data_nodeGenerationData;
}

void NodeChange::set_nodeGenerationData(NodeGenerationData *value) {
  _data_nodeGenerationData = value;
}

CodeBlockLanguage *NodeChange::codeBlockLanguage() {
  return _flags[7] & 2097152 ? &_data_codeBlockLanguage : nullptr;
}

const CodeBlockLanguage *NodeChange::codeBlockLanguage() const {
  return _flags[7] & 2097152 ? &_data_codeBlockLanguage : nullptr;
}

void NodeChange::set_codeBlockLanguage(const CodeBlockLanguage &value) {
  _flags[7] |= 2097152; _data_codeBlockLanguage = value;
}

LinkPreviewData *NodeChange::linkPreviewData() {
  return _data_linkPreviewData;
}

const LinkPreviewData *NodeChange::linkPreviewData() const {
  return _data_linkPreviewData;
}

void NodeChange::set_linkPreviewData(LinkPreviewData *value) {
  _data_linkPreviewData = value;
}

bool *NodeChange::shapeTruncates() {
  return _flags[7] & 8388608 ? &_data_shapeTruncates : nullptr;
}

const bool *NodeChange::shapeTruncates() const {
  return _flags[7] & 8388608 ? &_data_shapeTruncates : nullptr;
}

void NodeChange::set_shapeTruncates(const bool &value) {
  _flags[7] |= 8388608; _data_shapeTruncates = value;
}

bool *NodeChange::sectionContentsHidden() {
  return _flags[7] & 16777216 ? &_data_sectionContentsHidden : nullptr;
}

const bool *NodeChange::sectionContentsHidden() const {
  return _flags[7] & 16777216 ? &_data_sectionContentsHidden : nullptr;
}

void NodeChange::set_sectionContentsHidden(const bool &value) {
  _flags[7] |= 16777216; _data_sectionContentsHidden = value;
}

VideoPlayback *NodeChange::videoPlayback() {
  return _data_videoPlayback;
}

const VideoPlayback *NodeChange::videoPlayback() const {
  return _data_videoPlayback;
}

void NodeChange::set_videoPlayback(VideoPlayback *value) {
  _data_videoPlayback = value;
}

StampData *NodeChange::stampData() {
  return _data_stampData;
}

const StampData *NodeChange::stampData() const {
  return _data_stampData;
}

void NodeChange::set_stampData(StampData *value) {
  _data_stampData = value;
}

MultiplayerMap *NodeChange::widgetSyncedState() {
  return _data_widgetSyncedState;
}

const MultiplayerMap *NodeChange::widgetSyncedState() const {
  return _data_widgetSyncedState;
}

void NodeChange::set_widgetSyncedState(MultiplayerMap *value) {
  _data_widgetSyncedState = value;
}

uint32_t *NodeChange::widgetSyncCursor() {
  return _flags[7] & 268435456 ? &_data_widgetSyncCursor : nullptr;
}

const uint32_t *NodeChange::widgetSyncCursor() const {
  return _flags[7] & 268435456 ? &_data_widgetSyncCursor : nullptr;
}

void NodeChange::set_widgetSyncCursor(const uint32_t &value) {
  _flags[7] |= 268435456; _data_widgetSyncCursor = value;
}

WidgetDerivedSubtreeCursor *NodeChange::widgetDerivedSubtreeCursor() {
  return _data_widgetDerivedSubtreeCursor;
}

const WidgetDerivedSubtreeCursor *NodeChange::widgetDerivedSubtreeCursor() const {
  return _data_widgetDerivedSubtreeCursor;
}

void NodeChange::set_widgetDerivedSubtreeCursor(WidgetDerivedSubtreeCursor *value) {
  _data_widgetDerivedSubtreeCursor = value;
}

WidgetPointer *NodeChange::widgetCachedAncestor() {
  return _data_widgetCachedAncestor;
}

const WidgetPointer *NodeChange::widgetCachedAncestor() const {
  return _data_widgetCachedAncestor;
}

void NodeChange::set_widgetCachedAncestor(WidgetPointer *value) {
  _data_widgetCachedAncestor = value;
}

WidgetInputBehavior *NodeChange::widgetInputBehavior() {
  return _flags[7] & 2147483648 ? &_data_widgetInputBehavior : nullptr;
}

const WidgetInputBehavior *NodeChange::widgetInputBehavior() const {
  return _flags[7] & 2147483648 ? &_data_widgetInputBehavior : nullptr;
}

void NodeChange::set_widgetInputBehavior(const WidgetInputBehavior &value) {
  _flags[7] |= 2147483648; _data_widgetInputBehavior = value;
}

kiwi::String *NodeChange::widgetTooltip() {
  return _flags[8] & 1 ? &_data_widgetTooltip : nullptr;
}

const kiwi::String *NodeChange::widgetTooltip() const {
  return _flags[8] & 1 ? &_data_widgetTooltip : nullptr;
}

void NodeChange::set_widgetTooltip(const kiwi::String &value) {
  _flags[8] |= 1; _data_widgetTooltip = value;
}

WidgetHoverStyle *NodeChange::widgetHoverStyle() {
  return _data_widgetHoverStyle;
}

const WidgetHoverStyle *NodeChange::widgetHoverStyle() const {
  return _data_widgetHoverStyle;
}

void NodeChange::set_widgetHoverStyle(WidgetHoverStyle *value) {
  _data_widgetHoverStyle = value;
}

bool *NodeChange::isWidgetStickable() {
  return _flags[8] & 4 ? &_data_isWidgetStickable : nullptr;
}

const bool *NodeChange::isWidgetStickable() const {
  return _flags[8] & 4 ? &_data_isWidgetStickable : nullptr;
}

void NodeChange::set_isWidgetStickable(const bool &value) {
  _flags[8] |= 4; _data_isWidgetStickable = value;
}

bool *NodeChange::shouldHideCursorsOnWidgetHover() {
  return _flags[8] & 8 ? &_data_shouldHideCursorsOnWidgetHover : nullptr;
}

const bool *NodeChange::shouldHideCursorsOnWidgetHover() const {
  return _flags[8] & 8 ? &_data_shouldHideCursorsOnWidgetHover : nullptr;
}

void NodeChange::set_shouldHideCursorsOnWidgetHover(const bool &value) {
  _flags[8] |= 8; _data_shouldHideCursorsOnWidgetHover = value;
}

WidgetMetadata *NodeChange::widgetMetadata() {
  return _data_widgetMetadata;
}

const WidgetMetadata *NodeChange::widgetMetadata() const {
  return _data_widgetMetadata;
}

void NodeChange::set_widgetMetadata(WidgetMetadata *value) {
  _data_widgetMetadata = value;
}

kiwi::Array<WidgetEvent> *NodeChange::widgetEvents() {
  return _flags[8] & 32 ? &_data_widgetEvents : nullptr;
}

const kiwi::Array<WidgetEvent> *NodeChange::widgetEvents() const {
  return _flags[8] & 32 ? &_data_widgetEvents : nullptr;
}

kiwi::Array<WidgetEvent> &NodeChange::set_widgetEvents(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[8] |= 32; return _data_widgetEvents = pool.array<WidgetEvent>(count);
}

kiwi::Array<WidgetPropertyMenuItem> *NodeChange::widgetPropertyMenuItems() {
  return _flags[8] & 64 ? &_data_widgetPropertyMenuItems : nullptr;
}

const kiwi::Array<WidgetPropertyMenuItem> *NodeChange::widgetPropertyMenuItems() const {
  return _flags[8] & 64 ? &_data_widgetPropertyMenuItems : nullptr;
}

kiwi::Array<WidgetPropertyMenuItem> &NodeChange::set_widgetPropertyMenuItems(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[8] |= 64; return _data_widgetPropertyMenuItems = pool.array<WidgetPropertyMenuItem>(count);
}

TableRowColumnPositionMap *NodeChange::tableRowPositions() {
  return _data_tableRowPositions;
}

const TableRowColumnPositionMap *NodeChange::tableRowPositions() const {
  return _data_tableRowPositions;
}

void NodeChange::set_tableRowPositions(TableRowColumnPositionMap *value) {
  _data_tableRowPositions = value;
}

TableRowColumnPositionMap *NodeChange::tableColumnPositions() {
  return _data_tableColumnPositions;
}

const TableRowColumnPositionMap *NodeChange::tableColumnPositions() const {
  return _data_tableColumnPositions;
}

void NodeChange::set_tableColumnPositions(TableRowColumnPositionMap *value) {
  _data_tableColumnPositions = value;
}

TableRowColumnSizeMap *NodeChange::tableRowHeights() {
  return _data_tableRowHeights;
}

const TableRowColumnSizeMap *NodeChange::tableRowHeights() const {
  return _data_tableRowHeights;
}

void NodeChange::set_tableRowHeights(TableRowColumnSizeMap *value) {
  _data_tableRowHeights = value;
}

TableRowColumnSizeMap *NodeChange::tableColumnWidths() {
  return _data_tableColumnWidths;
}

const TableRowColumnSizeMap *NodeChange::tableColumnWidths() const {
  return _data_tableColumnWidths;
}

void NodeChange::set_tableColumnWidths(TableRowColumnSizeMap *value) {
  _data_tableColumnWidths = value;
}

InternalEnumForTest *NodeChange::internalEnumForTest() {
  return _flags[8] & 2048 ? &_data_internalEnumForTest : nullptr;
}

const InternalEnumForTest *NodeChange::internalEnumForTest() const {
  return _flags[8] & 2048 ? &_data_internalEnumForTest : nullptr;
}

void NodeChange::set_internalEnumForTest(const InternalEnumForTest &value) {
  _flags[8] |= 2048; _data_internalEnumForTest = value;
}

InternalDataForTest *NodeChange::internalDataForTest() {
  return _data_internalDataForTest;
}

const InternalDataForTest *NodeChange::internalDataForTest() const {
  return _data_internalDataForTest;
}

void NodeChange::set_internalDataForTest(InternalDataForTest *value) {
  _data_internalDataForTest = value;
}

uint32_t *NodeChange::count() {
  return _flags[8] & 8192 ? &_data_count : nullptr;
}

const uint32_t *NodeChange::count() const {
  return _flags[8] & 8192 ? &_data_count : nullptr;
}

void NodeChange::set_count(const uint32_t &value) {
  _flags[8] |= 8192; _data_count = value;
}

uint32_t *NodeChange::countTag() {
  return _flags[8] & 16384 ? &_data_countTag : nullptr;
}

const uint32_t *NodeChange::countTag() const {
  return _flags[8] & 16384 ? &_data_countTag : nullptr;
}

void NodeChange::set_countTag(const uint32_t &value) {
  _flags[8] |= 16384; _data_countTag = value;
}

bool *NodeChange::autoRename() {
  return _flags[8] & 32768 ? &_data_autoRename : nullptr;
}

const bool *NodeChange::autoRename() const {
  return _flags[8] & 32768 ? &_data_autoRename : nullptr;
}

void NodeChange::set_autoRename(const bool &value) {
  _flags[8] |= 32768; _data_autoRename = value;
}

uint32_t *NodeChange::autoRenameTag() {
  return _flags[8] & 65536 ? &_data_autoRenameTag : nullptr;
}

const uint32_t *NodeChange::autoRenameTag() const {
  return _flags[8] & 65536 ? &_data_autoRenameTag : nullptr;
}

void NodeChange::set_autoRenameTag(const uint32_t &value) {
  _flags[8] |= 65536; _data_autoRenameTag = value;
}

bool *NodeChange::backgroundEnabled() {
  return _flags[8] & 131072 ? &_data_backgroundEnabled : nullptr;
}

const bool *NodeChange::backgroundEnabled() const {
  return _flags[8] & 131072 ? &_data_backgroundEnabled : nullptr;
}

void NodeChange::set_backgroundEnabled(const bool &value) {
  _flags[8] |= 131072; _data_backgroundEnabled = value;
}

uint32_t *NodeChange::backgroundEnabledTag() {
  return _flags[8] & 262144 ? &_data_backgroundEnabledTag : nullptr;
}

const uint32_t *NodeChange::backgroundEnabledTag() const {
  return _flags[8] & 262144 ? &_data_backgroundEnabledTag : nullptr;
}

void NodeChange::set_backgroundEnabledTag(const uint32_t &value) {
  _flags[8] |= 262144; _data_backgroundEnabledTag = value;
}

bool *NodeChange::exportContentsOnly() {
  return _flags[8] & 524288 ? &_data_exportContentsOnly : nullptr;
}

const bool *NodeChange::exportContentsOnly() const {
  return _flags[8] & 524288 ? &_data_exportContentsOnly : nullptr;
}

void NodeChange::set_exportContentsOnly(const bool &value) {
  _flags[8] |= 524288; _data_exportContentsOnly = value;
}

uint32_t *NodeChange::exportContentsOnlyTag() {
  return _flags[8] & 1048576 ? &_data_exportContentsOnlyTag : nullptr;
}

const uint32_t *NodeChange::exportContentsOnlyTag() const {
  return _flags[8] & 1048576 ? &_data_exportContentsOnlyTag : nullptr;
}

void NodeChange::set_exportContentsOnlyTag(const uint32_t &value) {
  _flags[8] |= 1048576; _data_exportContentsOnlyTag = value;
}

float *NodeChange::starInnerScale() {
  return _flags[8] & 2097152 ? &_data_starInnerScale : nullptr;
}

const float *NodeChange::starInnerScale() const {
  return _flags[8] & 2097152 ? &_data_starInnerScale : nullptr;
}

void NodeChange::set_starInnerScale(const float &value) {
  _flags[8] |= 2097152; _data_starInnerScale = value;
}

uint32_t *NodeChange::starInnerScaleTag() {
  return _flags[8] & 4194304 ? &_data_starInnerScaleTag : nullptr;
}

const uint32_t *NodeChange::starInnerScaleTag() const {
  return _flags[8] & 4194304 ? &_data_starInnerScaleTag : nullptr;
}

void NodeChange::set_starInnerScaleTag(const uint32_t &value) {
  _flags[8] |= 4194304; _data_starInnerScaleTag = value;
}

float *NodeChange::miterLimit() {
  return _flags[8] & 8388608 ? &_data_miterLimit : nullptr;
}

const float *NodeChange::miterLimit() const {
  return _flags[8] & 8388608 ? &_data_miterLimit : nullptr;
}

void NodeChange::set_miterLimit(const float &value) {
  _flags[8] |= 8388608; _data_miterLimit = value;
}

uint32_t *NodeChange::miterLimitTag() {
  return _flags[8] & 16777216 ? &_data_miterLimitTag : nullptr;
}

const uint32_t *NodeChange::miterLimitTag() const {
  return _flags[8] & 16777216 ? &_data_miterLimitTag : nullptr;
}

void NodeChange::set_miterLimitTag(const uint32_t &value) {
  _flags[8] |= 16777216; _data_miterLimitTag = value;
}

float *NodeChange::textTracking() {
  return _flags[8] & 33554432 ? &_data_textTracking : nullptr;
}

const float *NodeChange::textTracking() const {
  return _flags[8] & 33554432 ? &_data_textTracking : nullptr;
}

void NodeChange::set_textTracking(const float &value) {
  _flags[8] |= 33554432; _data_textTracking = value;
}

uint32_t *NodeChange::textTrackingTag() {
  return _flags[8] & 67108864 ? &_data_textTrackingTag : nullptr;
}

const uint32_t *NodeChange::textTrackingTag() const {
  return _flags[8] & 67108864 ? &_data_textTrackingTag : nullptr;
}

void NodeChange::set_textTrackingTag(const uint32_t &value) {
  _flags[8] |= 67108864; _data_textTrackingTag = value;
}

BooleanOperation *NodeChange::booleanOperation() {
  return _flags[8] & 134217728 ? &_data_booleanOperation : nullptr;
}

const BooleanOperation *NodeChange::booleanOperation() const {
  return _flags[8] & 134217728 ? &_data_booleanOperation : nullptr;
}

void NodeChange::set_booleanOperation(const BooleanOperation &value) {
  _flags[8] |= 134217728; _data_booleanOperation = value;
}

uint32_t *NodeChange::booleanOperationTag() {
  return _flags[8] & 268435456 ? &_data_booleanOperationTag : nullptr;
}

const uint32_t *NodeChange::booleanOperationTag() const {
  return _flags[8] & 268435456 ? &_data_booleanOperationTag : nullptr;
}

void NodeChange::set_booleanOperationTag(const uint32_t &value) {
  _flags[8] |= 268435456; _data_booleanOperationTag = value;
}

ConstraintType *NodeChange::verticalConstraint() {
  return _flags[8] & 536870912 ? &_data_verticalConstraint : nullptr;
}

const ConstraintType *NodeChange::verticalConstraint() const {
  return _flags[8] & 536870912 ? &_data_verticalConstraint : nullptr;
}

void NodeChange::set_verticalConstraint(const ConstraintType &value) {
  _flags[8] |= 536870912; _data_verticalConstraint = value;
}

uint32_t *NodeChange::verticalConstraintTag() {
  return _flags[8] & 1073741824 ? &_data_verticalConstraintTag : nullptr;
}

const uint32_t *NodeChange::verticalConstraintTag() const {
  return _flags[8] & 1073741824 ? &_data_verticalConstraintTag : nullptr;
}

void NodeChange::set_verticalConstraintTag(const uint32_t &value) {
  _flags[8] |= 1073741824; _data_verticalConstraintTag = value;
}

VectorMirror *NodeChange::handleMirroring() {
  return _flags[8] & 2147483648 ? &_data_handleMirroring : nullptr;
}

const VectorMirror *NodeChange::handleMirroring() const {
  return _flags[8] & 2147483648 ? &_data_handleMirroring : nullptr;
}

void NodeChange::set_handleMirroring(const VectorMirror &value) {
  _flags[8] |= 2147483648; _data_handleMirroring = value;
}

uint32_t *NodeChange::handleMirroringTag() {
  return _flags[9] & 1 ? &_data_handleMirroringTag : nullptr;
}

const uint32_t *NodeChange::handleMirroringTag() const {
  return _flags[9] & 1 ? &_data_handleMirroringTag : nullptr;
}

void NodeChange::set_handleMirroringTag(const uint32_t &value) {
  _flags[9] |= 1; _data_handleMirroringTag = value;
}

kiwi::Array<ExportSettings> *NodeChange::exportSettings() {
  return _flags[9] & 2 ? &_data_exportSettings : nullptr;
}

const kiwi::Array<ExportSettings> *NodeChange::exportSettings() const {
  return _flags[9] & 2 ? &_data_exportSettings : nullptr;
}

kiwi::Array<ExportSettings> &NodeChange::set_exportSettings(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[9] |= 2; return _data_exportSettings = pool.array<ExportSettings>(count);
}

uint32_t *NodeChange::exportSettingsTag() {
  return _flags[9] & 4 ? &_data_exportSettingsTag : nullptr;
}

const uint32_t *NodeChange::exportSettingsTag() const {
  return _flags[9] & 4 ? &_data_exportSettingsTag : nullptr;
}

void NodeChange::set_exportSettingsTag(const uint32_t &value) {
  _flags[9] |= 4; _data_exportSettingsTag = value;
}

TextAutoResize *NodeChange::textAutoResize() {
  return _flags[9] & 8 ? &_data_textAutoResize : nullptr;
}

const TextAutoResize *NodeChange::textAutoResize() const {
  return _flags[9] & 8 ? &_data_textAutoResize : nullptr;
}

void NodeChange::set_textAutoResize(const TextAutoResize &value) {
  _flags[9] |= 8; _data_textAutoResize = value;
}

uint32_t *NodeChange::textAutoResizeTag() {
  return _flags[9] & 16 ? &_data_textAutoResizeTag : nullptr;
}

const uint32_t *NodeChange::textAutoResizeTag() const {
  return _flags[9] & 16 ? &_data_textAutoResizeTag : nullptr;
}

void NodeChange::set_textAutoResizeTag(const uint32_t &value) {
  _flags[9] |= 16; _data_textAutoResizeTag = value;
}

kiwi::Array<LayoutGrid> *NodeChange::layoutGrids() {
  return _flags[9] & 32 ? &_data_layoutGrids : nullptr;
}

const kiwi::Array<LayoutGrid> *NodeChange::layoutGrids() const {
  return _flags[9] & 32 ? &_data_layoutGrids : nullptr;
}

kiwi::Array<LayoutGrid> &NodeChange::set_layoutGrids(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[9] |= 32; return _data_layoutGrids = pool.array<LayoutGrid>(count);
}

uint32_t *NodeChange::layoutGridsTag() {
  return _flags[9] & 64 ? &_data_layoutGridsTag : nullptr;
}

const uint32_t *NodeChange::layoutGridsTag() const {
  return _flags[9] & 64 ? &_data_layoutGridsTag : nullptr;
}

void NodeChange::set_layoutGridsTag(const uint32_t &value) {
  _flags[9] |= 64; _data_layoutGridsTag = value;
}

VectorData *NodeChange::vectorData() {
  return _data_vectorData;
}

const VectorData *NodeChange::vectorData() const {
  return _data_vectorData;
}

void NodeChange::set_vectorData(VectorData *value) {
  _data_vectorData = value;
}

uint32_t *NodeChange::vectorDataTag() {
  return _flags[9] & 256 ? &_data_vectorDataTag : nullptr;
}

const uint32_t *NodeChange::vectorDataTag() const {
  return _flags[9] & 256 ? &_data_vectorDataTag : nullptr;
}

void NodeChange::set_vectorDataTag(const uint32_t &value) {
  _flags[9] |= 256; _data_vectorDataTag = value;
}

bool *NodeChange::frameMaskDisabled() {
  return _flags[9] & 512 ? &_data_frameMaskDisabled : nullptr;
}

const bool *NodeChange::frameMaskDisabled() const {
  return _flags[9] & 512 ? &_data_frameMaskDisabled : nullptr;
}

void NodeChange::set_frameMaskDisabled(const bool &value) {
  _flags[9] |= 512; _data_frameMaskDisabled = value;
}

uint32_t *NodeChange::frameMaskDisabledTag() {
  return _flags[9] & 1024 ? &_data_frameMaskDisabledTag : nullptr;
}

const uint32_t *NodeChange::frameMaskDisabledTag() const {
  return _flags[9] & 1024 ? &_data_frameMaskDisabledTag : nullptr;
}

void NodeChange::set_frameMaskDisabledTag(const uint32_t &value) {
  _flags[9] |= 1024; _data_frameMaskDisabledTag = value;
}

bool *NodeChange::resizeToFit() {
  return _flags[9] & 2048 ? &_data_resizeToFit : nullptr;
}

const bool *NodeChange::resizeToFit() const {
  return _flags[9] & 2048 ? &_data_resizeToFit : nullptr;
}

void NodeChange::set_resizeToFit(const bool &value) {
  _flags[9] |= 2048; _data_resizeToFit = value;
}

uint32_t *NodeChange::resizeToFitTag() {
  return _flags[9] & 4096 ? &_data_resizeToFitTag : nullptr;
}

const uint32_t *NodeChange::resizeToFitTag() const {
  return _flags[9] & 4096 ? &_data_resizeToFitTag : nullptr;
}

void NodeChange::set_resizeToFitTag(const uint32_t &value) {
  _flags[9] |= 4096; _data_resizeToFitTag = value;
}

bool *NodeChange::exportBackgroundDisabled() {
  return _flags[9] & 8192 ? &_data_exportBackgroundDisabled : nullptr;
}

const bool *NodeChange::exportBackgroundDisabled() const {
  return _flags[9] & 8192 ? &_data_exportBackgroundDisabled : nullptr;
}

void NodeChange::set_exportBackgroundDisabled(const bool &value) {
  _flags[9] |= 8192; _data_exportBackgroundDisabled = value;
}

kiwi::Array<Guide> *NodeChange::guides() {
  return _flags[9] & 16384 ? &_data_guides : nullptr;
}

const kiwi::Array<Guide> *NodeChange::guides() const {
  return _flags[9] & 16384 ? &_data_guides : nullptr;
}

kiwi::Array<Guide> &NodeChange::set_guides(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[9] |= 16384; return _data_guides = pool.array<Guide>(count);
}

bool *NodeChange::internalOnly() {
  return _flags[9] & 32768 ? &_data_internalOnly : nullptr;
}

const bool *NodeChange::internalOnly() const {
  return _flags[9] & 32768 ? &_data_internalOnly : nullptr;
}

void NodeChange::set_internalOnly(const bool &value) {
  _flags[9] |= 32768; _data_internalOnly = value;
}

ScrollDirection *NodeChange::scrollDirection() {
  return _flags[9] & 65536 ? &_data_scrollDirection : nullptr;
}

const ScrollDirection *NodeChange::scrollDirection() const {
  return _flags[9] & 65536 ? &_data_scrollDirection : nullptr;
}

void NodeChange::set_scrollDirection(const ScrollDirection &value) {
  _flags[9] |= 65536; _data_scrollDirection = value;
}

float *NodeChange::cornerSmoothing() {
  return _flags[9] & 131072 ? &_data_cornerSmoothing : nullptr;
}

const float *NodeChange::cornerSmoothing() const {
  return _flags[9] & 131072 ? &_data_cornerSmoothing : nullptr;
}

void NodeChange::set_cornerSmoothing(const float &value) {
  _flags[9] |= 131072; _data_cornerSmoothing = value;
}

Vector *NodeChange::scrollOffset() {
  return _data_scrollOffset;
}

const Vector *NodeChange::scrollOffset() const {
  return _data_scrollOffset;
}

void NodeChange::set_scrollOffset(Vector *value) {
  _data_scrollOffset = value;
}

bool *NodeChange::exportTextAsSVGText() {
  return _flags[9] & 524288 ? &_data_exportTextAsSVGText : nullptr;
}

const bool *NodeChange::exportTextAsSVGText() const {
  return _flags[9] & 524288 ? &_data_exportTextAsSVGText : nullptr;
}

void NodeChange::set_exportTextAsSVGText(const bool &value) {
  _flags[9] |= 524288; _data_exportTextAsSVGText = value;
}

ScrollContractedState *NodeChange::scrollContractedState() {
  return _flags[9] & 1048576 ? &_data_scrollContractedState : nullptr;
}

const ScrollContractedState *NodeChange::scrollContractedState() const {
  return _flags[9] & 1048576 ? &_data_scrollContractedState : nullptr;
}

void NodeChange::set_scrollContractedState(const ScrollContractedState &value) {
  _flags[9] |= 1048576; _data_scrollContractedState = value;
}

Vector *NodeChange::contractedSize() {
  return _data_contractedSize;
}

const Vector *NodeChange::contractedSize() const {
  return _data_contractedSize;
}

void NodeChange::set_contractedSize(Vector *value) {
  _data_contractedSize = value;
}

kiwi::String *NodeChange::fixedChildrenDivider() {
  return _flags[9] & 4194304 ? &_data_fixedChildrenDivider : nullptr;
}

const kiwi::String *NodeChange::fixedChildrenDivider() const {
  return _flags[9] & 4194304 ? &_data_fixedChildrenDivider : nullptr;
}

void NodeChange::set_fixedChildrenDivider(const kiwi::String &value) {
  _flags[9] |= 4194304; _data_fixedChildrenDivider = value;
}

ScrollBehavior *NodeChange::scrollBehavior() {
  return _flags[9] & 8388608 ? &_data_scrollBehavior : nullptr;
}

const ScrollBehavior *NodeChange::scrollBehavior() const {
  return _flags[9] & 8388608 ? &_data_scrollBehavior : nullptr;
}

void NodeChange::set_scrollBehavior(const ScrollBehavior &value) {
  _flags[9] |= 8388608; _data_scrollBehavior = value;
}

ArcData *NodeChange::arcData() {
  return _data_arcData;
}

const ArcData *NodeChange::arcData() const {
  return _data_arcData;
}

void NodeChange::set_arcData(ArcData *value) {
  _data_arcData = value;
}

int32_t *NodeChange::derivedSymbolDataLayoutVersion() {
  return _flags[9] & 33554432 ? &_data_derivedSymbolDataLayoutVersion : nullptr;
}

const int32_t *NodeChange::derivedSymbolDataLayoutVersion() const {
  return _flags[9] & 33554432 ? &_data_derivedSymbolDataLayoutVersion : nullptr;
}

void NodeChange::set_derivedSymbolDataLayoutVersion(const int32_t &value) {
  _flags[9] |= 33554432; _data_derivedSymbolDataLayoutVersion = value;
}

NavigationType *NodeChange::navigationType() {
  return _flags[9] & 67108864 ? &_data_navigationType : nullptr;
}

const NavigationType *NodeChange::navigationType() const {
  return _flags[9] & 67108864 ? &_data_navigationType : nullptr;
}

void NodeChange::set_navigationType(const NavigationType &value) {
  _flags[9] |= 67108864; _data_navigationType = value;
}

OverlayPositionType *NodeChange::overlayPositionType() {
  return _flags[9] & 134217728 ? &_data_overlayPositionType : nullptr;
}

const OverlayPositionType *NodeChange::overlayPositionType() const {
  return _flags[9] & 134217728 ? &_data_overlayPositionType : nullptr;
}

void NodeChange::set_overlayPositionType(const OverlayPositionType &value) {
  _flags[9] |= 134217728; _data_overlayPositionType = value;
}

Vector *NodeChange::overlayRelativePosition() {
  return _data_overlayRelativePosition;
}

const Vector *NodeChange::overlayRelativePosition() const {
  return _data_overlayRelativePosition;
}

void NodeChange::set_overlayRelativePosition(Vector *value) {
  _data_overlayRelativePosition = value;
}

OverlayBackgroundInteraction *NodeChange::overlayBackgroundInteraction() {
  return _flags[9] & 536870912 ? &_data_overlayBackgroundInteraction : nullptr;
}

const OverlayBackgroundInteraction *NodeChange::overlayBackgroundInteraction() const {
  return _flags[9] & 536870912 ? &_data_overlayBackgroundInteraction : nullptr;
}

void NodeChange::set_overlayBackgroundInteraction(const OverlayBackgroundInteraction &value) {
  _flags[9] |= 536870912; _data_overlayBackgroundInteraction = value;
}

OverlayBackgroundAppearance *NodeChange::overlayBackgroundAppearance() {
  return _data_overlayBackgroundAppearance;
}

const OverlayBackgroundAppearance *NodeChange::overlayBackgroundAppearance() const {
  return _data_overlayBackgroundAppearance;
}

void NodeChange::set_overlayBackgroundAppearance(OverlayBackgroundAppearance *value) {
  _data_overlayBackgroundAppearance = value;
}

GUID *NodeChange::overrideKey() {
  return _data_overrideKey;
}

const GUID *NodeChange::overrideKey() const {
  return _data_overrideKey;
}

void NodeChange::set_overrideKey(GUID *value) {
  _data_overrideKey = value;
}

bool *NodeChange::containerSupportsFillStrokeAndCorners() {
  return _flags[10] & 1 ? &_data_containerSupportsFillStrokeAndCorners : nullptr;
}

const bool *NodeChange::containerSupportsFillStrokeAndCorners() const {
  return _flags[10] & 1 ? &_data_containerSupportsFillStrokeAndCorners : nullptr;
}

void NodeChange::set_containerSupportsFillStrokeAndCorners(const bool &value) {
  _flags[10] |= 1; _data_containerSupportsFillStrokeAndCorners = value;
}

StackSize *NodeChange::stackCounterSizing() {
  return _flags[10] & 2 ? &_data_stackCounterSizing : nullptr;
}

const StackSize *NodeChange::stackCounterSizing() const {
  return _flags[10] & 2 ? &_data_stackCounterSizing : nullptr;
}

void NodeChange::set_stackCounterSizing(const StackSize &value) {
  _flags[10] |= 2; _data_stackCounterSizing = value;
}

bool *NodeChange::containersSupportFillStrokeAndCorners() {
  return _flags[10] & 4 ? &_data_containersSupportFillStrokeAndCorners : nullptr;
}

const bool *NodeChange::containersSupportFillStrokeAndCorners() const {
  return _flags[10] & 4 ? &_data_containersSupportFillStrokeAndCorners : nullptr;
}

void NodeChange::set_containersSupportFillStrokeAndCorners(const bool &value) {
  _flags[10] |= 4; _data_containersSupportFillStrokeAndCorners = value;
}

KeyTrigger *NodeChange::keyTrigger() {
  return _data_keyTrigger;
}

const KeyTrigger *NodeChange::keyTrigger() const {
  return _data_keyTrigger;
}

void NodeChange::set_keyTrigger(KeyTrigger *value) {
  _data_keyTrigger = value;
}

kiwi::String *NodeChange::voiceEventPhrase() {
  return _flags[10] & 16 ? &_data_voiceEventPhrase : nullptr;
}

const kiwi::String *NodeChange::voiceEventPhrase() const {
  return _flags[10] & 16 ? &_data_voiceEventPhrase : nullptr;
}

void NodeChange::set_voiceEventPhrase(const kiwi::String &value) {
  _flags[10] |= 16; _data_voiceEventPhrase = value;
}

kiwi::Array<GUID> *NodeChange::ancestorPathBeforeDeletion() {
  return _flags[10] & 32 ? &_data_ancestorPathBeforeDeletion : nullptr;
}

const kiwi::Array<GUID> *NodeChange::ancestorPathBeforeDeletion() const {
  return _flags[10] & 32 ? &_data_ancestorPathBeforeDeletion : nullptr;
}

kiwi::Array<GUID> &NodeChange::set_ancestorPathBeforeDeletion(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[10] |= 32; return _data_ancestorPathBeforeDeletion = pool.array<GUID>(count);
}

kiwi::Array<SymbolLink> *NodeChange::symbolLinks() {
  return _flags[10] & 64 ? &_data_symbolLinks : nullptr;
}

const kiwi::Array<SymbolLink> *NodeChange::symbolLinks() const {
  return _flags[10] & 64 ? &_data_symbolLinks : nullptr;
}

kiwi::Array<SymbolLink> &NodeChange::set_symbolLinks(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[10] |= 64; return _data_symbolLinks = pool.array<SymbolLink>(count);
}

TextListData *NodeChange::textListData() {
  return _data_textListData;
}

const TextListData *NodeChange::textListData() const {
  return _data_textListData;
}

void NodeChange::set_textListData(TextListData *value) {
  _data_textListData = value;
}

bool *NodeChange::detachOpticalSizeFromFontSize() {
  return _flags[10] & 256 ? &_data_detachOpticalSizeFromFontSize : nullptr;
}

const bool *NodeChange::detachOpticalSizeFromFontSize() const {
  return _flags[10] & 256 ? &_data_detachOpticalSizeFromFontSize : nullptr;
}

void NodeChange::set_detachOpticalSizeFromFontSize(const bool &value) {
  _flags[10] |= 256; _data_detachOpticalSizeFromFontSize = value;
}

float *NodeChange::listSpacing() {
  return _flags[10] & 512 ? &_data_listSpacing : nullptr;
}

const float *NodeChange::listSpacing() const {
  return _flags[10] & 512 ? &_data_listSpacing : nullptr;
}

void NodeChange::set_listSpacing(const float &value) {
  _flags[10] |= 512; _data_listSpacing = value;
}

EmbedData *NodeChange::embedData() {
  return _data_embedData;
}

const EmbedData *NodeChange::embedData() const {
  return _data_embedData;
}

void NodeChange::set_embedData(EmbedData *value) {
  _data_embedData = value;
}

RichMediaData *NodeChange::richMediaData() {
  return _data_richMediaData;
}

const RichMediaData *NodeChange::richMediaData() const {
  return _data_richMediaData;
}

void NodeChange::set_richMediaData(RichMediaData *value) {
  _data_richMediaData = value;
}

MultiplayerMap *NodeChange::renderedSyncedState() {
  return _data_renderedSyncedState;
}

const MultiplayerMap *NodeChange::renderedSyncedState() const {
  return _data_renderedSyncedState;
}

void NodeChange::set_renderedSyncedState(MultiplayerMap *value) {
  _data_renderedSyncedState = value;
}

bool *NodeChange::simplifyInstancePanels() {
  return _flags[10] & 8192 ? &_data_simplifyInstancePanels : nullptr;
}

const bool *NodeChange::simplifyInstancePanels() const {
  return _flags[10] & 8192 ? &_data_simplifyInstancePanels : nullptr;
}

void NodeChange::set_simplifyInstancePanels(const bool &value) {
  _flags[10] |= 8192; _data_simplifyInstancePanels = value;
}

HTMLTag *NodeChange::accessibleHTMLTag() {
  return _flags[10] & 16384 ? &_data_accessibleHTMLTag : nullptr;
}

const HTMLTag *NodeChange::accessibleHTMLTag() const {
  return _flags[10] & 16384 ? &_data_accessibleHTMLTag : nullptr;
}

void NodeChange::set_accessibleHTMLTag(const HTMLTag &value) {
  _flags[10] |= 16384; _data_accessibleHTMLTag = value;
}

ARIARole *NodeChange::ariaRole() {
  return _flags[10] & 32768 ? &_data_ariaRole : nullptr;
}

const ARIARole *NodeChange::ariaRole() const {
  return _flags[10] & 32768 ? &_data_ariaRole : nullptr;
}

void NodeChange::set_ariaRole(const ARIARole &value) {
  _flags[10] |= 32768; _data_ariaRole = value;
}

kiwi::String *NodeChange::accessibleLabel() {
  return _flags[10] & 65536 ? &_data_accessibleLabel : nullptr;
}

const kiwi::String *NodeChange::accessibleLabel() const {
  return _flags[10] & 65536 ? &_data_accessibleLabel : nullptr;
}

void NodeChange::set_accessibleLabel(const kiwi::String &value) {
  _flags[10] |= 65536; _data_accessibleLabel = value;
}

VariableData *NodeChange::variableData() {
  return _data_variableData;
}

const VariableData *NodeChange::variableData() const {
  return _data_variableData;
}

void NodeChange::set_variableData(VariableData *value) {
  _data_variableData = value;
}

VariableDataMap *NodeChange::variableConsumptionMap() {
  return _data_variableConsumptionMap;
}

const VariableDataMap *NodeChange::variableConsumptionMap() const {
  return _data_variableConsumptionMap;
}

void NodeChange::set_variableConsumptionMap(VariableDataMap *value) {
  _data_variableConsumptionMap = value;
}

VariableModeBySetMap *NodeChange::variableModeBySetMap() {
  return _data_variableModeBySetMap;
}

const VariableModeBySetMap *NodeChange::variableModeBySetMap() const {
  return _data_variableModeBySetMap;
}

void NodeChange::set_variableModeBySetMap(VariableModeBySetMap *value) {
  _data_variableModeBySetMap = value;
}

kiwi::Array<VariableSetMode> *NodeChange::variableSetModes() {
  return _flags[10] & 1048576 ? &_data_variableSetModes : nullptr;
}

const kiwi::Array<VariableSetMode> *NodeChange::variableSetModes() const {
  return _flags[10] & 1048576 ? &_data_variableSetModes : nullptr;
}

kiwi::Array<VariableSetMode> &NodeChange::set_variableSetModes(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[10] |= 1048576; return _data_variableSetModes = pool.array<VariableSetMode>(count);
}

VariableSetID *NodeChange::variableSetID() {
  return _data_variableSetID;
}

const VariableSetID *NodeChange::variableSetID() const {
  return _data_variableSetID;
}

void NodeChange::set_variableSetID(VariableSetID *value) {
  _data_variableSetID = value;
}

VariableResolvedDataType *NodeChange::variableResolvedType() {
  return _flags[10] & 4194304 ? &_data_variableResolvedType : nullptr;
}

const VariableResolvedDataType *NodeChange::variableResolvedType() const {
  return _flags[10] & 4194304 ? &_data_variableResolvedType : nullptr;
}

void NodeChange::set_variableResolvedType(const VariableResolvedDataType &value) {
  _flags[10] |= 4194304; _data_variableResolvedType = value;
}

VariableDataValues *NodeChange::variableDataValues() {
  return _data_variableDataValues;
}

const VariableDataValues *NodeChange::variableDataValues() const {
  return _data_variableDataValues;
}

void NodeChange::set_variableDataValues(VariableDataValues *value) {
  _data_variableDataValues = value;
}

kiwi::String *NodeChange::variableTokenName() {
  return _flags[10] & 16777216 ? &_data_variableTokenName : nullptr;
}

const kiwi::String *NodeChange::variableTokenName() const {
  return _flags[10] & 16777216 ? &_data_variableTokenName : nullptr;
}

void NodeChange::set_variableTokenName(const kiwi::String &value) {
  _flags[10] |= 16777216; _data_variableTokenName = value;
}

kiwi::Array<VariableScope> *NodeChange::variableScopes() {
  return _flags[10] & 33554432 ? &_data_variableScopes : nullptr;
}

const kiwi::Array<VariableScope> *NodeChange::variableScopes() const {
  return _flags[10] & 33554432 ? &_data_variableScopes : nullptr;
}

kiwi::Array<VariableScope> &NodeChange::set_variableScopes(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[10] |= 33554432; return _data_variableScopes = pool.array<VariableScope>(count);
}

CodeSyntaxMap *NodeChange::codeSyntax() {
  return _data_codeSyntax;
}

const CodeSyntaxMap *NodeChange::codeSyntax() const {
  return _data_codeSyntax;
}

void NodeChange::set_codeSyntax(CodeSyntaxMap *value) {
  _data_codeSyntax = value;
}

HandoffStatusMap *NodeChange::handoffStatusMap() {
  return _data_handoffStatusMap;
}

const HandoffStatusMap *NodeChange::handoffStatusMap() const {
  return _data_handoffStatusMap;
}

void NodeChange::set_handoffStatusMap(HandoffStatusMap *value) {
  _data_handoffStatusMap = value;
}

AgendaPositionMap *NodeChange::agendaPositionMap() {
  return _data_agendaPositionMap;
}

const AgendaPositionMap *NodeChange::agendaPositionMap() const {
  return _data_agendaPositionMap;
}

void NodeChange::set_agendaPositionMap(AgendaPositionMap *value) {
  _data_agendaPositionMap = value;
}

AgendaMetadataMap *NodeChange::agendaMetadataMap() {
  return _data_agendaMetadataMap;
}

const AgendaMetadataMap *NodeChange::agendaMetadataMap() const {
  return _data_agendaMetadataMap;
}

void NodeChange::set_agendaMetadataMap(AgendaMetadataMap *value) {
  _data_agendaMetadataMap = value;
}

MigrationStatus *NodeChange::migrationStatus() {
  return _data_migrationStatus;
}

const MigrationStatus *NodeChange::migrationStatus() const {
  return _data_migrationStatus;
}

void NodeChange::set_migrationStatus(MigrationStatus *value) {
  _data_migrationStatus = value;
}

bool *NodeChange::isSoftDeleted() {
  return _flags[10] & 2147483648 ? &_data_isSoftDeleted : nullptr;
}

const bool *NodeChange::isSoftDeleted() const {
  return _flags[10] & 2147483648 ? &_data_isSoftDeleted : nullptr;
}

void NodeChange::set_isSoftDeleted(const bool &value) {
  _flags[10] |= 2147483648; _data_isSoftDeleted = value;
}

EditInfo *NodeChange::editInfo() {
  return _data_editInfo;
}

const EditInfo *NodeChange::editInfo() const {
  return _data_editInfo;
}

void NodeChange::set_editInfo(EditInfo *value) {
  _data_editInfo = value;
}

ColorProfile *NodeChange::colorProfile() {
  return _flags[11] & 2 ? &_data_colorProfile : nullptr;
}

const ColorProfile *NodeChange::colorProfile() const {
  return _flags[11] & 2 ? &_data_colorProfile : nullptr;
}

void NodeChange::set_colorProfile(const ColorProfile &value) {
  _flags[11] |= 2; _data_colorProfile = value;
}

SymbolId *NodeChange::detachedSymbolId() {
  return _data_detachedSymbolId;
}

const SymbolId *NodeChange::detachedSymbolId() const {
  return _data_detachedSymbolId;
}

void NodeChange::set_detachedSymbolId(SymbolId *value) {
  _data_detachedSymbolId = value;
}

ChildReadingDirection *NodeChange::childReadingDirection() {
  return _flags[11] & 8 ? &_data_childReadingDirection : nullptr;
}

const ChildReadingDirection *NodeChange::childReadingDirection() const {
  return _flags[11] & 8 ? &_data_childReadingDirection : nullptr;
}

void NodeChange::set_childReadingDirection(const ChildReadingDirection &value) {
  _flags[11] |= 8; _data_childReadingDirection = value;
}

kiwi::String *NodeChange::readingIndex() {
  return _flags[11] & 16 ? &_data_readingIndex : nullptr;
}

const kiwi::String *NodeChange::readingIndex() const {
  return _flags[11] & 16 ? &_data_readingIndex : nullptr;
}

void NodeChange::set_readingIndex(const kiwi::String &value) {
  _flags[11] |= 16; _data_readingIndex = value;
}

DocumentColorProfile *NodeChange::documentColorProfile() {
  return _flags[11] & 32 ? &_data_documentColorProfile : nullptr;
}

const DocumentColorProfile *NodeChange::documentColorProfile() const {
  return _flags[11] & 32 ? &_data_documentColorProfile : nullptr;
}

void NodeChange::set_documentColorProfile(const DocumentColorProfile &value) {
  _flags[11] |= 32; _data_documentColorProfile = value;
}

kiwi::Array<DeveloperRelatedLink> *NodeChange::developerRelatedLinks() {
  return _flags[11] & 64 ? &_data_developerRelatedLinks : nullptr;
}

const kiwi::Array<DeveloperRelatedLink> *NodeChange::developerRelatedLinks() const {
  return _flags[11] & 64 ? &_data_developerRelatedLinks : nullptr;
}

kiwi::Array<DeveloperRelatedLink> &NodeChange::set_developerRelatedLinks(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[11] |= 64; return _data_developerRelatedLinks = pool.array<DeveloperRelatedLink>(count);
}

kiwi::String *NodeChange::slideActiveThemeLibKey() {
  return _flags[11] & 128 ? &_data_slideActiveThemeLibKey : nullptr;
}

const kiwi::String *NodeChange::slideActiveThemeLibKey() const {
  return _flags[11] & 128 ? &_data_slideActiveThemeLibKey : nullptr;
}

void NodeChange::set_slideActiveThemeLibKey(const kiwi::String &value) {
  _flags[11] |= 128; _data_slideActiveThemeLibKey = value;
}

ARIAAttributesMap *NodeChange::ariaAttributes() {
  return _data_ariaAttributes;
}

const ARIAAttributesMap *NodeChange::ariaAttributes() const {
  return _data_ariaAttributes;
}

void NodeChange::set_ariaAttributes(ARIAAttributesMap *value) {
  _data_ariaAttributes = value;
}

bool NodeChange::encode(kiwi::ByteBuffer &_bb) {
  if (guid() != nullptr) {
    _bb.writeVarUint(1);
    if (!_data_guid->encode(_bb)) return false;
  }
  if (guidTag() != nullptr) {
    _bb.writeVarUint(53);
    _bb.writeVarUint(_data_guidTag);
  }
  if (phase() != nullptr) {
    _bb.writeVarUint(2);
    _bb.writeVarUint(static_cast<uint32_t>(_data_phase));
  }
  if (phaseTag() != nullptr) {
    _bb.writeVarUint(54);
    _bb.writeVarUint(_data_phaseTag);
  }
  if (parentIndex() != nullptr) {
    _bb.writeVarUint(3);
    if (!_data_parentIndex->encode(_bb)) return false;
  }
  if (parentIndexTag() != nullptr) {
    _bb.writeVarUint(55);
    _bb.writeVarUint(_data_parentIndexTag);
  }
  if (type() != nullptr) {
    _bb.writeVarUint(4);
    _bb.writeVarUint(static_cast<uint32_t>(_data_type));
  }
  if (typeTag() != nullptr) {
    _bb.writeVarUint(56);
    _bb.writeVarUint(_data_typeTag);
  }
  if (name() != nullptr) {
    _bb.writeVarUint(5);
    _bb.writeString(_data_name.c_str());
  }
  if (nameTag() != nullptr) {
    _bb.writeVarUint(57);
    _bb.writeVarUint(_data_nameTag);
  }
  if (isPublishable() != nullptr) {
    _bb.writeVarUint(174);
    _bb.writeByte(_data_isPublishable);
  }
  if (description() != nullptr) {
    _bb.writeVarUint(318);
    _bb.writeString(_data_description.c_str());
  }
  if (libraryMoveInfo() != nullptr) {
    _bb.writeVarUint(256);
    if (!_data_libraryMoveInfo->encode(_bb)) return false;
  }
  if (libraryMoveHistory() != nullptr) {
    _bb.writeVarUint(281);
    _bb.writeVarUint(_data_libraryMoveHistory.size());
    for (LibraryMoveHistoryItem &_it : _data_libraryMoveHistory) if (!_it.encode(_bb)) return false;
  }
  if (key() != nullptr) {
    _bb.writeVarUint(319);
    _bb.writeString(_data_key.c_str());
  }
  if (styleID() != nullptr) {
    _bb.writeVarUint(49);
    _bb.writeVarUint(_data_styleID);
  }
  if (styleIDTag() != nullptr) {
    _bb.writeVarUint(101);
    _bb.writeVarUint(_data_styleIDTag);
  }
  if (isSoftDeletedStyle() != nullptr) {
    _bb.writeVarUint(176);
    _bb.writeByte(_data_isSoftDeletedStyle);
  }
  if (isNonUpdateable() != nullptr) {
    _bb.writeVarUint(177);
    _bb.writeByte(_data_isNonUpdateable);
  }
  if (isFillStyle() != nullptr) {
    _bb.writeVarUint(157);
    _bb.writeByte(_data_isFillStyle);
  }
  if (isStrokeStyle() != nullptr) {
    _bb.writeVarUint(161);
    _bb.writeByte(_data_isStrokeStyle);
  }
  if (styleType() != nullptr) {
    _bb.writeVarUint(163);
    _bb.writeVarUint(static_cast<uint32_t>(_data_styleType));
  }
  if (styleDescription() != nullptr) {
    _bb.writeVarUint(191);
    _bb.writeString(_data_styleDescription.c_str());
  }
  if (version() != nullptr) {
    _bb.writeVarUint(171);
    _bb.writeString(_data_version.c_str());
  }
  if (sharedStyleMasterData() != nullptr) {
    _bb.writeVarUint(172);
    if (!_data_sharedStyleMasterData->encode(_bb)) return false;
  }
  if (sharedStyleReference() != nullptr) {
    _bb.writeVarUint(173);
    if (!_data_sharedStyleReference->encode(_bb)) return false;
  }
  if (sortPosition() != nullptr) {
    _bb.writeVarUint(320);
    _bb.writeString(_data_sortPosition.c_str());
  }
  if (ojansSuperSecretNodeField() != nullptr) {
    _bb.writeVarUint(345);
    if (!_data_ojansSuperSecretNodeField->encode(_bb)) return false;
  }
  if (sevMoonlitLilyData() != nullptr) {
    _bb.writeVarUint(348);
    if (!_data_sevMoonlitLilyData->encode(_bb)) return false;
  }
  if (inheritFillStyleID() != nullptr) {
    _bb.writeVarUint(158);
    if (!_data_inheritFillStyleID->encode(_bb)) return false;
  }
  if (inheritStrokeStyleID() != nullptr) {
    _bb.writeVarUint(162);
    if (!_data_inheritStrokeStyleID->encode(_bb)) return false;
  }
  if (inheritTextStyleID() != nullptr) {
    _bb.writeVarUint(167);
    if (!_data_inheritTextStyleID->encode(_bb)) return false;
  }
  if (inheritExportStyleID() != nullptr) {
    _bb.writeVarUint(168);
    if (!_data_inheritExportStyleID->encode(_bb)) return false;
  }
  if (inheritEffectStyleID() != nullptr) {
    _bb.writeVarUint(169);
    if (!_data_inheritEffectStyleID->encode(_bb)) return false;
  }
  if (inheritGridStyleID() != nullptr) {
    _bb.writeVarUint(170);
    if (!_data_inheritGridStyleID->encode(_bb)) return false;
  }
  if (inheritFillStyleIDForStroke() != nullptr) {
    _bb.writeVarUint(185);
    if (!_data_inheritFillStyleIDForStroke->encode(_bb)) return false;
  }
  if (styleIdForFill() != nullptr) {
    _bb.writeVarUint(332);
    if (!_data_styleIdForFill->encode(_bb)) return false;
  }
  if (styleIdForStrokeFill() != nullptr) {
    _bb.writeVarUint(333);
    if (!_data_styleIdForStrokeFill->encode(_bb)) return false;
  }
  if (styleIdForText() != nullptr) {
    _bb.writeVarUint(334);
    if (!_data_styleIdForText->encode(_bb)) return false;
  }
  if (styleIdForEffect() != nullptr) {
    _bb.writeVarUint(335);
    if (!_data_styleIdForEffect->encode(_bb)) return false;
  }
  if (styleIdForGrid() != nullptr) {
    _bb.writeVarUint(336);
    if (!_data_styleIdForGrid->encode(_bb)) return false;
  }
  if (backgroundPaints() != nullptr) {
    _bb.writeVarUint(193);
    _bb.writeVarUint(_data_backgroundPaints.size());
    for (Paint &_it : _data_backgroundPaints) if (!_it.encode(_bb)) return false;
  }
  if (inheritFillStyleIDForBackground() != nullptr) {
    _bb.writeVarUint(194);
    if (!_data_inheritFillStyleIDForBackground->encode(_bb)) return false;
  }
  if (isStateGroup() != nullptr) {
    _bb.writeVarUint(225);
    _bb.writeByte(_data_isStateGroup);
  }
  if (stateGroupPropertyValueOrders() != nullptr) {
    _bb.writeVarUint(238);
    _bb.writeVarUint(_data_stateGroupPropertyValueOrders.size());
    for (StateGroupPropertyValueOrder &_it : _data_stateGroupPropertyValueOrders) if (!_it.encode(_bb)) return false;
  }
  if (sharedSymbolReference() != nullptr) {
    _bb.writeVarUint(122);
    if (!_data_sharedSymbolReference->encode(_bb)) return false;
  }
  if (isSymbolPublishable() != nullptr) {
    _bb.writeVarUint(123);
    _bb.writeByte(_data_isSymbolPublishable);
  }
  if (sharedSymbolMappings() != nullptr) {
    _bb.writeVarUint(124);
    _bb.writeVarUint(_data_sharedSymbolMappings.size());
    for (GUIDPathMapping &_it : _data_sharedSymbolMappings) if (!_it.encode(_bb)) return false;
  }
  if (sharedSymbolVersion() != nullptr) {
    _bb.writeVarUint(126);
    _bb.writeString(_data_sharedSymbolVersion.c_str());
  }
  if (sharedComponentMasterData() != nullptr) {
    _bb.writeVarUint(152);
    if (!_data_sharedComponentMasterData->encode(_bb)) return false;
  }
  if (symbolDescription() != nullptr) {
    _bb.writeVarUint(144);
    _bb.writeString(_data_symbolDescription.c_str());
  }
  if (unflatteningMappings() != nullptr) {
    _bb.writeVarUint(164);
    _bb.writeVarUint(_data_unflatteningMappings.size());
    for (GUIDPathMapping &_it : _data_unflatteningMappings) if (!_it.encode(_bb)) return false;
  }
  if (forceUnflatteningMappings() != nullptr) {
    _bb.writeVarUint(228);
    _bb.writeVarUint(_data_forceUnflatteningMappings.size());
    for (GUIDPathMapping &_it : _data_forceUnflatteningMappings) if (!_it.encode(_bb)) return false;
  }
  if (publishFile() != nullptr) {
    _bb.writeVarUint(214);
    _bb.writeString(_data_publishFile.c_str());
  }
  if (publishID() != nullptr) {
    _bb.writeVarUint(215);
    if (!_data_publishID->encode(_bb)) return false;
  }
  if (componentKey() != nullptr) {
    _bb.writeVarUint(216);
    _bb.writeString(_data_componentKey.c_str());
  }
  if (isC2() != nullptr) {
    _bb.writeVarUint(217);
    _bb.writeByte(_data_isC2);
  }
  if (publishedVersion() != nullptr) {
    _bb.writeVarUint(218);
    _bb.writeString(_data_publishedVersion.c_str());
  }
  if (originComponentKey() != nullptr) {
    _bb.writeVarUint(252);
    _bb.writeString(_data_originComponentKey.c_str());
  }
  if (componentPropDefs() != nullptr) {
    _bb.writeVarUint(266);
    _bb.writeVarUint(_data_componentPropDefs.size());
    for (ComponentPropDef &_it : _data_componentPropDefs) if (!_it.encode(_bb)) return false;
  }
  if (componentPropRefs() != nullptr) {
    _bb.writeVarUint(267);
    _bb.writeVarUint(_data_componentPropRefs.size());
    for (ComponentPropRef &_it : _data_componentPropRefs) if (!_it.encode(_bb)) return false;
  }
  if (symbolData() != nullptr) {
    _bb.writeVarUint(113);
    if (!_data_symbolData->encode(_bb)) return false;
  }
  if (symbolDataTag() != nullptr) {
    _bb.writeVarUint(114);
    _bb.writeVarUint(_data_symbolDataTag);
  }
  if (derivedSymbolData() != nullptr) {
    _bb.writeVarUint(125);
    _bb.writeVarUint(_data_derivedSymbolData.size());
    for (NodeChange &_it : _data_derivedSymbolData) if (!_it.encode(_bb)) return false;
  }
  if (overriddenSymbolID() != nullptr) {
    _bb.writeVarUint(143);
    if (!_data_overriddenSymbolID->encode(_bb)) return false;
  }
  if (componentPropAssignments() != nullptr) {
    _bb.writeVarUint(268);
    _bb.writeVarUint(_data_componentPropAssignments.size());
    for (ComponentPropAssignment &_it : _data_componentPropAssignments) if (!_it.encode(_bb)) return false;
  }
  if (propsAreBubbled() != nullptr) {
    _bb.writeVarUint(305);
    _bb.writeByte(_data_propsAreBubbled);
  }
  if (overrideStash() != nullptr) {
    _bb.writeVarUint(248);
    _bb.writeVarUint(_data_overrideStash.size());
    for (InstanceOverrideStash &_it : _data_overrideStash) if (!_it.encode(_bb)) return false;
  }
  if (overrideStashV2() != nullptr) {
    _bb.writeVarUint(250);
    _bb.writeVarUint(_data_overrideStashV2.size());
    for (InstanceOverrideStashV2 &_it : _data_overrideStashV2) if (!_it.encode(_bb)) return false;
  }
  if (guidPath() != nullptr) {
    _bb.writeVarUint(111);
    if (!_data_guidPath->encode(_bb)) return false;
  }
  if (guidPathTag() != nullptr) {
    _bb.writeVarUint(112);
    _bb.writeVarUint(_data_guidPathTag);
  }
  if (overrideLevel() != nullptr) {
    _bb.writeVarUint(321);
    _bb.writeVarInt(_data_overrideLevel);
  }
  if (fontSize() != nullptr) {
    _bb.writeVarUint(21);
    _bb.writeVarFloat(_data_fontSize);
  }
  if (fontSizeTag() != nullptr) {
    _bb.writeVarUint(73);
    _bb.writeVarUint(_data_fontSizeTag);
  }
  if (paragraphIndent() != nullptr) {
    _bb.writeVarUint(22);
    _bb.writeVarFloat(_data_paragraphIndent);
  }
  if (paragraphIndentTag() != nullptr) {
    _bb.writeVarUint(74);
    _bb.writeVarUint(_data_paragraphIndentTag);
  }
  if (paragraphSpacing() != nullptr) {
    _bb.writeVarUint(23);
    _bb.writeVarFloat(_data_paragraphSpacing);
  }
  if (paragraphSpacingTag() != nullptr) {
    _bb.writeVarUint(75);
    _bb.writeVarUint(_data_paragraphSpacingTag);
  }
  if (textAlignHorizontal() != nullptr) {
    _bb.writeVarUint(32);
    _bb.writeVarUint(static_cast<uint32_t>(_data_textAlignHorizontal));
  }
  if (textAlignHorizontalTag() != nullptr) {
    _bb.writeVarUint(84);
    _bb.writeVarUint(_data_textAlignHorizontalTag);
  }
  if (textAlignVertical() != nullptr) {
    _bb.writeVarUint(33);
    _bb.writeVarUint(static_cast<uint32_t>(_data_textAlignVertical));
  }
  if (textAlignVerticalTag() != nullptr) {
    _bb.writeVarUint(85);
    _bb.writeVarUint(_data_textAlignVerticalTag);
  }
  if (textCase() != nullptr) {
    _bb.writeVarUint(34);
    _bb.writeVarUint(static_cast<uint32_t>(_data_textCase));
  }
  if (textCaseTag() != nullptr) {
    _bb.writeVarUint(86);
    _bb.writeVarUint(_data_textCaseTag);
  }
  if (textDecoration() != nullptr) {
    _bb.writeVarUint(35);
    _bb.writeVarUint(static_cast<uint32_t>(_data_textDecoration));
  }
  if (textDecorationTag() != nullptr) {
    _bb.writeVarUint(87);
    _bb.writeVarUint(_data_textDecorationTag);
  }
  if (lineHeight() != nullptr) {
    _bb.writeVarUint(40);
    if (!_data_lineHeight->encode(_bb)) return false;
  }
  if (lineHeightTag() != nullptr) {
    _bb.writeVarUint(92);
    _bb.writeVarUint(_data_lineHeightTag);
  }
  if (fontName() != nullptr) {
    _bb.writeVarUint(41);
    if (!_data_fontName->encode(_bb)) return false;
  }
  if (fontNameTag() != nullptr) {
    _bb.writeVarUint(93);
    _bb.writeVarUint(_data_fontNameTag);
  }
  if (textData() != nullptr) {
    _bb.writeVarUint(42);
    if (!_data_textData->encode(_bb)) return false;
  }
  if (textDataTag() != nullptr) {
    _bb.writeVarUint(94);
    _bb.writeVarUint(_data_textDataTag);
  }
  if (derivedTextData() != nullptr) {
    _bb.writeVarUint(359);
    if (!_data_derivedTextData->encode(_bb)) return false;
  }
  if (fontVariantCommonLigatures() != nullptr) {
    _bb.writeVarUint(127);
    _bb.writeByte(_data_fontVariantCommonLigatures);
  }
  if (fontVariantContextualLigatures() != nullptr) {
    _bb.writeVarUint(128);
    _bb.writeByte(_data_fontVariantContextualLigatures);
  }
  if (fontVariantDiscretionaryLigatures() != nullptr) {
    _bb.writeVarUint(129);
    _bb.writeByte(_data_fontVariantDiscretionaryLigatures);
  }
  if (fontVariantHistoricalLigatures() != nullptr) {
    _bb.writeVarUint(130);
    _bb.writeByte(_data_fontVariantHistoricalLigatures);
  }
  if (fontVariantOrdinal() != nullptr) {
    _bb.writeVarUint(131);
    _bb.writeByte(_data_fontVariantOrdinal);
  }
  if (fontVariantSlashedZero() != nullptr) {
    _bb.writeVarUint(132);
    _bb.writeByte(_data_fontVariantSlashedZero);
  }
  if (fontVariantNumericFigure() != nullptr) {
    _bb.writeVarUint(133);
    _bb.writeVarUint(static_cast<uint32_t>(_data_fontVariantNumericFigure));
  }
  if (fontVariantNumericSpacing() != nullptr) {
    _bb.writeVarUint(134);
    _bb.writeVarUint(static_cast<uint32_t>(_data_fontVariantNumericSpacing));
  }
  if (fontVariantNumericFraction() != nullptr) {
    _bb.writeVarUint(135);
    _bb.writeVarUint(static_cast<uint32_t>(_data_fontVariantNumericFraction));
  }
  if (fontVariantCaps() != nullptr) {
    _bb.writeVarUint(136);
    _bb.writeVarUint(static_cast<uint32_t>(_data_fontVariantCaps));
  }
  if (fontVariantPosition() != nullptr) {
    _bb.writeVarUint(137);
    _bb.writeVarUint(static_cast<uint32_t>(_data_fontVariantPosition));
  }
  if (letterSpacing() != nullptr) {
    _bb.writeVarUint(165);
    if (!_data_letterSpacing->encode(_bb)) return false;
  }
  if (fontVersion() != nullptr) {
    _bb.writeVarUint(202);
    _bb.writeString(_data_fontVersion.c_str());
  }
  if (leadingTrim() != nullptr) {
    _bb.writeVarUint(322);
    _bb.writeVarUint(static_cast<uint32_t>(_data_leadingTrim));
  }
  if (hangingPunctuation() != nullptr) {
    _bb.writeVarUint(337);
    _bb.writeByte(_data_hangingPunctuation);
  }
  if (hangingList() != nullptr) {
    _bb.writeVarUint(339);
    _bb.writeByte(_data_hangingList);
  }
  if (maxLines() != nullptr) {
    _bb.writeVarUint(351);
    _bb.writeVarInt(_data_maxLines);
  }
  if (sectionStatus() != nullptr) {
    _bb.writeVarUint(352);
    _bb.writeVarUint(static_cast<uint32_t>(_data_sectionStatus));
  }
  if (sectionStatusInfo() != nullptr) {
    _bb.writeVarUint(355);
    if (!_data_sectionStatusInfo->encode(_bb)) return false;
  }
  if (textUserLayoutVersion() != nullptr) {
    _bb.writeVarUint(203);
    _bb.writeVarUint(_data_textUserLayoutVersion);
  }
  if (toggledOnOTFeatures() != nullptr) {
    _bb.writeVarUint(205);
    _bb.writeVarUint(_data_toggledOnOTFeatures.size());
    for (OpenTypeFeature &_it : _data_toggledOnOTFeatures) _bb.writeVarUint(static_cast<uint32_t>(_it));
  }
  if (toggledOffOTFeatures() != nullptr) {
    _bb.writeVarUint(206);
    _bb.writeVarUint(_data_toggledOffOTFeatures.size());
    for (OpenTypeFeature &_it : _data_toggledOffOTFeatures) _bb.writeVarUint(static_cast<uint32_t>(_it));
  }
  if (hyperlink() != nullptr) {
    _bb.writeVarUint(223);
    if (!_data_hyperlink->encode(_bb)) return false;
  }
  if (mention() != nullptr) {
    _bb.writeVarUint(340);
    if (!_data_mention->encode(_bb)) return false;
  }
  if (fontVariations() != nullptr) {
    _bb.writeVarUint(260);
    _bb.writeVarUint(_data_fontVariations.size());
    for (FontVariation &_it : _data_fontVariations) if (!_it.encode(_bb)) return false;
  }
  if (textBidiVersion() != nullptr) {
    _bb.writeVarUint(279);
    _bb.writeVarUint(_data_textBidiVersion);
  }
  if (textTruncation() != nullptr) {
    _bb.writeVarUint(280);
    _bb.writeVarUint(static_cast<uint32_t>(_data_textTruncation));
  }
  if (hasHadRTLText() != nullptr) {
    _bb.writeVarUint(292);
    _bb.writeByte(_data_hasHadRTLText);
  }
  if (visible() != nullptr) {
    _bb.writeVarUint(6);
    _bb.writeByte(_data_visible);
  }
  if (visibleTag() != nullptr) {
    _bb.writeVarUint(58);
    _bb.writeVarUint(_data_visibleTag);
  }
  if (locked() != nullptr) {
    _bb.writeVarUint(7);
    _bb.writeByte(_data_locked);
  }
  if (lockedTag() != nullptr) {
    _bb.writeVarUint(59);
    _bb.writeVarUint(_data_lockedTag);
  }
  if (opacity() != nullptr) {
    _bb.writeVarUint(8);
    _bb.writeVarFloat(_data_opacity);
  }
  if (opacityTag() != nullptr) {
    _bb.writeVarUint(60);
    _bb.writeVarUint(_data_opacityTag);
  }
  if (blendMode() != nullptr) {
    _bb.writeVarUint(9);
    _bb.writeVarUint(static_cast<uint32_t>(_data_blendMode));
  }
  if (blendModeTag() != nullptr) {
    _bb.writeVarUint(61);
    _bb.writeVarUint(_data_blendModeTag);
  }
  if (size() != nullptr) {
    _bb.writeVarUint(11);
    if (!_data_size->encode(_bb)) return false;
  }
  if (sizeTag() != nullptr) {
    _bb.writeVarUint(63);
    _bb.writeVarUint(_data_sizeTag);
  }
  if (transform() != nullptr) {
    _bb.writeVarUint(12);
    if (!_data_transform->encode(_bb)) return false;
  }
  if (transformTag() != nullptr) {
    _bb.writeVarUint(64);
    _bb.writeVarUint(_data_transformTag);
  }
  if (dashPattern() != nullptr) {
    _bb.writeVarUint(13);
    _bb.writeVarUint(_data_dashPattern.size());
    for (float &_it : _data_dashPattern) _bb.writeVarFloat(_it);
  }
  if (dashPatternTag() != nullptr) {
    _bb.writeVarUint(65);
    _bb.writeVarUint(_data_dashPatternTag);
  }
  if (mask() != nullptr) {
    _bb.writeVarUint(16);
    _bb.writeByte(_data_mask);
  }
  if (maskTag() != nullptr) {
    _bb.writeVarUint(68);
    _bb.writeVarUint(_data_maskTag);
  }
  if (maskIsOutline() != nullptr) {
    _bb.writeVarUint(18);
    _bb.writeByte(_data_maskIsOutline);
  }
  if (maskIsOutlineTag() != nullptr) {
    _bb.writeVarUint(70);
    _bb.writeVarUint(_data_maskIsOutlineTag);
  }
  if (maskType() != nullptr) {
    _bb.writeVarUint(317);
    _bb.writeVarUint(static_cast<uint32_t>(_data_maskType));
  }
  if (backgroundOpacity() != nullptr) {
    _bb.writeVarUint(19);
    _bb.writeVarFloat(_data_backgroundOpacity);
  }
  if (backgroundOpacityTag() != nullptr) {
    _bb.writeVarUint(71);
    _bb.writeVarUint(_data_backgroundOpacityTag);
  }
  if (cornerRadius() != nullptr) {
    _bb.writeVarUint(20);
    _bb.writeVarFloat(_data_cornerRadius);
  }
  if (cornerRadiusTag() != nullptr) {
    _bb.writeVarUint(72);
    _bb.writeVarUint(_data_cornerRadiusTag);
  }
  if (strokeWeight() != nullptr) {
    _bb.writeVarUint(26);
    _bb.writeVarFloat(_data_strokeWeight);
  }
  if (strokeWeightTag() != nullptr) {
    _bb.writeVarUint(78);
    _bb.writeVarUint(_data_strokeWeightTag);
  }
  if (strokeAlign() != nullptr) {
    _bb.writeVarUint(29);
    _bb.writeVarUint(static_cast<uint32_t>(_data_strokeAlign));
  }
  if (strokeAlignTag() != nullptr) {
    _bb.writeVarUint(81);
    _bb.writeVarUint(_data_strokeAlignTag);
  }
  if (strokeCap() != nullptr) {
    _bb.writeVarUint(30);
    _bb.writeVarUint(static_cast<uint32_t>(_data_strokeCap));
  }
  if (strokeCapTag() != nullptr) {
    _bb.writeVarUint(82);
    _bb.writeVarUint(_data_strokeCapTag);
  }
  if (strokeJoin() != nullptr) {
    _bb.writeVarUint(31);
    _bb.writeVarUint(static_cast<uint32_t>(_data_strokeJoin));
  }
  if (strokeJoinTag() != nullptr) {
    _bb.writeVarUint(83);
    _bb.writeVarUint(_data_strokeJoinTag);
  }
  if (fillPaints() != nullptr) {
    _bb.writeVarUint(38);
    _bb.writeVarUint(_data_fillPaints.size());
    for (Paint &_it : _data_fillPaints) if (!_it.encode(_bb)) return false;
  }
  if (fillPaintsTag() != nullptr) {
    _bb.writeVarUint(90);
    _bb.writeVarUint(_data_fillPaintsTag);
  }
  if (strokePaints() != nullptr) {
    _bb.writeVarUint(39);
    _bb.writeVarUint(_data_strokePaints.size());
    for (Paint &_it : _data_strokePaints) if (!_it.encode(_bb)) return false;
  }
  if (strokePaintsTag() != nullptr) {
    _bb.writeVarUint(91);
    _bb.writeVarUint(_data_strokePaintsTag);
  }
  if (effects() != nullptr) {
    _bb.writeVarUint(43);
    _bb.writeVarUint(_data_effects.size());
    for (Effect &_it : _data_effects) if (!_it.encode(_bb)) return false;
  }
  if (effectsTag() != nullptr) {
    _bb.writeVarUint(95);
    _bb.writeVarUint(_data_effectsTag);
  }
  if (backgroundColor() != nullptr) {
    _bb.writeVarUint(50);
    if (!_data_backgroundColor->encode(_bb)) return false;
  }
  if (backgroundColorTag() != nullptr) {
    _bb.writeVarUint(102);
    _bb.writeVarUint(_data_backgroundColorTag);
  }
  if (fillGeometry() != nullptr) {
    _bb.writeVarUint(51);
    _bb.writeVarUint(_data_fillGeometry.size());
    for (Path &_it : _data_fillGeometry) if (!_it.encode(_bb)) return false;
  }
  if (fillGeometryTag() != nullptr) {
    _bb.writeVarUint(103);
    _bb.writeVarUint(_data_fillGeometryTag);
  }
  if (strokeGeometry() != nullptr) {
    _bb.writeVarUint(52);
    _bb.writeVarUint(_data_strokeGeometry.size());
    for (Path &_it : _data_strokeGeometry) if (!_it.encode(_bb)) return false;
  }
  if (strokeGeometryTag() != nullptr) {
    _bb.writeVarUint(104);
    _bb.writeVarUint(_data_strokeGeometryTag);
  }
  if (rectangleTopLeftCornerRadius() != nullptr) {
    _bb.writeVarUint(145);
    _bb.writeVarFloat(_data_rectangleTopLeftCornerRadius);
  }
  if (rectangleTopRightCornerRadius() != nullptr) {
    _bb.writeVarUint(146);
    _bb.writeVarFloat(_data_rectangleTopRightCornerRadius);
  }
  if (rectangleBottomLeftCornerRadius() != nullptr) {
    _bb.writeVarUint(147);
    _bb.writeVarFloat(_data_rectangleBottomLeftCornerRadius);
  }
  if (rectangleBottomRightCornerRadius() != nullptr) {
    _bb.writeVarUint(148);
    _bb.writeVarFloat(_data_rectangleBottomRightCornerRadius);
  }
  if (rectangleCornerRadiiIndependent() != nullptr) {
    _bb.writeVarUint(149);
    _bb.writeByte(_data_rectangleCornerRadiiIndependent);
  }
  if (rectangleCornerToolIndependent() != nullptr) {
    _bb.writeVarUint(150);
    _bb.writeByte(_data_rectangleCornerToolIndependent);
  }
  if (proportionsConstrained() != nullptr) {
    _bb.writeVarUint(151);
    _bb.writeByte(_data_proportionsConstrained);
  }
  if (useAbsoluteBounds() != nullptr) {
    _bb.writeVarUint(258);
    _bb.writeByte(_data_useAbsoluteBounds);
  }
  if (borderTopHidden() != nullptr) {
    _bb.writeVarUint(287);
    _bb.writeByte(_data_borderTopHidden);
  }
  if (borderBottomHidden() != nullptr) {
    _bb.writeVarUint(288);
    _bb.writeByte(_data_borderBottomHidden);
  }
  if (borderLeftHidden() != nullptr) {
    _bb.writeVarUint(289);
    _bb.writeByte(_data_borderLeftHidden);
  }
  if (borderRightHidden() != nullptr) {
    _bb.writeVarUint(290);
    _bb.writeByte(_data_borderRightHidden);
  }
  if (bordersTakeSpace() != nullptr) {
    _bb.writeVarUint(294);
    _bb.writeByte(_data_bordersTakeSpace);
  }
  if (borderTopWeight() != nullptr) {
    _bb.writeVarUint(295);
    _bb.writeVarFloat(_data_borderTopWeight);
  }
  if (borderBottomWeight() != nullptr) {
    _bb.writeVarUint(296);
    _bb.writeVarFloat(_data_borderBottomWeight);
  }
  if (borderLeftWeight() != nullptr) {
    _bb.writeVarUint(297);
    _bb.writeVarFloat(_data_borderLeftWeight);
  }
  if (borderRightWeight() != nullptr) {
    _bb.writeVarUint(298);
    _bb.writeVarFloat(_data_borderRightWeight);
  }
  if (borderStrokeWeightsIndependent() != nullptr) {
    _bb.writeVarUint(299);
    _bb.writeByte(_data_borderStrokeWeightsIndependent);
  }
  if (horizontalConstraint() != nullptr) {
    _bb.writeVarUint(28);
    _bb.writeVarUint(static_cast<uint32_t>(_data_horizontalConstraint));
  }
  if (horizontalConstraintTag() != nullptr) {
    _bb.writeVarUint(80);
    _bb.writeVarUint(_data_horizontalConstraintTag);
  }
  if (stackMode() != nullptr) {
    _bb.writeVarUint(105);
    _bb.writeVarUint(static_cast<uint32_t>(_data_stackMode));
  }
  if (stackModeTag() != nullptr) {
    _bb.writeVarUint(106);
    _bb.writeVarUint(_data_stackModeTag);
  }
  if (stackSpacing() != nullptr) {
    _bb.writeVarUint(107);
    _bb.writeVarFloat(_data_stackSpacing);
  }
  if (stackSpacingTag() != nullptr) {
    _bb.writeVarUint(108);
    _bb.writeVarUint(_data_stackSpacingTag);
  }
  if (stackPadding() != nullptr) {
    _bb.writeVarUint(109);
    _bb.writeVarFloat(_data_stackPadding);
  }
  if (stackPaddingTag() != nullptr) {
    _bb.writeVarUint(110);
    _bb.writeVarUint(_data_stackPaddingTag);
  }
  if (stackCounterAlign() != nullptr) {
    _bb.writeVarUint(120);
    _bb.writeVarUint(static_cast<uint32_t>(_data_stackCounterAlign));
  }
  if (stackJustify() != nullptr) {
    _bb.writeVarUint(121);
    _bb.writeVarUint(static_cast<uint32_t>(_data_stackJustify));
  }
  if (stackAlign() != nullptr) {
    _bb.writeVarUint(208);
    _bb.writeVarUint(static_cast<uint32_t>(_data_stackAlign));
  }
  if (stackHorizontalPadding() != nullptr) {
    _bb.writeVarUint(209);
    _bb.writeVarFloat(_data_stackHorizontalPadding);
  }
  if (stackVerticalPadding() != nullptr) {
    _bb.writeVarUint(210);
    _bb.writeVarFloat(_data_stackVerticalPadding);
  }
  if (stackWidth() != nullptr) {
    _bb.writeVarUint(211);
    _bb.writeVarUint(static_cast<uint32_t>(_data_stackWidth));
  }
  if (stackHeight() != nullptr) {
    _bb.writeVarUint(212);
    _bb.writeVarUint(static_cast<uint32_t>(_data_stackHeight));
  }
  if (stackPrimarySizing() != nullptr) {
    _bb.writeVarUint(229);
    _bb.writeVarUint(static_cast<uint32_t>(_data_stackPrimarySizing));
  }
  if (stackPrimaryAlignItems() != nullptr) {
    _bb.writeVarUint(230);
    _bb.writeVarUint(static_cast<uint32_t>(_data_stackPrimaryAlignItems));
  }
  if (stackCounterAlignItems() != nullptr) {
    _bb.writeVarUint(231);
    _bb.writeVarUint(static_cast<uint32_t>(_data_stackCounterAlignItems));
  }
  if (stackChildPrimaryGrow() != nullptr) {
    _bb.writeVarUint(232);
    _bb.writeVarFloat(_data_stackChildPrimaryGrow);
  }
  if (stackPaddingRight() != nullptr) {
    _bb.writeVarUint(233);
    _bb.writeVarFloat(_data_stackPaddingRight);
  }
  if (stackPaddingBottom() != nullptr) {
    _bb.writeVarUint(234);
    _bb.writeVarFloat(_data_stackPaddingBottom);
  }
  if (stackChildAlignSelf() != nullptr) {
    _bb.writeVarUint(236);
    _bb.writeVarUint(static_cast<uint32_t>(_data_stackChildAlignSelf));
  }
  if (stackPositioning() != nullptr) {
    _bb.writeVarUint(269);
    _bb.writeVarUint(static_cast<uint32_t>(_data_stackPositioning));
  }
  if (stackReverseZIndex() != nullptr) {
    _bb.writeVarUint(271);
    _bb.writeByte(_data_stackReverseZIndex);
  }
  if (stackWrap() != nullptr) {
    _bb.writeVarUint(323);
    _bb.writeVarUint(static_cast<uint32_t>(_data_stackWrap));
  }
  if (stackCounterSpacing() != nullptr) {
    _bb.writeVarUint(324);
    _bb.writeVarFloat(_data_stackCounterSpacing);
  }
  if (minSize() != nullptr) {
    _bb.writeVarUint(325);
    if (!_data_minSize->encode(_bb)) return false;
  }
  if (maxSize() != nullptr) {
    _bb.writeVarUint(326);
    if (!_data_maxSize->encode(_bb)) return false;
  }
  if (stackCounterAlignContent() != nullptr) {
    _bb.writeVarUint(343);
    _bb.writeVarUint(static_cast<uint32_t>(_data_stackCounterAlignContent));
  }
  if (isSnakeGameBoard() != nullptr) {
    _bb.writeVarUint(344);
    _bb.writeByte(_data_isSnakeGameBoard);
  }
  if (transitionNodeID() != nullptr) {
    _bb.writeVarUint(139);
    if (!_data_transitionNodeID->encode(_bb)) return false;
  }
  if (prototypeStartNodeID() != nullptr) {
    _bb.writeVarUint(140);
    if (!_data_prototypeStartNodeID->encode(_bb)) return false;
  }
  if (prototypeBackgroundColor() != nullptr) {
    _bb.writeVarUint(141);
    if (!_data_prototypeBackgroundColor->encode(_bb)) return false;
  }
  if (transitionInfo() != nullptr) {
    _bb.writeVarUint(153);
    if (!_data_transitionInfo->encode(_bb)) return false;
  }
  if (transitionType() != nullptr) {
    _bb.writeVarUint(154);
    _bb.writeVarUint(static_cast<uint32_t>(_data_transitionType));
  }
  if (transitionDuration() != nullptr) {
    _bb.writeVarUint(155);
    _bb.writeVarFloat(_data_transitionDuration);
  }
  if (easingType() != nullptr) {
    _bb.writeVarUint(156);
    _bb.writeVarUint(static_cast<uint32_t>(_data_easingType));
  }
  if (transitionPreserveScroll() != nullptr) {
    _bb.writeVarUint(181);
    _bb.writeByte(_data_transitionPreserveScroll);
  }
  if (connectionType() != nullptr) {
    _bb.writeVarUint(182);
    _bb.writeVarUint(static_cast<uint32_t>(_data_connectionType));
  }
  if (connectionURL() != nullptr) {
    _bb.writeVarUint(183);
    _bb.writeString(_data_connectionURL.c_str());
  }
  if (prototypeDevice() != nullptr) {
    _bb.writeVarUint(184);
    if (!_data_prototypeDevice->encode(_bb)) return false;
  }
  if (interactionType() != nullptr) {
    _bb.writeVarUint(187);
    _bb.writeVarUint(static_cast<uint32_t>(_data_interactionType));
  }
  if (transitionTimeout() != nullptr) {
    _bb.writeVarUint(188);
    _bb.writeVarFloat(_data_transitionTimeout);
  }
  if (interactionMaintained() != nullptr) {
    _bb.writeVarUint(189);
    _bb.writeByte(_data_interactionMaintained);
  }
  if (interactionDuration() != nullptr) {
    _bb.writeVarUint(190);
    _bb.writeVarFloat(_data_interactionDuration);
  }
  if (destinationIsOverlay() != nullptr) {
    _bb.writeVarUint(192);
    _bb.writeByte(_data_destinationIsOverlay);
  }
  if (transitionShouldSmartAnimate() != nullptr) {
    _bb.writeVarUint(207);
    _bb.writeByte(_data_transitionShouldSmartAnimate);
  }
  if (prototypeInteractions() != nullptr) {
    _bb.writeVarUint(226);
    _bb.writeVarUint(_data_prototypeInteractions.size());
    for (PrototypeInteraction &_it : _data_prototypeInteractions) if (!_it.encode(_bb)) return false;
  }
  if (prototypeStartingPoint() != nullptr) {
    _bb.writeVarUint(249);
    if (!_data_prototypeStartingPoint->encode(_bb)) return false;
  }
  if (pluginData() != nullptr) {
    _bb.writeVarUint(204);
    _bb.writeVarUint(_data_pluginData.size());
    for (PluginData &_it : _data_pluginData) if (!_it.encode(_bb)) return false;
  }
  if (pluginRelaunchData() != nullptr) {
    _bb.writeVarUint(219);
    _bb.writeVarUint(_data_pluginRelaunchData.size());
    for (PluginRelaunchData &_it : _data_pluginRelaunchData) if (!_it.encode(_bb)) return false;
  }
  if (connectorStart() != nullptr) {
    _bb.writeVarUint(242);
    if (!_data_connectorStart->encode(_bb)) return false;
  }
  if (connectorEnd() != nullptr) {
    _bb.writeVarUint(243);
    if (!_data_connectorEnd->encode(_bb)) return false;
  }
  if (connectorLineStyle() != nullptr) {
    _bb.writeVarUint(244);
    _bb.writeVarUint(static_cast<uint32_t>(_data_connectorLineStyle));
  }
  if (connectorStartCap() != nullptr) {
    _bb.writeVarUint(245);
    _bb.writeVarUint(static_cast<uint32_t>(_data_connectorStartCap));
  }
  if (connectorEndCap() != nullptr) {
    _bb.writeVarUint(246);
    _bb.writeVarUint(static_cast<uint32_t>(_data_connectorEndCap));
  }
  if (connectorControlPoints() != nullptr) {
    _bb.writeVarUint(253);
    _bb.writeVarUint(_data_connectorControlPoints.size());
    for (ConnectorControlPoint &_it : _data_connectorControlPoints) if (!_it.encode(_bb)) return false;
  }
  if (connectorTextMidpoint() != nullptr) {
    _bb.writeVarUint(255);
    if (!_data_connectorTextMidpoint->encode(_bb)) return false;
  }
  if (shapeWithTextType() != nullptr) {
    _bb.writeVarUint(241);
    _bb.writeVarUint(static_cast<uint32_t>(_data_shapeWithTextType));
  }
  if (shapeUserHeight() != nullptr) {
    _bb.writeVarUint(247);
    _bb.writeVarFloat(_data_shapeUserHeight);
  }
  if (derivedImmutableFrameData() != nullptr) {
    _bb.writeVarUint(254);
    if (!_data_derivedImmutableFrameData->encode(_bb)) return false;
  }
  if (derivedImmutableFrameDataVersion() != nullptr) {
    _bb.writeVarUint(338);
    if (!_data_derivedImmutableFrameDataVersion->encode(_bb)) return false;
  }
  if (nodeGenerationData() != nullptr) {
    _bb.writeVarUint(240);
    if (!_data_nodeGenerationData->encode(_bb)) return false;
  }
  if (codeBlockLanguage() != nullptr) {
    _bb.writeVarUint(259);
    _bb.writeVarUint(static_cast<uint32_t>(_data_codeBlockLanguage));
  }
  if (linkPreviewData() != nullptr) {
    _bb.writeVarUint(278);
    if (!_data_linkPreviewData->encode(_bb)) return false;
  }
  if (shapeTruncates() != nullptr) {
    _bb.writeVarUint(282);
    _bb.writeByte(_data_shapeTruncates);
  }
  if (sectionContentsHidden() != nullptr) {
    _bb.writeVarUint(283);
    _bb.writeByte(_data_sectionContentsHidden);
  }
  if (videoPlayback() != nullptr) {
    _bb.writeVarUint(300);
    if (!_data_videoPlayback->encode(_bb)) return false;
  }
  if (stampData() != nullptr) {
    _bb.writeVarUint(301);
    if (!_data_stampData->encode(_bb)) return false;
  }
  if (widgetSyncedState() != nullptr) {
    _bb.writeVarUint(273);
    if (!_data_widgetSyncedState->encode(_bb)) return false;
  }
  if (widgetSyncCursor() != nullptr) {
    _bb.writeVarUint(274);
    _bb.writeVarUint(_data_widgetSyncCursor);
  }
  if (widgetDerivedSubtreeCursor() != nullptr) {
    _bb.writeVarUint(275);
    if (!_data_widgetDerivedSubtreeCursor->encode(_bb)) return false;
  }
  if (widgetCachedAncestor() != nullptr) {
    _bb.writeVarUint(276);
    if (!_data_widgetCachedAncestor->encode(_bb)) return false;
  }
  if (widgetInputBehavior() != nullptr) {
    _bb.writeVarUint(285);
    _bb.writeVarUint(static_cast<uint32_t>(_data_widgetInputBehavior));
  }
  if (widgetTooltip() != nullptr) {
    _bb.writeVarUint(286);
    _bb.writeString(_data_widgetTooltip.c_str());
  }
  if (widgetHoverStyle() != nullptr) {
    _bb.writeVarUint(291);
    if (!_data_widgetHoverStyle->encode(_bb)) return false;
  }
  if (isWidgetStickable() != nullptr) {
    _bb.writeVarUint(293);
    _bb.writeByte(_data_isWidgetStickable);
  }
  if (shouldHideCursorsOnWidgetHover() != nullptr) {
    _bb.writeVarUint(360);
    _bb.writeByte(_data_shouldHideCursorsOnWidgetHover);
  }
  if (widgetMetadata() != nullptr) {
    _bb.writeVarUint(262);
    if (!_data_widgetMetadata->encode(_bb)) return false;
  }
  if (widgetEvents() != nullptr) {
    _bb.writeVarUint(263);
    _bb.writeVarUint(_data_widgetEvents.size());
    for (WidgetEvent &_it : _data_widgetEvents) _bb.writeVarUint(static_cast<uint32_t>(_it));
  }
  if (widgetPropertyMenuItems() != nullptr) {
    _bb.writeVarUint(265);
    _bb.writeVarUint(_data_widgetPropertyMenuItems.size());
    for (WidgetPropertyMenuItem &_it : _data_widgetPropertyMenuItems) if (!_it.encode(_bb)) return false;
  }
  if (tableRowPositions() != nullptr) {
    _bb.writeVarUint(308);
    if (!_data_tableRowPositions->encode(_bb)) return false;
  }
  if (tableColumnPositions() != nullptr) {
    _bb.writeVarUint(309);
    if (!_data_tableColumnPositions->encode(_bb)) return false;
  }
  if (tableRowHeights() != nullptr) {
    _bb.writeVarUint(310);
    if (!_data_tableRowHeights->encode(_bb)) return false;
  }
  if (tableColumnWidths() != nullptr) {
    _bb.writeVarUint(311);
    if (!_data_tableColumnWidths->encode(_bb)) return false;
  }
  if (internalEnumForTest() != nullptr) {
    _bb.writeVarUint(251);
    _bb.writeVarUint(static_cast<uint32_t>(_data_internalEnumForTest));
  }
  if (internalDataForTest() != nullptr) {
    _bb.writeVarUint(257);
    if (!_data_internalDataForTest->encode(_bb)) return false;
  }
  if (count() != nullptr) {
    _bb.writeVarUint(10);
    _bb.writeVarUint(_data_count);
  }
  if (countTag() != nullptr) {
    _bb.writeVarUint(62);
    _bb.writeVarUint(_data_countTag);
  }
  if (autoRename() != nullptr) {
    _bb.writeVarUint(14);
    _bb.writeByte(_data_autoRename);
  }
  if (autoRenameTag() != nullptr) {
    _bb.writeVarUint(66);
    _bb.writeVarUint(_data_autoRenameTag);
  }
  if (backgroundEnabled() != nullptr) {
    _bb.writeVarUint(15);
    _bb.writeByte(_data_backgroundEnabled);
  }
  if (backgroundEnabledTag() != nullptr) {
    _bb.writeVarUint(67);
    _bb.writeVarUint(_data_backgroundEnabledTag);
  }
  if (exportContentsOnly() != nullptr) {
    _bb.writeVarUint(17);
    _bb.writeByte(_data_exportContentsOnly);
  }
  if (exportContentsOnlyTag() != nullptr) {
    _bb.writeVarUint(69);
    _bb.writeVarUint(_data_exportContentsOnlyTag);
  }
  if (starInnerScale() != nullptr) {
    _bb.writeVarUint(24);
    _bb.writeVarFloat(_data_starInnerScale);
  }
  if (starInnerScaleTag() != nullptr) {
    _bb.writeVarUint(76);
    _bb.writeVarUint(_data_starInnerScaleTag);
  }
  if (miterLimit() != nullptr) {
    _bb.writeVarUint(25);
    _bb.writeVarFloat(_data_miterLimit);
  }
  if (miterLimitTag() != nullptr) {
    _bb.writeVarUint(77);
    _bb.writeVarUint(_data_miterLimitTag);
  }
  if (textTracking() != nullptr) {
    _bb.writeVarUint(27);
    _bb.writeVarFloat(_data_textTracking);
  }
  if (textTrackingTag() != nullptr) {
    _bb.writeVarUint(79);
    _bb.writeVarUint(_data_textTrackingTag);
  }
  if (booleanOperation() != nullptr) {
    _bb.writeVarUint(36);
    _bb.writeVarUint(static_cast<uint32_t>(_data_booleanOperation));
  }
  if (booleanOperationTag() != nullptr) {
    _bb.writeVarUint(88);
    _bb.writeVarUint(_data_booleanOperationTag);
  }
  if (verticalConstraint() != nullptr) {
    _bb.writeVarUint(37);
    _bb.writeVarUint(static_cast<uint32_t>(_data_verticalConstraint));
  }
  if (verticalConstraintTag() != nullptr) {
    _bb.writeVarUint(89);
    _bb.writeVarUint(_data_verticalConstraintTag);
  }
  if (handleMirroring() != nullptr) {
    _bb.writeVarUint(44);
    _bb.writeVarUint(static_cast<uint32_t>(_data_handleMirroring));
  }
  if (handleMirroringTag() != nullptr) {
    _bb.writeVarUint(96);
    _bb.writeVarUint(_data_handleMirroringTag);
  }
  if (exportSettings() != nullptr) {
    _bb.writeVarUint(45);
    _bb.writeVarUint(_data_exportSettings.size());
    for (ExportSettings &_it : _data_exportSettings) if (!_it.encode(_bb)) return false;
  }
  if (exportSettingsTag() != nullptr) {
    _bb.writeVarUint(97);
    _bb.writeVarUint(_data_exportSettingsTag);
  }
  if (textAutoResize() != nullptr) {
    _bb.writeVarUint(46);
    _bb.writeVarUint(static_cast<uint32_t>(_data_textAutoResize));
  }
  if (textAutoResizeTag() != nullptr) {
    _bb.writeVarUint(98);
    _bb.writeVarUint(_data_textAutoResizeTag);
  }
  if (layoutGrids() != nullptr) {
    _bb.writeVarUint(47);
    _bb.writeVarUint(_data_layoutGrids.size());
    for (LayoutGrid &_it : _data_layoutGrids) if (!_it.encode(_bb)) return false;
  }
  if (layoutGridsTag() != nullptr) {
    _bb.writeVarUint(99);
    _bb.writeVarUint(_data_layoutGridsTag);
  }
  if (vectorData() != nullptr) {
    _bb.writeVarUint(48);
    if (!_data_vectorData->encode(_bb)) return false;
  }
  if (vectorDataTag() != nullptr) {
    _bb.writeVarUint(100);
    _bb.writeVarUint(_data_vectorDataTag);
  }
  if (frameMaskDisabled() != nullptr) {
    _bb.writeVarUint(115);
    _bb.writeByte(_data_frameMaskDisabled);
  }
  if (frameMaskDisabledTag() != nullptr) {
    _bb.writeVarUint(116);
    _bb.writeVarUint(_data_frameMaskDisabledTag);
  }
  if (resizeToFit() != nullptr) {
    _bb.writeVarUint(117);
    _bb.writeByte(_data_resizeToFit);
  }
  if (resizeToFitTag() != nullptr) {
    _bb.writeVarUint(118);
    _bb.writeVarUint(_data_resizeToFitTag);
  }
  if (exportBackgroundDisabled() != nullptr) {
    _bb.writeVarUint(119);
    _bb.writeByte(_data_exportBackgroundDisabled);
  }
  if (guides() != nullptr) {
    _bb.writeVarUint(138);
    _bb.writeVarUint(_data_guides.size());
    for (Guide &_it : _data_guides) if (!_it.encode(_bb)) return false;
  }
  if (internalOnly() != nullptr) {
    _bb.writeVarUint(142);
    _bb.writeByte(_data_internalOnly);
  }
  if (scrollDirection() != nullptr) {
    _bb.writeVarUint(159);
    _bb.writeVarUint(static_cast<uint32_t>(_data_scrollDirection));
  }
  if (cornerSmoothing() != nullptr) {
    _bb.writeVarUint(160);
    _bb.writeVarFloat(_data_cornerSmoothing);
  }
  if (scrollOffset() != nullptr) {
    _bb.writeVarUint(166);
    if (!_data_scrollOffset->encode(_bb)) return false;
  }
  if (exportTextAsSVGText() != nullptr) {
    _bb.writeVarUint(175);
    _bb.writeByte(_data_exportTextAsSVGText);
  }
  if (scrollContractedState() != nullptr) {
    _bb.writeVarUint(178);
    _bb.writeVarUint(static_cast<uint32_t>(_data_scrollContractedState));
  }
  if (contractedSize() != nullptr) {
    _bb.writeVarUint(179);
    if (!_data_contractedSize->encode(_bb)) return false;
  }
  if (fixedChildrenDivider() != nullptr) {
    _bb.writeVarUint(180);
    _bb.writeString(_data_fixedChildrenDivider.c_str());
  }
  if (scrollBehavior() != nullptr) {
    _bb.writeVarUint(186);
    _bb.writeVarUint(static_cast<uint32_t>(_data_scrollBehavior));
  }
  if (arcData() != nullptr) {
    _bb.writeVarUint(195);
    if (!_data_arcData->encode(_bb)) return false;
  }
  if (derivedSymbolDataLayoutVersion() != nullptr) {
    _bb.writeVarUint(196);
    _bb.writeVarInt(_data_derivedSymbolDataLayoutVersion);
  }
  if (navigationType() != nullptr) {
    _bb.writeVarUint(197);
    _bb.writeVarUint(static_cast<uint32_t>(_data_navigationType));
  }
  if (overlayPositionType() != nullptr) {
    _bb.writeVarUint(198);
    _bb.writeVarUint(static_cast<uint32_t>(_data_overlayPositionType));
  }
  if (overlayRelativePosition() != nullptr) {
    _bb.writeVarUint(199);
    if (!_data_overlayRelativePosition->encode(_bb)) return false;
  }
  if (overlayBackgroundInteraction() != nullptr) {
    _bb.writeVarUint(200);
    _bb.writeVarUint(static_cast<uint32_t>(_data_overlayBackgroundInteraction));
  }
  if (overlayBackgroundAppearance() != nullptr) {
    _bb.writeVarUint(201);
    if (!_data_overlayBackgroundAppearance->encode(_bb)) return false;
  }
  if (overrideKey() != nullptr) {
    _bb.writeVarUint(213);
    if (!_data_overrideKey->encode(_bb)) return false;
  }
  if (containerSupportsFillStrokeAndCorners() != nullptr) {
    _bb.writeVarUint(220);
    _bb.writeByte(_data_containerSupportsFillStrokeAndCorners);
  }
  if (stackCounterSizing() != nullptr) {
    _bb.writeVarUint(221);
    _bb.writeVarUint(static_cast<uint32_t>(_data_stackCounterSizing));
  }
  if (containersSupportFillStrokeAndCorners() != nullptr) {
    _bb.writeVarUint(222);
    _bb.writeByte(_data_containersSupportFillStrokeAndCorners);
  }
  if (keyTrigger() != nullptr) {
    _bb.writeVarUint(224);
    if (!_data_keyTrigger->encode(_bb)) return false;
  }
  if (voiceEventPhrase() != nullptr) {
    _bb.writeVarUint(227);
    _bb.writeString(_data_voiceEventPhrase.c_str());
  }
  if (ancestorPathBeforeDeletion() != nullptr) {
    _bb.writeVarUint(235);
    _bb.writeVarUint(_data_ancestorPathBeforeDeletion.size());
    for (GUID &_it : _data_ancestorPathBeforeDeletion) if (!_it.encode(_bb)) return false;
  }
  if (symbolLinks() != nullptr) {
    _bb.writeVarUint(237);
    _bb.writeVarUint(_data_symbolLinks.size());
    for (SymbolLink &_it : _data_symbolLinks) if (!_it.encode(_bb)) return false;
  }
  if (textListData() != nullptr) {
    _bb.writeVarUint(239);
    if (!_data_textListData->encode(_bb)) return false;
  }
  if (detachOpticalSizeFromFontSize() != nullptr) {
    _bb.writeVarUint(261);
    _bb.writeByte(_data_detachOpticalSizeFromFontSize);
  }
  if (listSpacing() != nullptr) {
    _bb.writeVarUint(264);
    _bb.writeVarFloat(_data_listSpacing);
  }
  if (embedData() != nullptr) {
    _bb.writeVarUint(270);
    if (!_data_embedData->encode(_bb)) return false;
  }
  if (richMediaData() != nullptr) {
    _bb.writeVarUint(272);
    if (!_data_richMediaData->encode(_bb)) return false;
  }
  if (renderedSyncedState() != nullptr) {
    _bb.writeVarUint(277);
    if (!_data_renderedSyncedState->encode(_bb)) return false;
  }
  if (simplifyInstancePanels() != nullptr) {
    _bb.writeVarUint(284);
    _bb.writeByte(_data_simplifyInstancePanels);
  }
  if (accessibleHTMLTag() != nullptr) {
    _bb.writeVarUint(302);
    _bb.writeVarUint(static_cast<uint32_t>(_data_accessibleHTMLTag));
  }
  if (ariaRole() != nullptr) {
    _bb.writeVarUint(303);
    _bb.writeVarUint(static_cast<uint32_t>(_data_ariaRole));
  }
  if (accessibleLabel() != nullptr) {
    _bb.writeVarUint(304);
    _bb.writeString(_data_accessibleLabel.c_str());
  }
  if (variableData() != nullptr) {
    _bb.writeVarUint(306);
    if (!_data_variableData->encode(_bb)) return false;
  }
  if (variableConsumptionMap() != nullptr) {
    _bb.writeVarUint(307);
    if (!_data_variableConsumptionMap->encode(_bb)) return false;
  }
  if (variableModeBySetMap() != nullptr) {
    _bb.writeVarUint(316);
    if (!_data_variableModeBySetMap->encode(_bb)) return false;
  }
  if (variableSetModes() != nullptr) {
    _bb.writeVarUint(312);
    _bb.writeVarUint(_data_variableSetModes.size());
    for (VariableSetMode &_it : _data_variableSetModes) if (!_it.encode(_bb)) return false;
  }
  if (variableSetID() != nullptr) {
    _bb.writeVarUint(313);
    if (!_data_variableSetID->encode(_bb)) return false;
  }
  if (variableResolvedType() != nullptr) {
    _bb.writeVarUint(314);
    _bb.writeVarUint(static_cast<uint32_t>(_data_variableResolvedType));
  }
  if (variableDataValues() != nullptr) {
    _bb.writeVarUint(315);
    if (!_data_variableDataValues->encode(_bb)) return false;
  }
  if (variableTokenName() != nullptr) {
    _bb.writeVarUint(350);
    _bb.writeString(_data_variableTokenName.c_str());
  }
  if (variableScopes() != nullptr) {
    _bb.writeVarUint(353);
    _bb.writeVarUint(_data_variableScopes.size());
    for (VariableScope &_it : _data_variableScopes) _bb.writeVarUint(static_cast<uint32_t>(_it));
  }
  if (codeSyntax() != nullptr) {
    _bb.writeVarUint(358);
    if (!_data_codeSyntax->encode(_bb)) return false;
  }
  if (handoffStatusMap() != nullptr) {
    _bb.writeVarUint(361);
    if (!_data_handoffStatusMap->encode(_bb)) return false;
  }
  if (agendaPositionMap() != nullptr) {
    _bb.writeVarUint(327);
    if (!_data_agendaPositionMap->encode(_bb)) return false;
  }
  if (agendaMetadataMap() != nullptr) {
    _bb.writeVarUint(328);
    if (!_data_agendaMetadataMap->encode(_bb)) return false;
  }
  if (migrationStatus() != nullptr) {
    _bb.writeVarUint(329);
    if (!_data_migrationStatus->encode(_bb)) return false;
  }
  if (isSoftDeleted() != nullptr) {
    _bb.writeVarUint(330);
    _bb.writeByte(_data_isSoftDeleted);
  }
  if (editInfo() != nullptr) {
    _bb.writeVarUint(331);
    if (!_data_editInfo->encode(_bb)) return false;
  }
  if (colorProfile() != nullptr) {
    _bb.writeVarUint(341);
    _bb.writeVarUint(static_cast<uint32_t>(_data_colorProfile));
  }
  if (detachedSymbolId() != nullptr) {
    _bb.writeVarUint(342);
    if (!_data_detachedSymbolId->encode(_bb)) return false;
  }
  if (childReadingDirection() != nullptr) {
    _bb.writeVarUint(346);
    _bb.writeVarUint(static_cast<uint32_t>(_data_childReadingDirection));
  }
  if (readingIndex() != nullptr) {
    _bb.writeVarUint(347);
    _bb.writeString(_data_readingIndex.c_str());
  }
  if (documentColorProfile() != nullptr) {
    _bb.writeVarUint(349);
    _bb.writeVarUint(static_cast<uint32_t>(_data_documentColorProfile));
  }
  if (developerRelatedLinks() != nullptr) {
    _bb.writeVarUint(354);
    _bb.writeVarUint(_data_developerRelatedLinks.size());
    for (DeveloperRelatedLink &_it : _data_developerRelatedLinks) if (!_it.encode(_bb)) return false;
  }
  if (slideActiveThemeLibKey() != nullptr) {
    _bb.writeVarUint(356);
    _bb.writeString(_data_slideActiveThemeLibKey.c_str());
  }
  if (ariaAttributes() != nullptr) {
    _bb.writeVarUint(357);
    if (!_data_ariaAttributes->encode(_bb)) return false;
  }
  _bb.writeVarUint(0);
  return true;
}

bool NodeChange::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  uint32_t _count;
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        _data_guid = _pool.allocate<GUID>();
        if (!_data_guid->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 53: {
        if (!_bb.readVarUint(_data_guidTag)) return false;
        set_guidTag(_data_guidTag);
        break;
      }
      case 2: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_phase))) return false;
        set_phase(_data_phase);
        break;
      }
      case 54: {
        if (!_bb.readVarUint(_data_phaseTag)) return false;
        set_phaseTag(_data_phaseTag);
        break;
      }
      case 3: {
        _data_parentIndex = _pool.allocate<ParentIndex>();
        if (!_data_parentIndex->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 55: {
        if (!_bb.readVarUint(_data_parentIndexTag)) return false;
        set_parentIndexTag(_data_parentIndexTag);
        break;
      }
      case 4: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_type))) return false;
        set_type(_data_type);
        break;
      }
      case 56: {
        if (!_bb.readVarUint(_data_typeTag)) return false;
        set_typeTag(_data_typeTag);
        break;
      }
      case 5: {
        if (!_bb.readString(_data_name, _pool)) return false;
        set_name(_data_name);
        break;
      }
      case 57: {
        if (!_bb.readVarUint(_data_nameTag)) return false;
        set_nameTag(_data_nameTag);
        break;
      }
      case 174: {
        if (!_bb.readByte(_data_isPublishable)) return false;
        set_isPublishable(_data_isPublishable);
        break;
      }
      case 318: {
        if (!_bb.readString(_data_description, _pool)) return false;
        set_description(_data_description);
        break;
      }
      case 256: {
        _data_libraryMoveInfo = _pool.allocate<LibraryMoveInfo>();
        if (!_data_libraryMoveInfo->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 281: {
        if (!_bb.readVarUint(_count)) return false;
        for (LibraryMoveHistoryItem &_it : set_libraryMoveHistory(_pool, _count)) if (!_it.decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 319: {
        if (!_bb.readString(_data_key, _pool)) return false;
        set_key(_data_key);
        break;
      }
      case 49: {
        if (!_bb.readVarUint(_data_styleID)) return false;
        set_styleID(_data_styleID);
        break;
      }
      case 101: {
        if (!_bb.readVarUint(_data_styleIDTag)) return false;
        set_styleIDTag(_data_styleIDTag);
        break;
      }
      case 176: {
        if (!_bb.readByte(_data_isSoftDeletedStyle)) return false;
        set_isSoftDeletedStyle(_data_isSoftDeletedStyle);
        break;
      }
      case 177: {
        if (!_bb.readByte(_data_isNonUpdateable)) return false;
        set_isNonUpdateable(_data_isNonUpdateable);
        break;
      }
      case 157: {
        if (!_bb.readByte(_data_isFillStyle)) return false;
        set_isFillStyle(_data_isFillStyle);
        break;
      }
      case 161: {
        if (!_bb.readByte(_data_isStrokeStyle)) return false;
        set_isStrokeStyle(_data_isStrokeStyle);
        break;
      }
      case 163: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_styleType))) return false;
        set_styleType(_data_styleType);
        break;
      }
      case 191: {
        if (!_bb.readString(_data_styleDescription, _pool)) return false;
        set_styleDescription(_data_styleDescription);
        break;
      }
      case 171: {
        if (!_bb.readString(_data_version, _pool)) return false;
        set_version(_data_version);
        break;
      }
      case 172: {
        _data_sharedStyleMasterData = _pool.allocate<SharedStyleMasterData>();
        if (!_data_sharedStyleMasterData->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 173: {
        _data_sharedStyleReference = _pool.allocate<SharedStyleReference>();
        if (!_data_sharedStyleReference->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 320: {
        if (!_bb.readString(_data_sortPosition, _pool)) return false;
        set_sortPosition(_data_sortPosition);
        break;
      }
      case 345: {
        _data_ojansSuperSecretNodeField = _pool.allocate<SharedStyleMasterData>();
        if (!_data_ojansSuperSecretNodeField->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 348: {
        _data_sevMoonlitLilyData = _pool.allocate<SharedStyleMasterData>();
        if (!_data_sevMoonlitLilyData->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 158: {
        _data_inheritFillStyleID = _pool.allocate<GUID>();
        if (!_data_inheritFillStyleID->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 162: {
        _data_inheritStrokeStyleID = _pool.allocate<GUID>();
        if (!_data_inheritStrokeStyleID->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 167: {
        _data_inheritTextStyleID = _pool.allocate<GUID>();
        if (!_data_inheritTextStyleID->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 168: {
        _data_inheritExportStyleID = _pool.allocate<GUID>();
        if (!_data_inheritExportStyleID->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 169: {
        _data_inheritEffectStyleID = _pool.allocate<GUID>();
        if (!_data_inheritEffectStyleID->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 170: {
        _data_inheritGridStyleID = _pool.allocate<GUID>();
        if (!_data_inheritGridStyleID->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 185: {
        _data_inheritFillStyleIDForStroke = _pool.allocate<GUID>();
        if (!_data_inheritFillStyleIDForStroke->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 332: {
        _data_styleIdForFill = _pool.allocate<StyleId>();
        if (!_data_styleIdForFill->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 333: {
        _data_styleIdForStrokeFill = _pool.allocate<StyleId>();
        if (!_data_styleIdForStrokeFill->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 334: {
        _data_styleIdForText = _pool.allocate<StyleId>();
        if (!_data_styleIdForText->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 335: {
        _data_styleIdForEffect = _pool.allocate<StyleId>();
        if (!_data_styleIdForEffect->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 336: {
        _data_styleIdForGrid = _pool.allocate<StyleId>();
        if (!_data_styleIdForGrid->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 193: {
        if (!_bb.readVarUint(_count)) return false;
        for (Paint &_it : set_backgroundPaints(_pool, _count)) if (!_it.decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 194: {
        _data_inheritFillStyleIDForBackground = _pool.allocate<GUID>();
        if (!_data_inheritFillStyleIDForBackground->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 225: {
        if (!_bb.readByte(_data_isStateGroup)) return false;
        set_isStateGroup(_data_isStateGroup);
        break;
      }
      case 238: {
        if (!_bb.readVarUint(_count)) return false;
        for (StateGroupPropertyValueOrder &_it : set_stateGroupPropertyValueOrders(_pool, _count)) if (!_it.decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 122: {
        _data_sharedSymbolReference = _pool.allocate<SharedSymbolReference>();
        if (!_data_sharedSymbolReference->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 123: {
        if (!_bb.readByte(_data_isSymbolPublishable)) return false;
        set_isSymbolPublishable(_data_isSymbolPublishable);
        break;
      }
      case 124: {
        if (!_bb.readVarUint(_count)) return false;
        for (GUIDPathMapping &_it : set_sharedSymbolMappings(_pool, _count)) if (!_it.decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 126: {
        if (!_bb.readString(_data_sharedSymbolVersion, _pool)) return false;
        set_sharedSymbolVersion(_data_sharedSymbolVersion);
        break;
      }
      case 152: {
        _data_sharedComponentMasterData = _pool.allocate<SharedComponentMasterData>();
        if (!_data_sharedComponentMasterData->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 144: {
        if (!_bb.readString(_data_symbolDescription, _pool)) return false;
        set_symbolDescription(_data_symbolDescription);
        break;
      }
      case 164: {
        if (!_bb.readVarUint(_count)) return false;
        for (GUIDPathMapping &_it : set_unflatteningMappings(_pool, _count)) if (!_it.decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 228: {
        if (!_bb.readVarUint(_count)) return false;
        for (GUIDPathMapping &_it : set_forceUnflatteningMappings(_pool, _count)) if (!_it.decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 214: {
        if (!_bb.readString(_data_publishFile, _pool)) return false;
        set_publishFile(_data_publishFile);
        break;
      }
      case 215: {
        _data_publishID = _pool.allocate<GUID>();
        if (!_data_publishID->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 216: {
        if (!_bb.readString(_data_componentKey, _pool)) return false;
        set_componentKey(_data_componentKey);
        break;
      }
      case 217: {
        if (!_bb.readByte(_data_isC2)) return false;
        set_isC2(_data_isC2);
        break;
      }
      case 218: {
        if (!_bb.readString(_data_publishedVersion, _pool)) return false;
        set_publishedVersion(_data_publishedVersion);
        break;
      }
      case 252: {
        if (!_bb.readString(_data_originComponentKey, _pool)) return false;
        set_originComponentKey(_data_originComponentKey);
        break;
      }
      case 266: {
        if (!_bb.readVarUint(_count)) return false;
        for (ComponentPropDef &_it : set_componentPropDefs(_pool, _count)) if (!_it.decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 267: {
        if (!_bb.readVarUint(_count)) return false;
        for (ComponentPropRef &_it : set_componentPropRefs(_pool, _count)) if (!_it.decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 113: {
        _data_symbolData = _pool.allocate<SymbolData>();
        if (!_data_symbolData->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 114: {
        if (!_bb.readVarUint(_data_symbolDataTag)) return false;
        set_symbolDataTag(_data_symbolDataTag);
        break;
      }
      case 125: {
        if (!_bb.readVarUint(_count)) return false;
        for (NodeChange &_it : set_derivedSymbolData(_pool, _count)) if (!_it.decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 143: {
        _data_overriddenSymbolID = _pool.allocate<GUID>();
        if (!_data_overriddenSymbolID->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 268: {
        if (!_bb.readVarUint(_count)) return false;
        for (ComponentPropAssignment &_it : set_componentPropAssignments(_pool, _count)) if (!_it.decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 305: {
        if (!_bb.readByte(_data_propsAreBubbled)) return false;
        set_propsAreBubbled(_data_propsAreBubbled);
        break;
      }
      case 248: {
        if (!_bb.readVarUint(_count)) return false;
        for (InstanceOverrideStash &_it : set_overrideStash(_pool, _count)) if (!_it.decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 250: {
        if (!_bb.readVarUint(_count)) return false;
        for (InstanceOverrideStashV2 &_it : set_overrideStashV2(_pool, _count)) if (!_it.decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 111: {
        _data_guidPath = _pool.allocate<GUIDPath>();
        if (!_data_guidPath->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 112: {
        if (!_bb.readVarUint(_data_guidPathTag)) return false;
        set_guidPathTag(_data_guidPathTag);
        break;
      }
      case 321: {
        if (!_bb.readVarInt(_data_overrideLevel)) return false;
        set_overrideLevel(_data_overrideLevel);
        break;
      }
      case 21: {
        if (!_bb.readVarFloat(_data_fontSize)) return false;
        set_fontSize(_data_fontSize);
        break;
      }
      case 73: {
        if (!_bb.readVarUint(_data_fontSizeTag)) return false;
        set_fontSizeTag(_data_fontSizeTag);
        break;
      }
      case 22: {
        if (!_bb.readVarFloat(_data_paragraphIndent)) return false;
        set_paragraphIndent(_data_paragraphIndent);
        break;
      }
      case 74: {
        if (!_bb.readVarUint(_data_paragraphIndentTag)) return false;
        set_paragraphIndentTag(_data_paragraphIndentTag);
        break;
      }
      case 23: {
        if (!_bb.readVarFloat(_data_paragraphSpacing)) return false;
        set_paragraphSpacing(_data_paragraphSpacing);
        break;
      }
      case 75: {
        if (!_bb.readVarUint(_data_paragraphSpacingTag)) return false;
        set_paragraphSpacingTag(_data_paragraphSpacingTag);
        break;
      }
      case 32: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_textAlignHorizontal))) return false;
        set_textAlignHorizontal(_data_textAlignHorizontal);
        break;
      }
      case 84: {
        if (!_bb.readVarUint(_data_textAlignHorizontalTag)) return false;
        set_textAlignHorizontalTag(_data_textAlignHorizontalTag);
        break;
      }
      case 33: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_textAlignVertical))) return false;
        set_textAlignVertical(_data_textAlignVertical);
        break;
      }
      case 85: {
        if (!_bb.readVarUint(_data_textAlignVerticalTag)) return false;
        set_textAlignVerticalTag(_data_textAlignVerticalTag);
        break;
      }
      case 34: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_textCase))) return false;
        set_textCase(_data_textCase);
        break;
      }
      case 86: {
        if (!_bb.readVarUint(_data_textCaseTag)) return false;
        set_textCaseTag(_data_textCaseTag);
        break;
      }
      case 35: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_textDecoration))) return false;
        set_textDecoration(_data_textDecoration);
        break;
      }
      case 87: {
        if (!_bb.readVarUint(_data_textDecorationTag)) return false;
        set_textDecorationTag(_data_textDecorationTag);
        break;
      }
      case 40: {
        _data_lineHeight = _pool.allocate<Number>();
        if (!_data_lineHeight->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 92: {
        if (!_bb.readVarUint(_data_lineHeightTag)) return false;
        set_lineHeightTag(_data_lineHeightTag);
        break;
      }
      case 41: {
        _data_fontName = _pool.allocate<FontName>();
        if (!_data_fontName->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 93: {
        if (!_bb.readVarUint(_data_fontNameTag)) return false;
        set_fontNameTag(_data_fontNameTag);
        break;
      }
      case 42: {
        _data_textData = _pool.allocate<TextData>();
        if (!_data_textData->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 94: {
        if (!_bb.readVarUint(_data_textDataTag)) return false;
        set_textDataTag(_data_textDataTag);
        break;
      }
      case 359: {
        _data_derivedTextData = _pool.allocate<DerivedTextData>();
        if (!_data_derivedTextData->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 127: {
        if (!_bb.readByte(_data_fontVariantCommonLigatures)) return false;
        set_fontVariantCommonLigatures(_data_fontVariantCommonLigatures);
        break;
      }
      case 128: {
        if (!_bb.readByte(_data_fontVariantContextualLigatures)) return false;
        set_fontVariantContextualLigatures(_data_fontVariantContextualLigatures);
        break;
      }
      case 129: {
        if (!_bb.readByte(_data_fontVariantDiscretionaryLigatures)) return false;
        set_fontVariantDiscretionaryLigatures(_data_fontVariantDiscretionaryLigatures);
        break;
      }
      case 130: {
        if (!_bb.readByte(_data_fontVariantHistoricalLigatures)) return false;
        set_fontVariantHistoricalLigatures(_data_fontVariantHistoricalLigatures);
        break;
      }
      case 131: {
        if (!_bb.readByte(_data_fontVariantOrdinal)) return false;
        set_fontVariantOrdinal(_data_fontVariantOrdinal);
        break;
      }
      case 132: {
        if (!_bb.readByte(_data_fontVariantSlashedZero)) return false;
        set_fontVariantSlashedZero(_data_fontVariantSlashedZero);
        break;
      }
      case 133: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_fontVariantNumericFigure))) return false;
        set_fontVariantNumericFigure(_data_fontVariantNumericFigure);
        break;
      }
      case 134: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_fontVariantNumericSpacing))) return false;
        set_fontVariantNumericSpacing(_data_fontVariantNumericSpacing);
        break;
      }
      case 135: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_fontVariantNumericFraction))) return false;
        set_fontVariantNumericFraction(_data_fontVariantNumericFraction);
        break;
      }
      case 136: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_fontVariantCaps))) return false;
        set_fontVariantCaps(_data_fontVariantCaps);
        break;
      }
      case 137: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_fontVariantPosition))) return false;
        set_fontVariantPosition(_data_fontVariantPosition);
        break;
      }
      case 165: {
        _data_letterSpacing = _pool.allocate<Number>();
        if (!_data_letterSpacing->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 202: {
        if (!_bb.readString(_data_fontVersion, _pool)) return false;
        set_fontVersion(_data_fontVersion);
        break;
      }
      case 322: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_leadingTrim))) return false;
        set_leadingTrim(_data_leadingTrim);
        break;
      }
      case 337: {
        if (!_bb.readByte(_data_hangingPunctuation)) return false;
        set_hangingPunctuation(_data_hangingPunctuation);
        break;
      }
      case 339: {
        if (!_bb.readByte(_data_hangingList)) return false;
        set_hangingList(_data_hangingList);
        break;
      }
      case 351: {
        if (!_bb.readVarInt(_data_maxLines)) return false;
        set_maxLines(_data_maxLines);
        break;
      }
      case 352: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_sectionStatus))) return false;
        set_sectionStatus(_data_sectionStatus);
        break;
      }
      case 355: {
        _data_sectionStatusInfo = _pool.allocate<SectionStatusInfo>();
        if (!_data_sectionStatusInfo->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 203: {
        if (!_bb.readVarUint(_data_textUserLayoutVersion)) return false;
        set_textUserLayoutVersion(_data_textUserLayoutVersion);
        break;
      }
      case 205: {
        if (!_bb.readVarUint(_count)) return false;
        for (OpenTypeFeature &_it : set_toggledOnOTFeatures(_pool, _count)) if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_it))) return false;
        break;
      }
      case 206: {
        if (!_bb.readVarUint(_count)) return false;
        for (OpenTypeFeature &_it : set_toggledOffOTFeatures(_pool, _count)) if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_it))) return false;
        break;
      }
      case 223: {
        _data_hyperlink = _pool.allocate<Hyperlink>();
        if (!_data_hyperlink->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 340: {
        _data_mention = _pool.allocate<Mention>();
        if (!_data_mention->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 260: {
        if (!_bb.readVarUint(_count)) return false;
        for (FontVariation &_it : set_fontVariations(_pool, _count)) if (!_it.decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 279: {
        if (!_bb.readVarUint(_data_textBidiVersion)) return false;
        set_textBidiVersion(_data_textBidiVersion);
        break;
      }
      case 280: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_textTruncation))) return false;
        set_textTruncation(_data_textTruncation);
        break;
      }
      case 292: {
        if (!_bb.readByte(_data_hasHadRTLText)) return false;
        set_hasHadRTLText(_data_hasHadRTLText);
        break;
      }
      case 6: {
        if (!_bb.readByte(_data_visible)) return false;
        set_visible(_data_visible);
        break;
      }
      case 58: {
        if (!_bb.readVarUint(_data_visibleTag)) return false;
        set_visibleTag(_data_visibleTag);
        break;
      }
      case 7: {
        if (!_bb.readByte(_data_locked)) return false;
        set_locked(_data_locked);
        break;
      }
      case 59: {
        if (!_bb.readVarUint(_data_lockedTag)) return false;
        set_lockedTag(_data_lockedTag);
        break;
      }
      case 8: {
        if (!_bb.readVarFloat(_data_opacity)) return false;
        set_opacity(_data_opacity);
        break;
      }
      case 60: {
        if (!_bb.readVarUint(_data_opacityTag)) return false;
        set_opacityTag(_data_opacityTag);
        break;
      }
      case 9: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_blendMode))) return false;
        set_blendMode(_data_blendMode);
        break;
      }
      case 61: {
        if (!_bb.readVarUint(_data_blendModeTag)) return false;
        set_blendModeTag(_data_blendModeTag);
        break;
      }
      case 11: {
        _data_size = _pool.allocate<Vector>();
        if (!_data_size->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 63: {
        if (!_bb.readVarUint(_data_sizeTag)) return false;
        set_sizeTag(_data_sizeTag);
        break;
      }
      case 12: {
        _data_transform = _pool.allocate<Matrix>();
        if (!_data_transform->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 64: {
        if (!_bb.readVarUint(_data_transformTag)) return false;
        set_transformTag(_data_transformTag);
        break;
      }
      case 13: {
        if (!_bb.readVarUint(_count)) return false;
        for (float &_it : set_dashPattern(_pool, _count)) if (!_bb.readVarFloat(_it)) return false;
        break;
      }
      case 65: {
        if (!_bb.readVarUint(_data_dashPatternTag)) return false;
        set_dashPatternTag(_data_dashPatternTag);
        break;
      }
      case 16: {
        if (!_bb.readByte(_data_mask)) return false;
        set_mask(_data_mask);
        break;
      }
      case 68: {
        if (!_bb.readVarUint(_data_maskTag)) return false;
        set_maskTag(_data_maskTag);
        break;
      }
      case 18: {
        if (!_bb.readByte(_data_maskIsOutline)) return false;
        set_maskIsOutline(_data_maskIsOutline);
        break;
      }
      case 70: {
        if (!_bb.readVarUint(_data_maskIsOutlineTag)) return false;
        set_maskIsOutlineTag(_data_maskIsOutlineTag);
        break;
      }
      case 317: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_maskType))) return false;
        set_maskType(_data_maskType);
        break;
      }
      case 19: {
        if (!_bb.readVarFloat(_data_backgroundOpacity)) return false;
        set_backgroundOpacity(_data_backgroundOpacity);
        break;
      }
      case 71: {
        if (!_bb.readVarUint(_data_backgroundOpacityTag)) return false;
        set_backgroundOpacityTag(_data_backgroundOpacityTag);
        break;
      }
      case 20: {
        if (!_bb.readVarFloat(_data_cornerRadius)) return false;
        set_cornerRadius(_data_cornerRadius);
        break;
      }
      case 72: {
        if (!_bb.readVarUint(_data_cornerRadiusTag)) return false;
        set_cornerRadiusTag(_data_cornerRadiusTag);
        break;
      }
      case 26: {
        if (!_bb.readVarFloat(_data_strokeWeight)) return false;
        set_strokeWeight(_data_strokeWeight);
        break;
      }
      case 78: {
        if (!_bb.readVarUint(_data_strokeWeightTag)) return false;
        set_strokeWeightTag(_data_strokeWeightTag);
        break;
      }
      case 29: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_strokeAlign))) return false;
        set_strokeAlign(_data_strokeAlign);
        break;
      }
      case 81: {
        if (!_bb.readVarUint(_data_strokeAlignTag)) return false;
        set_strokeAlignTag(_data_strokeAlignTag);
        break;
      }
      case 30: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_strokeCap))) return false;
        set_strokeCap(_data_strokeCap);
        break;
      }
      case 82: {
        if (!_bb.readVarUint(_data_strokeCapTag)) return false;
        set_strokeCapTag(_data_strokeCapTag);
        break;
      }
      case 31: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_strokeJoin))) return false;
        set_strokeJoin(_data_strokeJoin);
        break;
      }
      case 83: {
        if (!_bb.readVarUint(_data_strokeJoinTag)) return false;
        set_strokeJoinTag(_data_strokeJoinTag);
        break;
      }
      case 38: {
        if (!_bb.readVarUint(_count)) return false;
        for (Paint &_it : set_fillPaints(_pool, _count)) if (!_it.decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 90: {
        if (!_bb.readVarUint(_data_fillPaintsTag)) return false;
        set_fillPaintsTag(_data_fillPaintsTag);
        break;
      }
      case 39: {
        if (!_bb.readVarUint(_count)) return false;
        for (Paint &_it : set_strokePaints(_pool, _count)) if (!_it.decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 91: {
        if (!_bb.readVarUint(_data_strokePaintsTag)) return false;
        set_strokePaintsTag(_data_strokePaintsTag);
        break;
      }
      case 43: {
        if (!_bb.readVarUint(_count)) return false;
        for (Effect &_it : set_effects(_pool, _count)) if (!_it.decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 95: {
        if (!_bb.readVarUint(_data_effectsTag)) return false;
        set_effectsTag(_data_effectsTag);
        break;
      }
      case 50: {
        _data_backgroundColor = _pool.allocate<Color>();
        if (!_data_backgroundColor->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 102: {
        if (!_bb.readVarUint(_data_backgroundColorTag)) return false;
        set_backgroundColorTag(_data_backgroundColorTag);
        break;
      }
      case 51: {
        if (!_bb.readVarUint(_count)) return false;
        for (Path &_it : set_fillGeometry(_pool, _count)) if (!_it.decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 103: {
        if (!_bb.readVarUint(_data_fillGeometryTag)) return false;
        set_fillGeometryTag(_data_fillGeometryTag);
        break;
      }
      case 52: {
        if (!_bb.readVarUint(_count)) return false;
        for (Path &_it : set_strokeGeometry(_pool, _count)) if (!_it.decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 104: {
        if (!_bb.readVarUint(_data_strokeGeometryTag)) return false;
        set_strokeGeometryTag(_data_strokeGeometryTag);
        break;
      }
      case 145: {
        if (!_bb.readVarFloat(_data_rectangleTopLeftCornerRadius)) return false;
        set_rectangleTopLeftCornerRadius(_data_rectangleTopLeftCornerRadius);
        break;
      }
      case 146: {
        if (!_bb.readVarFloat(_data_rectangleTopRightCornerRadius)) return false;
        set_rectangleTopRightCornerRadius(_data_rectangleTopRightCornerRadius);
        break;
      }
      case 147: {
        if (!_bb.readVarFloat(_data_rectangleBottomLeftCornerRadius)) return false;
        set_rectangleBottomLeftCornerRadius(_data_rectangleBottomLeftCornerRadius);
        break;
      }
      case 148: {
        if (!_bb.readVarFloat(_data_rectangleBottomRightCornerRadius)) return false;
        set_rectangleBottomRightCornerRadius(_data_rectangleBottomRightCornerRadius);
        break;
      }
      case 149: {
        if (!_bb.readByte(_data_rectangleCornerRadiiIndependent)) return false;
        set_rectangleCornerRadiiIndependent(_data_rectangleCornerRadiiIndependent);
        break;
      }
      case 150: {
        if (!_bb.readByte(_data_rectangleCornerToolIndependent)) return false;
        set_rectangleCornerToolIndependent(_data_rectangleCornerToolIndependent);
        break;
      }
      case 151: {
        if (!_bb.readByte(_data_proportionsConstrained)) return false;
        set_proportionsConstrained(_data_proportionsConstrained);
        break;
      }
      case 258: {
        if (!_bb.readByte(_data_useAbsoluteBounds)) return false;
        set_useAbsoluteBounds(_data_useAbsoluteBounds);
        break;
      }
      case 287: {
        if (!_bb.readByte(_data_borderTopHidden)) return false;
        set_borderTopHidden(_data_borderTopHidden);
        break;
      }
      case 288: {
        if (!_bb.readByte(_data_borderBottomHidden)) return false;
        set_borderBottomHidden(_data_borderBottomHidden);
        break;
      }
      case 289: {
        if (!_bb.readByte(_data_borderLeftHidden)) return false;
        set_borderLeftHidden(_data_borderLeftHidden);
        break;
      }
      case 290: {
        if (!_bb.readByte(_data_borderRightHidden)) return false;
        set_borderRightHidden(_data_borderRightHidden);
        break;
      }
      case 294: {
        if (!_bb.readByte(_data_bordersTakeSpace)) return false;
        set_bordersTakeSpace(_data_bordersTakeSpace);
        break;
      }
      case 295: {
        if (!_bb.readVarFloat(_data_borderTopWeight)) return false;
        set_borderTopWeight(_data_borderTopWeight);
        break;
      }
      case 296: {
        if (!_bb.readVarFloat(_data_borderBottomWeight)) return false;
        set_borderBottomWeight(_data_borderBottomWeight);
        break;
      }
      case 297: {
        if (!_bb.readVarFloat(_data_borderLeftWeight)) return false;
        set_borderLeftWeight(_data_borderLeftWeight);
        break;
      }
      case 298: {
        if (!_bb.readVarFloat(_data_borderRightWeight)) return false;
        set_borderRightWeight(_data_borderRightWeight);
        break;
      }
      case 299: {
        if (!_bb.readByte(_data_borderStrokeWeightsIndependent)) return false;
        set_borderStrokeWeightsIndependent(_data_borderStrokeWeightsIndependent);
        break;
      }
      case 28: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_horizontalConstraint))) return false;
        set_horizontalConstraint(_data_horizontalConstraint);
        break;
      }
      case 80: {
        if (!_bb.readVarUint(_data_horizontalConstraintTag)) return false;
        set_horizontalConstraintTag(_data_horizontalConstraintTag);
        break;
      }
      case 105: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_stackMode))) return false;
        set_stackMode(_data_stackMode);
        break;
      }
      case 106: {
        if (!_bb.readVarUint(_data_stackModeTag)) return false;
        set_stackModeTag(_data_stackModeTag);
        break;
      }
      case 107: {
        if (!_bb.readVarFloat(_data_stackSpacing)) return false;
        set_stackSpacing(_data_stackSpacing);
        break;
      }
      case 108: {
        if (!_bb.readVarUint(_data_stackSpacingTag)) return false;
        set_stackSpacingTag(_data_stackSpacingTag);
        break;
      }
      case 109: {
        if (!_bb.readVarFloat(_data_stackPadding)) return false;
        set_stackPadding(_data_stackPadding);
        break;
      }
      case 110: {
        if (!_bb.readVarUint(_data_stackPaddingTag)) return false;
        set_stackPaddingTag(_data_stackPaddingTag);
        break;
      }
      case 120: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_stackCounterAlign))) return false;
        set_stackCounterAlign(_data_stackCounterAlign);
        break;
      }
      case 121: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_stackJustify))) return false;
        set_stackJustify(_data_stackJustify);
        break;
      }
      case 208: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_stackAlign))) return false;
        set_stackAlign(_data_stackAlign);
        break;
      }
      case 209: {
        if (!_bb.readVarFloat(_data_stackHorizontalPadding)) return false;
        set_stackHorizontalPadding(_data_stackHorizontalPadding);
        break;
      }
      case 210: {
        if (!_bb.readVarFloat(_data_stackVerticalPadding)) return false;
        set_stackVerticalPadding(_data_stackVerticalPadding);
        break;
      }
      case 211: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_stackWidth))) return false;
        set_stackWidth(_data_stackWidth);
        break;
      }
      case 212: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_stackHeight))) return false;
        set_stackHeight(_data_stackHeight);
        break;
      }
      case 229: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_stackPrimarySizing))) return false;
        set_stackPrimarySizing(_data_stackPrimarySizing);
        break;
      }
      case 230: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_stackPrimaryAlignItems))) return false;
        set_stackPrimaryAlignItems(_data_stackPrimaryAlignItems);
        break;
      }
      case 231: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_stackCounterAlignItems))) return false;
        set_stackCounterAlignItems(_data_stackCounterAlignItems);
        break;
      }
      case 232: {
        if (!_bb.readVarFloat(_data_stackChildPrimaryGrow)) return false;
        set_stackChildPrimaryGrow(_data_stackChildPrimaryGrow);
        break;
      }
      case 233: {
        if (!_bb.readVarFloat(_data_stackPaddingRight)) return false;
        set_stackPaddingRight(_data_stackPaddingRight);
        break;
      }
      case 234: {
        if (!_bb.readVarFloat(_data_stackPaddingBottom)) return false;
        set_stackPaddingBottom(_data_stackPaddingBottom);
        break;
      }
      case 236: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_stackChildAlignSelf))) return false;
        set_stackChildAlignSelf(_data_stackChildAlignSelf);
        break;
      }
      case 269: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_stackPositioning))) return false;
        set_stackPositioning(_data_stackPositioning);
        break;
      }
      case 271: {
        if (!_bb.readByte(_data_stackReverseZIndex)) return false;
        set_stackReverseZIndex(_data_stackReverseZIndex);
        break;
      }
      case 323: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_stackWrap))) return false;
        set_stackWrap(_data_stackWrap);
        break;
      }
      case 324: {
        if (!_bb.readVarFloat(_data_stackCounterSpacing)) return false;
        set_stackCounterSpacing(_data_stackCounterSpacing);
        break;
      }
      case 325: {
        _data_minSize = _pool.allocate<OptionalVector>();
        if (!_data_minSize->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 326: {
        _data_maxSize = _pool.allocate<OptionalVector>();
        if (!_data_maxSize->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 343: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_stackCounterAlignContent))) return false;
        set_stackCounterAlignContent(_data_stackCounterAlignContent);
        break;
      }
      case 344: {
        if (!_bb.readByte(_data_isSnakeGameBoard)) return false;
        set_isSnakeGameBoard(_data_isSnakeGameBoard);
        break;
      }
      case 139: {
        _data_transitionNodeID = _pool.allocate<GUID>();
        if (!_data_transitionNodeID->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 140: {
        _data_prototypeStartNodeID = _pool.allocate<GUID>();
        if (!_data_prototypeStartNodeID->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 141: {
        _data_prototypeBackgroundColor = _pool.allocate<Color>();
        if (!_data_prototypeBackgroundColor->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 153: {
        _data_transitionInfo = _pool.allocate<TransitionInfo>();
        if (!_data_transitionInfo->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 154: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_transitionType))) return false;
        set_transitionType(_data_transitionType);
        break;
      }
      case 155: {
        if (!_bb.readVarFloat(_data_transitionDuration)) return false;
        set_transitionDuration(_data_transitionDuration);
        break;
      }
      case 156: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_easingType))) return false;
        set_easingType(_data_easingType);
        break;
      }
      case 181: {
        if (!_bb.readByte(_data_transitionPreserveScroll)) return false;
        set_transitionPreserveScroll(_data_transitionPreserveScroll);
        break;
      }
      case 182: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_connectionType))) return false;
        set_connectionType(_data_connectionType);
        break;
      }
      case 183: {
        if (!_bb.readString(_data_connectionURL, _pool)) return false;
        set_connectionURL(_data_connectionURL);
        break;
      }
      case 184: {
        _data_prototypeDevice = _pool.allocate<PrototypeDevice>();
        if (!_data_prototypeDevice->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 187: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_interactionType))) return false;
        set_interactionType(_data_interactionType);
        break;
      }
      case 188: {
        if (!_bb.readVarFloat(_data_transitionTimeout)) return false;
        set_transitionTimeout(_data_transitionTimeout);
        break;
      }
      case 189: {
        if (!_bb.readByte(_data_interactionMaintained)) return false;
        set_interactionMaintained(_data_interactionMaintained);
        break;
      }
      case 190: {
        if (!_bb.readVarFloat(_data_interactionDuration)) return false;
        set_interactionDuration(_data_interactionDuration);
        break;
      }
      case 192: {
        if (!_bb.readByte(_data_destinationIsOverlay)) return false;
        set_destinationIsOverlay(_data_destinationIsOverlay);
        break;
      }
      case 207: {
        if (!_bb.readByte(_data_transitionShouldSmartAnimate)) return false;
        set_transitionShouldSmartAnimate(_data_transitionShouldSmartAnimate);
        break;
      }
      case 226: {
        if (!_bb.readVarUint(_count)) return false;
        for (PrototypeInteraction &_it : set_prototypeInteractions(_pool, _count)) if (!_it.decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 249: {
        _data_prototypeStartingPoint = _pool.allocate<PrototypeStartingPoint>();
        if (!_data_prototypeStartingPoint->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 204: {
        if (!_bb.readVarUint(_count)) return false;
        for (PluginData &_it : set_pluginData(_pool, _count)) if (!_it.decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 219: {
        if (!_bb.readVarUint(_count)) return false;
        for (PluginRelaunchData &_it : set_pluginRelaunchData(_pool, _count)) if (!_it.decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 242: {
        _data_connectorStart = _pool.allocate<ConnectorEndpoint>();
        if (!_data_connectorStart->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 243: {
        _data_connectorEnd = _pool.allocate<ConnectorEndpoint>();
        if (!_data_connectorEnd->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 244: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_connectorLineStyle))) return false;
        set_connectorLineStyle(_data_connectorLineStyle);
        break;
      }
      case 245: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_connectorStartCap))) return false;
        set_connectorStartCap(_data_connectorStartCap);
        break;
      }
      case 246: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_connectorEndCap))) return false;
        set_connectorEndCap(_data_connectorEndCap);
        break;
      }
      case 253: {
        if (!_bb.readVarUint(_count)) return false;
        for (ConnectorControlPoint &_it : set_connectorControlPoints(_pool, _count)) if (!_it.decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 255: {
        _data_connectorTextMidpoint = _pool.allocate<ConnectorTextMidpoint>();
        if (!_data_connectorTextMidpoint->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 241: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_shapeWithTextType))) return false;
        set_shapeWithTextType(_data_shapeWithTextType);
        break;
      }
      case 247: {
        if (!_bb.readVarFloat(_data_shapeUserHeight)) return false;
        set_shapeUserHeight(_data_shapeUserHeight);
        break;
      }
      case 254: {
        _data_derivedImmutableFrameData = _pool.allocate<DerivedImmutableFrameData>();
        if (!_data_derivedImmutableFrameData->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 338: {
        _data_derivedImmutableFrameDataVersion = _pool.allocate<MultiplayerFieldVersion>();
        if (!_data_derivedImmutableFrameDataVersion->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 240: {
        _data_nodeGenerationData = _pool.allocate<NodeGenerationData>();
        if (!_data_nodeGenerationData->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 259: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_codeBlockLanguage))) return false;
        set_codeBlockLanguage(_data_codeBlockLanguage);
        break;
      }
      case 278: {
        _data_linkPreviewData = _pool.allocate<LinkPreviewData>();
        if (!_data_linkPreviewData->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 282: {
        if (!_bb.readByte(_data_shapeTruncates)) return false;
        set_shapeTruncates(_data_shapeTruncates);
        break;
      }
      case 283: {
        if (!_bb.readByte(_data_sectionContentsHidden)) return false;
        set_sectionContentsHidden(_data_sectionContentsHidden);
        break;
      }
      case 300: {
        _data_videoPlayback = _pool.allocate<VideoPlayback>();
        if (!_data_videoPlayback->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 301: {
        _data_stampData = _pool.allocate<StampData>();
        if (!_data_stampData->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 273: {
        _data_widgetSyncedState = _pool.allocate<MultiplayerMap>();
        if (!_data_widgetSyncedState->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 274: {
        if (!_bb.readVarUint(_data_widgetSyncCursor)) return false;
        set_widgetSyncCursor(_data_widgetSyncCursor);
        break;
      }
      case 275: {
        _data_widgetDerivedSubtreeCursor = _pool.allocate<WidgetDerivedSubtreeCursor>();
        if (!_data_widgetDerivedSubtreeCursor->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 276: {
        _data_widgetCachedAncestor = _pool.allocate<WidgetPointer>();
        if (!_data_widgetCachedAncestor->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 285: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_widgetInputBehavior))) return false;
        set_widgetInputBehavior(_data_widgetInputBehavior);
        break;
      }
      case 286: {
        if (!_bb.readString(_data_widgetTooltip, _pool)) return false;
        set_widgetTooltip(_data_widgetTooltip);
        break;
      }
      case 291: {
        _data_widgetHoverStyle = _pool.allocate<WidgetHoverStyle>();
        if (!_data_widgetHoverStyle->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 293: {
        if (!_bb.readByte(_data_isWidgetStickable)) return false;
        set_isWidgetStickable(_data_isWidgetStickable);
        break;
      }
      case 360: {
        if (!_bb.readByte(_data_shouldHideCursorsOnWidgetHover)) return false;
        set_shouldHideCursorsOnWidgetHover(_data_shouldHideCursorsOnWidgetHover);
        break;
      }
      case 262: {
        _data_widgetMetadata = _pool.allocate<WidgetMetadata>();
        if (!_data_widgetMetadata->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 263: {
        if (!_bb.readVarUint(_count)) return false;
        for (WidgetEvent &_it : set_widgetEvents(_pool, _count)) if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_it))) return false;
        break;
      }
      case 265: {
        if (!_bb.readVarUint(_count)) return false;
        for (WidgetPropertyMenuItem &_it : set_widgetPropertyMenuItems(_pool, _count)) if (!_it.decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 308: {
        _data_tableRowPositions = _pool.allocate<TableRowColumnPositionMap>();
        if (!_data_tableRowPositions->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 309: {
        _data_tableColumnPositions = _pool.allocate<TableRowColumnPositionMap>();
        if (!_data_tableColumnPositions->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 310: {
        _data_tableRowHeights = _pool.allocate<TableRowColumnSizeMap>();
        if (!_data_tableRowHeights->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 311: {
        _data_tableColumnWidths = _pool.allocate<TableRowColumnSizeMap>();
        if (!_data_tableColumnWidths->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 251: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_internalEnumForTest))) return false;
        set_internalEnumForTest(_data_internalEnumForTest);
        break;
      }
      case 257: {
        _data_internalDataForTest = _pool.allocate<InternalDataForTest>();
        if (!_data_internalDataForTest->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 10: {
        if (!_bb.readVarUint(_data_count)) return false;
        set_count(_data_count);
        break;
      }
      case 62: {
        if (!_bb.readVarUint(_data_countTag)) return false;
        set_countTag(_data_countTag);
        break;
      }
      case 14: {
        if (!_bb.readByte(_data_autoRename)) return false;
        set_autoRename(_data_autoRename);
        break;
      }
      case 66: {
        if (!_bb.readVarUint(_data_autoRenameTag)) return false;
        set_autoRenameTag(_data_autoRenameTag);
        break;
      }
      case 15: {
        if (!_bb.readByte(_data_backgroundEnabled)) return false;
        set_backgroundEnabled(_data_backgroundEnabled);
        break;
      }
      case 67: {
        if (!_bb.readVarUint(_data_backgroundEnabledTag)) return false;
        set_backgroundEnabledTag(_data_backgroundEnabledTag);
        break;
      }
      case 17: {
        if (!_bb.readByte(_data_exportContentsOnly)) return false;
        set_exportContentsOnly(_data_exportContentsOnly);
        break;
      }
      case 69: {
        if (!_bb.readVarUint(_data_exportContentsOnlyTag)) return false;
        set_exportContentsOnlyTag(_data_exportContentsOnlyTag);
        break;
      }
      case 24: {
        if (!_bb.readVarFloat(_data_starInnerScale)) return false;
        set_starInnerScale(_data_starInnerScale);
        break;
      }
      case 76: {
        if (!_bb.readVarUint(_data_starInnerScaleTag)) return false;
        set_starInnerScaleTag(_data_starInnerScaleTag);
        break;
      }
      case 25: {
        if (!_bb.readVarFloat(_data_miterLimit)) return false;
        set_miterLimit(_data_miterLimit);
        break;
      }
      case 77: {
        if (!_bb.readVarUint(_data_miterLimitTag)) return false;
        set_miterLimitTag(_data_miterLimitTag);
        break;
      }
      case 27: {
        if (!_bb.readVarFloat(_data_textTracking)) return false;
        set_textTracking(_data_textTracking);
        break;
      }
      case 79: {
        if (!_bb.readVarUint(_data_textTrackingTag)) return false;
        set_textTrackingTag(_data_textTrackingTag);
        break;
      }
      case 36: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_booleanOperation))) return false;
        set_booleanOperation(_data_booleanOperation);
        break;
      }
      case 88: {
        if (!_bb.readVarUint(_data_booleanOperationTag)) return false;
        set_booleanOperationTag(_data_booleanOperationTag);
        break;
      }
      case 37: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_verticalConstraint))) return false;
        set_verticalConstraint(_data_verticalConstraint);
        break;
      }
      case 89: {
        if (!_bb.readVarUint(_data_verticalConstraintTag)) return false;
        set_verticalConstraintTag(_data_verticalConstraintTag);
        break;
      }
      case 44: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_handleMirroring))) return false;
        set_handleMirroring(_data_handleMirroring);
        break;
      }
      case 96: {
        if (!_bb.readVarUint(_data_handleMirroringTag)) return false;
        set_handleMirroringTag(_data_handleMirroringTag);
        break;
      }
      case 45: {
        if (!_bb.readVarUint(_count)) return false;
        for (ExportSettings &_it : set_exportSettings(_pool, _count)) if (!_it.decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 97: {
        if (!_bb.readVarUint(_data_exportSettingsTag)) return false;
        set_exportSettingsTag(_data_exportSettingsTag);
        break;
      }
      case 46: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_textAutoResize))) return false;
        set_textAutoResize(_data_textAutoResize);
        break;
      }
      case 98: {
        if (!_bb.readVarUint(_data_textAutoResizeTag)) return false;
        set_textAutoResizeTag(_data_textAutoResizeTag);
        break;
      }
      case 47: {
        if (!_bb.readVarUint(_count)) return false;
        for (LayoutGrid &_it : set_layoutGrids(_pool, _count)) if (!_it.decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 99: {
        if (!_bb.readVarUint(_data_layoutGridsTag)) return false;
        set_layoutGridsTag(_data_layoutGridsTag);
        break;
      }
      case 48: {
        _data_vectorData = _pool.allocate<VectorData>();
        if (!_data_vectorData->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 100: {
        if (!_bb.readVarUint(_data_vectorDataTag)) return false;
        set_vectorDataTag(_data_vectorDataTag);
        break;
      }
      case 115: {
        if (!_bb.readByte(_data_frameMaskDisabled)) return false;
        set_frameMaskDisabled(_data_frameMaskDisabled);
        break;
      }
      case 116: {
        if (!_bb.readVarUint(_data_frameMaskDisabledTag)) return false;
        set_frameMaskDisabledTag(_data_frameMaskDisabledTag);
        break;
      }
      case 117: {
        if (!_bb.readByte(_data_resizeToFit)) return false;
        set_resizeToFit(_data_resizeToFit);
        break;
      }
      case 118: {
        if (!_bb.readVarUint(_data_resizeToFitTag)) return false;
        set_resizeToFitTag(_data_resizeToFitTag);
        break;
      }
      case 119: {
        if (!_bb.readByte(_data_exportBackgroundDisabled)) return false;
        set_exportBackgroundDisabled(_data_exportBackgroundDisabled);
        break;
      }
      case 138: {
        if (!_bb.readVarUint(_count)) return false;
        for (Guide &_it : set_guides(_pool, _count)) if (!_it.decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 142: {
        if (!_bb.readByte(_data_internalOnly)) return false;
        set_internalOnly(_data_internalOnly);
        break;
      }
      case 159: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_scrollDirection))) return false;
        set_scrollDirection(_data_scrollDirection);
        break;
      }
      case 160: {
        if (!_bb.readVarFloat(_data_cornerSmoothing)) return false;
        set_cornerSmoothing(_data_cornerSmoothing);
        break;
      }
      case 166: {
        _data_scrollOffset = _pool.allocate<Vector>();
        if (!_data_scrollOffset->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 175: {
        if (!_bb.readByte(_data_exportTextAsSVGText)) return false;
        set_exportTextAsSVGText(_data_exportTextAsSVGText);
        break;
      }
      case 178: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_scrollContractedState))) return false;
        set_scrollContractedState(_data_scrollContractedState);
        break;
      }
      case 179: {
        _data_contractedSize = _pool.allocate<Vector>();
        if (!_data_contractedSize->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 180: {
        if (!_bb.readString(_data_fixedChildrenDivider, _pool)) return false;
        set_fixedChildrenDivider(_data_fixedChildrenDivider);
        break;
      }
      case 186: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_scrollBehavior))) return false;
        set_scrollBehavior(_data_scrollBehavior);
        break;
      }
      case 195: {
        _data_arcData = _pool.allocate<ArcData>();
        if (!_data_arcData->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 196: {
        if (!_bb.readVarInt(_data_derivedSymbolDataLayoutVersion)) return false;
        set_derivedSymbolDataLayoutVersion(_data_derivedSymbolDataLayoutVersion);
        break;
      }
      case 197: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_navigationType))) return false;
        set_navigationType(_data_navigationType);
        break;
      }
      case 198: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_overlayPositionType))) return false;
        set_overlayPositionType(_data_overlayPositionType);
        break;
      }
      case 199: {
        _data_overlayRelativePosition = _pool.allocate<Vector>();
        if (!_data_overlayRelativePosition->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 200: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_overlayBackgroundInteraction))) return false;
        set_overlayBackgroundInteraction(_data_overlayBackgroundInteraction);
        break;
      }
      case 201: {
        _data_overlayBackgroundAppearance = _pool.allocate<OverlayBackgroundAppearance>();
        if (!_data_overlayBackgroundAppearance->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 213: {
        _data_overrideKey = _pool.allocate<GUID>();
        if (!_data_overrideKey->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 220: {
        if (!_bb.readByte(_data_containerSupportsFillStrokeAndCorners)) return false;
        set_containerSupportsFillStrokeAndCorners(_data_containerSupportsFillStrokeAndCorners);
        break;
      }
      case 221: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_stackCounterSizing))) return false;
        set_stackCounterSizing(_data_stackCounterSizing);
        break;
      }
      case 222: {
        if (!_bb.readByte(_data_containersSupportFillStrokeAndCorners)) return false;
        set_containersSupportFillStrokeAndCorners(_data_containersSupportFillStrokeAndCorners);
        break;
      }
      case 224: {
        _data_keyTrigger = _pool.allocate<KeyTrigger>();
        if (!_data_keyTrigger->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 227: {
        if (!_bb.readString(_data_voiceEventPhrase, _pool)) return false;
        set_voiceEventPhrase(_data_voiceEventPhrase);
        break;
      }
      case 235: {
        if (!_bb.readVarUint(_count)) return false;
        for (GUID &_it : set_ancestorPathBeforeDeletion(_pool, _count)) if (!_it.decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 237: {
        if (!_bb.readVarUint(_count)) return false;
        for (SymbolLink &_it : set_symbolLinks(_pool, _count)) if (!_it.decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 239: {
        _data_textListData = _pool.allocate<TextListData>();
        if (!_data_textListData->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 261: {
        if (!_bb.readByte(_data_detachOpticalSizeFromFontSize)) return false;
        set_detachOpticalSizeFromFontSize(_data_detachOpticalSizeFromFontSize);
        break;
      }
      case 264: {
        if (!_bb.readVarFloat(_data_listSpacing)) return false;
        set_listSpacing(_data_listSpacing);
        break;
      }
      case 270: {
        _data_embedData = _pool.allocate<EmbedData>();
        if (!_data_embedData->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 272: {
        _data_richMediaData = _pool.allocate<RichMediaData>();
        if (!_data_richMediaData->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 277: {
        _data_renderedSyncedState = _pool.allocate<MultiplayerMap>();
        if (!_data_renderedSyncedState->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 284: {
        if (!_bb.readByte(_data_simplifyInstancePanels)) return false;
        set_simplifyInstancePanels(_data_simplifyInstancePanels);
        break;
      }
      case 302: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_accessibleHTMLTag))) return false;
        set_accessibleHTMLTag(_data_accessibleHTMLTag);
        break;
      }
      case 303: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_ariaRole))) return false;
        set_ariaRole(_data_ariaRole);
        break;
      }
      case 304: {
        if (!_bb.readString(_data_accessibleLabel, _pool)) return false;
        set_accessibleLabel(_data_accessibleLabel);
        break;
      }
      case 306: {
        _data_variableData = _pool.allocate<VariableData>();
        if (!_data_variableData->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 307: {
        _data_variableConsumptionMap = _pool.allocate<VariableDataMap>();
        if (!_data_variableConsumptionMap->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 316: {
        _data_variableModeBySetMap = _pool.allocate<VariableModeBySetMap>();
        if (!_data_variableModeBySetMap->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 312: {
        if (!_bb.readVarUint(_count)) return false;
        for (VariableSetMode &_it : set_variableSetModes(_pool, _count)) if (!_it.decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 313: {
        _data_variableSetID = _pool.allocate<VariableSetID>();
        if (!_data_variableSetID->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 314: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_variableResolvedType))) return false;
        set_variableResolvedType(_data_variableResolvedType);
        break;
      }
      case 315: {
        _data_variableDataValues = _pool.allocate<VariableDataValues>();
        if (!_data_variableDataValues->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 350: {
        if (!_bb.readString(_data_variableTokenName, _pool)) return false;
        set_variableTokenName(_data_variableTokenName);
        break;
      }
      case 353: {
        if (!_bb.readVarUint(_count)) return false;
        for (VariableScope &_it : set_variableScopes(_pool, _count)) if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_it))) return false;
        break;
      }
      case 358: {
        _data_codeSyntax = _pool.allocate<CodeSyntaxMap>();
        if (!_data_codeSyntax->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 361: {
        _data_handoffStatusMap = _pool.allocate<HandoffStatusMap>();
        if (!_data_handoffStatusMap->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 327: {
        _data_agendaPositionMap = _pool.allocate<AgendaPositionMap>();
        if (!_data_agendaPositionMap->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 328: {
        _data_agendaMetadataMap = _pool.allocate<AgendaMetadataMap>();
        if (!_data_agendaMetadataMap->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 329: {
        _data_migrationStatus = _pool.allocate<MigrationStatus>();
        if (!_data_migrationStatus->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 330: {
        if (!_bb.readByte(_data_isSoftDeleted)) return false;
        set_isSoftDeleted(_data_isSoftDeleted);
        break;
      }
      case 331: {
        _data_editInfo = _pool.allocate<EditInfo>();
        if (!_data_editInfo->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 341: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_colorProfile))) return false;
        set_colorProfile(_data_colorProfile);
        break;
      }
      case 342: {
        _data_detachedSymbolId = _pool.allocate<SymbolId>();
        if (!_data_detachedSymbolId->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 346: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_childReadingDirection))) return false;
        set_childReadingDirection(_data_childReadingDirection);
        break;
      }
      case 347: {
        if (!_bb.readString(_data_readingIndex, _pool)) return false;
        set_readingIndex(_data_readingIndex);
        break;
      }
      case 349: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_documentColorProfile))) return false;
        set_documentColorProfile(_data_documentColorProfile);
        break;
      }
      case 354: {
        if (!_bb.readVarUint(_count)) return false;
        for (DeveloperRelatedLink &_it : set_developerRelatedLinks(_pool, _count)) if (!_it.decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 356: {
        if (!_bb.readString(_data_slideActiveThemeLibKey, _pool)) return false;
        set_slideActiveThemeLibKey(_data_slideActiveThemeLibKey);
        break;
      }
      case 357: {
        _data_ariaAttributes = _pool.allocate<ARIAAttributesMap>();
        if (!_data_ariaAttributes->decode(_bb, _pool, _schema)) return false;
        break;
      }
      default: {
        if (!_schema || !_schema->skipNodeChangeField(_bb, _type)) return false;
        break;
      }
    }
  }
}

bool *VideoPlayback::autoplay() {
  return _flags[0] & 1 ? &_data_autoplay : nullptr;
}

const bool *VideoPlayback::autoplay() const {
  return _flags[0] & 1 ? &_data_autoplay : nullptr;
}

void VideoPlayback::set_autoplay(const bool &value) {
  _flags[0] |= 1; _data_autoplay = value;
}

bool *VideoPlayback::mediaLoop() {
  return _flags[0] & 2 ? &_data_mediaLoop : nullptr;
}

const bool *VideoPlayback::mediaLoop() const {
  return _flags[0] & 2 ? &_data_mediaLoop : nullptr;
}

void VideoPlayback::set_mediaLoop(const bool &value) {
  _flags[0] |= 2; _data_mediaLoop = value;
}

bool *VideoPlayback::muted() {
  return _flags[0] & 4 ? &_data_muted : nullptr;
}

const bool *VideoPlayback::muted() const {
  return _flags[0] & 4 ? &_data_muted : nullptr;
}

void VideoPlayback::set_muted(const bool &value) {
  _flags[0] |= 4; _data_muted = value;
}

bool VideoPlayback::encode(kiwi::ByteBuffer &_bb) {
  if (autoplay() != nullptr) {
    _bb.writeVarUint(1);
    _bb.writeByte(_data_autoplay);
  }
  if (mediaLoop() != nullptr) {
    _bb.writeVarUint(2);
    _bb.writeByte(_data_mediaLoop);
  }
  if (muted() != nullptr) {
    _bb.writeVarUint(3);
    _bb.writeByte(_data_muted);
  }
  _bb.writeVarUint(0);
  return true;
}

bool VideoPlayback::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        if (!_bb.readByte(_data_autoplay)) return false;
        set_autoplay(_data_autoplay);
        break;
      }
      case 2: {
        if (!_bb.readByte(_data_mediaLoop)) return false;
        set_mediaLoop(_data_mediaLoop);
        break;
      }
      case 3: {
        if (!_bb.readByte(_data_muted)) return false;
        set_muted(_data_muted);
        break;
      }
      default: {
        if (!_schema || !_schema->skipVideoPlaybackField(_bb, _type)) return false;
        break;
      }
    }
  }
}

kiwi::Array<Paint> *WidgetHoverStyle::fillPaints() {
  return _flags[0] & 1 ? &_data_fillPaints : nullptr;
}

const kiwi::Array<Paint> *WidgetHoverStyle::fillPaints() const {
  return _flags[0] & 1 ? &_data_fillPaints : nullptr;
}

kiwi::Array<Paint> &WidgetHoverStyle::set_fillPaints(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[0] |= 1; return _data_fillPaints = pool.array<Paint>(count);
}

kiwi::Array<Paint> *WidgetHoverStyle::strokePaints() {
  return _flags[0] & 2 ? &_data_strokePaints : nullptr;
}

const kiwi::Array<Paint> *WidgetHoverStyle::strokePaints() const {
  return _flags[0] & 2 ? &_data_strokePaints : nullptr;
}

kiwi::Array<Paint> &WidgetHoverStyle::set_strokePaints(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[0] |= 2; return _data_strokePaints = pool.array<Paint>(count);
}

float *WidgetHoverStyle::opacity() {
  return _flags[0] & 4 ? &_data_opacity : nullptr;
}

const float *WidgetHoverStyle::opacity() const {
  return _flags[0] & 4 ? &_data_opacity : nullptr;
}

void WidgetHoverStyle::set_opacity(const float &value) {
  _flags[0] |= 4; _data_opacity = value;
}

bool *WidgetHoverStyle::areFillPaintsSet() {
  return _flags[0] & 8 ? &_data_areFillPaintsSet : nullptr;
}

const bool *WidgetHoverStyle::areFillPaintsSet() const {
  return _flags[0] & 8 ? &_data_areFillPaintsSet : nullptr;
}

void WidgetHoverStyle::set_areFillPaintsSet(const bool &value) {
  _flags[0] |= 8; _data_areFillPaintsSet = value;
}

bool *WidgetHoverStyle::areStrokePaintsSet() {
  return _flags[0] & 16 ? &_data_areStrokePaintsSet : nullptr;
}

const bool *WidgetHoverStyle::areStrokePaintsSet() const {
  return _flags[0] & 16 ? &_data_areStrokePaintsSet : nullptr;
}

void WidgetHoverStyle::set_areStrokePaintsSet(const bool &value) {
  _flags[0] |= 16; _data_areStrokePaintsSet = value;
}

bool *WidgetHoverStyle::isOpacitySet() {
  return _flags[0] & 32 ? &_data_isOpacitySet : nullptr;
}

const bool *WidgetHoverStyle::isOpacitySet() const {
  return _flags[0] & 32 ? &_data_isOpacitySet : nullptr;
}

void WidgetHoverStyle::set_isOpacitySet(const bool &value) {
  _flags[0] |= 32; _data_isOpacitySet = value;
}

bool WidgetHoverStyle::encode(kiwi::ByteBuffer &_bb) {
  if (fillPaints() != nullptr) {
    _bb.writeVarUint(1);
    _bb.writeVarUint(_data_fillPaints.size());
    for (Paint &_it : _data_fillPaints) if (!_it.encode(_bb)) return false;
  }
  if (strokePaints() != nullptr) {
    _bb.writeVarUint(2);
    _bb.writeVarUint(_data_strokePaints.size());
    for (Paint &_it : _data_strokePaints) if (!_it.encode(_bb)) return false;
  }
  if (opacity() != nullptr) {
    _bb.writeVarUint(3);
    _bb.writeVarFloat(_data_opacity);
  }
  if (areFillPaintsSet() != nullptr) {
    _bb.writeVarUint(4);
    _bb.writeByte(_data_areFillPaintsSet);
  }
  if (areStrokePaintsSet() != nullptr) {
    _bb.writeVarUint(5);
    _bb.writeByte(_data_areStrokePaintsSet);
  }
  if (isOpacitySet() != nullptr) {
    _bb.writeVarUint(6);
    _bb.writeByte(_data_isOpacitySet);
  }
  _bb.writeVarUint(0);
  return true;
}

bool WidgetHoverStyle::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  uint32_t _count;
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        if (!_bb.readVarUint(_count)) return false;
        for (Paint &_it : set_fillPaints(_pool, _count)) if (!_it.decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 2: {
        if (!_bb.readVarUint(_count)) return false;
        for (Paint &_it : set_strokePaints(_pool, _count)) if (!_it.decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 3: {
        if (!_bb.readVarFloat(_data_opacity)) return false;
        set_opacity(_data_opacity);
        break;
      }
      case 4: {
        if (!_bb.readByte(_data_areFillPaintsSet)) return false;
        set_areFillPaintsSet(_data_areFillPaintsSet);
        break;
      }
      case 5: {
        if (!_bb.readByte(_data_areStrokePaintsSet)) return false;
        set_areStrokePaintsSet(_data_areStrokePaintsSet);
        break;
      }
      case 6: {
        if (!_bb.readByte(_data_isOpacitySet)) return false;
        set_isOpacitySet(_data_isOpacitySet);
        break;
      }
      default: {
        if (!_schema || !_schema->skipWidgetHoverStyleField(_bb, _type)) return false;
        break;
      }
    }
  }
}

uint32_t *WidgetDerivedSubtreeCursor::sessionID() {
  return _flags[0] & 1 ? &_data_sessionID : nullptr;
}

const uint32_t *WidgetDerivedSubtreeCursor::sessionID() const {
  return _flags[0] & 1 ? &_data_sessionID : nullptr;
}

void WidgetDerivedSubtreeCursor::set_sessionID(const uint32_t &value) {
  _flags[0] |= 1; _data_sessionID = value;
}

uint32_t *WidgetDerivedSubtreeCursor::counter() {
  return _flags[0] & 2 ? &_data_counter : nullptr;
}

const uint32_t *WidgetDerivedSubtreeCursor::counter() const {
  return _flags[0] & 2 ? &_data_counter : nullptr;
}

void WidgetDerivedSubtreeCursor::set_counter(const uint32_t &value) {
  _flags[0] |= 2; _data_counter = value;
}

bool WidgetDerivedSubtreeCursor::encode(kiwi::ByteBuffer &_bb) {
  if (sessionID() != nullptr) {
    _bb.writeVarUint(1);
    _bb.writeVarUint(_data_sessionID);
  }
  if (counter() != nullptr) {
    _bb.writeVarUint(2);
    _bb.writeVarUint(_data_counter);
  }
  _bb.writeVarUint(0);
  return true;
}

bool WidgetDerivedSubtreeCursor::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        if (!_bb.readVarUint(_data_sessionID)) return false;
        set_sessionID(_data_sessionID);
        break;
      }
      case 2: {
        if (!_bb.readVarUint(_data_counter)) return false;
        set_counter(_data_counter);
        break;
      }
      default: {
        if (!_schema || !_schema->skipWidgetDerivedSubtreeCursorField(_bb, _type)) return false;
        break;
      }
    }
  }
}

kiwi::Array<MultiplayerMapEntry> *MultiplayerMap::entries() {
  return _flags[0] & 1 ? &_data_entries : nullptr;
}

const kiwi::Array<MultiplayerMapEntry> *MultiplayerMap::entries() const {
  return _flags[0] & 1 ? &_data_entries : nullptr;
}

kiwi::Array<MultiplayerMapEntry> &MultiplayerMap::set_entries(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[0] |= 1; return _data_entries = pool.array<MultiplayerMapEntry>(count);
}

bool MultiplayerMap::encode(kiwi::ByteBuffer &_bb) {
  if (entries() != nullptr) {
    _bb.writeVarUint(1);
    _bb.writeVarUint(_data_entries.size());
    for (MultiplayerMapEntry &_it : _data_entries) if (!_it.encode(_bb)) return false;
  }
  _bb.writeVarUint(0);
  return true;
}

bool MultiplayerMap::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  uint32_t _count;
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        if (!_bb.readVarUint(_count)) return false;
        for (MultiplayerMapEntry &_it : set_entries(_pool, _count)) if (!_it.decode(_bb, _pool, _schema)) return false;
        break;
      }
      default: {
        if (!_schema || !_schema->skipMultiplayerMapField(_bb, _type)) return false;
        break;
      }
    }
  }
}

kiwi::String *MultiplayerMapEntry::key() {
  return _flags[0] & 1 ? &_data_key : nullptr;
}

const kiwi::String *MultiplayerMapEntry::key() const {
  return _flags[0] & 1 ? &_data_key : nullptr;
}

void MultiplayerMapEntry::set_key(const kiwi::String &value) {
  _flags[0] |= 1; _data_key = value;
}

kiwi::String *MultiplayerMapEntry::value() {
  return _flags[0] & 2 ? &_data_value : nullptr;
}

const kiwi::String *MultiplayerMapEntry::value() const {
  return _flags[0] & 2 ? &_data_value : nullptr;
}

void MultiplayerMapEntry::set_value(const kiwi::String &value) {
  _flags[0] |= 2; _data_value = value;
}

bool MultiplayerMapEntry::encode(kiwi::ByteBuffer &_bb) {
  if (key() != nullptr) {
    _bb.writeVarUint(1);
    _bb.writeString(_data_key.c_str());
  }
  if (value() != nullptr) {
    _bb.writeVarUint(2);
    _bb.writeString(_data_value.c_str());
  }
  _bb.writeVarUint(0);
  return true;
}

bool MultiplayerMapEntry::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        if (!_bb.readString(_data_key, _pool)) return false;
        set_key(_data_key);
        break;
      }
      case 2: {
        if (!_bb.readString(_data_value, _pool)) return false;
        set_value(_data_value);
        break;
      }
      default: {
        if (!_schema || !_schema->skipMultiplayerMapEntryField(_bb, _type)) return false;
        break;
      }
    }
  }
}

kiwi::Array<VariableDataMapEntry> *VariableDataMap::entries() {
  return _flags[0] & 1 ? &_data_entries : nullptr;
}

const kiwi::Array<VariableDataMapEntry> *VariableDataMap::entries() const {
  return _flags[0] & 1 ? &_data_entries : nullptr;
}

kiwi::Array<VariableDataMapEntry> &VariableDataMap::set_entries(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[0] |= 1; return _data_entries = pool.array<VariableDataMapEntry>(count);
}

bool VariableDataMap::encode(kiwi::ByteBuffer &_bb) {
  if (entries() != nullptr) {
    _bb.writeVarUint(1);
    _bb.writeVarUint(_data_entries.size());
    for (VariableDataMapEntry &_it : _data_entries) if (!_it.encode(_bb)) return false;
  }
  _bb.writeVarUint(0);
  return true;
}

bool VariableDataMap::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  uint32_t _count;
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        if (!_bb.readVarUint(_count)) return false;
        for (VariableDataMapEntry &_it : set_entries(_pool, _count)) if (!_it.decode(_bb, _pool, _schema)) return false;
        break;
      }
      default: {
        if (!_schema || !_schema->skipVariableDataMapField(_bb, _type)) return false;
        break;
      }
    }
  }
}

uint32_t *VariableDataMapEntry::nodeField() {
  return _flags[0] & 1 ? &_data_nodeField : nullptr;
}

const uint32_t *VariableDataMapEntry::nodeField() const {
  return _flags[0] & 1 ? &_data_nodeField : nullptr;
}

void VariableDataMapEntry::set_nodeField(const uint32_t &value) {
  _flags[0] |= 1; _data_nodeField = value;
}

VariableData *VariableDataMapEntry::variableData() {
  return _data_variableData;
}

const VariableData *VariableDataMapEntry::variableData() const {
  return _data_variableData;
}

void VariableDataMapEntry::set_variableData(VariableData *value) {
  _data_variableData = value;
}

VariableField *VariableDataMapEntry::variableField() {
  return _flags[0] & 4 ? &_data_variableField : nullptr;
}

const VariableField *VariableDataMapEntry::variableField() const {
  return _flags[0] & 4 ? &_data_variableField : nullptr;
}

void VariableDataMapEntry::set_variableField(const VariableField &value) {
  _flags[0] |= 4; _data_variableField = value;
}

bool VariableDataMapEntry::encode(kiwi::ByteBuffer &_bb) {
  if (nodeField() != nullptr) {
    _bb.writeVarUint(1);
    _bb.writeVarUint(_data_nodeField);
  }
  if (variableData() != nullptr) {
    _bb.writeVarUint(2);
    if (!_data_variableData->encode(_bb)) return false;
  }
  if (variableField() != nullptr) {
    _bb.writeVarUint(3);
    _bb.writeVarUint(static_cast<uint32_t>(_data_variableField));
  }
  _bb.writeVarUint(0);
  return true;
}

bool VariableDataMapEntry::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        if (!_bb.readVarUint(_data_nodeField)) return false;
        set_nodeField(_data_nodeField);
        break;
      }
      case 2: {
        _data_variableData = _pool.allocate<VariableData>();
        if (!_data_variableData->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 3: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_variableField))) return false;
        set_variableField(_data_variableField);
        break;
      }
      default: {
        if (!_schema || !_schema->skipVariableDataMapEntryField(_bb, _type)) return false;
        break;
      }
    }
  }
}

kiwi::Array<VariableModeBySetMapEntry> *VariableModeBySetMap::entries() {
  return _flags[0] & 1 ? &_data_entries : nullptr;
}

const kiwi::Array<VariableModeBySetMapEntry> *VariableModeBySetMap::entries() const {
  return _flags[0] & 1 ? &_data_entries : nullptr;
}

kiwi::Array<VariableModeBySetMapEntry> &VariableModeBySetMap::set_entries(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[0] |= 1; return _data_entries = pool.array<VariableModeBySetMapEntry>(count);
}

bool VariableModeBySetMap::encode(kiwi::ByteBuffer &_bb) {
  if (entries() != nullptr) {
    _bb.writeVarUint(1);
    _bb.writeVarUint(_data_entries.size());
    for (VariableModeBySetMapEntry &_it : _data_entries) if (!_it.encode(_bb)) return false;
  }
  _bb.writeVarUint(0);
  return true;
}

bool VariableModeBySetMap::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  uint32_t _count;
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        if (!_bb.readVarUint(_count)) return false;
        for (VariableModeBySetMapEntry &_it : set_entries(_pool, _count)) if (!_it.decode(_bb, _pool, _schema)) return false;
        break;
      }
      default: {
        if (!_schema || !_schema->skipVariableModeBySetMapField(_bb, _type)) return false;
        break;
      }
    }
  }
}

VariableSetID *VariableModeBySetMapEntry::variableSetID() {
  return _data_variableSetID;
}

const VariableSetID *VariableModeBySetMapEntry::variableSetID() const {
  return _data_variableSetID;
}

void VariableModeBySetMapEntry::set_variableSetID(VariableSetID *value) {
  _data_variableSetID = value;
}

GUID *VariableModeBySetMapEntry::variableModeID() {
  return _data_variableModeID;
}

const GUID *VariableModeBySetMapEntry::variableModeID() const {
  return _data_variableModeID;
}

void VariableModeBySetMapEntry::set_variableModeID(GUID *value) {
  _data_variableModeID = value;
}

bool VariableModeBySetMapEntry::encode(kiwi::ByteBuffer &_bb) {
  if (variableSetID() != nullptr) {
    _bb.writeVarUint(1);
    if (!_data_variableSetID->encode(_bb)) return false;
  }
  if (variableModeID() != nullptr) {
    _bb.writeVarUint(2);
    if (!_data_variableModeID->encode(_bb)) return false;
  }
  _bb.writeVarUint(0);
  return true;
}

bool VariableModeBySetMapEntry::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        _data_variableSetID = _pool.allocate<VariableSetID>();
        if (!_data_variableSetID->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 2: {
        _data_variableModeID = _pool.allocate<GUID>();
        if (!_data_variableModeID->decode(_bb, _pool, _schema)) return false;
        break;
      }
      default: {
        if (!_schema || !_schema->skipVariableModeBySetMapEntryField(_bb, _type)) return false;
        break;
      }
    }
  }
}

kiwi::Array<CodeSyntaxMapEntry> *CodeSyntaxMap::entries() {
  return _flags[0] & 1 ? &_data_entries : nullptr;
}

const kiwi::Array<CodeSyntaxMapEntry> *CodeSyntaxMap::entries() const {
  return _flags[0] & 1 ? &_data_entries : nullptr;
}

kiwi::Array<CodeSyntaxMapEntry> &CodeSyntaxMap::set_entries(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[0] |= 1; return _data_entries = pool.array<CodeSyntaxMapEntry>(count);
}

bool CodeSyntaxMap::encode(kiwi::ByteBuffer &_bb) {
  if (entries() != nullptr) {
    _bb.writeVarUint(1);
    _bb.writeVarUint(_data_entries.size());
    for (CodeSyntaxMapEntry &_it : _data_entries) if (!_it.encode(_bb)) return false;
  }
  _bb.writeVarUint(0);
  return true;
}

bool CodeSyntaxMap::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  uint32_t _count;
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        if (!_bb.readVarUint(_count)) return false;
        for (CodeSyntaxMapEntry &_it : set_entries(_pool, _count)) if (!_it.decode(_bb, _pool, _schema)) return false;
        break;
      }
      default: {
        if (!_schema || !_schema->skipCodeSyntaxMapField(_bb, _type)) return false;
        break;
      }
    }
  }
}

CodeSyntaxPlatform *CodeSyntaxMapEntry::platform() {
  return _flags[0] & 1 ? &_data_platform : nullptr;
}

const CodeSyntaxPlatform *CodeSyntaxMapEntry::platform() const {
  return _flags[0] & 1 ? &_data_platform : nullptr;
}

void CodeSyntaxMapEntry::set_platform(const CodeSyntaxPlatform &value) {
  _flags[0] |= 1; _data_platform = value;
}

kiwi::String *CodeSyntaxMapEntry::value() {
  return _flags[0] & 2 ? &_data_value : nullptr;
}

const kiwi::String *CodeSyntaxMapEntry::value() const {
  return _flags[0] & 2 ? &_data_value : nullptr;
}

void CodeSyntaxMapEntry::set_value(const kiwi::String &value) {
  _flags[0] |= 2; _data_value = value;
}

bool CodeSyntaxMapEntry::encode(kiwi::ByteBuffer &_bb) {
  if (platform() != nullptr) {
    _bb.writeVarUint(1);
    _bb.writeVarUint(static_cast<uint32_t>(_data_platform));
  }
  if (value() != nullptr) {
    _bb.writeVarUint(2);
    _bb.writeString(_data_value.c_str());
  }
  _bb.writeVarUint(0);
  return true;
}

bool CodeSyntaxMapEntry::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_platform))) return false;
        set_platform(_data_platform);
        break;
      }
      case 2: {
        if (!_bb.readString(_data_value, _pool)) return false;
        set_value(_data_value);
        break;
      }
      default: {
        if (!_schema || !_schema->skipCodeSyntaxMapEntryField(_bb, _type)) return false;
        break;
      }
    }
  }
}

kiwi::Array<TableRowColumnPositionMapEntry> *TableRowColumnPositionMap::entries() {
  return _flags[0] & 1 ? &_data_entries : nullptr;
}

const kiwi::Array<TableRowColumnPositionMapEntry> *TableRowColumnPositionMap::entries() const {
  return _flags[0] & 1 ? &_data_entries : nullptr;
}

kiwi::Array<TableRowColumnPositionMapEntry> &TableRowColumnPositionMap::set_entries(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[0] |= 1; return _data_entries = pool.array<TableRowColumnPositionMapEntry>(count);
}

bool TableRowColumnPositionMap::encode(kiwi::ByteBuffer &_bb) {
  if (entries() != nullptr) {
    _bb.writeVarUint(1);
    _bb.writeVarUint(_data_entries.size());
    for (TableRowColumnPositionMapEntry &_it : _data_entries) if (!_it.encode(_bb)) return false;
  }
  _bb.writeVarUint(0);
  return true;
}

bool TableRowColumnPositionMap::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  uint32_t _count;
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        if (!_bb.readVarUint(_count)) return false;
        for (TableRowColumnPositionMapEntry &_it : set_entries(_pool, _count)) if (!_it.decode(_bb, _pool, _schema)) return false;
        break;
      }
      default: {
        if (!_schema || !_schema->skipTableRowColumnPositionMapField(_bb, _type)) return false;
        break;
      }
    }
  }
}

GUID *TableRowColumnPositionMapEntry::id() {
  return _data_id;
}

const GUID *TableRowColumnPositionMapEntry::id() const {
  return _data_id;
}

void TableRowColumnPositionMapEntry::set_id(GUID *value) {
  _data_id = value;
}

kiwi::String *TableRowColumnPositionMapEntry::position() {
  return _flags[0] & 2 ? &_data_position : nullptr;
}

const kiwi::String *TableRowColumnPositionMapEntry::position() const {
  return _flags[0] & 2 ? &_data_position : nullptr;
}

void TableRowColumnPositionMapEntry::set_position(const kiwi::String &value) {
  _flags[0] |= 2; _data_position = value;
}

bool TableRowColumnPositionMapEntry::encode(kiwi::ByteBuffer &_bb) {
  if (id() != nullptr) {
    _bb.writeVarUint(1);
    if (!_data_id->encode(_bb)) return false;
  }
  if (position() != nullptr) {
    _bb.writeVarUint(2);
    _bb.writeString(_data_position.c_str());
  }
  _bb.writeVarUint(0);
  return true;
}

bool TableRowColumnPositionMapEntry::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        _data_id = _pool.allocate<GUID>();
        if (!_data_id->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 2: {
        if (!_bb.readString(_data_position, _pool)) return false;
        set_position(_data_position);
        break;
      }
      default: {
        if (!_schema || !_schema->skipTableRowColumnPositionMapEntryField(_bb, _type)) return false;
        break;
      }
    }
  }
}

kiwi::Array<TableRowColumnSizeMapEntry> *TableRowColumnSizeMap::entries() {
  return _flags[0] & 1 ? &_data_entries : nullptr;
}

const kiwi::Array<TableRowColumnSizeMapEntry> *TableRowColumnSizeMap::entries() const {
  return _flags[0] & 1 ? &_data_entries : nullptr;
}

kiwi::Array<TableRowColumnSizeMapEntry> &TableRowColumnSizeMap::set_entries(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[0] |= 1; return _data_entries = pool.array<TableRowColumnSizeMapEntry>(count);
}

bool TableRowColumnSizeMap::encode(kiwi::ByteBuffer &_bb) {
  if (entries() != nullptr) {
    _bb.writeVarUint(1);
    _bb.writeVarUint(_data_entries.size());
    for (TableRowColumnSizeMapEntry &_it : _data_entries) if (!_it.encode(_bb)) return false;
  }
  _bb.writeVarUint(0);
  return true;
}

bool TableRowColumnSizeMap::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  uint32_t _count;
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        if (!_bb.readVarUint(_count)) return false;
        for (TableRowColumnSizeMapEntry &_it : set_entries(_pool, _count)) if (!_it.decode(_bb, _pool, _schema)) return false;
        break;
      }
      default: {
        if (!_schema || !_schema->skipTableRowColumnSizeMapField(_bb, _type)) return false;
        break;
      }
    }
  }
}

GUID *TableRowColumnSizeMapEntry::id() {
  return _data_id;
}

const GUID *TableRowColumnSizeMapEntry::id() const {
  return _data_id;
}

void TableRowColumnSizeMapEntry::set_id(GUID *value) {
  _data_id = value;
}

float *TableRowColumnSizeMapEntry::size() {
  return _flags[0] & 2 ? &_data_size : nullptr;
}

const float *TableRowColumnSizeMapEntry::size() const {
  return _flags[0] & 2 ? &_data_size : nullptr;
}

void TableRowColumnSizeMapEntry::set_size(const float &value) {
  _flags[0] |= 2; _data_size = value;
}

bool TableRowColumnSizeMapEntry::encode(kiwi::ByteBuffer &_bb) {
  if (id() != nullptr) {
    _bb.writeVarUint(1);
    if (!_data_id->encode(_bb)) return false;
  }
  if (size() != nullptr) {
    _bb.writeVarUint(2);
    _bb.writeVarFloat(_data_size);
  }
  _bb.writeVarUint(0);
  return true;
}

bool TableRowColumnSizeMapEntry::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        _data_id = _pool.allocate<GUID>();
        if (!_data_id->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 2: {
        if (!_bb.readVarFloat(_data_size)) return false;
        set_size(_data_size);
        break;
      }
      default: {
        if (!_schema || !_schema->skipTableRowColumnSizeMapEntryField(_bb, _type)) return false;
        break;
      }
    }
  }
}

kiwi::Array<AgendaPositionMapEntry> *AgendaPositionMap::entries() {
  return _flags[0] & 1 ? &_data_entries : nullptr;
}

const kiwi::Array<AgendaPositionMapEntry> *AgendaPositionMap::entries() const {
  return _flags[0] & 1 ? &_data_entries : nullptr;
}

kiwi::Array<AgendaPositionMapEntry> &AgendaPositionMap::set_entries(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[0] |= 1; return _data_entries = pool.array<AgendaPositionMapEntry>(count);
}

bool AgendaPositionMap::encode(kiwi::ByteBuffer &_bb) {
  if (entries() != nullptr) {
    _bb.writeVarUint(1);
    _bb.writeVarUint(_data_entries.size());
    for (AgendaPositionMapEntry &_it : _data_entries) if (!_it.encode(_bb)) return false;
  }
  _bb.writeVarUint(0);
  return true;
}

bool AgendaPositionMap::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  uint32_t _count;
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        if (!_bb.readVarUint(_count)) return false;
        for (AgendaPositionMapEntry &_it : set_entries(_pool, _count)) if (!_it.decode(_bb, _pool, _schema)) return false;
        break;
      }
      default: {
        if (!_schema || !_schema->skipAgendaPositionMapField(_bb, _type)) return false;
        break;
      }
    }
  }
}

GUID *AgendaPositionMapEntry::id() {
  return _data_id;
}

const GUID *AgendaPositionMapEntry::id() const {
  return _data_id;
}

void AgendaPositionMapEntry::set_id(GUID *value) {
  _data_id = value;
}

kiwi::String *AgendaPositionMapEntry::position() {
  return _flags[0] & 2 ? &_data_position : nullptr;
}

const kiwi::String *AgendaPositionMapEntry::position() const {
  return _flags[0] & 2 ? &_data_position : nullptr;
}

void AgendaPositionMapEntry::set_position(const kiwi::String &value) {
  _flags[0] |= 2; _data_position = value;
}

bool AgendaPositionMapEntry::encode(kiwi::ByteBuffer &_bb) {
  if (id() != nullptr) {
    _bb.writeVarUint(1);
    if (!_data_id->encode(_bb)) return false;
  }
  if (position() != nullptr) {
    _bb.writeVarUint(2);
    _bb.writeString(_data_position.c_str());
  }
  _bb.writeVarUint(0);
  return true;
}

bool AgendaPositionMapEntry::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        _data_id = _pool.allocate<GUID>();
        if (!_data_id->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 2: {
        if (!_bb.readString(_data_position, _pool)) return false;
        set_position(_data_position);
        break;
      }
      default: {
        if (!_schema || !_schema->skipAgendaPositionMapEntryField(_bb, _type)) return false;
        break;
      }
    }
  }
}

kiwi::Array<AgendaMetadataMapEntry> *AgendaMetadataMap::entries() {
  return _flags[0] & 1 ? &_data_entries : nullptr;
}

const kiwi::Array<AgendaMetadataMapEntry> *AgendaMetadataMap::entries() const {
  return _flags[0] & 1 ? &_data_entries : nullptr;
}

kiwi::Array<AgendaMetadataMapEntry> &AgendaMetadataMap::set_entries(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[0] |= 1; return _data_entries = pool.array<AgendaMetadataMapEntry>(count);
}

bool AgendaMetadataMap::encode(kiwi::ByteBuffer &_bb) {
  if (entries() != nullptr) {
    _bb.writeVarUint(1);
    _bb.writeVarUint(_data_entries.size());
    for (AgendaMetadataMapEntry &_it : _data_entries) if (!_it.encode(_bb)) return false;
  }
  _bb.writeVarUint(0);
  return true;
}

bool AgendaMetadataMap::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  uint32_t _count;
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        if (!_bb.readVarUint(_count)) return false;
        for (AgendaMetadataMapEntry &_it : set_entries(_pool, _count)) if (!_it.decode(_bb, _pool, _schema)) return false;
        break;
      }
      default: {
        if (!_schema || !_schema->skipAgendaMetadataMapField(_bb, _type)) return false;
        break;
      }
    }
  }
}

GUID *AgendaMetadataMapEntry::id() {
  return _data_id;
}

const GUID *AgendaMetadataMapEntry::id() const {
  return _data_id;
}

void AgendaMetadataMapEntry::set_id(GUID *value) {
  _data_id = value;
}

AgendaMetadata *AgendaMetadataMapEntry::data() {
  return _data_data;
}

const AgendaMetadata *AgendaMetadataMapEntry::data() const {
  return _data_data;
}

void AgendaMetadataMapEntry::set_data(AgendaMetadata *value) {
  _data_data = value;
}

bool AgendaMetadataMapEntry::encode(kiwi::ByteBuffer &_bb) {
  if (id() != nullptr) {
    _bb.writeVarUint(1);
    if (!_data_id->encode(_bb)) return false;
  }
  if (data() != nullptr) {
    _bb.writeVarUint(2);
    if (!_data_data->encode(_bb)) return false;
  }
  _bb.writeVarUint(0);
  return true;
}

bool AgendaMetadataMapEntry::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        _data_id = _pool.allocate<GUID>();
        if (!_data_id->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 2: {
        _data_data = _pool.allocate<AgendaMetadata>();
        if (!_data_data->decode(_bb, _pool, _schema)) return false;
        break;
      }
      default: {
        if (!_schema || !_schema->skipAgendaMetadataMapEntryField(_bb, _type)) return false;
        break;
      }
    }
  }
}

kiwi::String *AgendaMetadata::name() {
  return _flags[0] & 1 ? &_data_name : nullptr;
}

const kiwi::String *AgendaMetadata::name() const {
  return _flags[0] & 1 ? &_data_name : nullptr;
}

void AgendaMetadata::set_name(const kiwi::String &value) {
  _flags[0] |= 1; _data_name = value;
}

AgendaItemType *AgendaMetadata::type() {
  return _flags[0] & 2 ? &_data_type : nullptr;
}

const AgendaItemType *AgendaMetadata::type() const {
  return _flags[0] & 2 ? &_data_type : nullptr;
}

void AgendaMetadata::set_type(const AgendaItemType &value) {
  _flags[0] |= 2; _data_type = value;
}

GUID *AgendaMetadata::targetNodeID() {
  return _data_targetNodeID;
}

const GUID *AgendaMetadata::targetNodeID() const {
  return _data_targetNodeID;
}

void AgendaMetadata::set_targetNodeID(GUID *value) {
  _data_targetNodeID = value;
}

AgendaTimerInfo *AgendaMetadata::timerInfo() {
  return _data_timerInfo;
}

const AgendaTimerInfo *AgendaMetadata::timerInfo() const {
  return _data_timerInfo;
}

void AgendaMetadata::set_timerInfo(AgendaTimerInfo *value) {
  _data_timerInfo = value;
}

AgendaVoteInfo *AgendaMetadata::voteInfo() {
  return _data_voteInfo;
}

const AgendaVoteInfo *AgendaMetadata::voteInfo() const {
  return _data_voteInfo;
}

void AgendaMetadata::set_voteInfo(AgendaVoteInfo *value) {
  _data_voteInfo = value;
}

AgendaMusicInfo *AgendaMetadata::musicInfo() {
  return _data_musicInfo;
}

const AgendaMusicInfo *AgendaMetadata::musicInfo() const {
  return _data_musicInfo;
}

void AgendaMetadata::set_musicInfo(AgendaMusicInfo *value) {
  _data_musicInfo = value;
}

bool AgendaMetadata::encode(kiwi::ByteBuffer &_bb) {
  if (name() != nullptr) {
    _bb.writeVarUint(1);
    _bb.writeString(_data_name.c_str());
  }
  if (type() != nullptr) {
    _bb.writeVarUint(2);
    _bb.writeVarUint(static_cast<uint32_t>(_data_type));
  }
  if (targetNodeID() != nullptr) {
    _bb.writeVarUint(3);
    if (!_data_targetNodeID->encode(_bb)) return false;
  }
  if (timerInfo() != nullptr) {
    _bb.writeVarUint(4);
    if (!_data_timerInfo->encode(_bb)) return false;
  }
  if (voteInfo() != nullptr) {
    _bb.writeVarUint(5);
    if (!_data_voteInfo->encode(_bb)) return false;
  }
  if (musicInfo() != nullptr) {
    _bb.writeVarUint(6);
    if (!_data_musicInfo->encode(_bb)) return false;
  }
  _bb.writeVarUint(0);
  return true;
}

bool AgendaMetadata::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        if (!_bb.readString(_data_name, _pool)) return false;
        set_name(_data_name);
        break;
      }
      case 2: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_type))) return false;
        set_type(_data_type);
        break;
      }
      case 3: {
        _data_targetNodeID = _pool.allocate<GUID>();
        if (!_data_targetNodeID->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 4: {
        _data_timerInfo = _pool.allocate<AgendaTimerInfo>();
        if (!_data_timerInfo->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 5: {
        _data_voteInfo = _pool.allocate<AgendaVoteInfo>();
        if (!_data_voteInfo->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 6: {
        _data_musicInfo = _pool.allocate<AgendaMusicInfo>();
        if (!_data_musicInfo->decode(_bb, _pool, _schema)) return false;
        break;
      }
      default: {
        if (!_schema || !_schema->skipAgendaMetadataField(_bb, _type)) return false;
        break;
      }
    }
  }
}

uint32_t *AgendaTimerInfo::timerLength() {
  return _flags[0] & 1 ? &_data_timerLength : nullptr;
}

const uint32_t *AgendaTimerInfo::timerLength() const {
  return _flags[0] & 1 ? &_data_timerLength : nullptr;
}

void AgendaTimerInfo::set_timerLength(const uint32_t &value) {
  _flags[0] |= 1; _data_timerLength = value;
}

bool AgendaTimerInfo::encode(kiwi::ByteBuffer &_bb) {
  if (timerLength() != nullptr) {
    _bb.writeVarUint(1);
    _bb.writeVarUint(_data_timerLength);
  }
  _bb.writeVarUint(0);
  return true;
}

bool AgendaTimerInfo::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        if (!_bb.readVarUint(_data_timerLength)) return false;
        set_timerLength(_data_timerLength);
        break;
      }
      default: {
        if (!_schema || !_schema->skipAgendaTimerInfoField(_bb, _type)) return false;
        break;
      }
    }
  }
}

uint32_t *AgendaVoteInfo::voteCount() {
  return _flags[0] & 1 ? &_data_voteCount : nullptr;
}

const uint32_t *AgendaVoteInfo::voteCount() const {
  return _flags[0] & 1 ? &_data_voteCount : nullptr;
}

void AgendaVoteInfo::set_voteCount(const uint32_t &value) {
  _flags[0] |= 1; _data_voteCount = value;
}

bool AgendaVoteInfo::encode(kiwi::ByteBuffer &_bb) {
  if (voteCount() != nullptr) {
    _bb.writeVarUint(1);
    _bb.writeVarUint(_data_voteCount);
  }
  _bb.writeVarUint(0);
  return true;
}

bool AgendaVoteInfo::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        if (!_bb.readVarUint(_data_voteCount)) return false;
        set_voteCount(_data_voteCount);
        break;
      }
      default: {
        if (!_schema || !_schema->skipAgendaVoteInfoField(_bb, _type)) return false;
        break;
      }
    }
  }
}

kiwi::String *AgendaMusicInfo::songID() {
  return _flags[0] & 1 ? &_data_songID : nullptr;
}

const kiwi::String *AgendaMusicInfo::songID() const {
  return _flags[0] & 1 ? &_data_songID : nullptr;
}

void AgendaMusicInfo::set_songID(const kiwi::String &value) {
  _flags[0] |= 1; _data_songID = value;
}

uint32_t *AgendaMusicInfo::startTimeMs() {
  return _flags[0] & 2 ? &_data_startTimeMs : nullptr;
}

const uint32_t *AgendaMusicInfo::startTimeMs() const {
  return _flags[0] & 2 ? &_data_startTimeMs : nullptr;
}

void AgendaMusicInfo::set_startTimeMs(const uint32_t &value) {
  _flags[0] |= 2; _data_startTimeMs = value;
}

bool AgendaMusicInfo::encode(kiwi::ByteBuffer &_bb) {
  if (songID() != nullptr) {
    _bb.writeVarUint(1);
    _bb.writeString(_data_songID.c_str());
  }
  if (startTimeMs() != nullptr) {
    _bb.writeVarUint(2);
    _bb.writeVarUint(_data_startTimeMs);
  }
  _bb.writeVarUint(0);
  return true;
}

bool AgendaMusicInfo::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        if (!_bb.readString(_data_songID, _pool)) return false;
        set_songID(_data_songID);
        break;
      }
      case 2: {
        if (!_bb.readVarUint(_data_startTimeMs)) return false;
        set_startTimeMs(_data_startTimeMs);
        break;
      }
      default: {
        if (!_schema || !_schema->skipAgendaMusicInfoField(_bb, _type)) return false;
        break;
      }
    }
  }
}

uint32_t *ComponentPropRef::nodeField() {
  return _flags[0] & 1 ? &_data_nodeField : nullptr;
}

const uint32_t *ComponentPropRef::nodeField() const {
  return _flags[0] & 1 ? &_data_nodeField : nullptr;
}

void ComponentPropRef::set_nodeField(const uint32_t &value) {
  _flags[0] |= 1; _data_nodeField = value;
}

GUID *ComponentPropRef::defID() {
  return _data_defID;
}

const GUID *ComponentPropRef::defID() const {
  return _data_defID;
}

void ComponentPropRef::set_defID(GUID *value) {
  _data_defID = value;
}

kiwi::String *ComponentPropRef::zombieFallbackName() {
  return _flags[0] & 4 ? &_data_zombieFallbackName : nullptr;
}

const kiwi::String *ComponentPropRef::zombieFallbackName() const {
  return _flags[0] & 4 ? &_data_zombieFallbackName : nullptr;
}

void ComponentPropRef::set_zombieFallbackName(const kiwi::String &value) {
  _flags[0] |= 4; _data_zombieFallbackName = value;
}

ComponentPropNodeField *ComponentPropRef::componentPropNodeField() {
  return _flags[0] & 8 ? &_data_componentPropNodeField : nullptr;
}

const ComponentPropNodeField *ComponentPropRef::componentPropNodeField() const {
  return _flags[0] & 8 ? &_data_componentPropNodeField : nullptr;
}

void ComponentPropRef::set_componentPropNodeField(const ComponentPropNodeField &value) {
  _flags[0] |= 8; _data_componentPropNodeField = value;
}

bool *ComponentPropRef::isDeleted() {
  return _flags[0] & 16 ? &_data_isDeleted : nullptr;
}

const bool *ComponentPropRef::isDeleted() const {
  return _flags[0] & 16 ? &_data_isDeleted : nullptr;
}

void ComponentPropRef::set_isDeleted(const bool &value) {
  _flags[0] |= 16; _data_isDeleted = value;
}

bool ComponentPropRef::encode(kiwi::ByteBuffer &_bb) {
  if (nodeField() != nullptr) {
    _bb.writeVarUint(1);
    _bb.writeVarUint(_data_nodeField);
  }
  if (defID() != nullptr) {
    _bb.writeVarUint(2);
    if (!_data_defID->encode(_bb)) return false;
  }
  if (zombieFallbackName() != nullptr) {
    _bb.writeVarUint(3);
    _bb.writeString(_data_zombieFallbackName.c_str());
  }
  if (componentPropNodeField() != nullptr) {
    _bb.writeVarUint(4);
    _bb.writeVarUint(static_cast<uint32_t>(_data_componentPropNodeField));
  }
  if (isDeleted() != nullptr) {
    _bb.writeVarUint(5);
    _bb.writeByte(_data_isDeleted);
  }
  _bb.writeVarUint(0);
  return true;
}

bool ComponentPropRef::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        if (!_bb.readVarUint(_data_nodeField)) return false;
        set_nodeField(_data_nodeField);
        break;
      }
      case 2: {
        _data_defID = _pool.allocate<GUID>();
        if (!_data_defID->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 3: {
        if (!_bb.readString(_data_zombieFallbackName, _pool)) return false;
        set_zombieFallbackName(_data_zombieFallbackName);
        break;
      }
      case 4: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_componentPropNodeField))) return false;
        set_componentPropNodeField(_data_componentPropNodeField);
        break;
      }
      case 5: {
        if (!_bb.readByte(_data_isDeleted)) return false;
        set_isDeleted(_data_isDeleted);
        break;
      }
      default: {
        if (!_schema || !_schema->skipComponentPropRefField(_bb, _type)) return false;
        break;
      }
    }
  }
}

GUID *ComponentPropAssignment::defID() {
  return _data_defID;
}

const GUID *ComponentPropAssignment::defID() const {
  return _data_defID;
}

void ComponentPropAssignment::set_defID(GUID *value) {
  _data_defID = value;
}

ComponentPropValue *ComponentPropAssignment::value() {
  return _data_value;
}

const ComponentPropValue *ComponentPropAssignment::value() const {
  return _data_value;
}

void ComponentPropAssignment::set_value(ComponentPropValue *value) {
  _data_value = value;
}

bool ComponentPropAssignment::encode(kiwi::ByteBuffer &_bb) {
  if (defID() != nullptr) {
    _bb.writeVarUint(1);
    if (!_data_defID->encode(_bb)) return false;
  }
  if (value() != nullptr) {
    _bb.writeVarUint(2);
    if (!_data_value->encode(_bb)) return false;
  }
  _bb.writeVarUint(0);
  return true;
}

bool ComponentPropAssignment::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        _data_defID = _pool.allocate<GUID>();
        if (!_data_defID->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 2: {
        _data_value = _pool.allocate<ComponentPropValue>();
        if (!_data_value->decode(_bb, _pool, _schema)) return false;
        break;
      }
      default: {
        if (!_schema || !_schema->skipComponentPropAssignmentField(_bb, _type)) return false;
        break;
      }
    }
  }
}

GUID *ComponentPropDef::id() {
  return _data_id;
}

const GUID *ComponentPropDef::id() const {
  return _data_id;
}

void ComponentPropDef::set_id(GUID *value) {
  _data_id = value;
}

kiwi::String *ComponentPropDef::name() {
  return _flags[0] & 2 ? &_data_name : nullptr;
}

const kiwi::String *ComponentPropDef::name() const {
  return _flags[0] & 2 ? &_data_name : nullptr;
}

void ComponentPropDef::set_name(const kiwi::String &value) {
  _flags[0] |= 2; _data_name = value;
}

ComponentPropValue *ComponentPropDef::initialValue() {
  return _data_initialValue;
}

const ComponentPropValue *ComponentPropDef::initialValue() const {
  return _data_initialValue;
}

void ComponentPropDef::set_initialValue(ComponentPropValue *value) {
  _data_initialValue = value;
}

kiwi::String *ComponentPropDef::sortPosition() {
  return _flags[0] & 8 ? &_data_sortPosition : nullptr;
}

const kiwi::String *ComponentPropDef::sortPosition() const {
  return _flags[0] & 8 ? &_data_sortPosition : nullptr;
}

void ComponentPropDef::set_sortPosition(const kiwi::String &value) {
  _flags[0] |= 8; _data_sortPosition = value;
}

GUID *ComponentPropDef::parentPropDefId() {
  return _data_parentPropDefId;
}

const GUID *ComponentPropDef::parentPropDefId() const {
  return _data_parentPropDefId;
}

void ComponentPropDef::set_parentPropDefId(GUID *value) {
  _data_parentPropDefId = value;
}

ComponentPropType *ComponentPropDef::type() {
  return _flags[0] & 32 ? &_data_type : nullptr;
}

const ComponentPropType *ComponentPropDef::type() const {
  return _flags[0] & 32 ? &_data_type : nullptr;
}

void ComponentPropDef::set_type(const ComponentPropType &value) {
  _flags[0] |= 32; _data_type = value;
}

bool *ComponentPropDef::isDeleted() {
  return _flags[0] & 64 ? &_data_isDeleted : nullptr;
}

const bool *ComponentPropDef::isDeleted() const {
  return _flags[0] & 64 ? &_data_isDeleted : nullptr;
}

void ComponentPropDef::set_isDeleted(const bool &value) {
  _flags[0] |= 64; _data_isDeleted = value;
}

ComponentPropPreferredValues *ComponentPropDef::preferredValues() {
  return _data_preferredValues;
}

const ComponentPropPreferredValues *ComponentPropDef::preferredValues() const {
  return _data_preferredValues;
}

void ComponentPropDef::set_preferredValues(ComponentPropPreferredValues *value) {
  _data_preferredValues = value;
}

bool ComponentPropDef::encode(kiwi::ByteBuffer &_bb) {
  if (id() != nullptr) {
    _bb.writeVarUint(1);
    if (!_data_id->encode(_bb)) return false;
  }
  if (name() != nullptr) {
    _bb.writeVarUint(2);
    _bb.writeString(_data_name.c_str());
  }
  if (initialValue() != nullptr) {
    _bb.writeVarUint(3);
    if (!_data_initialValue->encode(_bb)) return false;
  }
  if (sortPosition() != nullptr) {
    _bb.writeVarUint(4);
    _bb.writeString(_data_sortPosition.c_str());
  }
  if (parentPropDefId() != nullptr) {
    _bb.writeVarUint(5);
    if (!_data_parentPropDefId->encode(_bb)) return false;
  }
  if (type() != nullptr) {
    _bb.writeVarUint(6);
    _bb.writeVarUint(static_cast<uint32_t>(_data_type));
  }
  if (isDeleted() != nullptr) {
    _bb.writeVarUint(7);
    _bb.writeByte(_data_isDeleted);
  }
  if (preferredValues() != nullptr) {
    _bb.writeVarUint(8);
    if (!_data_preferredValues->encode(_bb)) return false;
  }
  _bb.writeVarUint(0);
  return true;
}

bool ComponentPropDef::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        _data_id = _pool.allocate<GUID>();
        if (!_data_id->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 2: {
        if (!_bb.readString(_data_name, _pool)) return false;
        set_name(_data_name);
        break;
      }
      case 3: {
        _data_initialValue = _pool.allocate<ComponentPropValue>();
        if (!_data_initialValue->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 4: {
        if (!_bb.readString(_data_sortPosition, _pool)) return false;
        set_sortPosition(_data_sortPosition);
        break;
      }
      case 5: {
        _data_parentPropDefId = _pool.allocate<GUID>();
        if (!_data_parentPropDefId->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 6: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_type))) return false;
        set_type(_data_type);
        break;
      }
      case 7: {
        if (!_bb.readByte(_data_isDeleted)) return false;
        set_isDeleted(_data_isDeleted);
        break;
      }
      case 8: {
        _data_preferredValues = _pool.allocate<ComponentPropPreferredValues>();
        if (!_data_preferredValues->decode(_bb, _pool, _schema)) return false;
        break;
      }
      default: {
        if (!_schema || !_schema->skipComponentPropDefField(_bb, _type)) return false;
        break;
      }
    }
  }
}

bool *ComponentPropValue::boolValue() {
  return _flags[0] & 1 ? &_data_boolValue : nullptr;
}

const bool *ComponentPropValue::boolValue() const {
  return _flags[0] & 1 ? &_data_boolValue : nullptr;
}

void ComponentPropValue::set_boolValue(const bool &value) {
  _flags[0] |= 1; _data_boolValue = value;
}

TextData *ComponentPropValue::textValue() {
  return _data_textValue;
}

const TextData *ComponentPropValue::textValue() const {
  return _data_textValue;
}

void ComponentPropValue::set_textValue(TextData *value) {
  _data_textValue = value;
}

GUID *ComponentPropValue::guidValue() {
  return _data_guidValue;
}

const GUID *ComponentPropValue::guidValue() const {
  return _data_guidValue;
}

void ComponentPropValue::set_guidValue(GUID *value) {
  _data_guidValue = value;
}

bool ComponentPropValue::encode(kiwi::ByteBuffer &_bb) {
  if (boolValue() != nullptr) {
    _bb.writeVarUint(1);
    _bb.writeByte(_data_boolValue);
  }
  if (textValue() != nullptr) {
    _bb.writeVarUint(2);
    if (!_data_textValue->encode(_bb)) return false;
  }
  if (guidValue() != nullptr) {
    _bb.writeVarUint(3);
    if (!_data_guidValue->encode(_bb)) return false;
  }
  _bb.writeVarUint(0);
  return true;
}

bool ComponentPropValue::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        if (!_bb.readByte(_data_boolValue)) return false;
        set_boolValue(_data_boolValue);
        break;
      }
      case 2: {
        _data_textValue = _pool.allocate<TextData>();
        if (!_data_textValue->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 3: {
        _data_guidValue = _pool.allocate<GUID>();
        if (!_data_guidValue->decode(_bb, _pool, _schema)) return false;
        break;
      }
      default: {
        if (!_schema || !_schema->skipComponentPropValueField(_bb, _type)) return false;
        break;
      }
    }
  }
}

kiwi::Array<kiwi::String> *ComponentPropPreferredValues::stringValues() {
  return _flags[0] & 1 ? &_data_stringValues : nullptr;
}

const kiwi::Array<kiwi::String> *ComponentPropPreferredValues::stringValues() const {
  return _flags[0] & 1 ? &_data_stringValues : nullptr;
}

kiwi::Array<kiwi::String> &ComponentPropPreferredValues::set_stringValues(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[0] |= 1; return _data_stringValues = pool.array<kiwi::String>(count);
}

kiwi::Array<InstanceSwapPreferredValue> *ComponentPropPreferredValues::instanceSwapValues() {
  return _flags[0] & 2 ? &_data_instanceSwapValues : nullptr;
}

const kiwi::Array<InstanceSwapPreferredValue> *ComponentPropPreferredValues::instanceSwapValues() const {
  return _flags[0] & 2 ? &_data_instanceSwapValues : nullptr;
}

kiwi::Array<InstanceSwapPreferredValue> &ComponentPropPreferredValues::set_instanceSwapValues(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[0] |= 2; return _data_instanceSwapValues = pool.array<InstanceSwapPreferredValue>(count);
}

bool ComponentPropPreferredValues::encode(kiwi::ByteBuffer &_bb) {
  if (stringValues() != nullptr) {
    _bb.writeVarUint(1);
    _bb.writeVarUint(_data_stringValues.size());
    for (kiwi::String &_it : _data_stringValues) _bb.writeString(_it.c_str());
  }
  if (instanceSwapValues() != nullptr) {
    _bb.writeVarUint(2);
    _bb.writeVarUint(_data_instanceSwapValues.size());
    for (InstanceSwapPreferredValue &_it : _data_instanceSwapValues) if (!_it.encode(_bb)) return false;
  }
  _bb.writeVarUint(0);
  return true;
}

bool ComponentPropPreferredValues::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  uint32_t _count;
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        if (!_bb.readVarUint(_count)) return false;
        for (kiwi::String &_it : set_stringValues(_pool, _count)) if (!_bb.readString(_it, _pool)) return false;
        break;
      }
      case 2: {
        if (!_bb.readVarUint(_count)) return false;
        for (InstanceSwapPreferredValue &_it : set_instanceSwapValues(_pool, _count)) if (!_it.decode(_bb, _pool, _schema)) return false;
        break;
      }
      default: {
        if (!_schema || !_schema->skipComponentPropPreferredValuesField(_bb, _type)) return false;
        break;
      }
    }
  }
}

InstanceSwapPreferredValueType *InstanceSwapPreferredValue::type() {
  return _flags[0] & 1 ? &_data_type : nullptr;
}

const InstanceSwapPreferredValueType *InstanceSwapPreferredValue::type() const {
  return _flags[0] & 1 ? &_data_type : nullptr;
}

void InstanceSwapPreferredValue::set_type(const InstanceSwapPreferredValueType &value) {
  _flags[0] |= 1; _data_type = value;
}

kiwi::String *InstanceSwapPreferredValue::key() {
  return _flags[0] & 2 ? &_data_key : nullptr;
}

const kiwi::String *InstanceSwapPreferredValue::key() const {
  return _flags[0] & 2 ? &_data_key : nullptr;
}

void InstanceSwapPreferredValue::set_key(const kiwi::String &value) {
  _flags[0] |= 2; _data_key = value;
}

bool InstanceSwapPreferredValue::encode(kiwi::ByteBuffer &_bb) {
  if (type() != nullptr) {
    _bb.writeVarUint(1);
    _bb.writeVarUint(static_cast<uint32_t>(_data_type));
  }
  if (key() != nullptr) {
    _bb.writeVarUint(2);
    _bb.writeString(_data_key.c_str());
  }
  _bb.writeVarUint(0);
  return true;
}

bool InstanceSwapPreferredValue::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_type))) return false;
        set_type(_data_type);
        break;
      }
      case 2: {
        if (!_bb.readString(_data_key, _pool)) return false;
        set_key(_data_key);
        break;
      }
      default: {
        if (!_schema || !_schema->skipInstanceSwapPreferredValueField(_bb, _type)) return false;
        break;
      }
    }
  }
}

kiwi::String *WidgetMetadata::pluginID() {
  return _flags[0] & 1 ? &_data_pluginID : nullptr;
}

const kiwi::String *WidgetMetadata::pluginID() const {
  return _flags[0] & 1 ? &_data_pluginID : nullptr;
}

void WidgetMetadata::set_pluginID(const kiwi::String &value) {
  _flags[0] |= 1; _data_pluginID = value;
}

kiwi::String *WidgetMetadata::pluginVersionID() {
  return _flags[0] & 2 ? &_data_pluginVersionID : nullptr;
}

const kiwi::String *WidgetMetadata::pluginVersionID() const {
  return _flags[0] & 2 ? &_data_pluginVersionID : nullptr;
}

void WidgetMetadata::set_pluginVersionID(const kiwi::String &value) {
  _flags[0] |= 2; _data_pluginVersionID = value;
}

kiwi::String *WidgetMetadata::widgetName() {
  return _flags[0] & 4 ? &_data_widgetName : nullptr;
}

const kiwi::String *WidgetMetadata::widgetName() const {
  return _flags[0] & 4 ? &_data_widgetName : nullptr;
}

void WidgetMetadata::set_widgetName(const kiwi::String &value) {
  _flags[0] |= 4; _data_widgetName = value;
}

bool WidgetMetadata::encode(kiwi::ByteBuffer &_bb) {
  if (pluginID() != nullptr) {
    _bb.writeVarUint(1);
    _bb.writeString(_data_pluginID.c_str());
  }
  if (pluginVersionID() != nullptr) {
    _bb.writeVarUint(2);
    _bb.writeString(_data_pluginVersionID.c_str());
  }
  if (widgetName() != nullptr) {
    _bb.writeVarUint(3);
    _bb.writeString(_data_widgetName.c_str());
  }
  _bb.writeVarUint(0);
  return true;
}

bool WidgetMetadata::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        if (!_bb.readString(_data_pluginID, _pool)) return false;
        set_pluginID(_data_pluginID);
        break;
      }
      case 2: {
        if (!_bb.readString(_data_pluginVersionID, _pool)) return false;
        set_pluginVersionID(_data_pluginVersionID);
        break;
      }
      case 3: {
        if (!_bb.readString(_data_widgetName, _pool)) return false;
        set_widgetName(_data_widgetName);
        break;
      }
      default: {
        if (!_schema || !_schema->skipWidgetMetadataField(_bb, _type)) return false;
        break;
      }
    }
  }
}

kiwi::String *WidgetPropertyMenuSelectorOption::option() {
  return _flags[0] & 1 ? &_data_option : nullptr;
}

const kiwi::String *WidgetPropertyMenuSelectorOption::option() const {
  return _flags[0] & 1 ? &_data_option : nullptr;
}

void WidgetPropertyMenuSelectorOption::set_option(const kiwi::String &value) {
  _flags[0] |= 1; _data_option = value;
}

kiwi::String *WidgetPropertyMenuSelectorOption::tooltip() {
  return _flags[0] & 2 ? &_data_tooltip : nullptr;
}

const kiwi::String *WidgetPropertyMenuSelectorOption::tooltip() const {
  return _flags[0] & 2 ? &_data_tooltip : nullptr;
}

void WidgetPropertyMenuSelectorOption::set_tooltip(const kiwi::String &value) {
  _flags[0] |= 2; _data_tooltip = value;
}

bool WidgetPropertyMenuSelectorOption::encode(kiwi::ByteBuffer &_bb) {
  if (option() != nullptr) {
    _bb.writeVarUint(1);
    _bb.writeString(_data_option.c_str());
  }
  if (tooltip() != nullptr) {
    _bb.writeVarUint(2);
    _bb.writeString(_data_tooltip.c_str());
  }
  _bb.writeVarUint(0);
  return true;
}

bool WidgetPropertyMenuSelectorOption::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        if (!_bb.readString(_data_option, _pool)) return false;
        set_option(_data_option);
        break;
      }
      case 2: {
        if (!_bb.readString(_data_tooltip, _pool)) return false;
        set_tooltip(_data_tooltip);
        break;
      }
      default: {
        if (!_schema || !_schema->skipWidgetPropertyMenuSelectorOptionField(_bb, _type)) return false;
        break;
      }
    }
  }
}

kiwi::String *WidgetPropertyMenuItem::propertyName() {
  return _flags[0] & 1 ? &_data_propertyName : nullptr;
}

const kiwi::String *WidgetPropertyMenuItem::propertyName() const {
  return _flags[0] & 1 ? &_data_propertyName : nullptr;
}

void WidgetPropertyMenuItem::set_propertyName(const kiwi::String &value) {
  _flags[0] |= 1; _data_propertyName = value;
}

kiwi::String *WidgetPropertyMenuItem::tooltip() {
  return _flags[0] & 2 ? &_data_tooltip : nullptr;
}

const kiwi::String *WidgetPropertyMenuItem::tooltip() const {
  return _flags[0] & 2 ? &_data_tooltip : nullptr;
}

void WidgetPropertyMenuItem::set_tooltip(const kiwi::String &value) {
  _flags[0] |= 2; _data_tooltip = value;
}

WidgetPropertyMenuItemType *WidgetPropertyMenuItem::itemType() {
  return _flags[0] & 4 ? &_data_itemType : nullptr;
}

const WidgetPropertyMenuItemType *WidgetPropertyMenuItem::itemType() const {
  return _flags[0] & 4 ? &_data_itemType : nullptr;
}

void WidgetPropertyMenuItem::set_itemType(const WidgetPropertyMenuItemType &value) {
  _flags[0] |= 4; _data_itemType = value;
}

kiwi::String *WidgetPropertyMenuItem::icon() {
  return _flags[0] & 8 ? &_data_icon : nullptr;
}

const kiwi::String *WidgetPropertyMenuItem::icon() const {
  return _flags[0] & 8 ? &_data_icon : nullptr;
}

void WidgetPropertyMenuItem::set_icon(const kiwi::String &value) {
  _flags[0] |= 8; _data_icon = value;
}

kiwi::Array<WidgetPropertyMenuSelectorOption> *WidgetPropertyMenuItem::options() {
  return _flags[0] & 16 ? &_data_options : nullptr;
}

const kiwi::Array<WidgetPropertyMenuSelectorOption> *WidgetPropertyMenuItem::options() const {
  return _flags[0] & 16 ? &_data_options : nullptr;
}

kiwi::Array<WidgetPropertyMenuSelectorOption> &WidgetPropertyMenuItem::set_options(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[0] |= 16; return _data_options = pool.array<WidgetPropertyMenuSelectorOption>(count);
}

kiwi::String *WidgetPropertyMenuItem::selectedOption() {
  return _flags[0] & 32 ? &_data_selectedOption : nullptr;
}

const kiwi::String *WidgetPropertyMenuItem::selectedOption() const {
  return _flags[0] & 32 ? &_data_selectedOption : nullptr;
}

void WidgetPropertyMenuItem::set_selectedOption(const kiwi::String &value) {
  _flags[0] |= 32; _data_selectedOption = value;
}

bool *WidgetPropertyMenuItem::isToggled() {
  return _flags[0] & 64 ? &_data_isToggled : nullptr;
}

const bool *WidgetPropertyMenuItem::isToggled() const {
  return _flags[0] & 64 ? &_data_isToggled : nullptr;
}

void WidgetPropertyMenuItem::set_isToggled(const bool &value) {
  _flags[0] |= 64; _data_isToggled = value;
}

kiwi::String *WidgetPropertyMenuItem::href() {
  return _flags[0] & 128 ? &_data_href : nullptr;
}

const kiwi::String *WidgetPropertyMenuItem::href() const {
  return _flags[0] & 128 ? &_data_href : nullptr;
}

void WidgetPropertyMenuItem::set_href(const kiwi::String &value) {
  _flags[0] |= 128; _data_href = value;
}

bool *WidgetPropertyMenuItem::allowCustomColor() {
  return _flags[0] & 256 ? &_data_allowCustomColor : nullptr;
}

const bool *WidgetPropertyMenuItem::allowCustomColor() const {
  return _flags[0] & 256 ? &_data_allowCustomColor : nullptr;
}

void WidgetPropertyMenuItem::set_allowCustomColor(const bool &value) {
  _flags[0] |= 256; _data_allowCustomColor = value;
}

bool WidgetPropertyMenuItem::encode(kiwi::ByteBuffer &_bb) {
  if (propertyName() != nullptr) {
    _bb.writeVarUint(1);
    _bb.writeString(_data_propertyName.c_str());
  }
  if (tooltip() != nullptr) {
    _bb.writeVarUint(2);
    _bb.writeString(_data_tooltip.c_str());
  }
  if (itemType() != nullptr) {
    _bb.writeVarUint(3);
    _bb.writeVarUint(static_cast<uint32_t>(_data_itemType));
  }
  if (icon() != nullptr) {
    _bb.writeVarUint(4);
    _bb.writeString(_data_icon.c_str());
  }
  if (options() != nullptr) {
    _bb.writeVarUint(5);
    _bb.writeVarUint(_data_options.size());
    for (WidgetPropertyMenuSelectorOption &_it : _data_options) if (!_it.encode(_bb)) return false;
  }
  if (selectedOption() != nullptr) {
    _bb.writeVarUint(6);
    _bb.writeString(_data_selectedOption.c_str());
  }
  if (isToggled() != nullptr) {
    _bb.writeVarUint(7);
    _bb.writeByte(_data_isToggled);
  }
  if (href() != nullptr) {
    _bb.writeVarUint(8);
    _bb.writeString(_data_href.c_str());
  }
  if (allowCustomColor() != nullptr) {
    _bb.writeVarUint(9);
    _bb.writeByte(_data_allowCustomColor);
  }
  _bb.writeVarUint(0);
  return true;
}

bool WidgetPropertyMenuItem::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  uint32_t _count;
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        if (!_bb.readString(_data_propertyName, _pool)) return false;
        set_propertyName(_data_propertyName);
        break;
      }
      case 2: {
        if (!_bb.readString(_data_tooltip, _pool)) return false;
        set_tooltip(_data_tooltip);
        break;
      }
      case 3: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_itemType))) return false;
        set_itemType(_data_itemType);
        break;
      }
      case 4: {
        if (!_bb.readString(_data_icon, _pool)) return false;
        set_icon(_data_icon);
        break;
      }
      case 5: {
        if (!_bb.readVarUint(_count)) return false;
        for (WidgetPropertyMenuSelectorOption &_it : set_options(_pool, _count)) if (!_it.decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 6: {
        if (!_bb.readString(_data_selectedOption, _pool)) return false;
        set_selectedOption(_data_selectedOption);
        break;
      }
      case 7: {
        if (!_bb.readByte(_data_isToggled)) return false;
        set_isToggled(_data_isToggled);
        break;
      }
      case 8: {
        if (!_bb.readString(_data_href, _pool)) return false;
        set_href(_data_href);
        break;
      }
      case 9: {
        if (!_bb.readByte(_data_allowCustomColor)) return false;
        set_allowCustomColor(_data_allowCustomColor);
        break;
      }
      default: {
        if (!_schema || !_schema->skipWidgetPropertyMenuItemField(_bb, _type)) return false;
        break;
      }
    }
  }
}

int32_t *InternalDataForTest::testFieldA() {
  return _flags[0] & 1 ? &_data_testFieldA : nullptr;
}

const int32_t *InternalDataForTest::testFieldA() const {
  return _flags[0] & 1 ? &_data_testFieldA : nullptr;
}

void InternalDataForTest::set_testFieldA(const int32_t &value) {
  _flags[0] |= 1; _data_testFieldA = value;
}

bool InternalDataForTest::encode(kiwi::ByteBuffer &_bb) {
  if (testFieldA() != nullptr) {
    _bb.writeVarUint(1);
    _bb.writeVarInt(_data_testFieldA);
  }
  _bb.writeVarUint(0);
  return true;
}

bool InternalDataForTest::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        if (!_bb.readVarInt(_data_testFieldA)) return false;
        set_testFieldA(_data_testFieldA);
        break;
      }
      default: {
        if (!_schema || !_schema->skipInternalDataForTestField(_bb, _type)) return false;
        break;
      }
    }
  }
}

kiwi::String *StateGroupPropertyValueOrder::property() {
  return _flags[0] & 1 ? &_data_property : nullptr;
}

const kiwi::String *StateGroupPropertyValueOrder::property() const {
  return _flags[0] & 1 ? &_data_property : nullptr;
}

void StateGroupPropertyValueOrder::set_property(const kiwi::String &value) {
  _flags[0] |= 1; _data_property = value;
}

kiwi::Array<kiwi::String> *StateGroupPropertyValueOrder::values() {
  return _flags[0] & 2 ? &_data_values : nullptr;
}

const kiwi::Array<kiwi::String> *StateGroupPropertyValueOrder::values() const {
  return _flags[0] & 2 ? &_data_values : nullptr;
}

kiwi::Array<kiwi::String> &StateGroupPropertyValueOrder::set_values(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[0] |= 2; return _data_values = pool.array<kiwi::String>(count);
}

bool StateGroupPropertyValueOrder::encode(kiwi::ByteBuffer &_bb) {
  if (property() != nullptr) {
    _bb.writeVarUint(1);
    _bb.writeString(_data_property.c_str());
  }
  if (values() != nullptr) {
    _bb.writeVarUint(2);
    _bb.writeVarUint(_data_values.size());
    for (kiwi::String &_it : _data_values) _bb.writeString(_it.c_str());
  }
  _bb.writeVarUint(0);
  return true;
}

bool StateGroupPropertyValueOrder::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  uint32_t _count;
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        if (!_bb.readString(_data_property, _pool)) return false;
        set_property(_data_property);
        break;
      }
      case 2: {
        if (!_bb.readVarUint(_count)) return false;
        for (kiwi::String &_it : set_values(_pool, _count)) if (!_bb.readString(_it, _pool)) return false;
        break;
      }
      default: {
        if (!_schema || !_schema->skipStateGroupPropertyValueOrderField(_bb, _type)) return false;
        break;
      }
    }
  }
}

int32_t *TextListData::listID() {
  return _flags[0] & 1 ? &_data_listID : nullptr;
}

const int32_t *TextListData::listID() const {
  return _flags[0] & 1 ? &_data_listID : nullptr;
}

void TextListData::set_listID(const int32_t &value) {
  _flags[0] |= 1; _data_listID = value;
}

BulletType *TextListData::bulletType() {
  return _flags[0] & 2 ? &_data_bulletType : nullptr;
}

const BulletType *TextListData::bulletType() const {
  return _flags[0] & 2 ? &_data_bulletType : nullptr;
}

void TextListData::set_bulletType(const BulletType &value) {
  _flags[0] |= 2; _data_bulletType = value;
}

int32_t *TextListData::indentationLevel() {
  return _flags[0] & 4 ? &_data_indentationLevel : nullptr;
}

const int32_t *TextListData::indentationLevel() const {
  return _flags[0] & 4 ? &_data_indentationLevel : nullptr;
}

void TextListData::set_indentationLevel(const int32_t &value) {
  _flags[0] |= 4; _data_indentationLevel = value;
}

int32_t *TextListData::lineNumber() {
  return _flags[0] & 8 ? &_data_lineNumber : nullptr;
}

const int32_t *TextListData::lineNumber() const {
  return _flags[0] & 8 ? &_data_lineNumber : nullptr;
}

void TextListData::set_lineNumber(const int32_t &value) {
  _flags[0] |= 8; _data_lineNumber = value;
}

bool TextListData::encode(kiwi::ByteBuffer &_bb) {
  if (listID() != nullptr) {
    _bb.writeVarUint(1);
    _bb.writeVarInt(_data_listID);
  }
  if (bulletType() != nullptr) {
    _bb.writeVarUint(2);
    _bb.writeVarUint(static_cast<uint32_t>(_data_bulletType));
  }
  if (indentationLevel() != nullptr) {
    _bb.writeVarUint(3);
    _bb.writeVarInt(_data_indentationLevel);
  }
  if (lineNumber() != nullptr) {
    _bb.writeVarUint(4);
    _bb.writeVarInt(_data_lineNumber);
  }
  _bb.writeVarUint(0);
  return true;
}

bool TextListData::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        if (!_bb.readVarInt(_data_listID)) return false;
        set_listID(_data_listID);
        break;
      }
      case 2: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_bulletType))) return false;
        set_bulletType(_data_bulletType);
        break;
      }
      case 3: {
        if (!_bb.readVarInt(_data_indentationLevel)) return false;
        set_indentationLevel(_data_indentationLevel);
        break;
      }
      case 4: {
        if (!_bb.readVarInt(_data_lineNumber)) return false;
        set_lineNumber(_data_lineNumber);
        break;
      }
      default: {
        if (!_schema || !_schema->skipTextListDataField(_bb, _type)) return false;
        break;
      }
    }
  }
}

LineType *TextLineData::lineType() {
  return _flags[0] & 1 ? &_data_lineType : nullptr;
}

const LineType *TextLineData::lineType() const {
  return _flags[0] & 1 ? &_data_lineType : nullptr;
}

void TextLineData::set_lineType(const LineType &value) {
  _flags[0] |= 1; _data_lineType = value;
}

int32_t *TextLineData::indentationLevel() {
  return _flags[0] & 2 ? &_data_indentationLevel : nullptr;
}

const int32_t *TextLineData::indentationLevel() const {
  return _flags[0] & 2 ? &_data_indentationLevel : nullptr;
}

void TextLineData::set_indentationLevel(const int32_t &value) {
  _flags[0] |= 2; _data_indentationLevel = value;
}

SourceDirectionality *TextLineData::sourceDirectionality() {
  return _flags[0] & 4 ? &_data_sourceDirectionality : nullptr;
}

const SourceDirectionality *TextLineData::sourceDirectionality() const {
  return _flags[0] & 4 ? &_data_sourceDirectionality : nullptr;
}

void TextLineData::set_sourceDirectionality(const SourceDirectionality &value) {
  _flags[0] |= 4; _data_sourceDirectionality = value;
}

Directionality *TextLineData::directionality() {
  return _flags[0] & 8 ? &_data_directionality : nullptr;
}

const Directionality *TextLineData::directionality() const {
  return _flags[0] & 8 ? &_data_directionality : nullptr;
}

void TextLineData::set_directionality(const Directionality &value) {
  _flags[0] |= 8; _data_directionality = value;
}

DirectionalityIntent *TextLineData::directionalityIntent() {
  return _flags[0] & 16 ? &_data_directionalityIntent : nullptr;
}

const DirectionalityIntent *TextLineData::directionalityIntent() const {
  return _flags[0] & 16 ? &_data_directionalityIntent : nullptr;
}

void TextLineData::set_directionalityIntent(const DirectionalityIntent &value) {
  _flags[0] |= 16; _data_directionalityIntent = value;
}

int32_t *TextLineData::downgradeStyleId() {
  return _flags[0] & 32 ? &_data_downgradeStyleId : nullptr;
}

const int32_t *TextLineData::downgradeStyleId() const {
  return _flags[0] & 32 ? &_data_downgradeStyleId : nullptr;
}

void TextLineData::set_downgradeStyleId(const int32_t &value) {
  _flags[0] |= 32; _data_downgradeStyleId = value;
}

int32_t *TextLineData::consistencyStyleId() {
  return _flags[0] & 64 ? &_data_consistencyStyleId : nullptr;
}

const int32_t *TextLineData::consistencyStyleId() const {
  return _flags[0] & 64 ? &_data_consistencyStyleId : nullptr;
}

void TextLineData::set_consistencyStyleId(const int32_t &value) {
  _flags[0] |= 64; _data_consistencyStyleId = value;
}

int32_t *TextLineData::listStartOffset() {
  return _flags[0] & 128 ? &_data_listStartOffset : nullptr;
}

const int32_t *TextLineData::listStartOffset() const {
  return _flags[0] & 128 ? &_data_listStartOffset : nullptr;
}

void TextLineData::set_listStartOffset(const int32_t &value) {
  _flags[0] |= 128; _data_listStartOffset = value;
}

bool *TextLineData::isFirstLineOfList() {
  return _flags[0] & 256 ? &_data_isFirstLineOfList : nullptr;
}

const bool *TextLineData::isFirstLineOfList() const {
  return _flags[0] & 256 ? &_data_isFirstLineOfList : nullptr;
}

void TextLineData::set_isFirstLineOfList(const bool &value) {
  _flags[0] |= 256; _data_isFirstLineOfList = value;
}

bool TextLineData::encode(kiwi::ByteBuffer &_bb) {
  if (lineType() != nullptr) {
    _bb.writeVarUint(1);
    _bb.writeVarUint(static_cast<uint32_t>(_data_lineType));
  }
  if (indentationLevel() != nullptr) {
    _bb.writeVarUint(2);
    _bb.writeVarInt(_data_indentationLevel);
  }
  if (sourceDirectionality() != nullptr) {
    _bb.writeVarUint(9);
    _bb.writeVarUint(static_cast<uint32_t>(_data_sourceDirectionality));
  }
  if (directionality() != nullptr) {
    _bb.writeVarUint(3);
    _bb.writeVarUint(static_cast<uint32_t>(_data_directionality));
  }
  if (directionalityIntent() != nullptr) {
    _bb.writeVarUint(4);
    _bb.writeVarUint(static_cast<uint32_t>(_data_directionalityIntent));
  }
  if (downgradeStyleId() != nullptr) {
    _bb.writeVarUint(5);
    _bb.writeVarInt(_data_downgradeStyleId);
  }
  if (consistencyStyleId() != nullptr) {
    _bb.writeVarUint(6);
    _bb.writeVarInt(_data_consistencyStyleId);
  }
  if (listStartOffset() != nullptr) {
    _bb.writeVarUint(7);
    _bb.writeVarInt(_data_listStartOffset);
  }
  if (isFirstLineOfList() != nullptr) {
    _bb.writeVarUint(8);
    _bb.writeByte(_data_isFirstLineOfList);
  }
  _bb.writeVarUint(0);
  return true;
}

bool TextLineData::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_lineType))) return false;
        set_lineType(_data_lineType);
        break;
      }
      case 2: {
        if (!_bb.readVarInt(_data_indentationLevel)) return false;
        set_indentationLevel(_data_indentationLevel);
        break;
      }
      case 9: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_sourceDirectionality))) return false;
        set_sourceDirectionality(_data_sourceDirectionality);
        break;
      }
      case 3: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_directionality))) return false;
        set_directionality(_data_directionality);
        break;
      }
      case 4: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_directionalityIntent))) return false;
        set_directionalityIntent(_data_directionalityIntent);
        break;
      }
      case 5: {
        if (!_bb.readVarInt(_data_downgradeStyleId)) return false;
        set_downgradeStyleId(_data_downgradeStyleId);
        break;
      }
      case 6: {
        if (!_bb.readVarInt(_data_consistencyStyleId)) return false;
        set_consistencyStyleId(_data_consistencyStyleId);
        break;
      }
      case 7: {
        if (!_bb.readVarInt(_data_listStartOffset)) return false;
        set_listStartOffset(_data_listStartOffset);
        break;
      }
      case 8: {
        if (!_bb.readByte(_data_isFirstLineOfList)) return false;
        set_isFirstLineOfList(_data_isFirstLineOfList);
        break;
      }
      default: {
        if (!_schema || !_schema->skipTextLineDataField(_bb, _type)) return false;
        break;
      }
    }
  }
}

Directionality *DerivedTextLineData::directionality() {
  return _flags[0] & 1 ? &_data_directionality : nullptr;
}

const Directionality *DerivedTextLineData::directionality() const {
  return _flags[0] & 1 ? &_data_directionality : nullptr;
}

void DerivedTextLineData::set_directionality(const Directionality &value) {
  _flags[0] |= 1; _data_directionality = value;
}

bool DerivedTextLineData::encode(kiwi::ByteBuffer &_bb) {
  if (directionality() != nullptr) {
    _bb.writeVarUint(1);
    _bb.writeVarUint(static_cast<uint32_t>(_data_directionality));
  }
  _bb.writeVarUint(0);
  return true;
}

bool DerivedTextLineData::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_directionality))) return false;
        set_directionality(_data_directionality);
        break;
      }
      default: {
        if (!_schema || !_schema->skipDerivedTextLineDataField(_bb, _type)) return false;
        break;
      }
    }
  }
}

GUID *PrototypeInteraction::id() {
  return _data_id;
}

const GUID *PrototypeInteraction::id() const {
  return _data_id;
}

void PrototypeInteraction::set_id(GUID *value) {
  _data_id = value;
}

PrototypeEvent *PrototypeInteraction::event() {
  return _data_event;
}

const PrototypeEvent *PrototypeInteraction::event() const {
  return _data_event;
}

void PrototypeInteraction::set_event(PrototypeEvent *value) {
  _data_event = value;
}

kiwi::Array<PrototypeAction> *PrototypeInteraction::actions() {
  return _flags[0] & 4 ? &_data_actions : nullptr;
}

const kiwi::Array<PrototypeAction> *PrototypeInteraction::actions() const {
  return _flags[0] & 4 ? &_data_actions : nullptr;
}

kiwi::Array<PrototypeAction> &PrototypeInteraction::set_actions(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[0] |= 4; return _data_actions = pool.array<PrototypeAction>(count);
}

bool *PrototypeInteraction::isDeleted() {
  return _flags[0] & 8 ? &_data_isDeleted : nullptr;
}

const bool *PrototypeInteraction::isDeleted() const {
  return _flags[0] & 8 ? &_data_isDeleted : nullptr;
}

void PrototypeInteraction::set_isDeleted(const bool &value) {
  _flags[0] |= 8; _data_isDeleted = value;
}

int32_t *PrototypeInteraction::stateManagementVersion() {
  return _flags[0] & 16 ? &_data_stateManagementVersion : nullptr;
}

const int32_t *PrototypeInteraction::stateManagementVersion() const {
  return _flags[0] & 16 ? &_data_stateManagementVersion : nullptr;
}

void PrototypeInteraction::set_stateManagementVersion(const int32_t &value) {
  _flags[0] |= 16; _data_stateManagementVersion = value;
}

bool PrototypeInteraction::encode(kiwi::ByteBuffer &_bb) {
  if (id() != nullptr) {
    _bb.writeVarUint(1);
    if (!_data_id->encode(_bb)) return false;
  }
  if (event() != nullptr) {
    _bb.writeVarUint(2);
    if (!_data_event->encode(_bb)) return false;
  }
  if (actions() != nullptr) {
    _bb.writeVarUint(3);
    _bb.writeVarUint(_data_actions.size());
    for (PrototypeAction &_it : _data_actions) if (!_it.encode(_bb)) return false;
  }
  if (isDeleted() != nullptr) {
    _bb.writeVarUint(4);
    _bb.writeByte(_data_isDeleted);
  }
  if (stateManagementVersion() != nullptr) {
    _bb.writeVarUint(5);
    _bb.writeVarInt(_data_stateManagementVersion);
  }
  _bb.writeVarUint(0);
  return true;
}

bool PrototypeInteraction::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  uint32_t _count;
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        _data_id = _pool.allocate<GUID>();
        if (!_data_id->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 2: {
        _data_event = _pool.allocate<PrototypeEvent>();
        if (!_data_event->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 3: {
        if (!_bb.readVarUint(_count)) return false;
        for (PrototypeAction &_it : set_actions(_pool, _count)) if (!_it.decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 4: {
        if (!_bb.readByte(_data_isDeleted)) return false;
        set_isDeleted(_data_isDeleted);
        break;
      }
      case 5: {
        if (!_bb.readVarInt(_data_stateManagementVersion)) return false;
        set_stateManagementVersion(_data_stateManagementVersion);
        break;
      }
      default: {
        if (!_schema || !_schema->skipPrototypeInteractionField(_bb, _type)) return false;
        break;
      }
    }
  }
}

InteractionType *PrototypeEvent::interactionType() {
  return _flags[0] & 1 ? &_data_interactionType : nullptr;
}

const InteractionType *PrototypeEvent::interactionType() const {
  return _flags[0] & 1 ? &_data_interactionType : nullptr;
}

void PrototypeEvent::set_interactionType(const InteractionType &value) {
  _flags[0] |= 1; _data_interactionType = value;
}

bool *PrototypeEvent::interactionMaintained() {
  return _flags[0] & 2 ? &_data_interactionMaintained : nullptr;
}

const bool *PrototypeEvent::interactionMaintained() const {
  return _flags[0] & 2 ? &_data_interactionMaintained : nullptr;
}

void PrototypeEvent::set_interactionMaintained(const bool &value) {
  _flags[0] |= 2; _data_interactionMaintained = value;
}

float *PrototypeEvent::interactionDuration() {
  return _flags[0] & 4 ? &_data_interactionDuration : nullptr;
}

const float *PrototypeEvent::interactionDuration() const {
  return _flags[0] & 4 ? &_data_interactionDuration : nullptr;
}

void PrototypeEvent::set_interactionDuration(const float &value) {
  _flags[0] |= 4; _data_interactionDuration = value;
}

KeyTrigger *PrototypeEvent::keyTrigger() {
  return _data_keyTrigger;
}

const KeyTrigger *PrototypeEvent::keyTrigger() const {
  return _data_keyTrigger;
}

void PrototypeEvent::set_keyTrigger(KeyTrigger *value) {
  _data_keyTrigger = value;
}

kiwi::String *PrototypeEvent::voiceEventPhrase() {
  return _flags[0] & 16 ? &_data_voiceEventPhrase : nullptr;
}

const kiwi::String *PrototypeEvent::voiceEventPhrase() const {
  return _flags[0] & 16 ? &_data_voiceEventPhrase : nullptr;
}

void PrototypeEvent::set_voiceEventPhrase(const kiwi::String &value) {
  _flags[0] |= 16; _data_voiceEventPhrase = value;
}

float *PrototypeEvent::transitionTimeout() {
  return _flags[0] & 32 ? &_data_transitionTimeout : nullptr;
}

const float *PrototypeEvent::transitionTimeout() const {
  return _flags[0] & 32 ? &_data_transitionTimeout : nullptr;
}

void PrototypeEvent::set_transitionTimeout(const float &value) {
  _flags[0] |= 32; _data_transitionTimeout = value;
}

float *PrototypeEvent::mediaHitTime() {
  return _flags[0] & 64 ? &_data_mediaHitTime : nullptr;
}

const float *PrototypeEvent::mediaHitTime() const {
  return _flags[0] & 64 ? &_data_mediaHitTime : nullptr;
}

void PrototypeEvent::set_mediaHitTime(const float &value) {
  _flags[0] |= 64; _data_mediaHitTime = value;
}

bool PrototypeEvent::encode(kiwi::ByteBuffer &_bb) {
  if (interactionType() != nullptr) {
    _bb.writeVarUint(1);
    _bb.writeVarUint(static_cast<uint32_t>(_data_interactionType));
  }
  if (interactionMaintained() != nullptr) {
    _bb.writeVarUint(2);
    _bb.writeByte(_data_interactionMaintained);
  }
  if (interactionDuration() != nullptr) {
    _bb.writeVarUint(3);
    _bb.writeVarFloat(_data_interactionDuration);
  }
  if (keyTrigger() != nullptr) {
    _bb.writeVarUint(4);
    if (!_data_keyTrigger->encode(_bb)) return false;
  }
  if (voiceEventPhrase() != nullptr) {
    _bb.writeVarUint(5);
    _bb.writeString(_data_voiceEventPhrase.c_str());
  }
  if (transitionTimeout() != nullptr) {
    _bb.writeVarUint(6);
    _bb.writeVarFloat(_data_transitionTimeout);
  }
  if (mediaHitTime() != nullptr) {
    _bb.writeVarUint(7);
    _bb.writeVarFloat(_data_mediaHitTime);
  }
  _bb.writeVarUint(0);
  return true;
}

bool PrototypeEvent::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_interactionType))) return false;
        set_interactionType(_data_interactionType);
        break;
      }
      case 2: {
        if (!_bb.readByte(_data_interactionMaintained)) return false;
        set_interactionMaintained(_data_interactionMaintained);
        break;
      }
      case 3: {
        if (!_bb.readVarFloat(_data_interactionDuration)) return false;
        set_interactionDuration(_data_interactionDuration);
        break;
      }
      case 4: {
        _data_keyTrigger = _pool.allocate<KeyTrigger>();
        if (!_data_keyTrigger->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 5: {
        if (!_bb.readString(_data_voiceEventPhrase, _pool)) return false;
        set_voiceEventPhrase(_data_voiceEventPhrase);
        break;
      }
      case 6: {
        if (!_bb.readVarFloat(_data_transitionTimeout)) return false;
        set_transitionTimeout(_data_transitionTimeout);
        break;
      }
      case 7: {
        if (!_bb.readVarFloat(_data_mediaHitTime)) return false;
        set_mediaHitTime(_data_mediaHitTime);
        break;
      }
      default: {
        if (!_schema || !_schema->skipPrototypeEventField(_bb, _type)) return false;
        break;
      }
    }
  }
}

VariableID *PrototypeVariableTarget::id() {
  return _data_id;
}

const VariableID *PrototypeVariableTarget::id() const {
  return _data_id;
}

void PrototypeVariableTarget::set_id(VariableID *value) {
  _data_id = value;
}

bool PrototypeVariableTarget::encode(kiwi::ByteBuffer &_bb) {
  if (id() != nullptr) {
    _bb.writeVarUint(1);
    if (!_data_id->encode(_bb)) return false;
  }
  _bb.writeVarUint(0);
  return true;
}

bool PrototypeVariableTarget::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        _data_id = _pool.allocate<VariableID>();
        if (!_data_id->decode(_bb, _pool, _schema)) return false;
        break;
      }
      default: {
        if (!_schema || !_schema->skipPrototypeVariableTargetField(_bb, _type)) return false;
        break;
      }
    }
  }
}

kiwi::Array<PrototypeAction> *ConditionalActions::actions() {
  return _flags[0] & 1 ? &_data_actions : nullptr;
}

const kiwi::Array<PrototypeAction> *ConditionalActions::actions() const {
  return _flags[0] & 1 ? &_data_actions : nullptr;
}

kiwi::Array<PrototypeAction> &ConditionalActions::set_actions(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[0] |= 1; return _data_actions = pool.array<PrototypeAction>(count);
}

VariableData *ConditionalActions::condition() {
  return _data_condition;
}

const VariableData *ConditionalActions::condition() const {
  return _data_condition;
}

void ConditionalActions::set_condition(VariableData *value) {
  _data_condition = value;
}

bool ConditionalActions::encode(kiwi::ByteBuffer &_bb) {
  if (actions() != nullptr) {
    _bb.writeVarUint(1);
    _bb.writeVarUint(_data_actions.size());
    for (PrototypeAction &_it : _data_actions) if (!_it.encode(_bb)) return false;
  }
  if (condition() != nullptr) {
    _bb.writeVarUint(2);
    if (!_data_condition->encode(_bb)) return false;
  }
  _bb.writeVarUint(0);
  return true;
}

bool ConditionalActions::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  uint32_t _count;
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        if (!_bb.readVarUint(_count)) return false;
        for (PrototypeAction &_it : set_actions(_pool, _count)) if (!_it.decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 2: {
        _data_condition = _pool.allocate<VariableData>();
        if (!_data_condition->decode(_bb, _pool, _schema)) return false;
        break;
      }
      default: {
        if (!_schema || !_schema->skipConditionalActionsField(_bb, _type)) return false;
        break;
      }
    }
  }
}

GUID *PrototypeAction::transitionNodeID() {
  return _data_transitionNodeID;
}

const GUID *PrototypeAction::transitionNodeID() const {
  return _data_transitionNodeID;
}

void PrototypeAction::set_transitionNodeID(GUID *value) {
  _data_transitionNodeID = value;
}

TransitionType *PrototypeAction::transitionType() {
  return _flags[0] & 2 ? &_data_transitionType : nullptr;
}

const TransitionType *PrototypeAction::transitionType() const {
  return _flags[0] & 2 ? &_data_transitionType : nullptr;
}

void PrototypeAction::set_transitionType(const TransitionType &value) {
  _flags[0] |= 2; _data_transitionType = value;
}

float *PrototypeAction::transitionDuration() {
  return _flags[0] & 4 ? &_data_transitionDuration : nullptr;
}

const float *PrototypeAction::transitionDuration() const {
  return _flags[0] & 4 ? &_data_transitionDuration : nullptr;
}

void PrototypeAction::set_transitionDuration(const float &value) {
  _flags[0] |= 4; _data_transitionDuration = value;
}

EasingType *PrototypeAction::easingType() {
  return _flags[0] & 8 ? &_data_easingType : nullptr;
}

const EasingType *PrototypeAction::easingType() const {
  return _flags[0] & 8 ? &_data_easingType : nullptr;
}

void PrototypeAction::set_easingType(const EasingType &value) {
  _flags[0] |= 8; _data_easingType = value;
}

float *PrototypeAction::transitionTimeout() {
  return _flags[0] & 16 ? &_data_transitionTimeout : nullptr;
}

const float *PrototypeAction::transitionTimeout() const {
  return _flags[0] & 16 ? &_data_transitionTimeout : nullptr;
}

void PrototypeAction::set_transitionTimeout(const float &value) {
  _flags[0] |= 16; _data_transitionTimeout = value;
}

bool *PrototypeAction::transitionShouldSmartAnimate() {
  return _flags[0] & 32 ? &_data_transitionShouldSmartAnimate : nullptr;
}

const bool *PrototypeAction::transitionShouldSmartAnimate() const {
  return _flags[0] & 32 ? &_data_transitionShouldSmartAnimate : nullptr;
}

void PrototypeAction::set_transitionShouldSmartAnimate(const bool &value) {
  _flags[0] |= 32; _data_transitionShouldSmartAnimate = value;
}

ConnectionType *PrototypeAction::connectionType() {
  return _flags[0] & 64 ? &_data_connectionType : nullptr;
}

const ConnectionType *PrototypeAction::connectionType() const {
  return _flags[0] & 64 ? &_data_connectionType : nullptr;
}

void PrototypeAction::set_connectionType(const ConnectionType &value) {
  _flags[0] |= 64; _data_connectionType = value;
}

kiwi::String *PrototypeAction::connectionURL() {
  return _flags[0] & 128 ? &_data_connectionURL : nullptr;
}

const kiwi::String *PrototypeAction::connectionURL() const {
  return _flags[0] & 128 ? &_data_connectionURL : nullptr;
}

void PrototypeAction::set_connectionURL(const kiwi::String &value) {
  _flags[0] |= 128; _data_connectionURL = value;
}

Vector *PrototypeAction::overlayRelativePosition() {
  return _data_overlayRelativePosition;
}

const Vector *PrototypeAction::overlayRelativePosition() const {
  return _data_overlayRelativePosition;
}

void PrototypeAction::set_overlayRelativePosition(Vector *value) {
  _data_overlayRelativePosition = value;
}

NavigationType *PrototypeAction::navigationType() {
  return _flags[0] & 512 ? &_data_navigationType : nullptr;
}

const NavigationType *PrototypeAction::navigationType() const {
  return _flags[0] & 512 ? &_data_navigationType : nullptr;
}

void PrototypeAction::set_navigationType(const NavigationType &value) {
  _flags[0] |= 512; _data_navigationType = value;
}

bool *PrototypeAction::transitionPreserveScroll() {
  return _flags[0] & 1024 ? &_data_transitionPreserveScroll : nullptr;
}

const bool *PrototypeAction::transitionPreserveScroll() const {
  return _flags[0] & 1024 ? &_data_transitionPreserveScroll : nullptr;
}

void PrototypeAction::set_transitionPreserveScroll(const bool &value) {
  _flags[0] |= 1024; _data_transitionPreserveScroll = value;
}

kiwi::Array<float> *PrototypeAction::easingFunction() {
  return _flags[0] & 2048 ? &_data_easingFunction : nullptr;
}

const kiwi::Array<float> *PrototypeAction::easingFunction() const {
  return _flags[0] & 2048 ? &_data_easingFunction : nullptr;
}

kiwi::Array<float> &PrototypeAction::set_easingFunction(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[0] |= 2048; return _data_easingFunction = pool.array<float>(count);
}

Vector *PrototypeAction::extraScrollOffset() {
  return _data_extraScrollOffset;
}

const Vector *PrototypeAction::extraScrollOffset() const {
  return _data_extraScrollOffset;
}

void PrototypeAction::set_extraScrollOffset(Vector *value) {
  _data_extraScrollOffset = value;
}

GUID *PrototypeAction::targetVariableID() {
  return _data_targetVariableID;
}

const GUID *PrototypeAction::targetVariableID() const {
  return _data_targetVariableID;
}

void PrototypeAction::set_targetVariableID(GUID *value) {
  _data_targetVariableID = value;
}

VariableAnyValue *PrototypeAction::targetVariableValue() {
  return _data_targetVariableValue;
}

const VariableAnyValue *PrototypeAction::targetVariableValue() const {
  return _data_targetVariableValue;
}

void PrototypeAction::set_targetVariableValue(VariableAnyValue *value) {
  _data_targetVariableValue = value;
}

MediaAction *PrototypeAction::mediaAction() {
  return _flags[0] & 32768 ? &_data_mediaAction : nullptr;
}

const MediaAction *PrototypeAction::mediaAction() const {
  return _flags[0] & 32768 ? &_data_mediaAction : nullptr;
}

void PrototypeAction::set_mediaAction(const MediaAction &value) {
  _flags[0] |= 32768; _data_mediaAction = value;
}

bool *PrototypeAction::transitionResetVideoPosition() {
  return _flags[0] & 65536 ? &_data_transitionResetVideoPosition : nullptr;
}

const bool *PrototypeAction::transitionResetVideoPosition() const {
  return _flags[0] & 65536 ? &_data_transitionResetVideoPosition : nullptr;
}

void PrototypeAction::set_transitionResetVideoPosition(const bool &value) {
  _flags[0] |= 65536; _data_transitionResetVideoPosition = value;
}

bool *PrototypeAction::openUrlInNewTab() {
  return _flags[0] & 131072 ? &_data_openUrlInNewTab : nullptr;
}

const bool *PrototypeAction::openUrlInNewTab() const {
  return _flags[0] & 131072 ? &_data_openUrlInNewTab : nullptr;
}

void PrototypeAction::set_openUrlInNewTab(const bool &value) {
  _flags[0] |= 131072; _data_openUrlInNewTab = value;
}

PrototypeVariableTarget *PrototypeAction::targetVariable() {
  return _data_targetVariable;
}

const PrototypeVariableTarget *PrototypeAction::targetVariable() const {
  return _data_targetVariable;
}

void PrototypeAction::set_targetVariable(PrototypeVariableTarget *value) {
  _data_targetVariable = value;
}

VariableData *PrototypeAction::targetVariableData() {
  return _data_targetVariableData;
}

const VariableData *PrototypeAction::targetVariableData() const {
  return _data_targetVariableData;
}

void PrototypeAction::set_targetVariableData(VariableData *value) {
  _data_targetVariableData = value;
}

float *PrototypeAction::mediaSkipToTime() {
  return _flags[0] & 1048576 ? &_data_mediaSkipToTime : nullptr;
}

const float *PrototypeAction::mediaSkipToTime() const {
  return _flags[0] & 1048576 ? &_data_mediaSkipToTime : nullptr;
}

void PrototypeAction::set_mediaSkipToTime(const float &value) {
  _flags[0] |= 1048576; _data_mediaSkipToTime = value;
}

float *PrototypeAction::mediaSkipByAmount() {
  return _flags[0] & 2097152 ? &_data_mediaSkipByAmount : nullptr;
}

const float *PrototypeAction::mediaSkipByAmount() const {
  return _flags[0] & 2097152 ? &_data_mediaSkipByAmount : nullptr;
}

void PrototypeAction::set_mediaSkipByAmount(const float &value) {
  _flags[0] |= 2097152; _data_mediaSkipByAmount = value;
}

kiwi::Array<VariableData> *PrototypeAction::conditions() {
  return _flags[0] & 4194304 ? &_data_conditions : nullptr;
}

const kiwi::Array<VariableData> *PrototypeAction::conditions() const {
  return _flags[0] & 4194304 ? &_data_conditions : nullptr;
}

kiwi::Array<VariableData> &PrototypeAction::set_conditions(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[0] |= 4194304; return _data_conditions = pool.array<VariableData>(count);
}

kiwi::Array<ConditionalActions> *PrototypeAction::conditionalActions() {
  return _flags[0] & 8388608 ? &_data_conditionalActions : nullptr;
}

const kiwi::Array<ConditionalActions> *PrototypeAction::conditionalActions() const {
  return _flags[0] & 8388608 ? &_data_conditionalActions : nullptr;
}

kiwi::Array<ConditionalActions> &PrototypeAction::set_conditionalActions(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[0] |= 8388608; return _data_conditionalActions = pool.array<ConditionalActions>(count);
}

bool *PrototypeAction::transitionResetScrollPosition() {
  return _flags[0] & 16777216 ? &_data_transitionResetScrollPosition : nullptr;
}

const bool *PrototypeAction::transitionResetScrollPosition() const {
  return _flags[0] & 16777216 ? &_data_transitionResetScrollPosition : nullptr;
}

void PrototypeAction::set_transitionResetScrollPosition(const bool &value) {
  _flags[0] |= 16777216; _data_transitionResetScrollPosition = value;
}

bool *PrototypeAction::transitionResetInteractiveComponents() {
  return _flags[0] & 33554432 ? &_data_transitionResetInteractiveComponents : nullptr;
}

const bool *PrototypeAction::transitionResetInteractiveComponents() const {
  return _flags[0] & 33554432 ? &_data_transitionResetInteractiveComponents : nullptr;
}

void PrototypeAction::set_transitionResetInteractiveComponents(const bool &value) {
  _flags[0] |= 33554432; _data_transitionResetInteractiveComponents = value;
}

bool PrototypeAction::encode(kiwi::ByteBuffer &_bb) {
  if (transitionNodeID() != nullptr) {
    _bb.writeVarUint(1);
    if (!_data_transitionNodeID->encode(_bb)) return false;
  }
  if (transitionType() != nullptr) {
    _bb.writeVarUint(2);
    _bb.writeVarUint(static_cast<uint32_t>(_data_transitionType));
  }
  if (transitionDuration() != nullptr) {
    _bb.writeVarUint(3);
    _bb.writeVarFloat(_data_transitionDuration);
  }
  if (easingType() != nullptr) {
    _bb.writeVarUint(4);
    _bb.writeVarUint(static_cast<uint32_t>(_data_easingType));
  }
  if (transitionTimeout() != nullptr) {
    _bb.writeVarUint(5);
    _bb.writeVarFloat(_data_transitionTimeout);
  }
  if (transitionShouldSmartAnimate() != nullptr) {
    _bb.writeVarUint(6);
    _bb.writeByte(_data_transitionShouldSmartAnimate);
  }
  if (connectionType() != nullptr) {
    _bb.writeVarUint(7);
    _bb.writeVarUint(static_cast<uint32_t>(_data_connectionType));
  }
  if (connectionURL() != nullptr) {
    _bb.writeVarUint(8);
    _bb.writeString(_data_connectionURL.c_str());
  }
  if (overlayRelativePosition() != nullptr) {
    _bb.writeVarUint(9);
    if (!_data_overlayRelativePosition->encode(_bb)) return false;
  }
  if (navigationType() != nullptr) {
    _bb.writeVarUint(10);
    _bb.writeVarUint(static_cast<uint32_t>(_data_navigationType));
  }
  if (transitionPreserveScroll() != nullptr) {
    _bb.writeVarUint(11);
    _bb.writeByte(_data_transitionPreserveScroll);
  }
  if (easingFunction() != nullptr) {
    _bb.writeVarUint(12);
    _bb.writeVarUint(_data_easingFunction.size());
    for (float &_it : _data_easingFunction) _bb.writeVarFloat(_it);
  }
  if (extraScrollOffset() != nullptr) {
    _bb.writeVarUint(13);
    if (!_data_extraScrollOffset->encode(_bb)) return false;
  }
  if (targetVariableID() != nullptr) {
    _bb.writeVarUint(14);
    if (!_data_targetVariableID->encode(_bb)) return false;
  }
  if (targetVariableValue() != nullptr) {
    _bb.writeVarUint(15);
    if (!_data_targetVariableValue->encode(_bb)) return false;
  }
  if (mediaAction() != nullptr) {
    _bb.writeVarUint(16);
    _bb.writeVarUint(static_cast<uint32_t>(_data_mediaAction));
  }
  if (transitionResetVideoPosition() != nullptr) {
    _bb.writeVarUint(17);
    _bb.writeByte(_data_transitionResetVideoPosition);
  }
  if (openUrlInNewTab() != nullptr) {
    _bb.writeVarUint(18);
    _bb.writeByte(_data_openUrlInNewTab);
  }
  if (targetVariable() != nullptr) {
    _bb.writeVarUint(19);
    if (!_data_targetVariable->encode(_bb)) return false;
  }
  if (targetVariableData() != nullptr) {
    _bb.writeVarUint(20);
    if (!_data_targetVariableData->encode(_bb)) return false;
  }
  if (mediaSkipToTime() != nullptr) {
    _bb.writeVarUint(21);
    _bb.writeVarFloat(_data_mediaSkipToTime);
  }
  if (mediaSkipByAmount() != nullptr) {
    _bb.writeVarUint(22);
    _bb.writeVarFloat(_data_mediaSkipByAmount);
  }
  if (conditions() != nullptr) {
    _bb.writeVarUint(23);
    _bb.writeVarUint(_data_conditions.size());
    for (VariableData &_it : _data_conditions) if (!_it.encode(_bb)) return false;
  }
  if (conditionalActions() != nullptr) {
    _bb.writeVarUint(24);
    _bb.writeVarUint(_data_conditionalActions.size());
    for (ConditionalActions &_it : _data_conditionalActions) if (!_it.encode(_bb)) return false;
  }
  if (transitionResetScrollPosition() != nullptr) {
    _bb.writeVarUint(25);
    _bb.writeByte(_data_transitionResetScrollPosition);
  }
  if (transitionResetInteractiveComponents() != nullptr) {
    _bb.writeVarUint(26);
    _bb.writeByte(_data_transitionResetInteractiveComponents);
  }
  _bb.writeVarUint(0);
  return true;
}

bool PrototypeAction::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  uint32_t _count;
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        _data_transitionNodeID = _pool.allocate<GUID>();
        if (!_data_transitionNodeID->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 2: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_transitionType))) return false;
        set_transitionType(_data_transitionType);
        break;
      }
      case 3: {
        if (!_bb.readVarFloat(_data_transitionDuration)) return false;
        set_transitionDuration(_data_transitionDuration);
        break;
      }
      case 4: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_easingType))) return false;
        set_easingType(_data_easingType);
        break;
      }
      case 5: {
        if (!_bb.readVarFloat(_data_transitionTimeout)) return false;
        set_transitionTimeout(_data_transitionTimeout);
        break;
      }
      case 6: {
        if (!_bb.readByte(_data_transitionShouldSmartAnimate)) return false;
        set_transitionShouldSmartAnimate(_data_transitionShouldSmartAnimate);
        break;
      }
      case 7: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_connectionType))) return false;
        set_connectionType(_data_connectionType);
        break;
      }
      case 8: {
        if (!_bb.readString(_data_connectionURL, _pool)) return false;
        set_connectionURL(_data_connectionURL);
        break;
      }
      case 9: {
        _data_overlayRelativePosition = _pool.allocate<Vector>();
        if (!_data_overlayRelativePosition->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 10: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_navigationType))) return false;
        set_navigationType(_data_navigationType);
        break;
      }
      case 11: {
        if (!_bb.readByte(_data_transitionPreserveScroll)) return false;
        set_transitionPreserveScroll(_data_transitionPreserveScroll);
        break;
      }
      case 12: {
        if (!_bb.readVarUint(_count)) return false;
        for (float &_it : set_easingFunction(_pool, _count)) if (!_bb.readVarFloat(_it)) return false;
        break;
      }
      case 13: {
        _data_extraScrollOffset = _pool.allocate<Vector>();
        if (!_data_extraScrollOffset->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 14: {
        _data_targetVariableID = _pool.allocate<GUID>();
        if (!_data_targetVariableID->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 15: {
        _data_targetVariableValue = _pool.allocate<VariableAnyValue>();
        if (!_data_targetVariableValue->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 16: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_mediaAction))) return false;
        set_mediaAction(_data_mediaAction);
        break;
      }
      case 17: {
        if (!_bb.readByte(_data_transitionResetVideoPosition)) return false;
        set_transitionResetVideoPosition(_data_transitionResetVideoPosition);
        break;
      }
      case 18: {
        if (!_bb.readByte(_data_openUrlInNewTab)) return false;
        set_openUrlInNewTab(_data_openUrlInNewTab);
        break;
      }
      case 19: {
        _data_targetVariable = _pool.allocate<PrototypeVariableTarget>();
        if (!_data_targetVariable->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 20: {
        _data_targetVariableData = _pool.allocate<VariableData>();
        if (!_data_targetVariableData->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 21: {
        if (!_bb.readVarFloat(_data_mediaSkipToTime)) return false;
        set_mediaSkipToTime(_data_mediaSkipToTime);
        break;
      }
      case 22: {
        if (!_bb.readVarFloat(_data_mediaSkipByAmount)) return false;
        set_mediaSkipByAmount(_data_mediaSkipByAmount);
        break;
      }
      case 23: {
        if (!_bb.readVarUint(_count)) return false;
        for (VariableData &_it : set_conditions(_pool, _count)) if (!_it.decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 24: {
        if (!_bb.readVarUint(_count)) return false;
        for (ConditionalActions &_it : set_conditionalActions(_pool, _count)) if (!_it.decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 25: {
        if (!_bb.readByte(_data_transitionResetScrollPosition)) return false;
        set_transitionResetScrollPosition(_data_transitionResetScrollPosition);
        break;
      }
      case 26: {
        if (!_bb.readByte(_data_transitionResetInteractiveComponents)) return false;
        set_transitionResetInteractiveComponents(_data_transitionResetInteractiveComponents);
        break;
      }
      default: {
        if (!_schema || !_schema->skipPrototypeActionField(_bb, _type)) return false;
        break;
      }
    }
  }
}

kiwi::String *PrototypeStartingPoint::name() {
  return _flags[0] & 1 ? &_data_name : nullptr;
}

const kiwi::String *PrototypeStartingPoint::name() const {
  return _flags[0] & 1 ? &_data_name : nullptr;
}

void PrototypeStartingPoint::set_name(const kiwi::String &value) {
  _flags[0] |= 1; _data_name = value;
}

kiwi::String *PrototypeStartingPoint::description() {
  return _flags[0] & 2 ? &_data_description : nullptr;
}

const kiwi::String *PrototypeStartingPoint::description() const {
  return _flags[0] & 2 ? &_data_description : nullptr;
}

void PrototypeStartingPoint::set_description(const kiwi::String &value) {
  _flags[0] |= 2; _data_description = value;
}

kiwi::String *PrototypeStartingPoint::position() {
  return _flags[0] & 4 ? &_data_position : nullptr;
}

const kiwi::String *PrototypeStartingPoint::position() const {
  return _flags[0] & 4 ? &_data_position : nullptr;
}

void PrototypeStartingPoint::set_position(const kiwi::String &value) {
  _flags[0] |= 4; _data_position = value;
}

bool PrototypeStartingPoint::encode(kiwi::ByteBuffer &_bb) {
  if (name() != nullptr) {
    _bb.writeVarUint(1);
    _bb.writeString(_data_name.c_str());
  }
  if (description() != nullptr) {
    _bb.writeVarUint(2);
    _bb.writeString(_data_description.c_str());
  }
  if (position() != nullptr) {
    _bb.writeVarUint(3);
    _bb.writeString(_data_position.c_str());
  }
  _bb.writeVarUint(0);
  return true;
}

bool PrototypeStartingPoint::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        if (!_bb.readString(_data_name, _pool)) return false;
        set_name(_data_name);
        break;
      }
      case 2: {
        if (!_bb.readString(_data_description, _pool)) return false;
        set_description(_data_description);
        break;
      }
      case 3: {
        if (!_bb.readString(_data_position, _pool)) return false;
        set_position(_data_position);
        break;
      }
      default: {
        if (!_schema || !_schema->skipPrototypeStartingPointField(_bb, _type)) return false;
        break;
      }
    }
  }
}

kiwi::Array<int32_t> *KeyTrigger::keyCodes() {
  return _flags[0] & 1 ? &_data_keyCodes : nullptr;
}

const kiwi::Array<int32_t> *KeyTrigger::keyCodes() const {
  return _flags[0] & 1 ? &_data_keyCodes : nullptr;
}

kiwi::Array<int32_t> &KeyTrigger::set_keyCodes(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[0] |= 1; return _data_keyCodes = pool.array<int32_t>(count);
}

TriggerDevice *KeyTrigger::triggerDevice() {
  return _flags[0] & 2 ? &_data_triggerDevice : nullptr;
}

const TriggerDevice *KeyTrigger::triggerDevice() const {
  return _flags[0] & 2 ? &_data_triggerDevice : nullptr;
}

void KeyTrigger::set_triggerDevice(const TriggerDevice &value) {
  _flags[0] |= 2; _data_triggerDevice = value;
}

bool KeyTrigger::encode(kiwi::ByteBuffer &_bb) {
  if (keyCodes() != nullptr) {
    _bb.writeVarUint(1);
    _bb.writeVarUint(_data_keyCodes.size());
    for (int32_t &_it : _data_keyCodes) _bb.writeVarInt(_it);
  }
  if (triggerDevice() != nullptr) {
    _bb.writeVarUint(2);
    _bb.writeVarUint(static_cast<uint32_t>(_data_triggerDevice));
  }
  _bb.writeVarUint(0);
  return true;
}

bool KeyTrigger::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  uint32_t _count;
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        if (!_bb.readVarUint(_count)) return false;
        for (int32_t &_it : set_keyCodes(_pool, _count)) if (!_bb.readVarInt(_it)) return false;
        break;
      }
      case 2: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_triggerDevice))) return false;
        set_triggerDevice(_data_triggerDevice);
        break;
      }
      default: {
        if (!_schema || !_schema->skipKeyTriggerField(_bb, _type)) return false;
        break;
      }
    }
  }
}

kiwi::String *Hyperlink::url() {
  return _flags[0] & 1 ? &_data_url : nullptr;
}

const kiwi::String *Hyperlink::url() const {
  return _flags[0] & 1 ? &_data_url : nullptr;
}

void Hyperlink::set_url(const kiwi::String &value) {
  _flags[0] |= 1; _data_url = value;
}

GUID *Hyperlink::guid() {
  return _data_guid;
}

const GUID *Hyperlink::guid() const {
  return _data_guid;
}

void Hyperlink::set_guid(GUID *value) {
  _data_guid = value;
}

bool Hyperlink::encode(kiwi::ByteBuffer &_bb) {
  if (url() != nullptr) {
    _bb.writeVarUint(1);
    _bb.writeString(_data_url.c_str());
  }
  if (guid() != nullptr) {
    _bb.writeVarUint(2);
    if (!_data_guid->encode(_bb)) return false;
  }
  _bb.writeVarUint(0);
  return true;
}

bool Hyperlink::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        if (!_bb.readString(_data_url, _pool)) return false;
        set_url(_data_url);
        break;
      }
      case 2: {
        _data_guid = _pool.allocate<GUID>();
        if (!_data_guid->decode(_bb, _pool, _schema)) return false;
        break;
      }
      default: {
        if (!_schema || !_schema->skipHyperlinkField(_bb, _type)) return false;
        break;
      }
    }
  }
}

GUID *Mention::id() {
  return _data_id;
}

const GUID *Mention::id() const {
  return _data_id;
}

void Mention::set_id(GUID *value) {
  _data_id = value;
}

kiwi::String *Mention::mentionedUserId() {
  return _flags[0] & 2 ? &_data_mentionedUserId : nullptr;
}

const kiwi::String *Mention::mentionedUserId() const {
  return _flags[0] & 2 ? &_data_mentionedUserId : nullptr;
}

void Mention::set_mentionedUserId(const kiwi::String &value) {
  _flags[0] |= 2; _data_mentionedUserId = value;
}

kiwi::String *Mention::mentionedByUserId() {
  return _flags[0] & 4 ? &_data_mentionedByUserId : nullptr;
}

const kiwi::String *Mention::mentionedByUserId() const {
  return _flags[0] & 4 ? &_data_mentionedByUserId : nullptr;
}

void Mention::set_mentionedByUserId(const kiwi::String &value) {
  _flags[0] |= 4; _data_mentionedByUserId = value;
}

kiwi::String *Mention::fileKey() {
  return _flags[0] & 8 ? &_data_fileKey : nullptr;
}

const kiwi::String *Mention::fileKey() const {
  return _flags[0] & 8 ? &_data_fileKey : nullptr;
}

void Mention::set_fileKey(const kiwi::String &value) {
  _flags[0] |= 8; _data_fileKey = value;
}

MentionSource *Mention::source() {
  return _flags[0] & 16 ? &_data_source : nullptr;
}

const MentionSource *Mention::source() const {
  return _flags[0] & 16 ? &_data_source : nullptr;
}

void Mention::set_source(const MentionSource &value) {
  _flags[0] |= 16; _data_source = value;
}

bool Mention::encode(kiwi::ByteBuffer &_bb) {
  if (id() != nullptr) {
    _bb.writeVarUint(1);
    if (!_data_id->encode(_bb)) return false;
  }
  if (mentionedUserId() != nullptr) {
    _bb.writeVarUint(2);
    _bb.writeString(_data_mentionedUserId.c_str());
  }
  if (mentionedByUserId() != nullptr) {
    _bb.writeVarUint(3);
    _bb.writeString(_data_mentionedByUserId.c_str());
  }
  if (fileKey() != nullptr) {
    _bb.writeVarUint(4);
    _bb.writeString(_data_fileKey.c_str());
  }
  if (source() != nullptr) {
    _bb.writeVarUint(5);
    _bb.writeVarUint(static_cast<uint32_t>(_data_source));
  }
  _bb.writeVarUint(0);
  return true;
}

bool Mention::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        _data_id = _pool.allocate<GUID>();
        if (!_data_id->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 2: {
        if (!_bb.readString(_data_mentionedUserId, _pool)) return false;
        set_mentionedUserId(_data_mentionedUserId);
        break;
      }
      case 3: {
        if (!_bb.readString(_data_mentionedByUserId, _pool)) return false;
        set_mentionedByUserId(_data_mentionedByUserId);
        break;
      }
      case 4: {
        if (!_bb.readString(_data_fileKey, _pool)) return false;
        set_fileKey(_data_fileKey);
        break;
      }
      case 5: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_source))) return false;
        set_source(_data_source);
        break;
      }
      default: {
        if (!_schema || !_schema->skipMentionField(_bb, _type)) return false;
        break;
      }
    }
  }
}

kiwi::String *EmbedData::url() {
  return _flags[0] & 1 ? &_data_url : nullptr;
}

const kiwi::String *EmbedData::url() const {
  return _flags[0] & 1 ? &_data_url : nullptr;
}

void EmbedData::set_url(const kiwi::String &value) {
  _flags[0] |= 1; _data_url = value;
}

kiwi::String *EmbedData::srcUrl() {
  return _flags[0] & 2 ? &_data_srcUrl : nullptr;
}

const kiwi::String *EmbedData::srcUrl() const {
  return _flags[0] & 2 ? &_data_srcUrl : nullptr;
}

void EmbedData::set_srcUrl(const kiwi::String &value) {
  _flags[0] |= 2; _data_srcUrl = value;
}

kiwi::String *EmbedData::title() {
  return _flags[0] & 4 ? &_data_title : nullptr;
}

const kiwi::String *EmbedData::title() const {
  return _flags[0] & 4 ? &_data_title : nullptr;
}

void EmbedData::set_title(const kiwi::String &value) {
  _flags[0] |= 4; _data_title = value;
}

kiwi::String *EmbedData::thumbnailUrl() {
  return _flags[0] & 8 ? &_data_thumbnailUrl : nullptr;
}

const kiwi::String *EmbedData::thumbnailUrl() const {
  return _flags[0] & 8 ? &_data_thumbnailUrl : nullptr;
}

void EmbedData::set_thumbnailUrl(const kiwi::String &value) {
  _flags[0] |= 8; _data_thumbnailUrl = value;
}

float *EmbedData::width() {
  return _flags[0] & 16 ? &_data_width : nullptr;
}

const float *EmbedData::width() const {
  return _flags[0] & 16 ? &_data_width : nullptr;
}

void EmbedData::set_width(const float &value) {
  _flags[0] |= 16; _data_width = value;
}

float *EmbedData::height() {
  return _flags[0] & 32 ? &_data_height : nullptr;
}

const float *EmbedData::height() const {
  return _flags[0] & 32 ? &_data_height : nullptr;
}

void EmbedData::set_height(const float &value) {
  _flags[0] |= 32; _data_height = value;
}

kiwi::String *EmbedData::embedType() {
  return _flags[0] & 64 ? &_data_embedType : nullptr;
}

const kiwi::String *EmbedData::embedType() const {
  return _flags[0] & 64 ? &_data_embedType : nullptr;
}

void EmbedData::set_embedType(const kiwi::String &value) {
  _flags[0] |= 64; _data_embedType = value;
}

kiwi::String *EmbedData::thumbnailImageHash() {
  return _flags[0] & 128 ? &_data_thumbnailImageHash : nullptr;
}

const kiwi::String *EmbedData::thumbnailImageHash() const {
  return _flags[0] & 128 ? &_data_thumbnailImageHash : nullptr;
}

void EmbedData::set_thumbnailImageHash(const kiwi::String &value) {
  _flags[0] |= 128; _data_thumbnailImageHash = value;
}

kiwi::String *EmbedData::faviconImageHash() {
  return _flags[0] & 256 ? &_data_faviconImageHash : nullptr;
}

const kiwi::String *EmbedData::faviconImageHash() const {
  return _flags[0] & 256 ? &_data_faviconImageHash : nullptr;
}

void EmbedData::set_faviconImageHash(const kiwi::String &value) {
  _flags[0] |= 256; _data_faviconImageHash = value;
}

kiwi::String *EmbedData::provider() {
  return _flags[0] & 512 ? &_data_provider : nullptr;
}

const kiwi::String *EmbedData::provider() const {
  return _flags[0] & 512 ? &_data_provider : nullptr;
}

void EmbedData::set_provider(const kiwi::String &value) {
  _flags[0] |= 512; _data_provider = value;
}

kiwi::String *EmbedData::originalText() {
  return _flags[0] & 1024 ? &_data_originalText : nullptr;
}

const kiwi::String *EmbedData::originalText() const {
  return _flags[0] & 1024 ? &_data_originalText : nullptr;
}

void EmbedData::set_originalText(const kiwi::String &value) {
  _flags[0] |= 1024; _data_originalText = value;
}

kiwi::String *EmbedData::description() {
  return _flags[0] & 2048 ? &_data_description : nullptr;
}

const kiwi::String *EmbedData::description() const {
  return _flags[0] & 2048 ? &_data_description : nullptr;
}

void EmbedData::set_description(const kiwi::String &value) {
  _flags[0] |= 2048; _data_description = value;
}

kiwi::String *EmbedData::embedVersionId() {
  return _flags[0] & 4096 ? &_data_embedVersionId : nullptr;
}

const kiwi::String *EmbedData::embedVersionId() const {
  return _flags[0] & 4096 ? &_data_embedVersionId : nullptr;
}

void EmbedData::set_embedVersionId(const kiwi::String &value) {
  _flags[0] |= 4096; _data_embedVersionId = value;
}

bool EmbedData::encode(kiwi::ByteBuffer &_bb) {
  if (url() != nullptr) {
    _bb.writeVarUint(1);
    _bb.writeString(_data_url.c_str());
  }
  if (srcUrl() != nullptr) {
    _bb.writeVarUint(2);
    _bb.writeString(_data_srcUrl.c_str());
  }
  if (title() != nullptr) {
    _bb.writeVarUint(3);
    _bb.writeString(_data_title.c_str());
  }
  if (thumbnailUrl() != nullptr) {
    _bb.writeVarUint(4);
    _bb.writeString(_data_thumbnailUrl.c_str());
  }
  if (width() != nullptr) {
    _bb.writeVarUint(5);
    _bb.writeVarFloat(_data_width);
  }
  if (height() != nullptr) {
    _bb.writeVarUint(6);
    _bb.writeVarFloat(_data_height);
  }
  if (embedType() != nullptr) {
    _bb.writeVarUint(7);
    _bb.writeString(_data_embedType.c_str());
  }
  if (thumbnailImageHash() != nullptr) {
    _bb.writeVarUint(8);
    _bb.writeString(_data_thumbnailImageHash.c_str());
  }
  if (faviconImageHash() != nullptr) {
    _bb.writeVarUint(9);
    _bb.writeString(_data_faviconImageHash.c_str());
  }
  if (provider() != nullptr) {
    _bb.writeVarUint(10);
    _bb.writeString(_data_provider.c_str());
  }
  if (originalText() != nullptr) {
    _bb.writeVarUint(11);
    _bb.writeString(_data_originalText.c_str());
  }
  if (description() != nullptr) {
    _bb.writeVarUint(12);
    _bb.writeString(_data_description.c_str());
  }
  if (embedVersionId() != nullptr) {
    _bb.writeVarUint(13);
    _bb.writeString(_data_embedVersionId.c_str());
  }
  _bb.writeVarUint(0);
  return true;
}

bool EmbedData::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        if (!_bb.readString(_data_url, _pool)) return false;
        set_url(_data_url);
        break;
      }
      case 2: {
        if (!_bb.readString(_data_srcUrl, _pool)) return false;
        set_srcUrl(_data_srcUrl);
        break;
      }
      case 3: {
        if (!_bb.readString(_data_title, _pool)) return false;
        set_title(_data_title);
        break;
      }
      case 4: {
        if (!_bb.readString(_data_thumbnailUrl, _pool)) return false;
        set_thumbnailUrl(_data_thumbnailUrl);
        break;
      }
      case 5: {
        if (!_bb.readVarFloat(_data_width)) return false;
        set_width(_data_width);
        break;
      }
      case 6: {
        if (!_bb.readVarFloat(_data_height)) return false;
        set_height(_data_height);
        break;
      }
      case 7: {
        if (!_bb.readString(_data_embedType, _pool)) return false;
        set_embedType(_data_embedType);
        break;
      }
      case 8: {
        if (!_bb.readString(_data_thumbnailImageHash, _pool)) return false;
        set_thumbnailImageHash(_data_thumbnailImageHash);
        break;
      }
      case 9: {
        if (!_bb.readString(_data_faviconImageHash, _pool)) return false;
        set_faviconImageHash(_data_faviconImageHash);
        break;
      }
      case 10: {
        if (!_bb.readString(_data_provider, _pool)) return false;
        set_provider(_data_provider);
        break;
      }
      case 11: {
        if (!_bb.readString(_data_originalText, _pool)) return false;
        set_originalText(_data_originalText);
        break;
      }
      case 12: {
        if (!_bb.readString(_data_description, _pool)) return false;
        set_description(_data_description);
        break;
      }
      case 13: {
        if (!_bb.readString(_data_embedVersionId, _pool)) return false;
        set_embedVersionId(_data_embedVersionId);
        break;
      }
      default: {
        if (!_schema || !_schema->skipEmbedDataField(_bb, _type)) return false;
        break;
      }
    }
  }
}

kiwi::String *StampData::userId() {
  return _flags[0] & 1 ? &_data_userId : nullptr;
}

const kiwi::String *StampData::userId() const {
  return _flags[0] & 1 ? &_data_userId : nullptr;
}

void StampData::set_userId(const kiwi::String &value) {
  _flags[0] |= 1; _data_userId = value;
}

kiwi::String *StampData::votingSessionId() {
  return _flags[0] & 2 ? &_data_votingSessionId : nullptr;
}

const kiwi::String *StampData::votingSessionId() const {
  return _flags[0] & 2 ? &_data_votingSessionId : nullptr;
}

void StampData::set_votingSessionId(const kiwi::String &value) {
  _flags[0] |= 2; _data_votingSessionId = value;
}

kiwi::String *StampData::stampedByUserId() {
  return _flags[0] & 4 ? &_data_stampedByUserId : nullptr;
}

const kiwi::String *StampData::stampedByUserId() const {
  return _flags[0] & 4 ? &_data_stampedByUserId : nullptr;
}

void StampData::set_stampedByUserId(const kiwi::String &value) {
  _flags[0] |= 4; _data_stampedByUserId = value;
}

bool StampData::encode(kiwi::ByteBuffer &_bb) {
  if (userId() != nullptr) {
    _bb.writeVarUint(1);
    _bb.writeString(_data_userId.c_str());
  }
  if (votingSessionId() != nullptr) {
    _bb.writeVarUint(2);
    _bb.writeString(_data_votingSessionId.c_str());
  }
  if (stampedByUserId() != nullptr) {
    _bb.writeVarUint(3);
    _bb.writeString(_data_stampedByUserId.c_str());
  }
  _bb.writeVarUint(0);
  return true;
}

bool StampData::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        if (!_bb.readString(_data_userId, _pool)) return false;
        set_userId(_data_userId);
        break;
      }
      case 2: {
        if (!_bb.readString(_data_votingSessionId, _pool)) return false;
        set_votingSessionId(_data_votingSessionId);
        break;
      }
      case 3: {
        if (!_bb.readString(_data_stampedByUserId, _pool)) return false;
        set_stampedByUserId(_data_stampedByUserId);
        break;
      }
      default: {
        if (!_schema || !_schema->skipStampDataField(_bb, _type)) return false;
        break;
      }
    }
  }
}

kiwi::String *LinkPreviewData::url() {
  return _flags[0] & 1 ? &_data_url : nullptr;
}

const kiwi::String *LinkPreviewData::url() const {
  return _flags[0] & 1 ? &_data_url : nullptr;
}

void LinkPreviewData::set_url(const kiwi::String &value) {
  _flags[0] |= 1; _data_url = value;
}

kiwi::String *LinkPreviewData::title() {
  return _flags[0] & 2 ? &_data_title : nullptr;
}

const kiwi::String *LinkPreviewData::title() const {
  return _flags[0] & 2 ? &_data_title : nullptr;
}

void LinkPreviewData::set_title(const kiwi::String &value) {
  _flags[0] |= 2; _data_title = value;
}

kiwi::String *LinkPreviewData::provider() {
  return _flags[0] & 4 ? &_data_provider : nullptr;
}

const kiwi::String *LinkPreviewData::provider() const {
  return _flags[0] & 4 ? &_data_provider : nullptr;
}

void LinkPreviewData::set_provider(const kiwi::String &value) {
  _flags[0] |= 4; _data_provider = value;
}

kiwi::String *LinkPreviewData::description() {
  return _flags[0] & 8 ? &_data_description : nullptr;
}

const kiwi::String *LinkPreviewData::description() const {
  return _flags[0] & 8 ? &_data_description : nullptr;
}

void LinkPreviewData::set_description(const kiwi::String &value) {
  _flags[0] |= 8; _data_description = value;
}

kiwi::String *LinkPreviewData::thumbnailImageHash() {
  return _flags[0] & 16 ? &_data_thumbnailImageHash : nullptr;
}

const kiwi::String *LinkPreviewData::thumbnailImageHash() const {
  return _flags[0] & 16 ? &_data_thumbnailImageHash : nullptr;
}

void LinkPreviewData::set_thumbnailImageHash(const kiwi::String &value) {
  _flags[0] |= 16; _data_thumbnailImageHash = value;
}

kiwi::String *LinkPreviewData::faviconImageHash() {
  return _flags[0] & 32 ? &_data_faviconImageHash : nullptr;
}

const kiwi::String *LinkPreviewData::faviconImageHash() const {
  return _flags[0] & 32 ? &_data_faviconImageHash : nullptr;
}

void LinkPreviewData::set_faviconImageHash(const kiwi::String &value) {
  _flags[0] |= 32; _data_faviconImageHash = value;
}

float *LinkPreviewData::thumbnailImageWidth() {
  return _flags[0] & 64 ? &_data_thumbnailImageWidth : nullptr;
}

const float *LinkPreviewData::thumbnailImageWidth() const {
  return _flags[0] & 64 ? &_data_thumbnailImageWidth : nullptr;
}

void LinkPreviewData::set_thumbnailImageWidth(const float &value) {
  _flags[0] |= 64; _data_thumbnailImageWidth = value;
}

float *LinkPreviewData::thumbnailImageHeight() {
  return _flags[0] & 128 ? &_data_thumbnailImageHeight : nullptr;
}

const float *LinkPreviewData::thumbnailImageHeight() const {
  return _flags[0] & 128 ? &_data_thumbnailImageHeight : nullptr;
}

void LinkPreviewData::set_thumbnailImageHeight(const float &value) {
  _flags[0] |= 128; _data_thumbnailImageHeight = value;
}

bool LinkPreviewData::encode(kiwi::ByteBuffer &_bb) {
  if (url() != nullptr) {
    _bb.writeVarUint(1);
    _bb.writeString(_data_url.c_str());
  }
  if (title() != nullptr) {
    _bb.writeVarUint(2);
    _bb.writeString(_data_title.c_str());
  }
  if (provider() != nullptr) {
    _bb.writeVarUint(3);
    _bb.writeString(_data_provider.c_str());
  }
  if (description() != nullptr) {
    _bb.writeVarUint(4);
    _bb.writeString(_data_description.c_str());
  }
  if (thumbnailImageHash() != nullptr) {
    _bb.writeVarUint(5);
    _bb.writeString(_data_thumbnailImageHash.c_str());
  }
  if (faviconImageHash() != nullptr) {
    _bb.writeVarUint(6);
    _bb.writeString(_data_faviconImageHash.c_str());
  }
  if (thumbnailImageWidth() != nullptr) {
    _bb.writeVarUint(7);
    _bb.writeVarFloat(_data_thumbnailImageWidth);
  }
  if (thumbnailImageHeight() != nullptr) {
    _bb.writeVarUint(8);
    _bb.writeVarFloat(_data_thumbnailImageHeight);
  }
  _bb.writeVarUint(0);
  return true;
}

bool LinkPreviewData::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        if (!_bb.readString(_data_url, _pool)) return false;
        set_url(_data_url);
        break;
      }
      case 2: {
        if (!_bb.readString(_data_title, _pool)) return false;
        set_title(_data_title);
        break;
      }
      case 3: {
        if (!_bb.readString(_data_provider, _pool)) return false;
        set_provider(_data_provider);
        break;
      }
      case 4: {
        if (!_bb.readString(_data_description, _pool)) return false;
        set_description(_data_description);
        break;
      }
      case 5: {
        if (!_bb.readString(_data_thumbnailImageHash, _pool)) return false;
        set_thumbnailImageHash(_data_thumbnailImageHash);
        break;
      }
      case 6: {
        if (!_bb.readString(_data_faviconImageHash, _pool)) return false;
        set_faviconImageHash(_data_faviconImageHash);
        break;
      }
      case 7: {
        if (!_bb.readVarFloat(_data_thumbnailImageWidth)) return false;
        set_thumbnailImageWidth(_data_thumbnailImageWidth);
        break;
      }
      case 8: {
        if (!_bb.readVarFloat(_data_thumbnailImageHeight)) return false;
        set_thumbnailImageHeight(_data_thumbnailImageHeight);
        break;
      }
      default: {
        if (!_schema || !_schema->skipLinkPreviewDataField(_bb, _type)) return false;
        break;
      }
    }
  }
}

Rect *Viewport::canvasSpaceBounds() {
  return _data_canvasSpaceBounds;
}

const Rect *Viewport::canvasSpaceBounds() const {
  return _data_canvasSpaceBounds;
}

void Viewport::set_canvasSpaceBounds(Rect *value) {
  _data_canvasSpaceBounds = value;
}

bool *Viewport::pixelPreview() {
  return _flags[0] & 2 ? &_data_pixelPreview : nullptr;
}

const bool *Viewport::pixelPreview() const {
  return _flags[0] & 2 ? &_data_pixelPreview : nullptr;
}

void Viewport::set_pixelPreview(const bool &value) {
  _flags[0] |= 2; _data_pixelPreview = value;
}

float *Viewport::pixelDensity() {
  return _flags[0] & 4 ? &_data_pixelDensity : nullptr;
}

const float *Viewport::pixelDensity() const {
  return _flags[0] & 4 ? &_data_pixelDensity : nullptr;
}

void Viewport::set_pixelDensity(const float &value) {
  _flags[0] |= 4; _data_pixelDensity = value;
}

GUID *Viewport::canvasGuid() {
  return _data_canvasGuid;
}

const GUID *Viewport::canvasGuid() const {
  return _data_canvasGuid;
}

void Viewport::set_canvasGuid(GUID *value) {
  _data_canvasGuid = value;
}

bool Viewport::encode(kiwi::ByteBuffer &_bb) {
  if (canvasSpaceBounds() != nullptr) {
    _bb.writeVarUint(1);
    if (!_data_canvasSpaceBounds->encode(_bb)) return false;
  }
  if (pixelPreview() != nullptr) {
    _bb.writeVarUint(2);
    _bb.writeByte(_data_pixelPreview);
  }
  if (pixelDensity() != nullptr) {
    _bb.writeVarUint(3);
    _bb.writeVarFloat(_data_pixelDensity);
  }
  if (canvasGuid() != nullptr) {
    _bb.writeVarUint(4);
    if (!_data_canvasGuid->encode(_bb)) return false;
  }
  _bb.writeVarUint(0);
  return true;
}

bool Viewport::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        _data_canvasSpaceBounds = _pool.allocate<Rect>();
        if (!_data_canvasSpaceBounds->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 2: {
        if (!_bb.readByte(_data_pixelPreview)) return false;
        set_pixelPreview(_data_pixelPreview);
        break;
      }
      case 3: {
        if (!_bb.readVarFloat(_data_pixelDensity)) return false;
        set_pixelDensity(_data_pixelDensity);
        break;
      }
      case 4: {
        _data_canvasGuid = _pool.allocate<GUID>();
        if (!_data_canvasGuid->decode(_bb, _pool, _schema)) return false;
        break;
      }
      default: {
        if (!_schema || !_schema->skipViewportField(_bb, _type)) return false;
        break;
      }
    }
  }
}

MouseCursor *Mouse::cursor() {
  return _flags[0] & 1 ? &_data_cursor : nullptr;
}

const MouseCursor *Mouse::cursor() const {
  return _flags[0] & 1 ? &_data_cursor : nullptr;
}

void Mouse::set_cursor(const MouseCursor &value) {
  _flags[0] |= 1; _data_cursor = value;
}

Vector *Mouse::canvasSpaceLocation() {
  return _data_canvasSpaceLocation;
}

const Vector *Mouse::canvasSpaceLocation() const {
  return _data_canvasSpaceLocation;
}

void Mouse::set_canvasSpaceLocation(Vector *value) {
  _data_canvasSpaceLocation = value;
}

Rect *Mouse::canvasSpaceSelectionBox() {
  return _data_canvasSpaceSelectionBox;
}

const Rect *Mouse::canvasSpaceSelectionBox() const {
  return _data_canvasSpaceSelectionBox;
}

void Mouse::set_canvasSpaceSelectionBox(Rect *value) {
  _data_canvasSpaceSelectionBox = value;
}

GUID *Mouse::canvasGuid() {
  return _data_canvasGuid;
}

const GUID *Mouse::canvasGuid() const {
  return _data_canvasGuid;
}

void Mouse::set_canvasGuid(GUID *value) {
  _data_canvasGuid = value;
}

uint32_t *Mouse::cursorHiddenReason() {
  return _flags[0] & 16 ? &_data_cursorHiddenReason : nullptr;
}

const uint32_t *Mouse::cursorHiddenReason() const {
  return _flags[0] & 16 ? &_data_cursorHiddenReason : nullptr;
}

void Mouse::set_cursorHiddenReason(const uint32_t &value) {
  _flags[0] |= 16; _data_cursorHiddenReason = value;
}

bool Mouse::encode(kiwi::ByteBuffer &_bb) {
  if (cursor() != nullptr) {
    _bb.writeVarUint(1);
    _bb.writeVarUint(static_cast<uint32_t>(_data_cursor));
  }
  if (canvasSpaceLocation() != nullptr) {
    _bb.writeVarUint(2);
    if (!_data_canvasSpaceLocation->encode(_bb)) return false;
  }
  if (canvasSpaceSelectionBox() != nullptr) {
    _bb.writeVarUint(3);
    if (!_data_canvasSpaceSelectionBox->encode(_bb)) return false;
  }
  if (canvasGuid() != nullptr) {
    _bb.writeVarUint(4);
    if (!_data_canvasGuid->encode(_bb)) return false;
  }
  if (cursorHiddenReason() != nullptr) {
    _bb.writeVarUint(5);
    _bb.writeVarUint(_data_cursorHiddenReason);
  }
  _bb.writeVarUint(0);
  return true;
}

bool Mouse::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_cursor))) return false;
        set_cursor(_data_cursor);
        break;
      }
      case 2: {
        _data_canvasSpaceLocation = _pool.allocate<Vector>();
        if (!_data_canvasSpaceLocation->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 3: {
        _data_canvasSpaceSelectionBox = _pool.allocate<Rect>();
        if (!_data_canvasSpaceSelectionBox->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 4: {
        _data_canvasGuid = _pool.allocate<GUID>();
        if (!_data_canvasGuid->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 5: {
        if (!_bb.readVarUint(_data_cursorHiddenReason)) return false;
        set_cursorHiddenReason(_data_cursorHiddenReason);
        break;
      }
      default: {
        if (!_schema || !_schema->skipMouseField(_bb, _type)) return false;
        break;
      }
    }
  }
}

uint32_t *Click::id() {
  return _flags[0] & 1 ? &_data_id : nullptr;
}

const uint32_t *Click::id() const {
  return _flags[0] & 1 ? &_data_id : nullptr;
}

void Click::set_id(const uint32_t &value) {
  _flags[0] |= 1; _data_id = value;
}

Vector *Click::point() {
  return _data_point;
}

const Vector *Click::point() const {
  return _data_point;
}

void Click::set_point(Vector *value) {
  _data_point = value;
}

bool Click::encode(kiwi::ByteBuffer &_bb) {
  if (id() == nullptr) return false;
  _bb.writeVarUint(_data_id);
  if (point() == nullptr) return false;
  if (!_data_point->encode(_bb)) return false;
  return true;
}

bool Click::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  if (!_bb.readVarUint(_data_id)) return false;
  set_id(_data_id);
  _data_point = _pool.allocate<Vector>();
  if (!_data_point->decode(_bb, _pool, _schema)) return false;
  return true;
}

GUID *ScrollPosition::node() {
  return _data_node;
}

const GUID *ScrollPosition::node() const {
  return _data_node;
}

void ScrollPosition::set_node(GUID *value) {
  _data_node = value;
}

Vector *ScrollPosition::scrollOffset() {
  return _data_scrollOffset;
}

const Vector *ScrollPosition::scrollOffset() const {
  return _data_scrollOffset;
}

void ScrollPosition::set_scrollOffset(Vector *value) {
  _data_scrollOffset = value;
}

bool ScrollPosition::encode(kiwi::ByteBuffer &_bb) {
  if (node() == nullptr) return false;
  if (!_data_node->encode(_bb)) return false;
  if (scrollOffset() == nullptr) return false;
  if (!_data_scrollOffset->encode(_bb)) return false;
  return true;
}

bool ScrollPosition::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  _data_node = _pool.allocate<GUID>();
  if (!_data_node->decode(_bb, _pool, _schema)) return false;
  _data_scrollOffset = _pool.allocate<Vector>();
  if (!_data_scrollOffset->decode(_bb, _pool, _schema)) return false;
  return true;
}

GUID *TriggeredOverlay::overlayGuid() {
  return _data_overlayGuid;
}

const GUID *TriggeredOverlay::overlayGuid() const {
  return _data_overlayGuid;
}

void TriggeredOverlay::set_overlayGuid(GUID *value) {
  _data_overlayGuid = value;
}

GUID *TriggeredOverlay::hotspotGuid() {
  return _data_hotspotGuid;
}

const GUID *TriggeredOverlay::hotspotGuid() const {
  return _data_hotspotGuid;
}

void TriggeredOverlay::set_hotspotGuid(GUID *value) {
  _data_hotspotGuid = value;
}

GUID *TriggeredOverlay::swapGuid() {
  return _data_swapGuid;
}

const GUID *TriggeredOverlay::swapGuid() const {
  return _data_swapGuid;
}

void TriggeredOverlay::set_swapGuid(GUID *value) {
  _data_swapGuid = value;
}

bool TriggeredOverlay::encode(kiwi::ByteBuffer &_bb) {
  if (overlayGuid() == nullptr) return false;
  if (!_data_overlayGuid->encode(_bb)) return false;
  if (hotspotGuid() == nullptr) return false;
  if (!_data_hotspotGuid->encode(_bb)) return false;
  if (swapGuid() == nullptr) return false;
  if (!_data_swapGuid->encode(_bb)) return false;
  return true;
}

bool TriggeredOverlay::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  _data_overlayGuid = _pool.allocate<GUID>();
  if (!_data_overlayGuid->decode(_bb, _pool, _schema)) return false;
  _data_hotspotGuid = _pool.allocate<GUID>();
  if (!_data_hotspotGuid->decode(_bb, _pool, _schema)) return false;
  _data_swapGuid = _pool.allocate<GUID>();
  if (!_data_swapGuid->decode(_bb, _pool, _schema)) return false;
  return true;
}

GUID *TriggeredOverlayData::overlayGuid() {
  return _data_overlayGuid;
}

const GUID *TriggeredOverlayData::overlayGuid() const {
  return _data_overlayGuid;
}

void TriggeredOverlayData::set_overlayGuid(GUID *value) {
  _data_overlayGuid = value;
}

GUID *TriggeredOverlayData::hotspotGuid() {
  return _data_hotspotGuid;
}

const GUID *TriggeredOverlayData::hotspotGuid() const {
  return _data_hotspotGuid;
}

void TriggeredOverlayData::set_hotspotGuid(GUID *value) {
  _data_hotspotGuid = value;
}

GUID *TriggeredOverlayData::swapGuid() {
  return _data_swapGuid;
}

const GUID *TriggeredOverlayData::swapGuid() const {
  return _data_swapGuid;
}

void TriggeredOverlayData::set_swapGuid(GUID *value) {
  _data_swapGuid = value;
}

GUID *TriggeredOverlayData::prototypeInteractionGuid() {
  return _data_prototypeInteractionGuid;
}

const GUID *TriggeredOverlayData::prototypeInteractionGuid() const {
  return _data_prototypeInteractionGuid;
}

void TriggeredOverlayData::set_prototypeInteractionGuid(GUID *value) {
  _data_prototypeInteractionGuid = value;
}

GUIDPath *TriggeredOverlayData::hotspotBlueprintId() {
  return _data_hotspotBlueprintId;
}

const GUIDPath *TriggeredOverlayData::hotspotBlueprintId() const {
  return _data_hotspotBlueprintId;
}

void TriggeredOverlayData::set_hotspotBlueprintId(GUIDPath *value) {
  _data_hotspotBlueprintId = value;
}

bool TriggeredOverlayData::encode(kiwi::ByteBuffer &_bb) {
  if (overlayGuid() != nullptr) {
    _bb.writeVarUint(1);
    if (!_data_overlayGuid->encode(_bb)) return false;
  }
  if (hotspotGuid() != nullptr) {
    _bb.writeVarUint(2);
    if (!_data_hotspotGuid->encode(_bb)) return false;
  }
  if (swapGuid() != nullptr) {
    _bb.writeVarUint(3);
    if (!_data_swapGuid->encode(_bb)) return false;
  }
  if (prototypeInteractionGuid() != nullptr) {
    _bb.writeVarUint(4);
    if (!_data_prototypeInteractionGuid->encode(_bb)) return false;
  }
  if (hotspotBlueprintId() != nullptr) {
    _bb.writeVarUint(5);
    if (!_data_hotspotBlueprintId->encode(_bb)) return false;
  }
  _bb.writeVarUint(0);
  return true;
}

bool TriggeredOverlayData::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        _data_overlayGuid = _pool.allocate<GUID>();
        if (!_data_overlayGuid->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 2: {
        _data_hotspotGuid = _pool.allocate<GUID>();
        if (!_data_hotspotGuid->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 3: {
        _data_swapGuid = _pool.allocate<GUID>();
        if (!_data_swapGuid->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 4: {
        _data_prototypeInteractionGuid = _pool.allocate<GUID>();
        if (!_data_prototypeInteractionGuid->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 5: {
        _data_hotspotBlueprintId = _pool.allocate<GUIDPath>();
        if (!_data_hotspotBlueprintId->decode(_bb, _pool, _schema)) return false;
        break;
      }
      default: {
        if (!_schema || !_schema->skipTriggeredOverlayDataField(_bb, _type)) return false;
        break;
      }
    }
  }
}

GUID *PresentedState::baseScreenID() {
  return _data_baseScreenID;
}

const GUID *PresentedState::baseScreenID() const {
  return _data_baseScreenID;
}

void PresentedState::set_baseScreenID(GUID *value) {
  _data_baseScreenID = value;
}

kiwi::Array<TriggeredOverlayData> *PresentedState::overlays() {
  return _flags[0] & 2 ? &_data_overlays : nullptr;
}

const kiwi::Array<TriggeredOverlayData> *PresentedState::overlays() const {
  return _flags[0] & 2 ? &_data_overlays : nullptr;
}

kiwi::Array<TriggeredOverlayData> &PresentedState::set_overlays(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[0] |= 2; return _data_overlays = pool.array<TriggeredOverlayData>(count);
}

bool PresentedState::encode(kiwi::ByteBuffer &_bb) {
  if (baseScreenID() != nullptr) {
    _bb.writeVarUint(1);
    if (!_data_baseScreenID->encode(_bb)) return false;
  }
  if (overlays() != nullptr) {
    _bb.writeVarUint(2);
    _bb.writeVarUint(_data_overlays.size());
    for (TriggeredOverlayData &_it : _data_overlays) if (!_it.encode(_bb)) return false;
  }
  _bb.writeVarUint(0);
  return true;
}

bool PresentedState::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  uint32_t _count;
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        _data_baseScreenID = _pool.allocate<GUID>();
        if (!_data_baseScreenID->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 2: {
        if (!_bb.readVarUint(_count)) return false;
        for (TriggeredOverlayData &_it : set_overlays(_pool, _count)) if (!_it.decode(_bb, _pool, _schema)) return false;
        break;
      }
      default: {
        if (!_schema || !_schema->skipPresentedStateField(_bb, _type)) return false;
        break;
      }
    }
  }
}

PresentedState *TopLevelPlaybackChange::oldState() {
  return _data_oldState;
}

const PresentedState *TopLevelPlaybackChange::oldState() const {
  return _data_oldState;
}

void TopLevelPlaybackChange::set_oldState(PresentedState *value) {
  _data_oldState = value;
}

PresentedState *TopLevelPlaybackChange::newState() {
  return _data_newState;
}

const PresentedState *TopLevelPlaybackChange::newState() const {
  return _data_newState;
}

void TopLevelPlaybackChange::set_newState(PresentedState *value) {
  _data_newState = value;
}

GUIDPath *TopLevelPlaybackChange::hotspotBlueprintID() {
  return _data_hotspotBlueprintID;
}

const GUIDPath *TopLevelPlaybackChange::hotspotBlueprintID() const {
  return _data_hotspotBlueprintID;
}

void TopLevelPlaybackChange::set_hotspotBlueprintID(GUIDPath *value) {
  _data_hotspotBlueprintID = value;
}

GUID *TopLevelPlaybackChange::interactionID() {
  return _data_interactionID;
}

const GUID *TopLevelPlaybackChange::interactionID() const {
  return _data_interactionID;
}

void TopLevelPlaybackChange::set_interactionID(GUID *value) {
  _data_interactionID = value;
}

bool *TopLevelPlaybackChange::isHotspotInNewPresentedState() {
  return _flags[0] & 16 ? &_data_isHotspotInNewPresentedState : nullptr;
}

const bool *TopLevelPlaybackChange::isHotspotInNewPresentedState() const {
  return _flags[0] & 16 ? &_data_isHotspotInNewPresentedState : nullptr;
}

void TopLevelPlaybackChange::set_isHotspotInNewPresentedState(const bool &value) {
  _flags[0] |= 16; _data_isHotspotInNewPresentedState = value;
}

TransitionDirection *TopLevelPlaybackChange::direction() {
  return _flags[0] & 32 ? &_data_direction : nullptr;
}

const TransitionDirection *TopLevelPlaybackChange::direction() const {
  return _flags[0] & 32 ? &_data_direction : nullptr;
}

void TopLevelPlaybackChange::set_direction(const TransitionDirection &value) {
  _flags[0] |= 32; _data_direction = value;
}

GUIDPath *TopLevelPlaybackChange::instanceStablePath() {
  return _data_instanceStablePath;
}

const GUIDPath *TopLevelPlaybackChange::instanceStablePath() const {
  return _data_instanceStablePath;
}

void TopLevelPlaybackChange::set_instanceStablePath(GUIDPath *value) {
  _data_instanceStablePath = value;
}

bool TopLevelPlaybackChange::encode(kiwi::ByteBuffer &_bb) {
  if (oldState() != nullptr) {
    _bb.writeVarUint(1);
    if (!_data_oldState->encode(_bb)) return false;
  }
  if (newState() != nullptr) {
    _bb.writeVarUint(2);
    if (!_data_newState->encode(_bb)) return false;
  }
  if (hotspotBlueprintID() != nullptr) {
    _bb.writeVarUint(3);
    if (!_data_hotspotBlueprintID->encode(_bb)) return false;
  }
  if (interactionID() != nullptr) {
    _bb.writeVarUint(4);
    if (!_data_interactionID->encode(_bb)) return false;
  }
  if (isHotspotInNewPresentedState() != nullptr) {
    _bb.writeVarUint(5);
    _bb.writeByte(_data_isHotspotInNewPresentedState);
  }
  if (direction() != nullptr) {
    _bb.writeVarUint(6);
    _bb.writeVarUint(static_cast<uint32_t>(_data_direction));
  }
  if (instanceStablePath() != nullptr) {
    _bb.writeVarUint(7);
    if (!_data_instanceStablePath->encode(_bb)) return false;
  }
  _bb.writeVarUint(0);
  return true;
}

bool TopLevelPlaybackChange::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        _data_oldState = _pool.allocate<PresentedState>();
        if (!_data_oldState->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 2: {
        _data_newState = _pool.allocate<PresentedState>();
        if (!_data_newState->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 3: {
        _data_hotspotBlueprintID = _pool.allocate<GUIDPath>();
        if (!_data_hotspotBlueprintID->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 4: {
        _data_interactionID = _pool.allocate<GUID>();
        if (!_data_interactionID->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 5: {
        if (!_bb.readByte(_data_isHotspotInNewPresentedState)) return false;
        set_isHotspotInNewPresentedState(_data_isHotspotInNewPresentedState);
        break;
      }
      case 6: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_direction))) return false;
        set_direction(_data_direction);
        break;
      }
      case 7: {
        _data_instanceStablePath = _pool.allocate<GUIDPath>();
        if (!_data_instanceStablePath->decode(_bb, _pool, _schema)) return false;
        break;
      }
      default: {
        if (!_schema || !_schema->skipTopLevelPlaybackChangeField(_bb, _type)) return false;
        break;
      }
    }
  }
}

GUID *InstanceStateChange::stateID() {
  return _data_stateID;
}

const GUID *InstanceStateChange::stateID() const {
  return _data_stateID;
}

void InstanceStateChange::set_stateID(GUID *value) {
  _data_stateID = value;
}

GUID *InstanceStateChange::interactionID() {
  return _data_interactionID;
}

const GUID *InstanceStateChange::interactionID() const {
  return _data_interactionID;
}

void InstanceStateChange::set_interactionID(GUID *value) {
  _data_interactionID = value;
}

GUIDPath *InstanceStateChange::hotspotStablePath() {
  return _data_hotspotStablePath;
}

const GUIDPath *InstanceStateChange::hotspotStablePath() const {
  return _data_hotspotStablePath;
}

void InstanceStateChange::set_hotspotStablePath(GUIDPath *value) {
  _data_hotspotStablePath = value;
}

GUIDPath *InstanceStateChange::instanceStablePath() {
  return _data_instanceStablePath;
}

const GUIDPath *InstanceStateChange::instanceStablePath() const {
  return _data_instanceStablePath;
}

void InstanceStateChange::set_instanceStablePath(GUIDPath *value) {
  _data_instanceStablePath = value;
}

PlaybackChangePhase *InstanceStateChange::phase() {
  return _flags[0] & 16 ? &_data_phase : nullptr;
}

const PlaybackChangePhase *InstanceStateChange::phase() const {
  return _flags[0] & 16 ? &_data_phase : nullptr;
}

void InstanceStateChange::set_phase(const PlaybackChangePhase &value) {
  _flags[0] |= 16; _data_phase = value;
}

bool InstanceStateChange::encode(kiwi::ByteBuffer &_bb) {
  if (stateID() != nullptr) {
    _bb.writeVarUint(1);
    if (!_data_stateID->encode(_bb)) return false;
  }
  if (interactionID() != nullptr) {
    _bb.writeVarUint(2);
    if (!_data_interactionID->encode(_bb)) return false;
  }
  if (hotspotStablePath() != nullptr) {
    _bb.writeVarUint(3);
    if (!_data_hotspotStablePath->encode(_bb)) return false;
  }
  if (instanceStablePath() != nullptr) {
    _bb.writeVarUint(4);
    if (!_data_instanceStablePath->encode(_bb)) return false;
  }
  if (phase() != nullptr) {
    _bb.writeVarUint(5);
    _bb.writeVarUint(static_cast<uint32_t>(_data_phase));
  }
  _bb.writeVarUint(0);
  return true;
}

bool InstanceStateChange::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        _data_stateID = _pool.allocate<GUID>();
        if (!_data_stateID->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 2: {
        _data_interactionID = _pool.allocate<GUID>();
        if (!_data_interactionID->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 3: {
        _data_hotspotStablePath = _pool.allocate<GUIDPath>();
        if (!_data_hotspotStablePath->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 4: {
        _data_instanceStablePath = _pool.allocate<GUIDPath>();
        if (!_data_instanceStablePath->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 5: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_phase))) return false;
        set_phase(_data_phase);
        break;
      }
      default: {
        if (!_schema || !_schema->skipInstanceStateChangeField(_bb, _type)) return false;
        break;
      }
    }
  }
}

Rect *TextCursor::selectionBox() {
  return _data_selectionBox;
}

const Rect *TextCursor::selectionBox() const {
  return _data_selectionBox;
}

void TextCursor::set_selectionBox(Rect *value) {
  _data_selectionBox = value;
}

GUID *TextCursor::canvasGuid() {
  return _data_canvasGuid;
}

const GUID *TextCursor::canvasGuid() const {
  return _data_canvasGuid;
}

void TextCursor::set_canvasGuid(GUID *value) {
  _data_canvasGuid = value;
}

GUID *TextCursor::textNodeGuid() {
  return _data_textNodeGuid;
}

const GUID *TextCursor::textNodeGuid() const {
  return _data_textNodeGuid;
}

void TextCursor::set_textNodeGuid(GUID *value) {
  _data_textNodeGuid = value;
}

bool TextCursor::encode(kiwi::ByteBuffer &_bb) {
  if (selectionBox() != nullptr) {
    _bb.writeVarUint(1);
    if (!_data_selectionBox->encode(_bb)) return false;
  }
  if (canvasGuid() != nullptr) {
    _bb.writeVarUint(2);
    if (!_data_canvasGuid->encode(_bb)) return false;
  }
  if (textNodeGuid() != nullptr) {
    _bb.writeVarUint(3);
    if (!_data_textNodeGuid->encode(_bb)) return false;
  }
  _bb.writeVarUint(0);
  return true;
}

bool TextCursor::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        _data_selectionBox = _pool.allocate<Rect>();
        if (!_data_selectionBox->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 2: {
        _data_canvasGuid = _pool.allocate<GUID>();
        if (!_data_canvasGuid->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 3: {
        _data_textNodeGuid = _pool.allocate<GUID>();
        if (!_data_textNodeGuid->decode(_bb, _pool, _schema)) return false;
        break;
      }
      default: {
        if (!_schema || !_schema->skipTextCursorField(_bb, _type)) return false;
        break;
      }
    }
  }
}

kiwi::Array<Rect> *TextSelection::selectionBoxes() {
  return _flags[0] & 1 ? &_data_selectionBoxes : nullptr;
}

const kiwi::Array<Rect> *TextSelection::selectionBoxes() const {
  return _flags[0] & 1 ? &_data_selectionBoxes : nullptr;
}

kiwi::Array<Rect> &TextSelection::set_selectionBoxes(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[0] |= 1; return _data_selectionBoxes = pool.array<Rect>(count);
}

GUID *TextSelection::canvasGuid() {
  return _data_canvasGuid;
}

const GUID *TextSelection::canvasGuid() const {
  return _data_canvasGuid;
}

void TextSelection::set_canvasGuid(GUID *value) {
  _data_canvasGuid = value;
}

GUID *TextSelection::textNodeGuid() {
  return _data_textNodeGuid;
}

const GUID *TextSelection::textNodeGuid() const {
  return _data_textNodeGuid;
}

void TextSelection::set_textNodeGuid(GUID *value) {
  _data_textNodeGuid = value;
}

Vector *TextSelection::textSelectionRange() {
  return _data_textSelectionRange;
}

const Vector *TextSelection::textSelectionRange() const {
  return _data_textSelectionRange;
}

void TextSelection::set_textSelectionRange(Vector *value) {
  _data_textSelectionRange = value;
}

GUID *TextSelection::textNodeOrContainingIfGuid() {
  return _data_textNodeOrContainingIfGuid;
}

const GUID *TextSelection::textNodeOrContainingIfGuid() const {
  return _data_textNodeOrContainingIfGuid;
}

void TextSelection::set_textNodeOrContainingIfGuid(GUID *value) {
  _data_textNodeOrContainingIfGuid = value;
}

GUID *TextSelection::tableCellRowId() {
  return _data_tableCellRowId;
}

const GUID *TextSelection::tableCellRowId() const {
  return _data_tableCellRowId;
}

void TextSelection::set_tableCellRowId(GUID *value) {
  _data_tableCellRowId = value;
}

GUID *TextSelection::tableCellColId() {
  return _data_tableCellColId;
}

const GUID *TextSelection::tableCellColId() const {
  return _data_tableCellColId;
}

void TextSelection::set_tableCellColId(GUID *value) {
  _data_tableCellColId = value;
}

bool TextSelection::encode(kiwi::ByteBuffer &_bb) {
  if (selectionBoxes() != nullptr) {
    _bb.writeVarUint(1);
    _bb.writeVarUint(_data_selectionBoxes.size());
    for (Rect &_it : _data_selectionBoxes) if (!_it.encode(_bb)) return false;
  }
  if (canvasGuid() != nullptr) {
    _bb.writeVarUint(2);
    if (!_data_canvasGuid->encode(_bb)) return false;
  }
  if (textNodeGuid() != nullptr) {
    _bb.writeVarUint(3);
    if (!_data_textNodeGuid->encode(_bb)) return false;
  }
  if (textSelectionRange() != nullptr) {
    _bb.writeVarUint(4);
    if (!_data_textSelectionRange->encode(_bb)) return false;
  }
  if (textNodeOrContainingIfGuid() != nullptr) {
    _bb.writeVarUint(5);
    if (!_data_textNodeOrContainingIfGuid->encode(_bb)) return false;
  }
  if (tableCellRowId() != nullptr) {
    _bb.writeVarUint(6);
    if (!_data_tableCellRowId->encode(_bb)) return false;
  }
  if (tableCellColId() != nullptr) {
    _bb.writeVarUint(7);
    if (!_data_tableCellColId->encode(_bb)) return false;
  }
  _bb.writeVarUint(0);
  return true;
}

bool TextSelection::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  uint32_t _count;
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        if (!_bb.readVarUint(_count)) return false;
        for (Rect &_it : set_selectionBoxes(_pool, _count)) if (!_it.decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 2: {
        _data_canvasGuid = _pool.allocate<GUID>();
        if (!_data_canvasGuid->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 3: {
        _data_textNodeGuid = _pool.allocate<GUID>();
        if (!_data_textNodeGuid->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 4: {
        _data_textSelectionRange = _pool.allocate<Vector>();
        if (!_data_textSelectionRange->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 5: {
        _data_textNodeOrContainingIfGuid = _pool.allocate<GUID>();
        if (!_data_textNodeOrContainingIfGuid->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 6: {
        _data_tableCellRowId = _pool.allocate<GUID>();
        if (!_data_tableCellRowId->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 7: {
        _data_tableCellColId = _pool.allocate<GUID>();
        if (!_data_tableCellColId->decode(_bb, _pool, _schema)) return false;
        break;
      }
      default: {
        if (!_schema || !_schema->skipTextSelectionField(_bb, _type)) return false;
        break;
      }
    }
  }
}

PlaybackChangePhase *PlaybackChangeKeyframe::phase() {
  return _flags[0] & 1 ? &_data_phase : nullptr;
}

const PlaybackChangePhase *PlaybackChangeKeyframe::phase() const {
  return _flags[0] & 1 ? &_data_phase : nullptr;
}

void PlaybackChangeKeyframe::set_phase(const PlaybackChangePhase &value) {
  _flags[0] |= 1; _data_phase = value;
}

float *PlaybackChangeKeyframe::progress() {
  return _flags[0] & 2 ? &_data_progress : nullptr;
}

const float *PlaybackChangeKeyframe::progress() const {
  return _flags[0] & 2 ? &_data_progress : nullptr;
}

void PlaybackChangeKeyframe::set_progress(const float &value) {
  _flags[0] |= 2; _data_progress = value;
}

float *PlaybackChangeKeyframe::timestamp() {
  return _flags[0] & 4 ? &_data_timestamp : nullptr;
}

const float *PlaybackChangeKeyframe::timestamp() const {
  return _flags[0] & 4 ? &_data_timestamp : nullptr;
}

void PlaybackChangeKeyframe::set_timestamp(const float &value) {
  _flags[0] |= 4; _data_timestamp = value;
}

bool PlaybackChangeKeyframe::encode(kiwi::ByteBuffer &_bb) {
  if (phase() != nullptr) {
    _bb.writeVarUint(1);
    _bb.writeVarUint(static_cast<uint32_t>(_data_phase));
  }
  if (progress() != nullptr) {
    _bb.writeVarUint(2);
    _bb.writeVarFloat(_data_progress);
  }
  if (timestamp() != nullptr) {
    _bb.writeVarUint(3);
    _bb.writeVarFloat(_data_timestamp);
  }
  _bb.writeVarUint(0);
  return true;
}

bool PlaybackChangeKeyframe::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_phase))) return false;
        set_phase(_data_phase);
        break;
      }
      case 2: {
        if (!_bb.readVarFloat(_data_progress)) return false;
        set_progress(_data_progress);
        break;
      }
      case 3: {
        if (!_bb.readVarFloat(_data_timestamp)) return false;
        set_timestamp(_data_timestamp);
        break;
      }
      default: {
        if (!_schema || !_schema->skipPlaybackChangeKeyframeField(_bb, _type)) return false;
        break;
      }
    }
  }
}

GUIDPath *StateMapping::stablePath() {
  return _data_stablePath;
}

const GUIDPath *StateMapping::stablePath() const {
  return _data_stablePath;
}

void StateMapping::set_stablePath(GUIDPath *value) {
  _data_stablePath = value;
}

TopLevelPlaybackChange *StateMapping::lastTopLevelChange() {
  return _data_lastTopLevelChange;
}

const TopLevelPlaybackChange *StateMapping::lastTopLevelChange() const {
  return _data_lastTopLevelChange;
}

void StateMapping::set_lastTopLevelChange(TopLevelPlaybackChange *value) {
  _data_lastTopLevelChange = value;
}

PlaybackChangeKeyframe *StateMapping::lastTopLevelChangeStatus() {
  return _data_lastTopLevelChangeStatus;
}

const PlaybackChangeKeyframe *StateMapping::lastTopLevelChangeStatus() const {
  return _data_lastTopLevelChangeStatus;
}

void StateMapping::set_lastTopLevelChangeStatus(PlaybackChangeKeyframe *value) {
  _data_lastTopLevelChangeStatus = value;
}

float *StateMapping::timestamp() {
  return _flags[0] & 8 ? &_data_timestamp : nullptr;
}

const float *StateMapping::timestamp() const {
  return _flags[0] & 8 ? &_data_timestamp : nullptr;
}

void StateMapping::set_timestamp(const float &value) {
  _flags[0] |= 8; _data_timestamp = value;
}

bool StateMapping::encode(kiwi::ByteBuffer &_bb) {
  if (stablePath() != nullptr) {
    _bb.writeVarUint(1);
    if (!_data_stablePath->encode(_bb)) return false;
  }
  if (lastTopLevelChange() != nullptr) {
    _bb.writeVarUint(2);
    if (!_data_lastTopLevelChange->encode(_bb)) return false;
  }
  if (lastTopLevelChangeStatus() != nullptr) {
    _bb.writeVarUint(3);
    if (!_data_lastTopLevelChangeStatus->encode(_bb)) return false;
  }
  if (timestamp() != nullptr) {
    _bb.writeVarUint(4);
    _bb.writeVarFloat(_data_timestamp);
  }
  _bb.writeVarUint(0);
  return true;
}

bool StateMapping::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        _data_stablePath = _pool.allocate<GUIDPath>();
        if (!_data_stablePath->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 2: {
        _data_lastTopLevelChange = _pool.allocate<TopLevelPlaybackChange>();
        if (!_data_lastTopLevelChange->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 3: {
        _data_lastTopLevelChangeStatus = _pool.allocate<PlaybackChangeKeyframe>();
        if (!_data_lastTopLevelChangeStatus->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 4: {
        if (!_bb.readVarFloat(_data_timestamp)) return false;
        set_timestamp(_data_timestamp);
        break;
      }
      default: {
        if (!_schema || !_schema->skipStateMappingField(_bb, _type)) return false;
        break;
      }
    }
  }
}

GUIDPath *ScrollMapping::blueprintID() {
  return _data_blueprintID;
}

const GUIDPath *ScrollMapping::blueprintID() const {
  return _data_blueprintID;
}

void ScrollMapping::set_blueprintID(GUIDPath *value) {
  _data_blueprintID = value;
}

uint32_t *ScrollMapping::overlayIndex() {
  return _flags[0] & 2 ? &_data_overlayIndex : nullptr;
}

const uint32_t *ScrollMapping::overlayIndex() const {
  return _flags[0] & 2 ? &_data_overlayIndex : nullptr;
}

void ScrollMapping::set_overlayIndex(const uint32_t &value) {
  _flags[0] |= 2; _data_overlayIndex = value;
}

Vector *ScrollMapping::scrollOffset() {
  return _data_scrollOffset;
}

const Vector *ScrollMapping::scrollOffset() const {
  return _data_scrollOffset;
}

void ScrollMapping::set_scrollOffset(Vector *value) {
  _data_scrollOffset = value;
}

bool ScrollMapping::encode(kiwi::ByteBuffer &_bb) {
  if (blueprintID() != nullptr) {
    _bb.writeVarUint(1);
    if (!_data_blueprintID->encode(_bb)) return false;
  }
  if (overlayIndex() != nullptr) {
    _bb.writeVarUint(2);
    _bb.writeVarUint(_data_overlayIndex);
  }
  if (scrollOffset() != nullptr) {
    _bb.writeVarUint(3);
    if (!_data_scrollOffset->encode(_bb)) return false;
  }
  _bb.writeVarUint(0);
  return true;
}

bool ScrollMapping::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        _data_blueprintID = _pool.allocate<GUIDPath>();
        if (!_data_blueprintID->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 2: {
        if (!_bb.readVarUint(_data_overlayIndex)) return false;
        set_overlayIndex(_data_overlayIndex);
        break;
      }
      case 3: {
        _data_scrollOffset = _pool.allocate<Vector>();
        if (!_data_scrollOffset->decode(_bb, _pool, _schema)) return false;
        break;
      }
      default: {
        if (!_schema || !_schema->skipScrollMappingField(_bb, _type)) return false;
        break;
      }
    }
  }
}

TopLevelPlaybackChange *PlaybackUpdate::lastTopLevelChange() {
  return _data_lastTopLevelChange;
}

const TopLevelPlaybackChange *PlaybackUpdate::lastTopLevelChange() const {
  return _data_lastTopLevelChange;
}

void PlaybackUpdate::set_lastTopLevelChange(TopLevelPlaybackChange *value) {
  _data_lastTopLevelChange = value;
}

PlaybackChangeKeyframe *PlaybackUpdate::lastTopLevelChangeStatus() {
  return _data_lastTopLevelChangeStatus;
}

const PlaybackChangeKeyframe *PlaybackUpdate::lastTopLevelChangeStatus() const {
  return _data_lastTopLevelChangeStatus;
}

void PlaybackUpdate::set_lastTopLevelChangeStatus(PlaybackChangeKeyframe *value) {
  _data_lastTopLevelChangeStatus = value;
}

kiwi::Array<ScrollMapping> *PlaybackUpdate::scrollMappings() {
  return _flags[0] & 4 ? &_data_scrollMappings : nullptr;
}

const kiwi::Array<ScrollMapping> *PlaybackUpdate::scrollMappings() const {
  return _flags[0] & 4 ? &_data_scrollMappings : nullptr;
}

kiwi::Array<ScrollMapping> &PlaybackUpdate::set_scrollMappings(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[0] |= 4; return _data_scrollMappings = pool.array<ScrollMapping>(count);
}

float *PlaybackUpdate::timestamp() {
  return _flags[0] & 8 ? &_data_timestamp : nullptr;
}

const float *PlaybackUpdate::timestamp() const {
  return _flags[0] & 8 ? &_data_timestamp : nullptr;
}

void PlaybackUpdate::set_timestamp(const float &value) {
  _flags[0] |= 8; _data_timestamp = value;
}

Vector *PlaybackUpdate::pointerLocation() {
  return _data_pointerLocation;
}

const Vector *PlaybackUpdate::pointerLocation() const {
  return _data_pointerLocation;
}

void PlaybackUpdate::set_pointerLocation(Vector *value) {
  _data_pointerLocation = value;
}

bool *PlaybackUpdate::isTopLevelFrameChange() {
  return _flags[0] & 32 ? &_data_isTopLevelFrameChange : nullptr;
}

const bool *PlaybackUpdate::isTopLevelFrameChange() const {
  return _flags[0] & 32 ? &_data_isTopLevelFrameChange : nullptr;
}

void PlaybackUpdate::set_isTopLevelFrameChange(const bool &value) {
  _flags[0] |= 32; _data_isTopLevelFrameChange = value;
}

kiwi::Array<StateMapping> *PlaybackUpdate::stateMappings() {
  return _flags[0] & 64 ? &_data_stateMappings : nullptr;
}

const kiwi::Array<StateMapping> *PlaybackUpdate::stateMappings() const {
  return _flags[0] & 64 ? &_data_stateMappings : nullptr;
}

kiwi::Array<StateMapping> &PlaybackUpdate::set_stateMappings(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[0] |= 64; return _data_stateMappings = pool.array<StateMapping>(count);
}

bool PlaybackUpdate::encode(kiwi::ByteBuffer &_bb) {
  if (lastTopLevelChange() != nullptr) {
    _bb.writeVarUint(1);
    if (!_data_lastTopLevelChange->encode(_bb)) return false;
  }
  if (lastTopLevelChangeStatus() != nullptr) {
    _bb.writeVarUint(2);
    if (!_data_lastTopLevelChangeStatus->encode(_bb)) return false;
  }
  if (scrollMappings() != nullptr) {
    _bb.writeVarUint(3);
    _bb.writeVarUint(_data_scrollMappings.size());
    for (ScrollMapping &_it : _data_scrollMappings) if (!_it.encode(_bb)) return false;
  }
  if (timestamp() != nullptr) {
    _bb.writeVarUint(4);
    _bb.writeVarFloat(_data_timestamp);
  }
  if (pointerLocation() != nullptr) {
    _bb.writeVarUint(5);
    if (!_data_pointerLocation->encode(_bb)) return false;
  }
  if (isTopLevelFrameChange() != nullptr) {
    _bb.writeVarUint(6);
    _bb.writeByte(_data_isTopLevelFrameChange);
  }
  if (stateMappings() != nullptr) {
    _bb.writeVarUint(7);
    _bb.writeVarUint(_data_stateMappings.size());
    for (StateMapping &_it : _data_stateMappings) if (!_it.encode(_bb)) return false;
  }
  _bb.writeVarUint(0);
  return true;
}

bool PlaybackUpdate::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  uint32_t _count;
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        _data_lastTopLevelChange = _pool.allocate<TopLevelPlaybackChange>();
        if (!_data_lastTopLevelChange->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 2: {
        _data_lastTopLevelChangeStatus = _pool.allocate<PlaybackChangeKeyframe>();
        if (!_data_lastTopLevelChangeStatus->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 3: {
        if (!_bb.readVarUint(_count)) return false;
        for (ScrollMapping &_it : set_scrollMappings(_pool, _count)) if (!_it.decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 4: {
        if (!_bb.readVarFloat(_data_timestamp)) return false;
        set_timestamp(_data_timestamp);
        break;
      }
      case 5: {
        _data_pointerLocation = _pool.allocate<Vector>();
        if (!_data_pointerLocation->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 6: {
        if (!_bb.readByte(_data_isTopLevelFrameChange)) return false;
        set_isTopLevelFrameChange(_data_isTopLevelFrameChange);
        break;
      }
      case 7: {
        if (!_bb.readVarUint(_count)) return false;
        for (StateMapping &_it : set_stateMappings(_pool, _count)) if (!_it.decode(_bb, _pool, _schema)) return false;
        break;
      }
      default: {
        if (!_schema || !_schema->skipPlaybackUpdateField(_bb, _type)) return false;
        break;
      }
    }
  }
}

kiwi::String *ChatMessage::text() {
  return _flags[0] & 1 ? &_data_text : nullptr;
}

const kiwi::String *ChatMessage::text() const {
  return _flags[0] & 1 ? &_data_text : nullptr;
}

void ChatMessage::set_text(const kiwi::String &value) {
  _flags[0] |= 1; _data_text = value;
}

kiwi::String *ChatMessage::previousText() {
  return _flags[0] & 2 ? &_data_previousText : nullptr;
}

const kiwi::String *ChatMessage::previousText() const {
  return _flags[0] & 2 ? &_data_previousText : nullptr;
}

void ChatMessage::set_previousText(const kiwi::String &value) {
  _flags[0] |= 2; _data_previousText = value;
}

bool ChatMessage::encode(kiwi::ByteBuffer &_bb) {
  if (text() != nullptr) {
    _bb.writeVarUint(1);
    _bb.writeString(_data_text.c_str());
  }
  if (previousText() != nullptr) {
    _bb.writeVarUint(2);
    _bb.writeString(_data_previousText.c_str());
  }
  _bb.writeVarUint(0);
  return true;
}

bool ChatMessage::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        if (!_bb.readString(_data_text, _pool)) return false;
        set_text(_data_text);
        break;
      }
      case 2: {
        if (!_bb.readString(_data_previousText, _pool)) return false;
        set_previousText(_data_previousText);
        break;
      }
      default: {
        if (!_schema || !_schema->skipChatMessageField(_bb, _type)) return false;
        break;
      }
    }
  }
}

kiwi::String *VoiceMetadata::connectedCallId() {
  return _flags[0] & 1 ? &_data_connectedCallId : nullptr;
}

const kiwi::String *VoiceMetadata::connectedCallId() const {
  return _flags[0] & 1 ? &_data_connectedCallId : nullptr;
}

void VoiceMetadata::set_connectedCallId(const kiwi::String &value) {
  _flags[0] |= 1; _data_connectedCallId = value;
}

bool VoiceMetadata::encode(kiwi::ByteBuffer &_bb) {
  if (connectedCallId() != nullptr) {
    _bb.writeVarUint(1);
    _bb.writeString(_data_connectedCallId.c_str());
  }
  _bb.writeVarUint(0);
  return true;
}

bool VoiceMetadata::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        if (!_bb.readString(_data_connectedCallId, _pool)) return false;
        set_connectedCallId(_data_connectedCallId);
        break;
      }
      default: {
        if (!_schema || !_schema->skipVoiceMetadataField(_bb, _type)) return false;
        break;
      }
    }
  }
}

uint32_t *UserChange::sessionID() {
  return _flags[0] & 1 ? &_data_sessionID : nullptr;
}

const uint32_t *UserChange::sessionID() const {
  return _flags[0] & 1 ? &_data_sessionID : nullptr;
}

void UserChange::set_sessionID(const uint32_t &value) {
  _flags[0] |= 1; _data_sessionID = value;
}

bool *UserChange::connected() {
  return _flags[0] & 2 ? &_data_connected : nullptr;
}

const bool *UserChange::connected() const {
  return _flags[0] & 2 ? &_data_connected : nullptr;
}

void UserChange::set_connected(const bool &value) {
  _flags[0] |= 2; _data_connected = value;
}

kiwi::String *UserChange::name() {
  return _flags[0] & 4 ? &_data_name : nullptr;
}

const kiwi::String *UserChange::name() const {
  return _flags[0] & 4 ? &_data_name : nullptr;
}

void UserChange::set_name(const kiwi::String &value) {
  _flags[0] |= 4; _data_name = value;
}

Color *UserChange::color() {
  return _data_color;
}

const Color *UserChange::color() const {
  return _data_color;
}

void UserChange::set_color(Color *value) {
  _data_color = value;
}

kiwi::String *UserChange::imageURL() {
  return _flags[0] & 16 ? &_data_imageURL : nullptr;
}

const kiwi::String *UserChange::imageURL() const {
  return _flags[0] & 16 ? &_data_imageURL : nullptr;
}

void UserChange::set_imageURL(const kiwi::String &value) {
  _flags[0] |= 16; _data_imageURL = value;
}

Viewport *UserChange::viewport() {
  return _data_viewport;
}

const Viewport *UserChange::viewport() const {
  return _data_viewport;
}

void UserChange::set_viewport(Viewport *value) {
  _data_viewport = value;
}

Mouse *UserChange::mouse() {
  return _data_mouse;
}

const Mouse *UserChange::mouse() const {
  return _data_mouse;
}

void UserChange::set_mouse(Mouse *value) {
  _data_mouse = value;
}

kiwi::Array<GUID> *UserChange::selection() {
  return _flags[0] & 128 ? &_data_selection : nullptr;
}

const kiwi::Array<GUID> *UserChange::selection() const {
  return _flags[0] & 128 ? &_data_selection : nullptr;
}

kiwi::Array<GUID> &UserChange::set_selection(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[0] |= 128; return _data_selection = pool.array<GUID>(count);
}

kiwi::Array<uint32_t> *UserChange::observing() {
  return _flags[0] & 256 ? &_data_observing : nullptr;
}

const kiwi::Array<uint32_t> *UserChange::observing() const {
  return _flags[0] & 256 ? &_data_observing : nullptr;
}

kiwi::Array<uint32_t> &UserChange::set_observing(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[0] |= 256; return _data_observing = pool.array<uint32_t>(count);
}

kiwi::String *UserChange::deviceName() {
  return _flags[0] & 512 ? &_data_deviceName : nullptr;
}

const kiwi::String *UserChange::deviceName() const {
  return _flags[0] & 512 ? &_data_deviceName : nullptr;
}

void UserChange::set_deviceName(const kiwi::String &value) {
  _flags[0] |= 512; _data_deviceName = value;
}

kiwi::Array<Click> *UserChange::recentClicks() {
  return _flags[0] & 1024 ? &_data_recentClicks : nullptr;
}

const kiwi::Array<Click> *UserChange::recentClicks() const {
  return _flags[0] & 1024 ? &_data_recentClicks : nullptr;
}

kiwi::Array<Click> &UserChange::set_recentClicks(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[0] |= 1024; return _data_recentClicks = pool.array<Click>(count);
}

kiwi::Array<ScrollPosition> *UserChange::scrollPositions() {
  return _flags[0] & 2048 ? &_data_scrollPositions : nullptr;
}

const kiwi::Array<ScrollPosition> *UserChange::scrollPositions() const {
  return _flags[0] & 2048 ? &_data_scrollPositions : nullptr;
}

kiwi::Array<ScrollPosition> &UserChange::set_scrollPositions(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[0] |= 2048; return _data_scrollPositions = pool.array<ScrollPosition>(count);
}

kiwi::Array<TriggeredOverlay> *UserChange::triggeredOverlays() {
  return _flags[0] & 4096 ? &_data_triggeredOverlays : nullptr;
}

const kiwi::Array<TriggeredOverlay> *UserChange::triggeredOverlays() const {
  return _flags[0] & 4096 ? &_data_triggeredOverlays : nullptr;
}

kiwi::Array<TriggeredOverlay> &UserChange::set_triggeredOverlays(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[0] |= 4096; return _data_triggeredOverlays = pool.array<TriggeredOverlay>(count);
}

kiwi::String *UserChange::userID() {
  return _flags[0] & 8192 ? &_data_userID : nullptr;
}

const kiwi::String *UserChange::userID() const {
  return _flags[0] & 8192 ? &_data_userID : nullptr;
}

void UserChange::set_userID(const kiwi::String &value) {
  _flags[0] |= 8192; _data_userID = value;
}

GUID *UserChange::lastTriggeredHotspot() {
  return _data_lastTriggeredHotspot;
}

const GUID *UserChange::lastTriggeredHotspot() const {
  return _data_lastTriggeredHotspot;
}

void UserChange::set_lastTriggeredHotspot(GUID *value) {
  _data_lastTriggeredHotspot = value;
}

GUID *UserChange::lastTriggeredPrototypeInteractionID() {
  return _data_lastTriggeredPrototypeInteractionID;
}

const GUID *UserChange::lastTriggeredPrototypeInteractionID() const {
  return _data_lastTriggeredPrototypeInteractionID;
}

void UserChange::set_lastTriggeredPrototypeInteractionID(GUID *value) {
  _data_lastTriggeredPrototypeInteractionID = value;
}

kiwi::Array<TriggeredOverlayData> *UserChange::triggeredOverlaysData() {
  return _flags[0] & 65536 ? &_data_triggeredOverlaysData : nullptr;
}

const kiwi::Array<TriggeredOverlayData> *UserChange::triggeredOverlaysData() const {
  return _flags[0] & 65536 ? &_data_triggeredOverlaysData : nullptr;
}

kiwi::Array<TriggeredOverlayData> &UserChange::set_triggeredOverlaysData(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[0] |= 65536; return _data_triggeredOverlaysData = pool.array<TriggeredOverlayData>(count);
}

kiwi::Array<PlaybackUpdate> *UserChange::playbackUpdates() {
  return _flags[0] & 131072 ? &_data_playbackUpdates : nullptr;
}

const kiwi::Array<PlaybackUpdate> *UserChange::playbackUpdates() const {
  return _flags[0] & 131072 ? &_data_playbackUpdates : nullptr;
}

kiwi::Array<PlaybackUpdate> &UserChange::set_playbackUpdates(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[0] |= 131072; return _data_playbackUpdates = pool.array<PlaybackUpdate>(count);
}

ChatMessage *UserChange::chatMessage() {
  return _data_chatMessage;
}

const ChatMessage *UserChange::chatMessage() const {
  return _data_chatMessage;
}

void UserChange::set_chatMessage(ChatMessage *value) {
  _data_chatMessage = value;
}

VoiceMetadata *UserChange::voiceMetadata() {
  return _data_voiceMetadata;
}

const VoiceMetadata *UserChange::voiceMetadata() const {
  return _data_voiceMetadata;
}

void UserChange::set_voiceMetadata(VoiceMetadata *value) {
  _data_voiceMetadata = value;
}

bool *UserChange::canWrite() {
  return _flags[0] & 1048576 ? &_data_canWrite : nullptr;
}

const bool *UserChange::canWrite() const {
  return _flags[0] & 1048576 ? &_data_canWrite : nullptr;
}

void UserChange::set_canWrite(const bool &value) {
  _flags[0] |= 1048576; _data_canWrite = value;
}

bool *UserChange::highFiveStatus() {
  return _flags[0] & 2097152 ? &_data_highFiveStatus : nullptr;
}

const bool *UserChange::highFiveStatus() const {
  return _flags[0] & 2097152 ? &_data_highFiveStatus : nullptr;
}

void UserChange::set_highFiveStatus(const bool &value) {
  _flags[0] |= 2097152; _data_highFiveStatus = value;
}

kiwi::Array<InstanceStateChange> *UserChange::instanceStateChanges() {
  return _flags[0] & 4194304 ? &_data_instanceStateChanges : nullptr;
}

const kiwi::Array<InstanceStateChange> *UserChange::instanceStateChanges() const {
  return _flags[0] & 4194304 ? &_data_instanceStateChanges : nullptr;
}

kiwi::Array<InstanceStateChange> &UserChange::set_instanceStateChanges(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[0] |= 4194304; return _data_instanceStateChanges = pool.array<InstanceStateChange>(count);
}

TextCursor *UserChange::textCursor() {
  return _data_textCursor;
}

const TextCursor *UserChange::textCursor() const {
  return _data_textCursor;
}

void UserChange::set_textCursor(TextCursor *value) {
  _data_textCursor = value;
}

TextSelection *UserChange::textSelection() {
  return _data_textSelection;
}

const TextSelection *UserChange::textSelection() const {
  return _data_textSelection;
}

void UserChange::set_textSelection(TextSelection *value) {
  _data_textSelection = value;
}

uint32_t *UserChange::connectedAtTimeS() {
  return _flags[0] & 33554432 ? &_data_connectedAtTimeS : nullptr;
}

const uint32_t *UserChange::connectedAtTimeS() const {
  return _flags[0] & 33554432 ? &_data_connectedAtTimeS : nullptr;
}

void UserChange::set_connectedAtTimeS(const uint32_t &value) {
  _flags[0] |= 33554432; _data_connectedAtTimeS = value;
}

bool *UserChange::focusOnTextCursor() {
  return _flags[0] & 67108864 ? &_data_focusOnTextCursor : nullptr;
}

const bool *UserChange::focusOnTextCursor() const {
  return _flags[0] & 67108864 ? &_data_focusOnTextCursor : nullptr;
}

void UserChange::set_focusOnTextCursor(const bool &value) {
  _flags[0] |= 67108864; _data_focusOnTextCursor = value;
}

Heartbeat *UserChange::heartbeat() {
  return _flags[0] & 134217728 ? &_data_heartbeat : nullptr;
}

const Heartbeat *UserChange::heartbeat() const {
  return _flags[0] & 134217728 ? &_data_heartbeat : nullptr;
}

void UserChange::set_heartbeat(const Heartbeat &value) {
  _flags[0] |= 134217728; _data_heartbeat = value;
}

bool UserChange::encode(kiwi::ByteBuffer &_bb) {
  if (sessionID() != nullptr) {
    _bb.writeVarUint(1);
    _bb.writeVarUint(_data_sessionID);
  }
  if (connected() != nullptr) {
    _bb.writeVarUint(2);
    _bb.writeByte(_data_connected);
  }
  if (name() != nullptr) {
    _bb.writeVarUint(3);
    _bb.writeString(_data_name.c_str());
  }
  if (color() != nullptr) {
    _bb.writeVarUint(4);
    if (!_data_color->encode(_bb)) return false;
  }
  if (imageURL() != nullptr) {
    _bb.writeVarUint(5);
    _bb.writeString(_data_imageURL.c_str());
  }
  if (viewport() != nullptr) {
    _bb.writeVarUint(6);
    if (!_data_viewport->encode(_bb)) return false;
  }
  if (mouse() != nullptr) {
    _bb.writeVarUint(7);
    if (!_data_mouse->encode(_bb)) return false;
  }
  if (selection() != nullptr) {
    _bb.writeVarUint(8);
    _bb.writeVarUint(_data_selection.size());
    for (GUID &_it : _data_selection) if (!_it.encode(_bb)) return false;
  }
  if (observing() != nullptr) {
    _bb.writeVarUint(9);
    _bb.writeVarUint(_data_observing.size());
    for (uint32_t &_it : _data_observing) _bb.writeVarUint(_it);
  }
  if (deviceName() != nullptr) {
    _bb.writeVarUint(10);
    _bb.writeString(_data_deviceName.c_str());
  }
  if (recentClicks() != nullptr) {
    _bb.writeVarUint(11);
    _bb.writeVarUint(_data_recentClicks.size());
    for (Click &_it : _data_recentClicks) if (!_it.encode(_bb)) return false;
  }
  if (scrollPositions() != nullptr) {
    _bb.writeVarUint(12);
    _bb.writeVarUint(_data_scrollPositions.size());
    for (ScrollPosition &_it : _data_scrollPositions) if (!_it.encode(_bb)) return false;
  }
  if (triggeredOverlays() != nullptr) {
    _bb.writeVarUint(13);
    _bb.writeVarUint(_data_triggeredOverlays.size());
    for (TriggeredOverlay &_it : _data_triggeredOverlays) if (!_it.encode(_bb)) return false;
  }
  if (userID() != nullptr) {
    _bb.writeVarUint(14);
    _bb.writeString(_data_userID.c_str());
  }
  if (lastTriggeredHotspot() != nullptr) {
    _bb.writeVarUint(15);
    if (!_data_lastTriggeredHotspot->encode(_bb)) return false;
  }
  if (lastTriggeredPrototypeInteractionID() != nullptr) {
    _bb.writeVarUint(16);
    if (!_data_lastTriggeredPrototypeInteractionID->encode(_bb)) return false;
  }
  if (triggeredOverlaysData() != nullptr) {
    _bb.writeVarUint(17);
    _bb.writeVarUint(_data_triggeredOverlaysData.size());
    for (TriggeredOverlayData &_it : _data_triggeredOverlaysData) if (!_it.encode(_bb)) return false;
  }
  if (playbackUpdates() != nullptr) {
    _bb.writeVarUint(18);
    _bb.writeVarUint(_data_playbackUpdates.size());
    for (PlaybackUpdate &_it : _data_playbackUpdates) if (!_it.encode(_bb)) return false;
  }
  if (chatMessage() != nullptr) {
    _bb.writeVarUint(19);
    if (!_data_chatMessage->encode(_bb)) return false;
  }
  if (voiceMetadata() != nullptr) {
    _bb.writeVarUint(20);
    if (!_data_voiceMetadata->encode(_bb)) return false;
  }
  if (canWrite() != nullptr) {
    _bb.writeVarUint(21);
    _bb.writeByte(_data_canWrite);
  }
  if (highFiveStatus() != nullptr) {
    _bb.writeVarUint(22);
    _bb.writeByte(_data_highFiveStatus);
  }
  if (instanceStateChanges() != nullptr) {
    _bb.writeVarUint(23);
    _bb.writeVarUint(_data_instanceStateChanges.size());
    for (InstanceStateChange &_it : _data_instanceStateChanges) if (!_it.encode(_bb)) return false;
  }
  if (textCursor() != nullptr) {
    _bb.writeVarUint(24);
    if (!_data_textCursor->encode(_bb)) return false;
  }
  if (textSelection() != nullptr) {
    _bb.writeVarUint(25);
    if (!_data_textSelection->encode(_bb)) return false;
  }
  if (connectedAtTimeS() != nullptr) {
    _bb.writeVarUint(26);
    _bb.writeVarUint(_data_connectedAtTimeS);
  }
  if (focusOnTextCursor() != nullptr) {
    _bb.writeVarUint(27);
    _bb.writeByte(_data_focusOnTextCursor);
  }
  if (heartbeat() != nullptr) {
    _bb.writeVarUint(28);
    _bb.writeVarUint(static_cast<uint32_t>(_data_heartbeat));
  }
  _bb.writeVarUint(0);
  return true;
}

bool UserChange::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  uint32_t _count;
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        if (!_bb.readVarUint(_data_sessionID)) return false;
        set_sessionID(_data_sessionID);
        break;
      }
      case 2: {
        if (!_bb.readByte(_data_connected)) return false;
        set_connected(_data_connected);
        break;
      }
      case 3: {
        if (!_bb.readString(_data_name, _pool)) return false;
        set_name(_data_name);
        break;
      }
      case 4: {
        _data_color = _pool.allocate<Color>();
        if (!_data_color->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 5: {
        if (!_bb.readString(_data_imageURL, _pool)) return false;
        set_imageURL(_data_imageURL);
        break;
      }
      case 6: {
        _data_viewport = _pool.allocate<Viewport>();
        if (!_data_viewport->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 7: {
        _data_mouse = _pool.allocate<Mouse>();
        if (!_data_mouse->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 8: {
        if (!_bb.readVarUint(_count)) return false;
        for (GUID &_it : set_selection(_pool, _count)) if (!_it.decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 9: {
        if (!_bb.readVarUint(_count)) return false;
        for (uint32_t &_it : set_observing(_pool, _count)) if (!_bb.readVarUint(_it)) return false;
        break;
      }
      case 10: {
        if (!_bb.readString(_data_deviceName, _pool)) return false;
        set_deviceName(_data_deviceName);
        break;
      }
      case 11: {
        if (!_bb.readVarUint(_count)) return false;
        for (Click &_it : set_recentClicks(_pool, _count)) if (!_it.decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 12: {
        if (!_bb.readVarUint(_count)) return false;
        for (ScrollPosition &_it : set_scrollPositions(_pool, _count)) if (!_it.decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 13: {
        if (!_bb.readVarUint(_count)) return false;
        for (TriggeredOverlay &_it : set_triggeredOverlays(_pool, _count)) if (!_it.decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 14: {
        if (!_bb.readString(_data_userID, _pool)) return false;
        set_userID(_data_userID);
        break;
      }
      case 15: {
        _data_lastTriggeredHotspot = _pool.allocate<GUID>();
        if (!_data_lastTriggeredHotspot->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 16: {
        _data_lastTriggeredPrototypeInteractionID = _pool.allocate<GUID>();
        if (!_data_lastTriggeredPrototypeInteractionID->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 17: {
        if (!_bb.readVarUint(_count)) return false;
        for (TriggeredOverlayData &_it : set_triggeredOverlaysData(_pool, _count)) if (!_it.decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 18: {
        if (!_bb.readVarUint(_count)) return false;
        for (PlaybackUpdate &_it : set_playbackUpdates(_pool, _count)) if (!_it.decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 19: {
        _data_chatMessage = _pool.allocate<ChatMessage>();
        if (!_data_chatMessage->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 20: {
        _data_voiceMetadata = _pool.allocate<VoiceMetadata>();
        if (!_data_voiceMetadata->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 21: {
        if (!_bb.readByte(_data_canWrite)) return false;
        set_canWrite(_data_canWrite);
        break;
      }
      case 22: {
        if (!_bb.readByte(_data_highFiveStatus)) return false;
        set_highFiveStatus(_data_highFiveStatus);
        break;
      }
      case 23: {
        if (!_bb.readVarUint(_count)) return false;
        for (InstanceStateChange &_it : set_instanceStateChanges(_pool, _count)) if (!_it.decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 24: {
        _data_textCursor = _pool.allocate<TextCursor>();
        if (!_data_textCursor->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 25: {
        _data_textSelection = _pool.allocate<TextSelection>();
        if (!_data_textSelection->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 26: {
        if (!_bb.readVarUint(_data_connectedAtTimeS)) return false;
        set_connectedAtTimeS(_data_connectedAtTimeS);
        break;
      }
      case 27: {
        if (!_bb.readByte(_data_focusOnTextCursor)) return false;
        set_focusOnTextCursor(_data_focusOnTextCursor);
        break;
      }
      case 28: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_heartbeat))) return false;
        set_heartbeat(_data_heartbeat);
        break;
      }
      default: {
        if (!_schema || !_schema->skipUserChangeField(_bb, _type)) return false;
        break;
      }
    }
  }
}

GUID *SceneGraphQuery::startingNode() {
  return _data_startingNode;
}

const GUID *SceneGraphQuery::startingNode() const {
  return _data_startingNode;
}

void SceneGraphQuery::set_startingNode(GUID *value) {
  _data_startingNode = value;
}

uint32_t *SceneGraphQuery::depth() {
  return _flags[0] & 2 ? &_data_depth : nullptr;
}

const uint32_t *SceneGraphQuery::depth() const {
  return _flags[0] & 2 ? &_data_depth : nullptr;
}

void SceneGraphQuery::set_depth(const uint32_t &value) {
  _flags[0] |= 2; _data_depth = value;
}

bool SceneGraphQuery::encode(kiwi::ByteBuffer &_bb) {
  if (startingNode() != nullptr) {
    _bb.writeVarUint(1);
    if (!_data_startingNode->encode(_bb)) return false;
  }
  if (depth() != nullptr) {
    _bb.writeVarUint(2);
    _bb.writeVarUint(_data_depth);
  }
  _bb.writeVarUint(0);
  return true;
}

bool SceneGraphQuery::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        _data_startingNode = _pool.allocate<GUID>();
        if (!_data_startingNode->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 2: {
        if (!_bb.readVarUint(_data_depth)) return false;
        set_depth(_data_depth);
        break;
      }
      default: {
        if (!_schema || !_schema->skipSceneGraphQueryField(_bb, _type)) return false;
        break;
      }
    }
  }
}

uint32_t *NodeChangesMetadata::blobsFieldOffset() {
  return _flags[0] & 1 ? &_data_blobsFieldOffset : nullptr;
}

const uint32_t *NodeChangesMetadata::blobsFieldOffset() const {
  return _flags[0] & 1 ? &_data_blobsFieldOffset : nullptr;
}

void NodeChangesMetadata::set_blobsFieldOffset(const uint32_t &value) {
  _flags[0] |= 1; _data_blobsFieldOffset = value;
}

bool NodeChangesMetadata::encode(kiwi::ByteBuffer &_bb) {
  if (blobsFieldOffset() != nullptr) {
    _bb.writeVarUint(1);
    _bb.writeVarUint(_data_blobsFieldOffset);
  }
  _bb.writeVarUint(0);
  return true;
}

bool NodeChangesMetadata::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        if (!_bb.readVarUint(_data_blobsFieldOffset)) return false;
        set_blobsFieldOffset(_data_blobsFieldOffset);
        break;
      }
      default: {
        if (!_schema || !_schema->skipNodeChangesMetadataField(_bb, _type)) return false;
        break;
      }
    }
  }
}

kiwi::String *CursorReaction::imageUrl() {
  return _flags[0] & 1 ? &_data_imageUrl : nullptr;
}

const kiwi::String *CursorReaction::imageUrl() const {
  return _flags[0] & 1 ? &_data_imageUrl : nullptr;
}

void CursorReaction::set_imageUrl(const kiwi::String &value) {
  _flags[0] |= 1; _data_imageUrl = value;
}

bool CursorReaction::encode(kiwi::ByteBuffer &_bb) {
  if (imageUrl() != nullptr) {
    _bb.writeVarUint(1);
    _bb.writeString(_data_imageUrl.c_str());
  }
  _bb.writeVarUint(0);
  return true;
}

bool CursorReaction::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        if (!_bb.readString(_data_imageUrl, _pool)) return false;
        set_imageUrl(_data_imageUrl);
        break;
      }
      default: {
        if (!_schema || !_schema->skipCursorReactionField(_bb, _type)) return false;
        break;
      }
    }
  }
}

bool *TimerInfo::isPaused() {
  return _flags[0] & 1 ? &_data_isPaused : nullptr;
}

const bool *TimerInfo::isPaused() const {
  return _flags[0] & 1 ? &_data_isPaused : nullptr;
}

void TimerInfo::set_isPaused(const bool &value) {
  _flags[0] |= 1; _data_isPaused = value;
}

uint32_t *TimerInfo::timeRemainingMs() {
  return _flags[0] & 2 ? &_data_timeRemainingMs : nullptr;
}

const uint32_t *TimerInfo::timeRemainingMs() const {
  return _flags[0] & 2 ? &_data_timeRemainingMs : nullptr;
}

void TimerInfo::set_timeRemainingMs(const uint32_t &value) {
  _flags[0] |= 2; _data_timeRemainingMs = value;
}

uint32_t *TimerInfo::totalTimeMs() {
  return _flags[0] & 4 ? &_data_totalTimeMs : nullptr;
}

const uint32_t *TimerInfo::totalTimeMs() const {
  return _flags[0] & 4 ? &_data_totalTimeMs : nullptr;
}

void TimerInfo::set_totalTimeMs(const uint32_t &value) {
  _flags[0] |= 4; _data_totalTimeMs = value;
}

uint32_t *TimerInfo::timerID() {
  return _flags[0] & 8 ? &_data_timerID : nullptr;
}

const uint32_t *TimerInfo::timerID() const {
  return _flags[0] & 8 ? &_data_timerID : nullptr;
}

void TimerInfo::set_timerID(const uint32_t &value) {
  _flags[0] |= 8; _data_timerID = value;
}

kiwi::String *TimerInfo::setBy() {
  return _flags[0] & 16 ? &_data_setBy : nullptr;
}

const kiwi::String *TimerInfo::setBy() const {
  return _flags[0] & 16 ? &_data_setBy : nullptr;
}

void TimerInfo::set_setBy(const kiwi::String &value) {
  _flags[0] |= 16; _data_setBy = value;
}

uint32_t *TimerInfo::songID() {
  return _flags[0] & 32 ? &_data_songID : nullptr;
}

const uint32_t *TimerInfo::songID() const {
  return _flags[0] & 32 ? &_data_songID : nullptr;
}

void TimerInfo::set_songID(const uint32_t &value) {
  _flags[0] |= 32; _data_songID = value;
}

uint32_t *TimerInfo::lastReceivedSongTimestampMs() {
  return _flags[0] & 64 ? &_data_lastReceivedSongTimestampMs : nullptr;
}

const uint32_t *TimerInfo::lastReceivedSongTimestampMs() const {
  return _flags[0] & 64 ? &_data_lastReceivedSongTimestampMs : nullptr;
}

void TimerInfo::set_lastReceivedSongTimestampMs(const uint32_t &value) {
  _flags[0] |= 64; _data_lastReceivedSongTimestampMs = value;
}

kiwi::String *TimerInfo::songUUID() {
  return _flags[0] & 128 ? &_data_songUUID : nullptr;
}

const kiwi::String *TimerInfo::songUUID() const {
  return _flags[0] & 128 ? &_data_songUUID : nullptr;
}

void TimerInfo::set_songUUID(const kiwi::String &value) {
  _flags[0] |= 128; _data_songUUID = value;
}

bool TimerInfo::encode(kiwi::ByteBuffer &_bb) {
  if (isPaused() != nullptr) {
    _bb.writeVarUint(1);
    _bb.writeByte(_data_isPaused);
  }
  if (timeRemainingMs() != nullptr) {
    _bb.writeVarUint(2);
    _bb.writeVarUint(_data_timeRemainingMs);
  }
  if (totalTimeMs() != nullptr) {
    _bb.writeVarUint(3);
    _bb.writeVarUint(_data_totalTimeMs);
  }
  if (timerID() != nullptr) {
    _bb.writeVarUint(4);
    _bb.writeVarUint(_data_timerID);
  }
  if (setBy() != nullptr) {
    _bb.writeVarUint(5);
    _bb.writeString(_data_setBy.c_str());
  }
  if (songID() != nullptr) {
    _bb.writeVarUint(6);
    _bb.writeVarUint(_data_songID);
  }
  if (lastReceivedSongTimestampMs() != nullptr) {
    _bb.writeVarUint(7);
    _bb.writeVarUint(_data_lastReceivedSongTimestampMs);
  }
  if (songUUID() != nullptr) {
    _bb.writeVarUint(8);
    _bb.writeString(_data_songUUID.c_str());
  }
  _bb.writeVarUint(0);
  return true;
}

bool TimerInfo::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        if (!_bb.readByte(_data_isPaused)) return false;
        set_isPaused(_data_isPaused);
        break;
      }
      case 2: {
        if (!_bb.readVarUint(_data_timeRemainingMs)) return false;
        set_timeRemainingMs(_data_timeRemainingMs);
        break;
      }
      case 3: {
        if (!_bb.readVarUint(_data_totalTimeMs)) return false;
        set_totalTimeMs(_data_totalTimeMs);
        break;
      }
      case 4: {
        if (!_bb.readVarUint(_data_timerID)) return false;
        set_timerID(_data_timerID);
        break;
      }
      case 5: {
        if (!_bb.readString(_data_setBy, _pool)) return false;
        set_setBy(_data_setBy);
        break;
      }
      case 6: {
        if (!_bb.readVarUint(_data_songID)) return false;
        set_songID(_data_songID);
        break;
      }
      case 7: {
        if (!_bb.readVarUint(_data_lastReceivedSongTimestampMs)) return false;
        set_lastReceivedSongTimestampMs(_data_lastReceivedSongTimestampMs);
        break;
      }
      case 8: {
        if (!_bb.readString(_data_songUUID, _pool)) return false;
        set_songUUID(_data_songUUID);
        break;
      }
      default: {
        if (!_schema || !_schema->skipTimerInfoField(_bb, _type)) return false;
        break;
      }
    }
  }
}

bool *MusicInfo::isPaused() {
  return _flags[0] & 1 ? &_data_isPaused : nullptr;
}

const bool *MusicInfo::isPaused() const {
  return _flags[0] & 1 ? &_data_isPaused : nullptr;
}

void MusicInfo::set_isPaused(const bool &value) {
  _flags[0] |= 1; _data_isPaused = value;
}

uint32_t *MusicInfo::messageID() {
  return _flags[0] & 2 ? &_data_messageID : nullptr;
}

const uint32_t *MusicInfo::messageID() const {
  return _flags[0] & 2 ? &_data_messageID : nullptr;
}

void MusicInfo::set_messageID(const uint32_t &value) {
  _flags[0] |= 2; _data_messageID = value;
}

kiwi::String *MusicInfo::songID() {
  return _flags[0] & 4 ? &_data_songID : nullptr;
}

const kiwi::String *MusicInfo::songID() const {
  return _flags[0] & 4 ? &_data_songID : nullptr;
}

void MusicInfo::set_songID(const kiwi::String &value) {
  _flags[0] |= 4; _data_songID = value;
}

uint32_t *MusicInfo::lastReceivedSongTimestampMs() {
  return _flags[0] & 8 ? &_data_lastReceivedSongTimestampMs : nullptr;
}

const uint32_t *MusicInfo::lastReceivedSongTimestampMs() const {
  return _flags[0] & 8 ? &_data_lastReceivedSongTimestampMs : nullptr;
}

void MusicInfo::set_lastReceivedSongTimestampMs(const uint32_t &value) {
  _flags[0] |= 8; _data_lastReceivedSongTimestampMs = value;
}

bool *MusicInfo::isStopped() {
  return _flags[0] & 16 ? &_data_isStopped : nullptr;
}

const bool *MusicInfo::isStopped() const {
  return _flags[0] & 16 ? &_data_isStopped : nullptr;
}

void MusicInfo::set_isStopped(const bool &value) {
  _flags[0] |= 16; _data_isStopped = value;
}

bool MusicInfo::encode(kiwi::ByteBuffer &_bb) {
  if (isPaused() != nullptr) {
    _bb.writeVarUint(1);
    _bb.writeByte(_data_isPaused);
  }
  if (messageID() != nullptr) {
    _bb.writeVarUint(2);
    _bb.writeVarUint(_data_messageID);
  }
  if (songID() != nullptr) {
    _bb.writeVarUint(3);
    _bb.writeString(_data_songID.c_str());
  }
  if (lastReceivedSongTimestampMs() != nullptr) {
    _bb.writeVarUint(4);
    _bb.writeVarUint(_data_lastReceivedSongTimestampMs);
  }
  if (isStopped() != nullptr) {
    _bb.writeVarUint(5);
    _bb.writeByte(_data_isStopped);
  }
  _bb.writeVarUint(0);
  return true;
}

bool MusicInfo::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        if (!_bb.readByte(_data_isPaused)) return false;
        set_isPaused(_data_isPaused);
        break;
      }
      case 2: {
        if (!_bb.readVarUint(_data_messageID)) return false;
        set_messageID(_data_messageID);
        break;
      }
      case 3: {
        if (!_bb.readString(_data_songID, _pool)) return false;
        set_songID(_data_songID);
        break;
      }
      case 4: {
        if (!_bb.readVarUint(_data_lastReceivedSongTimestampMs)) return false;
        set_lastReceivedSongTimestampMs(_data_lastReceivedSongTimestampMs);
        break;
      }
      case 5: {
        if (!_bb.readByte(_data_isStopped)) return false;
        set_isStopped(_data_isStopped);
        break;
      }
      default: {
        if (!_schema || !_schema->skipMusicInfoField(_bb, _type)) return false;
        break;
      }
    }
  }
}

uint32_t *PresenterNomination::sessionID() {
  return _flags[0] & 1 ? &_data_sessionID : nullptr;
}

const uint32_t *PresenterNomination::sessionID() const {
  return _flags[0] & 1 ? &_data_sessionID : nullptr;
}

void PresenterNomination::set_sessionID(const uint32_t &value) {
  _flags[0] |= 1; _data_sessionID = value;
}

bool *PresenterNomination::isCancelled() {
  return _flags[0] & 2 ? &_data_isCancelled : nullptr;
}

const bool *PresenterNomination::isCancelled() const {
  return _flags[0] & 2 ? &_data_isCancelled : nullptr;
}

void PresenterNomination::set_isCancelled(const bool &value) {
  _flags[0] |= 2; _data_isCancelled = value;
}

bool PresenterNomination::encode(kiwi::ByteBuffer &_bb) {
  if (sessionID() != nullptr) {
    _bb.writeVarUint(1);
    _bb.writeVarUint(_data_sessionID);
  }
  if (isCancelled() != nullptr) {
    _bb.writeVarUint(2);
    _bb.writeByte(_data_isCancelled);
  }
  _bb.writeVarUint(0);
  return true;
}

bool PresenterNomination::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        if (!_bb.readVarUint(_data_sessionID)) return false;
        set_sessionID(_data_sessionID);
        break;
      }
      case 2: {
        if (!_bb.readByte(_data_isCancelled)) return false;
        set_isCancelled(_data_isCancelled);
        break;
      }
      default: {
        if (!_schema || !_schema->skipPresenterNominationField(_bb, _type)) return false;
        break;
      }
    }
  }
}

uint32_t *PresenterInfo::sessionID() {
  return _flags[0] & 1 ? &_data_sessionID : nullptr;
}

const uint32_t *PresenterInfo::sessionID() const {
  return _flags[0] & 1 ? &_data_sessionID : nullptr;
}

void PresenterInfo::set_sessionID(const uint32_t &value) {
  _flags[0] |= 1; _data_sessionID = value;
}

PresenterNomination *PresenterInfo::nomination() {
  return _data_nomination;
}

const PresenterNomination *PresenterInfo::nomination() const {
  return _data_nomination;
}

void PresenterInfo::set_nomination(PresenterNomination *value) {
  _data_nomination = value;
}

bool PresenterInfo::encode(kiwi::ByteBuffer &_bb) {
  if (sessionID() != nullptr) {
    _bb.writeVarUint(1);
    _bb.writeVarUint(_data_sessionID);
  }
  if (nomination() != nullptr) {
    _bb.writeVarUint(2);
    if (!_data_nomination->encode(_bb)) return false;
  }
  _bb.writeVarUint(0);
  return true;
}

bool PresenterInfo::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        if (!_bb.readVarUint(_data_sessionID)) return false;
        set_sessionID(_data_sessionID);
        break;
      }
      case 2: {
        _data_nomination = _pool.allocate<PresenterNomination>();
        if (!_data_nomination->decode(_bb, _pool, _schema)) return false;
        break;
      }
      default: {
        if (!_schema || !_schema->skipPresenterInfoField(_bb, _type)) return false;
        break;
      }
    }
  }
}

uint32_t *ClientBroadcast::sessionID() {
  return _flags[0] & 1 ? &_data_sessionID : nullptr;
}

const uint32_t *ClientBroadcast::sessionID() const {
  return _flags[0] & 1 ? &_data_sessionID : nullptr;
}

void ClientBroadcast::set_sessionID(const uint32_t &value) {
  _flags[0] |= 1; _data_sessionID = value;
}

CursorReaction *ClientBroadcast::cursorReaction() {
  return _data_cursorReaction;
}

const CursorReaction *ClientBroadcast::cursorReaction() const {
  return _data_cursorReaction;
}

void ClientBroadcast::set_cursorReaction(CursorReaction *value) {
  _data_cursorReaction = value;
}

TimerInfo *ClientBroadcast::timer() {
  return _data_timer;
}

const TimerInfo *ClientBroadcast::timer() const {
  return _data_timer;
}

void ClientBroadcast::set_timer(TimerInfo *value) {
  _data_timer = value;
}

PresenterInfo *ClientBroadcast::presenter() {
  return _data_presenter;
}

const PresenterInfo *ClientBroadcast::presenter() const {
  return _data_presenter;
}

void ClientBroadcast::set_presenter(PresenterInfo *value) {
  _data_presenter = value;
}

PresenterInfo *ClientBroadcast::prototypePresenter() {
  return _data_prototypePresenter;
}

const PresenterInfo *ClientBroadcast::prototypePresenter() const {
  return _data_prototypePresenter;
}

void ClientBroadcast::set_prototypePresenter(PresenterInfo *value) {
  _data_prototypePresenter = value;
}

MusicInfo *ClientBroadcast::music() {
  return _data_music;
}

const MusicInfo *ClientBroadcast::music() const {
  return _data_music;
}

void ClientBroadcast::set_music(MusicInfo *value) {
  _data_music = value;
}

bool ClientBroadcast::encode(kiwi::ByteBuffer &_bb) {
  if (sessionID() != nullptr) {
    _bb.writeVarUint(1);
    _bb.writeVarUint(_data_sessionID);
  }
  if (cursorReaction() != nullptr) {
    _bb.writeVarUint(2);
    if (!_data_cursorReaction->encode(_bb)) return false;
  }
  if (timer() != nullptr) {
    _bb.writeVarUint(3);
    if (!_data_timer->encode(_bb)) return false;
  }
  if (presenter() != nullptr) {
    _bb.writeVarUint(4);
    if (!_data_presenter->encode(_bb)) return false;
  }
  if (prototypePresenter() != nullptr) {
    _bb.writeVarUint(5);
    if (!_data_prototypePresenter->encode(_bb)) return false;
  }
  if (music() != nullptr) {
    _bb.writeVarUint(6);
    if (!_data_music->encode(_bb)) return false;
  }
  _bb.writeVarUint(0);
  return true;
}

bool ClientBroadcast::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        if (!_bb.readVarUint(_data_sessionID)) return false;
        set_sessionID(_data_sessionID);
        break;
      }
      case 2: {
        _data_cursorReaction = _pool.allocate<CursorReaction>();
        if (!_data_cursorReaction->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 3: {
        _data_timer = _pool.allocate<TimerInfo>();
        if (!_data_timer->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 4: {
        _data_presenter = _pool.allocate<PresenterInfo>();
        if (!_data_presenter->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 5: {
        _data_prototypePresenter = _pool.allocate<PresenterInfo>();
        if (!_data_prototypePresenter->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 6: {
        _data_music = _pool.allocate<MusicInfo>();
        if (!_data_music->decode(_bb, _pool, _schema)) return false;
        break;
      }
      default: {
        if (!_schema || !_schema->skipClientBroadcastField(_bb, _type)) return false;
        break;
      }
    }
  }
}

MessageType *Message::type() {
  return _flags[0] & 1 ? &_data_type : nullptr;
}

const MessageType *Message::type() const {
  return _flags[0] & 1 ? &_data_type : nullptr;
}

void Message::set_type(const MessageType &value) {
  _flags[0] |= 1; _data_type = value;
}

uint32_t *Message::sessionID() {
  return _flags[0] & 2 ? &_data_sessionID : nullptr;
}

const uint32_t *Message::sessionID() const {
  return _flags[0] & 2 ? &_data_sessionID : nullptr;
}

void Message::set_sessionID(const uint32_t &value) {
  _flags[0] |= 2; _data_sessionID = value;
}

uint32_t *Message::ackID() {
  return _flags[0] & 4 ? &_data_ackID : nullptr;
}

const uint32_t *Message::ackID() const {
  return _flags[0] & 4 ? &_data_ackID : nullptr;
}

void Message::set_ackID(const uint32_t &value) {
  _flags[0] |= 4; _data_ackID = value;
}

kiwi::Array<NodeChange> *Message::nodeChanges() {
  return _flags[0] & 8 ? &_data_nodeChanges : nullptr;
}

const kiwi::Array<NodeChange> *Message::nodeChanges() const {
  return _flags[0] & 8 ? &_data_nodeChanges : nullptr;
}

kiwi::Array<NodeChange> &Message::set_nodeChanges(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[0] |= 8; return _data_nodeChanges = pool.array<NodeChange>(count);
}

kiwi::Array<UserChange> *Message::userChanges() {
  return _flags[0] & 16 ? &_data_userChanges : nullptr;
}

const kiwi::Array<UserChange> *Message::userChanges() const {
  return _flags[0] & 16 ? &_data_userChanges : nullptr;
}

kiwi::Array<UserChange> &Message::set_userChanges(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[0] |= 16; return _data_userChanges = pool.array<UserChange>(count);
}

kiwi::Array<Blob> *Message::blobs() {
  return _flags[0] & 32 ? &_data_blobs : nullptr;
}

const kiwi::Array<Blob> *Message::blobs() const {
  return _flags[0] & 32 ? &_data_blobs : nullptr;
}

kiwi::Array<Blob> &Message::set_blobs(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[0] |= 32; return _data_blobs = pool.array<Blob>(count);
}

uint32_t *Message::blobBaseIndex() {
  return _flags[0] & 64 ? &_data_blobBaseIndex : nullptr;
}

const uint32_t *Message::blobBaseIndex() const {
  return _flags[0] & 64 ? &_data_blobBaseIndex : nullptr;
}

void Message::set_blobBaseIndex(const uint32_t &value) {
  _flags[0] |= 64; _data_blobBaseIndex = value;
}

kiwi::String *Message::signalName() {
  return _flags[0] & 128 ? &_data_signalName : nullptr;
}

const kiwi::String *Message::signalName() const {
  return _flags[0] & 128 ? &_data_signalName : nullptr;
}

void Message::set_signalName(const kiwi::String &value) {
  _flags[0] |= 128; _data_signalName = value;
}

Access *Message::access() {
  return _flags[0] & 256 ? &_data_access : nullptr;
}

const Access *Message::access() const {
  return _flags[0] & 256 ? &_data_access : nullptr;
}

void Message::set_access(const Access &value) {
  _flags[0] |= 256; _data_access = value;
}

kiwi::String *Message::styleSetName() {
  return _flags[0] & 512 ? &_data_styleSetName : nullptr;
}

const kiwi::String *Message::styleSetName() const {
  return _flags[0] & 512 ? &_data_styleSetName : nullptr;
}

void Message::set_styleSetName(const kiwi::String &value) {
  _flags[0] |= 512; _data_styleSetName = value;
}

StyleSetType *Message::styleSetType() {
  return _flags[0] & 1024 ? &_data_styleSetType : nullptr;
}

const StyleSetType *Message::styleSetType() const {
  return _flags[0] & 1024 ? &_data_styleSetType : nullptr;
}

void Message::set_styleSetType(const StyleSetType &value) {
  _flags[0] |= 1024; _data_styleSetType = value;
}

StyleSetContentType *Message::styleSetContentType() {
  return _flags[0] & 2048 ? &_data_styleSetContentType : nullptr;
}

const StyleSetContentType *Message::styleSetContentType() const {
  return _flags[0] & 2048 ? &_data_styleSetContentType : nullptr;
}

void Message::set_styleSetContentType(const StyleSetContentType &value) {
  _flags[0] |= 2048; _data_styleSetContentType = value;
}

int32_t *Message::pasteID() {
  return _flags[0] & 4096 ? &_data_pasteID : nullptr;
}

const int32_t *Message::pasteID() const {
  return _flags[0] & 4096 ? &_data_pasteID : nullptr;
}

void Message::set_pasteID(const int32_t &value) {
  _flags[0] |= 4096; _data_pasteID = value;
}

Vector *Message::pasteOffset() {
  return _data_pasteOffset;
}

const Vector *Message::pasteOffset() const {
  return _data_pasteOffset;
}

void Message::set_pasteOffset(Vector *value) {
  _data_pasteOffset = value;
}

kiwi::String *Message::pasteFileKey() {
  return _flags[0] & 16384 ? &_data_pasteFileKey : nullptr;
}

const kiwi::String *Message::pasteFileKey() const {
  return _flags[0] & 16384 ? &_data_pasteFileKey : nullptr;
}

void Message::set_pasteFileKey(const kiwi::String &value) {
  _flags[0] |= 16384; _data_pasteFileKey = value;
}

kiwi::String *Message::signalPayload() {
  return _flags[0] & 32768 ? &_data_signalPayload : nullptr;
}

const kiwi::String *Message::signalPayload() const {
  return _flags[0] & 32768 ? &_data_signalPayload : nullptr;
}

void Message::set_signalPayload(const kiwi::String &value) {
  _flags[0] |= 32768; _data_signalPayload = value;
}

kiwi::Array<SceneGraphQuery> *Message::sceneGraphQueries() {
  return _flags[0] & 65536 ? &_data_sceneGraphQueries : nullptr;
}

const kiwi::Array<SceneGraphQuery> *Message::sceneGraphQueries() const {
  return _flags[0] & 65536 ? &_data_sceneGraphQueries : nullptr;
}

kiwi::Array<SceneGraphQuery> &Message::set_sceneGraphQueries(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[0] |= 65536; return _data_sceneGraphQueries = pool.array<SceneGraphQuery>(count);
}

NodeChangesMetadata *Message::nodeChangesMetadata() {
  return _data_nodeChangesMetadata;
}

const NodeChangesMetadata *Message::nodeChangesMetadata() const {
  return _data_nodeChangesMetadata;
}

void Message::set_nodeChangesMetadata(NodeChangesMetadata *value) {
  _data_nodeChangesMetadata = value;
}

uint32_t *Message::fileVersion() {
  return _flags[0] & 262144 ? &_data_fileVersion : nullptr;
}

const uint32_t *Message::fileVersion() const {
  return _flags[0] & 262144 ? &_data_fileVersion : nullptr;
}

void Message::set_fileVersion(const uint32_t &value) {
  _flags[0] |= 262144; _data_fileVersion = value;
}

bool *Message::pasteIsPartiallyOutsideEnclosingFrame() {
  return _flags[0] & 524288 ? &_data_pasteIsPartiallyOutsideEnclosingFrame : nullptr;
}

const bool *Message::pasteIsPartiallyOutsideEnclosingFrame() const {
  return _flags[0] & 524288 ? &_data_pasteIsPartiallyOutsideEnclosingFrame : nullptr;
}

void Message::set_pasteIsPartiallyOutsideEnclosingFrame(const bool &value) {
  _flags[0] |= 524288; _data_pasteIsPartiallyOutsideEnclosingFrame = value;
}

GUID *Message::pastePageId() {
  return _data_pastePageId;
}

const GUID *Message::pastePageId() const {
  return _data_pastePageId;
}

void Message::set_pastePageId(GUID *value) {
  _data_pastePageId = value;
}

bool *Message::isCut() {
  return _flags[0] & 2097152 ? &_data_isCut : nullptr;
}

const bool *Message::isCut() const {
  return _flags[0] & 2097152 ? &_data_isCut : nullptr;
}

void Message::set_isCut(const bool &value) {
  _flags[0] |= 2097152; _data_isCut = value;
}

kiwi::Array<Message> *Message::localUndoStack() {
  return _flags[0] & 4194304 ? &_data_localUndoStack : nullptr;
}

const kiwi::Array<Message> *Message::localUndoStack() const {
  return _flags[0] & 4194304 ? &_data_localUndoStack : nullptr;
}

kiwi::Array<Message> &Message::set_localUndoStack(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[0] |= 4194304; return _data_localUndoStack = pool.array<Message>(count);
}

kiwi::Array<Message> *Message::localRedoStack() {
  return _flags[0] & 8388608 ? &_data_localRedoStack : nullptr;
}

const kiwi::Array<Message> *Message::localRedoStack() const {
  return _flags[0] & 8388608 ? &_data_localRedoStack : nullptr;
}

kiwi::Array<Message> &Message::set_localRedoStack(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[0] |= 8388608; return _data_localRedoStack = pool.array<Message>(count);
}

kiwi::Array<ClientBroadcast> *Message::broadcasts() {
  return _flags[0] & 16777216 ? &_data_broadcasts : nullptr;
}

const kiwi::Array<ClientBroadcast> *Message::broadcasts() const {
  return _flags[0] & 16777216 ? &_data_broadcasts : nullptr;
}

kiwi::Array<ClientBroadcast> &Message::set_broadcasts(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[0] |= 16777216; return _data_broadcasts = pool.array<ClientBroadcast>(count);
}

uint32_t *Message::reconnectSequenceNumber() {
  return _flags[0] & 33554432 ? &_data_reconnectSequenceNumber : nullptr;
}

const uint32_t *Message::reconnectSequenceNumber() const {
  return _flags[0] & 33554432 ? &_data_reconnectSequenceNumber : nullptr;
}

void Message::set_reconnectSequenceNumber(const uint32_t &value) {
  _flags[0] |= 33554432; _data_reconnectSequenceNumber = value;
}

kiwi::String *Message::pasteBranchSourceFileKey() {
  return _flags[0] & 67108864 ? &_data_pasteBranchSourceFileKey : nullptr;
}

const kiwi::String *Message::pasteBranchSourceFileKey() const {
  return _flags[0] & 67108864 ? &_data_pasteBranchSourceFileKey : nullptr;
}

void Message::set_pasteBranchSourceFileKey(const kiwi::String &value) {
  _flags[0] |= 67108864; _data_pasteBranchSourceFileKey = value;
}

EditorType *Message::pasteEditorType() {
  return _flags[0] & 134217728 ? &_data_pasteEditorType : nullptr;
}

const EditorType *Message::pasteEditorType() const {
  return _flags[0] & 134217728 ? &_data_pasteEditorType : nullptr;
}

void Message::set_pasteEditorType(const EditorType &value) {
  _flags[0] |= 134217728; _data_pasteEditorType = value;
}

kiwi::String *Message::postSyncActions() {
  return _flags[0] & 268435456 ? &_data_postSyncActions : nullptr;
}

const kiwi::String *Message::postSyncActions() const {
  return _flags[0] & 268435456 ? &_data_postSyncActions : nullptr;
}

void Message::set_postSyncActions(const kiwi::String &value) {
  _flags[0] |= 268435456; _data_postSyncActions = value;
}

kiwi::Array<GUID> *Message::publishedAssetGuids() {
  return _flags[0] & 536870912 ? &_data_publishedAssetGuids : nullptr;
}

const kiwi::Array<GUID> *Message::publishedAssetGuids() const {
  return _flags[0] & 536870912 ? &_data_publishedAssetGuids : nullptr;
}

kiwi::Array<GUID> &Message::set_publishedAssetGuids(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[0] |= 536870912; return _data_publishedAssetGuids = pool.array<GUID>(count);
}

bool *Message::dirtyFromInitialLoad() {
  return _flags[0] & 1073741824 ? &_data_dirtyFromInitialLoad : nullptr;
}

const bool *Message::dirtyFromInitialLoad() const {
  return _flags[0] & 1073741824 ? &_data_dirtyFromInitialLoad : nullptr;
}

void Message::set_dirtyFromInitialLoad(const bool &value) {
  _flags[0] |= 1073741824; _data_dirtyFromInitialLoad = value;
}

bool Message::encode(kiwi::ByteBuffer &_bb) {
  if (type() != nullptr) {
    _bb.writeVarUint(1);
    _bb.writeVarUint(static_cast<uint32_t>(_data_type));
  }
  if (sessionID() != nullptr) {
    _bb.writeVarUint(2);
    _bb.writeVarUint(_data_sessionID);
  }
  if (ackID() != nullptr) {
    _bb.writeVarUint(3);
    _bb.writeVarUint(_data_ackID);
  }
  if (nodeChanges() != nullptr) {
    _bb.writeVarUint(4);
    _bb.writeVarUint(_data_nodeChanges.size());
    for (NodeChange &_it : _data_nodeChanges) if (!_it.encode(_bb)) return false;
  }
  if (userChanges() != nullptr) {
    _bb.writeVarUint(5);
    _bb.writeVarUint(_data_userChanges.size());
    for (UserChange &_it : _data_userChanges) if (!_it.encode(_bb)) return false;
  }
  if (blobs() != nullptr) {
    _bb.writeVarUint(6);
    _bb.writeVarUint(_data_blobs.size());
    for (Blob &_it : _data_blobs) if (!_it.encode(_bb)) return false;
  }
  if (blobBaseIndex() != nullptr) {
    _bb.writeVarUint(30);
    _bb.writeVarUint(_data_blobBaseIndex);
  }
  if (signalName() != nullptr) {
    _bb.writeVarUint(7);
    _bb.writeString(_data_signalName.c_str());
  }
  if (access() != nullptr) {
    _bb.writeVarUint(8);
    _bb.writeVarUint(static_cast<uint32_t>(_data_access));
  }
  if (styleSetName() != nullptr) {
    _bb.writeVarUint(9);
    _bb.writeString(_data_styleSetName.c_str());
  }
  if (styleSetType() != nullptr) {
    _bb.writeVarUint(10);
    _bb.writeVarUint(static_cast<uint32_t>(_data_styleSetType));
  }
  if (styleSetContentType() != nullptr) {
    _bb.writeVarUint(11);
    _bb.writeVarUint(static_cast<uint32_t>(_data_styleSetContentType));
  }
  if (pasteID() != nullptr) {
    _bb.writeVarUint(12);
    _bb.writeVarInt(_data_pasteID);
  }
  if (pasteOffset() != nullptr) {
    _bb.writeVarUint(13);
    if (!_data_pasteOffset->encode(_bb)) return false;
  }
  if (pasteFileKey() != nullptr) {
    _bb.writeVarUint(14);
    _bb.writeString(_data_pasteFileKey.c_str());
  }
  if (signalPayload() != nullptr) {
    _bb.writeVarUint(15);
    _bb.writeString(_data_signalPayload.c_str());
  }
  if (sceneGraphQueries() != nullptr) {
    _bb.writeVarUint(16);
    _bb.writeVarUint(_data_sceneGraphQueries.size());
    for (SceneGraphQuery &_it : _data_sceneGraphQueries) if (!_it.encode(_bb)) return false;
  }
  if (nodeChangesMetadata() != nullptr) {
    _bb.writeVarUint(17);
    if (!_data_nodeChangesMetadata->encode(_bb)) return false;
  }
  if (fileVersion() != nullptr) {
    _bb.writeVarUint(18);
    _bb.writeVarUint(_data_fileVersion);
  }
  if (pasteIsPartiallyOutsideEnclosingFrame() != nullptr) {
    _bb.writeVarUint(19);
    _bb.writeByte(_data_pasteIsPartiallyOutsideEnclosingFrame);
  }
  if (pastePageId() != nullptr) {
    _bb.writeVarUint(20);
    if (!_data_pastePageId->encode(_bb)) return false;
  }
  if (isCut() != nullptr) {
    _bb.writeVarUint(21);
    _bb.writeByte(_data_isCut);
  }
  if (localUndoStack() != nullptr) {
    _bb.writeVarUint(22);
    _bb.writeVarUint(_data_localUndoStack.size());
    for (Message &_it : _data_localUndoStack) if (!_it.encode(_bb)) return false;
  }
  if (localRedoStack() != nullptr) {
    _bb.writeVarUint(23);
    _bb.writeVarUint(_data_localRedoStack.size());
    for (Message &_it : _data_localRedoStack) if (!_it.encode(_bb)) return false;
  }
  if (broadcasts() != nullptr) {
    _bb.writeVarUint(24);
    _bb.writeVarUint(_data_broadcasts.size());
    for (ClientBroadcast &_it : _data_broadcasts) if (!_it.encode(_bb)) return false;
  }
  if (reconnectSequenceNumber() != nullptr) {
    _bb.writeVarUint(25);
    _bb.writeVarUint(_data_reconnectSequenceNumber);
  }
  if (pasteBranchSourceFileKey() != nullptr) {
    _bb.writeVarUint(26);
    _bb.writeString(_data_pasteBranchSourceFileKey.c_str());
  }
  if (pasteEditorType() != nullptr) {
    _bb.writeVarUint(27);
    _bb.writeVarUint(static_cast<uint32_t>(_data_pasteEditorType));
  }
  if (postSyncActions() != nullptr) {
    _bb.writeVarUint(28);
    _bb.writeString(_data_postSyncActions.c_str());
  }
  if (publishedAssetGuids() != nullptr) {
    _bb.writeVarUint(29);
    _bb.writeVarUint(_data_publishedAssetGuids.size());
    for (GUID &_it : _data_publishedAssetGuids) if (!_it.encode(_bb)) return false;
  }
  if (dirtyFromInitialLoad() != nullptr) {
    _bb.writeVarUint(31);
    _bb.writeByte(_data_dirtyFromInitialLoad);
  }
  _bb.writeVarUint(0);
  return true;
}

bool Message::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  uint32_t _count;
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_type))) return false;
        set_type(_data_type);
        break;
      }
      case 2: {
        if (!_bb.readVarUint(_data_sessionID)) return false;
        set_sessionID(_data_sessionID);
        break;
      }
      case 3: {
        if (!_bb.readVarUint(_data_ackID)) return false;
        set_ackID(_data_ackID);
        break;
      }
      case 4: {
        if (!_bb.readVarUint(_count)) return false;
        for (NodeChange &_it : set_nodeChanges(_pool, _count)) if (!_it.decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 5: {
        if (!_bb.readVarUint(_count)) return false;
        for (UserChange &_it : set_userChanges(_pool, _count)) if (!_it.decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 6: {
        if (!_bb.readVarUint(_count)) return false;
        for (Blob &_it : set_blobs(_pool, _count)) if (!_it.decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 30: {
        if (!_bb.readVarUint(_data_blobBaseIndex)) return false;
        set_blobBaseIndex(_data_blobBaseIndex);
        break;
      }
      case 7: {
        if (!_bb.readString(_data_signalName, _pool)) return false;
        set_signalName(_data_signalName);
        break;
      }
      case 8: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_access))) return false;
        set_access(_data_access);
        break;
      }
      case 9: {
        if (!_bb.readString(_data_styleSetName, _pool)) return false;
        set_styleSetName(_data_styleSetName);
        break;
      }
      case 10: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_styleSetType))) return false;
        set_styleSetType(_data_styleSetType);
        break;
      }
      case 11: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_styleSetContentType))) return false;
        set_styleSetContentType(_data_styleSetContentType);
        break;
      }
      case 12: {
        if (!_bb.readVarInt(_data_pasteID)) return false;
        set_pasteID(_data_pasteID);
        break;
      }
      case 13: {
        _data_pasteOffset = _pool.allocate<Vector>();
        if (!_data_pasteOffset->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 14: {
        if (!_bb.readString(_data_pasteFileKey, _pool)) return false;
        set_pasteFileKey(_data_pasteFileKey);
        break;
      }
      case 15: {
        if (!_bb.readString(_data_signalPayload, _pool)) return false;
        set_signalPayload(_data_signalPayload);
        break;
      }
      case 16: {
        if (!_bb.readVarUint(_count)) return false;
        for (SceneGraphQuery &_it : set_sceneGraphQueries(_pool, _count)) if (!_it.decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 17: {
        _data_nodeChangesMetadata = _pool.allocate<NodeChangesMetadata>();
        if (!_data_nodeChangesMetadata->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 18: {
        if (!_bb.readVarUint(_data_fileVersion)) return false;
        set_fileVersion(_data_fileVersion);
        break;
      }
      case 19: {
        if (!_bb.readByte(_data_pasteIsPartiallyOutsideEnclosingFrame)) return false;
        set_pasteIsPartiallyOutsideEnclosingFrame(_data_pasteIsPartiallyOutsideEnclosingFrame);
        break;
      }
      case 20: {
        _data_pastePageId = _pool.allocate<GUID>();
        if (!_data_pastePageId->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 21: {
        if (!_bb.readByte(_data_isCut)) return false;
        set_isCut(_data_isCut);
        break;
      }
      case 22: {
        if (!_bb.readVarUint(_count)) return false;
        for (Message &_it : set_localUndoStack(_pool, _count)) if (!_it.decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 23: {
        if (!_bb.readVarUint(_count)) return false;
        for (Message &_it : set_localRedoStack(_pool, _count)) if (!_it.decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 24: {
        if (!_bb.readVarUint(_count)) return false;
        for (ClientBroadcast &_it : set_broadcasts(_pool, _count)) if (!_it.decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 25: {
        if (!_bb.readVarUint(_data_reconnectSequenceNumber)) return false;
        set_reconnectSequenceNumber(_data_reconnectSequenceNumber);
        break;
      }
      case 26: {
        if (!_bb.readString(_data_pasteBranchSourceFileKey, _pool)) return false;
        set_pasteBranchSourceFileKey(_data_pasteBranchSourceFileKey);
        break;
      }
      case 27: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_pasteEditorType))) return false;
        set_pasteEditorType(_data_pasteEditorType);
        break;
      }
      case 28: {
        if (!_bb.readString(_data_postSyncActions, _pool)) return false;
        set_postSyncActions(_data_postSyncActions);
        break;
      }
      case 29: {
        if (!_bb.readVarUint(_count)) return false;
        for (GUID &_it : set_publishedAssetGuids(_pool, _count)) if (!_it.decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 31: {
        if (!_bb.readByte(_data_dirtyFromInitialLoad)) return false;
        set_dirtyFromInitialLoad(_data_dirtyFromInitialLoad);
        break;
      }
      default: {
        if (!_schema || !_schema->skipMessageField(_bb, _type)) return false;
        break;
      }
    }
  }
}

kiwi::Array<uint32_t> *DiffChunk::nodeChanges() {
  return _flags[0] & 1 ? &_data_nodeChanges : nullptr;
}

const kiwi::Array<uint32_t> *DiffChunk::nodeChanges() const {
  return _flags[0] & 1 ? &_data_nodeChanges : nullptr;
}

kiwi::Array<uint32_t> &DiffChunk::set_nodeChanges(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[0] |= 1; return _data_nodeChanges = pool.array<uint32_t>(count);
}

NodePhase *DiffChunk::phase() {
  return _flags[0] & 2 ? &_data_phase : nullptr;
}

const NodePhase *DiffChunk::phase() const {
  return _flags[0] & 2 ? &_data_phase : nullptr;
}

void DiffChunk::set_phase(const NodePhase &value) {
  _flags[0] |= 2; _data_phase = value;
}

NodeChange *DiffChunk::displayNode() {
  return _data_displayNode;
}

const NodeChange *DiffChunk::displayNode() const {
  return _data_displayNode;
}

void DiffChunk::set_displayNode(NodeChange *value) {
  _data_displayNode = value;
}

GUID *DiffChunk::canvasId() {
  return _data_canvasId;
}

const GUID *DiffChunk::canvasId() const {
  return _data_canvasId;
}

void DiffChunk::set_canvasId(GUID *value) {
  _data_canvasId = value;
}

kiwi::String *DiffChunk::canvasName() {
  return _flags[0] & 16 ? &_data_canvasName : nullptr;
}

const kiwi::String *DiffChunk::canvasName() const {
  return _flags[0] & 16 ? &_data_canvasName : nullptr;
}

void DiffChunk::set_canvasName(const kiwi::String &value) {
  _flags[0] |= 16; _data_canvasName = value;
}

bool *DiffChunk::canvasIsInternal() {
  return _flags[0] & 32 ? &_data_canvasIsInternal : nullptr;
}

const bool *DiffChunk::canvasIsInternal() const {
  return _flags[0] & 32 ? &_data_canvasIsInternal : nullptr;
}

void DiffChunk::set_canvasIsInternal(const bool &value) {
  _flags[0] |= 32; _data_canvasIsInternal = value;
}

kiwi::Array<uint32_t> *DiffChunk::chunksAffectingThisChunk() {
  return _flags[0] & 64 ? &_data_chunksAffectingThisChunk : nullptr;
}

const kiwi::Array<uint32_t> *DiffChunk::chunksAffectingThisChunk() const {
  return _flags[0] & 64 ? &_data_chunksAffectingThisChunk : nullptr;
}

kiwi::Array<uint32_t> &DiffChunk::set_chunksAffectingThisChunk(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[0] |= 64; return _data_chunksAffectingThisChunk = pool.array<uint32_t>(count);
}

kiwi::Array<NodeChange> *DiffChunk::basisParentHierarchy() {
  return _flags[0] & 128 ? &_data_basisParentHierarchy : nullptr;
}

const kiwi::Array<NodeChange> *DiffChunk::basisParentHierarchy() const {
  return _flags[0] & 128 ? &_data_basisParentHierarchy : nullptr;
}

kiwi::Array<NodeChange> &DiffChunk::set_basisParentHierarchy(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[0] |= 128; return _data_basisParentHierarchy = pool.array<NodeChange>(count);
}

kiwi::Array<NodeChange> *DiffChunk::parentHierarchy() {
  return _flags[0] & 256 ? &_data_parentHierarchy : nullptr;
}

const kiwi::Array<NodeChange> *DiffChunk::parentHierarchy() const {
  return _flags[0] & 256 ? &_data_parentHierarchy : nullptr;
}

kiwi::Array<NodeChange> &DiffChunk::set_parentHierarchy(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[0] |= 256; return _data_parentHierarchy = pool.array<NodeChange>(count);
}

kiwi::Array<GUID> *DiffChunk::basisParentHierarchyGuids() {
  return _flags[0] & 512 ? &_data_basisParentHierarchyGuids : nullptr;
}

const kiwi::Array<GUID> *DiffChunk::basisParentHierarchyGuids() const {
  return _flags[0] & 512 ? &_data_basisParentHierarchyGuids : nullptr;
}

kiwi::Array<GUID> &DiffChunk::set_basisParentHierarchyGuids(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[0] |= 512; return _data_basisParentHierarchyGuids = pool.array<GUID>(count);
}

kiwi::Array<GUID> *DiffChunk::parentHierarchyGuids() {
  return _flags[0] & 1024 ? &_data_parentHierarchyGuids : nullptr;
}

const kiwi::Array<GUID> *DiffChunk::parentHierarchyGuids() const {
  return _flags[0] & 1024 ? &_data_parentHierarchyGuids : nullptr;
}

kiwi::Array<GUID> &DiffChunk::set_parentHierarchyGuids(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[0] |= 1024; return _data_parentHierarchyGuids = pool.array<GUID>(count);
}

bool DiffChunk::encode(kiwi::ByteBuffer &_bb) {
  if (nodeChanges() != nullptr) {
    _bb.writeVarUint(1);
    _bb.writeVarUint(_data_nodeChanges.size());
    for (uint32_t &_it : _data_nodeChanges) _bb.writeVarUint(_it);
  }
  if (phase() != nullptr) {
    _bb.writeVarUint(2);
    _bb.writeVarUint(static_cast<uint32_t>(_data_phase));
  }
  if (displayNode() != nullptr) {
    _bb.writeVarUint(3);
    if (!_data_displayNode->encode(_bb)) return false;
  }
  if (canvasId() != nullptr) {
    _bb.writeVarUint(4);
    if (!_data_canvasId->encode(_bb)) return false;
  }
  if (canvasName() != nullptr) {
    _bb.writeVarUint(5);
    _bb.writeString(_data_canvasName.c_str());
  }
  if (canvasIsInternal() != nullptr) {
    _bb.writeVarUint(6);
    _bb.writeByte(_data_canvasIsInternal);
  }
  if (chunksAffectingThisChunk() != nullptr) {
    _bb.writeVarUint(7);
    _bb.writeVarUint(_data_chunksAffectingThisChunk.size());
    for (uint32_t &_it : _data_chunksAffectingThisChunk) _bb.writeVarUint(_it);
  }
  if (basisParentHierarchy() != nullptr) {
    _bb.writeVarUint(8);
    _bb.writeVarUint(_data_basisParentHierarchy.size());
    for (NodeChange &_it : _data_basisParentHierarchy) if (!_it.encode(_bb)) return false;
  }
  if (parentHierarchy() != nullptr) {
    _bb.writeVarUint(9);
    _bb.writeVarUint(_data_parentHierarchy.size());
    for (NodeChange &_it : _data_parentHierarchy) if (!_it.encode(_bb)) return false;
  }
  if (basisParentHierarchyGuids() != nullptr) {
    _bb.writeVarUint(10);
    _bb.writeVarUint(_data_basisParentHierarchyGuids.size());
    for (GUID &_it : _data_basisParentHierarchyGuids) if (!_it.encode(_bb)) return false;
  }
  if (parentHierarchyGuids() != nullptr) {
    _bb.writeVarUint(11);
    _bb.writeVarUint(_data_parentHierarchyGuids.size());
    for (GUID &_it : _data_parentHierarchyGuids) if (!_it.encode(_bb)) return false;
  }
  _bb.writeVarUint(0);
  return true;
}

bool DiffChunk::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  uint32_t _count;
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        if (!_bb.readVarUint(_count)) return false;
        for (uint32_t &_it : set_nodeChanges(_pool, _count)) if (!_bb.readVarUint(_it)) return false;
        break;
      }
      case 2: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_phase))) return false;
        set_phase(_data_phase);
        break;
      }
      case 3: {
        _data_displayNode = _pool.allocate<NodeChange>();
        if (!_data_displayNode->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 4: {
        _data_canvasId = _pool.allocate<GUID>();
        if (!_data_canvasId->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 5: {
        if (!_bb.readString(_data_canvasName, _pool)) return false;
        set_canvasName(_data_canvasName);
        break;
      }
      case 6: {
        if (!_bb.readByte(_data_canvasIsInternal)) return false;
        set_canvasIsInternal(_data_canvasIsInternal);
        break;
      }
      case 7: {
        if (!_bb.readVarUint(_count)) return false;
        for (uint32_t &_it : set_chunksAffectingThisChunk(_pool, _count)) if (!_bb.readVarUint(_it)) return false;
        break;
      }
      case 8: {
        if (!_bb.readVarUint(_count)) return false;
        for (NodeChange &_it : set_basisParentHierarchy(_pool, _count)) if (!_it.decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 9: {
        if (!_bb.readVarUint(_count)) return false;
        for (NodeChange &_it : set_parentHierarchy(_pool, _count)) if (!_it.decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 10: {
        if (!_bb.readVarUint(_count)) return false;
        for (GUID &_it : set_basisParentHierarchyGuids(_pool, _count)) if (!_it.decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 11: {
        if (!_bb.readVarUint(_count)) return false;
        for (GUID &_it : set_parentHierarchyGuids(_pool, _count)) if (!_it.decode(_bb, _pool, _schema)) return false;
        break;
      }
      default: {
        if (!_schema || !_schema->skipDiffChunkField(_bb, _type)) return false;
        break;
      }
    }
  }
}

kiwi::Array<NodeChange> *DiffPayload::nodeChanges() {
  return _flags[0] & 1 ? &_data_nodeChanges : nullptr;
}

const kiwi::Array<NodeChange> *DiffPayload::nodeChanges() const {
  return _flags[0] & 1 ? &_data_nodeChanges : nullptr;
}

kiwi::Array<NodeChange> &DiffPayload::set_nodeChanges(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[0] |= 1; return _data_nodeChanges = pool.array<NodeChange>(count);
}

kiwi::Array<Blob> *DiffPayload::blobs() {
  return _flags[0] & 2 ? &_data_blobs : nullptr;
}

const kiwi::Array<Blob> *DiffPayload::blobs() const {
  return _flags[0] & 2 ? &_data_blobs : nullptr;
}

kiwi::Array<Blob> &DiffPayload::set_blobs(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[0] |= 2; return _data_blobs = pool.array<Blob>(count);
}

kiwi::Array<DiffChunk> *DiffPayload::diffChunks() {
  return _flags[0] & 4 ? &_data_diffChunks : nullptr;
}

const kiwi::Array<DiffChunk> *DiffPayload::diffChunks() const {
  return _flags[0] & 4 ? &_data_diffChunks : nullptr;
}

kiwi::Array<DiffChunk> &DiffPayload::set_diffChunks(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[0] |= 4; return _data_diffChunks = pool.array<DiffChunk>(count);
}

kiwi::Array<NodeChange> *DiffPayload::diffBasis() {
  return _flags[0] & 8 ? &_data_diffBasis : nullptr;
}

const kiwi::Array<NodeChange> *DiffPayload::diffBasis() const {
  return _flags[0] & 8 ? &_data_diffBasis : nullptr;
}

kiwi::Array<NodeChange> &DiffPayload::set_diffBasis(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[0] |= 8; return _data_diffBasis = pool.array<NodeChange>(count);
}

kiwi::Array<NodeChange> *DiffPayload::basisParentNodeChanges() {
  return _flags[0] & 16 ? &_data_basisParentNodeChanges : nullptr;
}

const kiwi::Array<NodeChange> *DiffPayload::basisParentNodeChanges() const {
  return _flags[0] & 16 ? &_data_basisParentNodeChanges : nullptr;
}

kiwi::Array<NodeChange> &DiffPayload::set_basisParentNodeChanges(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[0] |= 16; return _data_basisParentNodeChanges = pool.array<NodeChange>(count);
}

kiwi::Array<NodeChange> *DiffPayload::parentNodeChanges() {
  return _flags[0] & 32 ? &_data_parentNodeChanges : nullptr;
}

const kiwi::Array<NodeChange> *DiffPayload::parentNodeChanges() const {
  return _flags[0] & 32 ? &_data_parentNodeChanges : nullptr;
}

kiwi::Array<NodeChange> &DiffPayload::set_parentNodeChanges(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[0] |= 32; return _data_parentNodeChanges = pool.array<NodeChange>(count);
}

bool DiffPayload::encode(kiwi::ByteBuffer &_bb) {
  if (nodeChanges() != nullptr) {
    _bb.writeVarUint(1);
    _bb.writeVarUint(_data_nodeChanges.size());
    for (NodeChange &_it : _data_nodeChanges) if (!_it.encode(_bb)) return false;
  }
  if (blobs() != nullptr) {
    _bb.writeVarUint(2);
    _bb.writeVarUint(_data_blobs.size());
    for (Blob &_it : _data_blobs) if (!_it.encode(_bb)) return false;
  }
  if (diffChunks() != nullptr) {
    _bb.writeVarUint(3);
    _bb.writeVarUint(_data_diffChunks.size());
    for (DiffChunk &_it : _data_diffChunks) if (!_it.encode(_bb)) return false;
  }
  if (diffBasis() != nullptr) {
    _bb.writeVarUint(4);
    _bb.writeVarUint(_data_diffBasis.size());
    for (NodeChange &_it : _data_diffBasis) if (!_it.encode(_bb)) return false;
  }
  if (basisParentNodeChanges() != nullptr) {
    _bb.writeVarUint(5);
    _bb.writeVarUint(_data_basisParentNodeChanges.size());
    for (NodeChange &_it : _data_basisParentNodeChanges) if (!_it.encode(_bb)) return false;
  }
  if (parentNodeChanges() != nullptr) {
    _bb.writeVarUint(6);
    _bb.writeVarUint(_data_parentNodeChanges.size());
    for (NodeChange &_it : _data_parentNodeChanges) if (!_it.encode(_bb)) return false;
  }
  _bb.writeVarUint(0);
  return true;
}

bool DiffPayload::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  uint32_t _count;
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        if (!_bb.readVarUint(_count)) return false;
        for (NodeChange &_it : set_nodeChanges(_pool, _count)) if (!_it.decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 2: {
        if (!_bb.readVarUint(_count)) return false;
        for (Blob &_it : set_blobs(_pool, _count)) if (!_it.decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 3: {
        if (!_bb.readVarUint(_count)) return false;
        for (DiffChunk &_it : set_diffChunks(_pool, _count)) if (!_it.decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 4: {
        if (!_bb.readVarUint(_count)) return false;
        for (NodeChange &_it : set_diffBasis(_pool, _count)) if (!_it.decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 5: {
        if (!_bb.readVarUint(_count)) return false;
        for (NodeChange &_it : set_basisParentNodeChanges(_pool, _count)) if (!_it.decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 6: {
        if (!_bb.readVarUint(_count)) return false;
        for (NodeChange &_it : set_parentNodeChanges(_pool, _count)) if (!_it.decode(_bb, _pool, _schema)) return false;
        break;
      }
      default: {
        if (!_schema || !_schema->skipDiffPayloadField(_bb, _type)) return false;
        break;
      }
    }
  }
}

kiwi::String *RichMediaData::mediaHash() {
  return _flags[0] & 1 ? &_data_mediaHash : nullptr;
}

const kiwi::String *RichMediaData::mediaHash() const {
  return _flags[0] & 1 ? &_data_mediaHash : nullptr;
}

void RichMediaData::set_mediaHash(const kiwi::String &value) {
  _flags[0] |= 1; _data_mediaHash = value;
}

RichMediaType *RichMediaData::richMediaType() {
  return _flags[0] & 2 ? &_data_richMediaType : nullptr;
}

const RichMediaType *RichMediaData::richMediaType() const {
  return _flags[0] & 2 ? &_data_richMediaType : nullptr;
}

void RichMediaData::set_richMediaType(const RichMediaType &value) {
  _flags[0] |= 2; _data_richMediaType = value;
}

bool RichMediaData::encode(kiwi::ByteBuffer &_bb) {
  if (mediaHash() != nullptr) {
    _bb.writeVarUint(1);
    _bb.writeString(_data_mediaHash.c_str());
  }
  if (richMediaType() != nullptr) {
    _bb.writeVarUint(2);
    _bb.writeVarUint(static_cast<uint32_t>(_data_richMediaType));
  }
  _bb.writeVarUint(0);
  return true;
}

bool RichMediaData::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        if (!_bb.readString(_data_mediaHash, _pool)) return false;
        set_mediaHash(_data_mediaHash);
        break;
      }
      case 2: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_richMediaType))) return false;
        set_richMediaType(_data_richMediaType);
        break;
      }
      default: {
        if (!_schema || !_schema->skipRichMediaDataField(_bb, _type)) return false;
        break;
      }
    }
  }
}

bool *VariableAnyValue::boolValue() {
  return _flags[0] & 1 ? &_data_boolValue : nullptr;
}

const bool *VariableAnyValue::boolValue() const {
  return _flags[0] & 1 ? &_data_boolValue : nullptr;
}

void VariableAnyValue::set_boolValue(const bool &value) {
  _flags[0] |= 1; _data_boolValue = value;
}

kiwi::String *VariableAnyValue::textValue() {
  return _flags[0] & 2 ? &_data_textValue : nullptr;
}

const kiwi::String *VariableAnyValue::textValue() const {
  return _flags[0] & 2 ? &_data_textValue : nullptr;
}

void VariableAnyValue::set_textValue(const kiwi::String &value) {
  _flags[0] |= 2; _data_textValue = value;
}

float *VariableAnyValue::floatValue() {
  return _flags[0] & 4 ? &_data_floatValue : nullptr;
}

const float *VariableAnyValue::floatValue() const {
  return _flags[0] & 4 ? &_data_floatValue : nullptr;
}

void VariableAnyValue::set_floatValue(const float &value) {
  _flags[0] |= 4; _data_floatValue = value;
}

VariableID *VariableAnyValue::alias() {
  return _data_alias;
}

const VariableID *VariableAnyValue::alias() const {
  return _data_alias;
}

void VariableAnyValue::set_alias(VariableID *value) {
  _data_alias = value;
}

Color *VariableAnyValue::colorValue() {
  return _data_colorValue;
}

const Color *VariableAnyValue::colorValue() const {
  return _data_colorValue;
}

void VariableAnyValue::set_colorValue(Color *value) {
  _data_colorValue = value;
}

Expression *VariableAnyValue::expressionValue() {
  return _data_expressionValue;
}

const Expression *VariableAnyValue::expressionValue() const {
  return _data_expressionValue;
}

void VariableAnyValue::set_expressionValue(Expression *value) {
  _data_expressionValue = value;
}

VariableMap *VariableAnyValue::mapValue() {
  return _data_mapValue;
}

const VariableMap *VariableAnyValue::mapValue() const {
  return _data_mapValue;
}

void VariableAnyValue::set_mapValue(VariableMap *value) {
  _data_mapValue = value;
}

SymbolId *VariableAnyValue::symbolIdValue() {
  return _data_symbolIdValue;
}

const SymbolId *VariableAnyValue::symbolIdValue() const {
  return _data_symbolIdValue;
}

void VariableAnyValue::set_symbolIdValue(SymbolId *value) {
  _data_symbolIdValue = value;
}

bool VariableAnyValue::encode(kiwi::ByteBuffer &_bb) {
  if (boolValue() != nullptr) {
    _bb.writeVarUint(1);
    _bb.writeByte(_data_boolValue);
  }
  if (textValue() != nullptr) {
    _bb.writeVarUint(2);
    _bb.writeString(_data_textValue.c_str());
  }
  if (floatValue() != nullptr) {
    _bb.writeVarUint(3);
    _bb.writeVarFloat(_data_floatValue);
  }
  if (alias() != nullptr) {
    _bb.writeVarUint(4);
    if (!_data_alias->encode(_bb)) return false;
  }
  if (colorValue() != nullptr) {
    _bb.writeVarUint(5);
    if (!_data_colorValue->encode(_bb)) return false;
  }
  if (expressionValue() != nullptr) {
    _bb.writeVarUint(6);
    if (!_data_expressionValue->encode(_bb)) return false;
  }
  if (mapValue() != nullptr) {
    _bb.writeVarUint(7);
    if (!_data_mapValue->encode(_bb)) return false;
  }
  if (symbolIdValue() != nullptr) {
    _bb.writeVarUint(8);
    if (!_data_symbolIdValue->encode(_bb)) return false;
  }
  _bb.writeVarUint(0);
  return true;
}

bool VariableAnyValue::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        if (!_bb.readByte(_data_boolValue)) return false;
        set_boolValue(_data_boolValue);
        break;
      }
      case 2: {
        if (!_bb.readString(_data_textValue, _pool)) return false;
        set_textValue(_data_textValue);
        break;
      }
      case 3: {
        if (!_bb.readVarFloat(_data_floatValue)) return false;
        set_floatValue(_data_floatValue);
        break;
      }
      case 4: {
        _data_alias = _pool.allocate<VariableID>();
        if (!_data_alias->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 5: {
        _data_colorValue = _pool.allocate<Color>();
        if (!_data_colorValue->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 6: {
        _data_expressionValue = _pool.allocate<Expression>();
        if (!_data_expressionValue->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 7: {
        _data_mapValue = _pool.allocate<VariableMap>();
        if (!_data_mapValue->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 8: {
        _data_symbolIdValue = _pool.allocate<SymbolId>();
        if (!_data_symbolIdValue->decode(_bb, _pool, _schema)) return false;
        break;
      }
      default: {
        if (!_schema || !_schema->skipVariableAnyValueField(_bb, _type)) return false;
        break;
      }
    }
  }
}

ExpressionFunction *Expression::expressionFunction() {
  return _flags[0] & 1 ? &_data_expressionFunction : nullptr;
}

const ExpressionFunction *Expression::expressionFunction() const {
  return _flags[0] & 1 ? &_data_expressionFunction : nullptr;
}

void Expression::set_expressionFunction(const ExpressionFunction &value) {
  _flags[0] |= 1; _data_expressionFunction = value;
}

kiwi::Array<VariableData> *Expression::expressionArguments() {
  return _flags[0] & 2 ? &_data_expressionArguments : nullptr;
}

const kiwi::Array<VariableData> *Expression::expressionArguments() const {
  return _flags[0] & 2 ? &_data_expressionArguments : nullptr;
}

kiwi::Array<VariableData> &Expression::set_expressionArguments(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[0] |= 2; return _data_expressionArguments = pool.array<VariableData>(count);
}

bool Expression::encode(kiwi::ByteBuffer &_bb) {
  if (expressionFunction() != nullptr) {
    _bb.writeVarUint(1);
    _bb.writeVarUint(static_cast<uint32_t>(_data_expressionFunction));
  }
  if (expressionArguments() != nullptr) {
    _bb.writeVarUint(2);
    _bb.writeVarUint(_data_expressionArguments.size());
    for (VariableData &_it : _data_expressionArguments) if (!_it.encode(_bb)) return false;
  }
  _bb.writeVarUint(0);
  return true;
}

bool Expression::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  uint32_t _count;
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_expressionFunction))) return false;
        set_expressionFunction(_data_expressionFunction);
        break;
      }
      case 2: {
        if (!_bb.readVarUint(_count)) return false;
        for (VariableData &_it : set_expressionArguments(_pool, _count)) if (!_it.decode(_bb, _pool, _schema)) return false;
        break;
      }
      default: {
        if (!_schema || !_schema->skipExpressionField(_bb, _type)) return false;
        break;
      }
    }
  }
}

kiwi::String *VariableMapValue::key() {
  return _flags[0] & 1 ? &_data_key : nullptr;
}

const kiwi::String *VariableMapValue::key() const {
  return _flags[0] & 1 ? &_data_key : nullptr;
}

void VariableMapValue::set_key(const kiwi::String &value) {
  _flags[0] |= 1; _data_key = value;
}

VariableData *VariableMapValue::value() {
  return _data_value;
}

const VariableData *VariableMapValue::value() const {
  return _data_value;
}

void VariableMapValue::set_value(VariableData *value) {
  _data_value = value;
}

bool VariableMapValue::encode(kiwi::ByteBuffer &_bb) {
  if (key() != nullptr) {
    _bb.writeVarUint(1);
    _bb.writeString(_data_key.c_str());
  }
  if (value() != nullptr) {
    _bb.writeVarUint(2);
    if (!_data_value->encode(_bb)) return false;
  }
  _bb.writeVarUint(0);
  return true;
}

bool VariableMapValue::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        if (!_bb.readString(_data_key, _pool)) return false;
        set_key(_data_key);
        break;
      }
      case 2: {
        _data_value = _pool.allocate<VariableData>();
        if (!_data_value->decode(_bb, _pool, _schema)) return false;
        break;
      }
      default: {
        if (!_schema || !_schema->skipVariableMapValueField(_bb, _type)) return false;
        break;
      }
    }
  }
}

kiwi::Array<VariableMapValue> *VariableMap::values() {
  return _flags[0] & 1 ? &_data_values : nullptr;
}

const kiwi::Array<VariableMapValue> *VariableMap::values() const {
  return _flags[0] & 1 ? &_data_values : nullptr;
}

kiwi::Array<VariableMapValue> &VariableMap::set_values(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[0] |= 1; return _data_values = pool.array<VariableMapValue>(count);
}

bool VariableMap::encode(kiwi::ByteBuffer &_bb) {
  if (values() != nullptr) {
    _bb.writeVarUint(1);
    _bb.writeVarUint(_data_values.size());
    for (VariableMapValue &_it : _data_values) if (!_it.encode(_bb)) return false;
  }
  _bb.writeVarUint(0);
  return true;
}

bool VariableMap::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  uint32_t _count;
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        if (!_bb.readVarUint(_count)) return false;
        for (VariableMapValue &_it : set_values(_pool, _count)) if (!_it.decode(_bb, _pool, _schema)) return false;
        break;
      }
      default: {
        if (!_schema || !_schema->skipVariableMapField(_bb, _type)) return false;
        break;
      }
    }
  }
}

VariableAnyValue *VariableData::value() {
  return _data_value;
}

const VariableAnyValue *VariableData::value() const {
  return _data_value;
}

void VariableData::set_value(VariableAnyValue *value) {
  _data_value = value;
}

VariableDataType *VariableData::dataType() {
  return _flags[0] & 2 ? &_data_dataType : nullptr;
}

const VariableDataType *VariableData::dataType() const {
  return _flags[0] & 2 ? &_data_dataType : nullptr;
}

void VariableData::set_dataType(const VariableDataType &value) {
  _flags[0] |= 2; _data_dataType = value;
}

VariableResolvedDataType *VariableData::resolvedDataType() {
  return _flags[0] & 4 ? &_data_resolvedDataType : nullptr;
}

const VariableResolvedDataType *VariableData::resolvedDataType() const {
  return _flags[0] & 4 ? &_data_resolvedDataType : nullptr;
}

void VariableData::set_resolvedDataType(const VariableResolvedDataType &value) {
  _flags[0] |= 4; _data_resolvedDataType = value;
}

bool VariableData::encode(kiwi::ByteBuffer &_bb) {
  if (value() != nullptr) {
    _bb.writeVarUint(1);
    if (!_data_value->encode(_bb)) return false;
  }
  if (dataType() != nullptr) {
    _bb.writeVarUint(2);
    _bb.writeVarUint(static_cast<uint32_t>(_data_dataType));
  }
  if (resolvedDataType() != nullptr) {
    _bb.writeVarUint(3);
    _bb.writeVarUint(static_cast<uint32_t>(_data_resolvedDataType));
  }
  _bb.writeVarUint(0);
  return true;
}

bool VariableData::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        _data_value = _pool.allocate<VariableAnyValue>();
        if (!_data_value->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 2: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_dataType))) return false;
        set_dataType(_data_dataType);
        break;
      }
      case 3: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_resolvedDataType))) return false;
        set_resolvedDataType(_data_resolvedDataType);
        break;
      }
      default: {
        if (!_schema || !_schema->skipVariableDataField(_bb, _type)) return false;
        break;
      }
    }
  }
}

GUID *VariableSetMode::id() {
  return _data_id;
}

const GUID *VariableSetMode::id() const {
  return _data_id;
}

void VariableSetMode::set_id(GUID *value) {
  _data_id = value;
}

kiwi::String *VariableSetMode::name() {
  return _flags[0] & 2 ? &_data_name : nullptr;
}

const kiwi::String *VariableSetMode::name() const {
  return _flags[0] & 2 ? &_data_name : nullptr;
}

void VariableSetMode::set_name(const kiwi::String &value) {
  _flags[0] |= 2; _data_name = value;
}

kiwi::String *VariableSetMode::sortPosition() {
  return _flags[0] & 4 ? &_data_sortPosition : nullptr;
}

const kiwi::String *VariableSetMode::sortPosition() const {
  return _flags[0] & 4 ? &_data_sortPosition : nullptr;
}

void VariableSetMode::set_sortPosition(const kiwi::String &value) {
  _flags[0] |= 4; _data_sortPosition = value;
}

bool VariableSetMode::encode(kiwi::ByteBuffer &_bb) {
  if (id() != nullptr) {
    _bb.writeVarUint(1);
    if (!_data_id->encode(_bb)) return false;
  }
  if (name() != nullptr) {
    _bb.writeVarUint(2);
    _bb.writeString(_data_name.c_str());
  }
  if (sortPosition() != nullptr) {
    _bb.writeVarUint(3);
    _bb.writeString(_data_sortPosition.c_str());
  }
  _bb.writeVarUint(0);
  return true;
}

bool VariableSetMode::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        _data_id = _pool.allocate<GUID>();
        if (!_data_id->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 2: {
        if (!_bb.readString(_data_name, _pool)) return false;
        set_name(_data_name);
        break;
      }
      case 3: {
        if (!_bb.readString(_data_sortPosition, _pool)) return false;
        set_sortPosition(_data_sortPosition);
        break;
      }
      default: {
        if (!_schema || !_schema->skipVariableSetModeField(_bb, _type)) return false;
        break;
      }
    }
  }
}

kiwi::Array<VariableDataValuesEntry> *VariableDataValues::entries() {
  return _flags[0] & 1 ? &_data_entries : nullptr;
}

const kiwi::Array<VariableDataValuesEntry> *VariableDataValues::entries() const {
  return _flags[0] & 1 ? &_data_entries : nullptr;
}

kiwi::Array<VariableDataValuesEntry> &VariableDataValues::set_entries(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[0] |= 1; return _data_entries = pool.array<VariableDataValuesEntry>(count);
}

bool VariableDataValues::encode(kiwi::ByteBuffer &_bb) {
  if (entries() != nullptr) {
    _bb.writeVarUint(1);
    _bb.writeVarUint(_data_entries.size());
    for (VariableDataValuesEntry &_it : _data_entries) if (!_it.encode(_bb)) return false;
  }
  _bb.writeVarUint(0);
  return true;
}

bool VariableDataValues::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  uint32_t _count;
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        if (!_bb.readVarUint(_count)) return false;
        for (VariableDataValuesEntry &_it : set_entries(_pool, _count)) if (!_it.decode(_bb, _pool, _schema)) return false;
        break;
      }
      default: {
        if (!_schema || !_schema->skipVariableDataValuesField(_bb, _type)) return false;
        break;
      }
    }
  }
}

GUID *VariableDataValuesEntry::modeID() {
  return _data_modeID;
}

const GUID *VariableDataValuesEntry::modeID() const {
  return _data_modeID;
}

void VariableDataValuesEntry::set_modeID(GUID *value) {
  _data_modeID = value;
}

VariableData *VariableDataValuesEntry::variableData() {
  return _data_variableData;
}

const VariableData *VariableDataValuesEntry::variableData() const {
  return _data_variableData;
}

void VariableDataValuesEntry::set_variableData(VariableData *value) {
  _data_variableData = value;
}

bool VariableDataValuesEntry::encode(kiwi::ByteBuffer &_bb) {
  if (modeID() != nullptr) {
    _bb.writeVarUint(1);
    if (!_data_modeID->encode(_bb)) return false;
  }
  if (variableData() != nullptr) {
    _bb.writeVarUint(2);
    if (!_data_variableData->encode(_bb)) return false;
  }
  _bb.writeVarUint(0);
  return true;
}

bool VariableDataValuesEntry::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        _data_modeID = _pool.allocate<GUID>();
        if (!_data_modeID->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 2: {
        _data_variableData = _pool.allocate<VariableData>();
        if (!_data_variableData->decode(_bb, _pool, _schema)) return false;
        break;
      }
      default: {
        if (!_schema || !_schema->skipVariableDataValuesEntryField(_bb, _type)) return false;
        break;
      }
    }
  }
}

Vector *OptionalVector::value() {
  return _data_value;
}

const Vector *OptionalVector::value() const {
  return _data_value;
}

void OptionalVector::set_value(Vector *value) {
  _data_value = value;
}

bool OptionalVector::encode(kiwi::ByteBuffer &_bb) {
  if (value() != nullptr) {
    _bb.writeVarUint(1);
    if (!_data_value->encode(_bb)) return false;
  }
  _bb.writeVarUint(0);
  return true;
}

bool OptionalVector::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        _data_value = _pool.allocate<Vector>();
        if (!_data_value->decode(_bb, _pool, _schema)) return false;
        break;
      }
      default: {
        if (!_schema || !_schema->skipOptionalVectorField(_bb, _type)) return false;
        break;
      }
    }
  }
}

bool *MigrationStatus::dsdCleanup() {
  return _flags[0] & 1 ? &_data_dsdCleanup : nullptr;
}

const bool *MigrationStatus::dsdCleanup() const {
  return _flags[0] & 1 ? &_data_dsdCleanup : nullptr;
}

void MigrationStatus::set_dsdCleanup(const bool &value) {
  _flags[0] |= 1; _data_dsdCleanup = value;
}

bool MigrationStatus::encode(kiwi::ByteBuffer &_bb) {
  if (dsdCleanup() != nullptr) {
    _bb.writeVarUint(1);
    _bb.writeByte(_data_dsdCleanup);
  }
  _bb.writeVarUint(0);
  return true;
}

bool MigrationStatus::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        if (!_bb.readByte(_data_dsdCleanup)) return false;
        set_dsdCleanup(_data_dsdCleanup);
        break;
      }
      default: {
        if (!_schema || !_schema->skipMigrationStatusField(_bb, _type)) return false;
        break;
      }
    }
  }
}

kiwi::Array<NodeFieldMapEntry> *NodeFieldMap::entries() {
  return _flags[0] & 1 ? &_data_entries : nullptr;
}

const kiwi::Array<NodeFieldMapEntry> *NodeFieldMap::entries() const {
  return _flags[0] & 1 ? &_data_entries : nullptr;
}

kiwi::Array<NodeFieldMapEntry> &NodeFieldMap::set_entries(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[0] |= 1; return _data_entries = pool.array<NodeFieldMapEntry>(count);
}

bool NodeFieldMap::encode(kiwi::ByteBuffer &_bb) {
  if (entries() != nullptr) {
    _bb.writeVarUint(1);
    _bb.writeVarUint(_data_entries.size());
    for (NodeFieldMapEntry &_it : _data_entries) if (!_it.encode(_bb)) return false;
  }
  _bb.writeVarUint(0);
  return true;
}

bool NodeFieldMap::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  uint32_t _count;
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        if (!_bb.readVarUint(_count)) return false;
        for (NodeFieldMapEntry &_it : set_entries(_pool, _count)) if (!_it.decode(_bb, _pool, _schema)) return false;
        break;
      }
      default: {
        if (!_schema || !_schema->skipNodeFieldMapField(_bb, _type)) return false;
        break;
      }
    }
  }
}

GUID *NodeFieldMapEntry::guid() {
  return _data_guid;
}

const GUID *NodeFieldMapEntry::guid() const {
  return _data_guid;
}

void NodeFieldMapEntry::set_guid(GUID *value) {
  _data_guid = value;
}

uint32_t *NodeFieldMapEntry::field() {
  return _flags[0] & 2 ? &_data_field : nullptr;
}

const uint32_t *NodeFieldMapEntry::field() const {
  return _flags[0] & 2 ? &_data_field : nullptr;
}

void NodeFieldMapEntry::set_field(const uint32_t &value) {
  _flags[0] |= 2; _data_field = value;
}

uint32_t *NodeFieldMapEntry::lastModifiedSequenceNumber() {
  return _flags[0] & 4 ? &_data_lastModifiedSequenceNumber : nullptr;
}

const uint32_t *NodeFieldMapEntry::lastModifiedSequenceNumber() const {
  return _flags[0] & 4 ? &_data_lastModifiedSequenceNumber : nullptr;
}

void NodeFieldMapEntry::set_lastModifiedSequenceNumber(const uint32_t &value) {
  _flags[0] |= 4; _data_lastModifiedSequenceNumber = value;
}

bool NodeFieldMapEntry::encode(kiwi::ByteBuffer &_bb) {
  if (guid() != nullptr) {
    _bb.writeVarUint(1);
    if (!_data_guid->encode(_bb)) return false;
  }
  if (field() != nullptr) {
    _bb.writeVarUint(2);
    _bb.writeVarUint(_data_field);
  }
  if (lastModifiedSequenceNumber() != nullptr) {
    _bb.writeVarUint(3);
    _bb.writeVarUint(_data_lastModifiedSequenceNumber);
  }
  _bb.writeVarUint(0);
  return true;
}

bool NodeFieldMapEntry::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        _data_guid = _pool.allocate<GUID>();
        if (!_data_guid->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 2: {
        if (!_bb.readVarUint(_data_field)) return false;
        set_field(_data_field);
        break;
      }
      case 3: {
        if (!_bb.readVarUint(_data_lastModifiedSequenceNumber)) return false;
        set_lastModifiedSequenceNumber(_data_lastModifiedSequenceNumber);
        break;
      }
      default: {
        if (!_schema || !_schema->skipNodeFieldMapEntryField(_bb, _type)) return false;
        break;
      }
    }
  }
}

bool *ARIAAttributeAnyValue::boolValue() {
  return _flags[0] & 1 ? &_data_boolValue : nullptr;
}

const bool *ARIAAttributeAnyValue::boolValue() const {
  return _flags[0] & 1 ? &_data_boolValue : nullptr;
}

void ARIAAttributeAnyValue::set_boolValue(const bool &value) {
  _flags[0] |= 1; _data_boolValue = value;
}

kiwi::String *ARIAAttributeAnyValue::stringValue() {
  return _flags[0] & 2 ? &_data_stringValue : nullptr;
}

const kiwi::String *ARIAAttributeAnyValue::stringValue() const {
  return _flags[0] & 2 ? &_data_stringValue : nullptr;
}

void ARIAAttributeAnyValue::set_stringValue(const kiwi::String &value) {
  _flags[0] |= 2; _data_stringValue = value;
}

float *ARIAAttributeAnyValue::floatValue() {
  return _flags[0] & 4 ? &_data_floatValue : nullptr;
}

const float *ARIAAttributeAnyValue::floatValue() const {
  return _flags[0] & 4 ? &_data_floatValue : nullptr;
}

void ARIAAttributeAnyValue::set_floatValue(const float &value) {
  _flags[0] |= 4; _data_floatValue = value;
}

int32_t *ARIAAttributeAnyValue::intValue() {
  return _flags[0] & 8 ? &_data_intValue : nullptr;
}

const int32_t *ARIAAttributeAnyValue::intValue() const {
  return _flags[0] & 8 ? &_data_intValue : nullptr;
}

void ARIAAttributeAnyValue::set_intValue(const int32_t &value) {
  _flags[0] |= 8; _data_intValue = value;
}

bool ARIAAttributeAnyValue::encode(kiwi::ByteBuffer &_bb) {
  if (boolValue() != nullptr) {
    _bb.writeVarUint(1);
    _bb.writeByte(_data_boolValue);
  }
  if (stringValue() != nullptr) {
    _bb.writeVarUint(2);
    _bb.writeString(_data_stringValue.c_str());
  }
  if (floatValue() != nullptr) {
    _bb.writeVarUint(3);
    _bb.writeVarFloat(_data_floatValue);
  }
  if (intValue() != nullptr) {
    _bb.writeVarUint(4);
    _bb.writeVarInt(_data_intValue);
  }
  _bb.writeVarUint(0);
  return true;
}

bool ARIAAttributeAnyValue::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        if (!_bb.readByte(_data_boolValue)) return false;
        set_boolValue(_data_boolValue);
        break;
      }
      case 2: {
        if (!_bb.readString(_data_stringValue, _pool)) return false;
        set_stringValue(_data_stringValue);
        break;
      }
      case 3: {
        if (!_bb.readVarFloat(_data_floatValue)) return false;
        set_floatValue(_data_floatValue);
        break;
      }
      case 4: {
        if (!_bb.readVarInt(_data_intValue)) return false;
        set_intValue(_data_intValue);
        break;
      }
      default: {
        if (!_schema || !_schema->skipARIAAttributeAnyValueField(_bb, _type)) return false;
        break;
      }
    }
  }
}

ARIAAttributeDataType *ARIAAttributeData::type() {
  return _flags[0] & 1 ? &_data_type : nullptr;
}

const ARIAAttributeDataType *ARIAAttributeData::type() const {
  return _flags[0] & 1 ? &_data_type : nullptr;
}

void ARIAAttributeData::set_type(const ARIAAttributeDataType &value) {
  _flags[0] |= 1; _data_type = value;
}

ARIAAttributeAnyValue *ARIAAttributeData::value() {
  return _data_value;
}

const ARIAAttributeAnyValue *ARIAAttributeData::value() const {
  return _data_value;
}

void ARIAAttributeData::set_value(ARIAAttributeAnyValue *value) {
  _data_value = value;
}

bool ARIAAttributeData::encode(kiwi::ByteBuffer &_bb) {
  if (type() != nullptr) {
    _bb.writeVarUint(1);
    _bb.writeVarUint(static_cast<uint32_t>(_data_type));
  }
  if (value() != nullptr) {
    _bb.writeVarUint(2);
    if (!_data_value->encode(_bb)) return false;
  }
  _bb.writeVarUint(0);
  return true;
}

bool ARIAAttributeData::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_type))) return false;
        set_type(_data_type);
        break;
      }
      case 2: {
        _data_value = _pool.allocate<ARIAAttributeAnyValue>();
        if (!_data_value->decode(_bb, _pool, _schema)) return false;
        break;
      }
      default: {
        if (!_schema || !_schema->skipARIAAttributeDataField(_bb, _type)) return false;
        break;
      }
    }
  }
}

kiwi::Array<ARIAAttributesMapEntry> *ARIAAttributesMap::entries() {
  return _flags[0] & 1 ? &_data_entries : nullptr;
}

const kiwi::Array<ARIAAttributesMapEntry> *ARIAAttributesMap::entries() const {
  return _flags[0] & 1 ? &_data_entries : nullptr;
}

kiwi::Array<ARIAAttributesMapEntry> &ARIAAttributesMap::set_entries(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[0] |= 1; return _data_entries = pool.array<ARIAAttributesMapEntry>(count);
}

bool ARIAAttributesMap::encode(kiwi::ByteBuffer &_bb) {
  if (entries() != nullptr) {
    _bb.writeVarUint(1);
    _bb.writeVarUint(_data_entries.size());
    for (ARIAAttributesMapEntry &_it : _data_entries) if (!_it.encode(_bb)) return false;
  }
  _bb.writeVarUint(0);
  return true;
}

bool ARIAAttributesMap::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  uint32_t _count;
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        if (!_bb.readVarUint(_count)) return false;
        for (ARIAAttributesMapEntry &_it : set_entries(_pool, _count)) if (!_it.decode(_bb, _pool, _schema)) return false;
        break;
      }
      default: {
        if (!_schema || !_schema->skipARIAAttributesMapField(_bb, _type)) return false;
        break;
      }
    }
  }
}

kiwi::String *ARIAAttributesMapEntry::attribute() {
  return _flags[0] & 1 ? &_data_attribute : nullptr;
}

const kiwi::String *ARIAAttributesMapEntry::attribute() const {
  return _flags[0] & 1 ? &_data_attribute : nullptr;
}

void ARIAAttributesMapEntry::set_attribute(const kiwi::String &value) {
  _flags[0] |= 1; _data_attribute = value;
}

ARIAAttributeData *ARIAAttributesMapEntry::value() {
  return _data_value;
}

const ARIAAttributeData *ARIAAttributesMapEntry::value() const {
  return _data_value;
}

void ARIAAttributesMapEntry::set_value(ARIAAttributeData *value) {
  _data_value = value;
}

bool ARIAAttributesMapEntry::encode(kiwi::ByteBuffer &_bb) {
  if (attribute() != nullptr) {
    _bb.writeVarUint(1);
    _bb.writeString(_data_attribute.c_str());
  }
  if (value() != nullptr) {
    _bb.writeVarUint(2);
    if (!_data_value->encode(_bb)) return false;
  }
  _bb.writeVarUint(0);
  return true;
}

bool ARIAAttributesMapEntry::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        if (!_bb.readString(_data_attribute, _pool)) return false;
        set_attribute(_data_attribute);
        break;
      }
      case 2: {
        _data_value = _pool.allocate<ARIAAttributeData>();
        if (!_data_value->decode(_bb, _pool, _schema)) return false;
        break;
      }
      default: {
        if (!_schema || !_schema->skipARIAAttributesMapEntryField(_bb, _type)) return false;
        break;
      }
    }
  }
}

GUID *HandoffStatusMapEntry::guid() {
  return _data_guid;
}

const GUID *HandoffStatusMapEntry::guid() const {
  return _data_guid;
}

void HandoffStatusMapEntry::set_guid(GUID *value) {
  _data_guid = value;
}

SectionStatusInfo *HandoffStatusMapEntry::handoffStatus() {
  return _data_handoffStatus;
}

const SectionStatusInfo *HandoffStatusMapEntry::handoffStatus() const {
  return _data_handoffStatus;
}

void HandoffStatusMapEntry::set_handoffStatus(SectionStatusInfo *value) {
  _data_handoffStatus = value;
}

bool HandoffStatusMapEntry::encode(kiwi::ByteBuffer &_bb) {
  if (guid() != nullptr) {
    _bb.writeVarUint(1);
    if (!_data_guid->encode(_bb)) return false;
  }
  if (handoffStatus() != nullptr) {
    _bb.writeVarUint(2);
    if (!_data_handoffStatus->encode(_bb)) return false;
  }
  _bb.writeVarUint(0);
  return true;
}

bool HandoffStatusMapEntry::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        _data_guid = _pool.allocate<GUID>();
        if (!_data_guid->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 2: {
        _data_handoffStatus = _pool.allocate<SectionStatusInfo>();
        if (!_data_handoffStatus->decode(_bb, _pool, _schema)) return false;
        break;
      }
      default: {
        if (!_schema || !_schema->skipHandoffStatusMapEntryField(_bb, _type)) return false;
        break;
      }
    }
  }
}

kiwi::Array<HandoffStatusMapEntry> *HandoffStatusMap::entries() {
  return _flags[0] & 1 ? &_data_entries : nullptr;
}

const kiwi::Array<HandoffStatusMapEntry> *HandoffStatusMap::entries() const {
  return _flags[0] & 1 ? &_data_entries : nullptr;
}

kiwi::Array<HandoffStatusMapEntry> &HandoffStatusMap::set_entries(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[0] |= 1; return _data_entries = pool.array<HandoffStatusMapEntry>(count);
}

bool HandoffStatusMap::encode(kiwi::ByteBuffer &_bb) {
  if (entries() != nullptr) {
    _bb.writeVarUint(1);
    _bb.writeVarUint(_data_entries.size());
    for (HandoffStatusMapEntry &_it : _data_entries) if (!_it.encode(_bb)) return false;
  }
  _bb.writeVarUint(0);
  return true;
}

bool HandoffStatusMap::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  uint32_t _count;
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        if (!_bb.readVarUint(_count)) return false;
        for (HandoffStatusMapEntry &_it : set_entries(_pool, _count)) if (!_it.decode(_bb, _pool, _schema)) return false;
        break;
      }
      default: {
        if (!_schema || !_schema->skipHandoffStatusMapField(_bb, _type)) return false;
        break;
      }
    }
  }
}

#endif

}
