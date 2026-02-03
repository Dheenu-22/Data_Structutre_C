struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode* prev = NULL;
    struct ListNode* curr = head;
    while (curr != NULL) {
        struct ListNode* nextTemp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextTemp;
    }
    return prev;
}
bool isPalindrome(struct ListNode* head) {
    if (!head || !head->next) return true;
    struct ListNode* slow = head;
    struct ListNode* fast = head;
    while (fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    struct ListNode* secondHalf = reverseList(slow->next);
    struct ListNode* firstHalf = head;
    struct ListNode* tempSecond = secondHalf;
    bool palindrome = true;
    while (tempSecond) {
        if (firstHalf->val != tempSecond->val) {
            palindrome = false;
            break;
        }
        firstHalf = firstHalf->next;
        tempSecond = tempSecond->next;
    }
    slow->next = reverseList(secondHalf); // restore
    return palindrome;
}
