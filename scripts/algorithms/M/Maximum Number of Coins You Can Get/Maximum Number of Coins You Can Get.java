// Runtime: 43 ms (Top 37.50%) | Memory: 77.8 MB (Top 8.89%)
class Solution {
    public int maxCoins(int[] piles) {
        Arrays.sort(piles);
        int s=0,n=piles.length;
        for(int i=n/3;i<n;i+=2)
            s+=piles[i];
        return s;
    }
}