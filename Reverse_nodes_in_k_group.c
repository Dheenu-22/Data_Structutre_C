struct ListNode* reverseKGroup(struct ListNode* head, int k) {
    struct ListNode dummy;
    dummy.next = head;
    struct ListNode *prev = &dummy, *curr, *next;
    while (1) {
        struct ListNode* check = prev;
        for (int i = 0; i < k && check; i++) {
            check = check->next;
        }
        if (!check) break;
        curr = prev->next;
        next = curr->next;
        for (int i = 1; i < k; i++) {
            curr->next = next->next;
            next->next = prev->next;
            prev->next = next;
            next = curr->next;
        }
        prev = curr;
    }
    return dummy.next;
}
