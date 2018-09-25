// 25. Reverse Nodes in k-Group
#include "common.h"

using namespace std;

class Solution {
public:
  bool next_group(ListNode *p, int k, ListNode **tail) {
    int i = 0;
    for (; i < k && p != NULL; ++i, p = p->next);
    if (i < k) {
      *tail = NULL;
      return false;
    }
    *tail = p;
    return true;
  }

  ListNode* reverseKGroup(ListNode *head, int k) {
    // add `root` node: root -> head
    ListNode root(-1);
    root.next = head;
    head = &root;
    // `tail`: the start node of next stage
    ListNode *tail = NULL;

    // `prev`: initially -> head
    while (next_group(head->next, k, &tail)) {  // break if not enough elements
      ListNode *prev = head, *curr = prev->next;
      for (; curr != tail; curr = prev->next) {
        if (curr == head->next) {
          prev = curr;
          continue;
        }
        // move node
        prev->next = curr->next;
        curr->next = head->next;
        head->next = curr;
      }
      head = prev;
    } // while

    return root.next;
  }
};

// Example:
//
// Given this linked list: 1->2->3->4->5
//
// For k = 2, you should return: 2->1->4->3->5
//
// For k = 3, you should return: 3->2->1->4->5
//
// Note:
//
// Only constant extra memory is allowed.
// You may not alter the values in the list's nodes, only nodes itself may be changed.
int main(int argc, char *argv[])
{
  // construct node list
  unordered_map<int, ListNode> nodes;
  for (int i = 1; i < 6; ++i)
    nodes[i] = i;

  ListNode *head = &nodes[1];
  nodes[1].next = &nodes[2];
  nodes[2].next = &nodes[3];
  nodes[3].next = &nodes[4];
  nodes[4].next = &nodes[5];

  int k = 2;
  Solution sol;
  ListNode* res = sol.reverseKGroup(head, k);
  show_list(res);

  return 0;
}
