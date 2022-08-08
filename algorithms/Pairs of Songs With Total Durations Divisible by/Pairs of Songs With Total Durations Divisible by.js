/**
 * @param {number[]} time
 * @return {number}
 */
var numPairsDivisibleBy60 = function(time) {
    let result = 0;
    let seen = new Map();
    
    
    for(let t of time){
        let target = 60 - (t % 60 );
        
		// check the count of the target time to make the current time[i] divisble by 60
        // The catch here is to treat 60 as 0 in the given formula : target = 60 - (time % 60)
        let targetCount = seen.get(target === 60 ? 0 : target);
        
		// if the target exists in the map, increment the result by the count
        if(targetCount !== undefined){
            result += targetCount;
        }
       
		// below steps are simply to check if the time[i] % 60 exists in map or not 
		// and increment the count 
        let count = seen.get(t % 60);
        
        if(count === undefined){
            seen.set(t % 60, 1);
        } else {
            seen.set(t % 60, count + 1);
        }
    }
    
    return result;
};
