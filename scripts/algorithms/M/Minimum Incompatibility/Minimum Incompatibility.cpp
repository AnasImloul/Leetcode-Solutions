// Runtime: 1882 ms (Top 19.05%) | Memory: 14.8 MB (Top 60.00%)
const int INF = 1e9;

class Solution {
public:
    int minimumIncompatibility(vector<int>& nums, int k) {
        int i, n = nums.size(), subset_size = n / k;
        sort(nums.begin(), nums.end());

        // Pre-calculate the range (max - min) for each subset of nums
        // Note that there are (1 << n) subsets (i.e. 2 ^ n subsets) of an array of size n
        vector<int> range(1 << n, INF);

        // Each mask represents every possible subset of elements in num (so, "mask" == "subset")
        // Specifically, if the bit at position i of mask is set to 1, then we include that number in the subset
        for(int mask = 1; mask < (1 << n); mask++) {
            int small = -1, big = -1;
            bool dup = false;

            // Identify elements that belong to this subset, find the largest & smallest, check for duplicates
            // Recall that this array was sorted in the beginning of the function
            for(i=0; i<n && !dup; i++)
                if(mask & (1 << i)) {
                    if(small == -1)
                        small = nums[i];
                    if(big == nums[i])
                        dup = true;
                    big = nums[i];
                }

            // If no duplicates were found, then calculate and store the range for this subset
            if(!dup)
                range[mask] = big - small;
        }

        vector<int> dp(1 << n, INF);
        dp[0] = 0;

        // Iterate over every mask (i.e. subset) and calculate its minimum sum
        for(int mask = 1; mask < (1 << n); mask++) {

            // Iterate over every submask for current mask
            for(int submask = mask; submask; submask = (submask - 1) & mask) {

                // Check that submask has the right number of elements
                if(__builtin_popcount(submask) == subset_size)
                    // Note that mask = submask + (mask ^ submask)
                    // ==> i.e., mask ^ submask = mask - submask
                    // In other words, (mask ^ submask) represents those elements in mask that are not in submask
                    dp[mask] = min(dp[mask], range[submask] + dp[mask ^ submask]);
            }
        }
        // dp.back() == dp[(1 << n) - 1];
        return dp.back() >= INF ? -1 : dp.back();
    }
};