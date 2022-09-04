// Runtime: 78 ms (Top 84.71%) | Memory: 42.5 MB (Top 77.27%)
var maxPower = function(s) {
    let count = 1;
    let maxNum =1;

    for(let i=0;i<s.length;i++){
       (s[i]===s[Number(i)+1]) ? count++ : count=1;
        maxNum = Math.max(count,maxNum);
    }

    return maxNum;
};