#include "loader.h"
#include "minizip/unzip.h"
#include <cassert>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <memory>
#include <span>

namespace loader {

Buffer::Buffer() : buffer_(nullptr), cursor_(0), capacity_(0) {}

void Buffer::resize(size_t newSize) {
  if (newSize > capacity_) {
    newSize = std::max(newSize, capacity_ * 2);
    size_t size = cursor_ - buffer_;
    capacity_ = newSize;
    auto *newBuffer = new char[newSize];
    if (buffer_) {
      memcpy(newBuffer, buffer_, size);
      delete[] buffer_;
    }
    buffer_ = newBuffer;
    cursor_ = buffer_ + size;
  }
}

void Buffer::write(const char *data, size_t size) {
  size_t newSize = getSize() + size;
  resize(newSize);
  memcpy(cursor_, data, size);
  cursor_ += size;
}

bool extractFile(unzFile zipFile, Loader &loader) {
  char buffer[8192];
  unz_file_info fileInfo;
  char filename[256];

  if (unzGetCurrentFileInfo(zipFile, &fileInfo, filename, sizeof(filename),
                            NULL, 0, NULL, 0) != UNZ_OK) {
    std::cerr << "Failed to get file info." << std::endl;
    return false;
  }

  if (unzOpenCurrentFile(zipFile) != UNZ_OK) {
    std::cerr << "Failed to open file: " << filename << std::endl;
    return false;
  }

  auto fileBuffer = std::make_unique<Buffer>();
  int bytesRead = -1;
  while ((bytesRead = unzReadCurrentFile(zipFile, buffer, sizeof(buffer))) >
         0) {
    fileBuffer->write(buffer, bytesRead);
  }

  if (bytesRead < 0) {
    std::cerr << "Error while reading the file: " << filename << std::endl;
    unzCloseCurrentFile(zipFile);
    return false;
  }
  loader.addFile(filename, std::move(fileBuffer));

  unzCloseCurrentFile(zipFile);

  return true;
}

bool extractAllFiles(const std::string &zipFilePath, Loader &loader) {
  unzFile zipFile = unzOpen(zipFilePath.c_str());
  if (!zipFile) {
    std::cerr << "Failed to open ZIP file: " << zipFilePath << std::endl;
    return false;
  }

  if (unzGoToFirstFile(zipFile) != UNZ_OK) {
    std::cerr << "Failed to go to first file in ZIP." << std::endl;
    unzClose(zipFile);
    return false;
  }

  do {
    if (!extractFile(zipFile, loader)) {
      std::cerr << "Failed to extract a file from ZIP." << std::endl;
      unzClose(zipFile);
      return false;
    }

  } while (unzGoToNextFile(zipFile) == UNZ_OK);

  unzClose(zipFile);
  return true;
}

bool Loader::loadFig(const std::string &filename) {
  std::filesystem::path fig_dir =
      std::filesystem::current_path() / "figs" / filename;
  return extractAllFiles(fig_dir.string(), *this);
}

std::span<char> Loader::getFig() const {
  auto it = figFiles_.find("canvas.fig");
  if (it == figFiles_.end()) {
    return {};
  }
  auto &buffer = it->second;
  return {buffer->getData(), buffer->getSize()};
}

} // namespace loader
