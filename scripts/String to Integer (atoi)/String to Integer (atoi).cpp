class Solution {
public:
    int myAtoi(string s) {
        int i=0, flag=0;
        while(s[i]==' ')
            i++;
        long long ans=0;
        if(s[i]=='+')
            i++;
        else if(s[i]=='-')
        {
            flag=1;
            i++;
        }
        
        while(isdigit(s[i]) && i<s.size())
        {
            ans *= 10;
            ans += (s[i]-'0');
            
            if(ans > 2147483647)
            {
                ans = 2147483647;
                if(flag)
                {
                    ans *= -1;
                    ans -= 1;
                }
                
                return ans;
            }
            i++;
        }
        
        if(flag)
            ans *= -1;
                
        return ans;
    }
};
