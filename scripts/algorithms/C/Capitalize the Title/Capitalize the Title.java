// Runtime: 1 ms (Top 99.1%) | Memory: 41.07 MB (Top 90.8%)

class Solution {
	public String capitalizeTitle(String title) {

		char[] ch = title.toCharArray();
		int len = ch.length;

		for(int i = 0; i < len; ++i) {

			int firstIndex = i; // store the first index of the word

			while(i < len && ch[i] != ' ') {
				ch[i] = Character.toLowerCase(ch[i]); // converting the character at ith index to lower case ony by one
				++i;
			}
			
			// if word is of length greater than 2, then turn the first character of the word to upper case
			if(i - firstIndex > 2) {
				ch[firstIndex] =  Character.toUpperCase(ch[firstIndex]); // converting the first character of the word to upper case
			}
		}

		return String.valueOf(ch); // return the final result by converting the char array into string
	}
}