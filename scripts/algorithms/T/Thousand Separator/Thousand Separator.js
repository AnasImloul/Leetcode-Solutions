// Runtime: 63 ms (Top 94.17%) | Memory: 41.7 MB (Top 95.00%)
var thousandSeparator = function(n) {
    let ans = "";

    if(n >= 1000){
    const arr = String(n).split('');
        for(let i=0;i<arr.length;i++){
            let temp = arr.length - i;
            if(temp === 3 && arr.length > temp || temp === 6 && arr.length > temp || temp === 9 && arr.length > temp || temp === 12 && arr.length > temp){
                ans += '.';
            }
        ans += arr[i];
        }
    }else{
        ans += n;
    }

    return ans;
};