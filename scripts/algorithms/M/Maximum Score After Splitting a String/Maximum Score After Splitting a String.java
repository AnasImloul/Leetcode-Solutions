// Runtime: 17 ms (Top 14.4%) | Memory: 44.28 MB (Top 5.7%)

class Solution {
    public int maxScore(String s) {
        int max =0;
        for(int i =0; i<s.length()-1; i++)
            max = Math.max(max,s.substring(0,i+1).replace("1","").length()+s.substring(i+1).replace("0","").length());
        
        return max;
    }
}