/**
 * @param {number[]} nums
 * @return {number}
 */
var countQuadruplets = function(nums) {
    const map = new Map();
    
    for(let i = 0; i < nums.length; i++) {
        let n = nums[i];
        
        if(map.has(n)) {
            let t = map.get(n);
            t.push(i);
            map.set(n, t);
        } else {
            map.set(n, [i]);
        }
    }
    
    let count = 0;
    
    for(let a = 0;a < nums.length - 3; a++) {
        for(let b = a + 1; b < nums.length - 2; b++) {
            for(let c = b + 1; c < nums.length - 1;c++) {
                let sum = nums[a] + nums[b] + nums[c];
                
                let indexes = map.get(sum) || [];
				//t is the d index that might exist
                let t = c + 1;
                
                let low = 0;
                let high = indexes.length - 1;
                let ans = -1;
                
                while(low <= high) {
                    let mid = low + Math.floor((high - low)/2);
                    
                    if(indexes[mid] === t) {
                        ans = mid;
                        break;
                    }
                    
                    if(indexes[mid] < t) {
                        low = mid + 1;
                    } else {
                        ans = mid;
                        high = mid - 1;
                    }
                }
                
                if(ans !== -1) {
                    count += indexes.length - ans;
                }
            }
        }
    }
    
    return count;
};
