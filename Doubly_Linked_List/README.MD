# 🔗 Doubly Linked List: Array Conversion & Delete Head
#🔗 GFG problem link: https://www.geeksforgeeks.org/problems/create-a-doubly-linked-list-from-a-given-array/1

> Implementation and understanding of two fundamental Doubly Linked List operations in C++.

---

## 📌 Topics Covered

This repository covers:

* Convert an **Array → Doubly Linked List**
* Delete the **Head Node** from a Doubly Linked List
* Handle important **edge cases**
* Analyze **Time & Space Complexity**

---

# 1️⃣ Convert Array to Doubly Linked List

## 📝 Problem Statement

Given an array of `n` elements, convert the array into a **Doubly Linked List (DLL)**.

A Doubly Linked List contains two pointers in every node:

* `next` → points to the next node
* `prev` → points to the previous node

### Example

**Input:**

```text
Array = [10, 20, 30, 40]
```

**Output:**

```text
NULL ← 10 ⇄ 20 ⇄ 30 ⇄ 40 → NULL
       ↑
      HEAD
```

---

## 💡 Approach

The idea is to traverse the array and create one linked-list node for each element.

* Create the first node and make it the `head`.
* Maintain a pointer to the previously created node.
* For every new node:

  * Connect its `prev` pointer to the previous node.
  * Connect the previous node's `next` pointer to the new node.
* Continue until all array elements are converted.
* Finally, return the `head`.

---

## 🔄 Algorithm

1. Check whether the array is empty.
2. If empty, return `NULL`.
3. Create a node using the first array element.
4. Make this node the `head`.
5. Maintain a pointer `prev` to the current last node.
6. Traverse the array from index `1` to `n-1`.
7. Create a new node for each element.
8. Set the new node's `prev` to `prev`.
9. Set `prev->next` to the new node.
10. Move `prev` to the newly created node.
11. Return `head`.

---

## ⚠️ Edge Cases

| Case              | Result                                          |
| ----------------- | ----------------------------------------------- |
| Empty array       | Return `NULL`                                   |
| One element       | DLL contains one node                           |
| Multiple elements | All nodes are connected using `prev` and `next` |

---

## ⏱️ Complexity

### Time Complexity

**O(n)**

Each element of the array is processed exactly once.

### Space Complexity

**O(n)**

We create `n` nodes for the Doubly Linked List.

---

# 2️⃣ Delete Head of Doubly Linked List
#🔗 GFG problem link: https://www.geeksforgeeks.org/problems/delete-head-of-doubly-linked-list/1

## 📝 Problem Statement

Given the `head` of a Doubly Linked List, delete the first node and return the **new head**.

### Example

**Before:**

```text
NULL ← 10 ⇄ 20 ⇄ 30 → NULL
       ↑
      HEAD
```

**After deleting Head:**

```text
NULL ← 20 ⇄ 30 → NULL
       ↑
      HEAD
```

---

## 💡 Approach

There are three important cases:

### Case 1: Empty List

If `head == NULL`, there is nothing to delete.

Return `NULL`.

### Case 2: Only One Node

If the list contains only one node:

* Delete the node.
* Return `NULL`.

### Case 3: Multiple Nodes

If there are multiple nodes:

* Store the current head.
* Move `head` to the next node.
* Set the new head's `prev` to `NULL`.
* Delete the old head.
* Return the new head.

---

## 🔄 Algorithm

1. Check if the list is empty.
2. If empty, return `NULL`.
3. Check if the list contains only one node.
4. If there is only one node:

   * Delete the node.
   * Return `NULL`.
5. Store the current head in `oldHead`.
6. Move `head` to `head->next`.
7. Set `head->prev = NULL`.
8. Delete `oldHead`.
9. Return the updated `head`.

---

## ⚠️ Edge Cases

| Case           | Action                        |
| -------------- | ----------------------------- |
| Empty DLL      | Return `NULL`                 |
| Single node    | Delete node and return `NULL` |
| Multiple nodes | Move head and update `prev`   |

---

## ⏱️ Complexity

### Time Complexity

**O(1)**

Only the first node is accessed. No traversal is required.

### Space Complexity

**O(1)**

No extra data structure is used.

---

# 📊 Complexity Summary

| Operation   | Time Complexity | Space Complexity |
| ----------- | --------------: | ---------------: |
| Array → DLL |            O(n) |             O(n) |
| Delete Head |            O(1) |             O(1) |

---

# 🧠 Key Learnings

* How to convert an array into a Doubly Linked List.
* How `prev` and `next` pointers work.
* How to handle empty and single-node lists.
* How to delete the head safely.
* Why deleting the head of a DLL takes **O(1)** time.
* Importance of updating pointers before deleting a node.

