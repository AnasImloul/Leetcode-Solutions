// Runtime: 2034 ms (Top 8.12%) | Memory: 50.3 MB (Top 81.93%)
var canCompleteCircuit = function(gas, cost) {
    const len = gas.length;
    // scan forward from the current index
    const scan = (i) => {
        let numTries = 0;
        let tank = 0;
        let c = 0;
        while (numTries <= len) {
            tank -= c;
            if (tank < 0) return -1;
            // if we made it back around, and we have gas, return the index, we made it!
            if (numTries === len && tank >= 0) {
                return i;
            }
            tank += gas[i];
            c = cost[i];
            i++;
            if (i === len) i = 0; // if we hit the end, bounce back to zero
            numTries++;
        }
        return -1;
    }

    for (let i = 0; i < len; i++) {
        if (!gas[i]) continue; // no gas / zero gas so let's just move on
        let index = scan(i);
        if (~index) return index; // if it's not -1, return it
    }

    return -1;
};