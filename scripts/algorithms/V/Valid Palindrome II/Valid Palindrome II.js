var validPalindrome = function(s, count) {
    let cursorStart = 0;
    let cursorEnd = s.length - 1;
    let countRemove = count || 0;
    
    while (cursorStart < cursorEnd) {
        if (s[cursorStart] === s[cursorEnd]) {
            cursorStart++;
            cursorEnd--;
        } else if (s[cursorStart] === s[cursorEnd - 1] && s[cursorStart + 1] === s[cursorEnd]) {
            return validPalindrome(s.slice(cursorStart + 1, cursorEnd + 1), countRemove + 1) || validPalindrome(s.slice(cursorStart, cursorEnd), countRemove + 1) ;
        } else if (s[cursorStart] === s[cursorEnd - 1]) {
            cursorEnd--;
            countRemove++;
        } else if (s[cursorStart + 1] === s[cursorEnd]) {
            cursorStart++;
            countRemove++;
        } else {
            return false;
        }
        if (countRemove > 1) return false;
    }
    
    return true;
};