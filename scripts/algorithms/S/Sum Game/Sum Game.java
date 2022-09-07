// Runtime: 18 ms (Top 22.45%) | Memory: 50.6 MB (Top 24.49%)
class Solution {
    public boolean sumGame(String num) {
        int q = 0, d = 0, n = num.length();
        for (int i = 0; i < n; i++){
            if (num.charAt(i) == '?'){
                q += 2* i < n? 1 : -1;
            }else{
                d += (2 * i < n? 1 : -1) * (num.charAt(i) - '0');
            }
        }
        return (q & 1) > 0 || q * 9 + 2 * d != 0;
    }
}