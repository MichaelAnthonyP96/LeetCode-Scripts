#include <random>

class Solution {
public:
    Solution(vector<int>& nums) : original(nums), generator(), distribution(0, original.size()-1)
    {    
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return original;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        std::vector<int> shuffled(original.size(), 0);
        std::unordered_set<int> mySet;
        
        for (const auto& itr: original)
        {
            int idx;
            do 
            {
               idx = distribution(generator);
            } while (mySet.find(idx) != mySet.end());
            mySet.insert(idx);
            // std::cout << "shuffled[" << idx << "] = " << itr << std::endl;
            shuffled[idx] = itr;
        }
        return std::move(shuffled);
    }
    
private:
    std::vector<int> original;
    std::default_random_engine generator;
    std::uniform_int_distribution<int> distribution;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */