var frequencySort = function(s) {
    let obj = {}
    for(const i of s){
        obj[i] = (obj[i] || 0) +1
    }
    let sorted = Object.entries(obj).sort((a,b)=> b[1]-a[1])
    return sorted.map((e)=> e[0].repeat(e[1])).join('')
};
