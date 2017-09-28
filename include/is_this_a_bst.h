#ifndef IS_THIS_A_BST_H_
#define IS_THIS_A_BST_H_

namespace is_this_a_bst {

  struct Node {
    Node(int data = 0) : data(data), left(nullptr), right(nullptr) {}
    int data;
    Node *left;
    Node *right;
  };

  bool checkBST(Node *root);
}

#endif // IS_THIS_A_BST_H_
