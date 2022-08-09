var smallerNumbersThanCurrent = function(nums) {
    let count, ans=[];
    /*Run a loop on each element excluding nums[i]
    and compare it with nums[j] if it's large, then count++
    else break;*/
    
    for(let i=0; i<nums.length; i++){
        let temp=nums[i], count=0;
        for(let j=0; j<nums.length; j++){
            if(i===j) continue;
            if(temp>nums[j]) count++;
        }
        ans.push(count);
    }
    return ans;
};

//second way using objects:--->

var smallerNumbersThanCurrent = function(nums) {
    let arr=[...nums], ans=[];
    arr.sort((a,b)=>a-b);
    let map={};
    map[arr[0]]=0;
    for(let i=1; i<arr.length; i++){
        if(arr[i-1]!==arr[i]) map[arr[i]]=i;
    }
    for(let i=0; i<nums.length; i++){
        ans.push(map[nums[i]]);
    }
    return ans;
};
