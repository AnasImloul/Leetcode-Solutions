// Runtime: 1 ms (Top 96.8%) | Memory: 41.04 MB (Top 50.9%)

class Solution {
    public boolean isCircularSentence(String s) {
        for(int i=0;i<s.length();i++)
        {
            if(s.charAt(i)==' ')
            {
                if(s.charAt(i-1)!=s.charAt(i+1))
                {
                    return false;
                }
            }
        }
        return s.charAt(0) == s.charAt(s.length()-1);
    }
}