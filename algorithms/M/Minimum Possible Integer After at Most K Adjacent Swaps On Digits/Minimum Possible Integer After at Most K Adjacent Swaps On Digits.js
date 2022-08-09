/**
 * @param {string} num
 * @param {number} k
 * @return {string}
 
 Idea is based on bubble sorting with limited steps k
 
 */

var minInteger = function(num, k) {
    if (num.length == 1)
        return num;
    
    let nums = num.split('');
    let i = 0, j = 0;
    
    while (k && i < num.length-1) {
//         step 0: if leading zero, check the next digit
        if (nums[i] == '0') {
            i++;
            j++;
            continue;
        }
        
//         step 1: find the min digit 
        let p = j, steps = 0;
        while (nums[p] !== '0' && j < nums.length && steps <= k) {
            if (nums[j] < nums[p])
                p = j;
            j++;
            steps++;
        }
        
//         step 2: nums[i] is the current minimum digit --> check next digit
        if (p == i) {
            i++;
            j = i;
            continue;
        }
            
//          step 3: move the min digit to i
        for (; p > i; p--) {
            [nums[p], nums[p-1]] = [nums[p-1], nums[p]];
            k--;
        }
        
        i++;
        j = i;
        
    }
    
    return nums.join('');
};
