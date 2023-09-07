// Runtime: 1 ms (Top 91.5%) | Memory: 38.98 MB (Top 97.6%)

class Solution {
    public int monotoneIncreasingDigits(int n) {
        int position;
        int digitInTheNextPosition;
        while ((position = getThePositionNotSatisfied(n)) != -1) {
            digitInTheNextPosition = ((int) (n / Math.pow(10, position - 1))) % 10;
            n -= Math.pow(10, position - 1) * (digitInTheNextPosition + 1);
            n -= n % Math.pow(10, position);
            n += Math.pow(10, position) - 1;
        }
        return n;
    }

    public int getThePositionNotSatisfied(int n) {
        int k = 10;
        int position = 0;
        while (n > 0) {
            if (k < n % 10) {
                return position;
            } else {
                k = n % 10;
                n /= 10;
                position++;
            }
        }
        return -1;
    }
}