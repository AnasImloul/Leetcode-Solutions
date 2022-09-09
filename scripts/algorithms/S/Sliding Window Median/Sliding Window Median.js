// Runtime: 317 ms (Top 27.08%) | Memory: 47.1 MB (Top 71.87%)
function convertNumber(num) {
    return parseFloat(num.toFixed(5))
}
function findMedian(arr) {
    let start = 0;
    let end = arr.length-1;
    let ans;
    if((end-start+1)%2===0) {
        ans = (arr[Math.floor((end+start)/2)] + arr[Math.floor((end+start)/2)+1])/2 ;
    } else {
        ans = arr[Math.floor((end+start)/2)];
    }
    return convertNumber(ans);
}
function updateWinArray(arr) {
    if(arr.length===1) {
        return;
    }
    let ele = arr[arr.length-1];
    let i;
    for(i=arr.length-2;i>=0;i--) {
        if(ele < arr[i]) {
            arr[i+1] = arr[i];
        } else {
            break;
        }
    }
    arr[i+1] = ele;
}
function binarySearch(arr,ele) {
    let start =0, end = arr.length-1, mid;
    while(start<=end) {
        mid = Math.floor((start+end)/2);
        if(arr[mid]===ele) {
            return mid;
        } else if(ele > arr[mid]) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }
}
var medianSlidingWindow = function(nums, k) {
    let i=0,j=0,result=[],winArr=[];
    while(j<nums.length) {
        winArr.push(nums[j]);
        updateWinArray(winArr);
        if(j-i+1 < k) {
            j++;
        } else if(j-i+1 === k) {
            let ans = findMedian(winArr);
            result.push(ans);
            let indexOfiEle = binarySearch(winArr,nums[i]);
            winArr.splice(indexOfiEle,1);
            i++;
            j++;
        }
    }
    return result;
};