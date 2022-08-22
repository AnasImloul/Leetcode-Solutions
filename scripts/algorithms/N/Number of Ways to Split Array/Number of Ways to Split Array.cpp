// Runtime: 298 ms (Top 27.82%) | Memory: 85.6 MB (Top 63.00%)
class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {

        long long sumFromBack(0), sumFromFront(0);
        for (auto& i : nums) sumFromBack += i;

        int n(size(nums)), res(0);
        for (auto i=0; i<n-1; i++) {

            sumFromFront += nums[i]; // sum of the first i + 1 elements
            sumFromBack -= nums[i]; // sum of the last n - i - 1 elements.
            if (sumFromFront >= sumFromBack) res++;
        }
        return res;
    }
};