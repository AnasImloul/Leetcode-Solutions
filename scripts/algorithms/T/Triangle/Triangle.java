// Runtime: 6 ms (Top 41.54%) | Memory: 43.9 MB (Top 66.49%)
class Solution {
    public int minimumTotal(List<List<Integer>> triangle) {

        int n = triangle.get( triangle.size() - 1).size();
        int dp[] = new int[n + 1];

        for(int i = triangle.size() - 1; i>=0; i--)
        {
            for(int j = 0; j<triangle.get(i).size(); j++)
                dp[j] = triangle.get(i).get(j) + Math.min(dp[j], dp[j+1]);
        }

        return dp[0];

    }
}