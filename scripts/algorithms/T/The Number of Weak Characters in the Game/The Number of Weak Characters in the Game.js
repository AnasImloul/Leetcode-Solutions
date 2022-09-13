// Runtime: 1076 ms (Top 5.06%) | Memory: 153.3 MB (Top 5.00%)
 var numberOfWeakCharacters = function(properties) {
    // sort strongest to weakest
    properties.sort((a, b) => {
        if (b[0] - a[0]) {
            return b[0] - a[0];
        }
        return b[1] - a[1];
    });

    // map all the unique index 0 values to a (descending)
    // sorted array
    const uniqueZeroIndexToOneIndex = new Map();
    for (const [a, b] of properties) {
        if (!uniqueZeroIndexToOneIndex.has(a)) {
            uniqueZeroIndexToOneIndex.set(a, []);
        }
        uniqueZeroIndexToOneIndex.get(a).push(b);
    }

    // get all the unique index 0 values
    const nums = [...uniqueZeroIndexToOneIndex.keys()];

    let maxValue = -1;
    let numWeakCharacters = 0;
    for (let i = 0; i < nums.length; i++) {
        // skip key in case if we deleted the key
        if (!uniqueZeroIndexToOneIndex.has(nums[i])) continue;

        const maxValOfI = uniqueZeroIndexToOneIndex.get(nums[i])[0];
        if (maxValOfI <= maxValue) continue;
        maxValue = maxValOfI;

        for (let j = i + 1; j < nums.length; j++) {
            // skip key in case if we deleted the key
            if (!uniqueZeroIndexToOneIndex.has(nums[j])) continue;

            // valuesOfJ will be sorted in descending order
            const valuesOfJ = uniqueZeroIndexToOneIndex.get(nums[j])

            // pop off all the weak values and add to numWeakCharacters
            for (let k = valuesOfJ.length - 1; k >= 0; k--) {
                if (maxValue > valuesOfJ[k]) {
                    valuesOfJ.pop();
                    numWeakCharacters++;
                } else {
                    // we won't be able to find any more weak characters
                    // in valuesOfJ
                    break;
                }
            }
            if (valuesOfJ.length === 0) {
                // delete the key if all the values were weak characters
                uniqueZeroIndexToOneIndex.delete(nums[j]);
            } else {
                // if there is a stronger character updated it so we can
                // eliminate more characters
                maxValue = Math.max(valuesOfJ[0], maxValue);
            }
        }
    }
    return numWeakCharacters;
};