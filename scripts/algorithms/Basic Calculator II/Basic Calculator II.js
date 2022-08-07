/**
 * @param {string} s
 * @return {number}
 */
var calculate = function(s) {
    const n = s.length;
    let currNum = 0, lastNum = 0, res = 0;
    let op = '+';
    
    for (let i = 0; i < n; i++) {
        let currChar = s[i];
        
        if (currChar !== " " && !isNaN(Number(currChar))) {
            currNum = currNum * 10 + Number(currChar);
        }
        
        if (isNaN(Number(currChar)) && currChar !== " " || i === n - 1) {
            if (op === '+' || op === '-') {
                res += lastNum;
                lastNum = (op === '+' ? currNum : -currNum);
            } else if (op === '*') {
                lastNum *= currNum;
            } else if (op === '/') {
                lastNum = Math.floor(Math.abs(lastNum) / currNum) * (lastNum < 0 ? -1 : 1);
            }
            
            op = currChar;
            currNum = 0;
        }
    }
    
    res += lastNum;
    return res;
};
