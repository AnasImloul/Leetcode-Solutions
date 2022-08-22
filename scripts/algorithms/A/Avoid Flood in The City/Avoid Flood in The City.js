// Runtime: 1794 ms (Top 18.18%) | Memory: 80.7 MB (Top 40.91%)
var avoidFlood = function(rains) {
    const n = rains.length;
    const filledLakes = new Map();
    const res = new Array(n).fill(-1);
    const dryDays = [];

    for (let i = 0; i < n; i++) {
        const lake = rains[i]; // lake to rain on

        if (lake === 0) {
        // It is a dry day
            dryDays.push(i);
        }
        else if (!filledLakes.has(lake)) {
        // The lake is not filled yet, so we let it be filled (we just don't want it to be rained on again and be flooded)
            filledLakes.set(lake, i);
        }
        else {
        // The lake is already filled. We want to see if a dry day was available after the lake was previously rained on so that we can empty the lake
            const lake_index = filledLakes.get(lake); //
            const dry_index = binarySearch(lake_index);

            if (dry_index === dryDays.length) return []; // there was no dry day after the lake was previouly filled

            res[dryDays[dry_index]] = lake; // mark the earliest dry day that was used in our result array
            filledLakes.set(lake, i); // we need to update the day that the lake is rained on again
            dryDays.splice(dry_index, 1); // remove the dry day that was used (this is not very efficient, but it just makes our code cleaner)
        }
    }

    dryDays.forEach((day) => res[day] = 1);

    return res;

    function binarySearch(target) {
        let left = 0;
        let right = dryDays.length - 1;

        while (left <= right) {
            const mid = left + Math.floor((right - left) / 2);

            if (dryDays[mid] < target) left = mid + 1;
            else right = mid - 1;
        }

        return left;
    }
};