// Runtime: 1 ms (Top 93.63%) | Memory: 41.7 MB (Top 86.60%)
class Solution {
    public String mergeAlternately(String word1, String word2) {
        StringBuilder sb = new StringBuilder();
        int lenmax = Math.max(word1.length(),word2.length());
        for(int i=0;i<=lenmax-1;i++)
        {
            if(i<word1.length()) sb.append(word1.charAt(i));
            if(i<word2.length()) sb.append(word2.charAt(i));
        }
        return sb.toString();
    }
}