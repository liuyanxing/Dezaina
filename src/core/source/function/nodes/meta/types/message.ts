enum MessageType {
  JOIN_START,
  NODE_CHANGES,
  USER_CHANGES,
  JOIN_END,
  SIGNAL,
  STYLE,
  STYLE_SET,
  JOIN_START_SKIP_RELOAD,
  NOTIFY_SHOULD_UPGRADE,
  UPGRADE_DONE,
  UPGRADE_REFRESH,
  SCENE_GRAPH_QUERY,
  SCENE_GRAPH_REPLY,
  DIFF,
  CLIENT_BROADCAST,
  JOIN_START_JOURNALED,
}

interface Message_KiwiOnly {
  type: MessageType;
  sessionID: uint;
  ackID: uint;
  nodeChanges: Array<NodeChange_kiwi>;
}