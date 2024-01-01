// Runtime: 58 ms (Top 64.29%) | Memory: 43.20 MB (Top 11.9%)

/**
 * // This is the CustomFunction's API interface.
 * // You should not implement it, or speculate about its implementation
 * function CustomFunction() {
 *     @param {integer, integer} x, y
 *     @return {integer}
 *     this.f = function(x, y) {
 *         ...
 *     };
 * };
 */

/**
 * @param {CustomFunction} customfunction
 * @param {integer} z
 * @return {integer[][]}
 */
var findSolution = function(customfunction, z) {
    var ans = []
    var x = 1, y = 1000;
    while(x<=1000 && y>0){
        if(customfunction.f(x,y)>z){
            y--;
        }else if(customfunction.f(x,y)<z){
            x++;
        }else{
            ans.push([x,y]);
            x++;
            y--;
        }
    }
    return ans;
};
