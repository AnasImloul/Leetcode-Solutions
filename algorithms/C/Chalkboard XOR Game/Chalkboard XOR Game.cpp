class Solution {
public:
    bool xorGame(vector<int>& nums) {
        int val = 0; 
        for (auto& x : nums) val ^= x; 
        return val == 0 || size(nums) % 2 == 0; 
    }
};
