// Runtime: 290 ms (Top 26.78%) | Memory: 13.40 MB (Top 40.95%)

class Solution {
public:
    int countPalindromicSubsequence(string inputString) {
        // Arrays to store the minimum and maximum occurrences of each character in the input string
        vector<int> minExist(26, INT_MAX);
        vector<int> maxExist(26, INT_MIN);

        // Populate minExist and maxExist arrays
        for(int i = 0; i < inputString.size(); i++) {
            int charIndex = inputString[i] - 'a';
            minExist[charIndex] = min(minExist[charIndex], i);
            maxExist[charIndex] = max(maxExist[charIndex], i);
        }

        // Variable to store the final count of unique palindromic subsequences
        int uniqueCount = 0;

        // Iterate over each character in the alphabet
        for (int charIndex = 0; charIndex < 26; charIndex++) {
            // Check if the character has occurred in the input string
            if (minExist[charIndex] == INT_MAX || maxExist[charIndex] == INT_MIN) {
                continue; // No occurrences, move to the next character
            }

            // Set to store unique characters between the minimum and maximum occurrences
            unordered_set<char> uniqueCharsBetween;

            // Iterate over the characters between the minimum and maximum occurrences
            for (int j = minExist[charIndex] + 1; j < maxExist[charIndex]; j++) {
                uniqueCharsBetween.insert(inputString[j]);
            }

            // Add the count of unique characters between the occurrences to the final count
            uniqueCount += uniqueCharsBetween.size();
        }

        // Return the total count of unique palindromic subsequences
        return uniqueCount;
    }
};
