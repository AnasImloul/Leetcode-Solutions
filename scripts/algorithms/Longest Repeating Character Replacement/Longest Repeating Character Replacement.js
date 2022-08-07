// O(n) time | O(26) -> O(1) space - only uppercase English letters
var characterReplacement = function(s, k) {
    const sLen = s.length, 
          charCount = {};
    if (k >= sLen) return sLen;
    let maxLen = 0,
        windowStart = 0,
        maxRepeatChar = 0;
    for (let windowEnd = 0; windowEnd < sLen; windowEnd++) {
        // increment charCount
        charCount[s[windowEnd]] ? charCount[s[windowEnd]]++ : charCount[s[windowEnd]] = 1;
        // calc max repeating char
        maxRepeatChar = Math.max(maxRepeatChar, charCount[s[windowEnd]]);
        // calc number of char that is not (or has fewer chars) repeating in window
        const remainingChar = windowEnd - windowStart + 1 - maxRepeatChar;
        // slide window by incrementing start of window
        if (remainingChar > k) {
            // decrement charCount
            charCount[s[windowStart]]--;
            windowStart++;
        }
        // calc maxLen
        maxLen = Math.max(maxLen, windowEnd - windowStart + 1);
    }
    return maxLen;
};
