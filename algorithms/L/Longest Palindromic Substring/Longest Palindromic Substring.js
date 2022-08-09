I solve the problem distinguishing two different cases.
First I consider the case when the length of the palindrome to be found is odd (there is a center). 
	I then expand the search to left and right from the possible found center.
Then I consider the case when the length of the palindrome to be found is pair (there is no center/middle).
	I then expand the search to left and right from the possible palindrome having the form "xx".
```/**
 * @param {string} s
 * @return {string}
 */
var longestPalindrome = function(s) {
    let longestP = s[0];
    let palindrome = "";
    if(s.length === 1 ) return s;
    
    //the length of the palindrome is odd
    for(let index = 1; index < s.length-1; index++){
        if(s[index - 1] === s[index + 1]){
            palindrome = s[index - 1] + s[index] + s[index + 1];
            for(let k = 1; index - 1 - k > -1 && index + 1 + k < s.length; k++){
                if(s[index - 1 - k] === s[index + 1 + k]){
                    palindrome = s[index - 1 - k] + palindrome + s[index + 1 + k];
                }
                else{
                    break;
                }
            }
        }
        if (palindrome.length > longestP.length){
            longestP = palindrome;
        }
        palindrome = "";
    }
    
    //the length of the palindrome is pair
    for(let index = 0; index < s.length-1; index++){
        if(s[index] === s[index + 1]){
            palindrome = s[index] + s[index + 1];
            for(let k = 1; (index - k > -1) && (index + 1 + k < s.length); k++){
                if(s[index - k] === s[index + 1 + k]){
                    palindrome = s[index - k] + palindrome + s[index + 1 + k];
                }
                else{
                    break;
                }
            }
        }
        if (palindrome.length > longestP.length){
            longestP = palindrome;
        }
        palindrome = "";
    }
    return longestP;
};`