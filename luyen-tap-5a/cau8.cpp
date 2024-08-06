#include <bits/stdc++.h>

Node* deleteDuplicates(Node* head) {
    if (!head) return head;

    std::unordered_set<int> seenValues;
    Node* current = head;
    Node* prev = nullptr;

    while (current) {
        if (seenValues.find(current->value) != seenValues.end()) {
            prev->next = current->next;
            delete current;
            current = prev->next;
        } else {
            seenValues.insert(current->value);
            prev = current;
            current = current->next;
        }
    }

    return head;
}