/**
 * @param {number[]} nums
 * @return {number}
 */
var reversePairs = function(nums) {
  
    let ans = mergeSort(nums,0,nums.length-1);
    return ans;
  
    
};

var mergeSort = function(nums,l,h){
    if(l>=h){
        return 0;
    }
    let m = Math.floor((l+h)/2);
    let inv = mergeSort(nums,l,m);
    inv = inv + mergeSort(nums,m+1,h);
    inv = inv + merge(nums,l,m,h);
    return inv;
}

var merge = function (nums,l,m,h){
    let cnt = 0;
    let j=m+1;
    for(let i=l;i<=m;i++){
        while(j<=h && nums[i]> 2*nums[j]){
            j++;
        }
        cnt = cnt+(j-(m+1));
    }
    
    let left = l, right=m+1,temp=[];
    while(left<=m && right<=h){
        if(nums[left]<=nums[right]){
            temp.push(nums[left]);
            left++;
        }
        else{
            temp.push(nums[right]);
            right++;
        }
    }
    while(left<=m){
        temp.push(nums[left]);
        left++;
    }
    while(right<=h){
        temp.push(nums[right]);
        right++;
    }
    for(let i=l;i<=h;i++){
        nums[i]=temp[i-l];
    }
    return cnt;
    
}

