class Solution {
public:
    int reverse(int x) {
		long res = 0;
		while (abs(x) > 0) {
			res = (res + x % 10) * 10;
			x /= 10;
		}
		x < 0 ? res = res / 10 * -1 : res = res / 10;
		if (res < INT32_MIN || res > INT32_MAX) {
			res = 0;
		}
		return res;
    }
};
