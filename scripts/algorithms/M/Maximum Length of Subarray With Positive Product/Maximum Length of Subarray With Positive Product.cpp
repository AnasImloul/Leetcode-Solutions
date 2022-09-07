// Runtime: 295 ms (Top 5.06%) | Memory: 57.9 MB (Top 75.87%)
class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int ans = 0;
        int lprod = 1,rprod = 1;
        int llen = 0, rlen = 0;
        int n = nums.size();
        for(int i = 0 ; i < n ; i++){
            lprod *= nums[i] != 0 ? nums[i]/abs(nums[i]) : 0;
            rprod *= nums[n-1-i] != 0 ? nums[n-1-i]/abs(nums[n-1-i]) : 0;
            if(lprod != 0) llen ++;
            if(rprod != 0) rlen ++;
            if(lprod > 0) ans = max(ans,llen);
            if(rprod > 0) ans = max(ans,rlen);
            if(lprod == 0) {
                lprod = 1;
                llen = 0;
            }
            if(rprod == 0){
                rlen = 0;
                rprod = 1;
            }
        }
        return ans;
    }
};