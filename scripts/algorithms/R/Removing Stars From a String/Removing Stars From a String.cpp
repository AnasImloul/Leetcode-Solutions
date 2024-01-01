// Runtime: 81 ms (Top 86.58%) | Memory: 25.50 MB (Top 88.04%)

class Solution {
public:
    string removeStars(string s) {
        int n = s.size();
        int cnt = 0;
        string k = "";
        for(int i = n-1; i >= 0; i--)
        {
            if(s[i] == '*')
            cnt++;
            else
            {
                if(cnt > 0)
                {
                    cnt--;
                }
                else
                {
                    k += s[i];
                }
            }
        }
        reverse(k.begin(),k.end());
        return k;
    }
};
