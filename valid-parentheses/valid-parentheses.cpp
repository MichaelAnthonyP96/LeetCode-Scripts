class Solution {
public:
    bool isValid(string s) {
        if (s.size() % 2)
        {
            return false;
        }
        
        std::stack<char> p;
        for (char c : s)
        {
            if (c == '(' || 
                c == '{' ||
                c == '[')
            {
                p.push(c);
            }
            else if (c == ')')
            {
                if (p.empty() || p.top() != '(')
                {
                    return false;
                }
                else
                {
                    p.pop();
                }
            }
            else if (c == '}')
            {
                if (p.empty() || p.top() != '{')
                {
                    return false;
                }
                else
                {
                    p.pop();
                }
            }
            else if (c == ']')
            {
                if (p.empty() || p.top() != '[')
                {
                    return false;
                }
                else
                {
                    p.pop();
                }
            }
            else
            {
                return false;
            }
        }
        return p.empty();
    }
};