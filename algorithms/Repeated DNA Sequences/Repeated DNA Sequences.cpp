class Solution {
	public:
		vector<string> findRepeatedDnaSequences(string s) {
			unordered_map<string,int> freq;
			int start = 0 , end = 9;
			while(end < s.size()){
				bool flag = true;
				for(int i = start ; i <= end ; i++){
					if(s[i] == 'A' or s[i] == 'C' or s[i] == 'G' or s[i] == 'T') continue;
					else {flag = false ; break ;}
				}
				if(flag){
					string temp = s.substr(start , 10);
					freq[temp]++;
				}
				start++;
				end++;
			}
			vector<string> ans;
			for(auto it : freq){
				if(it.second >= 2) ans.push_back(it.first);
			}
			return ans;
		}
};
