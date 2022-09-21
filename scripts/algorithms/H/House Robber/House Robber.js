// Runtime: 81 ms (Top 64.99%) | Memory: 42 MB (Top 44.71%)
const max=(x,y)=>x>y?x:y
var rob = function(nums) {
     if(nums.length==1) return(nums[0]);
    let temp=[]
    temp[0]=nums[0];
        temp[1]=max(nums[0],nums[1]);

        for(let i =2;i<nums.length;i++){
            temp[i] = max(temp[i-1],nums[i]+temp[i-2]);
        }
        // console.log(temp)
        return(temp[nums.length-1]);
};