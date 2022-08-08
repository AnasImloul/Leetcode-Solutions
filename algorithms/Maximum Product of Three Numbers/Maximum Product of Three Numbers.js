var maximumProduct = function(nums) {
    nums.sort((a, b) => a-b)
    
    var lastNumber = nums.length - 1
    var midNumber = nums.length - 2
    var firstNumber = nums.length - 3
    var total = nums[lastNumber] * nums[midNumber] * nums[firstNumber]
    return total
    
};
