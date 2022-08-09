var canBeEqual = function(target, arr) {
    if(arr.length==1){
        if(arr[0]===target[0]){
            return true
        }
    }
    let obj = {}
    for(let i =0;i<arr.length; i ++){
        if(obj[arr[i]]==undefined){
            obj[arr[i]]=1
        }else{
            obj[arr[i]]++
        }
    }
    for(let i =0;i<target.length; i ++){
        if(obj[target[i]]==undefined){
            return false
        }else{
            obj[target[i]]++
        }
    }
   let result = Object.values(obj)
   
   for(let i =0; i <result.length; i ++){
       if(result[i]%2!==0){
           return false
       }
   }
    return true
};
