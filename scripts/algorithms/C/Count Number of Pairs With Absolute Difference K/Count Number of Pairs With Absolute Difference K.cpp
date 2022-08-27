// Runtime: 45 ms (Top 15.79%) | Memory: 14.5 MB (Top 9.64%)
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