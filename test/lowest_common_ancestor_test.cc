#include <lowest_common_ancestor.h>
#include "gtest/gtest.h"

using namespace lowest_common_ancestor;

namespace {

  node one {1, nullptr, nullptr};
  node two {2, nullptr, nullptr};
  node three {3, nullptr, nullptr};
  node four {4, nullptr, nullptr};
  node six {6, nullptr, nullptr};
  node seven {7, nullptr, nullptr};

  TEST(LowestCommonAncestor, Sample) {
    node *root = &four;
    root->left = &two;
    root->right = &seven;
    seven.left = &six;
    two.left = &one;
    two.right = &three;

    ASSERT_EQ(&four, lca(root, 1, 7));
  }

}
