var numSubarrayProductLessThanK = function(nums, k) {
    var used = new Array(nums.length).fill(0);
    var l, r, runsum=1;
    let ans=0;
    
    l = 0;
    r = 0;
    while( r < nums.length ) {
        if( r < nums.length && runsum * nums[r] >= k ) {
            if( r != l )
                runsum /= nums[l];
            else
                r++;
            l++;
        } else if( l <= r ) {
            runsum *= nums[r];
            r++;
            ans += (r-l);
        } else break;
    }
    
    return ans;
};
