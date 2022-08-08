/**
 * @param {number[]} arr
 * @return {void} Do not return anything, modify arr in-place instead.
 */
var duplicateZeros = function(arr) {
    // Variables
    const originalLength = arr.length;
    
    // Iterate over all the numbers in 'arr', if the number is 0 we duplicate it and skip the next loop iteration to prevent an overflow.
    for (let idx = 0; idx < arr.length; idx ++)
    {
      const number = arr[idx];
      if (number === 0 )
      {
        arr.splice(idx, 0, 0);
        idx += 1;
      };
    };
    
    // Here we restore the array to its original length.
    return (arr.length = originalLength);
};
