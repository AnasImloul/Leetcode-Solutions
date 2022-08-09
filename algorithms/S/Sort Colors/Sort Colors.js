var sortColors = function(nums) {
    let map = {
        '0': 0,
        '1': 0,
        '2': 0
    };
    for(let char of nums) {
        map[char] = map[char] + 1;
    }
    let values = Object.values(map);
    let curr = 0;
    for(let k=0; k<values.length; k++) {
        for(let i=curr; i<curr+values[k]; i++) {
            nums[i] = k;
        }
        curr = curr + values[k];
    }
};
