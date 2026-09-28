// Delete Head of Doubly Linked List
// Time Complexity: O(1)
// Space Complexity: O(1)

class Solution {
public:
    ListNode* deleteHead(ListNode*& head) {

        // Case 1: Empty list
        if (head == nullptr) {
            return nullptr;
        }

        // Store the old head
        ListNode* temp = head;

        // Move head to the next node
        head = head->next;

        // If new head exists, remove its previous link
        if (head != nullptr) {
            head->prev = nullptr;
        }

        // Delete old head
        delete temp;

        return head;
    }
};
