#include <is_this_a_bst.h>
#include "gtest/gtest.h"

using namespace is_this_a_bst;

namespace {

  TEST(IsThisABst, Null) {
    ASSERT_TRUE(checkBST(nullptr));
  }

  TEST(IsThisABst, SingleNode) {
    Node n;
    ASSERT_TRUE(checkBST(&n));
  }

  TEST(IsThisABst, Left) {
    Node root(2);
    Node left(1);
    root.left = &left;
    ASSERT_TRUE(checkBST(&root));
    root.left->data = 3;
    ASSERT_FALSE(checkBST(&root));
  }

  TEST(IsThisABst, Right) {
    Node root(2);
    Node right(3);
    root.right = &right;
    ASSERT_TRUE(checkBST(&root));
    root.right->data = 1;
    ASSERT_FALSE(checkBST(&root));
  }

  TEST(IsThisABst, LeftBstLarger) {
    Node root(3);
    Node l(1);
    Node n(2);
    Node r(4);
    n.left = &l;
    n.right = &r;
    root.left = &n;
    ASSERT_FALSE(checkBST(&root));
  }

  TEST(IsThisABst, LeftIsNotBst) {
    Node root(4);
    Node l(3);
    Node n(1);
    Node r(2);
    n.left = &l;
    n.right = &r;
    root.left = &n;
    ASSERT_FALSE(checkBST(&root));
  }
}
