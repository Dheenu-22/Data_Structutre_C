struct ListNode* rotateRight(struct ListNode* head, int k) {
    if (!head || !head->next || k == 0) return head;
    struct ListNode* curr = head;
    int len = 1;
    while (curr->next) {
        curr = curr->next;
        len++;
    }
    k = k % len;
    if (k == 0) return head;
    curr->next = head; 
    int steps = len - k;
    while (steps--) {
        curr = curr->next;
    }
    head = curr->next;
    curr->next = NULL;
    return head;
}
