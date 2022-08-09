/**
 * @param {number[]} nums
 * @return {number}
 */
var largestPerimeter = function(nums) {
    const sorted=nums.sort((a,b)=>a-b);
    const result=[];
    
    for(let i=0;i<sorted.length;i++){
        
        if((sorted[i]+sorted[i+1]>sorted[i+2])&&(sorted[i+2]+sorted[i+1]>sorted[i])&&(sorted[i]+sorted[i+2]>sorted[i+1])){
            
           result.push(sorted[i]+sorted[i+1]+sorted[i+2]);
        
        }
    }
    if(result.length!==0){
        
    return Math.max(...result); 
        
    }else{
        
    return 0;
        
    }
};
