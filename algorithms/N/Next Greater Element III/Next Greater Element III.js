var nextGreaterElement = function(n) {
	const MAX_VALUE = 2 ** 31 - 1;
	const nums = `${n}`.split('');
	let findPos;

	for (let index = nums.length - 2; index >= 0; index--) {
		if (nums[index] < nums[index + 1]) {
			findPos = index;
			break;
		}
	}

	if (findPos === undefined) return -1;
	for (let index = nums.length - 1; index >= 0; index--) {
		if (nums[index] > nums[findPos]) {
			[nums[index], nums[findPos]] = [nums[findPos], nums[index]];
			break;
		}
	}

	const mantissa = nums.slice(findPos + 1).sort((a, b) => a - b).join('');
	const result = Number(nums.slice(0, findPos + 1).join('') + mantissa);
	return result > MAX_VALUE ? -1 : result;
};