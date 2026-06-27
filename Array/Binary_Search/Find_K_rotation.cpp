/*
Brute Force Approach:

1. Traverse the entire array.
2. Find the minimum element.
3. Return its index.
4. The index of the minimum element is equal to the number of rotations.

Time Complexity: O(n)
Space Complexity: O(1)
*/

/*
Optimal Approach (Binary Search):

1. The minimum element's index is the number of rotations.
2. At every step, determine which half is sorted.
3. Store the smallest element (and its index) from the sorted half.
4. Continue searching in the unsorted half.
5. If the current search space is already sorted, update the answer and stop.

Why it works:
- In a rotated sorted array, one half is always sorted.
- The minimum element is either the first element of the sorted half
  or lies inside the unsorted half.
- Binary Search reduces the search space by half in every iteration.

Time Complexity: O(log n)
Space Complexity: O(1)
*/


// Problem: Find K Rotation (GFG)
// Link: https://www.geeksforgeeks.org/problems/rotation4723/1
//
// Approach: Binary Search
// 1. The index of the minimum element represents the number of rotations.
// 2. In every iteration, identify the sorted half.
// 3. Store the index of the smallest element seen so far.
// 4. Continue searching in the unsorted half.
// 5. If the current search space is already sorted, update the answer and stop.
//
// Time Complexity: O(log n)
// Space Complexity: O(1)

class Solution {
public:
    int findKRotation(vector<int> &arr) {

        int low = 0;
        int high = arr.size() - 1;

        // Stores the minimum element and its index
        int ans = INT_MAX;
        int index = -1;

        while (low <= high) {

            int mid = low + (high - low) / 2;

            // Current search space is already sorted
            if (arr[low] <= arr[high]) {
                if (arr[low] < ans) {
                    ans = arr[low];
                    index = low;
                }
                break;
            }

            // Left half is sorted
            if (arr[low] <= arr[mid]) {

                if (arr[low] < ans) {
                    ans = arr[low];
                    index = low;
                }

                low = mid + 1;
            }

            // Right half is sorted
            else {

                if (arr[mid] < ans) {
                    ans = arr[mid];
                    index = mid;
                }

                high = mid - 1;
            }
        }

        return index;
    }
};
