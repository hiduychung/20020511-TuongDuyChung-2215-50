void print(Node* head) {
    while (head != NULL) {
        cout << head->value << ' ';
        head = head->next;
    }
}