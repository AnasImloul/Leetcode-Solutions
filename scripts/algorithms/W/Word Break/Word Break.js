// Runtime: 72 ms (Top 92.39%) | Memory: 42.9 MB (Top 90.15%)

/**
 * @param {string} s
 * @param {string[]} wordDict
 * @return {boolean}
 */
var wordBreak = function(s, wordDict) {
    var dp = new Array(s.length + 1).fill(false);
    dp[s.length] = true;

    for (var i = s.length - 1; i >= 0; i--) {
        for (const word of wordDict) {
            if ((i + word.length) <= s.length
                && s.substring(i, i + word.length) === word) {
                dp[i] = dp[i + word.length];
            }

            if(dp[i]) break;
        }
    }

    return dp[0];
};

// naive approach, take each word from the set and check if they match
/// O(n ^ 2 * m)
// considering m as the dictionary size
/*
var dict = new Set();
for (const word of wordDict) {
    dict.add(word);
}

return canSegment(s, dict, 0);

function canSegment (str, dict, index) {
    if (index >= str.length) return true;

    var success = false;
    for (const word of dict.values()) {

        if ((index + word.length) <= str.length) {
            var substring = str.substring(index, index + word.length);

            if (dict.has(substring)) {
                success = success | canSegment(str, dict, index + word.length);
            }
        }
    }

    return success;
}
*/