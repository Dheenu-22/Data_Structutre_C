struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode* prev = NULL;
    struct ListNode* curr = head;
    while (curr != NULL) {
        struct ListNode* nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }
    return prev;
}
struct ListNode* removeNodes(struct ListNode* head) {
    head = reverseList(head);
    int maxVal = head->val;
    struct ListNode* curr = head;
    while (curr->next != NULL) {
        if (curr->next->val < maxVal) {
            curr->next = curr->next->next;
        } else {
            curr = curr->next;
            maxVal = curr->val;
        }
    }
    head = reverseList(head);
    return head;
}
