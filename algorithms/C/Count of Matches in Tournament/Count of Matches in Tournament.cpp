//recursion (Runtime: 0 ms, faster than 100.00%)
class Solution {
public:
    int numberOfMatches(int n) {
      return n == 1 ? 0 : n / 2 + numberOfMatches(n / 2 + (n%2));
    }
};
//iterative
class Solution {
public:
    int numberOfMatches(int n) {
        int cnt = 0;
        while (n>1) {
            cnt+=n/2;
            n=n/2+n%2;
        }
    return cnt;
	}
};
