struct ListNode* partition(struct ListNode* head, int x) {
    struct ListNode smallDummy;
    struct ListNode bigDummy;
    struct ListNode* small = &smallDummy;
    struct ListNode* big = &bigDummy;
    smallDummy.next = NULL;
    bigDummy.next = NULL;
    while (head != NULL) {
        if (head->val < x) {
            small->next = head;
            small = small->next;
        } else {
            big->next = head;
            big = big->next;
        }
        head = head->next;
    }
    big->next = NULL;
    small->next = bigDummy.next;
    return smallDummy.next;
}
