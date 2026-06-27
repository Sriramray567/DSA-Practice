// ------------------------- Brute Force Approach -------------------------
/*
Problem LINK:-https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/


Approach:
1. Traverse the entire array from left to right.
2. Keep track of the smallest element encountered so far.
3. Update the minimum whenever a smaller element is found.
4. After completing the traversal, return the minimum element.

Example:
nums = [4,5,6,7,0,1,2]

min = 4
5 > 4  -> ignore
6 > 4  -> ignore
7 > 4  -> ignore
0 < 4  -> min = 0
1 > 0  -> ignore
2 > 0  -> ignore

Answer = 0

Time Complexity : O(n)
- Every element is visited exactly once.

Space Complexity : O(1)
- No extra space is used except a single variable.
*/

// ------------------------- Optimal Approach (Binary Search) -------------------------

/*
Approach:
1. Use Binary Search because the array is sorted and then rotated.
2. At every step, identify which half is sorted.
3. If the left half is sorted:
   - nums[low] is the smallest element of that half.
   - Update the answer with nums[low].
   - Search in the right (unsorted) half.
4. Otherwise:
   - The rotation point lies in the left half.
   - nums[mid] can be the minimum element.
   - Update the answer with nums[mid].
   - Search in the left half.
5. Continue until the search space becomes empty.
6. Return the minimum element found.

Why it works:
- In a rotated sorted array, at least one half is always sorted.
- The minimum element is either:
  • the first element of the sorted half, or
  • inside the unsorted half containing the rotation point.
- Binary Search eliminates half of the search space in every iteration.

Time Complexity : O(log n)
- The search space is reduced by half in every iteration.

Space Complexity : O(1)
- Only a few variables are used.
*/

class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0;
        int high = nums.size() - 1;

        // Stores the minimum element found so far
        int ans = INT_MAX;

        while (low <= high) {
            // Calculate middle index safely
            int mid = low + (high - low) / 2;

            // If left half is sorted
            if (nums[low] <= nums[mid]) {

                // The first element of the sorted half is the minimum
                ans = min(ans, nums[low]);

                // Search in the right half
                low = mid + 1;
            }
            else {
                // Right half is sorted, so the pivot lies in the left half.
                // nums[mid] can be the minimum element.
                ans = min(ans, nums[mid]);

                // Continue searching in the left half
                high = mid - 1;
            }
        }

        return ans;
    }
};
