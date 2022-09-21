// Runtime: 99 ms (Top 27.52%) | Memory: 42.1 MB (Top 51.50%)
var percentageLetter = function(s, letter) {
    let count = 0;
    for (let i of s) { // count how many letters are in s
        if (i == letter) count++;
    }
    return (Math.floor((count*1.0) / (s.length*1.0) * 100)) // get percentage
};