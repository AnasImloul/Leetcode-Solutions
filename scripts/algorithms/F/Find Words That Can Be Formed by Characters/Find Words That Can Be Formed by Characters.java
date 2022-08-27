// Runtime: 8 ms (Top 90.62%) | Memory: 53.5 MB (Top 72.75%)
class Solution {
    public int countCharacters(String[] words, String chars) {
        int[] freq = new int[26];
        for (int i = 0; i < chars.length(); i++) {
            // char - char is a kind of clever way to get the position of
            // the character in the alphabet. 'a' - 'a' would give you 0.
            // 'b' - 'a' would give you 1. 'c' - 'a' would give you 2, and so on.
            freq[chars.charAt(i) - 'a'] ++;
        }

        int result = 0;
        for (String word : words) {
            int[] copy = Arrays.copyOf(freq, freq.length);
            boolean pass = true;
            for (int j = 0; j < word.length(); j++) {
                // decrement the frequency of this char in array for using
                // if there are less than 1 chance for using this character, invalid,
                // move to next word in words
                if (-- copy[word.charAt(j) - 'a'] < 0) {
                    pass = false;
                    break;
                }
            }
            if (pass) {
                result += word.length();
            }
        }
        return result;
    }
}