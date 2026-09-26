```cpp
/*
    Problem: Insert a Node at the Head of a Linked List

    Approach:
    1. Create a new node with value X.
    2. Point the new node's next to the current head.
    3. Update head to the new node.
    4. Return the updated head.

    Important:
    This logic works for both:
    - Empty linked list
    - Non-empty linked list

    Time Complexity: O(1)
    Space Complexity: O(1)
*/

class Solution {
public:
    ListNode* insertAtHead(ListNode*& head, int X) {

        // Create a new node
        ListNode* newNode = new ListNode(X, nullptr);

        // Connect new node to the current head
        newNode->next = head;

        // Make new node the new head
        head = newNode;

        // Return updated head
        return head;
    }
};
```
