var fourSum = function(nums, target) {
    nums.sort((a, b) => a - b);
    const res = [];
    
    for(let i=0; i<nums.length-3; i++) {
        for(let j=i+1; j<nums.length-2; j++) {
            let min = j + 1;
            let max = nums.length - 1;
            while(min < max) {
                const sum = nums[i] + nums[j] + nums[min] + nums[max];
                if(sum === target) {
                    res.push([nums[min], nums[max], nums[i], nums[j]]);
                    while(nums[min] === nums[min+1]) min++;
                    while(nums[max] === nums[max-1]) max--;
                    min++;
                    max--;
                }
                
                else if(sum > target) 
                    max--;
                else
                    min++
            }
            while(nums[j] === nums[j+1]) j++;
        }
        while(nums[i] === nums[i+1]) i++;
    }
    
    return res;
};
