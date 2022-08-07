var searchMatrix = function(matrix, target) {
    let matCopy = [...matrix];
    let leftIndex = 0;
    let rightIndex = matrix.length - 1;

    let mid = Math.ceil((matrix.length - 1) / 2);

    let eachMatrixLength = matrix[0].length;
  
    if (matrix[mid].includes(target) === true) {
        return true;
    } else if (matrix.length == 1) {
        return false;
    }

    if (matrix[mid][eachMatrixLength - 1] > target) {
        rightIndex = mid - 1;
        matCopy.splice(-mid);
    } else {
        leftIndex = mid + 1;
        matCopy.splice(0, mid);
    }

    return searchMatrix(matCopy, target);
   
};
