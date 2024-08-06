Node* sort(Node* head) {
    if (!head) return NULL;

    Node* sorted = NULL;
    Node* current = head; 

    while (current) {
        Node* next = current->next;
        if (!sorted || sorted->getValue() >= current->getValue()) {
            current->next = sorted;
            if (sorted) {
                sorted->prev = current;
            }
            sorted = current;
            sorted->prev = nullptr;
        } else {
            Node* temp = sorted;
            while (temp->next && temp->next->getValue() < current->getValue()) {
                temp = temp->next;
            }
            current->next = temp->next;
            if (temp->next) {
                temp->next->prev = current;
            }
            temp->next = current;
            current->prev = temp;
        }
        current = next;
    }

    return sorted;
}