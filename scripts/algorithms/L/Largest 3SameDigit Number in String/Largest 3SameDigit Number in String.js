// Runtime: 62 ms (Top 51.3%) | Memory: 45.70 MB (Top 9.7%)

var largestGoodInteger = function(num) {
    let returnVal = ''
    for(let i=0;i<num.length;i++){
        if(num[i] === num[i+1] && num[i] === num[i+2]){
            const n = num[i] + num[i+1] + num[i+2]
            if(returnVal < n) returnVal=n
        }
    }
    return returnVal;
};