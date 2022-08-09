/**
 * @param {number[][]} trips
 * @param {number} capacity
 * @return {boolean}
 */
var carPooling = function(trips, capacity) {
    
    // sort trips by destination distance
    trips.sort((a, b) => a[2] - b[2]);
    
    // build result array, using max distance
    const lastTrip = trips[trips.length - 1];
    const maxDistance = lastTrip[lastTrip.length - 1];
    const arr = new Array(maxDistance + 1).fill(0);
    
    // build partial sum array
    for (const [val, start, end] of trips) {
        arr[start] += val;
        arr[end] -= val;
    }

    // build combined sum array
    let sum = 0;
    for (let i = 0; i < arr.length; i++) {
        sum += arr[i];
        if (sum > capacity) return false;
    }
    
    return true;
};
