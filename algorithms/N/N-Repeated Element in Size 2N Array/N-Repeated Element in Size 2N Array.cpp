class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        unordered_map<int, int> mp;
        for(auto it : nums) mp[it]++;
        int n;
        for(auto it : mp) {
            if(it.second == nums.size() / 2) {
                n = it.first;
                break;
            }
        }
        return n;
    }
};
