struct ListNode* mergeNodes(struct ListNode* head) {
    struct ListNode* curr = head->next; 
    struct ListNode* newHead = NULL;
    struct ListNode* write = NULL;
    int sum = 0;
    while (curr != NULL) {
        if (curr->val != 0) {
            sum += curr->val;
        } else {
            if (newHead == NULL) {
                newHead = curr;
                write = curr;
            } else {
                write->next = curr;
                write = write->next;
            }
            write->val = sum;
            sum = 0;
        }
        curr = curr->next;
    }
    write->next = NULL;
    return newHead;
}
