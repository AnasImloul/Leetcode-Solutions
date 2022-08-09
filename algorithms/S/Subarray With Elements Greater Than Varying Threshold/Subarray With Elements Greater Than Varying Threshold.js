/**
 * @param {number[]} nums
 * @param {number} threshold
 * @return {number}
 */
var validSubarraySize = function(nums, threshold) {
    /*
    Approach: Use monotonous increasing array
    */
    let stack=[];
    for(let i=0;i<nums.length;i++){
        let start = i;
        while(stack.length>0 && stack[stack.length-1][0]>nums[i]){
            let popped = stack.pop();
            let min = popped[0];
            let len = i-popped[1];
            if(min>threshold/len){
                return len;
            }
            start = popped[1];
        }
        stack.push([nums[i],start]);
    }
    let end = nums.length-1;
    for(let i=0;i<stack.length;i++){
        let len = end - stack[i][1] +1;
        let min = stack[i][0];
        if(min>threshold/len){
            return len;
        }
    }
    return -1;
};

