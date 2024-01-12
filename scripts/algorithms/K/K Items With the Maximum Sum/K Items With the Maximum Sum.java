// Runtime: 1 ms (Top 98.36%) | Memory: 41.40 MB (Top 10.96%)

class Solution {
    public int kItemsWithMaximumSum(int numOnes, int numZeros, int numNegOnes, int k) {
        
        int max = 0; // the maximum sum
        
        // while we still need to select k numbers
        while(k > 0){
            
            // if we have at least one 1 left, add it to the sum
            if(numOnes > 0){
                numOnes--;
                max++;
                k--;
            }
            // if we have at least one 0 left, skip it
            else if(numZeros > 0){
                numZeros--;
                k--;
            }
            // if we have at least one -1 left, add it to the sum
            else{
                numNegOnes--;
                max--;
                k--;
            }   
        } 
        // if we did not select k numbers, return the maximum sum anyway
        return max;
    }
}
