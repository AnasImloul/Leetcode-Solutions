// Runtime: 20 ms (Top 58.35%) | Memory: 143.3 MB (Top 38.21%)
class Solution {
    // O(sLen + queries.length) time, O(sLen) space
    public int[] platesBetweenCandles(String s, int[][] queries) {
        int sLen = s.length();
        // cumulative number of plates from the left
        int[] numberOfPlates = new int[sLen+1];
        for (int i=0; i<sLen; i++) {
            numberOfPlates[i+1] = numberOfPlates[i] + (s.charAt(i) == '*' ? 1 : 0);
        }
        // closest candle to the left
        int[] candleToTheLeft = new int[sLen];
        int cand = -1;
        for (int i=0; i<sLen; i++) {
            if (s.charAt(i) == '|') {
                cand = i;
            }
            candleToTheLeft[i] = cand;
        }
        // closest candle to the right
        int[] candleToTheRight = new int[sLen];
        cand = -1;
        for (int i=sLen-1; i>=0; i--) {
            if (s.charAt(i) == '|') {
                cand = i;
            }
            candleToTheRight[i] = cand;
        }
        // for each query - count the number of plates between closest candles
        int[] res = new int[queries.length];
        for (int i=0; i<queries.length; i++) {
            int left = candleToTheRight[queries[i][0]];
            int right = candleToTheLeft[queries[i][1]];
            if (left == -1 || right == -1 || left >= right) {
                res[i] = 0;
            } else {
                res[i] = numberOfPlates[right+1] - numberOfPlates[left];
            }
        }
        return res;
    }
}