#pragma once
#include <memory>
#include <vector>
#include <cassert>

template <class T>
class KTree final {
 public:
  class Node {
    std::vector<Node> m_childs{};

    Node() {}
  };

  KTree(int nodesPerLevel = 0) : m_nodesPerLevel(nodesPerLevel) {
    assert(nodesPerLevel >= 0);

    m_root.m_childs.resize(m_nodesPerLevel);
  }

 private:
  std::shared_ptr<Node> m_root{};
  static const int m_nodesPerLevel{0};
};