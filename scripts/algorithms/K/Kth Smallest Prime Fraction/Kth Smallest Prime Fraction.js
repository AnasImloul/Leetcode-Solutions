// Runtime: 2630 ms (Top 7.69%) | Memory: 195.70 MB (Top 38.46%)

/**
 * @param {number[]} arr
 * @param {number} k
 * @return {number[]}
 */
var kthSmallestPrimeFraction = function(arr, k) {
    const res = [];
	arr.forEach((item, i) => {
		for (let j = i + 1; j < arr.length; j++) {
			res.push([ item / arr[j], item, arr[j] ]);
		}
	});
	res.sort((a, b) => a[0] - b[0]);
	return [ res[k - 1][1], res[k - 1][2] ];
};
