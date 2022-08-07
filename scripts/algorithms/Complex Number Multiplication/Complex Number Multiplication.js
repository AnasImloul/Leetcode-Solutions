var complexNumberMultiply = function(num1, num2) {
	let [realA, imaginaryA] = num1.split('+');
	let [realB, imaginaryB] = num2.split('+');
	imaginaryA = parseInt(imaginaryA);
	imaginaryB = parseInt(imaginaryB);
	const real = realA * realB - imaginaryA * imaginaryB;
	const imaginary = realA * imaginaryB + imaginaryA * realB;

	return `${real}+${imaginary}i`;
};