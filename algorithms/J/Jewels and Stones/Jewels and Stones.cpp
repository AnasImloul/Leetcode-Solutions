class Solution {
public:
	int numJewelsInStones(string jewels, string stones) {

		unordered_map<char, int> mp;

		for(int i=0 ; i<jewels.size() ; i++){
			mp[jewels[i]]++;
		}

		int ans = 0;
		for(int i=0 ; i<stones.size() ; i++){
			if(mp.find(stones[i]) != mp.end()){
				ans++;
			}
		}

		return ans;
	}
};