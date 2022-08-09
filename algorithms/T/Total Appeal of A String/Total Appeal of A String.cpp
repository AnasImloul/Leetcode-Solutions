class Solution {
public:
	long long appealSum(string s) {
		int n = s.size();
		long long ans = 0;
		for(char ch='a';ch<='z';ch++)       // we are finding the number of substrings containing at least 1 occurence of ch
		{
			int prev = 0;                   // prev will store the previous index of the charcter ch
			for(int i=0;i<n;i++)
			{
				if(s[i] == ch) prev = i+1;  // if the current character is equal to ch , then the no. of substring
											// ending at i and having at least one occurence of ch will be i+1 .

				ans+=prev;                  // else the no. of substrings ending at i and having at least
											// one occurence of ch will be the equal to, the previous index of ch.
			}
		}
		return ans;                        // TC - O(n*26) , SC - O(1)
	}
};