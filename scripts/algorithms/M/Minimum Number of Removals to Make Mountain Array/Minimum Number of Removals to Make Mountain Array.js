var minimumMountainRemovals = function(nums) {
    let n=nums.length
    let previous=Array.from({length:n},item=>1)
    let previous2=Array.from({length:n},item=>1)
    //calcultaing left and right side LIS in single iteration
    for (let i=0;i<n;i++){
        for (let j=0;j<i;j++){
            //reverse indexes
            let i2=n-1-i
            let j2=n-1-j
            //calculating first dp serially 
            if (nums[i]>nums[j] && previous[i]<previous[j]+1){
                previous[i]=previous[j]+1
            }
            //calculating second dp reversely
            if (nums[i2]>nums[j2] && previous2[i2]<previous2[j2]+1){
                previous2[i2]=previous2[j2]+1
            }
        }
    }
    let max=0
    for (let i=0;i<n;i++){
        //golden condition// to avoid only increasing and decreasing
        //because if a combination of 1 indicates its increasing fully or decreasing !
        if (previous[i]>1 && previous2[i]>1){
        //at a specific index highest increasing will come from left LIS
        // and highest decreasing will come from right side LIS
        max=Math.max(max,previous[i]+previous2[i]-1)
        }
    }
    return n-max //we need to remove the rest from total
};
