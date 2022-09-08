// Runtime: 0 ms (Top 100.00%) | Memory: 39.7 MB (Top 97.89%)
class Solution {
    public int largestAltitude(int[] gain) {
         int max_alt=0;
        int curr_alt=0;
        for(int i=0;i<gain.length;i++){
            curr_alt+=gain[i];
            max_alt=Math.max(curr_alt, max_alt);
        }
        return max_alt;
    }
}

//TC: O(n), SC: O(1)