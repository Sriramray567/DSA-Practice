/**
 * Definition of doubly linked list:
 *
 * struct Node {
 *      int value;
 *      Node *prev;
 *      Node *next;
 *      Node() : value(0), prev(nullptr), next(nullptr) {}
 *      Node(int val) : value(val), prev(nullptr), next(nullptr) {}
 *      Node(int val, Node *p, Node *n) : value(val), prev(p), next(n) {}
 * };
 */

// Insert a new node before the tail of the DLL
Node* insertBeforeTail(Node* head, int k) {

    // Case 1: Empty list
    if (head == nullptr)
        return new Node(k);

    // Case 2: Only one node
    // New node becomes the new head
    if (head->next == nullptr) {
        Node* newNode = new Node(k);

        newNode->next = head;
        head->prev = newNode;

        return newNode;
    }

    // Find the tail node
    Node* tail = head;
    while (tail->next != nullptr) {
        tail = tail->next;
    }

    // Create the new node
    Node* newNode = new Node(k);

    // Connect new node before the tail
    newNode->prev = tail->prev;
    newNode->next = tail;

    // Update surrounding nodes
    tail->prev->next = newNode;
    tail->prev = newNode;

    return head;
}
