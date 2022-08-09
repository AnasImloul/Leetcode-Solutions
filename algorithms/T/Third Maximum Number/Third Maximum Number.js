var thirdMax = function(nums) {
    nums.sort((a,b) => b-a);
	//remove duplicate elements
    for(let i=0; i<nums.length;i++){
        if(nums[i] === nums[i+1]){
            nums.splice(i+1, 1);
            i--
        }
    }
    
    return nums[2] !=undefined?nums[2]: nums[0]
};
