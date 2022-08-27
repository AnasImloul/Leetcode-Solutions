// Runtime: 2 ms (Top 57.48%) | Memory: 41.5 MB (Top 82.47%)
class Solution {
    public boolean arrayStringsAreEqual(String[] word1, String[] word2)
    {
        return(String.join("", word1).equals(String.join("", word2)));
    }
}