class Solution {
public:
	bool isPerfectSquare(int num) {

		if (num == 1)return true;
		long long l = 1, h = num / 2;

		while (l <= h) {
			long long mid = l + (h - l) / 2;
			long long midSqr = mid * mid;

			if (midSqr == num) return true;

			if (num < midSqr) {
				h = mid - 1;
			} else {
				l = mid + 1;
			}
		}
		return false;
	}
};
