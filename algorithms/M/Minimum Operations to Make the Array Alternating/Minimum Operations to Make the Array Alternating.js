/**
 * @param {number[]} nums
 * @return {number}
 */

var minimumOperations = function(nums) {
    let countOddId = {}    
    let countEvenId = {}
    if(nums.length === 1) return 0
    if(nums.length === 2 && nums[0] === nums[1]) {
        return 1
    }
    nums.forEach((n, i) => {
        if(i%2) {
            if(!countOddId[n]) {
                countOddId[n] = 1;
            } else {
                countOddId[n]++
            }
        } else {
            if(!countEvenId[n]) {
                countEvenId[n] = 1;
            } else {
                countEvenId[n]++
            }
        }
    })
    
    const sortedEven = Object.entries(countEvenId).sort((a, b) => {
        return  b[1] - a[1]
    })

    const sortedOdd = Object.entries(countOddId).sort((a, b) => {
        return  b[1] - a[1]
    })

    if(sortedEven[0][0] === sortedOdd[0][0]) {
        let maxFirst =0;
        let maxSec =0;

        if(sortedEven.length === 1) {
            maxFirst = sortedEven[0][1];
            maxSec = sortedOdd[1]? sortedOdd[1][1] : 0;
            return  nums.length - (maxFirst + maxSec)  
        } 
        
        if(sortedOdd.length === 1) {
            maxFirst = sortedOdd[0][1];
            maxSec = sortedEven[1] ? sortedEven[1][1] : 0;
            return  nums.length - (maxFirst + maxSec)  
        }
        if(sortedEven[0][1] >= sortedOdd[0][1] && sortedEven[1][1] <= sortedOdd[1][1]) {
            maxFirst = sortedEven[0][1]
            maxSec = sortedOdd[1][1]
            return  nums.length - (maxFirst + maxSec)  
        } else {
            maxFirst = sortedOdd[0][1]
            maxSec = sortedEven[1][1]
            return  nums.length - (maxFirst + maxSec)  
        }
    } else {
        return nums.length - (sortedEven[0][1] + sortedOdd[0][1])
    }

};
