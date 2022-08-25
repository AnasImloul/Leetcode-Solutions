// Runtime: 19 ms (Top 23.87%) | Memory: 13.1 MB (Top 34.84%)
class Solution {
public:
    bool xorGame(vector<int>& nums) {
        int val = 0;
        for (auto& x : nums) val ^= x;
        return val == 0 || size(nums) % 2 == 0;
    }
};