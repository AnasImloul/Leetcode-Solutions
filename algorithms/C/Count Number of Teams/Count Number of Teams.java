// Smaller * Larger Solution
// sum of #smaller * #larger
// Time complexity: O(N^2)
// Space complexity: O(1)
class Solution {
    public int numTeams(int[] rating) {
        final int N = rating.length;
        int res = 0;
        for (int i = 1; i < N; i++) {
            res += smaller(rating, i, -1) * larger(rating, i, 1);
            res += larger(rating, i, -1) * smaller(rating, i, 1);
        }
        return res;
    }
    
    private int smaller(int[] rating, int i, int diff) {
        int t = rating[i], count = 0;
        i += diff;
        while (i >= 0 && i < rating.length) {
            if (rating[i] < t) count++;
            i += diff;
        }
        return count;
    }
    
    private int larger(int[] rating, int i, int diff) {
        int t = rating[i], count = 0;
        i += diff;
        while (i >= 0 && i < rating.length) {
            if (rating[i] > t) count++;
            i += diff;
        }
        return count;
    }
}
