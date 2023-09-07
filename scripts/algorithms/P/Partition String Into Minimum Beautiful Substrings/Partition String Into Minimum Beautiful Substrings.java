// Runtime: 4 ms (Top 64.7%) | Memory: 43.46 MB (Top 48.3%)

class Solution {
    public int minimumBeautifulSubstrings(String s) {
        return backtrack(s, 0);
    }
    
    private int backtrack(String s, int index) {
        if (index == s.length())
            return 0;
        
        int minPartitions = Integer.MAX_VALUE;
        for (int i = index + 1; i <= s.length(); i++) {
            String substring = s.substring(index, i);
            if (isValidBeautiful(substring)) {
                int partitions = backtrack(s, i);
                if (partitions != -1)
                    minPartitions = Math.min(minPartitions, partitions + 1);
            }
        }
        
        return (minPartitions == Integer.MAX_VALUE) ? -1 : minPartitions;
    }
    
    private boolean isValidBeautiful(String substring) {
        if (substring.startsWith("0"))
            return false;
        
        int decimalValue = Integer.parseInt(substring, 2);
        return isPowerOfFive(decimalValue);
    }
    
    private boolean isPowerOfFive(int num) {
        while (num % 5 == 0) {
            num /= 5;
        }
        return num == 1;
    }
}
