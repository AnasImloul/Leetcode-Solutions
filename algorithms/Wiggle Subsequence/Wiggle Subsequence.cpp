class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n=nums.size();
        if(n==1){
            return 1;
        }
        if(n==2 && nums[0]!=nums[1]){
            return 2;
        }
        if(n==2 && nums[0]==nums[1]){
            return 1;
        }
        char c;
        int dp[n];
        dp[0]=1;
        int p=1;
        for(p=1;p<n;p++){
            if(nums[p]==nums[p-1]){
                dp[p]=1;
            }
            else{
                break;
            }
        }
        if(p==n){
            return dp[n-1];
        }
        if(nums[p-1]<nums[p]){
            c='d';
        }
        else{
            c='i';
        }
        dp[p-1]=1;
        dp[p]=2;
        for(int i=p+1;i<n;i++){
            if(c=='d'){
                if(nums[i]<nums[i-1]){
                    dp[i]=dp[i-1]+1;
                    c='i';
                }
                else{
                    dp[i]=dp[i-1];
                }
            }
            else if(c=='i'){
                if(nums[i]>nums[i-1]){
                    dp[i]=dp[i-1]+1;
                    c='d';
                }
                else{
                    dp[i]=dp[i-1];
                }
            }
        }
        return dp[n-1];
    }
};