---

# 🎯 Interview Takeaway

> **Array → DLL:** Traverse the array and connect every newly created node using `prev` and `next`.

> **Delete Head:** Move `head` to `head->next`, set the new head's `prev` to `NULL`, delete the old head, and return the new head.
---

**Doubly Linked List (DLL)**

# 🔗 Delete Node in a Doubly Linked List

> A solution and explanation for deleting the **X-th node** from a Doubly Linked List.

## 🔗 Problem Link

**GeeksforGeeks:**
https://www.geeksforgeeks.org/problems/delete-node-in-doubly-linked-list/1

---

## 📝 Problem Statement

Given the head of a Doubly Linked List and an integer `x`, delete the **x-th node** from the linked list.

The list should remain a valid Doubly Linked List after deletion.

---

## 💡 Approach

To delete the `x-th` node:

1. Traverse the list until reaching the `x-th` node.
2. Handle the special case when the node to delete is the **head**.
3. Connect the previous node to the next node.
4. If the next node exists, connect its `prev` pointer to the previous node.
5. Delete the target node.
6. Return the updated head.

---

# 🔄 Algorithm

### Step 1: Find the Target Node

Start from `head` and move through the list until reaching the `x-th` node.

### Step 2: Delete the Head

If the target node is the first node:

* Move `head` to the next node.
* Set the new head's `prev` to `NULL`.
* Delete the old head.
* Return the new head.

### Step 3: Delete a Middle/Last Node

For a node having a previous node:

* Set `previous->next = current->next`.
* If `current->next` exists, set `current->next->prev = current->prev`.
* Delete the current node.

### Step 4: Return Head

Return the updated head of the Doubly Linked List.

---

# 📌 Example

### Original DLL

```text
NULL ← 10 ⇄ 20 ⇄ 30 ⇄ 40 ⇄ 50 → NULL
```

Suppose:

```text
x = 3
```

We need to delete `30`.

### After Deletion

```text
NULL ← 10 ⇄ 20 ⇄ 40 ⇄ 50 → NULL
```

The links around `30` are updated:

```text
20.next = 40
40.prev = 20
```

---

# ⚠️ Edge Cases

### 1. Empty List

```text
head = NULL
```

Nothing can be deleted.

**Result:** `NULL`

---

### 2. Delete Head

If `x = 1`:

```text
NULL ← 10 ⇄ 20 ⇄ 30 → NULL
```

After deletion:

```text
NULL ← 20 ⇄ 30 → NULL
```

The new head's `prev` must be `NULL`.

---

### 3. Delete Middle Node

```text
10 ⇄ 20 ⇄ 30 ⇄ 40
```

Delete `30`:

```text
10 ⇄ 20 ⇄ 40
```

Both connections around the deleted node must be updated.

---

### 4. Delete Last Node

```text
10 ⇄ 20 ⇄ 30
```

Delete `30`:

```text
10 ⇄ 20
```

The new last node's `next` must be `NULL`.

---

### 5. Single Node

```text
NULL ← 10 → NULL
```

If this node is deleted:

```text
NULL
```

---

### 6. Invalid Position

If `x` is greater than the number of nodes, there is no valid target node.

The list should remain unchanged.

---

# 🧠 Key Pointer Logic

For a node in the middle:

```text
A ⇄ B ⇄ C
```

If `B` is deleted:

```text
A ⇄ C
```

We need to update **both directions**:

```text
A.next = C
C.prev = A
```

This is the most important concept in DLL deletion.

---

# ⏱️ Complexity Analysis

### Time Complexity

**O(n)**

We may need to traverse up to the `x-th` node.

### Space Complexity

**O(1)**

No extra data structure is used.

---

# 📊 Complexity Summary

| Operation      | Complexity |
| -------------- | ---------: |
| Find X-th Node |       O(n) |
| Delete Node    |       O(1) |
| Overall Time   |   **O(n)** |
| Extra Space    |   **O(1)** |

---

# ⭐ Important Interview Points

* In a DLL, every node has both `prev` and `next`.
* While deleting a node, both neighbouring links must be updated.
* Deleting the head requires updating the new head's `prev`.
* Deleting the last node requires making the new last node's `next` `NULL`.
* If the target node is already known, deletion itself takes **O(1)**.
* Finding the `x-th` node takes **O(n)**.

---

# 🎯 Core Learning

The main idea of deletion in a Doubly Linked List is:

```text
Find Target
     ↓
Check Head Case
     ↓
Connect Previous ↔ Next
     ↓
Delete Target
     ↓
Return Head
```

> **Always remember:** When deleting a node from a DLL, carefully update both `prev` and `next` pointers.

