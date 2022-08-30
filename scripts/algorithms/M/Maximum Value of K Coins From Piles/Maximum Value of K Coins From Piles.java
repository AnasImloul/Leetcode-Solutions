// Runtime: 223 ms (Top 73.40%) | Memory: 55.8 MB (Top 38.07%)
class Solution {
    public int maxValueOfCoins(List<List<Integer>> piles, int k) {
        int n = piles.size();
        int[][] ans = new int[n+1][2001];
        Collections.sort(piles, (List<Integer> a, List<Integer> b) -> b.size() - a.size());
        for(int i = 1; i <= k; i++) {
            for(int j = 1; j <= n; j++) {
                int sizeOfPile = piles.get(j-1).size();
                List<Integer> pile = piles.get(j-1);
                int sum = 0;
                ans[j][i] = ans[j-1][i];
                for(int l = 1; l <= Math.min(i, sizeOfPile); l++) {
                    // Take K from this pile + remaining from previous piles
                    sum += pile.get(l-1);
                    int rem = i - l;
                    ans[j][i] = Math.max(ans[j][i], sum + ans[j-1][rem]);
                }
            }
        }

        return ans[n][k];
    }
}