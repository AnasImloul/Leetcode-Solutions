// Runtime: 218 ms (Top 90.0%) | Memory: 61.37 MB (Top 60.0%)

/**
 * @param {number[]} beans
 * @return {number}
 */
 // time complexity -> O(NlogN) and Space is O(logN) due to sorting. 
 var minimumRemoval = function(beans) {
    beans.sort((a, b) => a - b);
    let frontSum = beans.reduce((sum , a) => sum + a, 0);
    let backSum = 0;
    let done = 0;
    let result = Number.MAX_SAFE_INTEGER;
    for(let j = beans.length - 1; j >= 0; j--){
        frontSum -= beans[j];
        count = frontSum + (backSum - (beans[j] * done));
        result = Math.min(result, count);
        done++;
        backSum += beans[j];
    }
    return result;
};