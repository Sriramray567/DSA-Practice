
/*
    Problem: Find Middle of Linked List

    Given the head of a singly linked list, find and return
    the middle node of the linked list.

    If the linked list has an even number of nodes,
    return the SECOND middle node.

    Example 1:
    Input:  1 -> 2 -> 3 -> 4 -> 5
    Output: 3

    Example 2:
    Input:  1 -> 2 -> 3 -> 4
    Output: 3


    ============================================================
    APPROACH 1: TWO TRAVERSAL (COUNT + TRAVERSE AGAIN)
    ============================================================

    Explanation:

    In this approach, we traverse the linked list twice.

    Step 1: First Traversal
    - Initialize a counter cnt = 0.
    - Traverse the entire linked list.
    - Count the total number of nodes.

    Step 2: Calculate Middle
    - Calculate middle index using cnt / 2.
    - We use 0-based indexing.
    - For even-length lists, cnt / 2 gives the
      index of the second middle node.

    Step 3: Second Traversal
    - Start again from the head.
    - Move forward cnt / 2 times.
    - Return the node at the middle position.

    Dry Run:

    Input: 1 -> 2 -> 3 -> 4 -> 5

    First Traversal:
    Total nodes = 5

    Middle Index:
    mid = 5 / 2 = 2

    Second Traversal:
    Move 2 steps from head.

    Middle Node = 3

    Output: 3

    Time Complexity: O(n) + O(n) = O(n)
    Space Complexity: O(1)

    Note:
    This approach uses two complete/partial traversals.
    It is simple but requires counting the nodes first.


    ============================================================
    APPROACH 2: TORTOISE AND HARE (SLOW AND FAST POINTER)
    ============================================================

    Explanation:

    This approach uses two pointers:
    
    1. Slow Pointer:
       Moves one step at a time.

    2. Fast Pointer:
       Moves two steps at a time.

    The fast pointer moves twice as fast as the slow pointer.

    Steps:

    1. Initialize both slow and fast pointers at head.

    2. Run a loop while:
       fast != nullptr AND fast->next != nullptr.

    3. Move slow by one step:
       slow = slow->next;

    4. Move fast by two steps:
       fast = fast->next->next;

    5. When fast reaches the end of the linked list,
       slow will be pointing to the middle node.

    6. Return slow.

    Dry Run:

    Input: 1 -> 2 -> 3 -> 4 -> 5

    Initially:
    slow = 1
    fast = 1

    Iteration 1:
    slow = 2
    fast = 3

    Iteration 2:
    slow = 3
    fast = 5

    Loop stops because fast->next == nullptr.

    Middle Node = 3

    Output: 3

    Why does it work?

    Fast pointer moves two steps while slow pointer
    moves one step.

    Therefore, when fast reaches the end,
    slow has covered approximately half the list.

    Time Complexity: O(n)
    Space Complexity: O(1)

    Advantages:
    - Only one traversal is required.
    - No need to count total nodes.
    - No extra data structure is required.
    - Efficient and commonly used in interviews.


    ============================================================
    COMPARISON OF BOTH APPROACHES
    ============================================================

    Approach 1: Two Traversal
    Time Complexity: O(n)
    Space Complexity: O(1)

    Approach 2: Tortoise and Hare
    Time Complexity: O(n)
    Space Complexity: O(1)

    Both approaches return the second middle node
    when the linked list has an even number of nodes.

    Recommended Approach:
    Tortoise and Hare (Slow and Fast Pointer).
*/


// ============================================================
// APPROACH 2: TORTOISE AND HARE
// ============================================================

class Solution {
public:
    ListNode* middleNode(ListNode* head) {

        // Initialize slow and fast pointers at head
        ListNode* slow = head;
        ListNode* fast = head;

        // Slow moves one step, fast moves two steps
        while (fast != nullptr && fast->next != nullptr) {

            slow = slow->next;

            fast = fast->next->next;
        }

        // Slow points to the middle node
        return slow;
    }
};

/*
    Complexity Analysis:

    Time Complexity: O(n)
    - Fast pointer moves two steps at a time.
    - The loop runs approximately n/2 times.
    - Therefore, overall time complexity is O(n).

    Space Complexity: O(1)
    - Only two pointers are used.
    - No extra data structure or recursion is required.
*/
