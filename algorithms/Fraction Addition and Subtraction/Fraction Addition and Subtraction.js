var fractionAddition = function(expression) {
	const fractions = expression.split(/[+-]/).filter(Boolean);
	const operator = expression.split(/[0-9/]/).filter(Boolean);
	expression[0] !== '-' && operator.unshift('+');

	const gcd = (a, b) => b === 0 ? a : gcd(b, a % b);
	const lcm = fractions.reduce((result, fraction) => {
		const denominator = fraction.split('/')[1];
		return result * denominator / gcd(result, denominator);
	}, 1);

	const molecularSum = fractions.reduce((total, fraction, index) => {
		const [molecular, denominator] = fraction.split('/');
		const multiple = lcm / denominator * (operator[index] === '+' ? 1 : -1);
		return total + molecular * multiple;
	}, 0);

	const resultGcd = gcd(Math.abs(molecularSum), lcm);
	return `${molecularSum / resultGcd}/${lcm / resultGcd}`;
};