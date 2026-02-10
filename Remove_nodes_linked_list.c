struct ListNode* reverse(struct ListNode* head) {
    struct ListNode *prev = NULL, *cur = head, *next;
    while (cur) {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    return prev;
}
struct ListNode* removeNodes(struct ListNode* head) {
    head = reverse(head);
    int max = head->val;
    struct ListNode *cur = head;

    while (cur && cur->next) {
        if (cur->next->val < max) {
            cur->next = cur->next->next;
        } else {
            cur = cur->next;
            max = cur->val;
        }
    }
    return reverse(head);
}
