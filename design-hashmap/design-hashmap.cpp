#include <algorithm> 
class MyHashMap {
public:
    /** Initialize your data structure here. */
    MyHashMap() : loadFactor(0.7), capacity(10000), size(0), buckets(capacity) {
        std::fill(buckets.begin(), buckets.end(), std::list<std::pair<int, int>>());
        a = 43;
        // b = 3;
    }
    
    ~MyHashMap() {
        // delete[] buckets;
    }
    
    std::list<std::pair<int, int>>& getList(int key)
    {
        // hash the key, returning the index in the array
        int idx = hashFunction(key);
        // fetch the list at that index
        return buckets[idx];
    }
    
    void put(int key, int value) 
    {
        // resize if the array is starting to get full beyond our liking
        // if (size >= (loadFactor * capacity))
        // {
        //     resize();
        // }
        auto& l = getList(key);
        if (!l.empty())
        {
            // linearly search the list for the key
            auto result = std::find_if(l.begin(), l.end(), [key] (std::pair<int, int>& itr)
                                   {
                                       return itr.first == key;
                                       });
            // we found something valid and can remove it
            if (result != l.end())
            {
                result->second = value;
            }
            else
            {
                l.push_front(std::make_pair(key, value));
                ++size;  
            }
        }
        else
        {
            // we didn't find the key, so insert it into the list
            l.push_front(std::make_pair(key, value));
            ++size;
        }
    }
    
    void remove(int key) 
    {
        auto& l = getList(key);
        // if there are values in this list
        if (!l.empty())
        {
            // linearly search the list for the key
            auto result = std::find_if(l.begin(), l.end(), [key] (std::pair<int, int>& itr)
                                   {
                                       return itr.first == key;
                                       });
            // we found something valid and can remove it
            if (result != l.end())
            {
                l.erase(result);
                --size;
            }
            
        }
    }
    
    /** Returns true if this set contains the specified element */
    int get(int key) 
    {
        auto& l = getList(key);
        // if there are values in this list
        if (!l.empty())
        {
            // linearly search the list for the key
            auto result = std::find_if(l.begin(), l.end(), [key] (std::pair<int, int>& itr)
                                   {
                                       return itr.first == key;
                                       });
            // we found something valid and can remove it
            if (result != l.end())
            {
                return result->second;
            }
            else
            {
                // the value isn't in the list
                return -1;
            }
            
        }
        else
        {
            // the list is empty
            return -1;
        }
    }
    
    void resize()
    {
        updateConstants();
        
        // create a handle to the old array
        auto oldBuckets = std::move(buckets);
        // allocate a new array and fill it with INT_MIN
        buckets = std::vector<std::list<std::pair<int,int>>>(capacity);
        
        // iterate the oldBuckets and rehash those values
        for (int i = 0; i < oldBuckets.size(); ++i)
        {
            if (auto& s = oldBuckets[i]; !s.empty())
            {
                // add the value to the new buckets array
                for (auto itr = s.begin(); itr != s.end(); ++itr)
                {
                    // add(*itr);
                    buckets[hashFunction(itr->first)].push_front(std::make_pair(itr->first, itr->second));
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
        return (a * key) % capacity;
    }
private:
    double loadFactor;
    int capacity;
    int size;
    int a; // b; // Linear probing constants
    std::vector<std::list<std::pair<int, int>>> buckets;
    const static std::set<int> primes;
};

const std::set<int> MyHashMap::primes{2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101,103,107,109,113,127,131,137,139,149,151,157,163,167,173,179,181,191,193,
                         197,199,211,223,227,229,233,239,241,251,257,263,269,271,277,281,283,293,307,311,313,317,331,337,347,349,353,359,367,373,379,383,389,397,401,409,
                         419,421,431,433,439,443,449,457,461,463,467,479,487,491,499,503,509,521,523,541};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */