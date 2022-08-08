  var numSubarrayBoundedMax = function(nums, left, right) {
        // si is start index
        // ei is end index
    let si=0, ei=0, finalCount=0, currentCount=0;

    while(ei<nums.length){ // moving ei till length of array
        if(left<=nums[ei] && nums[ei]<=right) // considering case number falls in the range
            {
                currentCount= ei-si+1;  // to get the subarrays b/w start index and end index
                finalCount+=currentCount; // add current count of subarrays to final count  which we will return at end
            }
        if(nums[ei]<left){
              finalCount+=currentCount;  // in this case when num is smaller than left range we won't calculate subarrays but just include the current count in final count.
        }
         if(nums[ei]>right){
              si=ei+1; // in this case when num is greater than right range we need to move our start index to end+1 because there won't be any subarrays that will fall in range.
             currentCount=0; // we will set current count 0 in such case.
        }

        ei++;
     }
    return finalCount;

    };
