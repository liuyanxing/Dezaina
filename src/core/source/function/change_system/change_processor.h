#pragma once
#include "base_type.h"
#include "desaina_node.h"
#include "node_type.h"

class Desaina;

class ChangeProcessor {
public:
  ChangeProcessor(Desaina* desaina) : desaina_(desaina) {};
  ~ChangeProcessor() = default;

  bool processMessage(kiwi::ByteBuffer& buffer);
  bool processMessage(const Desaina_Kiwi::Message& message);
private:
  void applyNodeChanges(const Desaina_Kiwi::Message& message);
  Node* applyNodeChange(const Desaina_Kiwi::NodeChange& node_change);

  void remapBlobId();

  Desaina* desaina_;
  vector<Node*> message_nodes_;
  unordered_map<uint32_t, uint32_t> blob_id_remap_{};
};