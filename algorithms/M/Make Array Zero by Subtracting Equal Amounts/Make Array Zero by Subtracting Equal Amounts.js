var minimumOperations = function(nums) {
    let k = new Set(nums) // convert array to set; [...nums] is destructuring syntax 
    return k.has(0) ? k.size-1 : k.size; // we dont need 0, hence if zero exists return size-1
};
