void printReverse(Node* head, int k) {
    if (k == 0) 
        return;
    printReverse(head->next, k - 1);
    cout << head->value << ' ';
}