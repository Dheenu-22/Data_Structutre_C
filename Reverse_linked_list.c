struct ListNode* reverseBetween(struct ListNode* head, int left, int right) {
    if (head == NULL || left == right)
        return head;
    struct ListNode dummy;
    dummy.next = head;
    struct ListNode* prev = &dummy;
    for (int i = 1; i < left; i++) {
        prev = prev->next;
    }
    struct ListNode* curr = prev->next;
    struct ListNode* next = NULL;
    for (int i = 0; i < right - left; i++) {
        next = curr->next;
        curr->next = next->next;
        next->next = prev->next;
        prev->next = next;
    }
    return dummy.next;
}
