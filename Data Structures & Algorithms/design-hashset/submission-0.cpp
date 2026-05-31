class MyHashSet {
private:
    struct LinkedNode {
        int key;
        LinkedNode* next;

        LinkedNode(int key) {
            this->key = key;
            this->next = nullptr;
        }
    };

    vector<LinkedNode*> node_list;

    int hash(int key) {
        return key % node_list.size();
    }
public:
    MyHashSet() {
        node_list.resize(10000);

        for(auto& bucket: node_list) {
            bucket = new LinkedNode(0);
        }   
    }
    
    void add(int key) {
        LinkedNode* curr = node_list[hash(key)];

        while(curr->next) {
            if(curr->next->key == key) {
                return;
            }
            curr = curr->next;
        }
        curr->next = new LinkedNode(key);
    }
    
    void remove(int key) {
        LinkedNode* curr = node_list[hash(key)];

        while(curr->next) {
            if(curr->next->key == key) {
                LinkedNode* temp = curr->next;
                curr->next = temp->next;
                delete temp;
                return;
            }
            curr = curr->next;
        }
    }
    
    bool contains(int key) {
        LinkedNode* curr = node_list[hash(key)];

        while(curr->next) {
            if(curr->next->key == key) {
                return true;
            }
            curr = curr->next;
        }
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */