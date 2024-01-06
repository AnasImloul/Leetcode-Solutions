// Runtime: 89 ms (Top 100.0%) | Memory: 48.20 MB (Top 87.5%)

/**
 * @param {number[]} ranks
 * @param {number} cars
 * @return {number}
 */
var repairCars = function(ranks, cars) {
    let counts = new Array(100).fill(0);

    for (let i = 0; i < ranks.length; i++) {
        counts[ranks[i] - 1]++;
    }

    let high = cars * cars * ranks[0];
    let low = 0;

    let best = high;
    
    while (high > low) {
        let mid = Math.floor(low + ((high - low) / 2));

        if (carsInMinutes(counts, mid) >= cars) {
            best = Math.min(best, mid);

            high = mid;
        } else {
            low = mid + 1;
        }
    }

    return best;
};

function carsInMinutes(counts, minutes) {
    let cars = 0;

    for (let i = 0; i < 100; i++) {
        cars += Math.floor(Math.sqrt(minutes / (i + 1))) * counts[i];
    }

    return cars;
}

// binary search number of minutes
