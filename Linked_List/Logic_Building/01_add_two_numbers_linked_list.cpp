```cpp
// Problem: Add Two Numbers Represented by Linked Lists
// Approach: Traversal with Carry
// Assumption: Digits are stored in reverse order.
//
// Example:
// List 1: 2 -> 4 -> 3  (represents 342)
// List 2: 5 -> 6 -> 4  (represents 465)
// Output: 7 -> 0 -> 8  (represents 807)
//
// Time Complexity: O(max(N, M))
// Auxiliary Space: O(1), excluding the output linked list.

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* &linkedList1,
                            ListNode* &linkedList2) {

        // Pointers to traverse both linked lists
        ListNode* temp1 = linkedList1;
        ListNode* temp2 = linkedList2;

        // Dummy node simplifies result list creation
        ListNode dummy(0);
        ListNode* curr = &dummy;

        // Stores carry from the previous addition
        int carry = 0;

        // Continue until both lists and carry are exhausted
        while (temp1 != nullptr || temp2 != nullptr || carry != 0) {

            // Start with the previous carry
            int sum = carry;

            // Add the current digit of the first list
            if (temp1 != nullptr) {
                sum += temp1->data;
                temp1 = temp1->next;
            }

            // Add the current digit of the second list
            if (temp2 != nullptr) {
                sum += temp2->data;
                temp2 = temp2->next;
            }

            // Calculate carry for the next position
            carry = sum / 10;

            // Calculate the digit to store in the result
            int digit = sum % 10;

            // Create a new node containing the result digit
            curr->next = new ListNode(digit);

            // Move curr to the newly created node
            curr = curr->next;
        }

        // Return the result, skipping the dummy node
        return dummy.next;
    }
};
```
