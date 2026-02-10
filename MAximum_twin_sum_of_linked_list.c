int pairSum(struct ListNode* head) {
    struct ListNode *slow = head, *fast = head;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    struct ListNode *prev = NULL, *cur = slow, *next;

    while (cur) {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }

    int max = 0;
    struct ListNode *p1 = head, *p2 = prev;

    while (p2) {
        int sum = p1->val + p2->val;
        if (sum > max) max = sum;
        p1 = p1->next;
        p2 = p2->next;
    }

    return max;
}
