class Solution {
public:
	int longestWPI(vector<int>& hours) {
        int n = hours.size();
		int ans = 0;
		int ct = 0;
		unordered_map<int, int> m;
		for (int i = 0; i < n; ++i) {
			if (hours[i] > 8) ct++;
			else ct--;
			if (ct > 0) ans = max(ans, i + 1);
			else {
				if (m.find(ct) == m.end()) m[ct] = i;
				if (m.find(ct - 1) != m.end()) ans = max(ans, i - m[ct - 1]);
			}
		}
		return ans;
	}
};

