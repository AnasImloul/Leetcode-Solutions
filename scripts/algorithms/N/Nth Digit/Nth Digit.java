// Runtime: 1237 ms (Top 5.08%) | Memory: 39.2 MB (Top 91.02%)
class Solution {
    public int findNthDigit(int n) {

        if(n < 10)
            return n;

        long currDigitIndex = 10;
        int tillNextIncrease = 90;
        int currNumberSize = 2;
        int currNumber = 10;
        int next = tillNextIncrease;

        while(currDigitIndex < n) {

            currNumber++;
            currDigitIndex += currNumberSize;
            next--;

            if(next == 0) {
                currNumberSize++;
                tillNextIncrease *= 10;
                next = tillNextIncrease;
            }
        }

        int nthDigit = currNumber % 10;
        if(currDigitIndex == n) {
            while(currNumber != 0) {
                nthDigit = currNumber % 10;
                currNumber /= 10;
            }
        } else if(currDigitIndex > n) {

            currNumber--;

            while(currDigitIndex > n) {
                currDigitIndex--;
                nthDigit = currNumber % 10;
                currNumber /= 10;
            }
        }

        return nthDigit;
    }
}