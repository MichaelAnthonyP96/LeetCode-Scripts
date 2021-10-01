class Solution {
public:
    int numUniqueEmails(vector<string>& emails) 
    {
        int count = 0;
        std::unordered_set<std::string> s;
        
        for(auto& email : emails)
        {
            auto at = email.find('@');
            // std::string curr = email.substr(0, pos);
            // std::cout << "email: " << email << std::endl;
            // find and remove '.' characters in the local name
            auto pos = email.find('.', 0);
            while (pos != std::string::npos && pos < at)
            {
                // remove the individual '.' characters before the @
                email.erase(pos, 1);
                pos = email.find('.');
                --at;
                // std::cout << "after removing . : " << email << std::endl;
            }
            
            // find and ignore everything after the '+' char
            // at = email.find('@');
            pos = email.find('+', 0);
            if (pos != std::string::npos && pos < at)
            {
                // remove everything after the +
                email.erase(pos, at - pos);
            }
            
            if (s.count(email) <= 0)
            {
                // we have not already encountered this email
                // std::cout << "inserting into the set: " << email << std::endl;
                s.insert(email);
                ++count;
            }
            
        }
        
        
        return count;
    }
};