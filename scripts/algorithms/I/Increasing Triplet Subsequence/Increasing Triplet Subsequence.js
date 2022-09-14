// Runtime: 690 ms (Top 5.03%) | Memory: 64.7 MB (Top 5.59%)
var increasingTriplet = function(nums) {
    const length = nums.length, arr = [];
    let tripletFound = false, arrLength, added = false, found = false;
    if(length < 3) return false;
    arr.push([nums[0],1]);
    for(let index = 1; index < length; index++) {
        let count = 1;
        added = false;
        found = false;
        arrLength = arr.length;
        for(let index2 = 0; index2 < arrLength; index2++) {
            if(arr[index2][0] < nums[index]) {
                added = true;
                if(count !== arr[index2][1]+1) {
                    count = arr[index2][1]+1;
                    if(JSON.stringify(arr[index2+1]) !== JSON.stringify([nums[index],count]))
                        arr.push([nums[index],count]);
                }
                if(arr[index2][1]+1 === 3) {
                    tripletFound = true;
                    break;
                }
            }
            if(arr[index2][0] === nums[index]) found = true;
        }
        if(tripletFound) break;
        if(!added && !found) {
                arr.push([nums[index],1]);
            }
    }
    return tripletFound;
};