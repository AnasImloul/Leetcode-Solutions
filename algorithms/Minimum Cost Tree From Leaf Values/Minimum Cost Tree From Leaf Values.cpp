class Solution {
public:
    int dp[40][40]={0};
    int solve(vector<int> arr,int start,int end)
    {
        if(start==end)
            return 0;
        if(dp[start][end]!=0)
            return dp[start][end];
        int mn=INT_MAX;
        for(int i=start;i<=end-1;i++)
        {
            int left=solve(arr,start,i);
            int right=solve(arr,i+1,end);
            int temp=left+right+*max_element(arr.begin()+start,arr.begin()+i+1) * *max_element(arr.begin()+i+1,arr.begin()+end+1);
            mn=min(mn,temp);
            
        }
        return dp[start][end]=mn;
    }
    int mctFromLeafValues(vector<int>& arr)
    {
        return solve(arr,0,arr.size()-1);
    }
};
//if you like the solution plz upvote.