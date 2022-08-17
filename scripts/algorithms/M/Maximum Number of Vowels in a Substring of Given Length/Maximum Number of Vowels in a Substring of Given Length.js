var maxVowels = function(s, k) {
    let vowels = ['a', 'e', 'i', 'o', 'u'];
    let maxCount = 0;
    let start = 0; // the left edge of the window
    let count = 0; // count of vowels for current substring
	// expanding the right edge of the window one character at a time
    for (let end = 0; end < s.length; end++) {
	    // increment count of vowels for current substring if the current character is present in vowels array
        if (vowels.includes(s[end])) {
            count +=1;
        }
        // if substring is longer than K, let's shrink the window by moving left edge
        if (end - start + 1 > k) {
			// reduce the current count by one if the character on the left edge is vowel
            if(vowels.includes(s[start])) {
                count -=1;
            }
			//shrinking the left edge of the window
            start +=1;
        }
		// checking if current count is larger than current maximum count
        maxCount = Math.max(maxCount, count)
		// if maxCount is equal to K, no need to check further, it is the max possible count
        if (maxCount == k) return maxCount;
    }
    return maxCount;
};
