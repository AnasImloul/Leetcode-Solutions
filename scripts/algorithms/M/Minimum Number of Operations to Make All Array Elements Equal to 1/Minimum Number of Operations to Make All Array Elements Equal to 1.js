// Runtime: 130 ms (Top 11.11%) | Memory: 44.60 MB (Top 11.11%)

/**
 * @param {number[]} nums
 * @return {number}
 */
var minOperations = function(nums) {
        let n=nums.length;
    let possible=false;
    let onePresent=false;
    var ans=0;
    var count=0;
    for(let i=0;i<nums.length;i++){
        if(nums[i]==1)count++;
    }
    if(count>0)return n-count;
    const gcd=(a,b)=>{
        while(b!=0){
            r=a%b;
            a=b;
            b=r;
        }
        return a;
    }
    oldArray=[...nums];
    var changed=true;
    while(changed==true){
        changed=false;
        for(let i=0;i<n-1;i++){
       nums[i]=gcd(nums[i],nums[i+1]);    
    } 
         for(let i=0;i<n-1;i++){
       if(nums[i]==1){
           return ans+nums.length;
       }
    }
        for(let i=0;i<n;i++){
            if(nums[i]!=oldArray[i]){
                changed=true;
                ans++;
                break;
            }
        }
        oldArray=[...nums]
    }


    return -1;  

    
};
