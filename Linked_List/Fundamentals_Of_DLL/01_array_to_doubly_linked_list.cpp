```cpp
/*
    Problem:
    Convert an array into a Doubly Linked List.

    Example:
    Input:
    arr = [10, 20, 30]

    Output:
    nullptr ← 10 ⇄ 20 ⇄ 30 → nullptr


    Approach:
    1. If the array is empty, return nullptr.
    2. Create the first element as the head.
    3. Use `temp` to keep track of the last node.
    4. For every remaining array element:
       - Create a new node.
       - Connect temp->next to the new node.
       - Connect newNode->prev to temp.
       - Move temp to the new node.
    5. Return the head.

    Important:
    In a Doubly Linked List, every node has two links:
    - `next` → points to the next node.
    - `prev` → points to the previous node.

    Time Complexity: O(n)
    Space Complexity: O(n)
*/

class Solution {
public:
    ListNode* arrayToDoublyLinkedList(vector<int>& arr) {

        // Empty array
        if (arr.empty())
            return nullptr;

        // Create the first node
        ListNode* head = new ListNode(arr[0]);
        ListNode* temp = head;

        // Create remaining nodes
        for (int i = 1; i < arr.size(); i++) {

            ListNode* newNode = new ListNode(arr[i]);

            // Connect in both directions
            temp->next = newNode;
            newNode->prev = temp;

            // Move to the newly created node
            temp = newNode;
        }

        return head;
    }
};
```
