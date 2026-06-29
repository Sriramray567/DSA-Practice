/*--------------Brute Force ---------------*/
// Problem Link:- https://leetcode.com/problems/find-peak-element/description/
// Brute Force Approach
//
// 1. Traverse the array.
// 2. For every element, check whether it is greater than its neighbors.
// 3. If it satisfies the peak condition, return its index.
//
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    int findPeakElement(vector<int>& nums) {

        int n = nums.size();

        for (int i = 0; i < n; i++) {

            if ((i == 0 || nums[i] > nums[i - 1]) &&
                (i == n - 1 || nums[i] > nums[i + 1])) {
                return i;
            }
        }

        return -1;
    }
};


/*
Optimal Approach (Binary Search):

1. Handle edge cases where the peak is at the beginning,
   end, or the array contains only one element.

2. Find the middle element.

3. If the middle element is greater than both neighbors,
   it is the peak.

4. If the array is increasing at mid
   (nums[mid] > nums[mid - 1]),
   then a peak must exist on the right side.

5. Otherwise, a peak must exist on the left side.

6. Continue Binary Search until a peak is found.

Why it works:
- If the sequence is increasing, moving right will
  eventually reach a peak.
- If the sequence is decreasing, moving left will
  eventually reach a peak.
- Therefore, one half can always be discarded.

Time Complexity: O(log n)
Space Complexity: O(1)
*/


class Solution {
public:
    int findPeakElement(vector<int>& nums) {

        int n = nums.size();

        // Only one element
        if (n == 1)
            return 0;

        // Peak at the beginning
        if (nums[0] > nums[1])
            return 0;

        // Peak at the end
        if (nums[n - 1] > nums[n - 2])
            return n - 1;

        int low = 1;
        int high = n - 2;

        while (low <= high) {

            int mid = low + (high - low) / 2;

            // Peak found
            if (nums[mid] > nums[mid - 1] &&
                nums[mid] > nums[mid + 1])
                return mid;

            // Increasing slope
            else if (nums[mid] > nums[mid - 1])
                low = mid + 1;

            // Decreasing slope
            else
                high = mid - 1;
        }

        return -1;
    }
};
