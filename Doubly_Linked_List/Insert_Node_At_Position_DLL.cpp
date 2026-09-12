/* Structure of Doubly Linked List Node
class Node {
  public:
    int data;
    Node* next;
    Node* prev;

    Node(int x) {
        data = x;
        next = prev = nullptr;
    }
};
*/

class Solution {
  public:
    Node* insertAtPos(Node* head, int p, int x) {
        
        // Move to the p-th node
        Node* temp = head;
        for (int i = 0; i < p; i++) {
            temp = temp->next;
        }

        // Create the new node
        Node* newNode = new Node(x);

        // Connect new node with next and previous nodes
        newNode->next = temp->next;
        newNode->prev = temp;

        // Update the next node's previous pointer
        if (temp->next != NULL) {
            temp->next->prev = newNode;
        }

        // Update current node's next pointer
        temp->next = newNode;

        return head;
    }
};
