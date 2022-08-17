class Solution {
public:
    int specialArray(vector<int>& nums) {
        int v[102];
        memset(v, 0, sizeof v);
        for (const auto &n : nums) {
            ++v[n > 100 ? 100 : n];
        }
        for (int i = 100; i > 0; --i) {
            v[i] = v[i + 1] + v[i];
            if (v[i] == i)
                return i;
        }
        return -1;
    }
};
