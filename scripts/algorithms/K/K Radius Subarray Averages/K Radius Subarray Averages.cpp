// Runtime: 487 ms (Top 9.36%) | Memory: 130 MB (Top 70.74%)
class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {

        int n = nums.size();
        vector<int> ans(n , -1);

        if(2 * k + 1 > n) return ans;

        // Simple Sliding Window

        long long int sum = 0;

        // Take a window of size 2 * k + 1
        for(int i =0 ; i < 2 * k + 1 ; i++) {
            sum += nums[i];
        }

        ans[k] = sum / (2 * k + 1);

        // Then slide it untill the end of the window reaches at the end

        for(int i = 2 * k + 1 , j = k + 1, s = 0; i < n ; i++ , j++, s++) {

            sum += nums[i];
            sum -= nums[s];
            ans[j] = sum /(2 * k + 1);

        }

        return ans;
    }
};