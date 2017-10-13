#include <self_balancing_tree.h>
#include <algorithm>
#include <iostream>

namespace self_balancing_tree {

  int height(node *n) {
    return n == nullptr ? -1 : n->ht;
  }

  void set_height(node *n) {
    n->ht = 1 + std::max(height(n->left), height(n->right));
  }

  void print(node *n) {
    if (n != nullptr) {
      std::cout << "value = " << n->val << ", balance = " << balance(n) << std::endl;
    }
  }

  node *RotateLeft(node *n) {
     auto right = n->right;
     n->right = right->left;
     right->left = n;

     set_height(n);
     set_height(right);

     return right;
  }

  node *RotateRight(node *n) {
    auto left = n->left;
    n->left = left->right;
    left->right = n;

    set_height(n);
    set_height(left);

    return left;
  }

  node *insert(node *root, int val) {
    if (root == nullptr) {
      return new node{val, nullptr, nullptr, 0};
    }

    if (val < root->val) {
      root->left = insert(root->left, val);
    } else if (val > root->val) {
      root->right = insert(root->right, val);
    } else {
      return root;
    }

    set_height(root);
    int b = balance(root);

    if (b > 1) {
      // left right case
      if (val > root->left->val) {
        root->left = RotateLeft(root->left);
      }
      // left left case
      return RotateRight(root);
    }
    if (b < -1) {
      // right left case
      if (val < root->right->val) {
        root->right = RotateRight(root->right);
      }
      // right right case
      return RotateLeft(root);
    }

    return root;
  }

  int balance(node *n) {
    return n == nullptr ? 0 : height(n->left) - height(n->right);
  }

  void Inorder(node *root) {
    if (root != nullptr) {
      Inorder(root->left);
      print(root);
      Inorder(root->right);
    }
  }

  void Preorder(node *root) {
    if (root != nullptr) {
      print(root);
      Preorder(root->left);
      Preorder(root->right);
    }
  }

  void DeleteTree(node *root) {
    if (root != nullptr) {
      DeleteTree(root->left);
      DeleteTree(root->right);
      delete root;
      root = nullptr;
    }
  }
}
