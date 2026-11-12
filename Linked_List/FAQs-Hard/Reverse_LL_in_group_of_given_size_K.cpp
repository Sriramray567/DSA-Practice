/*
    Problem: Reverse Nodes in K-Group

    Given the head of a singly linked list and an integer k,
    reverse the nodes of the linked list k at a time.

    Important:
    - Only complete groups of k nodes are reversed.
    - If fewer than k nodes remain at the end, they are NOT reversed.

    Example:

    Input:
    1 -> 2 -> 3 -> 4 -> 5
    k = 2

    Output:
    2 -> 1 -> 4 -> 3 -> 5

    Explanation:
    First group:  1 -> 2  =>  2 -> 1
    Second group: 3 -> 4  =>  4 -> 3
    Remaining:    5       =>  5 remains unchanged


    ============================================================
    APPROACH: FIND KTH NODE + REVERSE EACH GROUP
    ============================================================

    Idea:

    We process the linked list group by group.

    For every group:

    1. Find the kth node from the current node.
    2. If kth node does not exist:
       - Fewer than k nodes remain.
       - Leave them unchanged.
       - Connect the previous reversed group to them.
    3. Save the node after the kth node.
    4. Disconnect the current group.
    5. Reverse the current group.
    6. Connect the reversed group with the previous group.
    7. Move to the next group.


    ============================================================
    IMPORTANT POINTERS
    ============================================================

    temp:
    - Points to the first node of the current group.

    kthNode:
    - Points to the kth node of the current group.

    nextNode:
    - Stores the first node of the next group.

    prevLast:
    - Points to the last node of the previously reversed group.


    ============================================================
    DRY RUN
    ============================================================

    Input:
    1 -> 2 -> 3 -> 4 -> 5
    k = 2

    Group 1:
    temp = 1
    kthNode = 2

    Group:
    1 -> 2

    Reverse:
    2 -> 1

    prevLast = 1


    Group 2:
    temp = 3
    kthNode = 4

    Group:
    3 -> 4

    Reverse:
    4 -> 3

    Connect:
    2 -> 1 -> 4 -> 3

    prevLast = 3


    Group 3:
    temp = 5

    Only one node remains, but k = 2.

    Therefore, do NOT reverse it.

    Final:
    2 -> 1 -> 4 -> 3 -> 5


    ============================================================
    TIME AND SPACE COMPLEXITY
    ============================================================

    Time Complexity: O(n)

    Why?
    - Every node is visited while finding kth nodes.
    - Every node is reversed exactly once.

    Space Complexity: O(1)

    Why?
    - We use only pointers.
    - No extra array, vector or recursion is used.


    ============================================================
    KEY POINT TO REMEMBER
    ============================================================

    For every group:

    Find Kth Node
          ↓
    Save Next Group
          ↓
    Disconnect Group
          ↓
    Reverse Group
          ↓
    Connect With Previous Group
          ↓
    Move To Next Group
*/


class Solution {
public:

    // ========================================================
    // Function 1: Reverse a Linked List
    // ========================================================

    ListNode* reverseLL(ListNode* head) {

        ListNode* prev = nullptr;
        ListNode* curr = head;

        while (curr != nullptr) {

            // Save next node
            ListNode* next = curr->next;

            // Reverse current node's pointer
            curr->next = prev;

            // Move prev and curr forward
            prev = curr;
            curr = next;
        }

        // prev becomes the new head
        return prev;
    }


    // ========================================================
    // Function 2: Find Kth Node
    // ========================================================

    ListNode* getKthNode(ListNode* temp, int k) {

        // Move k-1 steps to reach kth node
        while (temp != nullptr && k > 1) {

            k--;
            temp = temp->next;
        }

        return temp;
    }


    // ========================================================
    // Function 3: Reverse Nodes in K-Group
    // ========================================================

    ListNode* reverseKGroup(ListNode* head, int k) {

        ListNode* temp = head;

        // Last node of previously reversed group
        ListNode* prevLast = nullptr;


        while (temp != nullptr) {

            // Find kth node of current group
            ListNode* kthNode = getKthNode(temp, k);


            // ------------------------------------------------
            // If fewer than k nodes remain
            // ------------------------------------------------

            if (kthNode == nullptr) {

                // Connect previous reversed group
                // with remaining nodes
                if (prevLast != nullptr)
                    prevLast->next = temp;

                // Remaining nodes are not reversed
                break;
            }


            // ------------------------------------------------
            // Save the beginning of next group
            // ------------------------------------------------

            ListNode* nextNode = kthNode->next;


            // ------------------------------------------------
            // Disconnect current group
            // ------------------------------------------------

            kthNode->next = nullptr;


            // ------------------------------------------------
            // Reverse current group
            // ------------------------------------------------

            reverseLL(temp);


            // ------------------------------------------------
            // Connect reversed group
            // ------------------------------------------------

            // If this is the first group,
            // update the head.
            if (temp == head) {

                head = kthNode;
            }
            else {

                // Connect previous group with current group
                prevLast->next = kthNode;
            }


            // ------------------------------------------------
            // After reversal, temp becomes the last node
            // of the current reversed group.
            // ------------------------------------------------

            prevLast = temp;


            // ------------------------------------------------
            // Move to the next group
            // ------------------------------------------------

            temp = nextNode;
        }


        return head;
    }
};


/*
    ============================================================
    COMPLEXITY SUMMARY
    ============================================================

    Time Complexity:
    O(n)

    Space Complexity:
    O(1)


    ============================================================
    EXAMPLE
    ============================================================

    Input:
    head = 1 -> 2 -> 3 -> 4 -> 5
    k = 3

    First group:
    1 -> 2 -> 3

    After reverse:
    3 -> 2 -> 1

    Remaining:
    4 -> 5

    Since remaining nodes < k,
    they remain unchanged.

    Output:
    3 -> 2 -> 1 -> 4 -> 5


    ============================================================
    INTERVIEW TAKEAWAY
    ============================================================

    The most important part of this problem is pointer
    management.

    Remember:

    kthNode->next = nullptr;

    This temporarily separates the current group.

    After reversing:

    kthNode becomes the first node of the reversed group.

    temp becomes the last node of the reversed group.

    Therefore:

    prevLast = temp;

    This allows us to connect the next reversed group correctly.
*/
