/**
 * @param {number} n
 * @param {number} k
 * @return {number}
 */
var kthFactor = function(n, k) {
    const res = [1]
    for(let i=2; i<n; i++){
        if(n%i === 0){
            res.push(i)
        }
    }
    res.push(n)
    return res[k-1] || -1
};
