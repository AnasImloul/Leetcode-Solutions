 * @param {number[]} arr
 * @return {number[]}
 */
var replaceElements = function(arr) {
    let max = arr[arr.length -1]
    
     for(let j=arr.length - 2; j>=0; --j){
         let curr = arr[j];
         arr[j] = max
         max = Math.max(max,curr)
     }
    
    arr[arr.length -1] = -1;
    return arr;
};