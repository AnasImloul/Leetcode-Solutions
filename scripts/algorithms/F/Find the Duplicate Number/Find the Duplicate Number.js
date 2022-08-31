// Runtime: 151 ms (Top 47.90%) | Memory: 70.3 MB (Top 5.11%)
var findDuplicate = function(nums) {
    let dup = new Map();

    for(let val of nums){
        if(dup.has(val)){
            dup.set(val, dup.get(val) + 1);
            return val;
        }
        else
            dup.set(val, 1);
    }
};