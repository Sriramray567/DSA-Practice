# Binary Search (Easy)

# 1. Search X in Sorted Array

## Problem Statement

Given a sorted array and a target element `X`, find the index of `X`. If the element is not present, return `-1`.

---

## Intuition

Since the array is sorted, comparing the middle element with the target allows us to discard half of the search space every time. This makes Binary Search much faster than Linear Search.

---

## Brute Force Approach

### Algorithm

1. Traverse the array from left to right.
2. Compare every element with `X`.
3. If found, return its index.
4. Otherwise, return `-1`.

### Time Complexity

`O(n)`

### Space Complexity

`O(1)`

---

## Optimal Approach (Binary Search)

### Algorithm

1. Initialize `low = 0` and `high = n-1`.
2. Calculate `mid`.
3. If `arr[mid] == X`, return `mid`.
4. If `arr[mid] < X`, search the right half.
5. Otherwise, search the left half.
6. Repeat until `low > high`.

### Why Binary Search Works?

Because the array is already sorted.

If

```
arr[mid] < X
```

then every element before `mid` is also smaller than `X`.

So we safely discard the left half.

Similarly,

```
arr[mid] > X
```

means the target can only exist on the left side.

---

### Time Complexity

`O(log n)`

### Space Complexity

`O(1)`

---

### Key Observation

A sorted array allows us to eliminate half of the search space after every comparison.

---

# 2. Lower Bound

## Problem Statement

Find the first index where

```
arr[index] >= X
```

If no such index exists, return `n`.

---

## Intuition

Lower Bound is not necessarily the position of `X`.

It returns the first position where `X` can be placed without disturbing the sorted order.

Example

```
arr = [1,2,4,4,6,8]
X = 5

Lower Bound = index 4
```

because

```
arr[4] = 6 >= 5
```

---

## Brute Force Approach

### Algorithm

1. Traverse the array.
2. Return the first index where

```
arr[i] >= X
```

3. If not found, return `n`.

### Time Complexity

`O(n)`

### Space Complexity

`O(1)`

---

## Optimal Approach (Binary Search)

### Algorithm

1. Initialize

```
ans = n
```

2. Find the middle element.

3. If

```
arr[mid] >= X
```

then

* store the answer
* continue searching on the left side

because there might be another valid index.

4. Otherwise search on the right side.

---

### Why Search Left?

Suppose

```
arr = [1,3,5,5,5,8]
X = 5
```

If Binary Search finds

```
index = 4
```

it may not be the first occurrence.

So after finding a valid answer, we move left.

---

### Time Complexity

`O(log n)`

### Space Complexity

`O(1)`

---

### Key Observation

Whenever

```
arr[mid] >= X
```

`mid` is a possible answer, but there may be another valid answer on the left.

---

# 3. Upper Bound

## Problem Statement

Find the first index where

```
arr[index] > X
```

If no such index exists, return `n`.

---

## Intuition

Upper Bound returns the first element strictly greater than `X`.

It is commonly used to find:

* insertion position
* last occurrence
* frequency of an element

---

## Brute Force Approach

### Algorithm

1. Traverse the array.
2. Return the first index satisfying

```
arr[i] > X
```

3. If no such element exists, return `n`.

### Time Complexity

`O(n)`

### Space Complexity

`O(1)`

---

## Optimal Approach (Binary Search)

### Algorithm

1. Initialize

```
ans = n
```

2. Calculate `mid`.

3. If

```
arr[mid] > X
```

then

* store `mid`
* continue searching on the left

4. Otherwise

search on the right.

---

### Why Search Left?

Example

```
arr = [1,2,4,4,4,7]
X = 4
```

Suppose Binary Search finds

```
index = 5
```

It could still be the first element greater than `4`, but we always move left after finding a valid answer to ensure it's the earliest such index.

---

### Time Complexity

`O(log n)`

### Space Complexity

`O(1)`

---

### Difference Between Lower Bound and Upper Bound

| Lower Bound                | Upper Bound                        |
| -------------------------- | ---------------------------------- |
| First element **>= X**     | First element **> X**              |
| Returns insertion position | Returns next greater element       |
| Used for first occurrence  | Used for last occurrence/frequency |

---

## Binary Search Template

