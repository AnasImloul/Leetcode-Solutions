// Runtime: 59 ms (Top 99.32%) | Memory: 49.50 MB (Top 66.21%)

var mostFrequentEven = function(nums) {
    let map = new Map();
    let max_freq = 0, element = -1;
    for(let num of nums){
        if(num % 2 == 0)    map.set(num, (map.get(num) || 0) + 1);
        if(num % 2 == 0 && max_freq <= map.get(num)){
            if(max_freq == map.get(num)){
                element = Math.min(element, num);
            }else{
                element = num;
                max_freq = map.get(element);
            }
        }
    }
    return element;
};
