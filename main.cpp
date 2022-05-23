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

void printNumOfLayers(std::string_view path) {
  SUInitialize();

  SUModelRef model{};
  SUModelCreateFromFile(&model, path.data());

  size_t layerCount;
  SUModelGetNumLayers(model, &layerCount);
  std::cout << "Layer Count: " << layerCount << std::endl;

  SUTerminate();
}