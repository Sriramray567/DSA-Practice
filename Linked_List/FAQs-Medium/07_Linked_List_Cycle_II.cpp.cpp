class Solution {
public:

    // ==========================================
    // Approach 1: Hash Map (unordered_map)
    // ==========================================

    /*
       LOGIC:

       1. Create an unordered_map to store visited node addresses.
       2. Traverse the linked list using temp.
       3. Check whether the current node address
          already exists in the map.
       4. If it exists, that node is the starting
          point of the cycle.
       5. Otherwise, store its address and move ahead.
       6. If temp reaches NULL, no cycle exists.

       IMPORTANT:
       We store node addresses (ListNode*), not values.
       Because two different nodes can have the same value.

       TC: O(N) average
       SC: O(N)
    */

    ListNode* detectCycleHash(ListNode* head) {

        unordered_map<ListNode*, int> mpp;

        ListNode* temp = head;

        while(temp != nullptr) {

            // Check whether current node is already visited
            if(mpp.find(temp) != mpp.end()) {
                return temp;
            }

            // Mark current node as visited
            mpp[temp] = 1;

            // Move to the next node
            temp = temp->next;
        }

        // No cycle found
        return nullptr;
    }


    // ==========================================
    // Approach 2: Optimal (Floyd's Cycle Detection)
    // Fast and Slow Pointer
    // ==========================================

    /*
       LOGIC:

       PHASE 1: Detect Cycle

       1. Initialize slow and fast pointers at head.
       2. Move slow by one step.
       3. Move fast by two steps.
       4. If both pointers meet, a cycle exists.
       5. If fast reaches NULL, no cycle exists.

       PHASE 2: Find Starting Point

       1. After both pointers meet, reset slow to head.
       2. Keep fast at the meeting point.
       3. Move both pointers one step at a time.
       4. The point where both meet is the starting
          node of the cycle.

       TC: O(N)
       SC: O(1)
    */

    ListNode* detectCycleOptimal(ListNode* head) {

        if(head == nullptr || head->next == nullptr) {
            return nullptr;
        }

        ListNode* slow = head;
        ListNode* fast = head;

        // PHASE 1: Detect cycle
        while(fast != nullptr && fast->next != nullptr) {

            // Slow moves one step
            slow = slow->next;

            // Fast moves two steps
            fast = fast->next->next;

            // Both pointers meet: cycle detected
            if(slow == fast) {

                // PHASE 2: Find starting point
                slow = head;

                while(slow != fast) {

                    // Move both pointers one step
                    slow = slow->next;
                    fast = fast->next;
                }

                // Return the starting node of cycle
                return slow;
            }
        }

        // No cycle exists
        return nullptr;
    }
};


/*
================================================
COMPARISON OF BOTH APPROACHES
================================================

Approach                 Time Complexity    Space Complexity

Hash Map                 O(N) Average       O(N)
Floyd's Algorithm        O(N)                O(1)


FINAL CONCLUSION:

1. Hash Map stores visited node addresses.
2. Floyd's algorithm uses two pointers.
3. Floyd's algorithm is optimal because it uses
   constant extra space.

IMPORTANT LEARNINGS:

- Compare node addresses, not node values.
- unordered_map<ListNode*, int> stores node addresses.
- Slow pointer moves one step.
- Fast pointer moves two steps.
- After collision, reset slow to head.
- Move both pointers one step at a time to find
  the starting point of the cycle.
*/
