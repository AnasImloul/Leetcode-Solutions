var trap = function(height) {
    let left = 0, right = height.length - 1;
    let hiLevel = 0, water = 0;
    while(left <= right) {
        let loLevel = height[height[left] < height[right] ? left++ : right--];
        hiLevel = Math.max(hiLevel, loLevel);
        water += hiLevel - loLevel ;
    }
    return water;
};
