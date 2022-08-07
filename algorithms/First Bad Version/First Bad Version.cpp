class Solution {
public:
    int firstBadVersion(int n) {
	//Using Binary Search
        int lo = 1, hi = n, mid;
        while (lo < hi) {
            mid = lo + (hi - lo) / 2;
            if (isBadVersion(mid)) hi = mid;
            else lo = mid+1;
        }
        return lo;
    }
};

