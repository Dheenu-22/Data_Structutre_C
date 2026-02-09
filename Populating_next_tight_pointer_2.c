struct Node* connect(struct Node* root) {
    if (root == NULL)
        return NULL;
    struct Node* curr = root;
    while (curr != NULL) {
        struct Node* head = NULL;
        struct Node* tail = NULL;
        while (curr != NULL) {
            if (curr->left != NULL) {
                if (head == NULL) {
                    head = curr->left;
                    tail = curr->left;
                } else {
                    tail->next = curr->left;
                    tail = tail->next;
                }
            }
            if (curr->right != NULL) {
                if (head == NULL) {
                    head = curr->right;
                    tail = curr->right;
                } else {
                    tail->next = curr->right;
                    tail = tail->next;
                }
            }
            curr = curr->next;
        }
        curr = head;
    }
    return root;
}
