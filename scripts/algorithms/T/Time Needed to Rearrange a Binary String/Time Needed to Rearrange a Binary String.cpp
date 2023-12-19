// Runtime: 66 ms (Top 13.2%) | Memory: 7.10 MB (Top 21.45%)

class Solution {
public:
	int secondsToRemoveOccurrences(string s) {
		int count=0;
		int n=s.size();
		for(int i=0;i<n;i++){
			bool flag=false;
			for(int j=0;j<n-1;j++){
				if(s[j]=='0' && s[j+1]=='1'){
					s[j]='1';
					s[j+1]='0';
					flag=true;
					j++;
				}
			}
			if(flag) count++;
		}
		return count;
	}
};