// Runtime: 447 ms (Top 28.83%) | Memory: 99.1 MB (Top 14.78%)

#define ll long long

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        // sorting so that can easily find the optimal window
        sort(nums.begin(), nums.end());

        // left - left pointer of window
        // right - right pointer of window
        int left = 0, right = 0, ans = 1;
        ll total = 0, n = nums.size();
        while(right < n){
            // total - total sum of elements in the window
            total += nums[right];

            // Checking if the we can achieve elements in this window
            // If it exceeds k then shrinking the window by moving left pointer
            // For optimal we will make all elements in the array equal to
            // the maximum value element
            while((1ll)*(right - left + 1)*nums[right] - total > k){
                total -= nums[left];
                left++;
            }

            ans = max(ans, right - left + 1);
            right++;
        }
        return ans;
    }
};
