var carFleet = function(target, position, speed) {
    for (let i = 0 ; i < position.length ; i ++) {
        position[i] = [target - position[i], speed[i]]
    }
    position.sort((a, b) => { return a[0] - b[0] })
    let count = 1, prev = position[0][0] / position[0][1]
    for (let i = 1 ; i < position.length ; i ++) {
		// if the time taken is longer then it will cause another fleet
        if (position[i][0] / position[i][1] > prev) {
            count ++
            prev = position[i][0] / position[i][1]
        }
    }
    
    return count
};
