// Runtime: 136 ms (Top 56.52%) | Memory: 53.8 MB (Top 73.91%)
var minimumRefill = function(plants, capacityA, capacityB) {
    const n = plants.length;

    let left = 0;
    let right = n - 1;

    let remA = capacityA;
    let remB = capacityB;

    let refills = 0;

    while (left < right) {
        const leftAmount = plants[left++];
        const rightAmount = plants[right--];

        if (leftAmount > remA) {
            ++refills;
            remA = capacityA;
        }
        remA -= leftAmount;

        if (rightAmount > remB) {
            ++refills;
            remB = capacityB;
        }
        remB -= rightAmount;

    }

    if (left === right) {
        const midAmount = plants[left];

        if (remB > remA) {
            if (remB < midAmount) ++refills;
        }
        else {
            if (remA < midAmount) ++refills;
        }
    }

    return refills;
};