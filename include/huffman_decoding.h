#ifndef HUFFMAN_DECODING_H_
#define HUFFMAN_DECODING_H_

#include <string>

namespace huffman_decoding {

  struct node {
    int freq;
    char data;
    node *left;
    node *right;
  };

  void decode_huff(node *root, std::string s);
}

#endif // HUFFMAN_DECODING_H_
