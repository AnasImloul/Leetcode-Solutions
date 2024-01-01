// Runtime: 53 ms (Top 32.76%) | Memory: 41.40 MB (Top 93.1%)

/**
 * @param {number} n
 * @return {number}
 */
var countNumbersWithUniqueDigits = function(n) {
    if(n==0) return 1;
    let res=1;
    let k=0;
    for(let i=1; i<=n; i++){
        k=1;
        for(let j=0; j<i; j++){
            if(j==0){ 
             k*=(9-j);}
            else{
             k*=(10-j);}
        }
        res+=k;
    }
    return res;

};
