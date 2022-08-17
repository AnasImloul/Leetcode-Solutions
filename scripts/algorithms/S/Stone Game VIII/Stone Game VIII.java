class Solution {
    int memo[];
    public int stoneGameVIII(int[] stones) {
        memo = new int[stones.length];
        Arrays.fill(memo, Integer.MIN_VALUE);
        
        int difference = helper(stones, 0);
        return difference;
    }
    
    int helper(int[] stones, int currentIndex) {
        if(currentIndex == stones.length - 1) {
            return 0;
        }
        
        if(memo[currentIndex]!=Integer.MIN_VALUE) return memo[currentIndex];
        int maxDiff = Integer.MIN_VALUE;
        int currentSum = stones[currentIndex];
        for(int i = 1; i<stones.length; i++) {
            if(currentIndex+i>stones.length - 1) continue;
            currentSum += stones[currentIndex+i];
            int tempValue = stones[currentIndex+i];
            stones[currentIndex+i] = currentSum;
            maxDiff = Math.max(maxDiff, currentSum - helper(stones, currentIndex+i));
            stones[currentIndex+i] = tempValue;
        }
        
        memo[currentIndex] = maxDiff;
        return maxDiff;
    }
}
