// Runtime: 645 ms (Top 8.33%) | Memory: 65.4 MB (Top 83.33%)
var getStrongest = function(arr, k) {
    // sort array so we can easily find median
    const sorted = arr.sort((a,b) => a-b)
    // get index of median
    const medianIndex = Math.floor(((sorted.length-1)/2))
    // get median
    const median = sorted[medianIndex]

    // custom sort function following the parameters given us in the description
    const compareFunction = (a, b) => {
        if (Math.abs(a-median) > Math.abs(b-median)) {
            return 1
        }
        else if (Math.abs(a-median) === Math.abs(b-median) && a > b) {
            return 1
        } else {
            return -1
        }
    }

    // sort array using our custom sort function
    const strongest = arr.sort(compareFunction).reverse().slice(0,k);

    return strongest;
};