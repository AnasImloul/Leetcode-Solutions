class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> sta;
        int nums = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(')
            {
                sta.push(s[i]);
            }
            else
            {
                if (!sta.empty())
                {
                    sta.pop();
                }
                else
                {
                    nums++;
                }
            }
        }
        nums += sta.size();
        return nums;
    }
};