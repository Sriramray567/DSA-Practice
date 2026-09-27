// Delete Tail of Singly Linked List
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    ListNode* deleteTail(ListNode*& head) {

        // Case 1: Empty linked list
        if (head == nullptr) {
            return nullptr;
        }

        // Case 2: Only one node
        if (head->next == nullptr) {
            delete head;
            return nullptr;
        }

        // Find the second-last node
        ListNode* temp = head;

        while (temp->next->next != nullptr) {
            temp = temp->next;
        }

        // Delete the last node
        delete temp->next;

        // Make second-last node the new tail
        temp->next = nullptr;

        return head;
    }
};