```cpp
while(low <= high){

    int mid = low + (high-low)/2;

    if(condition){
        // answer found
    }
    else if(...){
        low = mid + 1;
    }
    else{
        high = mid - 1;
    }
}

# 4. Search Insert Position

## Problem Statement

Given a sorted array and a target value `X`, return the index if the target is found. Otherwise, return the index where it should be inserted to maintain the sorted order.

---

## Intuition

The insertion position of an element is exactly the **Lower Bound** of that element.

Therefore, this problem is simply an application of the Lower Bound algorithm.

Example:

```text
arr = [1,3,5,6]
X = 4

Answer = 2
```

Because inserting `4` at index `2` keeps the array sorted.

---

## Brute Force Approach

### Algorithm

1. Traverse the array from left to right.
2. Find the first element greater than or equal to `X`.
3. Return its index.
4. If every element is smaller than `X`, return `n`.

### Time Complexity

`O(n)`

### Space Complexity

`O(1)`

---

## Optimal Approach (Binary Search)

### Algorithm

1. Initialize `ans = n`.
2. Find the middle element.
3. If `arr[mid] >= X`

   * Store `mid` as a possible answer.
   * Continue searching on the left.
4. Otherwise search on the right.
5. Return `ans`.

---

### Key Observation

**Search Insert Position = Lower Bound**

No new algorithm is required.

---

### Time Complexity

`O(log n)`

### Space Complexity

`O(1)`

---

# 5. Floor and Ceil in Sorted Array

## Problem Statement

Find:

* **Floor** → Largest element **≤ X**
* **Ceil** → Smallest element **≥ X**

---

## Intuition

Both Floor and Ceil can be found independently using Binary Search.

Instead of finding the exact element, we keep updating the best possible answer.

---

## Brute Force Approach

### Algorithm

Traverse the array once.

For every element

* update Floor if element ≤ X
* update Ceil if element ≥ X

---

### Time Complexity

`O(n)`

### Space Complexity

`O(1)`

---

## Optimal Approach

### Floor

Whenever

```text
arr[mid] <= X
```

`mid` can be the Floor.

Store it and move right to search for a larger valid value.

---

### Ceil

Whenever

```text
arr[mid] >= X
```

`mid` can be the Ceil.

Store it and move left to search for a smaller valid value.

---

### Key Observation

Floor always searches towards the **right** after finding a valid answer.

Ceil always searches towards the **left** after finding a valid answer.

---

### Time Complexity

`O(log n)`

### Space Complexity

`O(1)`

---

# 6. First and Last Occurrence

## Problem Statement

Find the first and last occurrence of a target element in a sorted array.

Example

```text
arr = [2,4,4,4,7]

Target = 4

Output = [1,3]
```

---

## Intuition

Instead of searching linearly,

perform Binary Search twice.

* First Binary Search → First Occurrence
* Second Binary Search → Last Occurrence

---

## Brute Force Approach

### Algorithm

1. Traverse the array.
2. Store the first occurrence.
3. Keep updating the last occurrence.
4. Return both indices.

---

### Time Complexity

`O(n)`

### Space Complexity

`O(1)`

---

## Optimal Approach

### First Occurrence

Whenever

```text
arr[mid] == X
```

Store the answer and continue searching on the left.

---

### Last Occurrence

Whenever

```text
arr[mid] == X
```

Store the answer and continue searching on the right.

---

### Key Observation

First occurrence is exactly the **Lower Bound** of `X`.

Last occurrence is obtained by modifying Binary Search to continue searching on the right after finding the target.

---

### Time Complexity

`O(log n)`

### Space Complexity

`O(1)`

---

# 7. Count Occurrences in a Sorted Array

## Problem Statement

Find how many times a target element appears in a sorted array.

---

## Intuition

If we know

* First Occurrence
* Last Occurrence

then frequency becomes

```text
Last - First + 1
```

---

## Brute Force Approach

### Algorithm

Traverse the array and count every occurrence of `X`.

---

### Time Complexity

`O(n)`

### Space Complexity

`O(1)`

---

## Optimal Approach

1. Find the first occurrence.
2. Find the last occurrence.
3. If the element doesn't exist, return `0`.
4. Otherwise,

```text
Count = Last - First + 1
```

---

### Why does this work?

All equal elements appear continuously in a sorted array.

Knowing the starting and ending index directly gives the frequency.

---

### Time Complexity

Finding First Occurrence → `O(log n)`

Finding Last Occurrence → `O(log n)`

Overall

`O(log n)`

---

### Space Complexity

`O(1)`

---

## Important Relation

```text
Search Insert Position = Lower Bound

First Occurrence = Lower Bound

