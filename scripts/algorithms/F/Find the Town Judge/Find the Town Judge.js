// Runtime: 207 ms (Top 21.58%) | Memory: 50.5 MB (Top 79.28%)
var findJudge = function(n, trust) {
    const length = trust.length;
    let possibleJudge = [], judgeMap = new Map(), value, judge = -1;
    for(let i = 0; i < length; i++) {
        if(judgeMap.has(trust[i][0])){
            value = judgeMap.get(trust[i][0]);
            value.push(trust[i][1]);
            judgeMap.set(trust[i][0], value);
        }
        else {
            judgeMap.set(trust[i][0], [trust[i][1]]);
        }
    }
    value = [];
    for(let i = 1; i <= n; i++) {
        if(!judgeMap.has(i)) {
            possibleJudge.push(i);
        }
        else {
            value.push([i,judgeMap.get(i)]);
        }
    }
    if(!value.length || value.length !== n-1) {
        if(possibleJudge.length === 1) return possibleJudge[0];
        return judge;
    }
    for(let i = 0; i < possibleJudge.length; i++) {
        judge = possibleJudge[i];
        for(let j = 0; j < value.length; j++) {
            if(value[j][1].indexOf(judge) < 0) {
                judge = -1;
                break;
            }
        }
        if(judge !== -1) break;
    }
    return judge;
};