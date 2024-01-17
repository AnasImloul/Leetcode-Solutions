// Runtime: 27 ms (Top 92.02%) | Memory: 45.10 MB (Top 27.31%)

class Solution {
    int res = 0;
    public int bestTeamScore(int[] scores, int[] ages) {
        int len = scores.length;
        int[][] team = new int[len][2];
        for (int i = 0; i < len; i++) {
            team[i][0] = ages[i];
            team[i][1] = scores[i]; // team is [age, score]
        }
		// double sort first by age then by score, then we can traverse from young to old
        Arrays.sort(team, (a, b) -> a[0] != b[0] ? a[0] - b[0] : a[1] - b[1]);
        
        int[] dp = new int[len];
        // dp is the max sum for all sequences (not necessarily consecutive) ending in current idx
        dp[0] = team[0][1];
        for (int i = 1; i < len; i++) {
            int max = team[i][1]; // At least it could start a new sequence by itself without extend
			// for each current idx, go visit all previous index to grow the sequences
            for (int j = 0; j < i; j++) {
                if (team[i][1] >= team[j][1]) {
                    max = Math.max(max, dp[j] + team[i][1]);
                }
            }
            dp[i] = max;
        }
      
        int res = 0;
        for (int num : dp) {
            res = Math.max(res, num);
        }
        
        return res;
    }
}
