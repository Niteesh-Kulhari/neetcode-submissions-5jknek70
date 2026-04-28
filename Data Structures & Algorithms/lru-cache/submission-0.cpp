
class ListNode{
public:
    int key;
    int val;
    ListNode* next;
    ListNode* prev;

    ListNode(int key, int val){
        this->key = key;
        this->val = val;
        prev = nullptr;
        next = nullptr;
    }
};



class LRUCache {
private:
    unordered_map<int, ListNode*> cache;
    ListNode* left;
    ListNode* right;
    int capacity;

    void remove(ListNode* node){
        ListNode* next = node->next;
        ListNode* prev = node->prev;

        prev->next = next;
        next->prev = prev;
    }

    void insert(ListNode* node){
        ListNode* prev = right->prev;
        prev->next = node;
        node->prev = prev;
        node->next = right;
        right->prev = node;
    }

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        cache.clear();
        left = new ListNode(0,0);
        right = new ListNode(0,0);
        left->next = right;
        right->prev = left;

    }
    
    int get(int key) {
        if(cache.find(key) != cache.end()){
            ListNode* temp = cache[key];
            remove(temp);
            insert(temp);
            return temp->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(cache.find(key) != cache.end()){
            remove(cache[key]);
        }

        ListNode* node = new ListNode(key, value);
        cache[key] = node;
        insert(node);

        if(cache.size() > capacity){
            ListNode* rmv = left->next;
            remove(rmv);
            cache.erase(rmv->key);
            delete rmv;
        }
    }
};
