// Runtime: 544 ms (Top 5.4%) | Memory: 49.14 MB (Top 26.7%)

const swapCase = (str) => str.split('').map((c) => c === c.toUpperCase() ? c.toLowerCase() : c.toUpperCase()).join('');

var longestNiceSubstring = function(s) {
    let ans = "";
        for (let i = 0; i < s.length; i++) {
            for (let ii = i + 1; ii < s.length + 1; ii++) {
                let substring = s.slice(i, ii); // we take a substring

                let invertedCaseChars = [...substring].map(swapCase); // we create an array of chars from the substring and invert case of this chars
                
                if (invertedCaseChars.every(char => substring.includes(char))) { // we check that substring includes every case inverted char (see the illustration above)
                    ans = substring.length > ans.length ? substring : ans; // we select the longest substring which satisfies our condition
                }
            } 
        }
        return ans 
};