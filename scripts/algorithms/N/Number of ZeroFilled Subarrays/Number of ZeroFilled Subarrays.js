// Runtime: 72 ms (Top 87.27%) | Memory: 61.30 MB (Top 5.45%)

/**
 * @param {number[]} nums
 * @return {number}
 */
function sum(n){
    return n*(n+1)/2;
}

var zeroFilledSubarray = function(arr) {
    let res=0;
    let count=0;
    for(let i=0;i<arr.length;i++){
        if(arr[i]){
            res+=sum(count);
            count=0;
        }
        else{
            count++;
        }
    }
    res+=sum(count);
    return res;
};
