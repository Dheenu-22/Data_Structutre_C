bool matchPath(struct ListNode* head, struct TreeNode* root) {
    if (!head) return true;
    if (!root) return false;
    if (head->val != root->val) return false;
    return matchPath(head->next, root->left) ||
           matchPath(head->next, root->right);
}
bool isSubPath(struct ListNode* head, struct TreeNode* root) {
    if (!root) return false;
    if (matchPath(head, root)) return true;
    return isSubPath(head, root->left) ||
           isSubPath(head, root->right);
}
