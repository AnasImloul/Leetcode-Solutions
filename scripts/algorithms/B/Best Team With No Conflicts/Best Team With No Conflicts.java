class Solution {
    public int bestTeamScore(int[] scores, int[] ages) {
        int n = scores.length;
        // combine the arrays for ease in processing
        int[][] combined = new int[n][2];
        for (int i = 0; i < n; i++) {
            combined[i][0] = ages[i];
            combined[i][1] = scores[i];
        }
        
        // sort the arrays by age and scores
        Arrays.sort(combined, (a, b) -> a[0] == b[0] ? a[1] - b[1] : a[0] - b[0]);
        
		// find max answer between all possible teams
        int ans = 0;
        for (int i = 0; i < n; i++)
            ans = Math.max(ans, recurse(combined, i));
        
        return ans;
    }
    
    private int recurse(int[][] combined, int cur) {
        // base case
        if (cur == -1)
            return 0;
        
        // try teaming player with others if no conflict found
        int ans = 0;
        for (int prev = 0; prev < cur; prev++) {
            if (combined[cur][0] == combined[prev][0] || combined[cur][1] >= combined[prev][1])
                ans = Math.max(ans, recurse(combined, prev));
        }
        
        // add score of current player
        ans += combined[cur][1];
        return ans;
    }
}
