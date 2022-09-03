// Runtime: 129 ms (Top 42.86%) | Memory: 49.9 MB (Top 85.71%)
var addRungs = function(rungs, dist) {
    let res = 0;
    let prev = 0;
    for ( let i = 0; i < rungs.length; i++ ){
        res += Math.floor(( rungs[i] - prev - 1 ) / dist );
        prev = rungs[i];
    }
    return res;
};
