class Solution {
public:
	string reverseWords(string s) {
		int i=0;
		string res = "";
		while(i<s.length())
		{
			while(i<s.length() && s[i]==' ')
				i++;

			if(i>=s.length())
				break;

			int j=i+1;

			while(j<s.length() && s[j]!=' ')
				j++;


			string tmp = s.substr(i,j-i);
			if(res.length()==0)
			{
				res = tmp;
			}
			else
			{
				res = tmp + " " + res;
			}
			i=j+1;
		}
		return res;
	}
};