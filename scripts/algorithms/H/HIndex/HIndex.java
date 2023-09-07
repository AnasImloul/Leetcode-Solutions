// Runtime: 0 ms (Top 100.0%) | Memory: 39.87 MB (Top 98.6%)

class Solution {
    public int hIndex(int[] citations) {
        // Array to the contain the counts for number of papers 
        // with x citations, where counts[x] will be the number of 
        // papers with x citations.  Because the h value cannot be 
        // larger than the number of papers, the last used count in 
        // this array, count[citations.length], is a count of the 
        // number of papers with citations.length or more citations.
        int[] counts = new int[citations.length + 2];
        
        // Build the counts of how many papers have x citations.  
        // If a paper has more than citations.length citations, then 
        // count it as citations.length citations.
        for (int i = citations.length - 1; i >= 0; i--)  
            counts[Math.min(citations[i], citations.length)]++;
        
        // Go through the count[] array from last index down to 0, trying 
        // successively smaller values for h.  Looping from high to low 
        // possible values for h, will find the highest valid value for 
        // h.  While descending through the count array, add the count 
        // from the next higher index in the count array, which will 
        // convert the current counts[h] value to become a count of 
        // papers with h or more citations.  This is slightly confusing 
        // because h is used as both an index and a value to compare to 
        // the array value at that index.  The "units" for h feel 
        // inconsistent.
        int h;
        for (h = citations.length; h > 0; h--) {
            counts[h] += counts[h + 1];
            if (counts[h] >= h)  break;
        }
        return h;
    }
}