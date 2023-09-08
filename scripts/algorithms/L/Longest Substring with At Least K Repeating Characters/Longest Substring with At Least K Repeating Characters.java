// Runtime: 1034 ms (Top 5.0%) | Memory: 40.34 MB (Top 79.2%)

// Solution 1: O(n^2) brute force
// time O(n^2)
// space O(1)
class Solution {
    public int longestSubstring(String s, int k) {
        if (s == null || s.isEmpty() || k > s.length()) {
            return 0;
        }
        
        int[] map = new int[26]; // letter -> freq
        int n = s.length();
        int max = 0; // length of longest substring T so far
        for (int i = 0; i < n; i++) {
            Arrays.fill(map, 0);
            for (int j = i; j < n; j++) {
                map[s.charAt(j) - 'a']++;                
                if (isValid(s, i, j, k, map)) {
                    max = Math.max(max, j - i + 1);
                }
            }
        }
        
        return max;
    }
    
    // return true if each distinct character in the substring s[left..right] appear >= k times
    private boolean isValid(String s, int left, int right, int k, int[] map) {
        int numLetters = 0; // number of distinct letters
        int numLettersAtLeastK = 0;
        for (int num : map) {
            if (num > 0) {
                numLetters++;
            }
            
            if (num >= k) {
                numLettersAtLeastK++;
            }
        }
        
        return numLettersAtLeastK == numLetters;
    }
}