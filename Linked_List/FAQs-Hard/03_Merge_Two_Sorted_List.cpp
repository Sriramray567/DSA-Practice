/*
===========================================================
Problem: Merge Two Sorted Linked Lists
===========================================================

Given two sorted singly linked lists, merge them into
one sorted linked list.

Example:

List 1: 1 -> 3 -> 5
List 2: 2 -> 4 -> 6

Output:
1 -> 2 -> 3 -> 4 -> 5 -> 6


===========================================================
Approach: Iterative + Dummy Node
===========================================================

Idea:
- Create a dummy node.
- Use two pointers:
      temp1 -> List 1
      temp2 -> List 2
- Compare the values of temp1 and temp2.
- Attach the smaller node to the merged list.
- Move that pointer forward.
- When one list becomes NULL, attach the remaining
  nodes of the other list.

Dummy node helps us avoid special handling for the
first node of the merged list.


===========================================================
Dry Run
===========================================================

List 1:
1 -> 3 -> 5

List 2:
2 -> 4 -> 6

Step 1:
1 < 2
Take 1

Merged:
1

Step 2:
3 > 2
Take 2

Merged:
1 -> 2

Step 3:
3 < 4
Take 3

Merged:
1 -> 2 -> 3

Step 4:
5 > 4
Take 4

Merged:
1 -> 2 -> 3 -> 4

Step 5:
5 < 6
Take 5

Merged:
1 -> 2 -> 3 -> 4 -> 5

List 1 is finished.

Attach remaining List 2:

1 -> 2 -> 3 -> 4 -> 5 -> 6


===========================================================
Time Complexity
===========================================================

O(N + M)

N = Number of nodes in List 1
M = Number of nodes in List 2


===========================================================
Space Complexity
===========================================================

O(1)

We are reusing the existing nodes.

Only one dummy node is created.


===========================================================
Important Point
===========================================================

We use:

ListNode* dummyNode = new ListNode(-1);

and

ListNode* dummt = dummyNode;

'dummt' keeps track of the last node of the merged list.

At the end:

return dummyNode->next;

Because dummyNode itself is not part of the answer.
===========================================================
*/

class Solution {
public:

    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        // Dummy node to simplify the merging process
        ListNode* dummyNode = new ListNode(-1);

        // Pointers for both linked lists
        ListNode* temp1 = list1;
        ListNode* temp2 = list2;

        // Pointer to build the merged list
        ListNode* dummt = dummyNode;

        // Compare nodes of both lists
        while (temp1 != NULL && temp2 != NULL) {

            // If List 1 node is smaller
            if (temp1->val < temp2->val) {

                dummt->next = temp1;
                dummt = dummt->next;
                temp1 = temp1->next;
            }

            // Otherwise take node from List 2
            else {

                dummt->next = temp2;
                dummt = dummt->next;
                temp2 = temp2->next;
            }
        }

        // If List 1 still has nodes,
        // attach all remaining nodes
        while (temp1 != NULL) {

            dummt->next = temp1;
            dummt = dummt->next;
            temp1 = temp1->next;
        }

        // If List 2 still has nodes,
        // attach all remaining nodes
        while (temp2 != NULL) {

            dummt->next = temp2;
            dummt = dummt->next;
            temp2 = temp2->next;
        }

        // Return actual head of merged list
        // Dummy node is skipped
        return dummyNode->next;
    }
};
