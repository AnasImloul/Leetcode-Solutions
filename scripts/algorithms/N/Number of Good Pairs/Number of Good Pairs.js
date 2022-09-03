// Runtime: 97 ms (Top 35.93%) | Memory: 42.3 MB (Top 27.32%)
var numIdenticalPairs = function(nums) {
    let counter = 0;
    let map = {};
    for(let num of nums) {
        if(map[num]) {
            counter += map[num];
            map[num]++;
        } else {
            map[num] = 1;
        }
    }
    return counter;
};