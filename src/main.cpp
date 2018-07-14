#include <iostream>

#include "tree.h"

int main() {
  KTree<int> tree(12);
  const auto root = tree.getRoot();
  std::cout << root->getChildsNumber() << std::endl;
  std::cout << tree.getMaximalNodesNumber() << std::endl;

  return 0;
}