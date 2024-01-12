// Runtime: 0 ms (Top 100.0%) | Memory: 42.30 MB (Top 39.5%)

class Solution {
    public int minHeightShelves(int[][] books, int shelfWidth) {
        int memo[] = new int[books.length];
        return recur(books, shelfWidth, 0, memo);
    }
    
    private int recur(int[][] books, int shelfWidth, int index, int[] memo) {
        
        if (index == books.length) {
            return 0;
        }
        
        if (memo[index] > 0) {
            return memo[index];
        }
        int ans = Integer.MAX_VALUE;
        int height = 0;
        int width = 0;
        
        for (int i = index; i < books.length; i++) {
            width += books[i][0];
            
            if (width > shelfWidth) {
                break;
            }
            height = Math.max(height, books[i][1]);
            ans = Math.min(ans, height + recur(books, shelfWidth, i + 1, memo));
        }
        return memo[index] = ans;
    }
}
