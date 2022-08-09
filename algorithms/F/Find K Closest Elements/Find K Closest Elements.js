var findClosestElements = function(arr, k, x) {
	const result = [...arr];

	while (result.length > k) {
		const start = result[0];
		const end = result.at(-1);

		x - start <= end - x 
			? result.pop() 
			: result.shift();
	}
	return result;
};