var minStartValue = function(nums) {
    var min = 1;
    var sum = 0;
	
    for(var i=0;i<nums.length;i++){
        sum = sum+nums[i];
        min = Math.min(min,sum);
    }
    if(min == 1){
        return min;
    }
	// add 1 to negative of min value obtained to keep the sum always positive
    return (-1*min)+1;
};
