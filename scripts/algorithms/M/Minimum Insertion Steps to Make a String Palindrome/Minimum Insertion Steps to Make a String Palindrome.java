// Runtime: 40 ms (Top 71.55%) | Memory: 43.3 MB (Top 97.03%)
class Solution {
    public int minInsertions(String s) {
        StringBuilder sb = new StringBuilder(s);
         String str = sb.reverse().toString();
        int m=s.length();
        int n=str.length();
         System.out.println(str);
        return LCS(s,str,m,n);

    }
    public int LCS(String x, String y,int m,int n){
        int [][] t = new int [m+1][n+1];
        for(int i=0;i<m+1;i++){
           for(int j=0;j<n+1;j++){
            if(m==0||n==0){t[m][n]=0;}
           }
        }
        for(int i=1;i<m+1;i++){
            for(int j=1;j<n+1;j++){
                if(x.charAt(i-1)==y.charAt(j-1)){
                    t[i][j]=1+t[i-1][j-1];
                }
                else{t[i][j]=Math.max(t[i][j-1],t[i-1][j]);
                }
            }
        }
        return y.length()-t[m][n];
    }
}