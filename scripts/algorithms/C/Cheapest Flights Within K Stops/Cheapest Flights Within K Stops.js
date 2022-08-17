/**
 * @param {number} n
 * @param {number[][]} flights
 * @param {number} src
 * @param {number} dst
 * @param {number} k
 * @return {number}
 */
const MAX_PRICE=Math.pow(10,8);
var findCheapestPrice = function(n, flights, src, dst, k) {
    let prev=[];
    let step=0;
    let curr=[];
    for(let i=0;i<n;i++){
        prev[i]=MAX_PRICE;
    }
    prev[src]=0;
    while(step-1<k){
      curr=[...prev];
        let isAnyChange=false;
        for(let i=0;i<flights.length;i++){
            let [src,dst,p]=flights[i];
            if(prev[src]>=MAX_PRICE)continue;
            let totalCostToReachDst=prev[src]+p;
            curr[dst]=Math.min(curr[dst],totalCostToReachDst);
        }
        step++;
        prev=curr;
        
    }
    return prev[dst]>=MAX_PRICE?-1:prev[dst];
    
};
