var maxRepeating = function(sequence, word) {
	let result = 0;

	while (sequence.includes(word.repeat(result + 1))) {
		result += 1;
	};
	return result;
};