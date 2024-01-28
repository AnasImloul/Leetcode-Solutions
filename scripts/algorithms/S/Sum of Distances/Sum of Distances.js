// Runtime: 258 ms (Top 76.92%) | Memory: 84.40 MB (Top 84.62%)

var distance = function(nums) {
    let arr = new Array(nums.length).fill(0);
    let map = {};
    
    for(let i = 0; i < nums.length; ++i) {
        if(map[nums[i]] == undefined) map[nums[i]] = [i]
        else  map[nums[i]].push(i)
    }

    for(let key of Object.keys(map)) {
        let indexesForCurrentElement = map[key]; // array of all indexed where the element occurs
        let totalLength = indexesForCurrentElement.length;
        
        if(totalLength > 1) {
            let totalSum = indexesForCurrentElement.reduce((acc, el) => acc + el, 0); // find total sum
            
            let currSum = 0;
            for(let i = 0; i < totalLength; ++i) {
                let prevCount = i - 0; // count of all instances of the element before current index
                let nextCount = totalLength - i - 1 // count of all instances after (excluding current index)
                

                arr[indexesForCurrentElement[i]] = (indexesForCurrentElement[i] * prevCount) - currSum + (totalSum - currSum - indexesForCurrentElement[i]) - (indexesForCurrentElement[i] * nextCount);
                currSum += indexesForCurrentElement[i];
            }
        }
    }
    
    return arr
};
