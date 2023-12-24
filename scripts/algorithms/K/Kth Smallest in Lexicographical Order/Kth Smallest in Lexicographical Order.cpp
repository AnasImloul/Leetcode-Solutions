// Runtime: 2 ms (Top 46.72%) | Memory: 6.30 MB (Top 76.64%)

class Solution {
public:
    static int findKthNumber(int const n, int const k) {
        int num = 0, rank_of_num = 0, nxt = 0, rank_of_nxt = 0;
        while (rank_of_num != k) {
            int lower = num ? 0 : 1, upper = 9;
            while (lower < upper) {
                auto const mid = (lower + upper + 1) / 2;
                nxt = num * 10 + mid;
                rank_of_nxt = rank(nxt, n);
                if (rank_of_nxt > k) upper = mid - 1; else lower = mid;
            }
            num *= 10;
            num += lower;
			// optimization: avoid re-computing rank(num, n) if possible
            rank_of_num = (num == nxt ? rank_of_nxt : rank(num, n));
        }
        return num;
    }
private:
    static int rank(int const prefix, int const max_val) {
        int r = 1;
        int num_digits = 0;
		// consider all possible numbers having prefix `p - d` that will be
		// lexicographically smaller than `prefix`
        for (int p = prefix; p; p /= 10, ++num_digits)
            for (int d = 1; d <= p % 10; ++d)
                r += numPrefixes(p - d, max_val);
        r += num_digits - 1;
        return r;
    }
    static int numPrefixes(int const prefix, int const max_val) {
        if (0 == prefix) return 0;
        int cnt = 0;
        unsigned long long p = 1;
		// This just sets p = pow(10, x) for each viable value of x and counts the number of
		// integers within the range of [prefix * pow(10, x), (prefix + 1) * pow(10, x)) that
		// also do not exceed `max_val`
        for (unsigned long long val = prefix; val <= max_val; p *= 10, val *= 10)
			cnt += min(p, max_val - val + 1);
        return cnt;
    }
};
