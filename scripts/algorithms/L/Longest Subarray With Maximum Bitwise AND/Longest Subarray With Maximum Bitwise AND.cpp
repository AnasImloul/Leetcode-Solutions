class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int N = nums.size();
        int maxEle = *max_element(nums.begin(), nums.end());
        int subarrayLen = 0, ans = 1;
        
        for(int i = 0; i < N; i++) {
            if (nums[i] == maxEle) {
                subarrayLen++;
                ans = max(ans, subarrayLen);
            } else {
                subarrayLen = 0;
            }
        }
        return ans;
    }
};