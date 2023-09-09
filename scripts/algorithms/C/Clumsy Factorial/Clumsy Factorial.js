// Runtime: 56 ms (Top 66.6%) | Memory: 44.56 MB (Top 25.0%)

var clumsy = function(N) {
    let s = [N];
    let op = "*"
    for (let i=N-1; i>0; i--) {
        n = s.length;
        switch (op) {
            case "*":
                s[n-1] *= i;
                op = "/"
                break
            case "/":
                s[n-1] = (s[n-1]<0) ? -Math.floor(Math.abs(s[n-1])/i) : Math.floor(s[n-1]/i)
                op = "+"
                break;
            case "+":
                s.push(i)
                op = "-";
                break;
            case "-":
                s.push(-i)
                op = "*";
                break;
        }
    }
    // console.log(s)
    let ans = s.reduce((a,b) => a+b)
    return ans
};