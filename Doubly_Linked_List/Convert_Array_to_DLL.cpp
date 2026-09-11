/* class Node {
  public:
    int data;
    Node* next;
    Node* prev;
    Node(int d) {
        data = d;
        next = nullptr;
        prev = nullptr;
    }
}; */

class Solution {
  public:
    Node* createDLL(vector<int>& arr) {
        Node* head = new Node(arr[0]);
        Node* prev = head;
        for(int i=1; i<arr.size(); i++){
            Node* temp = new Node(arr[i]);
            prev->next=temp;
            temp->prev=prev;
            prev=temp;
        }
        return head;
    }
};
