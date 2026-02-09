struct Node* copyRandomList(struct Node* head) {
    if (head == NULL)
        return NULL;
    struct Node* curr = head;
    while (curr != NULL) {
        struct Node* copy = (struct Node*)malloc(sizeof(struct Node));
        copy->val = curr->val;
        copy->random = NULL;
        copy->next = curr->next;
        curr->next = copy;
        curr = copy->next;
    }
    curr = head;
    while (curr != NULL) {
        if (curr->random != NULL) {
            curr->next->random = curr->random->next;
        }
        curr = curr->next->next;
    }
    curr = head;
    struct Node* copyHead = head->next;
    struct Node* copyCurr = copyHead;
    while (curr != NULL) {
        curr->next = curr->next->next;
        if (copyCurr->next != NULL)
            copyCurr->next = copyCurr->next->next;
        curr = curr->next;
        copyCurr = copyCurr->next;
    }
    return copyHead;
}
