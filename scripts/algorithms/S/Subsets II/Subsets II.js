// Runtime: 125 ms (Top 19.54%) | Memory: 44.7 MB (Top 48.96%)
var subsetsWithDup = function(nums) {
    let result = [];
    //sort the nums to avoid duplicates;
    nums.sort((a,b) => a -b);
    result.push([]);

    let startIdx = 0;
    let endIdx = 0;

    for(let i =0; i<nums.length; i++){
        let current = nums[i];
        startIdx = 0;

        //check for duplicates and get the idx of last subset
        if(i> 0 && nums[i] === nums[i-1]){
            startIdx = endIdx +1;
        }
        endIdx = result.length - 1;

        for(let j = startIdx; j< endIdx+1; j++){
            let set1 = result[j].slice(0);
            set1.push(current);
            result.push(set1);
        }
    }

    return result;

};