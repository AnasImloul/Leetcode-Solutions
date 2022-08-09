class Solution {
    public int findKthNumber(int m, int n, int k) {
        int lo = 1;
        int hi = m * n;
        
        while(lo < hi){
            int mid = lo + (hi - lo) / 2;
            
            if(count(mid, m, n) < k){
                lo = mid + 1;
            } else if(count(mid, m, n) >= k){
                hi = mid;
            }
        }
        return lo;
    }
    private int count(int mid, int m, int n){
        int ans = 0;
        for(int i = 1; i <= m; i++){
            int res = Math.min(mid / i, n);
            ans += res;
        }
        return ans;
    }
}
