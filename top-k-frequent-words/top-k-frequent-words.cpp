#include <algorithm>

class Solution {
public:
    class BinaryHeap
    {
        public:
            BinaryHeap() : array()
            {
                
            }
        
            int find (const std::string& val)
            {
                auto result = std::find_if(array.begin(), array.end(), [val] (const HeapNode& h)
                                           {
                                               return h.value == val;
                                           });
                return result != array.end() ? std::distance(array.begin(), result) : -1;
            }
        
            void insert(const std::string& val)
            {
                if (array.size() == 0)
                {
                    array.emplace_back(HeapNode{val, 1});
                }
                else
                {
                    auto resultIdx = find(val);
                    // the node already exists, increase the count
                    if (-1 != resultIdx)
                    {
                        ++(array[resultIdx].count);
                        heapifyUp(resultIdx);
                    }
                    else
                    {
                        // we need to insert a new node
                        array.emplace_back(HeapNode{val, 1});
                        heapifyUp(array.size() - 1);
                    }
                }
            }
        
            std::string pop()
            {
                // extract the string matching the word
                auto returnStr = array[0].value;
                // swap the root node with the last child
                std::swap(array[0], array[array.size()-1]);
                // delete the last child
                array.erase(array.begin() + (array.size() - 1));
                // heapify down from the root
                heapifyDown(0);
                // return the string which was removed from the heap
                return returnStr;
            }    
            
        
            static inline int leftChild(int index)
            {
                return (2 * index) + 1;
            }
        
            static inline int rightChild(int index)
            {
                return (2 * index) + 2;
            }
        
            static inline int parent(int index)
            {
                return (index - 1) / 2;
            }
        
            void heapifyUp(int idx)
            {
                int parentIdx = parent(idx);
                if (parentIdx >= 0)
                {
                    if (array[parentIdx].count < array[idx].count || 
                        (array[parentIdx].count == array[idx].count 
                            && array[idx].value < array[parentIdx].value))
                    {
                        std::swap(array[parentIdx], array[idx]);
                        heapifyUp(parentIdx);
                    }
                }
            }
        
            void heapifyDown(int idx)
            {
                int greatestIdx = idx;
                int l = leftChild(idx);
                int r = rightChild(idx);
                if (l < array.size()) 
                {
                    if (array[l].count > array[greatestIdx].count ||
                        (array[l].count == array[greatestIdx].count && array[l].value < array[greatestIdx].value))
                    {
                        greatestIdx = l;
                    }
                    // else if ()
                    // {
                    //     std::swap(array[l], array[idx]);
                    // }
                }
                if (r < array.size())
                {
                    if (array[r].count > array[greatestIdx].count || 
                        (array[r].count == array[greatestIdx].count && array[r].value < array[greatestIdx].value))
                    {
                        greatestIdx = r;
                    }
                    // else if ()
                    // {
                    //     std::swap(array[r], array[idx]);
                    // }
                }
                
                if (greatestIdx != idx)
                {
                    std::swap(array[idx], array[greatestIdx]);
                    heapifyDown(greatestIdx);
                }
            }
        private:
            struct HeapNode
            {
                std::string value;
                int count;
            };
            std::vector<HeapNode> array;
    };
    
    
    
    vector<string> topKFrequent(vector<string>& words, int k) 
    {
        BinaryHeap bh;
        for (auto& word : words)
        {
            bh.insert(word);
        }
        
        std::vector<std::string> results;
        for (int i = 0; i < k; ++i)
        {
            results.push_back(bh.pop());
        }
        
        return results;
    }
};