// Runtime: 65 ms (Top 92.65%) | Memory: 44.9 MB (Top 5.15%)
var countElements = function(nums) {
    let map = {}, total = 0;

    // adding elements to map
    for(let i of nums) map[i] ? map[i]++ : map[i] = 1;

    // Removing repeated elements
    let newNums = [... new Set(nums)];

    // If length of array after removing repeated nums is less than three return 0;
    if(newNums.length < 3) return 0;

    // sort the newNums array and remove the first and last element.
    // for all the remaining elements check their number in map and add it to total variable
    newNums.sort((a,b) => a-b).slice(1, newNums.length-1).forEach(num => total += map[num]);

    // return total variable
    return total;
};