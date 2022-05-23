#include <SketchUpAPI/sketchup.h>
#include <iostream>
#include <string_view>
#include <vector>

void printNumOfLayers(std::string_view path);

int main(int argc, char* argv[]) {
  if (argc > 1) {
    printNumOfLayers(argv[1]);
  } else {
    std::cout << "Successfully executed without any argument" << std::endl;
  }
  return 0;
}

static void check(SUResult result, const char* message) {
  if (result != SUResult::SU_ERROR_NONE) {
    throw std::runtime_error(message);
  }
}

void printNumOfLayers(std::string_view path) {
  SUInitialize();
  SUModelRef model{};
  SUModelCreateFromFile(&model, path.data());
  size_t layerCount;
  check(SUModelGetNumLayers(model, &layerCount), "failed to read layer count");
  std::cout << "Layer Count: " << layerCount << std::endl;
  SUTerminate();
}