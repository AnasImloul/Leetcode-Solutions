#include <regex>

class Solution {
public:
	int countValidWords(string sentence) {

		int count = 0;
		
		// Defining the regex pattern
		regex valid_word("[a-z]*([a-z]-[a-z])?[a-z]*[!,.]?");

		// splitting the sentence to words
		stringstream s(sentence);
		string word;
		while(getline(s, word, ' ')) {
		
			// Checking if the word matches the regex pattern
			if(word != "" && regex_match(word, valid_word)){
				++count;
			} 
		}

		return count;
	}  
};
