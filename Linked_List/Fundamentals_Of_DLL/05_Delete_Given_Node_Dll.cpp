// Problem: Remove Given Node in Doubly Linked List
// File: delete_given_node_dll.cpp
//
// Given:
// - Reference to a node
// - Head is NOT given
// - Given node is guaranteed NOT to be the head
//
// Goal:
// Remove the given node while maintaining the DLL structure.
//
// Time Complexity: O(1)
// Space Complexity: O(1)

class Solution {
public:
    void deleteNode(ListNode* node) {

        // Since the given node is NOT the head,
        // node->prev will always exist.

        // Connect the previous node to the next node.
        node->prev->next = node->next;

        // If node is not the tail,
        // connect the next node back to the previous node.
        if (node->next != nullptr) {
            node->next->prev = node->prev;
        }

        // Delete the given node.
        delete node;
    }
};
