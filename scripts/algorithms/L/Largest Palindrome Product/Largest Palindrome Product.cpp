// Runtime: 335 ms (Top 8.2%) | Memory: 7.03 MB (Top 6.6%)

class Solution {
public:
    int largestPalindrome(int n) {
        if(n==1)
        {
            return 9;
        }
        int hi=pow(10,n)-1;
        int lo=pow(10,n-1);
        int kk=1337;
        for(int i=hi;i>=lo;i--)
        {
            string s=to_string(i);
            string k=s;
            reverse(k.begin(),k.end());
            s+=k;
            long long int ll=stol(s);
            for(int j=hi;j>=sqrtl(ll);j--)
            {
                if(ll%j==0)
                {
                    return ll%kk;
                }
            }
            
        }
        return 0;
    }
};