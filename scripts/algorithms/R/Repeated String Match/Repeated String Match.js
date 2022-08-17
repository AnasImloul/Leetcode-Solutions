var repeatedStringMatch = function(a, b) {
	const initRepeatTimes = Math.ceil(b.length / a.length);
	const isMatch = (times) => a.repeat(times).includes(b);

	if (isMatch(initRepeatTimes)) return initRepeatTimes;
	if (isMatch(initRepeatTimes + 1)) return initRepeatTimes + 1;
	return -1;
};