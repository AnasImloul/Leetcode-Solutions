class Solution {
    // T = O(n) S=O(n)
    public boolean[] canEat(int[] candiesCount, int[][] queries) {
        // calculate prefix sum
        long[] prefix = new long[candiesCount.length+1];
        boolean[] res = new boolean[queries.length];
        prefix[0] = 0;
        
        for(int i=1; i< prefix.length; i++)
            prefix[i] = prefix[i-1]+candiesCount[i-1];
        
        for(int i=0; i< res.length; i++) {
            int type = queries[i][0];
            int day  = queries[i][1];
            int cap  = queries[i][2];
            
            // max and min day required to eat
            // if we eat one candy per day including type candy (prefix[type+1]). we decrement by 1 since we need atleast one candy of type
            long maxDay = prefix[type+1]-1; 
            // if we eat upto capacity each day upto previous candy
            long minDay = prefix[type]/cap; 
        
            // check if query day is within the limits (minDay and maxDay inclusive)
            res[i] = (minDay <= day && day <= maxDay);            
        }
        
        return res;
    }
}
