#pragma once

#include <memory>
#include <span>
#include <string>
#include <unordered_map>

namespace loader {

class Buffer {
public:
  Buffer();
  ~Buffer() = default;

  void write(const char *data, size_t size);
  std::span<char> getBuffer() const { return {buffer_, getSize()}; }
  size_t getSize() const { return cursor_ - buffer_; }
  char *getData() const { return buffer_; }

private:
  char *buffer_;
  char *cursor_;
  size_t capacity_;

  void resize(size_t size);
};

class Loader {
public:
  Loader() = default;
  ~Loader() = default;

  bool loadFig(const std::string &filename);
  std::span<char> getFig() const;

  void addFile(const std::string &filename, std::unique_ptr<Buffer> data) {
    figFiles_[filename] = std::move(data);
  }

private:
  std::span<char> figData;
  std::unordered_map<std::string, std::unique_ptr<Buffer>> figFiles_;
};

} // namespace loader
