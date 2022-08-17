class Solution {
public:
	int findLeastNumOfUniqueInts(vector<int>& arr, int k) {

		int n = arr.size();

		unordered_map<int,int> m;

		for(auto it : arr) m[it]++;

		vector<int> v;
		// storing the frequency of number
		for(auto it : m) v.push_back(it.second);

		// sorting to least to most frequent
		sort(v.begin(),v.end());

		for(int i = 0; i < v.size(); i++){
			if(k <= 0) break;
			int mn = min(k,v[i]);
			k -= mn;
			v[i] -= mn;
		}

		int ans = 0;

		for(int i = 0; i < v.size(); i++){
			if(v[i] > 0) ans++;
		}

		return ans;
	}
};