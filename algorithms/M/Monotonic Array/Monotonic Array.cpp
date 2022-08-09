class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        auto i = find_if_not(begin(nums), end(nums), [&](int a) {return a == nums.front();});
        auto j = find_if_not(rbegin(nums), rend(nums), [&](int a) {return a == nums.back();});
        return is_sorted(--i, end(nums)) or is_sorted(--j, rend(nums));
    }
};
