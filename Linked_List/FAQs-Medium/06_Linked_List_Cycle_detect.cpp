// # LeetCode 141: Linked List Cycle

// **Problem:** Given the head of a linked list, determine if the linked list contains a cycle.

// A cycle exists if a node's `next` pointer points back to a previously visited node.

---


class Solution {
public:

    // ==========================================
    // Approach 1: Brute Force (Hash Map)
    // ==========================================

    /*
       LOGIC:
       1. Create an unordered_map to store visited node addresses.
       2. Traverse the linked list using temp.
       3. Before storing the current node, check whether
          its address already exists in the map.
       4. If the node is already present, a cycle exists.
       5. Otherwise, store its address and move forward.
       6. If temp reaches NULL, no cycle exists.

       IMPORTANT:
       We store node addresses (ListNode*), not node values.
       Two different nodes can have the same value.

       TC: O(N) average
       SC: O(N)
    */

    bool hasCycleHash(ListNode* head) {

        unordered_map<ListNode*, int> mpp;

        ListNode* temp = head;

        while(temp != nullptr) {

            // Check whether current node is already visited
            if(mpp.find(temp) != mpp.end()) {
                return true;
            }

            // Mark current node as visited
            mpp[temp] = 1;

            // Move to the next node
            temp = temp->next;
        }

        // Reached NULL, so no cycle exists
        return false;
    }


    // ==========================================
    // Approach 2: Optimal (Floyd's Cycle Detection)
    // Slow and Fast Pointer
    // ==========================================

    /*
       LOGIC:
       1. Initialize slow and fast pointers at head.
       2. Move slow by one step.
       3. Move fast by two steps.
       4. If both pointers meet, a cycle exists.
       5. If fast reaches NULL or fast->next reaches NULL,
          no cycle exists.

       WHY DOES IT WORK?
       If a cycle exists, the fast pointer moves faster
       than the slow pointer and eventually catches it.

       TC: O(N)
       SC: O(1)
    */

    bool hasCycleOptimal(ListNode* head) {

        ListNode* slow = head;
        ListNode* fast = head;

        // Check whether fast and its next node exist
        while(fast != nullptr && fast->next != nullptr) {

            // Slow moves one step
            slow = slow->next;

            // Fast moves two steps
            fast = fast->next->next;

            // If both point to the same node, cycle exists
            if(slow == fast) {
                return true;
            }
        }

        // Fast reached NULL, so no cycle exists
        return false;
    }
};


/*
==========================================
COMPARISON OF BOTH APPROACHES
==========================================

Approach             Time Complexity    Space Complexity

Hash Map             O(N) Average       O(N)
Floyd's Algorithm    O(N)                O(1)

FINAL CONCLUSION:

Floyd's Cycle Detection is the optimal approach
because it uses constant extra space.

Hash Map approach is useful for understanding
how visited nodes can be tracked using hashing.

IMPORTANT LEARNINGS:
1. Compare node addresses, not node values.
2. unordered_map stores node addresses as keys.
3. slow moves one step and fast moves two steps.
4. Always check fast != NULL and fast->next != NULL
   before accessing fast->next->next.
*/
```

---

// ## Complexity Comparison

// | Approach | TC | SC |
// |---|---|---|
// | Hash Map | O(N) average | O(N) |
// | Floyd's Algorithm | O(N) | O(1) |

// **GitHub file name:** `Linked_List_Cycle.cpp`

// **DSA Learning Tip:** First understand why Hash Map works, then understand why Floyd's algorithm detects a cycle without storing visited nodes. This distinction is important for interviews.
