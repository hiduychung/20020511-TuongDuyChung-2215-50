Node* insertHead(Node* head, int value) {
    Node* newNode = new Node();
    newNode->value = value;
    newNode->next = head;
    return newNode;
}