// Runtime: 23 ms (Top 23.53%) | Memory: 45.40 MB (Top 5.88%)

class Solution {
    public String smallestBeautifulString(String s, int k) {
        char[] ch = s.toCharArray();
        int i = ch.length - 1;
        while (i >= 0) {
            ch[i]++;
            if (ch[i] - 'a' == k) {
                i--;
            } else if ((i - 1 < 0 || ch[i - 1] != ch[i]) && (i - 2 < 0 || ch[i - 2] != ch[i])) {
                break;
            }
        }
        if (i < 0) return "";
        for (int j = i + 1; j < ch.length; j++) {
            SortedSet<Character> set = new TreeSet<>(Arrays.asList('a', 'b', 'c'));
            if (j - 2 >= 0) set.remove(ch[j - 2]);
            if (j - 1 >= 0) set.remove(ch[j - 1]);
            ch[j] = set.first();
        }
        return new String(ch);
    }
}
