// Runtime: 1339 ms (Top 11.66%) | Memory: 7.20 MB (Top 82.43%)

class Solution {
public:
    int ans = INT_MAX;
    void solve(int start, vector<int>& nums, vector<int>& v, int k){
        if(start==nums.size()){
            int maxm = INT_MIN;
            for(int i=0;i<k;i++){
                maxm = max(maxm,v[i]);
            }
            ans = min(ans,maxm);
            return;
        }
        for(int i=0;i<k;i++){
            v[i] += nums[start];
            solve(start+1,nums,v,k);
            v[i] -= nums[start];
        }
    }
    
    int distributeCookies(vector<int>& nums, int k) { // nums is the cookies vector
        int n = nums.size();
        vector<int> v(k,0); // v is to store each sum of the k subsets
        solve(0,nums,v,k);
        return ans;
    }
};
