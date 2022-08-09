var pivotIndex = function(nums) {
    let leftValue = 0
    let rightValue = nums.reduce((a, b) => a + b )
    for(let pivot = 0; pivot < nums.length; pivot++) {  
        leftValue += nums[pivot - 1] || 0
        rightValue -= nums[pivot]
        if (leftValue === rightValue) return pivot
    }
    return -1
};
