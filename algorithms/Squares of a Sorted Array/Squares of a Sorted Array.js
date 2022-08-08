var sortedSquares = function(nums) {
	let left = 0;
	let right = nums.length - 1;
	const arr = new Array(nums.length);
	let arrIndex = arr.length - 1;

	while (left <= right) {
		if (Math.abs(nums[left]) > Math.abs(nums[right])) {
			arr[arrIndex] = nums[left] * nums[left];
			left++;
		} else {
			arr[arrIndex] = nums[right] * nums[right];
			right--;
		}
		arrIndex--;
	}

	return arr;
};
