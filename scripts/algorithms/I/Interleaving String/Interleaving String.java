class Solution {
    
    public int dp[][] = new int[1001][1001];
    public boolean isInterleave(String s1, String s2, String s3) {
        int n = s1.length();
        int m = s2.length();
        int t = s3.length();
        int i = 0;
        int j = 0;
        int k = 0;
        
        for(int p=0;p<dp.length;p++)
        {
            for(int q=0;q<dp[0].length;q++)
            {
                dp[p][q] = -1;
            }
        }
        if(n+m!=t)
        {
            return false;
        }
        
        
        
        return find(s1,s2,s3,i,j,k);
    }
    
    public boolean find(String s1,String s2,String s3,int i,int j,int k)
    {
        if(dp[i][j]!=-1)
        {
            if(dp[i][j]==1)
            {
                return true;
            }else{
                return false;
            }
        }
        
        if(i==s1.length() && j==s2.length() && k==s3.length())
        {
            return true;
        }
        boolean x = false;
        boolean y = false;
        
        if(i<s1.length())
        {
            if(s1.charAt(i)==s3.charAt(k))
            {
                 x = find(s1,s2,s3,i+1,j,k+1);
            }
        }
        
        if(j<s2.length())
        {
            if(s2.charAt(j)==s3.charAt(k))
            {
                 y = find(s1,s2,s3,i,j+1,k+1);
            }
        }
        
        if(x||y==true)
        {
            dp[i][j] = 1;
        }else{
            dp[i][j] = 0;
        }
        return x||y;
    }
}
