// Runtime: 52 ms (Top 49.08%) | Memory: 40.20 MB (Top 68.84%)

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int totalSum = 0, maxSum = INT_MIN, curMax = 0, minSum = INT_MAX, curMin = 0;
    for (int x : nums) {
        curMax = max(x, curMax + x);  //update the current max subarray sum
        maxSum = max(maxSum, curMax); //update the overall max subarray sum
        curMin = min(x, curMin + x);  //update the current min subarray sum
        minSum = min(minSum, curMin); //update the overall min subarray sum
        totalSum += x;
    }
    return maxSum > 0 ? max(maxSum, totalSum - minSum) : maxSum;
    }
};
