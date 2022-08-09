/**
 * @param {number[]} height
 * @return {number}
 */
var maxArea = function(height) {
    let max = -1;
    
    /*===========BRUTE FORCE========== */
    for(let i=0;i<height.length - 1;i++){
         let currMax = -1;
         for(let j=i+1;j<height.length;j++){
             let min = Math.min(height[i], height[j]);
             let length = j-i;
             let filled = min * length;
             if(filled>currMax){
                 currMax = filled;
             }
         }
         if(currMax > max){
             max = currMax;
         }
     }
    
    return max;
};
