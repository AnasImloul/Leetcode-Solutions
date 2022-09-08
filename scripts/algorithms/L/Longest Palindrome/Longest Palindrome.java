// Runtime: 6 ms (Top 56.47%) | Memory: 40.7 MB (Top 92.38%)
class Solution {
    public int longestPalindrome(String s) {
        HashMap<Character, Integer> map = new HashMap<>();

        int evenNo = 0;
        int oddNo = 0;

        for ( int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            if (map.containsKey(c)) {
                map.put(c, map.get(c) + 1);
            } else {
                map.put(c, 1);
            }

        }
        for (Map.Entry e : map.entrySet()) {
            int n = (int) e.getValue();
            if (n % 2 != 0) {
                oddNo += n;
            }
            evenNo += (n / 2) * 2;
        }

        if (oddNo > 0) {
            evenNo += 1;
        }
        return evenNo;
    }
}