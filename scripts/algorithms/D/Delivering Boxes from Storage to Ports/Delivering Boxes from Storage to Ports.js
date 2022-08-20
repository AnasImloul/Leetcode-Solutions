// Runtime: 310 ms (Top 33.33%) | Memory: 85.8 MB (Top 33.33%)

/**
 * @param {number[][]} boxes
 * @param {number} portsCount
 * @param {number} maxBoxes
 * @param {number} maxWeight
 * @return {number}
 */
var boxDelivering = function(boxes, portsCount, maxBoxes, maxWeight) {

    const trips = Array(boxes.length + 1).fill(0);
    let left = 0;
    let diff = 0;

    for (let right = 0; right < boxes.length; right++) {
        maxBoxes--;
        maxWeight -= boxes[right][1];
        if (right > 0 && boxes[right][0] !== boxes[right - 1][0]) diff++;

        while (maxBoxes < 0 || maxWeight < 0 || (left < right && trips[left + 1] === trips[left])) {
            maxBoxes++;
            maxWeight += boxes[left++][1];
            if (boxes[left][0] !== boxes[left - 1][0]) diff--;
        }

        trips[right + 1] = diff + 2 + trips[left];
    }

    return trips[boxes.length];
};