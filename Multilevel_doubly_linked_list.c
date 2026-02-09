class Solution {
public:
    Node* flatten(Node* head) {
        if (!head) return nullptr;
        flattenDFS(head);
        return head;
    }
private:
    Node* flattenDFS(Node* node) {
        Node* curr = node;
        Node* last = nullptr;
        while (curr) {
            Node* nextNode = curr->next;
            if (curr->child) {
                Node* childTail = flattenDFS(curr->child);
                curr->next = curr->child;
                curr->child->prev = curr;
                curr->child = nullptr;
                if (nextNode) {
                    childTail->next = nextNode;
                    nextNode->prev = childTail;
                }
                last = childTail;
            } else {
                last = curr;
            }
            curr = nextNode;
        }
        return last; 
    }
};
