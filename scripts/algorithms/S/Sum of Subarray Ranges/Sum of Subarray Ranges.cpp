// Runtime: 237 ms (Top 7.93%) | Memory: 10.4 MB (Top 69.08%)
class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n=nums.size();
        long long res=0;
        for(int i=0;i<n-1;i++){
            int maxi=nums[i], mini=nums[i];
            for(int j=i+1;j<n;j++){
                if(nums[j]>maxi)maxi=nums[j];
                else if(nums[j]<mini)mini=nums[j];
                res+=maxi-mini;
            }
        }
        return res;
    }
};