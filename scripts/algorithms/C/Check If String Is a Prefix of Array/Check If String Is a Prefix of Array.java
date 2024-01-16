// Runtime: 1 ms (Top 90.41%) | Memory: 42.90 MB (Top 8.98%)

class Solution {
    public boolean isPrefixString(String s, String[] words) {
        StringBuilder res = new StringBuilder ("");
        for (String word : words) {
            res.append (word);
            if (s.equals (res.toString()))
                return true;
            if (s.indexOf (res.toString()) == -1)
                return false;
        }
        return false;
    }
}
