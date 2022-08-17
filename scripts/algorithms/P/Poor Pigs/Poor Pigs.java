class Solution {
    public int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int T = (minutesToTest/minutesToDie) + 1;
        int cnt = 0;
        int total = 1;
        while (total < buckets) {
            total *= T;
            cnt++;
        }
        return cnt;
    }
}
