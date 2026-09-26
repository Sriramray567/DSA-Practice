```cpp
/*
    Problem: Delete Node With Value X from a Linked List

    Problem Link:
    https://www.geeksforgeeks.org/problems/delete-a-node-in-single-linked-list/1

    Approach:
    - If the list is empty, return nullptr.
    - If the head contains X, delete the head separately.
    - Otherwise, use two pointers:
        prev -> previous node
        temp -> current node
    - If temp contains X:
        1. Connect prev to temp->next.
        2. Delete temp.
    - If X is not found, move both pointers forward.

    Time Complexity: O(n)
    Space Complexity: O(1)
*/

class Solution {
public:
    ListNode* deleteNodeWithValueX(ListNode*& head, int X) {

        // Case 1: Empty linked list
        if (head == nullptr)
            return nullptr;

        // Case 2: Delete the head node
        if (head->data == X) {

            ListNode* temp = head;
            head = head->next;

            // Free memory of the old head
            delete temp;

            return head;
        }

        // temp points to the current node
        ListNode* temp = head;

        // prev points to the previous node
        ListNode* prev = nullptr;

        // Traverse the linked list
        while (temp != nullptr) {

            // Found the node containing X
            if (temp->data == X) {

                // Skip the current node
                prev->next = temp->next;

                // Delete the current node
                delete temp;

                return head;
            }

            // Move prev to the current node
            prev = temp;

            // Move temp to the next node
            temp = temp->next;
        }

        // X was not found
        return head;
    }
};
```
