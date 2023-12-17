// Runtime: 40 ms (Top 12.52%) | Memory: 44.60 MB (Top 24.53%)

class Solution {
    public int maximalNetworkRank(int n, int[][] roads) {
        int[] degree = new int[n];
        Set<String> roadSet = new HashSet<>();
        
        for (int[] road : roads) {
            degree[road[0]]++;
            degree[road[1]]++;
            roadSet.add(road[0] + "," + road[1]);
            roadSet.add(road[1] + "," + road[0]);
        }

        int maxRank = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                int rank = degree[i] + degree[j];
                if (roadSet.contains(i + "," + j)) {
                    rank--;
                }
                maxRank = Math.max(maxRank, rank);
            }
        }

        return maxRank;
    }
}
