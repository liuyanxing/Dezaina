#include "dezaina.h"
#include "loader.h"
#include <gtest/gtest.h>

auto &dezaina = dea::Dezaina::instance();

TEST(LoadFig, loadFile) {
  loader::Loader loader;
  loader.loadFig("index.fig");
  dezaina.loadFig(loader.getFig());
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
