// Runtime: 0 ms (Top 100.0%) | Memory: 39.12 MB (Top 86.0%)

class Solution {
    public int pivotInteger(int n) {
        int ans = (n * n + n ) /2;
        int sq = (int)Math.sqrt(ans);
        if(sq * sq == ans)return sq;
        else return -1;
    }
}