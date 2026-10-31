    // ==========================================
    // Approach 1: Hash Map + Timer
    // ==========================================

    /*
       LOGIC:

       1. Create an unordered_map to store node addresses
          and their visiting time/index.
       2. Traverse the linked list using temp.
       3. If the current node is already present in the map,
          it means we have detected a cycle.
       4. Get the previous visiting time from the map.
       5. Calculate the loop length:

          Loop Length = Current Timer - Previous Timer

       6. If temp reaches NULL, no loop exists.

       Example:

       1 -> 2 -> 3 -> 4 -> 5
                 ^         |
                 |_________|

       Node 3 was first visited at timer = 3.
       It is visited again at timer = 6.

       Loop Length = 6 - 3 = 3

       TC: O(N) average
       SC: O(N)
    */

    int findLengthHash(ListNode* head) {

        unordered_map<ListNode*, int> mpp;

        ListNode* temp = head;

        int timer = 1;

        while(temp != nullptr) {

            // Check whether current node is already visited
            if(mpp.find(temp) != mpp.end()) {

                int value = mpp[temp];

                // Calculate length of the loop
                return timer - value;
            }

            // Store node address and visiting time
            mpp[temp] = timer;

            timer++;

            temp = temp->next;
        }

        // No loop found
        return 0;
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

       PHASE 2: Calculate Loop Length

       1. Both pointers are currently at the same node.
       2. Move fast one step ahead.
       3. Initialize count = 1.
       4. Continue moving fast one step at a time.
       5. Increment count after every move.
       6. Stop when fast reaches slow again.

       The count represents the length of the cycle.

       TC: O(N)
       SC: O(1)
    */

    // Helper function to calculate loop length
    int findLengthOfLoop(ListNode* slow, ListNode* fast) {

        fast = fast->next;

        int count = 1;

        while(slow != fast) {

            count++;

            fast = fast->next;
        }

        return count;
    }


    // Main function for optimal approach
    int findLengthOfLoop(ListNode* head) {

        ListNode* slow = head;
        ListNode* fast = head;

        // PHASE 1: Detect cycle
        while(fast != nullptr && fast->next != nullptr) {

            // Slow moves one step
            slow = slow->next;

            // Fast moves two steps
            fast = fast->next->next;

            // Cycle detected
            if(slow == fast) {

                // PHASE 2: Calculate cycle length
                return findLengthOfLoop(slow, fast);
            }
        }

        // No cycle exists
        return 0;
    }
};


/*
================================================
COMPARISON OF BOTH APPROACHES
================================================

Approach                Time Complexity    Space Complexity

Hash Map + Timer        O(N) Average       O(N)
Floyd's Algorithm       O(N)                O(1)


FINAL CONCLUSION:

1. Hash Map stores visited node addresses and their
   visiting time.
2. Repeated node detection helps calculate loop length.
3. Floyd's algorithm detects the cycle using two pointers.
4. After collision, one pointer completes one full cycle
   to calculate its length.

Floyd's Algorithm is optimal because it uses O(1)
extra space.
*/
