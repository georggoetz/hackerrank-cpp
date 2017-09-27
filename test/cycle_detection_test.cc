#include <cycle_detection.h>
#include "gtest/gtest.h"

using namespace cycle_detection;

namespace {

  TEST(CycleDetectionTest, Null) {
    EXPECT_FALSE(has_cycle(nullptr));
  }

  TEST(CycleDetectionTest, SingleNode) {
    Node n;
    EXPECT_FALSE(has_cycle(&n));
  }

  TEST(CycleDetectionTest, WithCycle) {
    Node n;
    n.next = &n;
    EXPECT_TRUE(has_cycle(&n));
  }

  TEST(CycleDetectionTest, WithoutCycle) {
    Node n1;
    Node n2;
    n1.next = &n2;
    EXPECT_FALSE(has_cycle(&n1));
  }
}
