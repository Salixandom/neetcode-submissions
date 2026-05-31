class MyHashMap {
private:
    struct LinkedNode{
        int key;
        int value;
        LinkedNode* next;

        LinkedNode(int key, int value) {
            this->key = key;
            this->value = value;
            this->next = nullptr;
        }
    };

    vector<LinkedNode*> bucket_list;

    int hash(int key) {
        return key % bucket_list.size();
    }
public:
    MyHashMap() {
        bucket_list.resize(10000);

        for(auto& bucket: bucket_list){
            bucket = new LinkedNode(0, 0);
        }
    }
    
    void put(int key, int value) {
        LinkedNode* curr = bucket_list[hash(key)];

        while(curr->next) {
            if(curr->next->key == key) {
                curr->next->value = value;
                return;
            }
            curr = curr->next;
        }
        
        curr->next = new LinkedNode(key, value);
    }
    
    int get(int key) {
        LinkedNode* curr = bucket_list[hash(key)];

        while(curr->next) {
            if(curr->next->key == key) {
                return curr->next->value;
            }
            curr = curr->next;
        }

        return -1;        
    }
    
    void remove(int key) {
        LinkedNode* curr = bucket_list[hash(key)];

        while(curr->next) {
            if(curr->next->key == key) {
                LinkedNode* temp = curr->next;
                curr->next = temp->next;
                delete temp;
                return;
            }
            curr = curr->next;
        }
        return;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */