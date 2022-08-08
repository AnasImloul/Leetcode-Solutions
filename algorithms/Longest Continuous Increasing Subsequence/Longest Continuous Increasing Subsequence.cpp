class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int maxLength = 1;
        int currLength = 1;
        int i = 0;
        int j = 1;
        
        while(j<nums.size()){
            if(nums[j] > nums[i]){
                currLength++;
                i++;
                j++;
                if(currLength > maxLength) maxLength = currLength;
            } else{
                currLength = 1;
                i = j;
                j++;
            }
        }
        return maxLength;
    }
};
