// Runtime: 948 ms (Top 34.96%) | Memory: 100.4 MB (Top 5.58%)
/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number[]}
 */
var maxSlidingWindow = function(nums, k) {
    var i=0, j=0, max=0, deque=[], output=[];
    while(j<nums.length){
        if(deque.length === 0){
            deque.push(nums[j])
        }else if(deque[deque.length-1] > nums[j]){
            deque.push(nums[j])
        }else{
            while(deque[deque.length-1] < nums[j]){
                deque.pop()
            }
            deque.push(nums[j])
        }

        if(j-i+1 === k){
            if(nums[i] === deque[0]){
                output.push(deque.shift());
            }else{
                output.push(deque[0])
            }
            i++;
        }
        j++;

    }
    return output
};