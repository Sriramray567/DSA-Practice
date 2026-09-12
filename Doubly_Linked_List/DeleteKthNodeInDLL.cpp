/* Structure of Doubly Linked List Node
class Node {
  public:
    int data;
    Node *next;
    Node *prev;

    Node(int val) {
        data = val;
        this->next = NULL;
        this->prev = NULL;
    }
};
*/

class Solution {
  public:
    Node* delPos(Node* head, int x) {
        Node* temp = head;
        
        for(int i=1; i<x; i++){
            temp = temp->next;
        }
        
        //Delete head
        if(temp->prev == NULL){
            head = temp->next;
            if(head != NULL){
                head->prev=NULL;
            }
            delete temp;
            return head;
        }
        
        //Delete mid or Tail
        Node* prev = temp->prev;
        Node* front = temp->next;
        
        prev->next = front;
        if(front != NULL)
            front->prev=prev;
        
        delete temp;
        return head;
    }
};
