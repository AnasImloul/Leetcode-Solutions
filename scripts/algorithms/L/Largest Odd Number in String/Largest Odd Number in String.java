// Runtime: 3 ms (Top 63.81%) | Memory: 54.8 MB (Top 11.36%)
class Solution {
    public String largestOddNumber(String num) {
        for (int i = num.length() - 1; i > -1; i--) {
            if (num.charAt(i) % 2 == 1) return num.substring(0,i+1);
        }
        return "";
    }
}