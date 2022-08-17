/**
 * @param {number[][]} mat
 * @return {number[]}
 */
var findPeakGrid = function(mat) {   
    /**
    * Helper function to find max value in a given list
    * Time: O(n)
    * Memory: O(1)
    */
    function maxValueIdx(array) {
        let maxIdx = 0;
        for(let i = 0; i < array.length; i++) {
            if(array[i] > array[maxIdx]) {
                maxIdx = i;
            }
        }
        return maxIdx
    };
    
    
    // Helper pointers for Binary Search
    let left = 0;
    let right = mat.length - 1;

    while(left < right) {
        const midRowIdx = parseInt((left + right) / 2, 10);
        
        // Find index with highest value in the mid row
        let colIdx = maxValueIdx(mat[midRowIdx]);
        
        // If value in the next row is higher - current value is not a pick - check right subgroup
        if(mat[midRowIdx][colIdx] < mat[midRowIdx + 1][colIdx]) {
            left = midRowIdx + 1;
        // If value in the next row is not higher - current value might be a pick - check left subgroup
        } else {
            right = midRowIdx;
        }
    }
    
    // After completing binary search last value will be pointing to a peak item.    
	// Complexity:
	// Time: Binary Search to find row * Linear search to find max value in a row
	// Time: O(log(N) * M) where N - number of rows, M - number of cells
	// Memory: O(1)
    return [left, maxValueIdx(mat[left])];
};
