// Runtime: 116 ms (Top 36.48%) | Memory: 43.8 MB (Top 80.69%)
/**
 * @param {string} s
 * @return {number}
 */
var secondHighest = function(s) {
    //let's start by getting rid of all the non-digits
    let myRegex = /\D/g
    s = s.replace(myRegex,'')
    var digits = s.split('')
    //at this point, digits is an array of all the digit characters that were originally in s
    digits.sort(function(a, b){return b - a}) //sort the array into descending order
    var res = new Set(digits) //turn the array into a set, to remove duplicates
    if(res.size <=1){
        //if the set is sized 1, then there is no second largest digit
        return -1
    }
    else{
        //otherwise, the second largest digit would be at index 1 (because we sorted the array into descending order)
        return [...res][1]
    }
};