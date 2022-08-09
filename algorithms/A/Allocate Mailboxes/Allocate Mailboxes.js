/**
 * @param {number[]} houses
 * @param {number} k
 * @return {number}
 */
var minDistance = function(houses, k) {
    var distance=[],median,dist,cache={};
    houses.sort(function(a,b){return a-b});
    //distance[i][j] is the minimun distacne if we cover houses from ith index to jth index with 1 mailbox. This mailbox will be at the median index of sub array from ith index to jth index.
    for(let i=0;i<houses.length;i++){
        for(let j=i;j<houses.length;j++){
            median = Math.floor((i+j)/2);
            dist=0;
            for(let k=i;k<=j;k++){
                dist+=Math.abs(houses[median]-houses[k]);
            }
            if(distance[i]===undefined){
                distance[i]=[];
            }
            distance[i][j]=dist;
        }
    }
    return dp(0,k);
    function dp(i,k){
        let cacheKey=i+"_"+k;
        if(cache[cacheKey]!==undefined){
            return cache[cacheKey];
        }
        let min=Number.MAX_SAFE_INTEGER,ans;
        if(i===houses.length && k===0){//Its a correct answer only if we have used all the mailboxes and all the houses are completed. 
            return 0;
        }
        if(i===houses.length || k===0){//Other than the first if condition, every other condition to exhaust either mailboxes for houses is an invalid answer. So returning minus an infinite number from here. 
            return min;
        }
        
        for(let j=i;j<houses.length;j++){//Here in each step we are covering houses from ith index to jth index with one mailbox and calling dp function to cover the rest of the houses, starting from jth+1 index with the remaining k-1 houses. In each possible answer we will keep the minimum ans. 
            ans = dp(j+1,k-1)+distance[i][j];
            min = Math.min(min,ans);
        }
        cache[cacheKey]=min;
        return min;
    }
};
