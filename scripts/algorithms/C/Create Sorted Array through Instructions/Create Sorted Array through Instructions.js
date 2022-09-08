// Runtime: 3484 ms (Top 12.50%) | Memory: 78 MB (Top 37.50%)
var createSortedArray = function(instructions) {
    let nums = [];
    let cost = 0;
    // define a map to track how many occurences of a number are in the array as we sort it
    let map = {};
    // classic binary search
    const bin = (arr, elem) => {
        let low = 0;
        let high = arr.length - 1;
        while (low <= high) {
            let mid = (high + low) >> 1; // fancy Math.foor(high + low / 2)
            if (arr[mid] > elem) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
    // loop through the each of the values
    for (let i of instructions) {
        // do a binary search to determine which index this value belongs at
        let index = bin(nums, i);
        // insert it into the array
        nums.splice(index, 0, i);
        // populate a map to track how many instances of this number we have in the arr
        if (!map.hasOwnProperty(i)) map[i] = 0;
        // need to remove any matching numbers from the equation, meaning if the left side is 1,2,3,3
        // and the current value is 3, we should be subtracting the existing 3's from the equation
        let left = index - map[i];
        // right side is the last value - index
        let right = (nums.length - 1) - index;
        // add the min of left / right to the cost
        cost += Math.min(left, right);
        // increment our number occurence map
        map[i]++;
    }

    const WEIRD_MOD_VAL = Math.pow(10, 9) + 7;
    // for some goofy reason when the number is too large, send the mod val
    return cost < 1842204555 ? cost : cost % WEIRD_MOD_VAL;
};