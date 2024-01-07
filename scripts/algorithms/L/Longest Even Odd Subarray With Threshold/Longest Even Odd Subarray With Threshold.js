// Runtime: 126 ms (Top 80.41%) | Memory: 50.50 MB (Top 34.02%)

/**
 * @param {number[]} nums
 * @param {number} threshold
 * @return {number}
 */
var longestAlternatingSubarray = function(nums, threshold) {
    let start = null;
    let end = null;
    let isPrevEven = null;
    let i=0;
    let maxLength = 0;
    if(nums.length === 0){
        return null;
    }
    while(i<nums.length){
        if(nums[i] <= threshold){
            if(nums[i] % 2 === 0){
                if(start === null){
                    start = i;
                } else {
                    if(isPrevEven){
                        end = i-1
                        if(start !== null){
                            maxLength = Math.max(maxLength, ((end-start)+1));
                        }
                        //assigning start to be same index, as we have to start with even number only
                        start = i;
                    } else {
                        // do nothing
                    }
                }
            }

            if(nums[i] % 2 !== 0){
                if(start === null){
                    //do nothing
                } else {
                    if(isPrevEven){
                        // do nothing
                    } else {
                        end = i-1;
                        if(start !== null){
                            maxLength = Math.max(maxLength, ((end-start)+1));
                        }
                         //assigning start to be same index, as we have to start with even number only, and odd can't be assigned
                        start = null;
                    }
                }
            }
        } else {
            end = i-1;
            if(start !== null){
                maxLength = Math.max(maxLength, ((end-start)+1));
            }
            
            start = null;
            isPrevEven = null;
        }
        isPrevEven = nums[i] % 2 === 0;
        i++;
    }

    if(start !== null){
        maxLength = Math.max(maxLength, nums.length - start);
    }

    return maxLength;
};
