var findPairs = function(nums, k) {
	nums.sort((a, b) => b - a);
	const { length } = nums;
	const hash = new Set();
	let left = 0;
	let right = 1;

	while (left < length - 1) {
		while (right < length) {
			const diff = nums[left] - nums[right];

			diff === k && hash.add(`${nums[left]},${nums[right]}`);
			diff > k
				? right = length
				: right += 1;
		}
		left += 1;
		right = left + 1;
	}
	return hash.size;
};