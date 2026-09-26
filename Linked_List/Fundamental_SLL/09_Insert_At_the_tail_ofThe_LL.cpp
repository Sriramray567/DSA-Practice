/*
    Problem: Insert a Node at the Tail of a Linked List

    Approach:
    1. If the linked list is empty, create a new node and make it the head.
    2. Otherwise, traverse the list until the last node.
    3. Connect the last node to the newly created node.
    4. Return the original head.

    Time Complexity: O(n)
    Space Complexity: O(1)
*/

class Solution {
public:
    ListNode* insertAtTail(ListNode*& head, int X) {

        // Case 1: Linked list is empty
        if (head == nullptr) {
            head = new ListNode(X);
            return head;
        }

        // Start traversal from the head
        ListNode* temp = head;

        // Move to the last node
        while (temp->next != nullptr) {
            temp = temp->next;
        }

        // Attach the new node at the end
        temp->next = new ListNode(X);

        // Return the unchanged head
        return head;
    }
};
