typedef struct Node {
    int key, value;
    struct Node *prev;
    struct Node *next;
} Node;
typedef struct {
    int capacity;
    int size;
    Node *head;
    Node *tail;
    Node **hash;
} LRUCache;
void removeNode(Node *node) {
    node->prev->next = node->next;
    node->next->prev = node->prev;
}
void addToFront(LRUCache *cache, Node *node) {
    node->next = cache->head->next;
    node->prev = cache->head;
    cache->head->next->prev = node;
    cache->head->next = node;
}
LRUCache* lRUCacheCreate(int capacity) {
    LRUCache *cache = (LRUCache *)malloc(sizeof(LRUCache));
    cache->capacity = capacity;
    cache->size = 0;
    cache->head = (Node *)malloc(sizeof(Node));
    cache->tail = (Node *)malloc(sizeof(Node));
    cache->head->next = cache->tail;
    cache->tail->prev = cache->head;
    cache->head->prev = NULL;
    cache->tail->next = NULL;
    cache->hash = (Node **)calloc(10001, sizeof(Node*));
    return cache;
}
int lRUCacheGet(LRUCache* obj, int key) {
    Node *node = obj->hash[key];
    if (node == NULL)
        return -1;
    removeNode(node);
    addToFront(obj, node);
    return node->value;
}
void lRUCachePut(LRUCache* obj, int key, int value) {
    Node *node = obj->hash[key];
    if (node != NULL) {
        node->value = value;
        removeNode(node);
        addToFront(obj, node);
        return;
    }
    if (obj->size == obj->capacity) {
        Node *lru = obj->tail->prev;
        removeNode(lru);
        obj->hash[lru->key] = NULL;
        free(lru);
        obj->size--;
    }
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->key = key;
    newNode->value = value;

    addToFront(obj, newNode);
    obj->hash[key] = newNode;
    obj->size++;
}
void lRUCacheFree(LRUCache* obj) {
    Node *curr = obj->head;
    while (curr != NULL) {
        Node *temp = curr;
        curr = curr->next;
        free(temp);
    }
    free(obj->hash);
    free(obj);
}
