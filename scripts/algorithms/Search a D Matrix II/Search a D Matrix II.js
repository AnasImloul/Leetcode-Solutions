function binarySearch(arr, target) {
    let low = 0;
    let high = arr.length - 1;

    while (low <= high) {
        let mid = parseInt((low + high) / 2);

        if (arr[mid] == target) {
            return mid;
        }
        else if (arr[mid] < target) {
            low = mid + 1;
        }
        else if (arr[mid] > target) {
            high = mid - 1;
        }
    }
    return -1;
}

var searchMatrix = function(matrix, target) {
    for (let i = 0; i < matrix.length; i++) {
        let check = binarySearch(matrix[i], target);

        if (check != -1) { return true }
    }
    return false
};

