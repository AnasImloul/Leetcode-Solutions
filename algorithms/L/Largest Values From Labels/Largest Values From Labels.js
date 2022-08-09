/**
 * @param {number[]} values
 * @param {number[]} labels
 * @param {number} numWanted
 * @param {number} useLimit
 * @return {number}
 */
var largestValsFromLabels = function(values, labels, numWanted, useLimit) {
    // this sortValues will create an addition array that keep track of the value idx after descending sort
    // which is useful to map the labels accordingly
    let sortValues = values.map((val, idx) => [val, idx]), sortLabels = []
    sortValues.sort((a, b) => b[0] - a[0])
    
    for (let [val, idx] of sortValues) {
        sortLabels.push(labels[idx])
    }
    values.sort((a, b) => b - a)
    labels = sortLabels
    
    let i = 0, map = {}, ans = 0
    while (i < values.length && numWanted > 0) {
        if (map[labels[i]]) map[labels[i]] ++
        else map[labels[i]] = 1
        
        if ((map[labels[i]]) <= useLimit) {
            ans += values[i]
            numWanted--
        }
        
        i++
    }
    
    return ans
    
};
