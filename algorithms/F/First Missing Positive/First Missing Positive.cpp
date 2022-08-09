class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for(int i=0; i<n; i++){
            if(nums[i]==i+1 || nums[i]<=0 || nums[i]>n) continue;
            while(nums[i]!=i+1 && nums[i]>0 && nums[i]<=n && nums[nums[i]-1] != nums[i]){
                swap(nums[i],nums[nums[i]-1]);
            }
        }
        int ans = -1;
        for(int i=0; i<n; i++){
            if(nums[i]!=i+1){
                ans = i+1;
                break;
            }
        }
        if(ans==-1){
            return n+1;
        }else{
            return ans;
        }
    }
};
