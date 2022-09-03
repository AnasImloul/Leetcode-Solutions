// Runtime: 1 ms (Top 45.03%) | Memory: 40.9 MB (Top 59.95%)
class Solution {
    public int hammingDistance(int x, int y) {
        int n = x^y;
        int ans = 0;

// Run loop till n does not contain any 1
        while(n != 0){
            ans = ans + (n &1);
            n >>>= 1;
        }
        return ans;
    }
}