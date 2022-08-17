var findRadius = function(houses, heaters) {
	houses.sort((a, b) => a - b);
	heaters.sort((a, b) => a - b);
	let heaterPos = 0;
	const getRadius = (house, pos) => Math.abs(heaters[pos] - house);

	return houses.reduce((radius, house) => {
		while (
			heaterPos < heaters.length &&
			getRadius(house, heaterPos) >= 
			getRadius(house, heaterPos + 1)
		) heaterPos += 1;

		const currentRadius = getRadius(house, heaterPos);
		return Math.max(radius, currentRadius);
	}, 0);
};