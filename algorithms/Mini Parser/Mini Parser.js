var deserialize = function(s) {
	if (s[0] !== '[') return new NestedInteger(s);

	const stack = [];
	let start = 0;
	const process = {
		'['(index) {
			stack.push(new NestedInteger());
			start = index + 1;
		},
		','(index) {
			if (index > start) {
				const value = s.slice(start, index);
				stack[stack.length - 1].add(new NestedInteger(value));
			}
			start = index + 1;
		},
		']'(index) {
			this[','](index);
			if (stack.length < 2) return;
			const last = stack.pop();
			stack[stack.length - 1].add(last);
		}
	};

	[...s].forEach((current, index) => process[current]?.(index));

	return stack[0];
};