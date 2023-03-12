var findBestValue = function (arr, target) {
	let low = 1, mid, high = Math.max(...arr);
	const getSumDif = val =>
		arr.reduce((acc, cur) => acc + (cur < val ? cur : val), 0) - target;
	while (low < high) {
		mid = (low + high) >>> 1;
		getSumDif(mid) < 0 ? (low = mid + 1) : (high = mid);
	}
	Math.abs(getSumDif(low - 1)) <= Math.abs(getSumDif(low)) && low--;
	return low;
};