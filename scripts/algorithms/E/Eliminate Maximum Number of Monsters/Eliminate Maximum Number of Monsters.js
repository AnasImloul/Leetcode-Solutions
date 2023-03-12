/**
 * @param {number[]} dist
 * @param {number[]} speed
 * @return {number}
 */
var eliminateMaximum = function(dist, speed) {
    let res = 0;
    let len = dist.length;
    let map = new Map();
    for(let i=0; i<len; i++){
        // the last time to eliminate
        let a = Math.ceil(dist[i] / speed[i]);
        if(map.has(a)){
            let c = map.get(a);
            c ++;
            map.set(a, c);
        }else{
            map.set(a, 1);
        }
    }

    let keys = Array.from(map.keys());
    keys.sort((a, b) => a-b);
    // time to eliminate
    let t = 0;
    for(let i=0; i<keys.length; i++){
        let c = map.get(keys[i]);
        if(c > keys[i]-t){
            res += keys[i]-t;
            break;
        }else{
            res += c;
            t += c;
        }
    }

    return res;
};