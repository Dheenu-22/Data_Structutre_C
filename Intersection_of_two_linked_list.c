struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    if (headA == NULL || headB == NULL)
        return NULL;
    struct ListNode *pA = headA;
    struct ListNode *pB = headB;
    while (pA != pB) {
        if (pA == NULL)
            pA = headB;
        else
            pA = pA->next;

        if (pB == NULL)
            pB = headA;
        else
            pB = pB->next;
    }
    return pA; 
}
