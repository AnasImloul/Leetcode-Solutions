class Solution {
public:
	bool checkAlmostEquivalent(string word1, string word2) {
		unordered_map<char, int> m;
		for(int i = 0; i < word1.size(); i++){
			m[word1[i]]++;
		}
		for(int i = 0; i < word2.size(); i++){
			m[word2[i]]--;
		}
		for(auto i : m){
			if(abs(i.second) > 3){
				return false;
			}
		}
		return true;
	}
};