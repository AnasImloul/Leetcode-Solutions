// Runtime: 111 ms (Top 46.85%) | Memory: 44.4 MB (Top 73.58%)
var intersection = function(nums) {
    let set = addToSet(nums[0]);
    for(let i=1; i<nums.length; i++) {
        let tempSet = addToSet(nums[i]);
        for(let key of set) {
            if( !tempSet.has(key) )
                set.delete(key);
        }
    }
    return [...set].sort( (a,b) => a-b );
};

function addToSet(arr) {
    let set = new Set(arr);
    return set;
}