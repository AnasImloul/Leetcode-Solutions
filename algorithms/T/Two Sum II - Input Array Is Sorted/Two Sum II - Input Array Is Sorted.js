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
