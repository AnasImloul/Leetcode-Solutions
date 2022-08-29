// Runtime: 140 ms (Top 67.23%) | Memory: 48.3 MB (Top 43.50%)
var countBalls = function(lowLimit, highLimit) {
    let obj={};
    for(let i=lowLimit; i<=highLimit; i++){
        i+=''; let sum=0;
        for(let j=0; j<i.length; j++){ sum+=i[j]*1; }
        obj[sum]?obj[sum]+=1:obj[sum]=1
    }
    return Math.max(...Object.values(obj));
};