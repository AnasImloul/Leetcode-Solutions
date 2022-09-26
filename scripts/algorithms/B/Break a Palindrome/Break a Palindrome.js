// Runtime: 96 ms (Top 40.74%) | Memory: 41.7 MB (Top 89.81%)
var breakPalindrome = function(palindrome) {
    // domain n / 2 k pehlay
    palindrome = palindrome.split('');
    const len = palindrome.length;
    if(len == 1) return "";
    const domain = Math.floor(len / 2);
    let firstNonAChar = -1, lastAChar = -1;
    for(let i = 0; i < domain; i++) {
        if(palindrome[i] != 'a') {
            firstNonAChar = i;
            break;
        }
    }
    if(firstNonAChar == -1) {
        palindrome[len - 1] = 'b';
    } else palindrome[firstNonAChar] = 'a';
    return palindrome.join('');
};