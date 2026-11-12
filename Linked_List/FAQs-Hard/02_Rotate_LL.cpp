/*
    Problem: Rotate List

    Given the head of a linked list, rotate the list to the right
    by k places.

    Example:

    Input:
    1 -> 2 -> 3 -> 4 -> 5
    k = 2

    Output:
    4 -> 5 -> 1 -> 2 -> 3


    ============================================================
    APPROACH: CIRCULAR LINKED LIST
    ============================================================

    Idea:

    Instead of moving nodes one by one, we can make the linked
    list circular temporarily.

    Steps:

    1. Find the length of the linked list.
    2. Find the last node (tail).
    3. Since rotating length times gives the original list,
       reduce k using:

            k = k % length

    4. If k == 0, return the original head.

    5. Connect tail to head.

       tail->next = head;

       Now the linked list becomes circular.

    6. Find the new last node.

       For right rotation by k:

            newLastPosition = length - k

       Example:

            length = 5
            k = 2

            newLastPosition = 5 - 2 = 3

       So node 3 will become the new last node.

    7. The node after newLastNode becomes the new head.

            head = newLastNode->next;

    8. Break the circular connection:

            newLastNode->next = NULL;


    ============================================================
    DRY RUN
    ============================================================

    Input:

        1 -> 2 -> 3 -> 4 -> 5
        k = 2

    Step 1:
        length = 5

    Step 2:
        k = k % length
        k = 2 % 5
        k = 2

    Step 3:
        Make list circular:

        1 -> 2 -> 3 -> 4 -> 5
        ^                       |
        |_______________________|

    Step 4:
        Find new last node:

        length - k
        = 5 - 2
        = 3

        New last node = 3

    Step 5:
        Node after 3 becomes new head.

        New head = 4

    Step 6:
        Break connection after 3.

        4 -> 5 -> 1 -> 2 -> 3


    ============================================================
    SPECIAL CASES
    ============================================================

    1. Empty list:
       return head

    2. Single node:
       return head

    3. k == 0:
       return head

    4. k is greater than length:
       Use k % length

       Example:

       length = 5
       k = 12

       k = 12 % 5 = 2


    ============================================================
    TIME AND SPACE COMPLEXITY
    ============================================================

    Time Complexity: O(n)

    - Find length and tail: O(n)
    - Find new last node: O(n)
    - Total: O(n)

    Space Complexity: O(1)

    - Only pointers and variables are used.
    - No extra array or data structure.


    ============================================================
    IMPORTANT FORMULA
    ============================================================

    New Last Node Position:

        length - k

    New Head:

        newLastNode->next


    ============================================================
    KEY CONCEPT
    ============================================================

    Right rotation by k means:

        Last k nodes move to the front.

    Example:

        1 -> 2 -> 3 -> 4 -> 5
                    _________
                   /         \
                  4 -> 5 -> 1 -> 2 -> 3

    Final:

        4 -> 5 -> 1 -> 2 -> 3
*/


class Solution {
public:

    // ========================================================
    // Find the kth node from the beginning
    // ========================================================

    ListNode* findLastNode(ListNode* temp, int k) {

        int cnt = 1;

        while (temp != NULL) {

            if (cnt == k)
                return temp;

            cnt++;
            temp = temp->next;
        }

        return NULL;
    }


    // ========================================================
    // Rotate Linked List to the Right
    // ========================================================

    ListNode* rotateRight(ListNode* head, int k) {

        // Handle empty list, single node and k = 0
        if (head == NULL || head->next == NULL || k == 0)
            return head;


        // ----------------------------------------------------
        // Step 1: Find length and tail
        // ----------------------------------------------------

        ListNode* tail = head;
        int length = 1;

        while (tail->next != NULL) {

            length++;
            tail = tail->next;
        }


        // ----------------------------------------------------
        // Step 2: Remove unnecessary full rotations
        // ----------------------------------------------------

        k = k % length;

        if (k == 0)
            return head;


        // ----------------------------------------------------
        // Step 3: Make the linked list circular
        // ----------------------------------------------------

        tail->next = head;


        // ----------------------------------------------------
        // Step 4: Find the new last node
        // ----------------------------------------------------

        ListNode* newLastNode =
            findLastNode(head, length - k);


        // ----------------------------------------------------
        // Step 5: Node after newLastNode becomes new head
        // ----------------------------------------------------

        head = newLastNode->next;


        // ----------------------------------------------------
        // Step 6: Break the circular connection
        // ----------------------------------------------------

        newLastNode->next = NULL;


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
    INTERVIEW TAKEAWAY
    ============================================================

    For Rotate List:

        1. Find length
        2. k = k % length
        3. Connect tail to head
        4. Find node at (length - k)
        5. Its next node becomes the new head
        6. Break the circular link

    Remember:

        New Last Node = length - k
        New Head      = newLastNode->next
*/
