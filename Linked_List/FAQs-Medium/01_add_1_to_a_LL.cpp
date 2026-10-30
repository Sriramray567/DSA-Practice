
/*
    Problem: Add One to a Number Represented by Linked List

    Given a linked list representing a positive integer,
    add 1 to the number and return the updated linked list.

    Example 1:
    Input:  1 -> 2 -> 3
    Output: 1 -> 2 -> 4

    Example 2:
    Input:  9 -> 9
    Output: 1 -> 0 -> 0


    ============================================================
    APPROACH 1: REVERSE LINKED LIST + CARRY (ITERATIVE)
    ============================================================

    Explanation:

    Addition starts from the rightmost digit, but a linked
    list stores digits from left to right.

    Therefore, we reverse the linked list to process digits
    from right to left.

    Steps:
    1. Reverse the given linked list.
    2. Initialize carry = 1.
    3. Traverse the reversed linked list.
    4. Calculate sum = current digit + carry.
    5. Update digit using sum % 10.
    6. Update carry using sum / 10.
    7. If carry remains after the last node, create a new node.
    8. Reverse the linked list again to restore its original order.

    Dry Run:

    Input: 1 -> 2 -> 9

    After Reverse:
    9 -> 2 -> 1

    Addition:
    9 + 1 = 10  => Digit = 0, Carry = 1
    2 + 1 = 3   => Digit = 3, Carry = 0
    1 + 0 = 1   => Digit = 1, Carry = 0

    After Reverse Again:
    1 -> 3 -> 0

    Output: 1 -> 3 -> 0

    Time Complexity: O(n)
    Space Complexity: O(1) Auxiliary Space

  
*/


class Solution {

    // ========================================================
    // APPROACH 1: REVERSE + CARRY (ITERATIVE)
    // ========================================================

    Node* reverseList(Node* head) {
        Node* prev = nullptr;

        while (head != nullptr) {
            Node* nextNode = head->next;
            head->next = prev;
            prev = head;
            head = nextNode;
        }

        return prev;
    }

public:

    Node* addOne(Node* head) {

        // Step 1: Reverse the linked list
        head = reverseList(head);

        Node* curr = head;
        Node* prev = nullptr;
        int carry = 1;

        // Step 2: Add one using carry propagation
        while (curr != nullptr) {

            int sum = curr->data + carry;

            // Update current digit
            curr->data = sum % 10;

            // Calculate next carry
            carry = sum / 10;

            prev = curr;
            curr = curr->next;

            // Stop if carry becomes zero
            if (carry == 0) break;
        }

        // Step 3: Create a new node if carry remains
        if (carry > 0) {
            prev->next = new Node(carry);
        }

        // Step 4: Reverse again to restore original order
        return reverseList(head);
    }


    // ========================================================
    // APPROACH 2: RECURSION + CARRY PROPAGATION
    // ========================================================

    /*
      ============================================================
    APPROACH 2: RECURSION + CARRY PROPAGATION
    ============================================================

    Explanation:

    In this approach, we do not reverse the linked list.

    Recursion is used to reach the last node first.
    While returning from recursion, carry is propagated
    from right to left.

    Steps:
    1. Base Case:
       If temp == nullptr, return 1 (initial carry).

    2. Recursively call helper(temp->next).

    3. Add the returned carry to the current node's digit.

    4. If the updated digit is less than 10:
       Return 0 because no carry remains.

    5. Otherwise:
       Set the current digit to 0 and return 1.

    6. After reaching the first node, if carry remains,
       create a new node and insert it before the head.

    Dry Run:

    Input: 1 -> 2 -> 9

    Recursion reaches the last node first.

    Node 9: 9 + 1 = 10 => Digit = 0, Carry = 1
    Node 2: 2 + 1 = 3  => Digit = 3, Carry = 0
    Node 1: 1 + 0 = 1  => Digit = 1, Carry = 0

    Output: 1 -> 3 -> 0

    Special Case:

    Input: 9 -> 9 -> 9

    All nodes become 0 and carry remains 1.
    A new node containing 1 is inserted before the head.

    Output: 1 -> 0 -> 0 -> 0

    Time Complexity: O(n)
    Space Complexity: O(n) due to recursion stack.


    ============================================================
    COMPARISON OF BOTH APPROACHES
    ============================================================

    Approach 1: Reverse Method
    Time Complexity: O(n)
    Space Complexity: O(1)

    Approach 2: Recursion Method
    Time Complexity: O(n)
    Space Complexity: O(n)

    Both approaches are correct.

    Reverse Method is better in terms of auxiliary space.
    Recursion Method demonstrates recursive carry propagation.
    */
    /*
       Recursive helper function:

       Base case:
       When temp becomes nullptr, return 1.

       This initial carry travels from the last node
       towards the first node during recursion return.
    */

    int helper(Node* temp) {

        if (temp == nullptr) return 1;

        // Reach the last node first
        int carry = helper(temp->next);

        // Add carry to the current digit
        temp->data += carry;

        // No carry if digit is less than 10
        if (temp->data < 10) return 0;

        // If digit becomes 10, make it 0
        temp->data = 0;

        // Propagate carry to the previous node
        return 1;
    }

    Node* addOneRecursive(Node* head) {

        // Start recursive carry propagation
        int carry = helper(head);

        // If carry remains, create a new head
        if (carry == 1) {
            Node* newNode = new Node(1);
            newNode->next = head;
            return newNode;
        }

        return head;
    }
};
