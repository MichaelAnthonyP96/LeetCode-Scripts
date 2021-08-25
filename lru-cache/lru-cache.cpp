#include <algorithm>
class LRUCache {
public:
    
    struct ListNode
    {
        int key_;
        int value_;
        ListNode* prev_;
        ListNode* next_;
    };
    
    void moveToHead(ListNode* ln)
    {
        // Remove node from the list
        ListNode* p = ln->prev_;
        ListNode* n = ln->next_;
        if (p)
        {
            p->next_ = n;
        }
        if (n)
        {
            n->prev_ = p;
        }
        // add the node to the front of the list
        ln->prev_ = &head_;
        ln->next_ = head_.next_;
        head_.next_->prev_ = ln;
        head_.next_ = ln;
    }
    
    int removeOldest()
    {
        if (tail_.prev_)
        {
            ListNode* tmp = tail_.prev_;
            tmp->prev_->next_ = &tail_;
            tail_.prev_ = tmp->prev_;
            int tmpKey = tmp->key_;
            delete tmp;
            --size_;
            return tmpKey;
        }
        else
        {
            return -1;
        }
    }
    
    LRUCache(int capacity) {
        capacity_ = capacity;
    }
    
    int get(int key) {
        auto result = dict_.find(key);
        if (result != dict_.end())
        {
            moveToHead(result->second);
            return result->second->value_;
        }
        else 
        {
            return -1;
        }
    }
    
    void put(int key, int value) {
        if (get(key) != -1)
        {
            // we need to update the key value
            dict_[key]->value_ = value;
            moveToHead(dict_[key]);
            return;
        }
        if (size_ >= capacity_)
        {
            // we need to evict the oldest node, we know this key value pair isn't in the dictionary
            auto poppedVal = removeOldest();
            if (poppedVal > -1)
            {
                dict_.erase(dict_.find(poppedVal));
            }
            
        }
        
        // insert the key into the map since there is more room
        ListNode* newNode = new ListNode{key, value, nullptr, nullptr};
        dict_[key] = newNode;
        moveToHead(newNode);
        ++size_;
        
    }
private:
    std::map<int, ListNode*> dict_;
    int size_ {0};
    int capacity_ {0};
    ListNode head_{-1, -1, nullptr, &tail_};
    ListNode tail_{-1, -1, &head_, nullptr};
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */