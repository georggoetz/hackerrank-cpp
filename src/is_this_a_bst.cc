#include <is_this_a_bst.h>
#include <limits>

namespace is_this_a_bst {

  bool isValidBst(Node *n, int min, int max);

  bool checkBST(Node *root) {
    if (root == nullptr) return true;
    return isValidBst(root, std::numeric_limits<int>::min(), std::numeric_limits<int>::max());
  }

  bool isValidBst(Node *n, int min, int max) {
    if (n == nullptr) return true;
    return min < n->data
      && max > n->data
      && isValidBst(n->left, min, n->data)
      && isValidBst(n->right, n->data, max);
  }
}
