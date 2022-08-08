var exclusiveTime = function(n, logs) {
	const stack = [];
	let preTimeStamp = 0;

	return logs.reduce((times, log) => {
		const [id, status, timeStamp] = log.split(':');
		const time = +timeStamp - preTimeStamp;
		const { length } = stack;

		if (length) {
			const lastId = stack[length - 1];
			times[lastId] += time;
		}
		preTimeStamp = +timeStamp;

		if (status === 'start') stack.push(id);
		else {
			const lastId = stack.pop();
			times[lastId] += 1;
			preTimeStamp += 1;
		}
		return times;
	}, Array(n).fill(0));
}