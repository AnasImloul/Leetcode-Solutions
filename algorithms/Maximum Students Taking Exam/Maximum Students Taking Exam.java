class Solution {
    static final int _inf = (int)1e9;
    public int maxStudents(char[][] seats) {
        int n = seats.length, m = seats[0].length;
        int[] masks = new int[n+1];
        masks[0] = 0;
        for(int i = 0; i < n; i++) {
            char[] s = seats[i];
            int mk = 0;
            for(int j = 0; j < m; j++) {
                if(s[j] == '.') mk |= (1<<j);
            }
            
            masks[i+1] = mk;
        }
        
        int[] dp = new int[1<<m];
        Arrays.fill(dp, -_inf);
        dp[0] = 0;
        for(int i = 1; i <= n; i++) {
            int[] ndp = new int[1<<m];
            Arrays.fill(ndp, -_inf);
            int prev = masks[i-1];
            for(int sm1 = prev; ; sm1 = (sm1-1)&prev) {
                int cur = masks[i];
                for(int sm2 = cur; ; sm2 = (sm2-1)&cur) {
                    if(!isValid(sm1, sm2, m)) continue;
                    ndp[sm2] = Math.max(ndp[sm2], dp[sm1] + Integer.bitCount(sm2));
                    if(sm2 == 0) break;
                }
                
                if(sm1 == 0) break;
            }
            
            dp = ndp;
        }
        
        int ans = 0;
        for(int i = 0; i < 1<<m; i++) ans = Math.max(ans, dp[i]);
        return ans;
    }
    
    public boolean isValid(int m1, int m2, int m) {
        for(int i = 0; i < m; i++) {
            if((m2&1<<i) > 0) {
                if(i-1 >= 0 && (m1&1<<(i-1)) > 0) return false;
                if(i+1 < m && (m1&1<<(i+1)) > 0) return false;
                if(i-1 >= 0 && (m2&1<<(i-1)) > 0) return false;
                if(i+1 < m && (m2&1<<(i+1)) > 0) return false;
            }
        }
        
        return true;
    }
}
