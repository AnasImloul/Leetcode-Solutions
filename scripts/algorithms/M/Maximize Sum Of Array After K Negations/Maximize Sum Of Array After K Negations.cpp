// Runtime: 4 ms (Top 87.70%) | Memory: 8.9 MB (Top 92.33%)
class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {

        int neg = 0, small = INT_MAX;

        for (auto &i: nums) small = min(abs(i), small), neg += i < 0;

        if (k >= neg) return reduce(begin(nums), end(nums), 0, [](int &a, int &b) {return abs(a) + abs(b);})
                             + (((k - neg) % 2) ? -2 * small : 0);

        nth_element(begin(nums), begin(nums) + k - 1, end(nums));

        return reduce(begin(nums), begin(nums) + k, 0, [](int &a, int &b) {return abs(a) + abs(b);})
               + reduce(begin(nums) + k, end(nums));
    }
};