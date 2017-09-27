#include <cycle_detection.h>
#include <set>

using namespace std;

namespace cycle_detection {

  bool has_cycle(Node *head) {
    set<Node *> s;
    for (Node *n = head; n != nullptr; n = n->next) {
      if (s.find(n) != s.end()) return true;
      s.insert(n);
    }
    return false;
  }
}
