var sortByBits = function(arr) {
    const map = {};
    
    for (let n of arr) {
        let counter = 0, item = n;
        
        while (item > 0) {
			counter += (item & 1);    //increment counter if the lowest (i.e. the rightest) bit is 1
			item = (item >> 1);        //bitwise right shift (here is equivalent to division by 2)
        }
        
        map[n] = counter;
    }

    return arr.sort((a, b) => map[a] - map[b] || a - b) //sort by number of 1 bits; if equal, sort by value
};
