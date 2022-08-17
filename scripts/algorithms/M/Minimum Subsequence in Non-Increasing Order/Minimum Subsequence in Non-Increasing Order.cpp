class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        
        sort(nums.begin(), nums.end(),greater<int>());
        vector<int> res;
        int sum = 0;
        for(int i: nums)
            sum += i;
        
        int x=0;
        for(int i=0; i<nums.size(); i++)
        {
            x += nums[i];
            sum -= nums[i];
            res.push_back(nums[i]);
            if(x>sum)
                break;
            
        }
        return res;
    }
};