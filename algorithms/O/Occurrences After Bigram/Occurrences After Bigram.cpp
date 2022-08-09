class Solution {
public:
	vector<string> findOcurrences(string text, string first, string second) {
		vector<string>ans;
		int i=0;
		while(i<text.length())
		{
			string word = "";
			string secondWord="";
			while(i<text.length() && text[i]!=' ')
			{
				word = word+text[i];
				i++;
			}
			if(word == first)
			{
				int k = i+1;
				while(k<text.length() && text[k]!=' ')
				{
					secondWord = secondWord+text[k];
					k++;
				}  
				k++;
				if(k<text.length() && secondWord==second)
				{
					string tmp="";
					int j=k;
					while(j<text.length() && text[j]!=' ')
					{
						tmp = tmp+text[j];
						j++;
					} 

					ans.push_back(tmp);
				}
			}
		   i++;
		}
		return ans;
	}
};