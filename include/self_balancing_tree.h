// http://www.hackerrank.com/challenges/self-balancing-tree

#ifndef SELF_BALANCING_TREE_H_
#define SELF_BALANCING_TREE_H_

namespace self_balancing_tree {

  typedef struct node {
    int val;
    struct node *left;
    struct node *right;
    int ht;
  } node;

  node *insert(node *root, int val);
  int balance(node *n);
  void Inorder(node *root);
  void Preorder(node *root);
  void DeleteTree(node *root);
}

#endif
