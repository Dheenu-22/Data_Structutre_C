struct ListNode* swapNodes(struct ListNode* head, int k) {
    struct ListNode *first = head, *second = head, *temp = head;
    for (int i = 1; i < k; i++) {
        first = first->next;
    }
    temp = first;
    while (temp->next) {
        temp = temp->next;
        second = second->next;
    }
    int t = first->val;
    first->val = second->val;
    second->val = t;
    return head;
}
