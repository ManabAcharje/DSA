class LRUCache {
public:
    struct Node{
        int key;
        int val;
        Node* prev;
        Node* next;

        Node(int key, int val) {
            this->key = key;
            this->val = val;

            prev = nullptr;
            next = nullptr;
        }
    };
    unordered_map<int, Node*> cacheMap;

    Node* head;
    Node* tail;

    void add(Node* newNode) { 
        Node* temp = head->next ;
        newNode ->next = temp;
        temp->prev= newNode;
        head->next = newNode;
        newNode->prev = head;
    }
    void del(Node* delNode) {
        Node* delPrev = delNode->prev;
        Node* delNext = delNode->next;
        delPrev->next = delNext;
        delNext->prev = delPrev;
    }
    int capacity;

    LRUCache(int capacity) {
        this->capacity = capacity;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);

        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if (cacheMap.contains(key)) {
            Node* resNode = cacheMap[key];
            int res = resNode->val;

            del(resNode);
            add(resNode);

            return res;
        }

        else
            return -1;
    }

    void put(int key, int value) {
        if (cacheMap.contains(key)) {
            Node* existingNode = cacheMap[key];
            existingNode->val = value;
            del(existingNode);
            add(existingNode);
            return;
        } else if (cacheMap.size() == capacity) {
            Node* lruNode = tail->prev;

            cacheMap.erase(lruNode->key);
            del(lruNode);
            delete lruNode;
        }
        Node* newNode = new Node(key, value);
        add(newNode);
        cacheMap[key] = newNode;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */