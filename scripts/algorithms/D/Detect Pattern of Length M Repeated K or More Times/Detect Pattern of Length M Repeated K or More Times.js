var containsPattern = function(arr, m, k) {
	const origin = arr.join(',');

	return arr.some((_, index, array) => {
		const check = arr.slice(index, m + index).join(',') + ',';

		index + k * m > arr.length && array.splice(index);
		const target = check.repeat(k).slice(0, -1);
		if (~origin.indexOf(target)) return true
	});
};