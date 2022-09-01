// Runtime: 11 ms (Top 8.63%) | Memory: 6.7 MB (Top 45.44%)
class Solution {
public:
    int maxNumberOfBalloons(string text) {
        map<char,int>m;
        for(int i=0;i<text.length();i++)
        {
            m[text[i]]++;
        }
        string s="balloon";
        int flag=1;
        int c=0;
        while(1)
        {
            for(int i=0;i<s.length();i++)
            {
                m[s[i]]--;
                if(m[s[i]]==-1)
                {
                    flag=0;
                }
            }
            if(flag==0)
                break;
            c++;
        }
        return c;
    }
};