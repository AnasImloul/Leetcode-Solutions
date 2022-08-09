class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        int n = nums.size();
        
        map<int, int> mp;
        for(int i = 0; i < n; i ++) {
            mp[nums[i]] ++;             // storing the frequency
        }
        
        int ans = 0;
        int pre = 0;
        for (auto i = mp.end(); i != mp.begin(); i--) {
            ans += i -> second + pre;   // total operations
            pre += i -> second;         // maintaing the previous frequency count
        }
        return ans;
    }
};
