// Runtime: 28 ms (Top 55.58%) | Memory: 124.3 MB (Top 45.11%)
class Solution {
    public long maximumImportance(int n, int[][] roads) {
        long ans = 0, x = 1;
        long degree[] = new long[n];
        for(int road[] : roads){
            degree[road[0]]++;
            degree[road[1]]++;
        }
        Arrays.sort(degree);
        for(long i : degree) ans += i * (x++) ;
        return ans;
    }
}