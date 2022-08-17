class Solution {
    public int mySqrt(int x) {
        long answer = 0;
        while (answer * answer <= x) {
            answer += 1;
        }
        return (int)answer - 1;
    }
}
