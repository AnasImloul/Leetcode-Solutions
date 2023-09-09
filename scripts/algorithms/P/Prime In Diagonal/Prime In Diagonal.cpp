// Runtime: 75 ms (Top 98.7%) | Memory: 35.60 MB (Top 74.4%)

class Solution {
public:
    bool check(int x){
        if(x==1)return false;
        for(int i = 2; i*i<=x; i++){
            if(x%i==0)return false;
        }
        return true;
    }
    int diagonalPrime(vector<vector<int>>& nums) {
        int i,ans=0,n=nums.size();
        for(i = 0; i < n; i++){
            if(check(nums[i][i]) && nums[i][i]>ans){
                ans = nums[i][i];
            }
            if(check(nums[i][n-1-i]) && nums[i][n-1-i]>ans){
                ans = nums[i][n-1-i];
            }
        }
        return ans;
    }
};