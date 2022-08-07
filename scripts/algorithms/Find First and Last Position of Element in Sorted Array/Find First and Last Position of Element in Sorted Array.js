var searchRange = function(nums, target) {
    if (nums.length === 1) return nums[0] === target ? [0, 0] : [-1, -1];
    
    const findFirstInstance = (left, right) => {
        if (left === right) return left;
        var pivot;
        while (left < right) {
            if (left === pivot) left += 1;
            pivot = Math.floor((left + right) / 2);
            if (nums[pivot] === target) {
                if (nums[pivot - 1] !== target) return pivot;
                return findFirstInstance(left, pivot - 1);
            }
            if (nums[pivot] > target) right = pivot;
            else left = pivot;
        }
    }
    const findLastInstance = (left, right) => {
        if (left === right) return left;
        var pivot;
        while (left < right) {
            if (left === pivot) left += 1;
            pivot = Math.floor((left + right) / 2);
            if (nums[pivot] === target) {
                if (nums[pivot + 1] !== target) return pivot;
                return findLastInstance(pivot + 1, right);
            }
            if (nums[pivot] > target) right = pivot;
            else left = pivot;
        }
    }
    
    var left = 0,
        right = nums.length - 1,
        pivot;
    
    while (left < right) {
        if (left === pivot) left += 1;
        pivot = Math.floor((left + right) / 2);
        if (nums[pivot] === target) {
            var first = nums[pivot - 1] !== target ? pivot : findFirstInstance(left, pivot - 1);
            var last = nums[pivot + 1] !== target ? pivot : findLastInstance(pivot + 1, right);
            return [first, last];
        }
        if (nums[pivot] > target) right = pivot;
        else left = pivot;
    }
    
    return [-1, -1];
};
