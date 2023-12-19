// Runtime: 4 ms (Top 41.14%) | Memory: 7.40 MB (Top 44.57%)

class Solution {
public:
    int minOperations(string s) {
        int n=s.size(), ans=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]-'0' != i%2)
            ans++;
        }
        return min(ans, n-ans);
    }
};
