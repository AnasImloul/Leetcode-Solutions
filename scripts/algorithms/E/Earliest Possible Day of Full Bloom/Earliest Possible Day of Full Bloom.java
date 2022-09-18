// Runtime: 168 ms (Top 19.82%) | Memory: 126.2 MB (Top 22.91%)
class Solution {
    public int earliestFullBloom(int[] plantTime, int[] growTime) {
        int n = plantTime.length;
        int[][] plants = new int[n][2];
        int totalPlantTime = 0;
        for (int i = 0; i < n; i++) {
            plants[i] = new int[]{plantTime[i], growTime[i]};
            totalPlantTime += plantTime[i];
        }
        // Sort plants by grow time.
        // The plant with fewer grow time can be planted at the end.
        Arrays.sort(plants, (a, b) -> a[1] - b[1]);
        // Max grow + plant time
        int maxTime = 0;
        for (int[] plant : plants) {
            maxTime = Math.max(maxTime, totalPlantTime + plant[1]);
            // After putting this plant at the end of the chain,
            // we can take the current plant time out of the total plant time
            totalPlantTime -= plant[0];
        }
        return maxTime;
    }
}