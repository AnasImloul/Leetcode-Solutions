// Camelcase Matching
// https://leetcode.com/problems/camelcase-matching/

class Solution {
    public List<Boolean> camelMatch(String[] queries, String pattern) {
        List<Boolean> res = new ArrayList<>();
        for (String query : queries) {
            res.add(match(query, pattern));
        }
        return res;       
    }
    private boolean match(String query, String pattern) {
        int i = 0;
        for (char c : query.toCharArray()) {
            if (i < pattern.length() && c == pattern.charAt(i)) {
                i++;
            } else if (Character.isUpperCase(c)) {
                return false;
            }
        }
        return i == pattern.length();
    }
}
