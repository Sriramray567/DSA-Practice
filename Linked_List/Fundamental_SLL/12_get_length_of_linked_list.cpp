```cpp
/*
    Problem:
    Find the length (number of nodes) of a singly linked list.

    Example:
    Linked List:
    10 → 20 → 30 → nullptr

    Length = 3


    Approach:
    1. Start a pointer `temp` from the head.
    2. Initialize `lengthLL = 0`.
    3. Traverse the linked list until `temp` becomes nullptr.
    4. For every node:
       - Increase the length by 1.
       - Move temp to the next node.
    5. Return the final length.

    Edge Cases:
    - Empty list → Length = 0
    - One node → Length = 1
    - Multiple nodes → Count all nodes

    Time Complexity: O(n)
    Space Complexity: O(1)
*/

class Solution {
public:
    int getLength(ListNode* head) {

        // Start traversal from the head
        ListNode* temp = head;

        // Stores the number of nodes
        int lengthLL = 0;

        // Traverse until the end of the linked list
        while (temp != nullptr) {

            // Count the current node
            lengthLL++;

            // Move to the next node
            temp = temp->next;
        }

        // Return the total number of nodes
        return lengthLL;
    }
};
```
