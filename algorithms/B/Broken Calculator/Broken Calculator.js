/**
 * @param {number} startValue
 * @param {number} target
 * @return {number}
 */
var brokenCalc = function(startValue, target) {
    let steps = 0;
    
    while(target !== startValue){

        if(startValue > target){
            return steps  + startValue - target;
        }
        if(target %2 === 0){
            target /= 2;
        }else {
            target += 1;
            
        }
        steps++;
    }
    return steps
};
