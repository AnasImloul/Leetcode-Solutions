// Runtime: 91 ms (Top 64.54%) | Memory: 43.9 MB (Top 36.99%)

function binarySearch(lists, sorted, low, high, target){
    if(low > high) return;

    const mid = low + Math.floor((high - low) / 2);

    if(sorted[mid] === target){
    lists.push(mid);
    }

    binarySearch(lists, sorted, low, mid-1, target);
    binarySearch(lists, sorted, mid+1, high, target);
}

var targetIndices = function(nums, target) {
    let result = [];
    nums.sort((a,b)=>a-b);
    if(!nums.includes(target)) return [];

    binarySearch(result, nums, 0 , nums.length-1, target);
    return result.sort((a,b) => a-b);
}