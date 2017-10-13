#include <self_balancing_tree.h>
#include "gtest/gtest.h"
#include "redirect_output.h"

using namespace hackerrank;
using namespace self_balancing_tree;

namespace {

  TEST(SelfBalancingTree, Empty) {
    auto node = insert(nullptr, 1);
    ASSERT_EQ(1, node->val);
    ASSERT_EQ(0, node->ht);
  }

  TEST(SelfBalancingTree, Left) {
    auto root = insert(nullptr, 2);
    root = insert(root, 1);
    ASSERT_EQ(2, root->val);
    ASSERT_EQ(1, root->ht);
    ASSERT_EQ(1, root->left->val);
    ASSERT_EQ(0, root->left->ht);
    ASSERT_EQ(nullptr, root->right);
  }

  TEST(SelfBalancingTree, Right) {
    auto root = insert(nullptr, 1);
    root = insert(root, 2);
    ASSERT_EQ(1, root->val);
    ASSERT_EQ(1, root->ht);
    ASSERT_EQ(2, root->right->val);
    ASSERT_EQ(0, root->right->ht);
    ASSERT_EQ(nullptr, root->left);
  }

  TEST(SelfBalancingTree, Self) {
    auto root = insert(nullptr, 1);
    ASSERT_EQ(root, insert(root, root->val));
  }

  TEST(SelfBalancingTree, LeftRightCase) {
    auto root = insert(nullptr, 5);
    root = insert(root, 3);
    root = insert(root, 4);
    ASSERT_EQ(4, root->val);
  }

  TEST(SelfBalancingTree, LeftLeftCase) {
    auto root = insert(nullptr, 5);
    root = insert(root, 4);
    root = insert(root, 3);
    ASSERT_EQ(4, root->val);
  }

  TEST(SelfBalancingTree, RightLeftCase) {
    auto root = insert(nullptr, 3);
    root = insert(root, 5);
    root = insert(root, 4);
    ASSERT_EQ(4, root->val);
  }

  TEST(SelfBalancingTree, RightRightCase) {
    auto root = insert(nullptr, 3);
    root = insert(root, 4);
    root = insert(root, 5);
    ASSERT_EQ(4, root->val);
  }

  class TraversalTest : public testing::Test {
  public:
    virtual void SetUp() {
      root_ = insert(nullptr, 3);
      root_ = insert(root_, 2);
      root_ = insert(root_, 4);
      root_ = insert(root_, 5);
      root_ = insert(root_, 6);
    }

    virtual void TearDown() {
      DeleteTree(root_);
      out_.clear();
    }

    RedirectOutput out_;
    node *root_;
  };

  TEST_F(TraversalTest, InorderTraversal) {
    Inorder(root_);
    const char *inorder =
      "value = 2, balance = 0\n"
      "value = 3, balance = -1\n"
      "value = 4, balance = 0\n"
      "value = 5, balance = 0\n"
      "value = 6, balance = 0\n";

    ASSERT_STREQ(inorder, out_.str().c_str());
  }

  TEST_F(TraversalTest, PreorderTraversal) {
    Preorder(root_);
    const char *preorder =
      "value = 3, balance = -1\n"
      "value = 2, balance = 0\n"
      "value = 5, balance = 0\n"
      "value = 4, balance = 0\n"
      "value = 6, balance = 0\n";

    ASSERT_STREQ(preorder, out_.str().c_str());
  }

}
