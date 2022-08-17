/**
 * @param {number[]} groupSizes
 * @return {number[][]}
 */
var groupThePeople = function(groupSizes) {
    let indices = [], result = [];
    groupSizes.forEach((x, idx) => {
        if (indices[x]) indices[x].push(idx);
        else indices[x] = [idx];
        if (indices[x].length === x) {
            result.push(indices[x]);
            indices[x] = undefined;
        }
    });
    return result;
};
