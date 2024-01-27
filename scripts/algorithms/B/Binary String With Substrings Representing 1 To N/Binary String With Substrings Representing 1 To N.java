// Runtime: 0 ms (Top 100.0%) | Memory: 41.50 MB (Top 30.38%)

class Solution {
    public boolean queryString(String s, int n) {
        for(int i = 1 ; i <= n ; i++) {
            String binary = Integer.toBinaryString(i);
            if(!s.contains(binary)) return false; 
        }
        return true;
    }
}
