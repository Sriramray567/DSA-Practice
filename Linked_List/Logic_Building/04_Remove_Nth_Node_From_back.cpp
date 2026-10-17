```cpp
// Problem: Remove Nth Node From End of Linked List
// Approach 1: Brute Force (Two Passes)
// Approach 2: Optimal (Fast and Slow Pointers)
//
// Brute Force:
// Time Complexity: O(N)
// Auxiliary Space: O(1)
//
// Optimal:
// Time Complexity: O(N)
// Auxiliary Space: O(1)

class Solution {
public:

    // --------------------------------------------------
    // Approach 1: Brute Force
    // Count the total nodes, then remove the Nth node
    // from the beginning using position = length - n + 1.
    // --------------------------------------------------

    /*
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int length = 0;
        ListNode* temp = head;

        // First pass: Count the total number of nodes
        while (temp != nullptr) {
            length++;
            temp = temp->next;
        }

        // If the head itself needs to be removed
        if (length == n) {
            ListNode* newHead = head->next;
            delete head;
            return newHead;
        }

        // Find the node just before the target node
        int position = length - n;
        temp = head;

        for (int i = 1; i < position; i++) {
            temp = temp->next;
        }

        // Remove the target node
        ListNode* nodeToDelete = temp->next;
        temp->next = nodeToDelete->next;
        delete nodeToDelete;

        return head;
    }
    */

    // --------------------------------------------------
    // Approach 2: Optimal (Fast and Slow Pointers)
    // Use a dummy node to handle head deletion easily.
    // --------------------------------------------------

    class Solution {
      public:
      ListNode* removeNthFromEnd(ListNode* head, int n) {
          ListNode* fast = head;
          ListNode* slow = head;
  
          for(int i=0; i<n; i++){
              fast = fast->next;
          }
          if(fast == nullptr){
              ListNode* newHead = head->next;
              delete head;
              return newHead;
          }
          while(fast->next != nullptr){
              slow = slow->next;
              fast = fast->next;
          }
  
          ListNode* delNode = slow->next;
          slow->next = slow->next->next;
          delete delNode;
          return head;
      }
};
```
