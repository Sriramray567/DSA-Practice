/* Structure of doubly linked list Node
class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int x) {
        data = x;
        next = nullptr;
        prev = nullptr;
    }
};*/
class Solution {
  public:
    Node* deleteHead(Node* head) {
        if(head == NULL) return NULL;
        if(head->next == NULL){
            delete head;
            return NULL;
        }
        
        Node* OldNode = head;
        head = head->next;
        head->prev=NULL;
        delete OldNode;
        return head;
    }
};
