struct ListNode* reverseEvenLengthGroups(struct ListNode* head) {
    struct ListNode dummy;
    dummy.next = head;

    struct ListNode *prev = &dummy;
    struct ListNode *curr = head;

    int group = 1;

    while (curr) {
        struct ListNode *start = curr;
        int count = 0;

        while (curr && count < group) {
            curr = curr->next;
            count++;
        }

        if (count % 2 == 0) {
            struct ListNode *p = start;
            struct ListNode *q = curr;
            struct ListNode *r;

            for (int i = 0; i < count; i++) {
                r = p->next;
                p->next = q;
                q = p;
                p = r;
            }

            prev->next = q;
            prev = start;
        } else {
            for (int i = 0; i < count; i++)
                prev = prev->next;
        }

        group++;
    }

    return dummy.next;
}
