// Runtime: 220 ms (Top 40.31%) | Memory: 52.3 MB (Top 90.31%)
var groupAnagrams = function(strs) {
    let totalResults = [];
    let grouped = new Map();

    for (let i=0; i < strs.length; i++) {
        let results = [];
        let res = strs[i];

        let sortedStr = strs[i].split('').sort().join('');
        let value = grouped.get(sortedStr);

        if (value !== undefined) {
            grouped.set(sortedStr, [...value, strs[i]]);
        } else {
            grouped.set(sortedStr, [strs[i]]);
        }
    }

    for (let [key, value] of grouped) {
        totalResults.push(grouped.get(key));
    }

    return totalResults;
};