// Runtime: 83 ms (Top 15.87%) | Memory: 54.4 MB (Top 56.08%)
class Solution {
    public long maximumSubsequenceCount(String text, String pattern) {
        //when pattern[0] == pattern[1]
        if (pattern.charAt(0) == pattern.charAt(1)) {
            long freq = 1;
            //O(N)
            for (int i = 0; i < text.length(); i++) {
                if (text.charAt(i) == pattern.charAt(0)) {
                    freq++;
                }
            }
            //number of subsequences : choose any two characters from freq nC2
            return (freq * (freq - 1)) / 2;
        }

        //choice 1
        String text1 = pattern.charAt(0) + text;

        int freq = 0;
        long count1 = 0;
        //O(N)
        for (int i = 0; i < text1.length(); i++) {
            if (text1.charAt(i) == pattern.charAt(0)) {
                freq++;
            } else if (text1.charAt(i) == pattern.charAt(1)) {
                count1 += freq;
            }
        }

        //choice 2
        String text2 = text + pattern.charAt(1);
        freq = 0;
        long count2 = 0;
        //O(N)
        for (int i = text2.length() - 1; i>= 0; i--) {
            if (text2.charAt(i) == pattern.charAt(1)) {
                freq++;
            } else if (text2.charAt(i) == pattern.charAt(0)) {
                count2 += freq;
            }
        }

        return Math.max(count1, count2);
    }
}