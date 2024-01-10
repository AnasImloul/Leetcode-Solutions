// Runtime: 60 ms (Top 37.5%) | Memory: 42.30 MB (Top 100.0%)

/**
 * @param {number[]} machines
 * @return {number}
 */
var findMinMoves = function(machines) {
    const totalDresses = machines.reduce((acc, dresses) => acc + dresses, 0);
    const numMachines = machines.length;
    if (totalDresses % numMachines !== 0) {
        return -1; // Cannot distribute dresses equally
    }
    const targetDresses = totalDresses / numMachines;
    let balance = 0;
    let maxImbalance = 0;
    for (let i = 0; i < numMachines; i++) {
        const imbalance = machines[i] - targetDresses;
        balance += imbalance;
        maxImbalance = Math.max(maxImbalance, Math.abs(balance), imbalance);
    }
    return maxImbalance;
};
