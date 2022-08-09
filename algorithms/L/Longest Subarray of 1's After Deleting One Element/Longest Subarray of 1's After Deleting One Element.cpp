class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int x=0,y=0,cnt=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1){
                x++;
            }
            else if(nums[i]==0){
               cnt=max(cnt,x+y);
                y=x;
                x=0;
            }
            if(i==nums.size()-1){
                cnt=max(cnt,x+y);
            }
        }
        if(cnt==nums.size())return cnt-1;
        return cnt;
    }
};
