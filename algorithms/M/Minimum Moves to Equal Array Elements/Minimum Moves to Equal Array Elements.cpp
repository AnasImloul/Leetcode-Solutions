class Solution {
public:
    int minMoves(vector<int>& nums) {
        
        // sorting the array to get min at the first
        sort(nums.begin(), nums.end());
        int cnt = 0, n = nums.size();
        
        // Now we have to make min equal to every number and keep adding the count
        for(int i = 1; i < n; i++)
            cnt += nums[i] - nums[0];
        
        return cnt;
    }
};
