// Runtime: 1 ms (Top 36.84%) | Memory: 41.2 MB (Top 58.44%)
class Solution {
    public String convertToTitle(int columnNumber) {
        String ans = "";
        while(columnNumber > 0){
            columnNumber--;
            ans = String.valueOf((char)('A' + (int)((26 + (long)columnNumber) % 26))) + ans;
            columnNumber /= 26;
        }
        return ans;
    }
}