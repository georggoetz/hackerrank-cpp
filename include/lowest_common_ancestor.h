#ifndef LOWEST_COMMON_ANCESTOR_H
#define LOWEST_COMMON_ANCESTOR_H

namespace lowest_common_ancestor {

  typedef struct node {
    int data;
    node *left;
    node *right;
  } node;

  node *lca(node *root, int v1,int v2);
}

#endif // LOWEST_COMMON_ANCESTOR_H
