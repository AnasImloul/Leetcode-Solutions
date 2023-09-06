// Runtime: 12 ms (Top 87.3%) | Memory: 43.43 MB (Top 64.1%)

class Solution {
    String s;
    int k;
    Integer[][][][][] dp;
    public int numberOfBeautifulIntegers(int low, int high, int k) {
        this.k = k;
        s = Integer.toString(low-1);
        dp = new Integer[s.length()][2][2][21][21];
        int l = f(0,true,true, 0, 0);
        
        s = Integer.toString(high);

        dp = new Integer[s.length()][2][2][21][21];
        int h = f(0,true,true, 0, 0);
        return h-l;
    }
    
    public int f(int i, boolean bound,boolean isZero, int cnt, int rem){
        
        if(i == s.length()){
            if(cnt == 0 && rem == 0){
                return 1;
            } 
            return 0;   
        }
        
        if(dp[i][bound ? 1 : 0][isZero ? 1 : 0][cnt+10][rem] != null) return dp[i][bound ? 1 : 0][isZero ? 1 : 0][cnt+10][rem];
        
        int max = 9;
        
        if(bound){
            max = s.charAt(i) - '0';
        }
        
        int ans = 0;
        for(int j = 0; j<=max; j++){
            int newCnt = cnt;
            if(!isZero || j > 0){
                newCnt += (j%2 == 0 ? 1:-1);
            }            
            ans += f(i+1, bound && j == max, isZero && j==0 , newCnt, (rem*10 + j)%k  );
        }
        return dp[i][bound ? 1 : 0][isZero ? 1 : 0][cnt+10][rem]=  ans;
        
    }
    
}