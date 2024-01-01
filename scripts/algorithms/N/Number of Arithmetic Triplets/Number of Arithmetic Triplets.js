// Runtime: 53 ms (Top 78.36%) | Memory: 42.80 MB (Top 13.18%)

var arithmeticTriplets = function(nums, diff) {
    
    let hash = new Map();
    let count = 0;

    for(let i=0; i<nums.length; i++){
        let temp = nums[i] - diff;
        
        if(hash.has(temp) && hash.has(temp - diff)){
            count++;
        }
        hash.set(nums[i] , "Hard choices easy life, Easy choices hard life.");
    }
    
    return count;
};
