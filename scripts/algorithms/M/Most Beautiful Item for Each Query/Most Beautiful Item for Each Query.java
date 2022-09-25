// Runtime: 65 ms (Top 93.33%) | Memory: 101.6 MB (Top 93.33%)
class Solution {
    public int[] maximumBeauty(int[][] items, int[] queries) {
        int n = queries.length, m = items.length;
        Arrays.sort(items, Comparator.comparingInt(o -> o[0]));
        int[] ans = new int[n];

        for (int i = 0; i < m; i++)
            items[i][1] = Math.max(items[i][1], items[i > 0? i - 1 : 0][1]);

        int j = 0;
        for (int q : queries){
            int lo = -1, hi = m - 1; //pad lo = -1 to mark no result
            while(lo < hi){
                int mid = lo + (hi - lo) / 2 + 1;
                if (q >= items[mid][0]) lo = mid;
                else hi = mid - 1;
            }
            ans[j++] = lo == -1? 0 : items[lo][1];
        }

        return ans;
    }
}