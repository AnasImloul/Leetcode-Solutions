// Runtime: 326 ms (Top 98.70%) | Memory: 81.8 MB (Top 88.96%)
// time O(N + M) Space O(N) N = s.length M = query.length
var platesBetweenCandles = function(s, queries) {
    let platPreFixSum = [...Array(s.length + 1)];
    let leftViewCandle = [...Array(s.length + 1)];
    let rightViewCandle = [...Array(s.length + 1)];

    platPreFixSum[0] = 0;
    leftViewCandle[0] = -1;
    rightViewCandle[s.length] = -1;

    for(let i = 1; i <= s.length; i++){
        platPreFixSum[i] = s[i-1] == '*' ? platPreFixSum[i - 1] + 1 : platPreFixSum[i - 1];
        leftViewCandle[i] = s[i - 1] == '|' ? i - 1 : leftViewCandle[i - 1];
        rightViewCandle[s.length - i] = s[s.length - i] == '|' ? s.length - i : rightViewCandle[s.length - i + 1];
    }

    let result = [];

    queries.forEach(([left, right]) => {
        if(rightViewCandle[left] >= 0 && leftViewCandle[right + 1] >= 0 &&
           rightViewCandle[left] < leftViewCandle[right + 1]) {
            result.push(platPreFixSum[leftViewCandle[right + 1]] - platPreFixSum[rightViewCandle[left]]);
        } else {
            result.push(0);
        }
    });

    return result;

};