// Runtime: 184 ms (Top 100.0%) | Memory: 54.40 MB (Top 6.82%)

/**
 * @param {number[]} position
 * @param {number} m
 * @return {number}
 */
var maxDistance = function(position, m) {
    position.sort((a, b) => a - b);

    let left = 1, right = Math.max(...position) - Math.min(...position);
    max = -1;
    while (left <= right) {
        const p = Math.floor((left + right) / 2);
        if (isValid(position, m, p)) {
            max = p;
            left = p + 1;
        } else {
            right = p - 1;
        }
    }

    return max;   
};
 

const isValid = (sortedPosition, m, p) => {
    let counter = 1;
    let prev = sortedPosition[0];
    for (let i = 1; i < sortedPosition.length; ++i) {
        if (sortedPosition[i] - prev >= p) {
            counter++;
            prev = sortedPosition[i];
        } 
    }

    return counter >= m;
}


