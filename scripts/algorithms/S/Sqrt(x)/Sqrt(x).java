// Runtime: 34 ms (Top 10.30%) | Memory: 41.3 MB (Top 62.51%)

class Solution {
    public int mySqrt(int x) {
        long answer = 0;
        while (answer * answer <= x) {
            answer += 1;
        }
        return (int)answer - 1;
    }
}