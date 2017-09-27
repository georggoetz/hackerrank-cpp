#ifndef CYCLE_DETECTION_
#define CYCLE_DETECTION_

namespace cycle_detection {

  struct Node {
    Node(int data = 0) : data(data), next(nullptr) {}
    int data;
    struct Node *next;
  };

  bool has_cycle(Node *head);
}

#endif // CYCLE_DETECTION_
