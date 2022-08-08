var findNumbers = function(nums) {
	let count = 0;
	for(let num of nums){
		if(String(num).length % 2 === 0) count++
	}
	return count;
};
