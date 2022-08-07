var arrayNesting = function(nums) {
	return nums.reduce((result, num, index) => {
		let count = 1;

		while (nums[index] !== index) {
			const next = nums[index];
			[nums[index], nums[next]] = [nums[next], nums[index]];
			count += 1;
		}
		return Math.max(result, count);
	}, 0);
};