class Solution {
public:
    vector<int> ans;
    vector<int> res;
    Solution(vector<int>& nums) {
        ans=nums;
        res=nums;
    }
    
    vector<int> reset() {
        return res;
    }
    
    vector<int> shuffle() {
        next_permutation(ans.begin(),ans.end());
        return ans;
    }
};
