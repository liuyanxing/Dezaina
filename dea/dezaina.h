#pragma once

#include "base/object.h"
#include "change/change.h"
#include "event.h"
#include "interaction.h"
#include "interaction/interaction.h"
#include "render.h"
#include "resource.h"
#include "viewport/viewport.h"
#include <memory>
#include <span>

#ifdef DEA_EANBLE_RENDER
#include "render.h"
#endif

namespace dea {

class Dezaina : public event::EventEmitter, public base::NonCopyable {
public:
  Dezaina()
      : doc_(0), viewport_(), eventSystem_(), interaction_(doc_),
#ifdef DEA_EANBLE_RENDER
        render_(doc_, viewport_),
#endif
        change_() {
    resource::Resource::Init();
    init();
    // eventSystem_.initialized();
  }

  ~Dezaina() {}

  static Dezaina &instance() {
    static Dezaina instance;
    return instance;
  }

  static document::Editor &editor() { return instance().doc_.editor(); }

  static document::Document &document() { return instance().doc_; }

  static Viewport &viewport() { return instance().viewport_; }

  static interaction::Interaction &interaction() {
    return instance().interaction_;
  }

  void flush();

  bool loadDocument(char *data, size_t size) {
    auto res = doc_.load(data, size);
    doc_.dump();
    if (res) {
      eventSystem_.start();
    }
    return res;
  }
  bool loadFig(std::span<char> data);

  void loadEmptyDocument() { doc_.loadEmpty(); }

  void setViewport(uint32_t width, uint32_t height, float devicePixelRatio) {
    viewport_.update(width, height, devicePixelRatio);
  }

  void dumpDocument() { doc_.dump(); }

  void completeEvent(event::MouseEvent &event);
  void dispatchEvent(event::Event &event);

  void dispatchMouseEvent(float x, float y, event::EventType type, int button,
                          int buttons) {
    auto event = event::MouseEvent::Make(x, y, type, button, buttons);
    completeEvent(event);
    eventSystem_.dispatchEvent(event);
  }

  void dispatchKeyEvent(event::EventType type, event::KeyCode code,
                        event::KeyMode mode) {
    auto event = event::KeyEvent::Make(type, code, mode);
    eventSystem_.dispatchEvent(event);
  }

  bool isKeyPressed(event::Key code) { return eventSystem_.isKeyPressed(code); }

  void nextTick(const event::ListenerFunc &listener) {
    addEventListener(event::EventType::NextTick, listener, true);
  }

  void tick();

  auto &getDocument() { return doc_; }
  auto &getViewport() { return viewport_; }
  auto &getInteraction() { return interaction_; }
  auto &getEventSystem() { return eventSystem_; }
  auto &getChange() { return change_; }

  bool dragInterNode(const std::string &query, float dx, float dy) {
    return interaction_.dragInterNode(query, dx, dy);
  }

  bool dragInterNode(const std::string &query, float worldX, float worldY,
                     float newWorldX, float newWorldY) {
    return interaction_.dragInterNode(query, worldX, worldY, newWorldX,
                                      newWorldY);
  }

private:
  document::Document doc_;
  Viewport viewport_;
  event::EventSystem eventSystem_;

#ifdef DEA_EANBLE_RENDER
  render::Render render_;
#endif

  interaction::Interaction interaction_;
  change::Change change_;
  void init();
};

} // namespace dea
