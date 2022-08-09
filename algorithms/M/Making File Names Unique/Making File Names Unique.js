/**
 * @param {string[]} names
 * @return {string[]}
 */
var getFolderNames = function(names) {
    // save existed folder names
    let hashMap = new Map();
    for(let name of names) {
        let finalName = name;
        // next smallest suffix number
        // if this name is not present in the map, next smallest suffix will be 1
        let number = hashMap.get(name) || 1;
        if(hashMap.has(name)) {
            // append suffix to original name
            finalName += '(' + number +')';
            // find the smallest suffix that hasn't been used before
            while(hashMap.has(finalName)) {
                number++;
                // try to use new suffix to update name
                finalName = name + '(' + number +')';
            }
            // update next smallest suffix number of new name
            hashMap.set(finalName, 1);
        }
        // update next smallest suffix number of original name
        hashMap.set(name, number);
    }
    return Array.from(hashMap.keys());
};
