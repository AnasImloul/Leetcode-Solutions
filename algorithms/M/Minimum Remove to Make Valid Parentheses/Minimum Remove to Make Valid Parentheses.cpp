class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int count = 0;
        for(int i = 0; i < s.size(); i++)
        {
            
            if(s[i]=='(')
            {
                count++;
            }
            if(s[i]==')')
            {
                if(count==0)
                {
                    s[i]='*';
                }
                else
                {
                    count--;
                }
            }
                
        }
        if(count==0)
        {
            s.erase(remove(s.begin(), s.end(), '*'), s.end());
            return s;
        }
        for(int i = s.size()-1; i >=0; i--)
        {
            if(s[i]=='(')
            {
                s[i]='*';
                count--;
            }
            if(count==0)
            {
                s.erase(remove(s.begin(), s.end(), '*'), s.end());
                return s;
            }
        }
        return s;
    }
};
