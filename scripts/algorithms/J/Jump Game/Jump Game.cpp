// Runtime: 72 ms (Top 91.03%) | Memory: 48.3 MB (Top 93.54%)
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int ans = nums[0];
        if(nums.size()>1&&ans==0) return false;
        for(int i=1; i<nums.size(); i++){
            ans = max(ans-1,nums[i]);
            if(ans<=0&&i!=nums.size()-1) return false;
        }
        return true;
    }
};