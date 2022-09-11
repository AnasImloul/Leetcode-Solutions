// Runtime: 160 ms (Top 18.09%) | Memory: 51.5 MB (Top 65.79%)
/**
 * @param {number[]} nums
 * @return {number}
 */
var getMaxLen = function(nums) {
    let leftToRight=0,p=1,count=0,max=0,item;
    //Process elements from left to right
    for(let i=0;i<nums.length;i++){
        if(nums[i]===0){
            p=0;
        }else if(nums[i]>0){
            p *=1
        }else if(nums[i]<0){
            p *=-1
        }
        count++;
        if(p>0){
            max = Math.max(max,count);
        }
        if(p===0){
            p=1;
            count=0;
        }
    }
    count = 0;p=1;
    //Process elements from right to left
    for(let i=nums.length-1;i>=0;i--){
        if(nums[i]===0){
            p=0;
        }else if(nums[i]>0){
            p *=1
        }else if(nums[i]<0){
            p *=-1
        }
        count++;
        if(p>0){
            max = Math.max(max,count);
        }
        if(p===0){
            p=1;
            count=0;
        }
    }
    return max;
};