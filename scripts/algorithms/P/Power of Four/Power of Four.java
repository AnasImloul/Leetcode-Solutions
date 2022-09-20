// Runtime: 2 ms (Top 64.18%) | Memory: 40.9 MB (Top 74.82%)
class Solution {
    public boolean isPowerOfFour(int n) {
        return (Math.log10(n)/Math.log10(4))%1==0;
    }
}