class Solution {
public:
    vector<int> groupStrings(vector<string>& words) {
        unordered_map<int, int> nums;
        for (const auto& w : words) {
            int x = accumulate(begin(w), end(w), 0,
                               [](int s, char c) { return s|(1<<(c-'a')); });
            nums[x]++;
        }
        int ngroups = 0, largest = 0;
        for (auto [x, count] : nums) {
            if (count) {
                ngroups++;
                largest = max(largest, dfs(x, nums));
            }
        }
        return {ngroups, largest};
    }
private:
    int dfs(int x, unordered_map<int, int>& nums) {
        int cur = 0;
        if (auto it = nums.find(x); it != end(nums) && it->second) {
            cur += it->second;
            it->second = 0;
            for (size_t m = 1; m < 1<<26; m <<= 1) {
                cur += dfs(x^m, nums);
                for (size_t m2 = 1; m2 < 1<<26; m2 <<= 1)
                    if (x&m && !(x&m2))
                        cur += dfs(x^m^m2, nums);
            }
        }
        return cur;
    }
};
