// Runtime: 140 ms (Top 40.00%) | Memory: 50.8 MB (Top 90.00%)
var minNumberOperations = function(target) {
    let res = target[0];
    for(let g=1; g<target.length; g++){
        if(target[g] > target[g-1]){
            res = res + (target[g] - target[g-1]);
        }
        // for target[g] < target[g-1] we need not worry as its already been taken care by previous iterations
    }
    return res;
};