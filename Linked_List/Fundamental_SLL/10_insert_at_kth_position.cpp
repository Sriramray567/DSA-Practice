class Solution {
public:
    ListNode* insertAtKthPosition(ListNode*& head, int X, int K) {

        // Case 1: Invalid position
        if (K <= 0) {
            return head;
        }

        // Case 2: Empty linked list
        // Only position 1 is valid
        if (head == nullptr) {
            if (K == 1) {
                head = new ListNode(X);
            }
            return head;
        }

        // Case 3: Insert at the head
        if (K == 1) {
            ListNode* newNode = new ListNode(X, head);
            head = newNode;
            return head;
        }

        // prev points to the node before temp
        // temp points to the current node
        ListNode* prev = head;
        ListNode* temp = head->next;

        // temp is currently at position 2
        int count = 2;

        while (temp != nullptr) {

            // Case 4: Insert at middle position
            if (K == count) {
                ListNode* newNode = new ListNode(X, temp);

                // Connect previous node to new node
                prev->next = newNode;

                return head;
            }

            // Move both pointers forward
            prev = temp;
            temp = temp->next;
            count++;
        }

        // Case 5: Insert at tail
        // count is now n + 1
        if (K == count) {
            ListNode* newNode = new ListNode(X, nullptr);

            // prev is the last node
            prev->next = newNode;

            return head;
        }

        // Case 6: K > n + 1
        // Position does not exist
        return head;
    }
};
