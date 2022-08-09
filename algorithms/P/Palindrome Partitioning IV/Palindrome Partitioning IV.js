/**
 * @param {string} s
 * @return {boolean}
 */
var checkPartitioning = function(s) {
    // create a dp that will represent the starting and ending index of a substring
    // if dp[i][j] is true that means that the string starting from i and ending at j is a palindrome
    const dp = new Array(s.length).fill(null).map(() => new Array(s.length).fill(false));
    
    // all substrings of length 1 are palindromes so we mark all matching indices as true
    for (let i = 0; i < s.length; i++) {
        dp[i][i] = true;
    }
    
    
    // slowly grow the substring from each index
    // we will know the substring is a palindrom if the substring prior was a palindrome
    for (let lengthOfSubString = 2; lengthOfSubString <= s.length; lengthOfSubString++) {
        for (let startingIndex = 0; startingIndex + lengthOfSubString <= s.length; startingIndex++) {
            
            // if it's not the same character, then it can not be a palindrome
            if (s[startingIndex] !== s[startingIndex + lengthOfSubString - 1]) continue;
            
            if (lengthOfSubString <= 3 || 
                
                // this checks if the prior substring was a palindrome
                dp[startingIndex + 1][startingIndex + lengthOfSubString - 2]) {
                
                dp[startingIndex][startingIndex + lengthOfSubString - 1] = true;
            }
        }
    }
    
    // find out if any 3 of the partitions are palindromes
    for (let i = 0; i < s.length; i++) {
        for (let j = i + 1; j < s.length; j++) {
            if (dp[0][i] && dp[i + 1][j] && dp[j + 1][s.length - 1]) return true;
        }
    }
    
    // if we haven't found a partition, return false
    return false;
};
