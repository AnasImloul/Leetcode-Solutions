// Runtime: 94 ms (Top 77.32%) | Memory: 44.2 MB (Top 71.88%)
var reorganizeString = function(s) {
    const charMap = {};
    const res = [];

    // Store the count of each char
    for (let char of s) {
        charMap[char] = (charMap[char] || 0) + 1;
    }

    // Sort in descending order by count
    const sortedMap = Object.entries(charMap).sort((a, b) => b[1] - a[1]);

    // Check if we can distribute the first char by every other position.
    // We only need to check the first char b/c the chars are ordered by count
    // so if the first char succeeds, all following chars will succeed
    if (sortedMap[0][1] > Math.floor((s.length + 1) / 2)) return '';

    let position = 0;
    for (let entry of sortedMap) {
        const char = entry[0]
        const count = entry[1];
        for (let j = 0; j < count; j++) {
            // Distribute the current char every other position. The same char
            // will never be placed next to each other even on the 2nd loop
            // for placing chars in odd positions
            res[position] = char;
            position +=2;

            // This will only happen once since total number of chars
            // will be exactly equal to the length of s
            if (position >= s.length) position = 1;
        }
    }

    return res.join('');
};