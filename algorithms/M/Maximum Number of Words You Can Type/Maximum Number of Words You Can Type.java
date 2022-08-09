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
