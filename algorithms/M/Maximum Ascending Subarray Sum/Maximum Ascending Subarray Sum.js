var maxAscendingSum = function(nums) {
	const subarray = nums.reduce((acc, curr, index) => {
		curr > nums[index - 1] ? acc[acc.length - 1] += curr : acc.push(curr);
		return acc;
	}, []);

	return Math.max(...subarray);
};