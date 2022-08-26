// Runtime: 146 ms (Top 31.11%) | Memory: 46.7 MB (Top 73.89%)
/**
 * @param {string[]} cpdomains
 * @return {string[]}
 */
var subdomainVisits = function(cpdomains) {
    let map = {}
    cpdomains.forEach(d => {
        let data = d.split(" ");
        let arr = data[1].split(".")
        while(arr.length > 0) {
            if(arr.join(".") in map) map[arr.join(".")]+=+data[0]
            else map[arr.join(".")] = +data[0]
            arr.shift()
        }
    })
    let result = []
    for(let key in map) result.push(map[key] + " "+ key)
    return result
};
