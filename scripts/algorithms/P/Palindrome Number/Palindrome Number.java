// Runtime: 16 ms (Top 39.53%) | Memory: 44.7 MB (Top 53.62%)
class Solution {
    public boolean isPalindrome(int x) {
        int sum = 0;
        int X = x;

        while(x > 0){
            sum = 10 * sum + x % 10;
            x /= 10;
        }

        return sum == X;
    }
}