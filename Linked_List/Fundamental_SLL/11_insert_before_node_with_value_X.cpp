```cpp
/*
    Problem:
    Insert a node with value `val` before the first node
    whose value is equal to `X` in a singly linked list.

    Example:
    Input:
    Linked List = 1 → 2 → 3
    X = 2
    val = 5

    Output:
    1 → 5 → 2 → 3


    Approach:
    1. If the list is empty, return the original head.
    2. If the head itself contains X:
       - Create a new node with value val.
       - Point the new node to head.
       - Return the new node as the updated head.
    3. Otherwise, use two pointers:
       - prev → previous node
       - temp → current node
    4. Traverse the list and search for X.
    5. When X is found:
       - Create the new node.
       - Connect newNode to temp.
       - Connect prev to newNode.
    6. If X is not found, return the original head.

    Important:
    - If X occurs multiple times, insertion is done before
      the FIRST occurrence of X.
    - The head case is handled separately because the head
      has no previous node.

    Time Complexity: O(n)
    Space Complexity: O(1) auxiliary space
*/

class Solution {
public:
    ListNode* insertBeforeX(ListNode* head, int X, int val) {

        // Edge Case 1: Empty linked list
        if (head == nullptr)
            return head;

        // Edge Case 2: X is present at the head
        if (head->data == X) {

            // New node points to the current head
            ListNode* newNode = new ListNode(val, head);

            // New node becomes the new head
            return newNode;
        }

        // prev points to the previous node
        ListNode* prev = head;

        // temp points to the current node
        ListNode* temp = head->next;

        // Traverse the linked list
        while (temp != nullptr) {

            // X found
            if (temp->data == X) {

                // Create new node and point it to X
                ListNode* newNode = new ListNode(val, temp);

                // Connect previous node to the new node
                prev->next = newNode;

                // Insertion completed
                return head;
            }

            // Move both pointers forward
            prev = temp;
            temp = temp->next;
        }

        // X was not found
        // Return the original linked list
        return head;
    }
};
```
