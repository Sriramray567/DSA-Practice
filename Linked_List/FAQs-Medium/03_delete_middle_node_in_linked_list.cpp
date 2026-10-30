
/*
    Problem: Delete the Middle Node of a Linked List

    Given the head of a singly linked list, delete the middle
    node and return the head of the modified linked list.

    For an even number of nodes, delete the SECOND middle node.

    Example 1:
    Input:  1 -> 2 -> 3 -> 4 -> 5
    Output: 1 -> 2 -> 4 -> 5

    Explanation:
    Middle node 3 is deleted.

    Example 2:
    Input:  1 -> 2 -> 3 -> 4
    Output: 1 -> 2 -> 4

    Explanation:
    Second middle node 3 is deleted.

    Example 3:
    Input:  1
    Output: NULL

    Explanation:
    If only one node exists, delete it and return NULL.


    ============================================================
    APPROACH 1: TWO TRAVERSAL (COUNT + DELETE)
    ============================================================

    Explanation:

    In this approach, we traverse the linked list twice.

    Step 1: First Traversal
    - Initialize cnt = 0.
    - Traverse the entire linked list.
    - Count the total number of nodes.

    Step 2: Find Middle Position
    - Calculate mid = cnt / 2.
    - We use 0-based indexing.
    - For even-length lists, this gives the index
      of the second middle node.

    Step 3: Second Traversal
    - Start from the head.
    - Maintain a previous pointer.
    - Move to the middle node.
    - Update prev->next = curr->next.
    - Delete the middle node.

    Special Case:
    - If head == nullptr, return nullptr.
    - If only one node exists, delete it and return nullptr.

    Dry Run:

    Input: 1 -> 2 -> 3 -> 4 -> 5

    First Traversal:
    cnt = 5

    Middle Index:
    mid = 5 / 2 = 2

    Second Traversal:
    Middle node = 3
    Previous node = 2

    Delete operation:
    prev->next = curr->next

    Output:
    1 -> 2 -> 4 -> 5

    Time Complexity: O(n) + O(n) = O(n)
    Space Complexity: O(1)


    ============================================================
    APPROACH 2: TORTOISE AND HARE (SLOW + FAST POINTER)
    ============================================================

    Explanation:

    This approach uses three pointers:

    1. Slow Pointer:
       Moves one step at a time.

    2. Fast Pointer:
       Moves two steps at a time.

    3. Previous Pointer:
       Stores the node before the slow pointer.

    Steps:

    1. Handle edge cases:
       - If head == nullptr, return nullptr.
       - If head->next == nullptr, delete the only node
         and return nullptr.

    2. Initialize:
       slow = head
       fast = head
       prev = nullptr

    3. Traverse the linked list:
       - Move fast by two steps.
       - Move slow by one step.
       - Before moving slow, store its previous node in prev.

    4. When fast reaches the end:
       - slow points to the middle node.
       - prev points to the node before the middle.

    5. Delete the middle node:
       prev->next = slow->next;
       delete slow;

    6. Return head.

    Dry Run:

    Input: 1 -> 2 -> 3 -> 4 -> 5

    Initially:
    slow = 1
    fast = 1
    prev = nullptr

    Iteration 1:
    prev = 1
    slow = 2
    fast = 3

    Iteration 2:
    prev = 2
    slow = 3
    fast = 5

    Loop stops because fast->next == nullptr.

    Now:
    prev = 2
    slow = 3

    Delete operation:
    prev->next = slow->next

    Delete node 3.

    Output:
    1 -> 2 -> 4 -> 5

    Time Complexity: O(n)
    Space Complexity: O(1)

    Advantages:
    - Only one traversal is required.
    - No need to count total nodes.
    - No extra data structure is required.
    - Efficient approach for interviews.


    ============================================================
    COMPARISON OF BOTH APPROACHES
    ============================================================

    Approach 1: Two Traversal
    Time Complexity: O(n)
    Space Complexity: O(1)

    Approach 2: Tortoise and Hare
    Time Complexity: O(n)
    Space Complexity: O(1)

    Both approaches delete the second middle node
    when the linked list has an even number of nodes.

    Recommended Approach:
    Tortoise and Hare (Slow and Fast Pointer).
*/


// ============================================================
// APPROACH 2: TORTOISE AND HARE
// ============================================================

class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {

        // Handle empty linked list
        if (head == nullptr) return nullptr;

        // Handle single-node linked list
        if (head->next == nullptr) {
            delete head;
            return nullptr;
        }

        // Initialize slow, fast and previous pointers
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = nullptr;

        // Find middle node using slow and fast pointers
        while (fast != nullptr && fast->next != nullptr) {

            prev = slow;

            slow = slow->next;

            fast = fast->next->next;
        }

        // Delete the middle node
        prev->next = slow->next;

        delete slow;

        // Return updated head
        return head;
    }
};


/*
    Complexity Analysis:

    Time Complexity: O(n)
    - Fast pointer moves two steps at a time.
    - Slow pointer moves one step at a time.
    - Only one traversal is required.

    Space Complexity: O(1)
    - Only three pointers are used.
    - No extra data structure or recursion is required.
*/