Last Occurrence = Modified Binary Search

Count = Last Occurrence - First Occurrence + 1
```

# 8. Search in Rotated Sorted Array - I

## Problem Statement

Given a rotated sorted array with **distinct elements**, search for a target element. Return its index if found, otherwise return `-1`.

Example:

```text
arr = [4,5,6,7,0,1,2]
target = 0

Output = 4
```

---

## Intuition

Even after rotation, **one half of the array is always sorted**.

We first identify the sorted half and then check whether the target lies inside that half.

If yes, search there; otherwise search in the other half.

---

## Brute Force Approach

### Algorithm

1. Traverse the entire array.
2. Compare every element with the target.
3. Return its index if found.
4. Otherwise return `-1`.

### Time Complexity

`O(n)`

### Space Complexity

`O(1)`

---

## Optimal Approach (Binary Search)

### Algorithm

1. Find the middle element.
2. Check which half is sorted.
3. If the target belongs to the sorted half, search there.
4. Otherwise search in the unsorted half.
5. Repeat until the target is found.

---

### Key Observation

At least **one half is always sorted**.

This observation allows Binary Search to eliminate half of the search space.

---

### Time Complexity

`O(log n)`

### Space Complexity

`O(1)`

---

# 9. Search in Rotated Sorted Array - II

## Problem Statement

Given a rotated sorted array that **may contain duplicate elements**, determine whether the target exists.

Return **true** or **false**.

---

## Intuition

Duplicates create ambiguity.

Sometimes we cannot determine which half is sorted because

```text
arr[low] == arr[mid] == arr[high]
```

In that case, simply shrink both ends.

---

## Brute Force Approach

### Algorithm

Traverse the array and compare every element with the target.

### Time Complexity

`O(n)`

### Space Complexity

`O(1)`

---

## Optimal Approach

### Algorithm

1. Handle duplicate case first.
2. If

```text
arr[low] == arr[mid] == arr[high]
```

then

```text
low++
high--
```

3. Otherwise identify the sorted half.
4. Search accordingly.

---

### Why Worst Case becomes O(n)?

Example

```text
[1,1,1,1,1,1,1]
```

Every iteration removes only one element from both sides.

Binary Search advantage disappears.

---

### Time Complexity

Average → `O(log n)`

Worst Case → `O(n)`

### Space Complexity

`O(1)`

---

# 10. Find Minimum in Rotated Sorted Array

## Problem Statement

Find the minimum element in a rotated sorted array.

Example

```text
[4,5,6,7,0,1,2]

Answer = 0
```

---

## Intuition

The minimum element always lies at the rotation point.

Again, one half is always sorted.

---

## Brute Force Approach

### Algorithm

Traverse the array and keep updating the minimum element.

### Time Complexity

`O(n)`

### Space Complexity

`O(1)`

---

## Optimal Approach

### Algorithm

1. If the current search space is already sorted,

return

```text
arr[low]
```

2. Otherwise identify the sorted half.

3. Store the smallest value from the sorted half.

4. Continue searching in the unsorted half.

---

### Key Observation

The minimum element is either

* the first element of the sorted half
* or inside the unsorted half.

---

### Time Complexity

`O(log n)`

### Space Complexity

`O(1)`

---

# 11. Find Out How Many Times the Array is Rotated

## Problem Statement

Return the number of rotations performed on a sorted array.

---

## Intuition

The number of rotations equals the **index of the minimum element**.

Example

```text
[4,5,6,7,0,1,2]

Minimum = 0

Index = 4

Rotations = 4
```

---

## Brute Force Approach

### Algorithm

Find the minimum element and return its index.

### Time Complexity

`O(n)`

### Space Complexity

`O(1)`

---

## Optimal Approach

Use the same Binary Search logic as **Find Minimum in Rotated Sorted Array**.

Instead of storing only the minimum value,

also store its index.

Return the index.

---

### Key Observation

```text
Rotation Count = Index of Minimum Element
```

---

### Time Complexity

`O(log n)`

### Space Complexity

`O(1)`

---

# Summary of Rotated Array Problems

| Problem                 | Key Observation                    |
| ----------------------- | ---------------------------------- |
| Search Rotated Array-I  | One half is always sorted          |
| Search Rotated Array-II | Handle duplicates first            |
| Find Minimum            | Minimum lies at the rotation point |
| Find K Rotations        | Rotation count = Index of minimum  |

These four problems are based on the **same Binary Search observation**. Once you understand how to identify the sorted half, all of them become much easier.


# 12. Single Element in a Sorted Array

## Problem Statement

Given a sorted array where every element appears exactly twice except one element, find that single element.

Example

```text
arr = [1,1,2,3,3,4,4,8,8]

