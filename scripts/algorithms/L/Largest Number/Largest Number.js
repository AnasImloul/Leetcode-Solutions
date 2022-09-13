// Runtime: 115 ms (Top 22.99%) | Memory: 46.6 MB (Top 5.11%)
var largestNumber = function(nums) {
    var arr=[]
    nums.forEach((item)=>{
        arr.push(item.toString());
    })
    arr.sort((a,b)=>(b+a).localeCompare(a+b));
    var ret=""
    if(arr[0]=="0") return "0";
    arr.forEach((item)=>{
        ret+=item;
    })
    return ret;
};