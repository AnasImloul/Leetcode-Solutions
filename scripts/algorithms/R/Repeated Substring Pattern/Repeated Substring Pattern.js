// Runtime: 120 ms (Top 50.89%) | Memory: 44.6 MB (Top 76.49%)
var repeatedSubstringPattern = function(s) {
    let repeatStr = s.repeat(2) //first duplicate the string with repeat function
    let sliceStr = repeatStr.slice(1,-1) // slice string first and last string word
    return sliceStr.includes(s) // now check if the main string(s) is included by sliced string
}