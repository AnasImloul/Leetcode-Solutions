// Runtime: 45 ms (Top 16.75%) | Memory: 15.4 MB (Top 94.25%)
//Need to consider each ith value as boundary and considering that,
//the max value can be max val - k or i-1 th value + k
//similarly the mn value can be min val + k or ith value - k
//Need to check the difference of max min for all ith positions and minimize this.
//Also check if the calculate min is larger than initial min or not
/*
Example :
     2 4 7 8 and k = 5
-k: -3 -1 2 3
+k: 7 9 12 13

here min value will be 9 -2 = 7 when i = 2 but intital diff between min and max is 6, so the
answer will be 6.
*/

class Solution {
public:
    int smallestRangeII(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int mn = nums.front();
        int mx = nums.back();
        if(mx - mn <= k) return mx - mn;
        int newMn = INT_MAX, newMx = INT_MIN;
        int ans = mx - mn;
        mn = mn + k;
        mx = mx - k;
        for(int i = 1; i < nums.size(); ++i){
            newMn = min(mn, nums[i] - k);
            newMx = max(mx, nums[i-1] + k);
            ans = min(ans, newMx - newMn);
        }
        return ans;
    }

};