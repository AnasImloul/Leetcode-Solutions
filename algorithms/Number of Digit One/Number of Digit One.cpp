class Solution {
public:
	int countDigitOne(int n) {
		int c = 0;
		for(int i=1; i<=n; i++){
			string s = to_string(i);
			c += count(s.begin(), s.end(), '1');
		}
		return c;
	}
};

// T.C. --> O(n * log(n))
// S.C. --> O(log(n))
