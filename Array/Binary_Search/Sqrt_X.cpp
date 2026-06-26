/*
------------------------------------------------------------
Problem : LeetCode 69 - Sqrt(x)
Problem Link:- https://leetcode.com/problems/sqrtx/description/

Approach:
1. The answer lies in the range [1, x].
2. Use Binary Search to find the integer square root.
3. If mid * mid == x, return mid.
4. If mid * mid < x, store mid as a possible answer
   and search in the right half.
5. Otherwise, search in the left half.
6. Return the last stored answer.

Key Idea:
- We are searching for the largest integer whose square
  is less than or equal to x.
- Instead of searching the array, Binary Search is applied
  on the answer space.
- To avoid integer overflow, compare using:
      mid <= x / mid
  instead of:
      mid * mid <= x

Time Complexity:
- O(log x)

Space Complexity:
- O(1)
------------------------------------------------------------
*/

class Solution {
public:
    int mySqrt(int x) {

        if (x <= 1)
            return x;

        int low = 1;
        int high = x;
        int ans = 0;

        while (low <= high) {

            // Find the middle value safely
            int mid = low + (high - low) / 2;

            // Check for the exact square root
            if (mid == x / mid && x % mid == 0)
                return mid;

            // mid^2 <= x (without overflow)
            if (mid <= x / mid) {
                ans = mid;
                low = mid + 1;
            }

            // mid^2 > x
            else {
                high = mid - 1;
            }
        }

        // Largest integer whose square is <= x
        return ans;
    }
};
