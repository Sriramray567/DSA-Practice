
/*
    Problem: Palindrome Linked List

    Given the head of a singly linked list, check whether
    the linked list is a palindrome or not.

    Example 1:
    Input:  1 -> 2 -> 2 -> 1
    Output: true

    Example 2:
    Input:  1 -> 2 -> 3
    Output: false


    ============================================================
    APPROACH 1: BRUTE FORCE (USING VECTOR)
    ============================================================

    Explanation:

    In this approach, we store all linked list elements
    in an array/vector and then check whether the array
    is a palindrome using two pointers.

    Steps:

    1. Traverse the linked list.
    2. Store every node's value in a vector.
    3. Initialize two pointers:
       - Left = 0
       - Right = n - 1
    4. Compare elements at both pointers.
    5. If values are different, return false.
    6. Otherwise, move left forward and right backward.
    7. If all elements match, return true.

    Dry Run:

    Input: 1 -> 2 -> 2 -> 1

    Vector: [1, 2, 2, 1]

    Comparison:
    arr[0] == arr[3]  => 1 == 1 (Match)
    arr[1] == arr[2]  => 2 == 2 (Match)

    Output: true

    Time Complexity: O(n)
    - O(n) to traverse and store elements.
    - O(n) to check palindrome.

    Space Complexity: O(n)
    - Vector stores all node values.


    ============================================================
    APPROACH 2: OPTIMAL (SLOW + FAST + REVERSE)
    ============================================================

    Explanation:

    In this approach, we do not use any extra array.
    We use slow-fast pointers to find the middle,
    reverse the second half and compare both halves.

    Steps:

    1. Find Middle:
       - Initialize slow and fast at head.
       - Slow moves one step.
       - Fast moves two steps.
       - Stop when fast cannot move further.
       - Slow points to the end of the first half.

    2. Reverse Second Half:
       - Start from slow->next.
       - Reverse the second half of the linked list.
       - Store the new head of reversed half.

    3. Compare Both Halves:
       - First pointer starts from head.
       - Second pointer starts from reversed second half.
       - Compare their values.
       - If any values differ, mark palindrome as false.

    4. Restore Linked List:
       - Reverse the second half again.
       - Connect it back to the first half.
       - Return the result.

    Dry Run:

    Input: 1 -> 2 -> 2 -> 1

    Step 1: Find Middle
    slow points to the second node (2).

    Step 2: Reverse Second Half

    Original:
    1 -> 2 -> 2 -> 1

    Reversed second half:
    1 -> 2

    Step 3: Compare

    First Half:  1 -> 2
    Second Half: 1 -> 2

    Both halves match.

    Step 4: Restore Original Linked List

    1 -> 2 -> 2 -> 1

    Output: true

    Time Complexity: O(n)
    - Find middle: O(n)
    - Reverse second half: O(n)
    - Compare both halves: O(n)
    - Restore linked list: O(n)

    Space Complexity: O(1)
    - Only pointers are used.
    - No extra data structure is required.


    ============================================================
    COMPARISON OF BOTH APPROACHES
    ============================================================

    Approach 1: Brute Force (Vector)
    Time Complexity: O(n)
    Space Complexity: O(n)

    Approach 2: Optimal (Slow-Fast + Reverse)
    Time Complexity: O(n)
    Space Complexity: O(1)

    Recommended Approach:
    Approach 2 is optimal because it uses constant
    auxiliary space and does not require an extra vector.
*/


class Solution {

    // ========================================================
    // APPROACH 1: BRUTE FORCE (USING VECTOR)
    // ========================================================

public:
    bool isPalindromeBrute(ListNode* head) {

        // Store linked list values in vector
        vector<int> arr;
        ListNode* temp = head;

        while (temp != nullptr) {
            arr.push_back(temp->val);
            temp = temp->next;
        }

        // Initialize two pointers
        int left = 0;
        int right = arr.size() - 1;

        // Check palindrome
        while (left < right) {

            if (arr[left] != arr[right])
                return false;

            left++;
            right--;
        }

        return true;
    }


    // ========================================================
    // APPROACH 2: OPTIMAL (SLOW + FAST + REVERSE)
    // ========================================================

    // Function to reverse linked list
    ListNode* reverseList(ListNode* head) {

        ListNode* prev = nullptr;

        while (head != nullptr) {

            ListNode* nextNode = head->next;

            head->next = prev;

            prev = head;
            head = nextNode;
        }

        return prev;
    }

    bool isPalindrome(ListNode* head) {

        // Handle empty and single-node linked list
        if (head == nullptr || head->next == nullptr)
            return true;

        // Step 1: Find middle using slow and fast pointers
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast->next != nullptr &&
               fast->next->next != nullptr) {

            slow = slow->next;
            fast = fast->next->next;
        }

        // Step 2: Reverse the second half
        ListNode* secondHalf = reverseList(slow->next);

        // Step 3: Compare both halves
        ListNode* first = head;
        ListNode* second = secondHalf;

        bool isPal = true;

        while (second != nullptr) {

            if (first->val != second->val) {
                isPal = false;
                break;
            }

            first = first->next;
            second = second->next;
        }

        // Step 4: Restore original linked list
        slow->next = reverseList(secondHalf);

        return isPal;
    }
};


/*
    FINAL COMPLEXITY COMPARISON:

    Brute Force:
    Time Complexity: O(n)
    Space Complexity: O(n)

    Optimal:
    Time Complexity: O(n)
    Space Complexity: O(1)

    Key Concepts Learned:
    1. Vector and Two Pointers
    2. Slow and Fast Pointers
    3. Find Middle of Linked List
    4. Reverse Linked List
    5. Compare Two Halves
    6. Restore Original Linked List
*/
