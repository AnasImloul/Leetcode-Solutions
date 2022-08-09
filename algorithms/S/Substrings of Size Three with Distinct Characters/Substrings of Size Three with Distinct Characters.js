var countGoodSubstrings = function(s) {
	let good = 0;

	for (let index = 0; index < s.length - 2; index++) {
		const subStr = s.slice(index, index + 3);
		const set = new Set(subStr);

		set.size === 3 && (good += 1);
	}
	return good;
};