Answer = 2
```

---

## Intuition

Before the single element, every pair starts at an **even index**.

After the single element, this pairing pattern gets disturbed.

We use this property to perform Binary Search.

---

## Brute Force Approach

### Algorithm

1. Traverse the array two elements at a time.
2. Compare every pair.
3. If a pair is broken, return the first element.
4. If every pair is valid, the last element is the answer.

### Time Complexity

`O(n)`

### Space Complexity

`O(1)`

---

## Optimal Approach (Binary Search)

### Algorithm

1. Handle edge cases:

   * Array contains only one element.
   * Unique element is at the beginning.
   * Unique element is at the end.
2. Find the middle element.
3. If `nums[mid]` is different from both neighbors, return it.
4. Otherwise, check whether the pairing pattern is correct.
5. If the pattern is correct, move to the right.
6. Otherwise, move to the left.

---

### Why Does It Work?

Before the unique element:

```text
Index : 0 1 2 3 4 5
Array : 1 1 2 2 3 3

Even Odd Even Odd Even Odd
```

After the unique element:

```text
Index : 0 1 2 3 4 5 6

Array : 1 1 2 3 3 4 4

Even Odd Even Odd Even Odd Even
               ^
Pairing breaks here
```

The unique element shifts the pairing pattern.

Binary Search uses this change to eliminate half of the search space.

---

### Key Observation

* Before the single element → Pair starts at an **even** index.
* After the single element → Pair starts at an **odd** index.

---

### Time Complexity

`O(log n)`

### Space Complexity

`O(1)`

---

# 13. Find Peak Element

## Problem Statement

A peak element is an element that is strictly greater than its adjacent elements.

Return the index of **any** peak element.

Example

```text
arr = [1,2,3,1]

Answer = 2
```

because

```text
3 > 2
3 > 1
```

---

## Intuition

If the array is increasing, a peak must exist on the right.

If the array is decreasing, a peak must exist on the left.

Therefore, Binary Search can always discard one half.

---

## Brute Force Approach

### Algorithm

1. Traverse the array.
2. For every element, check whether it is greater than both neighbors.
3. Return the first peak index.

### Time Complexity

`O(n)`

### Space Complexity

`O(1)`

---

## Optimal Approach (Binary Search)

### Algorithm

1. Handle edge cases:

   * Only one element.
   * Peak at the first index.
   * Peak at the last index.
2. Find the middle element.
3. If it is greater than both neighbors, return it.
4. If the array is increasing at `mid`, move right.
5. Otherwise, move left.

---

### Why Does It Work?

Suppose

```text
1 3 5 7 9
```

The array is increasing.

Moving right eventually reaches a peak.

Similarly,

```text
9 7 5 3 1
```

The array is decreasing.

Moving left eventually reaches a peak.

Hence, one side can always be discarded.

---

### Key Observation

Always move towards the larger neighbor.

* If `nums[mid] < nums[mid + 1]`
  → Search the **right half**.

* Otherwise
  → Search the **left half**.

A peak is guaranteed to exist.

---

### Time Complexity

`O(log n)`

### Space Complexity

`O(1)`

---

# Binary Search Patterns Learned

After completing these problems, you have learned the following Binary Search patterns:

### 1. Classic Binary Search

* Search an element in a sorted array.

### 2. Lower Bound

* Find the first element **≥ X**.

### 3. Upper Bound

* Find the first element **> X**.

### 4. Search Insert Position

* Lower Bound application.

### 5. Floor & Ceil

* Store the best possible answer while searching.

### 6. First & Last Occurrence

* Binary Search twice.

### 7. Count Occurrences

* Use First and Last Occurrence.

### 8. Rotated Sorted Array

* One half is always sorted.

### 9. Find Minimum / K Rotations

* Minimum element represents the rotation point.

### 10. Single Element

* Use the even-odd pairing pattern.

### 11. Peak Element

* Follow the increasing/decreasing slope.

---

# Conclusion

These problems cover the core Binary Search patterns that are frequently asked in coding interviews. Once these concepts are clear, advanced topics like **Binary Search on Answers**, **Search in 2D Matrix**, **Median of Two Sorted Arrays**, and **Aggressive Cows** become much easier to understand.

```

