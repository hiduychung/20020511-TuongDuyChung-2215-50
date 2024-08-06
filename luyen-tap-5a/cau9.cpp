Node* insert(Node* head, int value) {
    Node* newNode = new Node{value, nullptr};

    if (!head || (head->value >= value && (!head->next || head->value <= head->next->value)) ||
        (head->value <= value && head->next && head->value >= head->next->value)) {
        newNode->next = head;
        return newNode;
    }

    Node* current = head;

    if (head->value <= value) {
        while (current->next && current->next->value <= value) {
            current = current->next;
        }
    } else {
        while (current->next && current->next->value >= value) {
            current = current->next;
        }
    }

    newNode->next = current->next;
    current->next = newNode;

    return head;
}