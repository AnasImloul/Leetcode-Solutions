var getWinner = function(arr, k) {
    let ws=0;
    let currentWinner=0;
    for(let i=1;i<arr.length;i++){
        if(arr[currentWinner]>arr[i]){
            ++ws
        }else{
            ws=1
            currentWinner=i
        }
        if(ws===k)return arr[currentWinner]
    }
    return arr[currentWinner]
};
