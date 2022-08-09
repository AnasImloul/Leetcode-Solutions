class Solution {
public:
	string freqAlphabets(string s) {
		int n=s.size(); 
		string ans="";
		for(int i=0;i<n;){
			if(i+2<n && s[i+2]=='#'){
				ans+= (s[i]-'0')*10 + (s[i+1]-'0') +96;
				i+=3;
			}
			else{
				ans+=(s[i]-'0') + 96;
				i++;
			}
		}
		return ans;
	}
};