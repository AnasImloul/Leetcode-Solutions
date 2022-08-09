var numberOfBoomerangs = function(points) {
	const POINTS_LEN = points.length;
	let result = 0;

	for (let i = 0; i < POINTS_LEN; i++) {
		const hash = new Map();

		for (let j = 0; j < POINTS_LEN; j++) {
			if (i === j) continue;
			const [x1, y1] = points[i];
			const [x2, y2] = points[j];
			const dis = Math.pow(x1 - x2, 2) + Math.pow(y1 - y2, 2);
			const value = hash.get(dis) ?? 0;

			if (value > 0) result += value * 2;
			hash.set(dis, value + 1);
		}
	}

	return result;
};