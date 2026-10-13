// Problem: Insert Before Head in Doubly Linked List
// File: insert_before_head_dll.cpp
//
// Approach:
// 1. Create a new node before the current head.
// 2. Set the new node's next pointer to the old head.
// 3. If the list is not empty, update the old head's prev pointer.
// 4. Update and return the new head.
//
// Time Complexity: O(1)
// Auxiliary Space: O(1)

class Solution {
public:
    ListNode* insertBeforeHead(ListNode* head, int X) {

        // Create a new node:
        // data = X, prev = nullptr, next = head
        ListNode* newNode = new ListNode(X, nullptr, head);

        // If the list is not empty,
        // connect the old head back to the new node
        if (head != nullptr) {
            head->prev = newNode;
        }

        // The new node becomes the head
        head = newNode;

        // Return the updated head
        return head;
    }
};
