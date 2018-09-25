#include "common.h"

using namespace std;

class Solution {
public:
  ListNode* partition(ListNode* head, int x) {
    if (head == NULL)
      return NULL;

    ListNode root;
    root.next = head;
    ListNode *tail = &root;
    int n = 0;
    for (; tail->next != NULL; tail = tail->next, ++n);

    ListNode *prev = &root, *curr = NULL;
    while (n-- > 0) {
      curr = prev->next;
      if (curr->val >= x && curr != tail) {
        prev->next = curr->next;
        curr->next = tail->next;
        tail->next = curr;
        tail = curr;
      } else
        prev = prev->next;
    }
    return root.next;
  }
};

// Given a linked list and a value x, partition it such that all nodes less than x
// come before nodes greater than or equal to x.
//
// You should preserve the original relative order of the nodes in each of the two
// partitions.
//
// Example:
//
// Input: head = 1->4->3->2->5->2, x = 3
// Output: 1->2->2->4->3->5
int main(int argc, char *argv[])
{
  vector<int> nums = {1, 4, 3, 2, 5, 2};
  unordered_map<Index, ListNode> nodes;
  create_node_pool(nums, nodes);
  ListNode *head = &nodes[1];
  nodes[1].next  = &nodes[4];
  nodes[4].next  = &nodes[3];
  nodes[3].next  = &nodes[{2, 0}];
  nodes[{2, 0}].next  = &nodes[5];
  nodes[5].next  = &nodes[{2, 1}];
  int x = 3;

  show_list(head);
  Solution sol;
  show_list(sol.partition(head, x));

  return 0;
}
