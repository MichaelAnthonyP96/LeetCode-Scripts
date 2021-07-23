class Solution {
public:
    bool process(string& dominoes)
    {
        bool flag = false;
        for (int i = 0; i < dominoes.size(); ++i)
        {
            char ch = dominoes[i];
            if (ch == 'L')
            {
                if ((i - 2 >= 0) && (dominoes[i - 2] == 'R'))
                {
                    // do nothing
                    // continue;
                }
                else if (((i-1) >= 0) && dominoes[i-1] != 'L' && dominoes[i-1] != 'R')
                {
                    dominoes[i-1] = 'L';
                    flag = true;
                }
            }
            else if (ch == 'R')
            {
                // std::cout << "3" << std::endl;
                if ((i + 2 <= (dominoes.size() - 1) && (dominoes[i + 2] == 'L')))
                {
                    // continue;
                }
                else if ((i + 1 <= (dominoes.size() - 1) && dominoes[i+1] != 'L' && dominoes[i+1] != 'R'))
                {
                    dominoes[i+1] = 'R';
                    ++i;
                    if (i + 2 <= (dominoes.size() - 1) && dominoes[i + 2] == 'L' && dominoes[i + 1] == '.')
                    {
                        dominoes[i+1] = 'L';
                    }
                    flag = true;
                }
            }
            else if (ch == '.')
            {
                // continue;
            }
        }
        return flag;
    }
    
    string pushDominoes(string dominoes) {
        while (process(dominoes))
        {
            // std::cout << "process = " << dominoes << std::endl;
        }
        return dominoes;
    }
};