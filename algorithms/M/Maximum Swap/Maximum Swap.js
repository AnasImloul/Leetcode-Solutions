var maximumSwap = function(num) {
	const nums = `${num}`.split('');

	for (let index = 0; index < nums.length - 1; index++) {
		const current = nums[index];
		const diff = nums.slice(index + 1);
		const max = Math.max(...diff);

		if (current >= max) continue;
		const swapIndex = index + diff.lastIndexOf(`${max}`) + 1;
		[nums[index], nums[swapIndex]] = [nums[swapIndex], nums[index]];
		break;
	}
	return nums.join('');
};