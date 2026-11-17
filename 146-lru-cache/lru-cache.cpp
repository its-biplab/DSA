class LRUCache {
public:
        class Node {
    public:
        int key, value;
        Node* prev;
        Node* next;

        Node(int k, int v) {
            key = k;
            value = v;
            prev = nullptr;
            next = nullptr;
        }
    };

    Node* head;
    Node* tail;
    int capacity;

    unordered_map<int, Node*> mp;
    LRUCache(int capacity) {
         this->capacity = capacity;

        head = new Node(-1, -1);
        tail = new Node(-1, -1);

        head->next = tail;
        tail->prev = head;
    }

    // Remove node from its current position
    void removeNode(Node* node) {
        Node* prevNode = node->prev;
        Node* nextNode = node->next;

        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }

    // Insert node just after head
    void insertAtFront(Node* node) {
        Node* nextNode = head->next;

        node->next = nextNode;
        node->prev = head;

        head->next = node;
        nextNode->prev = node;
    }
    
    int get(int key) {
        if (mp.find(key) == mp.end()) {
            return -1;
        }

        Node* node = mp[key];

        removeNode(node);
        insertAtFront(node);

        return node->value;
    }
    
     void put(int key, int value) {
        // Key already exists
        if (mp.find(key) != mp.end()) {
            Node* node = mp[key];

            node->value = value;

            removeNode(node);
            insertAtFront(node);
        }
        else {
            // Cache is full
            if (mp.size() == capacity) {
                Node* lruNode = tail->prev;

                removeNode(lruNode);
                mp.erase(lruNode->key);

                delete lruNode;
            }

            // Create new node
            Node* newNode = new Node(key, value);

            insertAtFront(newNode);
            mp[key] = newNode;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */