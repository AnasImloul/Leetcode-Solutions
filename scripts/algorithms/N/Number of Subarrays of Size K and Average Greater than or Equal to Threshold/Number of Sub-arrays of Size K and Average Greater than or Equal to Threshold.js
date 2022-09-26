// Runtime: 124 ms (Top 49.52%) | Memory: 50.1 MB (Top 11.43%)
var numOfSubarrays = function(arr, k, threshold) {
    let total = 0;
    let left = 0;
    let right = k;
    // get initial sum of numbers in first sub array range, by summing left -> right
    let sum = arr.slice(left, right).reduce((a, b) => a + b, 0);
    while (right <= arr.length) {
        // move through the array as a sliding window
        if (left > 0) {
            // on each iteration of the loop, subtract the val that has fallen out of the window,
            // and add the new value that has entered the window
            sum -= arr[left - 1];
            sum += arr[right - 1];
        }
        if (sum / k >= threshold) {
            total++;
        }
        left++;
        right++;
    }
    return total;
};