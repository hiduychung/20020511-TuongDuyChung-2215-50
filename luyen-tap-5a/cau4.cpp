Node* deleteNode(Node* head, int pos) {
    if (head == NULL || pos < 0)
        return head;
    
    if (pos == 0) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }
    
    Node* cur = head;
    for (int i = 0; cur != NULL && i < pos - 1; i++) {
        cur = cur->next;
    }
    
    if (cur == NULL || cur->next == NULL)
        return head;
        
    Node* next = cur->next->next;
    delete cur->next;
    cur->next = next;
    
    return head;
}