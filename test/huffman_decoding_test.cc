#include <huffman_decoding.h>
#include <string>
#include "gtest/gtest.h"
#include "redirect_output.h"

using namespace huffman_decoding;
using namespace hackerrank;
using namespace std;

namespace {

  TEST(HuffmanDecoding, Sample) {
    RedirectOutput out;
    node a = {3, 'A', nullptr, nullptr};
    node b = {1, 'B', nullptr, nullptr};
    node c = {1, 'C', nullptr, nullptr};
    node left = {2, '\0', &b, &c};
    node root = {5, '\0', &left, &a};
    decode_huff(&root, string("1001011"));
    ASSERT_STREQ("ABACA", out.str().c_str());
  }

}
