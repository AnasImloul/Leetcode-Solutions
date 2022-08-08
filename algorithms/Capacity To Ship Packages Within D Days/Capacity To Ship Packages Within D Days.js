/**
 * @param {number[]} weights
 * @param {number} days
 * @return {number}
 */
var shipWithinDays = function(weights, days) {
    // set left as max of weight, set right as sum of weight
    let left = Math.max(...weights), right = weights.reduce((a, b) => a + b);

    // max weight cannot exceed the capacity of ship
    while (left < right) {
        // set middle weight
        const m = Math.floor((left + right) / 2);
        // reset weight if can be load
        can(m) ? (left = m + 1) : (right = m);
    }

    // result
    return left;

    // check if load can be
    function can(v) {
        let need = 1, current = 0;

        for (let i of weights) {
            if (current + i > v) {
                need++;
                current = i;
            }
            else {
                current += i;
            }
        }

        return need > days;
    }
};
