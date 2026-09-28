// Delete Kth Element from Doubly Linked List
// k is 1-based indexing.
//
// Example:
// NULL <- 10 <-> 20 <-> 30 <-> 40 -> NULL
//                  ↑
//                 k=2
//
// After deleting kth node:
// NULL <- 10 <-> 30 <-> 40 -> NULL
//
// Time Complexity: O(k), worst case O(n)
// Space Complexity: O(1)

class Solution {
public:
    ListNode* deleteKthElement(ListNode*& head, int k) {

        // ------------------------------------------------
        // Case 1: Empty Doubly Linked List
        // ------------------------------------------------
        // If head is NULL, there is no node to delete.
        if (head == nullptr) {
            return nullptr;
        }

        // ------------------------------------------------
        // Step 1: Find the kth node
        // ------------------------------------------------
        // temp will point to the kth node after the loop.
        ListNode* temp = head;

        for (int i = 1; i < k && temp != nullptr; i++) {
            temp = temp->next;
        }

        // ------------------------------------------------
        // Case 2: k is greater than the number of nodes
        // ------------------------------------------------
        // If temp becomes NULL, kth node does not exist.
        if (temp == nullptr) {
            return head;
        }

        // ------------------------------------------------
        // Case 3: Delete the head node
        // ------------------------------------------------
        if (temp == head) {

            // Move head to the next node.
            head = head->next;

            // If the new head exists,
            // its previous pointer should be NULL.
            if (head != nullptr) {
                head->prev = nullptr;
            }

            // Delete the old head.
            delete temp;

            return head;
        }

        // ------------------------------------------------
        // Case 4: Delete middle or last node
        // ------------------------------------------------

        // Connect the previous node to the next node.
        temp->prev->next = temp->next;

        // If temp is NOT the last node,
        // connect the next node back to the previous node.
        if (temp->next != nullptr) {
            temp->next->prev = temp->prev;
        }

        // Delete the kth node.
        delete temp;

        return head;
    }
};
