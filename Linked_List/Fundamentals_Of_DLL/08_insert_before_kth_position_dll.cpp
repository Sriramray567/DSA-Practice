```cpp
// Problem: Insert Before Kth Position in Doubly Linked List
// File: insert_before_kth_position_dll.cpp
//
// Approach:
// 1. If K <= 0, do not modify the list.
// 2. If K == 1, insert the new node before the head.
// 3. Traverse the list to find the Kth node.
// 4. If the Kth node does not exist, return the original head.
// 5. Insert the new node before the Kth node by updating
//    the prev and next pointers.
//
// Time Complexity: O(n)
// Auxiliary Space: O(1), excluding the new node.

class Solution {
public:
    ListNode* insertBeforeKthPosition(ListNode* head, int X, int K) {

        // Invalid position
        if (K <= 0) {
            return head;
        }

        // Case 1: Insert before the head
        if (K == 1) {

            // Create a new node with prev = nullptr and next = head
            ListNode* newNode = new ListNode(X, nullptr, head);

            // If the list is not empty, update the old head's prev
            if (head != nullptr) {
                head->prev = newNode;
            }

            // The new node becomes the updated head
            return newNode;
        }

        // Case 2: Find the Kth node
        ListNode* curr = head;

        for (int pos = 1; pos < K && curr != nullptr; pos++) {
            curr = curr->next;
        }

        // If the Kth node does not exist, leave the list unchanged
        if (curr == nullptr) {
            return head;
        }

        // Case 3: Insert the new node before curr
        // The new node points backward to curr->prev
        // and forward to curr
        ListNode* newNode = new ListNode(X, curr->prev, curr);

        // Connect the previous node to the new node
        curr->prev->next = newNode;

        // Connect curr back to the new node
        curr->prev = newNode;

        // The head remains unchanged
        return head;
    }
};
```
