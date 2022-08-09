var maxOperations = function(nums, k) {
let freq = new Map(),count=0; 
for (let i = 0; i < nums.length; i++) {
    if (freq.get(k-nums[i])) {
        if(freq.get(k-nums[i])==1) freq.delete(k-nums[i])
        else freq.set(k-nums[i],freq.get(k-nums[i])-1)
        count++;
    }else freq.set(nums[i],freq.get(nums[i])+1||1)
} 
return count;
};
