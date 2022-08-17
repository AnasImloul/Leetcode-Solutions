class Solution {
    public String shortestCommonSupersequence(String str1, String str2) {
        int m=str1.length();
        int n=str2.length();
        int[][] dp=new int[m+1][n+1];
        for(int i=1;i<m+1;i++){
            for(int j=1;j<n+1;j++){
                if(str1.charAt(i-1)==str2.charAt(j-1)){
                    dp[i][j]=1+dp[i-1][j-1];
                }else{
                    dp[i][j]=Math.max(dp[i][j-1],dp[i-1][j]);
                }
            }
        }
        int i=m,j=n;
        String res="";
        while(i>0 && j>0){
            if(str1.charAt(i-1)==str2.charAt(j-1)){
                res=str1.charAt(i-1)+res;
                i--;
                j--;
            }else if(dp[i-1][j]>dp[i][j-1]){
                res=str1.charAt(i-1)+res;
                i--;
            }else{
                res=str2.charAt(j-1)+res;
                j--;
            }
        }
        while(i>0){
            res=str1.charAt(i-1)+res;
            i--;
        }
        while(j>0){
            res=str2.charAt(j-1)+res;
            j--;
        }
        return res;
    }
}
