// Runtime: 234 ms (Top 41.24%) | Memory: 51.4 MB (Top 8.73%)
var findAnagrams = function(s, p) {

    function compareMaps(map1, map2) {
    var testVal;
    if (map1.size !== map2.size) {
        return false;
    }
    for (var [key, val] of map1) {
        testVal = map2.get(key);
        // in cases of an undefined value, make sure the key
        // actually exists on the object so there are no false positives
        if (testVal !== val || (testVal === undefined && !map2.has(key))) {
            return false;
        }
    }
    return true;
    }

    let p_map=new Map()
    let s_map=new Map()
    let res=[]
    let pn=p.length
    let sn=s.length
    for(let i in p){
        p_map.set(p[i],p_map.get(p[i])?p_map.get(p[i])+1:1)
        s_map.set(s[i],s_map.get(s[i])?s_map.get(s[i])+1:1)
    }
    let l=0
    if(compareMaps(s_map,p_map)) res.push(l)
    for(let r=pn;r<sn;r++){
        s_map.set(s[r],s_map.get(s[r])?s_map.get(s[r])+1:1)
        s_map.set(s[l],s_map.get(s[l])-1)
        if(s_map.get(s[l])===0){
            s_map.delete(s[l])
        }
        if(compareMaps(s_map,p_map)) res.push(l+1)
        l++
    }
    return(res)

};