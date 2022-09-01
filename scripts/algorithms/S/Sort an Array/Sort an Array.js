// Runtime: 346 ms (Top 43.21%) | Memory: 58.4 MB (Top 51.45%)
var sortArray = function(nums) {
    return quickSort(nums, 0, nums.length - 1);
};

const quickSort = (arr, start, end) => {
    // base case
    if (start >= end) return arr;

    // return pivot index to divide array into 2 sub-arrays.
    const pivotIdx = partition(arr, start, end);
    // sort sub-array to the left and right of pivot index.
    quickSort(arr, start, pivotIdx - 1);
    quickSort(arr, pivotIdx + 1, end);

    return arr;
}

const partition = (arr, start, end) => {
    // select a random pivot index, and swap pivot value with end value.
    const pivotIdx = Math.floor(Math.random() * (end - start + 1)) + start;
    [arr[pivotIdx], arr[end]] = [arr[end], arr[pivotIdx]];

    const pivotVal = arr[end];
    // loop from start to before end index (because pivot is stored at end index).
    for (let i = start; i < end; i++) {
        if (arr[i] < pivotVal) {
            // swap smaller-than-pivot value (at i) with the value at the start index.
            // This ensures all values to the left of start index will be less than pivot.
            [arr[i], arr[start]] = [arr[start], arr[i]];
            start++;
        }
    }

    // swap pivot (which was stored at end index) with value at start index.
    // This puts the pivot in its correct place.
    [arr[start], arr[end]] = [arr[end], arr[start]];
    return start;
}

/*
Note: Instead of always picking a fixed index as the pivot (ie. start or end index),
The pivot was randomly selected to mitigate the odds of achieving worst case TC and SC.
TC:
Best and avg case: O(nlogn)
worst case: O(n^2)

SC:
Since algo done in-place, space comes from recursive call stack.
best and avg case: O(logn)
worst case: O(n)
*/