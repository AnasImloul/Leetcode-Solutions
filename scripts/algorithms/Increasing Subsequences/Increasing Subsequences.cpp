class Solution {
public:
    set<vector<int>>ans;
    void solve(int start, int n, vector<int>&nums, vector<int>&result){
        if(result.size()>1)ans.insert(result);
        if(start==n){
            return;
        }
        for(int i=start; i<n; i++){
            if(result.empty() || result.back()<=nums[i]){
                result.push_back(nums[i]);
                solve(i+1, n, nums, result);
                result.pop_back();
            }
        }
        
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        int n = nums.size();
        vector<int>result;
        solve(0, n, nums, result);
        return vector<vector<int>>(ans.begin(), ans.end());
    }
};
