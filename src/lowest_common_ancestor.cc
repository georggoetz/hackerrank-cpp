#include <lowest_common_ancestor.h>

namespace lowest_common_ancestor {

  node *lca(node *root, int v1,int v2) {
    if (root == nullptr) {
      return nullptr;
    }
    if (v1 < root->data && v2 < root->data) {
      return lca(root->left, v1, v2);
    }
    if (v1 > root->data && v2 > root->data) {
      return lca(root->right, v1, v2);
    }
    return root;
  }

}
