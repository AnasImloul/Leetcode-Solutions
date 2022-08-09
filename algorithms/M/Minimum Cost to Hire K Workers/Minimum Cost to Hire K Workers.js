/**
 * @param {number[]} quality
 * @param {number[]} wage
 * @param {number} k
 * @return {number}
 */
var mincostToHireWorkers = function(quality, wage, k) {
  let minCost = Number.MAX_SAFE_INTEGER;
  let offer, accepted, ratio;
  for(let i=0; i<quality.length; i++) {
    ratio = wage[i]/quality[i];
    accepted = [];
    for(let j=0; j<quality.length; j++) {
      offer = quality[j] * ratio;
      if(offer >= wage[j]) accepted.push(offer);
    } 
    if(accepted.length < k) continue;
    minCost = Math.min(minCost, accepted.sort((a,b) => a-b).splice(0, k).reduce((acc, cur) => acc+cur, 0));
  }
  return minCost;
}
