
var fourSumCount = function(nums1, nums2, nums3, nums4) {
    let result = 0;
    
    let sumMap = {}; 
    
    for(let i=0; i < nums1.length; i++){
       for(let j=0; j < nums2.length; j++){
           let sum = nums1[i] + nums2[j];
              if(!sumMap[sum]){
                sumMap[sum] = 0;
              }
           
           sumMap[sum]+=1;
       } 
    }
    
    for(let k=0; k < nums3.length; k++){
         for(let l=0; l < nums4.length; l++){
            let sum = nums3[k] + nums4[l];
            if(sumMap[-sum]){
                result+=sumMap[-sum];    
            }
         }  
    } 
    
    return result;
};