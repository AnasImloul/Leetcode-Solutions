function binarySearch(array, target, findFirst) {
    function helper(start, end) {
        if (start > end) {
            return -1;
        }       
        
        const middle = Math.floor((start + end) / 2);
        const value = array[middle];
        
        if (value === target) {
            if (findFirst) {
                if (middle === 0 || array[middle - 1] !== value) {
                    return middle;
                }
                
                return helper(start, middle - 1);
            } else {
                if (middle === array.length -1 || array[middle + 1] !== value) {
                    return middle;
                }
                
                return helper(middle + 1, end);
            }
        } else if (value < target) {
          return helper(middle + 1, end);    
        }
        
        return helper(start, middle - 1);
    }
    
    return helper(0, array.length - 1)
}

const findFirstOccurance = (array, target) => binarySearch(array, target, true);
const findLastOccurance = (array, target) => binarySearch(array, target, false);

var findSpecialInteger = function(arr) {
    for (const i of [Math.floor(arr.length / 4), Math.floor(arr.length / 2), Math.floor(3 * arr.length / 4)]) {
        const firstOccurance = findFirstOccurance(arr, arr[i]);
        const lastOccurance = findLastOccurance(arr, arr[i]);
                
        if (lastOccurance - firstOccurance + 1 > arr.length / 4) {
            return arr[i]
        }
    }
    
    return -1;
};

