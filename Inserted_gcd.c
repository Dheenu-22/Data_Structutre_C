#include <stdlib.h>
int gcd(int a, int b) {
    while (b != 0) {
        int t = a % b;
        a = b;
        b = t;
    }
    return a;
}
struct ListNode* insertGreatestCommonDivisors(struct ListNode* head) {
    if (head == NULL || head->next == NULL)
        return head;
    struct ListNode* curr = head;
    while (curr->next != NULL) {
        int g = gcd(curr->val, curr->next->val);
        struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
        node->val = g;
        node->next = curr->next;
        curr->next = node;
        curr = node->next; 
    }
    return head;
}
