
/*
=========================================================
Problem: Sort a Linked List of 0s, 1s and 2s
Pattern: Linked List
=========================================================

Problem Statement:
Given a linked list containing only 0s, 1s and 2s,
sort the linked list in ascending order.

Example:
Input:  1 -> 2 -> 0 -> 1 -> 2 -> 0 -> NULL
Output: 0 -> 0 -> 1 -> 1 -> 2 -> 2 -> NULL

=========================================================
APPROACH 1: BRUTE FORCE (Using Sorting)
=========================================================

Explanation:
1. Store all node values in a vector.
2. Sort the vector using sort().
3. Copy the sorted values back into the linked list.

Advantages:
- Very easy to understand.
- Uses the standard sorting algorithm.

Disadvantages:
- Requires extra space.
- Changes node data instead of rearranging node links.

Time Complexity: O(n log n)
Auxiliary Space: O(n)

Brute Force Code:
*/
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        vector<int> arr;
        ListNode* temp = head;

        while (temp != nullptr) {
            arr.push_back(temp->data);
            temp = temp->next;
        }

        sort(arr.begin(), arr.end());

        temp = head;
        int i = 0;

        while (temp != nullptr) {
            temp->data = arr[i++];
            temp = temp->next;
        }

        return head;
    }
};
/*
=========================================================
APPROACH 2: BETTER (Counting 0s, 1s and 2s)
=========================================================

Explanation:
1. Traverse the list and count 0s, 1s and 2s.
2. Traverse again and write all 0s first.
3. Write all 1s next.
4. Write all 2s at the end.

Advantages:
- Linear time complexity.
- No extra array or stack is needed.

Disadvantages:
- Modifies node data.
- Not suitable when node values must remain unchanged.

Time Complexity: O(n)
Auxiliary Space: O(1)

Better Code:
*/
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        int cnt0 = 0, cnt1 = 0, cnt2 = 0;
        ListNode* temp = head;

        // Count 0s, 1s and 2s
        while (temp != nullptr) {
            if (temp->data == 0) cnt0++;
            else if (temp->data == 1) cnt1++;
            else cnt2++;

            temp = temp->next;
        }

        temp = head;

        // Update values using a single loop
        while (temp != nullptr) {
            if (cnt0 > 0) {
                temp->data = 0;
                cnt0--;
            }
            else if (cnt1 > 0) {
                temp->data = 1;
                cnt1--;
            }
            else {
                temp->data = 2;
                cnt2--;
            }

            temp = temp->next;
        }

        return head;
    }
};
/*
=========================================================
APPROACH 3: OPTIMAL (Three Separate Linked Lists)
=========================================================

Explanation:
Create three separate lists:
1. Zero list: nodes containing 0.
2. One list: nodes containing 1.
3. Two list: nodes containing 2.

Use dummy nodes to simplify list creation.

Steps:
1. Create three dummy nodes.
2. Traverse the original list.
3. Save temp->next before changing any links.
4. Attach the current node to its corresponding list.
5. Connect the zero list to the one list if it exists;
   otherwise, connect it to the two list.
6. Connect the one list to the two list.
7. Set the final next pointer to nullptr.
8. Return the first actual node.

Advantages:
- Does not modify node data.
- Rearranges the actual nodes.
- Uses constant auxiliary space.
- No vector, stack or sorting algorithm required.

Time Complexity: O(n)
Auxiliary Space: O(1)

=========================================================
OPTIMAL CODE (ACTIVE SOLUTION)
=========================================================
*/

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return head;

        // Dummy nodes for the three lists
        ListNode zeroDummy(-1), oneDummy(-1), twoDummy(-1);

        ListNode* zero = &zeroDummy;
        ListNode* one = &oneDummy;
        ListNode* two = &twoDummy;

        ListNode* temp = head;

        while (temp != nullptr) {
            // Save the next node before changing links
            ListNode* nextNode = temp->next;

            if (temp->data == 0) {
                zero->next = temp;
                zero = temp;
            }
            else if (temp->data == 1) {
                one->next = temp;
                one = temp;
            }
            else {
                two->next = temp;
                two = temp;
            }

            temp = nextNode;
        }

        // Connect zero list to one list, or two list
        zero->next = oneDummy.next
                     ? oneDummy.next
                     : twoDummy.next;

        // Connect one list to two list
        one->next = twoDummy.next;

        // Terminate the final list
        two->next = nullptr;

        return zeroDummy.next;
    }
};

/*
=========================================================
DRY RUN
=========================================================

Input:
1 -> 2 -> 0 -> 1 -> 2 -> 0 -> NULL

After separating nodes:

Zero list:
0 -> 0 -> NULL

One list:
1 -> 1 -> NULL

Two list:
2 -> 2 -> NULL

After connecting all lists:

Output:
0 -> 0 -> 1 -> 1 -> 2 -> 2 -> NULL

=========================================================
COMPLEXITY COMPARISON
=========================================================

Approach       Time           Auxiliary Space
------------------------------------------------
Brute Force    O(n log n)     O(n)
Better         O(n)           O(1)
Optimal        O(n)           O(1)

=========================================================
EDGE CASES
=========================================================

1. Empty list:
   NULL

2. Single node:
   1 -> NULL

3. All nodes are 0:
   0 -> 0 -> 0 -> NULL

4. All nodes are 1:
   1 -> 1 -> 1 -> NULL

5. All nodes are 2:
   2 -> 2 -> 2 -> NULL

6. Mixed nodes:
   2 -> 0 -> 1 -> 2 -> 0 -> NULL
   Output: 0 -> 0 -> 1 -> 2 -> 2 -> NULL

=========================================================
KEY TAKEAWAY
=========================================================

Brute Force:
Store values and sort them.

Better:
Count 0s, 1s and 2s, then overwrite node data.

Optimal:
Rearrange actual node links using three separate lists.

The optimal approach is preferred when node data must
not be changed.

=========================================================
*/
