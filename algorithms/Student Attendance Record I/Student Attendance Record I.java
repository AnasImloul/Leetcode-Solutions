class Solution {
    public boolean checkRecord(String s) {
        return !s.contains("LLL") && (s.indexOf('A') == s.lastIndexOf('A'));
    }
}
