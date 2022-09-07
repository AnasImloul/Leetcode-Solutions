// Runtime: 311 ms (Top 8.76%) | Memory: 8.6 MB (Top 54.12%)
class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        int ans=0;
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                for(int k=j+1;k<nums.size();k++){
                    if((nums[j]-nums[i])==diff && (nums[k]-nums[j])==diff){
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};