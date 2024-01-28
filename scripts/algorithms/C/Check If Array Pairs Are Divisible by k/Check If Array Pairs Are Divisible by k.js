// Runtime: 88 ms (Top 87.5%) | Memory: 59.10 MB (Top 40.63%)

/**
 * @param {number[]} arr
 * @param {number} k
 * @return {boolean}
 */
var canArrange = function(arr, k) {
    let result=new Array(k).fill(0);
    let tmp;

    //caculate the number of all mod
    for(let i=0;i<arr.length;i++){
        tmp=arr[i];

        //caculate the mod
        if(tmp>=k||tmp<=-k)tmp%=k;

        //turn negative to Positive number, so it could use as array's index 
        if(tmp<0)tmp+=k;
        
        result[tmp]+=1;//counting
    }

    //Notice when i=0 and i==k-i
    if(result[0]%2==1)return false;
    for(let i=1;i<Math.ceil(result.length/2);i++){
        if(i==k-1&&result[i]%2==1)return false;
        if(result[i]!=result[k-i])return false;
    }
    return true;
};
