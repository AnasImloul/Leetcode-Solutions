// Runtime: 4 ms (Top 46.95%) | Memory: 72.5 MB (Top 49.39%)
class Solution {
    public int addRungs(int[] rungs, int dist) {
        int ans = 0;
        for (int i=0 ; i<rungs.length ; i++) {
            int d = (i==0) ? rungs[i] : rungs[i] - rungs[i-1];
            if ( d > dist ) {
                ans += d/dist;
                ans += ( d%dist == 0 ) ? -1 : 0;
            }
        }
        return ans;
    }
}