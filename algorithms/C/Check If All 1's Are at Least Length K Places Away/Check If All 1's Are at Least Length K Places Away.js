var kLengthApart = function(nums, k) {
	let arr = [] ;

	for(let i = 0 ; i < nums.length ; i++){
		if(nums[i] === 1)
			arr.push(i)
	}
	for(let i = arr.length -1  ; i >= 0 ; i--){
	   if(arr[i] - arr[i - 1] -1 < k )
		   return false
	}
	return true

};