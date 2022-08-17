class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int ans=0;
        int size=nums.size();
        if(target>nums[size-1]){
            return nums.size();
        }
        for(int i=0;i<nums.size();i++){
            while(target>nums[i]){
                if(target==nums[i]){
                    return i; 
                    i++;
                }
                ans=i+1;
                i++;
            }
            
        }
        return ans;
    }
};
