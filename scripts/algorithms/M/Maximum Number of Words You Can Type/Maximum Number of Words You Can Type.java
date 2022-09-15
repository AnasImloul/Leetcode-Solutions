// Runtime: 8 ms (Top 25.13%) | Memory: 42.1 MB (Top 88.13%)
class Solution {
    public int canBeTypedWords(String text, String brokenLetters) {
        int count = 1;
        boolean isBad = false;
        for (char c : text.toCharArray()) {
            if (c == ' ') {
                isBad = false;
                count++;
            } else {
                if (!isBad && brokenLetters.indexOf(c) != -1) {
                    isBad = true;
                    count--;
                }
            }
        }
        return count;
    }
}