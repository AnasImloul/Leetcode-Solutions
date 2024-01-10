// Runtime: 202 ms (Top 75.0%) | Memory: 65.00 MB (Top 100.0%)

/**
 * @param {number[]} nums
 * @param {number[]} target
 * @return {number}
 */
 var makeSimilar = function(nums, target) {
    let res = 0;
    let [n1, n2] = trans(nums);
    let [t1, t2] = trans(target);

    for(let i=0; i<n1.length; i++){
        let r = t1[i] - n1[i];
        if(r > 0){
            res += r / 2;
        }
    }
    for(let i=0; i<n2.length; i++){
        let r = t2[i] - n2[i];
        if(r > 0){
            res += r / 2;
        }
    }

    return res;    
};

function trans(arr){
    let res = [];
    let arr1 = [];
    let arr2 = [];

    for(let i=0; i<arr.length; i++){
        if(arr[i] % 2 === 0){
            arr1.push(arr[i]);
        }else{
            arr2.push(arr[i]);
        }
    }
    arr1.sort((a, b) => a-b);
    arr2.sort((a, b) => a-b);
    res = [arr1, arr2];

    return res;
}
