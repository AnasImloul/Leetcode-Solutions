// Runtime: 5 ms (Top 73.70%) | Memory: 42.2 MB (Top 97.84%)
class Solution {
    public boolean isAnagram(String s, String t) {
        if (s.length() != t.length()) return false;
        int[] haha1 = new int[26];//26 because input contains of only lower english letters
        int[] haha2 = new int[26];
        for (int i = 0; i < s.length(); ++i) {
            haha1[(int)s.charAt(i)-97] += 1;//omitting 97 because 'a' is 97, it will be 0 now
            haha2[(int)t.charAt(i)-97] += 1;
        }
        for (int i = 0; i < haha1.length; ++i) {
            if (haha1[i] != haha2[i]) return false;
        }
        return true;
    }
}