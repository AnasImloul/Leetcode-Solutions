var uniqueOccurrences = function(arr) {
    const obj = {};
//     Creating hashmap to store count of each number
    arr.forEach(val => obj[val] = (obj[val] || 0) + 1);
//     Creating an array of the count times
    const val = Object.values(obj).sort((a, b) => a-b);
//     Now, just finding the duplicates
    for(let i = 0; i<val.length-1; i++){
        if(val[i]===val[i+1]) return false;
    }
    return true;
};
