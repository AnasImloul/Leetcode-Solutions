// Runtime: 157 ms (Top 35.29%) | Memory: 34.80 MB (Top 43.14%)

class Solution {
public:
    string robotWithString(string s) {
        int n=s.length();
        vector<char>mn(n);
        mn[n-1]=s[n-1];
        char m=s[n-1];
        for(int i=n-2;i>=0;i--)
        {
            if(s[i]<m)
            {
                m=s[i];
            }
            mn[i]=m;
        }
        string t="";
        string ans="";
        t+=s[0];
        for(int i=1;i<n;i++)
        {
            if(t.length()==0 || s[i]<=t.back() )
            {
                t+=s[i];
            }
            else
            {
                while(true)
                {
                     if(t.length()!=0 && mn[i]<t.back())
                     {
                         t+=s[i];
                         break;
                     }
                    else
                    {
                         if(t.length()==0 || t.back()>s[i])
                         {
                             i--;
                             break;
                         }
                         ans+=t.back();
                         t.pop_back();
                    }    
                 }   
            }       
         }
        
        for(int i=t.length()-1;i>=0;i--)
        {
            ans+=t[i];
        }
        return ans;
    }
};
