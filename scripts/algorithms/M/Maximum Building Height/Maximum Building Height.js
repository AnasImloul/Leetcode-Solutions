// Runtime: 411 ms (Top 50.00%) | Memory: 69.9 MB (Top 50.00%)
/**
 * @param {number} n
 * @param {number[][]} restrictions
 * @return {number}
 */
var maxBuilding = function(n, restrictions) {
    let maxHeight=0;
    restrictions.push([1,0]);//Push extra restriction as 0 for 1
    restrictions.push([n,n-1]);//Push extra restrition as n-1 for n
    restrictions.sort(function(a,b){return a[0]-b[0]});
    //Propogate from left to right to tighten the restriction: Check building restriction can be furhter tightened due to the left side building restriction.
    for(let i=1;i<restrictions.length;i++){
        restrictions[i][1] = Math.min(restrictions[i][1], (restrictions[i][0]-restrictions[i-1][0])+restrictions[i-1][1]);
    }
    //Propogate from right to left to tighten the restriction: Check building restriction can be furhter tightened due to the right side building restriction.
    for(let i=restrictions.length-2;i>=0;i--){
        restrictions[i][1] = Math.min(restrictions[i][1], (restrictions[i+1][0]-restrictions[i][0])+restrictions[i+1][1]);
    }
    let max=0;
    for(let i=0;i<restrictions.length-1;i++){
        let leftHeight = restrictions[i][1];
        let rightHeight = restrictions[i+1][1];
        let distance = restrictions[i+1][0]-restrictions[i][0]-1;//Number of cities between ith and i+1th city, excluding these cities
        let hightDiff = Math.abs(restrictions[i+1][1]-restrictions[i][1]);
        let middleHeight = Math.max(leftHeight,rightHeight)+Math.ceil((distance-hightDiff)/2);
        max = Math.max(max,middleHeight);
    }
    return max;
};