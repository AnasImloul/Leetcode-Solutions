var judgeSquareSum = function(c) {
	let a = 0;
	let b = Math.sqrt(c) | 0;

	while (a <= b) {
		const sum = a ** 2 + b ** 2;
		if (sum === c) return true;
		sum > c ? b -= 1 : a += 1;
	}
	return false;
};