struct ListNode* reverse(struct ListNode* head) {
    struct ListNode* prev = NULL;
    struct ListNode* curr = head;
    while (curr) {
        struct ListNode* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}
struct ListNode* doubleIt(struct ListNode* head) {
    head = reverse(head);
    struct ListNode* curr = head;
    int carry = 0;
    while (curr) {
        int val = curr->val * 2 + carry;
        curr->val = val % 10;
        carry = val / 10;
        if (!curr->next && carry) {
            curr->next = (struct ListNode*)malloc(sizeof(struct ListNode));
            curr->next->val = carry;
            curr->next->next = NULL;
            carry = 0;
            break;
        }
        curr = curr->next;
    }
    return reverse(head);
}
