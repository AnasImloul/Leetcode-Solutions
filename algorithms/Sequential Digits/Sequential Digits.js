/**
 * @param {number} low
 * @param {number} high
 * @return {number[]}
 */
var sequentialDigits = function(low, high) {
    let res=[];
    
    function recur(start,num,prev){
        if(Number(num)>high) return;
        
        if(Number(num)>=low){
            res.push(num);
        }
        for(let i=start+1;i<=10;i++){
            if(prev+1==i || prev==0){
                recur(i,num+prev,i);
            }
        }
    }
    recur(0,'',0);
    return res.map((str)=>Number(str)).sort((a,b)=>a-b);
};
