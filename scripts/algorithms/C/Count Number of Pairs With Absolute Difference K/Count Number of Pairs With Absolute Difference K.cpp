// Runtime: 18 ms (Top 82.67%) | Memory: 14.6 MB (Top 9.93%)
class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        int res = 0;

        for (auto num : nums) {
            res += freq[num+k] + freq[num-k];
            freq[num]++;
        }

        return res;
    }
};