class Solution {
    public String convertToTitle(int columnNumber) {
        String ans = "";
        while(columnNumber > 0){
            columnNumber--;
            ans = String.valueOf((char)('A' + (int)((26 + (long)columnNumber)  % 26))) + ans;
            columnNumber /= 26;
        }
        return ans;
    }
}
