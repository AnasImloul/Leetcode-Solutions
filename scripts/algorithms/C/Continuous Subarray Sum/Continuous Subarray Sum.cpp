class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_set<int> s;
        int sum = 0;
        int pre = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            int remainder = sum%k;
            if (s.find(remainder) != s.end())
            {
                return true;
            }
            s.insert(pre);
            pre = remainder;
        }
        return false;
    }