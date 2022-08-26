// Runtime: 42 ms (Top 86.81%) | Memory: 28.8 MB (Top 72.20%)
class Solution {
public:

    int lessequal(vector<int>& nums, int goal) {

        if(goal < 0) return 0;

        int n = nums.size();
        int i = 0, j = 0;
        int sum = 0;
        int ans = 0;

        while(j < n) {

            sum += nums[j];

            while(sum > goal) {
                sum -= nums[i];
                i++;
            }
            ans += j-i+1;
            j++;
        }

        return ans;
    }

    int numSubarraysWithSum(vector<int>& nums, int goal) {

        return lessequal(nums, goal) - lessequal(nums, goal - 1);
    }
};

// our function is giving number of subarrays with sum less or equal to goal.
// upvote if it helps.