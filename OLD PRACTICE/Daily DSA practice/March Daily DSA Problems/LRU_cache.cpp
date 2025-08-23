class LRUCache {
    public:
        class Node{
            public:
                int key;
                int val;
                Node* prev;
                Node* next;
    
                Node(int key,int val)
                {
                    this->key = key;
                    this->val = val;
                    next = NULL;
                    prev = NULL;
                }
        };
    
        Node* head = new Node(-1,-1);
        Node* tail = new Node(-1,-1);
        int capacity;
        unordered_map<int,Node*> mpp;
        LRUCache(int capacity) {
            this->capacity = capacity;
            head->next = tail;
            tail->prev = head;
            mpp.clear();
        }
        void deleteNode(Node* newNode)
        {
            Node* delPrev = newNode->prev;
            Node* delNext = newNode->next;
            delPrev->next = delNext;
            delNext->prev = delPrev;
            delete(newNode);
        }
        void addNode(Node* newNode)
        {
            Node* temp = head->next;
            head->next = newNode;
            temp->prev = newNode;
            newNode->prev = head;//my code is giving heap buffer overflow error at there
            newNode->next = temp;
        }
        int get(int key) {
            if(mpp.find(key)!=mpp.end())
            {
                Node* resNode = mpp[key];
                int res = resNode->val;
                deleteNode(resNode);
                Node* newNode = new Node(key,res);
                addNode(newNode);
                mpp[key] = head->next;
                return res;
            }
            return -1;
        }
        
        void put(int key, int value) {
            if(mpp.find(key)!=mpp.end())
            {
                Node* resNode = mpp[key];
                mpp.erase(key);
                deleteNode(resNode);
            }
            if(mpp.size()==capacity)
            {
                Node* nodie = tail->prev;
                mpp.erase(nodie->key);
                deleteNode(nodie);
            }
            addNode(new Node(key,value));
            mpp[key] = head->next;
        }
    };
    
    /**
     * Your LRUCache object will be instantiated and called as such:
     * LRUCache* obj = new LRUCache(capacity);
     * int param_1 = obj->get(key);
     * obj->put(key,value);
     */