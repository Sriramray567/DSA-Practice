```cpp
/*
    Problem:
    Search for a given key in a singly linked list.

    Return:
    - true  → if the key is present
    - false → if the key is not present

    Example:
    Linked List:
    10 → 20 → 30 → nullptr

    key = 20
    Output: true

    key = 50
    Output: false


    Approach:
    1. Start traversal from the head.
    2. Use `temp` to point to the current node.
    3. Traverse until `temp` becomes nullptr.
    4. If `temp->val == key`, the key is found.
    5. Return true immediately.
    6. If the complete list is traversed without finding
       the key, return false.

    Edge Cases:
    - Empty list → false
    - Key at head → true
    - Key in middle → true
    - Key at last node → true
    - Key not present → false

    Time Complexity: O(n)
    Space Complexity: O(1)
*/

class Solution {
public:
    bool searchKey(ListNode* head, int key) {

        // Start traversal from the head
        ListNode* temp = head;

        // Traverse the linked list
        while (temp != nullptr) {

            // Key found
            if (temp->val == key) {
                return true;
            }

            // Move to the next node
            temp = temp->next;
        }

        // Key was not found
        return false;
    }
};
```
