var calculate = function(s) {

	const numStack = [[]];
	const opStack = [];

	const isNumber = char => !isNaN(char);

	function calculate(a, b, op){
		if(op === '+') return a + b;
		if(op === '-') return a - b;
	}

	let number = '';
	for (let i = 0; i < s.length; i++) {
		const char = s[i];

		if (char === ' ') continue;

		if (isNumber(char)) {
			number += char;
			continue;
		}

		if(number) { // i.e. char is not a number so the number has ended
			if (numStack[numStack.length - 1].length === 0) {
				numStack[numStack.length - 1].push(+number);
			} else {
				const a = numStack[numStack.length - 1].pop();
				const op = opStack.pop();
				numStack[numStack.length - 1].push(calculate(a, +number, op));
			}

			number = '';
		}

		if (char === '(') {
			if (numStack[numStack.length - 1].length === 0) {
				numStack[numStack.length - 1].push(0);
				opStack.push('+');
			}

			numStack.push([]); // Start a new stack for this parenthesis
			continue;
		}

		if (char === ')') {
			const b = numStack.pop().pop();
			const a = numStack[numStack.length - 1].pop();
			const op = opStack.pop();
			numStack[numStack.length - 1].push(calculate(a, b, op));
			continue;
		}

		if (char === '+' || char === '-') {
			if (numStack[numStack.length - 1].length === 0) {
				numStack[numStack.length - 1].push(0);
			}

			opStack.push(char);
			continue;
		}


		// We should never reach here
		throw new Error('Unexpected input: ' + char);
	}

	if(number){
		if (numStack[numStack.length - 1].length === 0) return +number;

		const a = numStack[numStack.length - 1].pop();
		const op = opStack.pop();
		numStack[0].push(calculate(a, +number, op));
	}

	return numStack.pop().pop();
};