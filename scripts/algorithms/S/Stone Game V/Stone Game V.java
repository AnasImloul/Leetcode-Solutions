// Runtime: 299 ms (Top 83.10%) | Memory: 42.5 MB (Top 97.18%)
class Solution {
    int dp[][];
    public int fnc(int a[], int i, int j, int sum){
        //System.out.println(i+" "+j);
        int n=a.length;
        if(i>j)
            return 0;
        if(j>n)
            return 0;
        if(i==j){
            dp[i][j]=-1;
            return 0;
        }
        if(dp[i][j]!=0)
            return dp[i][j];

   int temp=0;
        int ans=Integer.MIN_VALUE;

        for(int index=i;index<=j;index++){
            temp+=a[index];
            if(temp>sum-temp){
                ans=Math.max(ans,((sum-temp)+fnc(a,index+1,j,sum-temp)));
            }
            else if(temp<sum-temp){
                ans=Math.max(ans,temp+fnc(a,i,index,temp));
            }
            else
                ans=Math.max(ans,Math.max(sum-temp+fnc(a,index+1,j,sum-temp),temp+fnc(a,i,index,temp)));
        }
        dp[i][j]=ans;
        return dp[i][j];
    }
    public int stoneGameV(int[] stoneValue) {
        int n=stoneValue.length;
        int sum=0;
        for(int ele:stoneValue)
            sum+=ele;
        dp= new int[n][n];
        return fnc(stoneValue,0,n-1,sum);

    }
}