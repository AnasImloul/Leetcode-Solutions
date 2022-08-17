class Solution {
public:
    int countHomogenous(string s) {
        
        int n = s.length();
        long long count = 0;
        long long len = 0;
        int MOD = 1000000007;
        
        int i = 0;    
        while(i<n)
        {
            len = 1;
            
            // get length of same char substring
            while(i+1<n && s[i]==s[i+1])i++,len++;
            
            // calculate number of substring from same char substring and then sum
            count = (count + ((len * (len+1)) /2 )%MOD ) % MOD;
            
            i++;
        }
        
        return count;
    }
};
