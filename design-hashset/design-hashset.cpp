#include <algorithm> 
class MyHashSet {
public:
    /** Initialize your data structure here. */
    MyHashSet() : loadFactor(0.7), capacity(10000), size(0), buckets(capacity) {
        std::fill(buckets.begin(), buckets.end(), std::list<int>());
        a = 43;
        // b = 43;
    }
    
    ~MyHashSet() {
        // delete[] buckets;
    }
    
    void add(int key) 
    {
        if (size >= (loadFactor * capacity))
        {
            resize();
        }
        int idx = hashFunction(key);
        auto& s = buckets[idx];
        auto result = std::find(s.begin(), s.end(), key);
        if (result != s.end())
        {
            // we found the value already, do nothing
            return;
        }
        else
        {
            s.push_front(key);
            ++size;
        }
    }
    
    void remove(int key) 
    {
        int idx = hashFunction(key);
        auto& s = buckets[idx];
        auto result = std::find(s.begin(), s.end(), key);
        if (result != s.end())
        {
            // we found something valid and can remove it
            s.erase(result);
            --size;
        }
    }
    
    // probe function
    // int probe(int key)
    // {
    //     // Just do linear probing for now
    //     return (a * key) + b;
    // }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) 
    {
        int idx = hashFunction(key);
        auto& s = buckets[idx];
        auto result = std::find(s.begin(), s.end(), key);
        if (result != s.end())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    
    void resize()
    {
        updateConstants();
        
        // create a handle to the old array
        auto oldBuckets = std::move(buckets);
        // allocate a new array and fill it with INT_MIN
        buckets = std::vector<std::list<int>>(capacity);
        
        // iterate the oldBuckets and rehash those values
        for (int i = 0; i < oldBuckets.size(); ++i)
        {
            if (auto& s = oldBuckets[i]; !s.empty())
            {
                // add the value to the new buckets array
                for (auto itr = s.begin(); itr != s.end(); ++itr)
                {
                    // add(*itr);
                    buckets[hashFunction(*itr)].push_front(*itr);
                }
            }
        }
        
        // delete[] oldBuckets;
    }
    
    void updateConstants()
    {
        // update the hash function constants
        capacity = *primes.lower_bound(capacity * 2);
        // b = a;
        a = *primes.upper_bound(a+1);
    }
    
    int hashFunction(int key)
    {
        return ((a * key)) % capacity;
    }
private:
    double loadFactor;
    int capacity;
    int size;
    int a; // b; // Linear probing constants
    std::vector<std::list<int>> buckets;
    const static std::set<int> primes;
};

const std::set<int> MyHashSet::primes{2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101,103,107,109,113,127,131,137,139,149,151,157,163,167,173,179,181,191,193,
                         197,199,211,223,227,229,233,239,241,251,257,263,269,271,277,281,283,293,307,311,313,317,331,337,347,349,353,359,367,373,379,383,389,397,401,409,
                         419,421,431,433,439,443,449,457,461,463,467,479,487,491,499,503,509,521,523,541};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */