// Runtime: 123 ms (Top 21.70%) | Memory: 45 MB (Top 6.60%)
/**
 * @param {number[]} arr1
 * @param {number[]} arr2
 * @param {number} d
 * @return {number}
 */
var findTheDistanceValue = function(arr1, arr2, d) {
    const arr2Sorted = arr2.sort((a, b) => a - b);
    let dist = 0;

    for (const num of arr1) {
        if (isDistanceValid(num, d, arr2Sorted)) {
            dist += 1;
        }
    }

    return dist;
};

function isDistanceValid(number, dist, array) {
    let left = 0;
    let right = array.length - 1;

    while (left <= right) {
        const mid = Math.floor((right + left) / 2);

        if (Math.abs(number - array[mid]) <= dist) {
            return false;
        }

        if (array[mid] < number) {
            left = mid + 1;
        }

        if (array[mid] > number) {
            right = mid - 1;
        }
    }

    return true;
}