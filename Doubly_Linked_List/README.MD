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

## 🛠️ Language

**C++**

## 📚 Data Structure

**Doubly Linked List (DLL)**
