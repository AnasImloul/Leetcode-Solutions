// Runtime: 154 ms (Top 33.70%) | Memory: 56.1 MB (Top 16.54%)
var minRemoveToMakeValid = function(s) {
    let validity = 0;
    for(let index = 0; index < s.length; index++) {
        if(s[index] == ')') {
            if(validity == 0) {
                s = s.substring(0,index)+s.substring(index+1);
                index--;
            }
            else {
                validity--;
            }
        }
        else if(s[index] == '(') {
            validity++;
        }
    }
    if(validity > 0) {
        for(let index = s.length-1; index >= 0; index--) {
            if(s[index] == '(') {
                s = s.substring(0,index)+s.substring(index+1);
                validity--;
                if(validity === 0) break;
            }
        }
    }
    return s;
};