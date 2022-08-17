var minSteps = function(n) {
	let result = 0;

	for (let index = 2; index <= n; index++) {
		while (n % index === 0) {
			result += index;
			n /= index;
		}
	}
	return result;
};