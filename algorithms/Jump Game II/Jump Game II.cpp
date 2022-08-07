class Solution {
public:
    int jump(vector<int>& nums) {
        int step=0, jump_now;
        int ans = 0, index=0, i, mx;
        if(nums.size()==1) return ans;
        while(index+step<nums.size()-1){
            ans++;
            step = nums[index];
            if(index+step>=nums.size()-1) break;
            mx = 0;
            for(i=1; i<=step; i++){
                if(i+nums[index+i]>mx){
                    mx = i+nums[index+i];
                    jump_now = i;
                }
            }
            step = 0;
            index += jump_now;
        }
        return ans;
    }
};
