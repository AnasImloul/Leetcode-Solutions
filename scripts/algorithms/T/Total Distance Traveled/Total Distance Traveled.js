// Runtime: 148 ms (Top 49.5%) | Memory: 49.04 MB (Top 69.5%)

/**
 * @param {number} mainTank
 * @param {number} additionalTank
 * @return {number}
 */
var distanceTraveled = function(mainTank, additionalTank) {
    let distance = 0;

    if (mainTank < 5) {
        let remainingFuel = mainTank % 5;
        return remainingFuel * 10;
    }

    while (mainTank > 0 || additionalTank > 0) {
        if (mainTank >= 5) {
            distance += 50;
            mainTank -= 5;

            if (additionalTank > 0) {
                mainTank += 1;
                additionalTank -= 1;
            }
        } else {
            let remainingFuel = mainTank % 5;
            distance += remainingFuel * 10;
            break;
        }
    }

    return distance;
};
