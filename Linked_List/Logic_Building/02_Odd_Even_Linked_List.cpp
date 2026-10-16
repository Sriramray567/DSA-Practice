
/*
=========================================================
Problem: Odd Even Linked List
Pattern: Linked List + Pointer Manipulation
=========================================================

Problem Statement:
Rearrange a linked list so that all nodes at odd positions
come first, followed by all nodes at even positions.

The relative order of nodes within each group must remain
the same.

Example:
Input:  1 -> 2 -> 3 -> 4 -> 5 -> NULL
Output: 1 -> 3 -> 5 -> 2 -> 4 -> NULL

NOTE:
Odd and even refer to node positions, not node values.

=========================================================
APPROACH 1: BRUTE FORCE (Using Extra Vectors)
=========================================================

Explanation:
1. Traverse the linked list.
2. Store odd-position node values in the odd vector.
3. Store even-position node values in the even vector.
4. Copy odd values back first.
5. Copy even values back afterward.

Advantages:
- Easy to understand and implement.

Disadvantages:
- Requires extra space.
- Changes node values instead of rearranging node links.

Time Complexity: O(n)
Auxiliary Space: O(n)

Brute Force Code:
*/
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return head;

        vector<int> odd, even;
        ListNode* temp = head;
        int pos = 1;

        while (temp != nullptr) {
            if (pos % 2 == 1)
                odd.push_back(temp->val);
            else
                even.push_back(temp->val);

            temp = temp->next;
            pos++;
        }

        temp = head;

        for (int x : odd) {
            temp->val = x;
            temp = temp->next;
        }

        for (int x : even) {
            temp->val = x;
            temp = temp->next;
        }

        return head;
    }
};

/*
=========================================================
APPROACH 2: OPTIMAL (In-Place Pointer Manipulation)
=========================================================

Explanation:
We use three pointers:

1. odd:
   Tracks the last node in the odd-position list.

2. even:
   Tracks the last node in the even-position list.

3. evenHead:
   Stores the first even-position node so that we can
   connect the even list after the odd list.

Steps:
1. Handle empty and single-node lists.
2. Initialize odd = head and even = head->next.
3. Save evenHead = even.
4. Connect odd nodes by skipping the next even node.
5. Connect even nodes by skipping the next odd node.
6. Move odd and even pointers forward.
7. Connect the odd list to the even list.
8. Return head.

Time Complexity: O(n)
Auxiliary Space: O(1)

Why is it optimal?
- No extra vector or stack.
- Rearranges actual node links.
- Preserves the relative order of nodes.
- Uses constant auxiliary space.

=========================================================
OPTIMAL CODE
=========================================================
*/

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {

        // Handle empty or single-node list
        if (head == nullptr || head->next == nullptr)
            return head;

        // Initialize odd and even pointers
        ListNode* odd = head;
        ListNode* even = head->next;

        // Save the beginning of the even list
        ListNode* evenHead = even;

        // Rearrange odd and even position nodes
        while (even != nullptr && even->next != nullptr) {

            // Connect current odd node to next odd node
            odd->next = even->next;

            // Connect current even node to next even node
            even->next = odd->next->next;

            // Move both pointers forward
            odd = odd->next;
            even = even->next;
        }

        // Attach even list after odd list
        odd->next = evenHead;

        return head;
    }
};

/*
=========================================================
DRY RUN
=========================================================

Input:
1 -> 2 -> 3 -> 4 -> 5 -> NULL

Initial:
odd = 1
even = 2
evenHead = 2

After rearranging:
Odd-position list:
1 -> 3 -> 5 -> NULL

Even-position list:
2 -> 4 -> NULL

Final connection:
odd->next = evenHead

Output:
1 -> 3 -> 5 -> 2 -> 4 -> NULL

=========================================================
EDGE CASES
=========================================================

1. Empty list:
   NULL -> NULL

2. Single node:
   1 -> NULL

3. Two nodes:
   1 -> 2 -> NULL

4. Odd number of nodes:
   1 -> 2 -> 3 -> 4 -> 5
   Output: 1 -> 3 -> 5 -> 2 -> 4

5. Even number of nodes:
   1 -> 2 -> 3 -> 4
   Output: 1 -> 3 -> 2 -> 4

=========================================================
FINAL COMPLEXITY
=========================================================

Brute Force:
Time: O(n)
Space: O(n)

Optimal:
Time: O(n)
Space: O(1)

Key Takeaway:
The brute-force approach uses extra vectors to rearrange
values. The optimal approach rearranges the actual links
using pointers and constant auxiliary space.

=========================================================
*/
