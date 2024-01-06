// Runtime: 0 ms (Top 100.0%) | Memory: 6.20 MB (Top 99.44%)

class Solution {
public:
	int xorOperation(int n, int start) {
		int ans =0;
		for(int i=0;i<n;i++){
			ans ^= start + 2*i;
		}
		return ans;
	}
};
