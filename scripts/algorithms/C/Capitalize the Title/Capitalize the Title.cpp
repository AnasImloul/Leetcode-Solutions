class Solution {
public:
	string capitalizeTitle(string title) {

		int len = title.length();

		for(int i = 0; i < len; ++i) {

			int firstIndex = i; // store the first index of the word

			while(i < len && title[i]  != ' ') {
				title[i] = tolower(title[i]); // converting the character at ith index to lower case ony by one
				++i;
			}
			
			// if word is of length greater than 2, then turn the first character of the word to upper case
			if(i - firstIndex > 2) {
				title[firstIndex] = toupper(title[firstIndex]); // converting the first character of the word to upper case
			}
		}

		return title; // return the final result
	}
};
