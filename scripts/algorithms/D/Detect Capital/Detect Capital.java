// Runtime: 3 ms (Top 29.72%) | Memory: 41.4 MB (Top 86.57%)
class Solution {
    public boolean detectCapitalUse(String word) {
        int count = 0;
        for(int i=0; i < word.length(); i++){
            if('A' <= word.charAt(i) && word.charAt(i) <= 'Z')
                count++;
        }
        if(count == 0 || count == word.length() || (count == 1 && ('A' <= word.charAt(0) && word.charAt(0) <= 'Z')))
            return true;
        else
            return false;
    }
}