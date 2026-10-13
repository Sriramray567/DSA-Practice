```cpp
// Problem: Insert Before Tail in Doubly Linked List
// File: insert_before_tail_dll.cpp
//
// Approach:
// 1. If the list is empty, create a new node and return it.
// 2. Traverse to find the tail node.
// 3. Create a new node before the tail.
// 4. Update the prev and next pointers.
// 5. If the list has only one node, update head.
//
// Time Complexity: O(n)
// Auxiliary Space: O(1)

class Solution {
public:
    ListNode* insertBeforeTail(ListNode* head, int X) {

        // Case 1: Empty list
        // The new node becomes the only node and the head.
        if (head == nullptr) {
            return new ListNode(X, nullptr, nullptr);
        }

        // Find the tail node
        ListNode* tail = head;

        while (tail->next != nullptr) {
            tail = tail->next;
        }

        // Create a new node between tail->prev and tail
        ListNode* newNode =
            new ListNode(X, tail->prev, tail);

        // Case 2: Only one node exists
        // The new node becomes the new head.
        if (tail->prev == nullptr) {
            head = newNode;
        } 
        else {
            // Connect the previous node to the new node
            tail->prev->next = newNode;
        }

        // Connect the tail back to the new node
        tail->prev = newNode;

        // Return the updated head
        return head;
    }
};
```
