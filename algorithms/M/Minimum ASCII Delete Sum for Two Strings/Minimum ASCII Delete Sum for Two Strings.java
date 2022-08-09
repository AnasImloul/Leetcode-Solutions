class Solution {
    public int minimumDeleteSum(String s1, String s2) {
        int m=s1.length();
        int n=s2.length();
        
        Integer [][]dp=new Integer[m][n];
        
        return helper(s1,s2,m,n,0,0,dp);
    }
    
    public int helper(String s1, String s2, int m, int n,int i1, int i2, Integer [][]dp){
        if(i1==m){
            
            int sum=0;
            for(int j=i2;j<n;j++){
                sum+=(int)s2.charAt(j);
            }
            
            return sum;
            
        }else if(i2==n){
            
            int sum=0;
            for(int j=i1;j<m;j++){
                sum+=(int)s1.charAt(j);
            }
            
            return sum;
            
        }else if(s1.charAt(i1)==s2.charAt(i2)){
            return helper(s1,s2,m,n,i1+1,i2+1,dp);
        }else if(dp[i1][i2]!=null){
            return dp[i1][i2];
        }else{
            int val1=(int)s1.charAt(i1);
            int val2=(int)s2.charAt(i2);
            
            int res1=val1+helper(s1,s2,m,n,i1+1,i2,dp);
            int res2=val2+helper(s1,s2,m,n,i1,i2+1,dp);
            int res3=val1+val2+helper(s1,s2,m,n,i1+1,i2+1,dp);
            
            dp[i1][i2]=Math.min(res1,Math.min(res2,res2));
            return dp[i1][i2];
        }
    }
}
