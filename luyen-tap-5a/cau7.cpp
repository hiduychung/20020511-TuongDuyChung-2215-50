Node* deleteSingle(Node* head) {
    if (!head || !head->next) return head;

    if (head->value != head->next->value) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    Node* current = head;
    Node* prev = nullptr;

    while (current && current->next) {
        if (current->value != current->next->value && (!prev || prev->value != current->value)) {
            if (prev) {
                prev->next = current->next;
            }
            delete current;
            return head;
        }
        prev = current;
        current = current->next;
    }

    if (prev && current && prev->value != current->value) {
        prev->next = nullptr;
        delete current;
    }

    return head;
}