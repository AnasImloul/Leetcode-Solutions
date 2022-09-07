// Runtime: 120 ms (Top 14.97%) | Memory: 43.4 MB (Top 8.82%)
var twoSum = function(numbers, target) {
    let store = {}
    for(let i=0;i<numbers.length;i++){
        if(store[numbers[i]]!==undefined){
            return [store[numbers[i]],i+1]
        }else{
            store[target-numbers[i]] = i+1
        }
    }
};