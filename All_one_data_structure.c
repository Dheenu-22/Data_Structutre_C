class AllOne {
private:
    struct Node {
        int cnt;
        unordered_set<string> keys;
        Node *prev, *next;
        Node(int c) : cnt(c), prev(NULL), next(NULL) {}
    };
    Node *head, *tail;
    unordered_map<string, Node*> mp;
    void addNodeAfter(Node* prevNode, Node* newNode) {
        newNode->next = prevNode->next;
        newNode->prev = prevNode;
        prevNode->next->prev = newNode;
        prevNode->next = newNode;
    }
    void removeNode(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
        delete node;
    }
public:
    AllOne() {
        head = new Node(0);
        tail = new Node(0);
        head->next = tail;
        tail->prev = head;
    }
    void inc(string key) {
        if (mp.find(key) == mp.end()) {
            Node* node;
            if (head->next != tail && head->next->cnt == 1) {
                node = head->next;
            } else {
                node = new Node(1);
                addNodeAfter(head, node);
            }
            node->keys.insert(key);
            mp[key] = node;
        } else {
            Node* cur = mp[key];
            Node* nextNode;
            int newCnt = cur->cnt + 1;

            if (cur->next != tail && cur->next->cnt == newCnt) {
                nextNode = cur->next;
            } else {
                nextNode = new Node(newCnt);
                addNodeAfter(cur, nextNode);
            }
            nextNode->keys.insert(key);
            mp[key] = nextNode;
            cur->keys.erase(key);
            if (cur->keys.empty())
                removeNode(cur);
        }
    }
    void dec(string key) {
        Node* cur = mp[key];
        if (cur->cnt == 1) {
            mp.erase(key);
        } else {
            Node* prevNode;
            int newCnt = cur->cnt - 1;
            if (cur->prev != head && cur->prev->cnt == newCnt) {
                prevNode = cur->prev;
            } else {
                prevNode = new Node(newCnt);
                addNodeAfter(cur->prev, prevNode);
            }

            prevNode->keys.insert(key);
            mp[key] = prevNode;
        }
        cur->keys.erase(key);
        if (cur->keys.empty())
            removeNode(cur);
    }
    string getMaxKey() {
        if (tail->prev == head) return "";
        return *(tail->prev->keys.begin());
    }
    string getMinKey() {
        if (head->next == tail) return "";
        return *(head->next->keys.begin());
    }
};
