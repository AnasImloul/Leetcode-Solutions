var canMeasureWater = function(jug1Capacity, jug2Capacity, targetCapacity) {
	const gcd = (x, y) => y === 0 ? x : gcd(y, x % y);

	return jug1Capacity + jug2Capacity >= targetCapacity && 
		targetCapacity % gcd(jug1Capacity, jug2Capacity) === 0;
};