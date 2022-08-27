// Runtime: 642 ms (Top 13.93%) | Memory: 67.4 MB (Top 22.14%)
var longestPalindrome = function(words) {
    const n = words.length;
    const map = new Map();

    let len = 0;

    for (const word of words) {
         const backward = word.split("").reverse().join("");

        if (map.has(backward)) {
            len += (word.length * 2);
            map.set(backward, map.get(backward) - 1);

            if (map.get(backward) === 0) map.delete(backward);
        }
        else {
            if (!map.has(word)) map.set(word, 0);
            map.set(word, map.get(word) + 1);
        }
    }

    let maxLenSelfPalindrome = 0;

    for (const word of map.keys()) {
        if (isPalindrome(word)) {
            maxLenSelfPalindrome = Math.max(maxLenSelfPalindrome, word.length);
        }
    }

    return len + maxLenSelfPalindrome;

    function isPalindrome(word) {
        let left = 0;
        let right = word.length - 1;

        while (left < right) {
            if (word[left] != word[right]) return false;
            left++;
            --right;
        }

        return true;
    }
};