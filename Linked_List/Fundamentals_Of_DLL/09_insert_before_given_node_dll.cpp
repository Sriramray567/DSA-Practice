// Problem: Insert Before a Given Node in Doubly Linked List
// Time Complexity: O(1)
// Auxiliary Space: O(1), excluding the new node

class Solution {
public:
    void insertBeforeGivenNode(ListNode* node, int X) {

        // Store the previous node
        ListNode* prevNode = node->prev;

        // Create a new node between prevNode and node
        ListNode* newNode = new ListNode(X, prevNode, node);

        // Connect the previous node to the new node
        prevNode->next = newNode;

        // Connect the given node back to the new node
        node->prev = newNode;
    }
};
