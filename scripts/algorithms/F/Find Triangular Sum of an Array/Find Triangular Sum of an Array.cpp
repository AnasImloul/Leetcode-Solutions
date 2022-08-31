// Runtime: 404 ms (Top 62.14%) | Memory: 18.6 MB (Top 88.13%)
class Solution {
public:
    int triangularSum(vector<int>& nums) {
        int n=nums.size();
        for(int i=n-1;i>=1;i--){
            for(int j=0;j<i;j++){
                nums[j]=(nums[j]+nums[j+1])%10;
            }
        }
        return nums[0];
    }
};