var kthDistinct = function(arr, k) {
    const map = {} // used for arr occurences
    const distinctArr = [] // store the distinct values (only appearing once)
    
	// increment the occurence to the map
    arr.forEach(letter => map[letter] = map[letter] + 1 || 1)
    
	// store all the distinct values in order
    for (let [key, val] of Object.entries(map)) 
        if (val == 1) distinctArr.push(key)
    
	// return the key or empty string
    return distinctArr[k-1] || ""
};
~``