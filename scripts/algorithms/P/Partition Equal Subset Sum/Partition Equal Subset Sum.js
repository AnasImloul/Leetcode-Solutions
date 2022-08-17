var canPartition = function(nums) {
    let sum = nums.reduce((prevVal, currValue) => prevVal + currValue, 0); // sum of each values
    if (sum % 2 !== 0) return false; // return false if odd sum
    
    let target = sum / 2;  // ex.[1,5,11,5]  target is half which is 11
    let dp = new Set(); // add unique values
    dp.add(0); //intialize with 0
    for (var i = nums.length - 1; i >= 0; i--) {  //start from end
        nextDp = new Set(); 
        for (const ele of dp.values()) {
           let newVal = ele + nums[i];
           if(newVal === target) return true; 
           nextDp.add(newVal); 
        }
        dp = new Set([...dp, ...nextDp]);
    }
    
    return false;
};
