var checkSubarraySum = function(nums, k) {
	const hash = new Map([[0, -1]]);
	let sum = 0;

	for (let index = 0; index < nums.length; index++) {
		sum += nums[index];
		const r = sum % k;

		if (hash.has(r)) {
			if (index - hash.get(r) > 1) return true;
		}
		else hash.set(r, index);
	}
	return false;
};