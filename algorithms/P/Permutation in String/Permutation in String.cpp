class Solution {
public:
	bool checkInclusion(string s1, string s2) {
		sort(s1.begin(),s1.end());
		int n = s1.size(), m = s2.size();
		for(int i=0;i<=m-n;i++)
		{
			string s = s2.substr(i,n);
			sort(s.begin(),s.end());
			if(s1 == s)     return true;
		}
		return false;
	}
};