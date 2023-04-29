class Solution {
public:
    int minimumLength(string s) {
        int i=0,j=s.length()-1;
        while(i<j)
        {
            if(s[i]!=s[j])
            {
                break;
            }
            else
            {
                char x=s[i];
                while(s[i]==x)
                {
                    i++;
                }
                if(i>j)
                {
                    return 0;
                }
                while(s[j]==x)
                {
                    j--;
                }
                if(j<i)
                {
                    return 0;
                }
            }
        }
        
        return j-i+1;
    }
};