/** 
 * Forward declaration of guess API.
 * @param {number} num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * var guess = function(num) {}
 */

/**
 * @param {number} n
 * @return {number}
 */
var guessNumber = function(n) {
    let lower=1;
    let higher=n;
    while(lower<=higher){
        let mid=Math.floor((lower+higher)/2);
        if(guess(mid)==0){
            return mid;            
        }
        else if(guess(mid)==-1){
            higher=mid-1;
        }
        else{
            lower=mid+1;
        }
    }
    return 0;
    
};
