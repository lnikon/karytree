#pragma once
#include <cassert>
#include <memory>
#include <vector>

template <class T>
class KTree final {
 public:
  struct Node {
    T m_value{};
    std::vector<std::shared_ptr<Node>> m_siblings{};

    Node(T value = T(), size_t nodesPerLevel = 0) : m_value(value) {
      m_siblings.reserve(nodesPerLevel);
    }

    auto getChildsNumber() const { return m_siblings.size(); }
    auto getMaximalNodesNumber() const { return m_siblings.capacity(); };
    auto isFull() const { return (m_siblings.size() == m_siblings.capacity()); }
    auto isEmpty() const { return (m_siblings.size() == 0); }
  };

  KTree(size_t nodesPerLevel = 0) {
    assert(nodesPerLevel >= 0);

    m_root = std::make_shared<Node>(nodesPerLevel);
  }

  auto insert(const T& value) {
    if (!m_root.isFull()) {
      auto getIndex = m_root->getChildsNumber();
      m_root->m_siblings[getIndex + 1] =
          std::make_shared<Node>(value, m_nodesPerLevel);
    } else {
    }
  }

  const auto getRoot() const { return m_root; }
  size_t getMaximalNodesNumber() { return m_nodesPerLevel; }

 private:
  std::shared_ptr<Node> m_root{};
  const size_t m_nodesPerLevel{0};
};