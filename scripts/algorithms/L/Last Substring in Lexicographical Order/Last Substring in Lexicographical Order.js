// Runtime: 83 ms (Top 70.37%) | Memory: 48.90 MB (Top 44.44%)

// Second Solution
// Efficient
/*
The substring starting with the largest character is the answer. Hence we advance j and try to find the biggest character 
while we use i to keep track of the current maximum string.
What if there is more than one largest character?
- we will need to compare both substrings starting with the largest character.
- (1) the substring with bigger next character is the answer.
- (2) if the shorter substring is exactly the same to the longer substring up to its end, the longer substring is the answer.

i is the starting index of the answer
j is the pointer iterating through given string
k is the offset to use when we find two substrings starting with the same character
*/
var lastSubstring = function(s) {
    let i = 0, j = 1, k = 0;
    while (j + k < s.length) {
        k = 0;
        while (s[i+k] === s[j+k]) {
            k += 1;
            if (j + k === s.length) break;
            // if the shorter substring is exactly the same to the longer substring up to its end, 
            // the longer substring is the answer.
            // hence, if j+k reaches the end, s.substring(i) will be the answer since we maintain i < j
        }
        if (s[i+k] > s[j+k]) {
            j = j + 1 + k; // because there is no chance s[i+k] <= s[j+k]
        } else if (s[i+k] < s[j+k]) {
            i = i + 1 + k; // because there is no chance s[i+k] >= s[j+k]
        }
        // to ensure that i < j
        if (i >= j) {
            j = i + 1;
        }
    }
    return s.substring(i);
    // T.C: O(N)
    // S.C: O(1)
};
