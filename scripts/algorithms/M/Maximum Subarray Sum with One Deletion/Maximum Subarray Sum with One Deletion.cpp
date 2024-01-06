// Runtime: 23 ms (Top 76.54%) | Memory: 23.70 MB (Top 72.35%)

class Solution {
public:
    int maximumSum(vector<int>& a) {
        
		// Kadane's Algo
        // DP time: O(N) space: O(N)
        // dp[i][2]-->dp[i][0]->suf_del and dp[i][1]->suf_no_del
        
        // Space optimized time: O(N) space: O(1)
		int n=a.size();
        int suf_del=0; 
        int suf_no_del=a[0];
        int ans=a[0];
        for(int i=1;i<n;i++){
            suf_del=max(suf_del+a[i],suf_no_del);       // suf_del
            suf_no_del=max(suf_no_del+a[i],a[i]);       // suf_no_del
            ans=max({ans,suf_del,suf_no_del});         
        }
        return ans;
    }
};
