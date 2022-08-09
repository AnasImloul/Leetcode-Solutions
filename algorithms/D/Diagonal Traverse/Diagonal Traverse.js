/**
 * @param {number[][]} mat
 * @return {number[]}
 */
var findDiagonalOrder = function(mat) {
    //we can initialize our answer array... it is guaranteed to be m x n in size & 1D
    let m = mat.length,
        n = mat[0].length,
        answer = new Array(m * n);
    //next we can decrement m & n to function as our limits for our indices
    m--;
    n--;
    
    //next, we use a boolean to act as our switch for which direction to go
    let upAndToRight = true;
    //we can also create a helper function to "flip the switch" upon meeting boundary conditions
    function flip() {upAndToRight = !upAndToRight};
    //next we iterate through our answer array while updating our indices and direction
    for(let i = 0, j = 0, k = 0; i < answer.length; i++) {
        //assign the (j,k) value to our answer
        answer[i] = mat[j][k];
        //next, we want to update our j & k indices, which is a function of upAndToRight,
        //as well as our boundary conditions...
        if(upAndToRight) {
            //default condition
            if(j > 0 && k < n) {
                j--;
                k++;
            //boundary condition met: top border of 2D array
            }else if(j === 0 && k < n) {
                k++;
                flip();
			//other boundary condition met: right border of 2D array
            }else {
                j++;
                flip();
            }
        }else {
            //default condition
            if(j < m && k > 0) {
                j++;
                k--;
            //boundary condition met: left border of 2D array
            }else if(j < m && k === 0){
                j += 1;
                flip();
            //boundary condition met: bottom border of 2D array
            }else {
                k++;
                flip();
            }
        }
    }
    
    return answer;
    
    
};
