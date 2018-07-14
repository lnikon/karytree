#pragma once
#include <cassert>
#include <memory>
#include <vector>

template <class T>
class KTree final {
 public:
  struct Node {
    std::vector<std::shared_ptr<Node>> m_childs{};

    Node() {}

    size_t getChildsNumber() { return m_childs.size(); }
  };

  KTree(size_t nodesPerLevel = 0) : m_nodesPerLevel(nodesPerLevel) {
    assert(nodesPerLevel >= 0);

    m_root = std::make_shared<Node>();
    m_root->m_childs.resize(m_nodesPerLevel);
  }

  const auto getRoot() const {
    return m_root;
  }

 private:
  std::shared_ptr<Node> m_root{};
  const size_t m_nodesPerLevel{0};
};