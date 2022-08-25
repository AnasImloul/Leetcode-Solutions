// Runtime: 84 ms (Top 55.68%) | Memory: 41.5 MB (Top 92.94%)
var decodeString = function(s) {
    const stack = [];

    for (let char of s) {
         if (char === "]") {
            let curr = stack.pop();
            let str = '';
            while (curr !== '[') {
                str = curr+ str;
                curr = stack.pop();
            }
            let num = "";
            curr = stack.pop();
            while (!isNaN(curr)) {
                num = curr + num;
                curr = stack.pop();
            }
            stack.push(curr);
            for (let i=0; i<Number(num);i++) {
                stack.push(str);
            }
        }
        else stack.push(char);
    }

    return stack.join('');
};