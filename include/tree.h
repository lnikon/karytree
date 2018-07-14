#pragma once
#include <cassert>
#include <memory>
#include <vector>

template <class T>
class KTree final {
 public:
  struct Node {
    std::vector<std::shared_ptr<Node>> m_siblings{};

    Node(size_t nodesPerLevel = 0) { m_siblings.reserve(nodesPerLevel); }

    size_t getChildsNumber() { return m_siblings.size(); }

  };

  KTree(size_t nodesPerLevel = 0) {
    assert(nodesPerLevel >= 0);

    m_root = std::make_shared<Node>(nodesPerLevel);
  }

  const auto getRoot() const { return m_root; }
  size_t getMaximalNodesNumber() { return m_nodesPerLevel; }

 private:
  std::shared_ptr<Node> m_root{};
  const size_t m_nodesPerLevel{0};
};