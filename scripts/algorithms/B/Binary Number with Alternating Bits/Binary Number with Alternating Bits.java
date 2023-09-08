// Runtime: 0 ms (Top 100.0%) | Memory: 39.76 MB (Top 13.5%)

class Solution {
    public boolean hasAlternatingBits(int n) {
        int flag = 1;
        if(n % 2 == 0) flag = 0;
        return bin(n / 2, flag);
    }
    public boolean bin(int n, int flag) {
        if(flag == n % 2) return false;
        if(n == 0) return true;
        else return bin(n / 2, n % 2);
    }
}