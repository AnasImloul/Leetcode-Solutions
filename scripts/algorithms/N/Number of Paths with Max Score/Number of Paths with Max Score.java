// Runtime: 42 ms (Top 12.33%) | Memory: 44.2 MB (Top 60.27%)
class Solution {
    public int[] pathsWithMaxScore(List<String> board) {
        int M = (int)1e9+7;
        int m = board.size();
        int n = board.get(0).length();
        int[][] dp = new int[m][n];
        int[][] ways = new int[m][n];
        ways[0][0]=1; // base case.
        int[][] dirs = {{-1, 0}, {0, -1}, {-1, -1}}; // all 3 ways where we can travel.
        for (int i=0;i<m;i++){
            for (int j=0;j<n;j++){
                if (board.get(i).charAt(j)=='X'){
                    continue;
                }
                int cur = Character.isDigit(board.get(i).charAt(j))?board.get(i).charAt(j)-'0':0;
                for (int[] d : dirs){
                    int x = d[0]+i;
                    int y = d[1]+j;
                    if (x < 0 || y < 0 || ways[x][y] == 0){
                        continue;
                    }
                    if (cur+dp[x][y]>dp[i][j]){
                        dp[i][j]=cur+dp[x][y];
                        ways[i][j]=0;
                    }
                    if (cur+dp[x][y]==dp[i][j]){
                        ways[i][j]+=ways[x][y];
                        ways[i][j]%=M;
                    }
                }
            }
        }
        return new int[]{dp[m-1][n-1], ways[m-1][n-1]};
    }
}