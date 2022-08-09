class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int ans=0;
        for(int i=1;i<nums.size();i++){
            if(nums[i]!=nums[ans]){
                ans++;
                nums[ans]=nums[i];
            }
        }
        return ans+1;
    }
};
