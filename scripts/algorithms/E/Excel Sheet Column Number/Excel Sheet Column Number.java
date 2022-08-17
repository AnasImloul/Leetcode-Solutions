class Solution {
    public int titleToNumber(String columnTitle) {
        int n = columnTitle.length();   
        int pow = 0;
        int res = 0;
        for(int i = n-1; i >= 0; i--) {
            char c = columnTitle.charAt(i);
            res += (c - 64) * Math.pow(26, pow);
            pow++;
        }
        
        return res;
    }
}