// Runtime: 25 ms (Top 76.04%) | Memory: 13.10 MB (Top 91.69%)

class Solution {
public: 
	int similarPairs(vector<string>& words) {
		int ans = 0; 
		unordered_map<int, int> freq; 
		for (auto& word : words) {
			int mask = 0; 
			for (auto& c : word) mask |= 1 << (c-'a'); 
			ans += freq[mask]++; 
		}
		return ans; 
	}
};
