/*
    Problem: Delete Kth Node from Linked List

    Approach:
    1. If the list is empty, return nullptr.
    2. If k == 1, delete the head node separately.
    3. Traverse the linked list while keeping:
       - temp  -> current node
       - prev  -> previous node
       - count -> current position
    4. When count == k:
       - Connect previous node to the next node of temp.
       - Delete temp.
    5. Return the updated head.

    Time Complexity: O(n)
    Space Complexity: O(1)
*/

class Solution {
public:
    ListNode* deleteKthNode(ListNode*& head, int k) {

        // If linked list is empty
        if (head == nullptr)
            return nullptr;

        // If the first node has to be deleted
        if (k == 1) {
            ListNode* temp = head;
            head = head->next;

            delete temp;
            return head;
        }

        int count = 1;

        ListNode* temp = head;
        ListNode* prev = nullptr;

        // Traverse the linked list
        while (temp != nullptr) {

            // Found the kth node
            if (count == k) {

                // Skip the kth node
                prev->next = temp->next;

                // Free memory
                delete temp;

                break;
            }

            // Move both pointers forward
            prev = temp;
            temp = temp->next;
            count++;
        }

        return head;
    }
};
