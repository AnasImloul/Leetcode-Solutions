// Runtime: 211 ms (Top 76.70%) | Memory: 88.3 MB (Top 35.46%)
class Solution {
public:
    int minimumDeletions(vector<int>& nums) {

        int indmin, indmax, mini(INT_MAX), maxi(INT_MIN), n(nums.size());

        for (int i=0; i<n; i++)
        {
            if (maxi < nums[i]) maxi = nums[i], indmax = i;
            if (mini > nums[i]) mini = nums[i], indmin = i;
        }

        int before(min(indmin, indmax)), after(max(indmin, indmax));
        return min(before+1 + min(n-after, after-before), n-after + min(before+1, after-before));
    }
};