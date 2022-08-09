class Solution {
    public int maxCoins(int[] piles) {
        Arrays.sort(piles);
        int s=0,n=piles.length;
        for(int i=n/3;i<n;i+=2)
            s+=piles[i];
        return s;
    }
}