/*
------------------------------------------------------------
Problem : LeetCode 81 - Search in Rotated Sorted Array II
Problem Link:-https://leetcode.com/problems/search-in-rotated-sorted-array-ii/

Approach:
1. Use Binary Search to search efficiently.
2. If nums[mid] == target, return true.
3. If nums[low] == nums[mid] == nums[high], we cannot determine
   which half is sorted because of duplicates.
   Shrink the search space by:
       low++;
       high--;
4. Otherwise, identify the sorted half.
5. If the target lies inside the sorted half, search there.
6. Otherwise, search the other half.

Key Idea:
- In a rotated sorted array, one half is always sorted.
- Duplicates can make both halves appear identical.
- Removing duplicate boundaries helps restore the Binary Search logic.

Time Complexity:
- Average Case : O(log n)
- Worst Case   : O(n)

Space Complexity:
- O(1)
------------------------------------------------------------
*/

class Solution {
public:
    bool search(vector<int>& nums, int target) {

        int n = nums.size();
        int low = 0;
        int high = n - 1;

        while (low <= high) {

            // Find the middle element
            int mid = low + (high - low) / 2;

            // Target found
            if (nums[mid] == target)
                return true;

            // Cannot determine the sorted half due to duplicates
            if (nums[low] == nums[mid] && nums[mid] == nums[high]) {
                low++;
                high--;
                continue;
            }

            // Left half is sorted
            if (nums[low] <= nums[mid]) {

                // Target lies in the left half
                if (nums[low] <= target && target <= nums[mid]) {
                    high = mid - 1;
                }
                // Search in the right half
                else {
                    low = mid + 1;
                }
            }

            // Right half is sorted
            else {

                // Target lies in the right half
                if (nums[mid] <= target && target <= nums[high]) {
                    low = mid + 1;
                }
                // Search in the left half
                else {
                    high = mid - 1;
                }
            }
        }

        // Target not found
        return false;
    }
};
