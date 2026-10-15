```cpp
// Problem: Reverse a Doubly Linked List
// Approaches:
// 1. Brute Force - Using Stack
// 2. Optimal - Swapping Pointers

// Doubly Linked List Node
// Use the ListNode definition provided by your platform if already present.

// --------------------------------------------------
// Approach 1: Brute Force (Using Stack)
// Time Complexity: O(n)
// Auxiliary Space: O(n)
// --------------------------------------------------

/*
class Solution {
public:
    ListNode* reverseDLL(ListNode* head) {
        if (head == nullptr) return head;

        stack<int> st;
        ListNode* temp = head;

        // Store all node values in the stack
        while (temp != nullptr) {
            st.push(temp->data);
            temp = temp->next;
        }

        // Replace node values in reverse order
        temp = head;

        while (temp != nullptr) {
            temp->data = st.top();
            st.pop();
            temp = temp->next;
        }

        return head;
    }
};
*/

// --------------------------------------------------
// Approach 2: Optimal (Swapping Pointers)
// Time Complexity: O(n)
// Auxiliary Space: O(1)
// --------------------------------------------------

class Solution {
public:
    ListNode* reverseDLL(ListNode* head) {
        ListNode* curr = head;
        ListNode* newHead = nullptr;

        while (curr != nullptr) {
            // Swap prev and next pointers
            ListNode* temp = curr->prev;
            curr->prev = curr->next;
            curr->next = temp;

            // Update the new head
            newHead = curr;

            // Move to the next node in the original list
            curr = curr->prev;
        }

        return newHead;
    }
};
```
