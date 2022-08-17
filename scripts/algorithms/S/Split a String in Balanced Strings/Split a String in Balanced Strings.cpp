class Solution {
public:
	int balancedStringSplit(string s) {

		int left = 0;
		int right = 0;
		int cnt = 0;

		for(int i=0 ; i<s.size() ; i++){
			if(s[i] == 'L'){
				left++;
			}
			if(s[i] == 'R'){
				right++;
			}

			if(left - right == 0){
				cnt++;
			}
		}

		return cnt;
	}
}
