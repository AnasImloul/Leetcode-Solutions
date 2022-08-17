/**
 * @param {number[]} dist
 * @param {number[]} speed
 * @return {number}
 */
var eliminateMaximum = function(dist, speed) {
      let t = new Array(dist.legnth)
    for(let i = 0; i< dist.length; i++){
      let m =  Math.ceil(dist[i]/ speed[i])
      t[i] = m
    }
   t = t.sort((a,b) => a-b)
    let c = 0
     for(let i = 0; i< t.length; i++){
        if(t[i]-i > 0) c++
       else if(t[i]-i <= 0) return c
    }
    return c
};