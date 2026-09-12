/*
class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int data1, Node* next1, Node* prev1) {
        data = data1;
        next = next1;
        prev = prev1;
    }

    Node(int data1) {
        data = data1;
        next = nullptr;
        prev = nullptr;
    }
};
*/

Node* insertFront(Node* head, int data) {
    
    // Create a new node
    Node* newNode = new Node(data);

    // Connect new node to the current head
    newNode->next = head;

    // Update the previous pointer of the old head
    if (head != NULL) {
        head->prev = newNode;
    }

    // New node becomes the head
    return newNode;
}
