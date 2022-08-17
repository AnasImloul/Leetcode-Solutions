class Solution {
public:
	int maxRepeating(string sequence, string word) {
		int k = 0;
		string temp = word;

		while(sequence.find(temp) != string::npos){
			temp += word;
			k++;
		}

		return k;
	}
};
