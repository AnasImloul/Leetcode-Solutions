// Runtime: 130 ms (Top 78.41%) | Memory: 107.10 MB (Top 22.73%)

class Solution {
public:
    int numberOfArrays(vector<int>& d, int l, int u) {
        
        long long int n = d.size();
        long long int pr =0;
        long long int mini =0;
        long long int maxi =0;
        for(long long int i=0;i<n;i++)
        {
            pr+=d[i];
            maxi=max(maxi,pr);
            mini=min(mini,pr);
        }
        

        long long int range = maxi-mini;
        long long int cnt=0;
        if(u-l<range)
            return 0;
        cnt = u-(l+range);
        return cnt+1;
        
    }
};
