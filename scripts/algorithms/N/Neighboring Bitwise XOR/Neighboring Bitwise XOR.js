// Runtime: 122 ms (Top 46.1%) | Memory: 56.38 MB (Top 46.1%)

var doesValidArrayExist = function(derived) {
    const n = derived.length;
    let arr = [0];
    for(let i = 0; i<n; i++) {
        let cur = derived[i];
        arr.push(cur ^ arr[i]);
    }
    if(arr[n] === arr[0]) {
        return true;
    }
    arr = [1];
    for(let i = 0; i<n; i++) {
        let cur = derived[i];
        arr.push(cur ^ arr[i]);
    }
    if(arr[n] === arr[0]) {
        return true;
    }
    return false;
};