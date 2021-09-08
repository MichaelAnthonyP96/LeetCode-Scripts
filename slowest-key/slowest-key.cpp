class Solution {
public:
    char slowestKey(vector<int>& releaseTimes, string keysPressed) {
        if (releaseTimes.empty())
        {
            return 'z';
        }
        int currLongTime = releaseTimes[0];
        int longIdx = 0;
        
        for (int i = 1; i < releaseTimes.size(); ++i)
        {
            int pressTime = releaseTimes[i] - releaseTimes[i-1];
            if (pressTime > currLongTime || (pressTime == currLongTime && keysPressed[i] > keysPressed[longIdx]))
            {
                longIdx = i;
                currLongTime = pressTime;
            }
        }       
        return keysPressed[longIdx];
    }
};