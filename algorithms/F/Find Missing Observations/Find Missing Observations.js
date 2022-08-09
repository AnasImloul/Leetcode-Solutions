var missingRolls = function(rolls, mean, n) {
    let res = [];
    let sum = ((n + rolls.length) * mean) - rolls.reduce((a,b)=>a+b);
    if(sum>6*n || sum<1*n) return res;
    let dec = sum % n;
    let num = Math.floor(sum / n);
    for(let i = 0; i < n; i++){
        if(dec) res.push(num+1), dec--;
        else res.push(num);
    }
    return res;
};
