void reorderList(struct ListNode* head) {
    if (head == NULL || head->next == NULL)
        return;
    struct ListNode *slow = head, *fast = head;
    while (fast->next != NULL && fast->next->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    struct ListNode *prev = NULL;
    struct ListNode *curr = slow->next;
    while (curr != NULL) {
        struct ListNode *nextTemp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextTemp;
    }
    slow->next = NULL;
    struct ListNode *first = head;
    struct ListNode *second = prev;
    while (second != NULL) {
        struct ListNode *t1 = first->next;
        struct ListNode *t2 = second->next;
        first->next = second;
        second->next = t1;
        first = t1;
        second = t2;
    }
}
