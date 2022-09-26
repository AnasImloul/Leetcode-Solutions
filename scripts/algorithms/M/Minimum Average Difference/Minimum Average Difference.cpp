// Runtime: 311 ms (Top 11.84%) | Memory: 78.4 MB (Top 71.03%)
class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {

        int n(size(nums)), minAverageDifference(INT_MAX), index;

        long long sumFromFront(0), sumFromEnd(0);
        for (auto& num : nums) sumFromEnd += num;

        for (int i=0; i<n; i++) {
            sumFromFront += nums[i];
            sumFromEnd -= nums[i];
            int a = sumFromFront / (i+1); // average of the first i + 1 elements.
            int b = (i == n-1) ? 0 : sumFromEnd / (n-i-1); // average of the last n - i - 1 elements.

            if (abs(a-b) < minAverageDifference) {
                minAverageDifference = abs(a-b);
                index = i;
            }
        }
        return index;
    }
};