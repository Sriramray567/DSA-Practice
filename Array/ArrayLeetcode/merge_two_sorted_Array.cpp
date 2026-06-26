/*
------------------------------------------------------------
Problem : LeetCode 88 - Merge Sorted Array
Problem Link:- https://leetcode.com/problems/merge-sorted-array/description/?envType=problem-list-v2&envId=sorting

Approach:
1. nums1 has enough extra space to store all elements.
2. Start comparing elements from the end of both arrays.
3. Place the larger element at the last available position.
4. Move the corresponding pointer backward.
5. If elements remain in nums2, copy them into nums1.
6. No need to copy remaining elements from nums1 because
   they are already in the correct position.

Key Idea:
- Merge the arrays from right to left.
- This prevents overwriting the valid elements of nums1.
- Using three pointers avoids the need for an extra array.

Pointers:
- i = last valid element of nums1 (m - 1)
- j = last element of nums2 (n - 1)
- k = last position of nums1 (m + n - 1)

Time Complexity:
- O(m + n)

Space Complexity:
- O(1)
------------------------------------------------------------
*/

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

        int i = m - 1;          // Last valid element in nums1
        int j = n - 1;          // Last element in nums2
        int k = m + n - 1;      // Last position in nums1

        // Merge from the end
        while (i >= 0 && j >= 0) {

            // Place the larger element at the end
            if (nums1[i] > nums2[j]) {
                nums1[k--] = nums1[i--];
            } else {
                nums1[k--] = nums2[j--];
            }
        }

        // Copy remaining elements of nums2 (if any)
        while (j >= 0) {
            nums1[k--] = nums2[j--];
        }
    }
};
