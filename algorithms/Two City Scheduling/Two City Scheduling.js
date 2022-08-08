/**
 * @param {number[][]} costs
 * @return {number}
 */
var twoCitySchedCost = function(costs) {
    // TC: O(nlogn) and O(1) extra space
    let n=costs.length;
    let countA=0,countB=0,minCost=0;
    
    // sorted in descending order by their absolute diff
    costs=costs.sort((a,b)=>{
        let diffA=Math.abs(a[0] - a[1]);
        let diffB=Math.abs(b[0] - b[1]);
        return diffB-diffA;
    });
    
    for(let i=0;i<n;i++){
        let [a,b]=costs[i];
        if(a<b){
            if(countA<n/2){
                minCost+=a;
                countA++;
            }else{
                minCost+=b;
                countB++;
            }
        }else{
            if(countB<n/2){
                minCost+=b;
                countB++;
            }else{
                minCost+=a;
                countA++;
            }
        }
    }
    return minCost;
};
