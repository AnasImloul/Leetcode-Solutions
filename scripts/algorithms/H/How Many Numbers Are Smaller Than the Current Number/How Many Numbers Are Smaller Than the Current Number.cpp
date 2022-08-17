class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> ans;
        int i,j,size,count;
        size = nums.size();
        for(i = 0; i<size; i++){
            count = 0;
            for(j = 0;j<size;j++){
                if(nums[j]<nums[i]) count++;
            }
            ans.push_back(count);
        }
        return ans;
    }
};
