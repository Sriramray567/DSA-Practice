/*
# LeetCode 160: Intersection of Two Linked Lists

## Problem
Given the heads of two singly linked lists, find the node at which the two lists intersect.

**Important:** Intersection means both linked lists point to the exact same node in memory, not just nodes having the same value.

---

## Approach 1: Brute Force

### Logic
1. Traverse the first linked list using `tempA`.
2. For every node of List A, traverse the entire second linked list using `tempB`.
3. Compare node addresses (`tempA == tempB`).
4. If both pointers point to the same node, return that node.
5. If no common node is found, return `nullptr`.

### C++ Code

```cpp
  */
ListNode* getIntersectionNodeBrute(ListNode* headA, ListNode* headB) {

    ListNode* tempA = headA;

    while(tempA != nullptr) {

        ListNode* tempB = headB;

        while(tempB != nullptr) {

            // Compare node addresses, not node values
            if(tempA == tempB) {
                return tempA;
            }

            tempB = tempB->next;
        }

        tempA = tempA->next;
    }

    return nullptr;
}
/*
```

### Complexity Analysis
- Time Complexity: O(N * M)
- Space Complexity: O(1)

---

## Approach 2: Hash Map (unordered_map)

### Logic
1. Create an unordered_map to store the addresses of nodes of List A.
2. Traverse List A and store every node address as a key.
3. Traverse List B.
4. Check whether the current node address exists in the map using `find()`.
5. If found, return the current node because it is the intersection node.
6. Otherwise, return `nullptr`.

### C++ Code

```cpp
  */
ListNode* getIntersectionNodeHash(ListNode* headA, ListNode* headB) {

    unordered_map<ListNode*, int> mp;

    ListNode* tempA = headA;

    // Step 1: Store addresses of all nodes of List A
    while(tempA != nullptr) {

        mp[tempA] = 1;

        tempA = tempA->next;
    }

    // Step 2: Search nodes of List B in the hash map
    ListNode* tempB = headB;

    while(tempB != nullptr) {

        // Check whether the current node address exists
        if(mp.find(tempB) != mp.end()) {
            return tempB;
        }

        tempB = tempB->next;
    }

    return nullptr;
  /*
}
```

### Complexity Analysis
- Time Complexity: O(N + M) average
- Space Complexity: O(N)

**Why O(N + M)?**

- First loop: N insertions, each O(1) average = O(N).
- Second loop: M searches, each O(1) average = O(M).
- Total = O(N + M).

---

## Approach 3: Optimal (Two Pointers)

### Logic
1. Initialize two pointers: `tempA = headA` and `tempB = headB`.
2. Move both pointers one step at a time.
3. When `tempA` reaches NULL, redirect it to `headB`.
4. When `tempB` reaches NULL, redirect it to `headA`.
5. Continue until both pointers become equal.
6. If intersection exists, both pointers meet at the intersection node.
7. If no intersection exists, both pointers meet at NULL.

### C++ Code

```cpp
  */
ListNode* getIntersectionNodeOptimal(ListNode* headA, ListNode* headB) {

    if(headA == nullptr || headB == nullptr) {
        return nullptr;
    }

    ListNode* tempA = headA;
    ListNode* tempB = headB;

    while(tempA != tempB) {

        // Move both pointers one step forward
        tempA = tempA->next;
        tempB = tempB->next;

        // If both pointers meet, return the common node
        if(tempA == tempB) {
            return tempA;
        }

        // If tempA reaches NULL, switch to List B
        if(tempA == nullptr) {
            tempA = headB;
        }

        // If tempB reaches NULL, switch to List A
        if(tempB == nullptr) {
            tempB = headA;
        }
    }

    return tempA;
}
/*
```

### Complexity Analysis
- Time Complexity: O(N + M)
- Space Complexity: O(1)

**Why does it work?**

Pointer A travels: List A + List B.

Pointer B travels: List B + List A.

Both pointers travel the same total distance. Therefore, they meet at the intersection node if one exists; otherwise, both meet at NULL.

---

## Comparison of All Three Approaches

| Approach | Time Complexity | Space Complexity |
|---|---|---|
| Brute Force | O(N * M) | O(1) |
| Hash Map | O(N + M) average | O(N) |
| Two Pointers | O(N + M) | O(1) |

## Key Learnings

1. Always compare node addresses (`tempA == tempB`), not node values.
2. `unordered_map<ListNode*, int>` stores node addresses as keys.
3. Hash Map reduces the time complexity compared to brute force.
4. Two Pointers is the optimal approach because it achieves O(N + M) time with O(1) extra space.

**Final Conclusion:** Two Pointers is the best approach for LeetCode 160 because it provides linear time complexity without using extra space.
  */
