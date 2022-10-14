// Runtime: 121 ms (Top 22.74%) | Memory: 30.1 MB (Top 48.29%)
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