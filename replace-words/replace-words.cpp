#include <sstream>
#include <iostream>

class Solution {
public:
    class Trie
    {
        public:
        Trie() : head (nullptr) {}
        
        void insert(const std::string& key)
        {
            if (head == nullptr)
            {
                head = new TrieNode('!');
            }
            
            TrieNode* itr = head;
            for (char c : key)
            {
                auto result = std::find_if(itr->children.begin(), itr->children.end(), [c] (TrieNode* t) {
                    return t->value == c;
                });
                if (result != itr->children.end())
                {
                    // we found a node in the children which matches this letter, move down the trie
                    itr = *result;
                }
                else
                {
                    // we need to create a new node for this letter
                    TrieNode* node = new TrieNode(c);
                    itr->children.push_back(node);
                    itr = node;
                }
            }
            itr->done = true;
        }
        
        std::string find(const std::string& word)
        {
            TrieNode* itr = head;
            // check that we have a valid initialized trie
            if (itr != nullptr)
            {
                // iterate over the characters in the word
                for (int i = 0; i < word.size(); ++i)
                {
                    auto result = std::find_if(itr->children.begin(), itr->children.end(), [word, i] (TrieNode* t) {
                        return t->value == word[i];
                    });
                    
                    if (result != itr->children.end())
                    {
                        // we found a node in the children which matches this letter, move down the trie
                        if ((*result)->done)
                        {
                            return word.substr(0, i+1);
                        }
                        else
                        {
                            itr = *result;
                        }
                    }
                    else
                    {
                        if (i <= 1 || !itr->done)
                        {
                            // we didn't find any nodes in our trie matching more than the first letter in our word
                            // or we are at a node which isn't the end of a prefix
                            return "";
                        }
                        else
                        {
                            // return the substring so far
                            return word.substr(0, i);
                        }
                    }
                }
                return word;
            }
            return "";
        }
        
        private:
        struct TrieNode
        {
            bool done;
            char value;
            std::vector<TrieNode*> children;
            TrieNode(char c) : done(false), value(c), children() {}
        };
        
        TrieNode* head;
    };
    
    string replaceWords(vector<string>& dictionary, string sentence) {
        Trie t;
        
        // first insert all the prefixes into the trie
        for (auto& prefix : dictionary)
        {
            t.insert(prefix);
        }
        
        // next iterate the sentence and replace all successors with the root forming it
        std::istringstream is(sentence);
        std::ostringstream os;
        while (is)
        {
            // extract the original word from the sentence
            std::string originalWord;
            is >> originalWord;
            // search for a prefix in the trie
            auto result = t.find(originalWord);
            // if the result is empty, we didnt find anything
            if (result.empty())
            {
                // add the original word back to the sentence
                os << originalWord;
            }
            else
            {
                os << result;
            }
            if (!is.eof())
            {
                os << " ";
            }
        }
        return os.str();
    }
};