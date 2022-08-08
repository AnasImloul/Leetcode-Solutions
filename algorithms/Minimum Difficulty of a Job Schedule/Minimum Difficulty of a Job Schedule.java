class Solution {
    // Given an array, cut it into d contiguous subarray and return the minimum sum of max of each subarray.
    public int minDifficulty(int[] jobDifficulty, int d) {
        if(d>jobDifficulty.length){
            return -1;
        }
        
        int[][] memo = new int[d+1][jobDifficulty.length];
        for(int[] m : memo){
            Arrays.fill(m, -1);
        }
        
        return getMinDays(jobDifficulty, d, memo, 0);
    }
    
    private int getMinDays(int[] jobDifficulty, int d, int[][] memo, int idx){
        if(d==1){
            int max=0;
            while(idx < jobDifficulty.length){
                max=Math.max(max, jobDifficulty[idx]);
                idx++;
            }
            return max;
        }
        
        if(memo[d][idx] != -1) return memo[d][idx];
        
        int max=0;
        int res=Integer.MAX_VALUE;
        // [6,5,4,3,2,1], d=5 => we don't want the cut at 4th position in the array because we won't be able to divide it into 5 parts
        for(int i=idx; i<jobDifficulty.length-d+1; i++){
            max = Math.max(max, jobDifficulty[i]);
            res = Math.min(res, max + getMinDays(jobDifficulty, d-1, memo, i+1));
        }
        
        memo[d][idx]=res;
        return memo[d][idx];
    }
}
