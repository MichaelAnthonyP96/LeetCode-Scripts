class Solution {
public:
    bool determineDigit(std::string& s)
    {
        std::size_t firstSpace = s.find_first_of(" ");
        return s.find_first_of("0123456789", firstSpace+1) != std::string::npos;
    }
    bool determineLetter(std::string& s)
    {
        return !determineDigit(s);
    }
    
    vector<string> reorderLogFiles(vector<string>& logs) {
        std::vector<std::string> onlyLetters;
        for (auto itr = logs.begin(); itr != logs.end();)
        {
            // std::cout << "itr = " << *itr << std::endl;
            if (determineLetter(*itr))
            {
                // std::cout << "Inside conditional" << std::endl;
                onlyLetters.push_back(*itr);
                logs.erase(itr);
            }
            else
            {
                ++itr;
            }
        }
        // for (auto& itr : onlyLetters)
        // {
        //    std::cout << "onlyLetters = " << itr << std::endl;
        // }
        
        std::sort(onlyLetters.begin(), onlyLetters.end(), [] (std::string& a, std::string& b) 
                  {
                    std::size_t firstSpaceA = a.find_first_of(" ");
                    std::size_t firstSpaceB = b.find_first_of(" ");
                    auto aSub = a.substr(firstSpaceA);
                    auto bSub = b.substr(firstSpaceB);
                    if (aSub.compare(bSub) != 0)
                    {
                        return  aSub < bSub;
                    }
                    else
                    {
                        return a.substr(0, firstSpaceA) < b.substr(0, firstSpaceB);    
                    }
                        });
        onlyLetters.insert(onlyLetters.end(), logs.begin(), logs.end());
        return onlyLetters;
    }
};