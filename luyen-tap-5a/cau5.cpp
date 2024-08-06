void printLast(Node* head, int k) {
    Node* fast = head;
    Node* slow = head;
    
    for (int i = 0; i < k; ++i) {
        fast = fast->next;
    }
    
    while (fast != NULL) {
        fast = fast->next;
        slow = slow->next;
    }
    
    while (slow != NULL) {
        cout << slow->value << ' ';
        slow = slow->next;
    }
}