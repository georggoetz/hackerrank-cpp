#include <huffman_decoding.h>
#include <iostream>

using namespace std;

namespace huffman_decoding {

  void decode_huff(node *root, string s) {
    node *next = root;
    for (char c : s) {
      switch (c) {
        case '0':
          next = next->left;
          break;
        case '1':
          next = next->right;
          break;
      }
      if (next->data != '\0') {
        cout << next->data;
        next = root;
      }
    }
  }

}
