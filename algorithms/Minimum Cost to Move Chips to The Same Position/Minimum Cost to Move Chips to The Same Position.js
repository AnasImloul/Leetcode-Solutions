var minCostToMoveChips = function(position) {
    const hashMap = new Map();
    let odd = 0, even = 0;
    for(const chip of position){
        if(hashMap.has(chip)) hashMap.set(chip, hashMap.get(chip)+1);
        else hashMap.set(chip, 1);
    }
    for(const [key, value] of hashMap){
        if(key%2===0) even+=value;
        else odd+=value;
    }
    return Math.min(odd, even);
};
