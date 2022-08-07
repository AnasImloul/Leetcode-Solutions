var findSubsequences = function(nums) {
    
    const result = [];
    const set = new Set();
    
    function bt(index=0,ar=[]){
        if(!set.has(ar.join("_")) && ar.length >=2){
            set.add(ar.join("_"));
            result.push(ar);
        }
        for(let i =index; i<nums.length; i++){
            if(nums[i] >= ar[ar.length-1] || ar.length===0){
                bt(i+1, [...ar, nums[i]]);
            }
        }
    }
    
    bt();
    return result;
};