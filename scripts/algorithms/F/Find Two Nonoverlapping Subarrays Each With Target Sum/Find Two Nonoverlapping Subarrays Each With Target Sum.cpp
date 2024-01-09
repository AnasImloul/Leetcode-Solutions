// Runtime: 82 ms (Top 97.16%) | Memory: 84.80 MB (Top 83.89%)

class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int sum = 0, n = arr.size(), ans = INT_MAX, len = INT_MAX;
        vector<int> min_len(n, INT_MAX);
        int start = 0;
        for (int end = 0; end < n; end++) {
            sum += arr[end];
            //shrink the window
            while (sum > target) {
                sum -= arr[start];
                start++;
            }
            if (sum == target) {
                //update the min_len
                int curLen = end - start + 1;
                if (start > 0 && min_len[start-1] != INT_MAX) {
                    ans = min(ans, curLen + min_len[start-1]);
                }
                len = min(curLen, len); 
            }
            min_len[end] = len;
        }
        return ans == INT_MAX ? -1 : ans;
    }
};
