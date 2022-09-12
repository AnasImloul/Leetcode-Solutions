// Runtime: 101 ms (Top 73.64%) | Memory: 42.7 MB (Top 97.01%)
var findMinDifference = function(timePoints) {
    const DAY_MINUTES = 24 * 60;
    const set = new Set();

    for (let index = 0; index < timePoints.length; index++) {
        const time = timePoints[index];
        const [hours, minutes] = time.split(':');
        const totalMinutes = hours * 60 + +minutes;
        if (set.has(totalMinutes)) return 0;
        set.add(totalMinutes);
    }

    const timeMinutes = [...set].sort((a, b) => a - b);
    return timeMinutes.reduce((min, time, index) => {
        const next = timeMinutes[index + 1];
        const diff = next ? next - time : DAY_MINUTES - time + timeMinutes[0];
        return Math.min(min, diff);
    }, Infinity);
};