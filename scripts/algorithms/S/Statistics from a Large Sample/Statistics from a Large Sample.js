// Runtime: 417 ms (Top 7.69%) | Memory: 44.4 MB (Top 23.08%)
/**
 * @param {number[]} count
 * @return {number[]}
 */
var sampleStats = function(count) {
    let min;
    let max;
    let sum = 0;
    let mode = 0;
    let prefix = 0;
    let prefixSum = new Map();
    for (let i=0; i<count.length; i++) {
        if (count[i] === 0) continue;
        if (min === undefined) min = i;
        max = i;
        if (count[i] > count[mode]) mode = i;
        sum += (count[i] * i);
        prefix += count[i];
        prefixSum.set(prefix, i);
    }
    const mean = sum / prefix;
    // min, max, mean, mode found
    // finding median using prefixSum map
    let median;
    let medianLeft;
    let medianRight;
    const medianPoint = Math.ceil(prefix/2);
    for (let i=medianPoint; i<=prefix; i++) {
        if (!prefixSum.has(i)) continue;
        if (medianLeft !== undefined) {
            medianRight = prefixSum.get(i);
            median = (medianLeft+medianRight) / 2;
            break;
        }
        if (i === medianPoint && prefix % 2 === 0) {
            medianLeft = prefixSum.get(i);
            continue;
        }
        median = prefixSum.get(i);
        break;
    }

    return [min, max, mean, median, mode];
};