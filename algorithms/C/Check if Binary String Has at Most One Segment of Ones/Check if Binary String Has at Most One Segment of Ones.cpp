class Solution {
public:
	bool checkOnesSegment(string s) {
		for(int i = 1; i < s.size(); i++){
			if(s[i - 1] == '0' and s[i] == '1'){
				return false;
			}
		}
		return true;
	}
};