var canArrange = function(arr, k) {
    let map = new Map();
    let index = 0;
    for(let i = 0; i < arr.length; i++){
        let val = arr[i] % k;
        if(val<0) val+=k;
        if(map.get(k-val)) map.set(k-val, map.get(k-val) - 1), index--;
        else if(map.get(-val)) map.set(-val, map.get(-val) - 1), index--;
        else map.set(val, map.get(val) + 1 || 1), index++;
    }
    return !index;
};
