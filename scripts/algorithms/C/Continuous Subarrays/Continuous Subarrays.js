// Runtime: 113 ms (Top 94.74%) | Memory: 54.10 MB (Top 100.0%)

/**
 * @param {number[]} nums
 * @return {number}
 */
var continuousSubarrays = function(nums) {
    let ans=0,min,max;
    for(let left=0,right=0;right<nums.length;right++){
        let c = nums[right];
        if(right===0){//its hte first number, we can always add it and set the min,max
            ans += right-left+1;//count all the sub arrays ending at the current element
            min = c-2;
            max = c+2;
        }else if(c>=min && c<=max){//we can add the current number and update the min,max
            ans += right-left+1;//count all the sub arrays ending at the current element
            min = Math.max(min,c-2);
            max = Math.min(max,c+2);
        }else{//we can't add the current number, now start new sub array from current element and go to the left side so that we can find all the subarrays ending at the current element.
            left = right-1;
            min = c-2;
            max = c+2;
            while(nums[left]>=min && nums[left]<=max){
                min = Math.max(min,nums[left]-2);
                max = Math.min(max,nums[left]+2);
                left--;
            }
            left++;//take care of the last element as this was invalid.
            ans += right-left+1;//count all the sub arrays ending at the current element
        }
    }
    return ans;
};
