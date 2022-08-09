var longestValidParentheses = function(s) {
    let validity = 0, length = 0, max =0;
    for(let index = 0; index < s.length; index++) { // front loop
        if(s[index] == ')') {
            if(validity == 0) {
                max = max > length ? max : length;
                length = 0;
            }
            else {
                validity--;
                length += 2;
            }        
        }
        else if(s[index] == '(') {
            validity++;
        }
        if(validity == 0) {
            max = max > length ? max : length;
        }
    }
    length = 0;
    validity = 0;
    for(let index = s.length-1; index >= 0; index--) { // back loop
        if(s[index] == '(') {
            if(validity == 0) {
                max = max > length ? max : length;
                length = 0;
            }
            else {
                validity--;
                length += 2;
            }        
        }
        else if(s[index] == ')') {
            validity++;
        }
        if(validity == 0) {
            max = max > length ? max : length;
        }
    }
    return max;
};
