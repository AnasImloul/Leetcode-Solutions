var taskSchedulerII = function(tasks, n) {
	const config = {};
	let totalIteration = 0;
	let currentTime = 0;
	for (const iterator of tasks) {
		currentTime++;
		if (!config[iterator]) {
			config[iterator] = 0;
		} else {
			if (config[iterator] > currentTime) {
				let difference = config[iterator] - currentTime;
				totalIteration += difference;
				currentTime += difference;
			}
		}
		config[iterator] = currentTime + n + 1;
		totalIteration++;
	}

	return totalIteration;
};