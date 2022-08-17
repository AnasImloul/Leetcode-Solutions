class Solution {
    void shift(string& s, int times, int amt)
    {
        const int clampL = 97;
        const int clampR = 123;
        
        for (int i = 0; i <= times; i++)
        {
            int op = (s[i] + amt) % clampR;
            
            if (op < clampL)
                op += clampL;
            
            s[i] = op;
        }
    }
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        
        for (int i = 0; i < shifts.size(); i++)
            shift(s,i,shifts[i]);
        
        return s;
    }
};
