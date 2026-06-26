/*Idea: In a rotated sorted array,
at least one half (left or right) is always sorted. 
At each step, identify the sorted half. 
If the target lies within that sorted half, continue searching there; 
otherwise, search the other half. 
This preserves the Binary Search property and achieves O(log n) time complexity.*/

// Problem link:- https://leetcode.com/problems/search-in-rotated-sorted-array/


class Solution {
public:
    int search(vector<int>& nums, int target) {

        int low = 0;
        int high = nums.size() - 1;

        while (low <= high) {

            // Find the middle element safely (avoids integer overflow)
            int mid = low + (high - low) / 2;

            // Target found
            if (nums[mid] == target)
                return mid;

            // Check if the left half is sorted
            if (nums[low] <= nums[mid]) {

                // If target lies within the sorted left half,
                // discard the right half.
                if (nums[low] <= target && target < nums[mid]) {
                    high = mid - 1;
                }
                // Otherwise, search in the right half.
                else {
                    low = mid + 1;
                }
            }

            // Otherwise, the right half must be sorted.
            else {

                // If target lies within the sorted right half,
                // discard the left half.
                if (nums[mid] < target && target <= nums[high]) {
                    low = mid + 1;
                }
                // Otherwise, search in the left half.
                else {
                    high = mid - 1;
                }
            }
        }

        // Target does not exist in the array.
        return -1;
    }
};
