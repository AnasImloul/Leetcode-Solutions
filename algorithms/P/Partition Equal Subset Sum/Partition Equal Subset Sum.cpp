 class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        for(int i = 0;i<n;i++)
            sum = sum + nums[i];
        cout<<sum;
        
        if(sum % 2 == 0){
            int s = sum/2;
            int t[n+1][s+1];
            for(int i = 0; i<s+1;i++)
                t[0][i] = false;
            for(int i = 0;i<n+1;i++)
                t[i][0] = true;
            
            for(int i =1;i<n+1;i++){
                for(int j = 1; j<s+1;j++){
                    if(nums[i-1] <= j)
                        t[i][j] = t[i-1][j-nums[i-1]] || t[i-1][j];
                    else
                        t[i][j] = t[i-1][j];
                }
            }
            return t[n][s];
        }else
            return false;
    }
};
