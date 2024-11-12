#pragma once

#include "node.h"
#include "node/node.h"
#include "base/type.h"
#include <array>
#include <functional>
#include <tuple>
#include <variant>

namespace dea::document {

enum class RecordType {
  kCreate,
  kSelection,
  FillPaint,
  kSetVectorData,
  kSetFillCommandBlob,
  kSetStrokeCommandBlob,
  kLayoutRelation,
  kSetParent = kLayoutRelation,
  kTransform,
  kSetSize,
};

using SetSizeValue = std::array<node::Vector, 2>;
using CreateNodeValue = std::tuple<node::NodeType, node::Node *>;
using PaintsValue = std::vector<node::PaintUnion>;
using RecordValue =
    std::variant<float, node::Matrix, node::Node *, base::v2<float>,
                 base::v4<float>, SetSizeValue, node::NodeIdArray,
                 CreateNodeValue, PaintsValue, node::VectorData>;

struct EditRecordItem {
  EditRecordItem(const node::GUID &nodeId, RecordType type,
                 const RecordValue &value)
      : nodeId(nodeId), type(type), value(value) {}
  node::GUID nodeId;
  RecordType type;
  RecordValue value;
  bool isLayoutRelated() const {
    return type >= RecordType::kLayoutRelation;
  }
};

class Editor {
public:
  Editor() = default;
  Editor(const std::vector<node::Node *> &nodes) : nodes_(nodes){};

  bool empty() const { return records_.empty(); }
  void clear() { records_.clear(); }

  bool editSelectedNodes();
  Editor &create(node::Node *node);
  Editor &setParent(node::Node *node) {
    addRecord(RecordType::kSetParent, node);
    return *this;
  }
  Editor &createAndSelect(node::NodeType type, node::Node *parent);
  void setEditNodes(node::NodeArary &&nodes) { nodes_ = move(nodes); };
  Editor &rotate(float degrees);
  Editor &translate(node::Vector translation);
  Editor &resize(float width, float height, const node::Vector &direction);
  Editor &setTranslate(node::Vector translation);
  Editor &setSize(node::Vector size, const node::Vector &direction = {1, 1});
  Editor &setTransform(const node::Matrix &transform);

  Editor &appendSolidPaint(node::Color color);

  Editor &setVectorData(const node::VectorData& vectorData);
  Editor &setFillCommandBlob(uint32_t commandBlobId);
  Editor &setStrokeCommandBlob(uint32_t commandBlobId);

  Editor &select(const node::NodeIdArray &selection) {
    addRecord(RecordType::kSelection, selection);
    return *this;
  }

  void setImmediate(bool immediate) { immediate_ = immediate; }

  static const auto &getRecords() { return records_; }
  ~Editor() = default;

  class ScopeLock {
  public:
    ScopeLock() { locked_ = true; }
    ~ScopeLock() { locked_ = false; }
  };

private:
  std::vector<node::Node *> nodes_;
  inline static std::vector<EditRecordItem> records_;
  inline static bool immediate_ = false;
  inline static bool locked_ = false;

  void editNodes(std::function<void(node::Node *)>);
  void addRecord(const node::GUID &layerId, const RecordType &type,
                 const RecordValue &value);
  void addRecord(const RecordType &type, const RecordValue &value);
};

} // namespace dea::document
