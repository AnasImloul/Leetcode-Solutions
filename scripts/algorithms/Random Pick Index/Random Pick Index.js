var Solution = function(nums) {
	this.map = nums.reduce((result, num, index) => {
		const value = result.get(num) ?? [];

		value.push(index);
		result.set(num, value);
		return result;
	}, new Map());
};

Solution.prototype.pick = function(target) {
	const pick = this.map.get(target);
	const random = Math.random() * pick.length | 0;

	return pick[random];
};