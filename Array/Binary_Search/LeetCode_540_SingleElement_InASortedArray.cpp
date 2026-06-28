// Problem: LeetCode 540 - Single Element in a Sorted Array
// Link: https://leetcode.com/problems/single-element-in-a-sorted-array/
//
// Brute Force Approach
// 1. Traverse the array two elements at a time.
// 2. Every element except one appears exactly twice.
// 3. If a pair is not equal, the first element of that pair is the answer.
// 4. If no broken pair is found, the last element is the single element.
//
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {

        int n = nums.size();

        // Edge case: Only one element
        if (n == 1)
            return nums[0];

        // Traverse the array in pairs
        for (int i = 0; i < n - 1; i += 2) {

            // Pair is broken
            if (nums[i] != nums[i + 1])
                return nums[i];
        }

        // Unique element is the last element
        return nums[n - 1];
    }
};


// Problem: LeetCode 540 - Single Element in a Sorted Array
// Link: https://leetcode.com/problems/single-element-in-a-sorted-array/
//
// Approach: Binary Search
// 1. Handle edge cases separately.
// 2. Find the unique element using Binary Search.
// 3. Check which side follows the pairing pattern.
// 4. Eliminate half of the search space in every iteration.
//
// Time Complexity: O(log n)
// Space Complexity: O(1)

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {

        int n = nums.size();

        // Edge case: only one element
        if (n == 1)
            return nums[0];

        // Unique element at the beginning
        if (nums[0] != nums[1])
            return nums[0];

        // Unique element at the end
        if (nums[n - 1] != nums[n - 2])
            return nums[n - 1];

        int low = 1;
        int high = n - 2;

        while (low <= high) {

            int mid = low + (high - low) / 2;

            // Found the unique element
            if (nums[mid] != nums[mid - 1] &&
                nums[mid] != nums[mid + 1])
                return nums[mid];

            // Pairing pattern is correct
            if ((mid % 2 == 1 && nums[mid] == nums[mid - 1]) ||
                (mid % 2 == 0 && nums[mid] == nums[mid + 1])) {

                low = mid + 1;
            }

            // Pairing pattern is broken
            else {
                high = mid - 1;
            }
        }

        return -1;
    }
};

/*
Optimal Approach (Binary Search):

1. Handle edge cases where the unique element is at the
   beginning, end, or the array contains only one element.

2. Apply Binary Search.

3. Every element appears exactly twice except one.

4. Before the unique element:
   - First occurrence is at an even index.
   - Second occurrence is at an odd index.

5. After the unique element:
   - The pairing pattern gets disturbed.

6. Use the index parity and neighboring elements to determine
   whether the unique element lies on the left or right half.

7. Continue until the unique element is found.

Why it works:
- The unique element changes the even-odd pairing pattern.
- Binary Search uses this property to eliminate half of the
  search space in every iteration.

Time Complexity: O(log n)
Space Complexity: O(1)
*/
