// Runtime: 120 ms (Top 27.08%) | Memory: 41.9 MB (Top 89.58%)

var minOperations = function(n) {
    let reqNum;
    if(n%2!=0){
        reqNum = Math.floor(n/2)*2+1
    }else{
        reqNum = ((Math.floor(n/2))*2+1 + (Math.floor(n/2) -1)*2+1)/2
    }
    let count = 0;
    for(let i=1; i<reqNum; i +=2){
        count += (reqNum-i)
    }
    return count
};