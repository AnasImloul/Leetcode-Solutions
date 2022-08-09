/**
 * @param {number[]} arr
 * @return {number[]}
 */
var arrayRankTransform = function(arr) {
    if(arr.length==0){
            return arr;
        }
        let a=arr.map((num)=>num);
        
        arr.sort((a,b)=>a-b);
        let map=new Map();
        map.set(arr[0],1);
        for(let i=1;i<arr.length;i++){
            if(arr[i]==arr[i-1]){
                continue;
            }
            else{
                map.set(arr[i],map.get(arr[i-1])+1);
            }
        }
       
        let rank=a.map((num)=>map.get(num));
        return rank;
};
